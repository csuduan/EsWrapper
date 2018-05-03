#pragma once
#include "Stdafx.h"
#include "include/EsunnyForeignApi.h"

using namespace ESForeign;
namespace EsForeignWrapper
{

	public ref  class EsTradeApi
	{
	private:
		IEsunnyTradeApi* pIEsunnyTradeApi;
		IEsunnyTradeSpi* pIEsunnyTradeSpi;
		int errorID;
		bool bLogin;

	public:
		RspOpen^            OnRspOpen;
		RspClose^           OnRspClose;
		RspLogin^           OnRspLogin;
		RspInitFinished^    OnRspInitFinished;
		RspLogOut^          OnRspLogOut;
		
		
		RspOrderInsert^  OnRspOrderInsert;
		RspOrderModify^  OnRspOrderModify;
		RspOrderDeleteError^  OnRspOrderDeleteError;
		RspQryOrder^     OnRspQryOrder;
		RspHistOrderQry^ OnRspHistOrderQry;
		RtnOrderState^   OnRtnOrderState;
		RtnOrderInfo^    OnRtnOrderInfo;
		
		RspMatchQry^     OnRspMatchQry;
		RtnMatchState^   OnRtnMatchState;
		RtnMatchInfo^    OnRtnMatchInfo;
		RspHistMatchQry^ OnRspHistMatchQry;
		
		QryContract^     OnQryContract;
		RtnOrderRemove^  OnRtnOrderRemove;
		RtnMatchRemove^  OnRtnMatchRemove;

		QryMoney^        OnQryMoney;
		QryHold^		 OnQryHold;
		QryCommodity^    OnQryCommodity;
		RspQryCurrency^  OnRspQryCurrency;
		RtnExchangeState^ OnRtnExchangeState;

	public:
		EsTradeApi(String^ cer, String^ filePath,String^ appId);
		~EsTradeApi();

#pragma region API
	public:


		// 关闭连接并释放当前api会话
		void  Free();

		// 获取错误码的中文描述(多字节编码)
		String^  GetErrcodeDesc(int iErrcode);

		//连接交易服务器，返回成功只表明成功发出连接请求，是否建立连接需要
		bool  Open(AddressField^ addr);


		//获取是否与交易服务器建立连接
		bool  IsOpen();


		//发送登录请求，暂时支持单客户登陆
		int  Login(LoginReqField^ loginReqField, int iReqID);


		///发送退出请求
		int  LogOut(int iReqID) ;
		//发起二次验证
		int  SetVertificateCode(String^ CertificateCode, int iReqID);

		String^  GetCertCodeExpireDate();


		// 报单请求
		int  OrderInsert(OrderInsertReqField^ orderInsertReqField, int iReqID);



		// 撤单请求
		int  OrderDelete(int orderId, int iReqID);


		///查询客户资金
		int QryMoney(MoneyQryReqField^ qryMoney, int iReqID) ;

		//查询出入金,暂无权限
		//int  QryCashOper(CashOperQryReqField^ req, int iReqID);


		//查询客户委托，查询所有数据 流号填0
		int QryOrder(OrderQryReqField^ qryOrder, int iReqID) ;


		///查询客户成交
		int  QryMatch( MatchQryReqField^ qryMatch, int iReqID) ;


		//查询持仓
		int  QryHold( HoldQryReqField^ qryHold, int iReqID) ;



		// 查询交易商品
		int  QryCommodity(CommodityQryReqField^ qryCmdy, int iReqID) ;



		//历史委托查询
		int  QryHistOrder(HisOrderQryReqField^ req, int iReqID) ;


		//历史成交查询
		int QryHistMatch(HisMatchQryReqField^ req, int iReqID) ;

		//查询货币信息
		int QryCurrency(CurrencyQryReqField^ req, int iReqID);
				
#pragma endregion
	
//#pragma region Event
//event RspOpen^  OnRspOpen
//{
//	void add(RspOpen^ handler)
//	{
//		this->delegate_RspOpen += handler;
//	}
//	void remove(RspOpen^ handler)
//	{
//		this->delegate_RspOpen -= handler;
//	}
//	void raise()
//	{
//		if (this->delegate_RspOpen != nullptr)
//			this->delegate_RspOpen();
//	}
//}
//
//event RspClose^  OnRspClose
//{
//	void add(RspClose^ handler)
//	{
//		this->delegate_RspClose += handler;
//	}
//	void remove(RspClose^ handler)
//	{
//		this->delegate_RspClose -= handler;
//	}
//	void raise()
//	{
//		if (this->delegate_RspClose != nullptr)
//			this->delegate_RspClose();
//	}
//}
//
//event RspLogin^  OnRspLogin
//{
//	void add(RspLogin^ handler)
//	{
//		this->delegate_RspLogin += handler;
//	}
//	void remove(RspLogin^ handler)
//	{
//		this->delegate_RspLogin -= handler;
//	}
//	void raise(LoginRspField^ pLoginRspField, int errCode, int iReqID)
//	{
//		if (this->delegate_RspLogin != nullptr)
//			this->delegate_RspLogin(pLoginRspField,errCode,iReqID);
//	}
//}
//
//event RspInitFinished^  OnRspInitFinished
//{
//	void add(RspInitFinished^ handler)
//	{
//		this->delegate_RspInitFinished += handler;
//	}
//	void remove(RspInitFinished^ handler)
//	{
//		this->delegate_RspInitFinished -= handler;
//	}
//	void raise(int errCode)
//	{
//		if (this->delegate_RspInitFinished != nullptr)
//			this->delegate_RspInitFinished(errCode);
//	}
//}
//
//event RspLogOut^  OnRspLogOut
//{
//	void add(RspLogOut^ handler)
//	{
//		this->delegate_RspLogOut += handler;
//	}
//	void remove(RspLogOut^ handler)
//	{
//		this->delegate_RspLogOut -= handler;
//	}
//	void raise(int errCode, int iReqID)
//	{
//		if (this->delegate_RspLogOut != nullptr)
//			this->delegate_RspLogOut(errCode,iReqID);
//	}
//}
//
//event RspOrderInsert^  OnRspOrderInsert
//{
//	void add(RspOrderInsert^ handler)
//	{
//		this->delegate_RspOrderInsert += handler;
//	}
//	void remove(RspOrderInsert^ handler)
//	{
//		this->delegate_RspOrderInsert -= handler;
//	}
//	void raise(OrderInsertRspField^ pOrderInsertRspField, int errCode, int iReqID)
//	{
//		if (this->delegate_RspOrderInsert != nullptr)
//			this->delegate_RspOrderInsert(pOrderInsertRspField, errCode,iReqID);
//	}
//}
//#pragma endregion




	};

	//交易数据处理的回调处理类，当有数据到达本地时，API会回调本类中对应的接口
	//回调函数不能有阻塞性操作
	//OnRsp开头的函数为发送请求后对应的应答，OnRtn开头的函数为服务器主动推送数据

	class EsTradeSpi : public IEsunnyTradeSpi
	{

	private:
		gcroot<EsTradeApi^ > esTradeApi;
	public:
		EsTradeSpi(EsTradeApi^ esTradeApi) {
			this->esTradeApi = esTradeApi;
		}

	public:
		////////////////////////////////////////
		/// \fn    ~IEsunnyTradeSpi
		/// \brief 纯虚类，需要派生
		/// \return   
		////////////////////////////////////////
		virtual ~EsTradeSpi() ;

		////////////////////////////////////////
		/// \fn    OnOpen
		/// \brief 与服务器建立连接时调用
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnOpen() ;

		////////////////////////////////////////
		/// \fn    OnClose
		/// \brief 与服务器断开连接时调用
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnClose();

		////////////////////////////////////////
		/// \fn    OnLogin
		/// \brief 发送Login登陆成功时收到服务器登陆响应调用
		/// \param const TEsLoginRspField & rsp
		/// \param int iReqID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID);

		////////////////////////////////////////
		/// \fn    OnInitFinished
		/// \brief 发送Login成功后，收到OnLogin应答成功后收到初始化操作完成
		///        所有的业务操作需要在本响应errCode为0（成功）后可进行
		/// \param int errCode 错误码，0-成功，其他值-错误的原因代码
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnInitFinished(int errCode) ;

		////////////////////////////////////////
		/// \fn    OnLogOut
		/// \brief 收到登出应答调用
		/// \param int errCode
		/// \param const int iReqID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnLogOut(int errCode, const int iReqID) ;

		

		////////////////////////////////////////
		/// \fn    OnQryMoney
		/// \brief 资金查询应答
		/// \param TEsMoneyQryRspField * rsp 查询完成时，指针为空，未完成时包含查询结果
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		

		
		////////////////////////////////////////
		/// \fn    OnRspOrderInsert
		/// \brief 报单请求的应答
		/// \param TEsOrderInsertRspField & rsp 报单请求的详细结果，会返回委托号及本地号
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRspOrderModify
		/// \brief 改单请求的应答，出错时会收到本应答
		/// \param TEsOrderModifyRspField & rsp
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID);

		////////////////////////////////////////
		/// \fn    OnRspOrderDelete
		/// \brief 撤单请求的应答，出错时会收到本应答
		/// \param TEsOrderDeleteRspField & rsp
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRspQryOrder
		/// \brief 委托查询应答
		/// \param TEsOrderDataQryRspField * rsp 委托查询结果，查询完成时，指针为空
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRspHistOrderQry
		/// \brief 历史委托查询应答
		/// \param TEsHisOrderQryRspField * rsp 历史委托查询结果，查询完成时，指针为空
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRtnOrderState
		/// \brief 委托变化通知，委托状态变化时回调
		/// \param TEsOrderStateNoticeField & rsp 委托详细数据
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnOrderState(const TEsOrderStateNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRtnOrderInfo
		/// \brief 委托信息变化通知，委托信息变化时回调
		/// \param TEsOrderInfoNoticeField & rsp 委托信息详细数据
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRspMatchQry
		/// \brief  成交查询应答
		/// \param TEsMatchDataQryRspField * rsp 成交查询结果，查询完成时，指针为空
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRtnMatchState
		/// \brief 成交变化推送通知
		/// \param TEsMatchStateNoticeField & rsp 成交详细数据
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnMatchState(const TEsMatchStateNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRtnMatchInfo
		/// \brief 成交信息变化推送通知
		/// \param TEsMatchInfoNoticeField & rsp 成交信息详细数据
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp) ;

		////////////////////////////////////////
		/// \fn    OnRspHistMatchQry
		/// \brief 历史成交查询应答
		/// \param TEsHisMatchQryRspField * rsp 历史成交查询结果，查询完成时，指针为空
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnQryHold
		/// \brief 持仓查询应答
		/// \param TEsHoldQryRspField * rsp 持仓查询结果，查询完成时，指针为空
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;

		////////////////////////////////////////
		/// \fn    OnRtnExchangeState
		/// \brief 市场状态变更推送通知
		/// \param TEsExchangeQryRspField & rsp 市场状态详细信息
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp);

		
		
		////////////////////////////////////////
		/// \fn    OnQryCommodity
		/// \brief 商品查询应答
		/// \param TEsCommodityQryRspField * rsp 商品详细信息，查询完成时，指针为空
		/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
		/// \param const int iReqID 对应发送请求的ID
		/// \return   void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;


	

		////////////////////////////////////////
		/// \fn    OnRspQryCurrency
		/// \brief 查询货币币种信息应答
		/// \param const TEsCurrencyQryRspField * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) ;


		////////////////////////////////////////
		/// \fn    OnRtnOrderRemove
		/// \brief 委托删除通知
		/// \param const TEsOrderRemoveNoticeField & rsp
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp) ;

		
	};
}


