#pragma once

#include "Stdafx.h"


namespace EsForeignWrapper
{

	public ref class EsQuotApi
	{
	private:
		IEsunnyQuotClient* pQuotClient;
		IEsunnyQuotNotify* pQuotNotify;
		int errorID;
		bool bLogin;

	public:
		/**
		*初始化API密钥
		* @param secretkey 密钥
		* @param option 1表示需要订阅期权品种，0表示不需要订阅期权
		* @return 0表示成功，否则失败
		*/
		EsQuotApi(String^ secretkey, int option);
		~EsQuotApi(void);

	public:
		/*
		*连接行情数据服务器IP及端口
		* @param ip 服务器的IP
		* @param port 服务器的端口
		* @return 0表示连接成功，否则失败
		*/
		 int  Connect(String^ ip, int port);

		/*
		*断开当前连接
		*/
		 void  DisConnect();

		 /*
		   释放对象
		 */
		 void Free();

		/*
		*登录行情数据服务器
		* @param user 登录用户名
		* @param password 登录密码
		* @return 0表示登录指令发送成功，否则发送失败，是否登录成功通过回调OnRspLogin
		*/
		 int Login(String^ user, String^ password);

		/*
		*请求/取消订阅品种即时行情
		* @param market 市场中文名
		* @param stk 合约代码
		* @param need 1表示订阅，0表示取消订阅
		* @return 0表示订阅请求成功，否则失败，成功之后将会在OnStkQuot中收到品种的即时行情
		*/
		 int  RequestQuot(String^ market, String^ stk, int need);

		/*
		*请求品种历史行情
		* @param market 市场中文名
		* @param stk 合约代码
		* @param period 周期 1：1分钟，2：5分钟，3：60分钟，4：日线
		* @return 0表示请求成功，否则失败，历史数据结果在OnRspHistoryQuot返回
		*/
		 int  RequestHistory(String^ market, String^ stk, int period);

		/*
		*请求品种明细数据
		* @param market 市场中文名
		* @param stk 合约代码
		* @param date 要请求明细的日期，形如20090901
		* @return 0表示请求成功，否则失败，历史数据结果在OnRspTraceData返回
		*/
		 int  RequestTrace(String^ market, String^ stk, String^ date);

		/*
		*针对订阅品种比较多时，先循环调用AddReqStk，最后调用一次SendReqStk
		* @param market 市场中文名
		* @param stk 合约代码
		* @param need 1表示订阅，0表示取消订阅
		* @return 0表示订阅请求成功，否则失败，成功之后将会在OnStkQuot中收到品种的即时行情
		*/
		 int  AddReqStk(String^ market, String^ stk, int need);

		/*
		*给服务器发送品种订阅请求
		* @return 0表示订阅请求成功，否则失败，成功之后将会在OnStkQuot中收到品种的即时行情
		*/
		 int  SendReqStk();




	public:
		RspQuotLogin^		OnRspLogin;
		ChannelLost^		OnChannelLost;
		StkQuot^			OnStkQuot;
		RspHistoryQuot^		OnRspHistoryQuot;
		RspTraceData^		OnRspTraceData;
		RspMarketInfo^		OnRspMarketInfo;

	//public:
	//	/**
	//	*登录反馈回调函数
	//	* @param err 错误号 0表示登录成功，否则失败
	//	* @param errtext 错误信息
	//	* @return 0表示成功，否则失败
	//	*/
	//	event RspQuotLogin^ OnRspLogin
	//	{
	//		void add(RspQuotLogin^ handler)
	//		{
	//			this->delegate_RspLogin += handler;
	//		}
	//		void remove(RspQuotLogin^ handler)
	//		{
	//			this->delegate_RspLogin -= handler;
	//		}
	//		void raise(int err, String^ errtext)
	//		{
	//			if (this->delegate_RspLogin != nullptr)
	//				this->delegate_RspLogin(err, errtext);
	//		}
	//	}

	//	/**
	//	*物理连接出错回调函数
	//	* @param err 错误号
	//	* @param errtext 错误信息
	//	* @return 0表示成功，否则失败
	//	*/
	//	event ChannelLost^ OnChannelLost
	//	{
	//		void add(ChannelLost^ handler)
	//		{
	//			this->delegate_ChannelLost += handler;
	//		}
	//		void remove(ChannelLost^ handler)
	//		{
	//			this->delegate_ChannelLost -= handler;
	//		}
	//		void raise(int err, String^ errtext)
	//		{
	//			if (this->delegate_ChannelLost)
	//				 this->delegate_ChannelLost(err, errtext);
	//		}
	//	}

	//	/**
	//	*即时行情回调函数
	//	* @param pData 行情结构指针
	//	* @return 0表示成功，否则失败
	//	*/
	//	event StkQuot^ OnStkQuot
	//	{
	//		void add(StkQuot^ handler)
	//		{
	//			this->delegate_StkQuot += handler;
	//		}
	//		void remove(StkQuot^ handler)
	//		{
	//			this->delegate_StkQuot -= handler;
	//		}
	//		void raise(StkData^ pData)
	//		{
	//			if (this->delegate_StkQuot)
	//				this->delegate_StkQuot(pData);
	//		}
	//	}

	//	/**
	//	*历史行情反馈回调函数
	//	* @param pHisData 历史行情数据结构指针
	//	* @return 0表示成功，否则失败
	//	*/
	//	event RspHistoryQuot^ OnRspHistoryQuot
	//	{
	//		void add(RspHistoryQuot^ handler)
	//		{
	//			this->delegate_RspHistoryQuot += handler;
	//		}
	//		void remove(RspHistoryQuot^ handler)
	//		{
	//			this->delegate_RspHistoryQuot -= handler;
	//		}
	//		void raise(StkHisData^ pHisData)
	//		{
	//			if (this->delegate_RspHistoryQuot)
	//				 this->delegate_RspHistoryQuot(pHisData);

	//		}
	//	}

	//	/**
	//	*明细数据反馈回调函数
	//	* @param pTraceData 明细数据结构指针
	//	* @return 0表示成功，否则失败
	//	*/
	//	event RspTraceData^ OnRspTraceData
	//	{
	//		void add(RspTraceData^ handler)
	//		{
	//			this->delegate_RspTraceData += handler;
	//		}
	//		void remove(RspTraceData^ handler)
	//		{
	//			this->delegate_RspTraceData -= handler;
	//		}
	//		void raise(StkTraceData^ pTraceData)
	//		{
	//			if (this->delegate_RspTraceData)
	//				 this->delegate_RspTraceData(pTraceData);
	//		}
	//	}

	//	/**
	//	*市场信息包反馈函数，收到市场信息表示数据已经初始化完成了！
	//	* @param pMarketInfo 市场信息数据指针
	//	* @param bLast 是否为最后一个市场，bLast为1表示是最后一个，0表示后面还有市场数据
	//	* @return 0表示成功，否则失败,
	//	*/
	//	event RspMarketInfo^ OnRspMarketInfo
	//	{
	//		void add(RspMarketInfo^ handler)
	//		{
	//			this->delegate_RspMarketInfo += handler;
	//		}
	//		void remove(RspMarketInfo^ handler)
	//		{
	//			this->delegate_RspMarketInfo -= handler;
	//		}
	//		void raise(WMarketInfo^ pMarketInfo, int bLast)
	//		{
	//			if (this->delegate_RspMarketInfo)
	//				 this->delegate_RspMarketInfo(pMarketInfo, bLast);
	//		}
	//	}
	};

	public  class IEsQuotSpi {
		void OnRspLogin();
	};


	class  EsQuotSpi : public IEsunnyQuotNotify
	{
	private:
		gcroot<EsQuotApi^ > client;
	public:
		EsQuotSpi(EsQuotApi^ esQuotClient) {
			this->client = esQuotClient;
		}
		void SetQuotClient(EsQuotApi^ esQuotClient) {
			this->client = esQuotClient;
		}

	public:
		/**
		*登录反馈回调函数
		* @param err 错误号 0表示登录成功，否则失败
		* @param errtext 错误信息
		* @return 0表示成功，否则失败
		*/
		virtual int __cdecl OnRspLogin(int err, const char *errtext);

		/**
		*物理连接出错回调函数
		* @param err 错误号
		* @param errtext 错误信息
		* @return 0表示成功，否则失败
		*/
		virtual int __cdecl OnChannelLost(int err, const char *errtext);

		/**
		*即时行情回调函数
		* @param pData 行情结构指针
		* @return 0表示成功，否则失败
		*/
		virtual int __cdecl OnStkQuot(struct STKDATA *pData);

		/**
		*历史行情反馈回调函数
		* @param pHisData 历史行情数据结构指针
		* @return 0表示成功，否则失败
		*/
		virtual int __cdecl OnRspHistoryQuot(struct STKHISDATA *pHisData);

		/**
		*明细数据反馈回调函数
		* @param pTraceData 明细数据结构指针
		* @return 0表示成功，否则失败
		*/
		virtual int __cdecl OnRspTraceData(struct STKTRACEDATA *pTraceData);

		/**
		*市场信息包反馈函数，收到市场信息表示数据已经初始化完成了！
		* @param pMarketInfo 市场信息数据指针
		* @param bLast 是否为最后一个市场，bLast为1表示是最后一个，0表示后面还有市场数据
		* @return 0表示成功，否则失败,
		*/
		virtual int __cdecl OnRspMarketInfo(struct MarketInfo *pMarketInfo, int bLast);
	};


};