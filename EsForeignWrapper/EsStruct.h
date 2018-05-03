#pragma once
#include "Enums.h"
using namespace System;
using namespace System::Runtime::InteropServices;


namespace EsForeignWrapper
{
	//即时数据结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct StkData
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^ Market;        //市场中文名
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^ Code;         //合约代码

		float	YClose;			//昨收盘
		float	YSettle;		//昨结算
		float	Open;			//开盘价
		float	High;			//最高价
		float	Low;			//最低价
		float	New;			//最新价
		float	NetChg;			//涨跌
		float	Markup;			//涨跌幅
		float	Swing;			//振幅
		float	Settle;			//结算价
		float	Volume;			//成交量
		float	Amount;			//持仓量

		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	Ask;			//申卖价
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	AskVol;		   //申卖量
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	Bid;		  //申买价
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 10, ArraySubType = UnmanagedType::R4)]
		array<float>^	BidVol;		  //申买量			

		float	AvgPrice;		//平均价

		float   LimitUp;		//涨停板
		float   LimitDown;		//跌停板
		float   HistoryHigh;	//合约最高
		float   HistoryLow;		//合约最低

		float	YOPI;			//昨持仓
		float   ZXSD;			//昨虚实度
		float   JXSD;			//今虚实度
		float   CJJE;			//成交金额

		//新增外盘
		float TClose;			//收盘价
		float Lastvol;			//最新成交量
		float status;			//合约交易状态 -1:未知 0:开市 1:无红利 2:竞价 3:挂起 4:闭市 5:开市前 6:闭市前 7:快市
		float updatetime;			//更新时间,形如：235959表示23：59：59

		float		BestBPrice;					//最优买价
		float		BestBVol;					//最优买量
		float		BestSPrice;					//最优卖价
		float		BestSVol;					//最优卖量	
	};

	//历史数据
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HistoryData 
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 20)]
		String^	time;	          //时间,形如：2009-06-01 08:00:00
		float	fOpen;		      //开盘
		float	fHigh;		      //最高
		float	fLow;			  //最低
		float	fClose;		      //收盘
		float	fVolume;		  //成交量(手)
		float	fAmount;		  //成交额(元)
	};


	//品种历史数据
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct StkHisData	  
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^			Market;	     //市场中文名
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^			Code;	    //品种代码
		short			nPeriod;	//周期
		short			nCount;		//历史数据数目
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 1)]
		array<HistoryData^>^	HisData;
	};


	//成交明细
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct StockTraceData 
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 20)]
		String^	time;	       //时间,形如：2009-06-01 08:00:00
		float	m_NewPrice;		//最新价
		float	m_Volume;		//总量
		float	m_Amount;		//持仓
		float	m_BuyPrice;		//委买价
		float	m_SellPrice;	//委卖价
		float	m_BuyVol;		//申买量
		float	m_SellVol;		//申卖量
	};


	//品种明细
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct StkTraceData 
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^			Market;	//市场中文名
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^			Code;	//品种代码
		unsigned short	nCount;		//记录数目
		[MarshalAs(UnmanagedType::ByValArray, SizeConst = 1)]
		array<StockTraceData^>^	TraceData;
	};


	//合约信息
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct WStockInfo
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 66)]
		String^    szCode;     //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 128)]
		String^	szName;  //中文名称
		unsigned char	Precision;    //精度，小数点位数	
	};


	//单个市场的合约信息
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct WMarketInfo
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 40)]
		String^			Market;	//市场中文名
		unsigned short stocknum;//合约数目
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1)]
		array<WStockInfo^>^	stockdata;//合约信息数据
	};


	
	//基于IP连接的地址信息
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct AddressField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^					Ip;             //IP地址
		UInt16		    Port;           //端口号
	};



	//登录请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	 public ref struct LoginReqField
	{
		Byte		IsCaLogin;              //是否CA认证
		Byte		Identity;               //登录身份类型,目前只支持单客户
		Byte		IsForcePwd;             //是否强制修改密码
			
																	
		////union
		////{
		////	TClientNoType				ClientNo;			//客户号,代理客户号
		////	TOperatorNoType				OperatorNo;			//操作员号,代理操作员号
		////};
		////由于托管不存在Union,使用一个大字节代替
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ClientNo;

		/// 对应所使用的登录账号的密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^			LoginPwd;				//登录密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]	/// 强制修改密码时的新密码
		String^			NewPwd;					//强制修改密码登录时,新修改密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				OtpPass;                //otp认证密码
		int                 CaLen;                  //CA信息长度，IsCaLogin为'Y'时，本字段有效
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1)]
		String^					CaInfo;					//CA登录时填写,IsCaLogin为'Y'时，本字段有效
	};



	//登录应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct LoginRspField
	{
		EnumIsCaLoginType				IsCaLogin;              //是否CA认证
		EnumIsForcePasswordType		IsForcePwd;             //是否强制修改密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LoginNo;				//登录号    
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LoginName;				//登录端帐号简称
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^			ReservedInfo;			//客户预留信息,客户自己识别后台系统
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LastLoginDateTime;		//上次登录时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				LastLogoutDateTime;		//上次登出时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^						LastLoginIp;			//上次登录ip
		short					LastLoginPort;			//上次登录port
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 201)]
		String^			LastLoginMachineInfo;	//上次登录机器信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ServerDateTime;			//系统当前时间(客户端校时)
	};

	//报单请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderInsertReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			    CommodityNo;            //商品代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;             //合约代码
		Byte				OrderType;				//委托类型
		Byte				OrderWay;				//委托方式,单客户不用关注本字段
		Byte				OrderMode;				//委托模式
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ValidDateTime;			//有效日期(GTD情况下使用)
		Byte			    IsRiskOrder;			//风险报单
		Byte				Direct;					//买入卖出
		Byte				Offset;					//开仓平仓
		Byte				Hedge;					//投机保值
		double				OrderPrice;				//委托价格
		double				TriggerPrice;			//触发价格
		int				    OrderVol;				//委托数量
		int				    MinMatchVol;			//最小成交量

		Byte					Randomise;						//冰山单是否随机量发出 2012-11-2
		int				MinClipSize;					//冰山单最小随机量
		int				MaxClipSize;					//冰山单最大随机量

		int			        SaveInt;                //客户保留字段1
		double		        SaveDouble;             //客户保留字段2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^		        SaveString;             //客户保留字段3
	};

	//报单应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderInsertRspField
	{
		UInt16				OrderStreamId;					//委托流号
		int				OrderId;						//委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				LocalNo;						//本地号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				TradeNo;						//客户交易帐号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				InsertNo;						//下单人
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				InsertDateTime;					//下单时间
		Byte				OrderState;						//委托状态
		OrderInsertReqField^      ReqData;                        //报单请求数据
	};

	//委托状态变更通知
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderStateNoticeField
	{
		Byte				    OrderType;						//委托类型
		Byte					Offset;							//开平类型
		Byte					Hedge;							//投机保值类型

		double				    OrderPrice;				        //委托价
		double				    TriggerPrice;                   //触发价
		int				        OrderVol;						//委托数量

		unsigned int			OrderStreamId;                  //委托流号,每个状态通知唯一
		int				        OrderId;                        //委托ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				    LocalNo;                        //本地号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				    SystemNo;                       //系统号

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				    UpdateNo;		                //操作员编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				    UpdateDateTime;					//操作时间
		Byte				    OrderState;                     //委托状态
		double				    MatchPrice;                     //成交均价
		int				        MatchVol;                       //成交数量
		int				        ErrorCode;                      //包含错误时对应错误码

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				    ActionLocalNo;                  //报单操作的本地号

		OrderInsertReqField^    ReqData;                        //报单请求数据
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				    ExchangeSystemNo;				//交易所系统号

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				    ErrorText;						//原始错误信息.2015-09-15增加
	};

	//委托信息变更通知
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderInfoNoticeField
	{
		OrderInsertReqField^	ReqData;                            //报单的请求数据

		unsigned int					OrderStreamId;                  //委托流号
		int				OrderId;                        //委托ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				LocalNo;                        //本地号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                       //系统号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				ExchangeSystemNo;				//交易所系统号   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				TradeNo;                        //交易账号

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				InsertNo;                       //录入操作员号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				InsertDateTime;                 //录入时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				UpdateNo;						//最后一次变更人
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				UpdateDateTime;					//最后一次变更时间
		Byte				OrderState;                     //委托状态
		double				MatchPrice;                     //成交价格
		int				MatchVol;                       //成交数量
		int				ErrorCode;						//最后一次操作错误信息码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				ErrorText;						//原始错误信息.2015-09-15增加

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				ActionLocalNo;                  //报单操作的本地号
		Byte				OrderInput;						//是否录单
		Byte				Deleted;                        //是否删除
		Byte					AddOne;							//T+1标志
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				ParentSystemNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				UpperNo;//上手号。
	};

	//撤单请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderDeleteReqField
	{
		int				OrderId;                        //委托ID
	};


	//撤单应答结构
	//typedef TEsOrderStateNoticeField TEsOrderDeleteRspField;
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct  OrderDeleteRspField
	{
		OrderStateNoticeField^    OrderStateField;
		OrderInsertReqField^      ReqData;                        //报单请求数据
	};



	////改单请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOrderModifyReqField
	//{
	//	TOrderIdType				OrderId;                        //委托ID
	//	TTradePriceType				OrderPrice;				        //委托价格
	//	TTradePriceType				TriggerPrice;                   //触发价格
	//	TTradeVolType				OrderVol;	                    //委托数量
	//};

	//改单应答结构
	//typedef TEsOrderStateNoticeField TEsOrderModifyRspField;
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderModifyRspField
	{
		OrderStateNoticeField^    OrderStateField;
		OrderInsertReqField^      ReqData;                        //报单请求数据
	};

	//成交状态通知
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchStateNoticeField
	{
		unsigned int				MatchStreamId;              //成交流号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                   //系统号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;                    //成交号
		Byte				MatchMode;                  //成交模式
		Byte				MatchWay;                   //成交方式式
		double				MatchPrice;                 //成交价
		int				MatchVol;                   //成交数量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				MatchDateTime;              //成交时间
		double				MatchFee;                   //成交费用
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;					//手续费币种
		Byte					AddOne;						//T+1标记
		Byte				ManualFee;					//手工手续费
		Byte				Deleted;                    //删除标志
		int				OrderId;                    //委托ID
		int				MatchId;                    //成交ID
		double				CoverPrice;                 //平仓价格
	};

	//成交信息通知
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchInfoNoticeField
	{
		
		MatchStateNoticeField^    StateData;                  //成交状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;				//跨品种套利需要

		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;					//跨期套利需要
		Byte					Direct;						//套利报单需要
		Byte					Offset;						//互换报单需要
	};

	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderQryReqField
	{
		int				OrderStreamId;					//查询条件返回大于此流号的委托数据
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                       //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;                     //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;                    //商品
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;                     //合约
		Byte				OrderType;						//委托类型
		Byte				OrderMode;						//委托模式
		Byte			IsRiskOrder;					//风险报单
		Byte					Hedge;							//投机保值
		int				OrderId;                        //委托ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^				LocalNo;                        //本地号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                       //系统号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				OperNo;							//下单人或操作人号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				BeginInsertDateTime;            //起始时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				EndInsertDateTime;              //结束时间
		Byte				OrderState;                     //委托状态
	};
	
	
	//委托数据应答命令
	typedef OrderInfoNoticeField OrderDataQryRspField;

	//成交查询请求命令
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchQryReqField
	{
		int				MatchStreamId;              //成交流号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;                   //系统号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^				MatchNo;                    //成交号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				BeginMatchDateTime;         //起始时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				EndMatchDateTime;           //结束时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;                 //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;				//跨品种套利需要
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;					//跨期套利需要
	};

	//成交数据应答命令
	typedef MatchInfoNoticeField MatchDataQryRspField;

	//资金查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MoneyQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //客户号
	};

	//资金查询应答结构(注意次结构与资金变化通知结构的关系)
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MoneyQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;                 //货币编号
		double				YAvailable;					//昨可用
		double				YCanCashOut;				//昨可提
		double				YMoney;						//昨账面
		double				YBalance;					//昨权益
		double				YUnExpiredProfit;			//昨未结平盈
		double				Adjust;						//资金调整0
		double				CashIn;						//入金1
		double				CashOut;					//出金2
		double				Fee;						//手续费3
		double				Frozen;						//冻结资金4
		double				CoverProfit;				//逐笔平盈5
		double				DayCoverProfit;				//盯市平盈6
		double				FloatProfit;				//逐笔浮盈7
		double				DayFloatProfit;				//盯市浮盈8
		double				UnExpiredProfit;			//未结平盈9
		double				Premium;					//权利金10
		double				Deposit;					//保证金11
		double				KeepDeposit;				//维持保证金12
		double				Pledge;						//质押资金13
		double				TAvailable;					//可用资金14
		double				Discount;					//贴现金额15
		double				TradeFee;					//交易手续费16
		double				DeliveryFee;				//交割手续费17
		double				ExchangeFee;				//汇兑手续费18
		double				FrozenDeposit;				//冻结保证金19
		double				FrozenFee;					//冻结手续费20
		double				NewFloatProfit;				//浮盈(无LME)21
		double				LmeFloatProfit;				//LME浮盈22
		double				OptionMarketValue;			//期权市值23
		double				OriCash;					//币种原始出入金24(非自动汇兑资金)
		double              TMoney;                     //今资金
		double		        TBalance;					//今权益
		double		        TCanCashOut;				//今可提
		double		        RiskRate;					//风险率
		double		        AccountMarketValue;			//账户市值
	};
	////资金变化通知结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TMoneyChgItem
	//{
	//	TMoneyChgType				MoneyChg;
	//	TMoneyValueType				MoneyValue;
	//};

	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsMoneyChgNoticeField
	//{
	//	TClientNoType				ClientNo;                   //客户号
	//	TCurrencyNoType				CurrencyNo;                 //货币编号
	//	u_short						MoneyChgNum;                //资金变化项的个数
	//	TMoneyChgItem				MoneyItem[1];				//资金变化内容
	//};

	//持仓查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HoldQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;                 //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CommodityNo;                //商品
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;                 //合约
	};
	//持仓查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HoldQryRspField
	{
		int				HoldKeyId;                  //持仓关键字
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;                   //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;                //商品
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;                 //合约
		Byte					Direct;                     //买卖方向
		Byte					Hedge;                      //投机保值
		double				TradePrice;                 //持仓均价
		int				TradeVol;                   //持仓量
		double				YSettlePrice;               //昨结算价
		double				TNewPrice;                  //最新价
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				MatchDateTime;              //成交时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;                    //成交号
		double				Deposit;                    //保证金
		double				KeepDeposit;                //维持保证金
	};

	//商品查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CommodityQryReqField
	{
	};
	//商品查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CommodityQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;				//交易所
		Byte				CommodityType;			//商品类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CommodityNo;			//商品
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				RelateCommodityNo;		//依赖合约
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CommodityName;          //商品名称
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CommodityAttribute;     //商品属性
		Byte				CommodityState;         //商品状态
		double				ProductDot;             //每手乘数
		double				UpperTick;              //最小变动价分子
		int					LowerTick;              //最小变动价分母
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CurrencyNo;				//商品使用币种
		Byte				DeliveryMode;			//交割方式
		int					DeliveryDays;           //交割日偏移
		Byte				DepositCalculateMode;	//保证金计算方式
		int					MaxSingleOrderVol;		//单笔最大下单量
		int					MaxHoldVol;				//最大持仓量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				AddOneTime;				//T+1时间,大于此时间为T+1数据
		Byte				CmbDirect;				//组合买卖方向(第一腿)
		Byte				CoverMode;              //平仓方式
	};

	////商品状态变化通知结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCommodityStateModNoticeField
	//{
	//	TCommodityNoType			CommodityNo;					//上边三个字段为商品关键字
	//	TCommodityStateType			CommodityState;
	//	TTradeVolType				MaxSingleOrderVol;				//单笔最大下单量
	//	TTradeVolType				MaxHoldVol;						//最大持仓量
	//};

	////合约查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsContractQryReqField
	//{
	//	TCommodityNoType			CommodityNo;            //商品
	//	TContractLastDays			LastDays;		        //临近日期数

	//};

	//合约查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ContractQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;			//商品
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;				//合约
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^			ContractName;			//合约名称
		Byte			ContractType;			//合约类型
		Byte			ContractState;			//合约状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^					ExpiryDate;				//到期日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						LastTradeDate;			//最后交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						FirstNoticeDate;		//首次通知日
	};

	////合约增加通知结构
	//typedef TEsContractQryRspField	TEsContractAddNoticeField;

	////客户密码修改请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsClientPasswordModifyReqField
	//{
	//	TClientNoType				ClientNo;               //客户号
	//	TPasswordTypeType			PasswordType;           //密码类型
	//	TLoginPasswordType			OldPassword;			//操作员修改客户密码时,有权限操作员可以不填写旧密码					
	//	TLoginPasswordType			NewPassword;            //新密码
	//};

	//客户密码修改应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ClientPasswordModifyRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;               //客户号
		Byte			    PasswordType;           //密码类型
	};

	////操作员密码修改请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorPasswordModifyReqField
	//{
	//	TOperatorNoType				OperatorNo;				//操作员号
	//	TLoginPasswordType			OldPassword;		    //旧密码
	//	TLoginPasswordType			NewPassword;			//新密码
	//};
	////操作员密码修改应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorPasswordModifyRspField
	//{
	//	TOperatorNoType				OperatorNo;			    //操作员号
	//};

	//市场查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ExchangeQryReqField
	{
	};
	////市场查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsExchangeQryRspField
	//{
	//	TExchangeNoType				ExchangeNo;		        //交易所
	//	TExchangeNameType			ExchangeName;		    //交易所名称
	//	TExchangeStateType			ExchangeState;		    //交易所状态
	//};

	//市场状态修改通知结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct ExchangeStateModifyNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				ExchangeNo;
		Byte			ExchangeState;
	};

	////操作员下属客户查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorClientQryReqField
	//{
	//	TOperatorNoType				OperatorNo;			    //操作员号
	//};
	////操作员下属客户查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOperatorClientQryRspField
	//{
	//	TClientNoType				ClientNo;			    //客户号
	//};

	//历史委托查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisOrderQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;				//客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						BeginDate;				//起始日期，必填
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						EndDate;				//结束日期，必填
	};

	//历史委托查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisOrderQryRspField
	{
		OrderInfoNoticeField^     Data;				    //委托数据
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^					Date;                   //委托日期
	};

	//历史成交查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisMatchQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;				//客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						BeginDate;				//起始日期，必填
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^						EndDate;				//结束日期，必填
		Byte			IsContainTotle;			//是否包含合计值
	};

	//历史成交查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct HisMatchQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^					Date;				    //结算日期
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;				//客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				SettleNo;				//结算用成交编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^			CommodityNo;			//商品
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				ContractNo;				//合约
		Byte				MatchWay;				//成交方式
		Byte					Direct;                 //买卖方向
		Byte					Offset;                 //开平类型
		int				MatchVol;               //成交数量
		double				MatchPrice;             //成交价格
		double				Premium;                //权利金
		double              Turnover;        //成交金额
		double				ClientFee;				//客户手续费
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				GroupNo;				//结算分组
		double				ManualFee;				//人工手续费
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;             //币种
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CommodityCurrencyNo;    //品种币种
		Byte			IsRiskOrder;            //是否风险报单
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;               //系统号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;                //成交号
		int				MatchStreamID;          //成交流号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				MatchDateTime;          //成交时间
		Byte				MatchMode;              //是否风险报单
		Byte				OrderType;              //委托类型
		double				CoverPrice;             //平仓价格
		double				CoverProfit;			//平仓盈亏
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				UpperNo;				//历史成交上手号
	};

	////委托变更流程查询请求命令
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsOrderProcessQryReqField
	//{
	//	TOrderIdType				OrderId;                //委托ID
	//};

	////委托变更流程查询应答命令
	//typedef TEsOrderStateNoticeField TEsOrderProcessQryRspField;

	////历史委托流程查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisOrderProcessQryReqField
	//{
	//	TOrderIdType				OrderId;                //委托ID
	//	TDateType					Date;                   //查询日期
	//};

	////历史委托流程查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisOrderProcessQryRspField
	//{
	//	TEsOrderProcessQryRspField  Data;                   //委托流程数据
	//	TDateType			        Date;                   //日期
	//};

	//出金入金查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CashOperQryReqField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				ClientNo;               //客户号
	};
	//出金入金查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CashOperQryRspField
	{
		CashOperQryReqField      ReqData;                //查询请求数据
		int			SerialId;               //出入金流水号
		Byte				CashState;              //出入金状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				OperDateTime;           //操作时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				OperatorNo;             //操作人
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CheckDateTime;          //审核时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CheckOperatorNo;        //审核人

		Byte				CashType;               //出入金类型
		Byte				CashMode;               //出入金方式
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;             //货币编号
		double				CashValue;              //操作金额
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^				CashRemark;             //备注
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^				ClientBank;				//客户银行标识
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				ClientAccount;			//客户银行账户
		Byte				ClientLWFlag;			//客户本外币账户标识
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		Byte				CompanyBank;			//公司银行标识
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^				CompanyAccount;			//公司银行账户
		Byte				CompanyLWFlag;			//公司本外币账户标识
	};

	////出金入金操作请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCashOperReqField
	//{
	//	TClientNoType				ClientNo;				//客户号
	//	TCashTypeType				CashType;				//出入金类型
	//	TCashModeType				CashMode;				//出入金方式
	//	TCurrencyNoType				CurrencyNo;				//货币编号
	//	TMoneyValueType				CashValue;				//操作金额
	//	TCashRemarkType				CashRemark;				//备注
	//	TBankType					ClientBank;				//客户银行标识
	//	TAccountType				ClientAccount;			//客户银行账户
	//	TLWFlagType					ClientLWFlag;			//客户本外币账户标识
	//	TBankType					CompanyBank;			//公司银行标识
	//	TAccountType				CompanyAccount;			//公司银行账户
	//	TLWFlagType					CompanyLWFlag;			//公司本外币账户标识
	//};

	////出金入金操作应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCashOperRspField
	//{
	//	TEsCashOperReqField			ReqData;				//出入金操作请求数据
	//	TCashSerialIdType			SerialId;				//出入金流水号
	//	TCashStateType				CashState;				//出入金状态
	//	TDateTimeType				OperDateTime;			//操作时间
	//	TOperatorNoType				OperatorNo;				//操作人
	//	TDateTimeType				CheckDateTime;			//审核时间
	//	TOperatorNoType				CheckOperatorNo;		//审核人
	//};

	////出金入金操作通知结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//typedef TEsCashOperRspField TEsCashOperNoticeField;

	////出金入金审核请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsCashCheckReqField
	//{
	//	TCashSerialIdType			SerialId;				//出入金流水号
	//	TCashStateType				CashState;				//出入金状态
	//	TForceCashOutFlagType		ForceCashOutFlag;		//是否强制出金标记
	//};

	////出金入金审核应答结构
	//typedef TEsCashOperRspField TEsCashCheckRspField;

	////出金入金审核通知结构
	//typedef TEsCashOperRspField TEsCashCheckNoticeField;

	////资金调整查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsAdjustQryReqField
	//{
	//	TClientNoType				ClientNo;               //客户号
	//};

	////资金调整查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsAdjustQryRspField
	//{
	//	TEsAdjustQryReqField        ReqData;                //查询请求数据
	//	TAdjustSerialIdType			SerialId;               //出入金流水号
	//	TAdjustStateType			AdjustState;            //资金调整状态   
	//	TDateTimeType				OperDateTime;           //操作时间
	//	TOperatorNoType				OperatorNo;             //操作人
	//	TDateTimeType				CheckDateTime;          //审核时间
	//	TOperatorNoType				CheckOperatorNo;        //审核人

	//	TAdjustTypeType				AdjustType;             //资金调整类型
	//	TCurrencyNoType				CurrencyNo;             //货币编号
	//	TMoneyValueType				AdjustValue;            //操作金额
	//	TAdjustRemarkType			AdjustRemark;           //备注
	//														//20120616增加
	//	TBankType					ClientBank;				//银行标识
	//	TAccountType				ClientAccount;			//银行账户
	//	TLWFlagType					ClientLWFlag;			//本外币账户标识
	//	TBankType					CompanyBank;			//银行标识
	//	TAccountType				CompanyAccount;			//银行账户
	//	TLWFlagType					CompanyLWFlag;			//本外币账户标识
	//};

	////历史出入金查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisCashOperQryReqField
	//{
	//	TClientNoType				ClientNo;				//客户号
	//	TDateType					BeginDate;				//起始日期
	//	TDateType					EndDate;				//终止日期
	//};

	////历史出入金查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisCashOperQryRspField
	//{
	//	TEsCashOperQryRspField		Data;
	//	TDateType					Date;
	//};

	////历史资金调整查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisAdjustQryReqField
	//{
	//	TClientNoType				ClientNo;				//客户号
	//	TDateType					BeginDate;				//起始日期
	//	TDateType					EndDate;				//终止日期
	//};
	////历史资金调整查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHisAdjustQryRspField
	//{
	//	TEsAdjustQryRspField		Data;
	//	TDateType					Date;
	//};

	////客户认证密码验证请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsClientPasswordAuthReqField
	//{
	//	TClientNoType				ClientNo;
	//	TLoginPasswordType			Password;
	//};
	////客户认证密码验证应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsClientPasswordAuthRspField
	//{
	//	TClientNoType				ClientNo;
	//};

	//币种查询请求结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CurrencyQryReqField
	{
	};
	//币种查询应答结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct CurrencyQryRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^				CurrencyNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^				CurrencyName;
		Byte				IsPrimary;
		Byte				CurrencyGroup;
		double				ExchangeRate;
	};

	//删除委托通知结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct OrderRemoveNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^               ClientNo;
		int				OrderId;
	};

	//删除成交通知结构
	[StructLayout(LayoutKind::Sequential,Pack=1)]
	public ref struct MatchRemoveNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^             ClientNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]
		String^				SystemNo;
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 71)]
		String^				MatchNo;
		int				    MatchId;
	};

	////汇率变更通知
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsExchangeRateModifyNoticeField
	//{
	//	TCurrencyNoType				CurrencyNo;
	//	TExchangeRateType			ExchangeRate;
	//};

	////监控事件查询请求结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsMonitorEventQryReqField
	//{
	//};

	////监控事件查询应答结构
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsMonitorEventQryRspField
	//{
	//	TEventTypeType				EventType;
	//	TEventLevelType				EventLevel;
	//	TEventSourceType			EventSource;
	//	TEventContentType			EventContent;
	//	TEventSerialIdType			SerialId;
	//	TDateTimeType				EventDateTime;
	//};

	////监控事件通知结构
	//typedef TEsMonitorEventQryRspField	TEsMonitorEventNoticeField;

	////港交所做市商报价请求---客户端用
	//[StructLayout(LayoutKind::Sequential,Pack=1)]
	//public ref struct TEsHKMarketOrderReq
	//{
	//	TClientNoType					ClientNo;
	//	TCommodityNoType				CommodityNo;
	//	TContractNoType					ContractNo;

	//	TOrderTypeType					OrderType;						//委托类型
	//	TOrderModeType					OrderMode;						//委托模式
	//	TDateTimeType					ValidDateTime;

	//	TTradePriceType					BuyPrice;
	//	TTradePriceType					SellPrice;

	//	TTradeVolType					BuyVol;
	//	TTradeVolType					SellVol;

	//	THKMarketOperType				BuyOper;
	//	THKMarketOperType				SellOper;

	//	TOrderIdType					BuyOrderID;
	//	TOrderIdType					SellOrderID;

	//	TOrderSaveStringType			SaveString;
	//};
	//typedef TEsHKMarketOrderReq TEsHKMarketOrderRsp;

	////客户计算参数查询请求结构

	//public ref public ref struct TClientCountRentQryReq
	//{
	//	TClientNoType				ClientNo;
	//	TCommodityNoType			CommodityNo;
	//	TContractNoType				ContractNo;			//可填空
	//	TMatchWayType				MatchWay;
	//};
	////客户结算参数查询应答结构
	//public ref public ref struct TClientCountRentQryRsp
	//{
	//	TClientCountRentQryReq		ReqData;

	//	TMoneyValueType				BFee;
	//	TMoneyValueType				DFee;
	//	TCurrencyNoType				CurrencyNo;

	//	TDepositModeType			DepositMode;		//仅比例和定额
	//	TMoneyValueType				Deposit;			//正常保证金
	//	TMoneyValueType				LockDeposit;		//锁仓保证金
	//	TMoneyValueType				KeepDeposit;		//维持保证金
	//};

}
