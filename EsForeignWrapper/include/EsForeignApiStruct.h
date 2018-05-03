#ifndef _ESUNNY_FOREIGN_TRADE_API_STRUCT_H
#define _ESUNNY_FOREIGN_TRADE_API_STRUCT_H

#include "EsForeignApiType.h"
#include "string.h"
#pragma pack(push, 1)

namespace ESForeign
{
    //基于IP连接的地址信息
    struct TEsAddressField
    {
        TIpType					Ip;             //IP地址
        TPortType				Port;           //端口号
    };

    //登录请求结构
    struct TEsLoginReqField
    {    
        TIsCaLoginType				IsCaLogin;              //是否CA认证
        TEsLoginIdentityType		Identity;               //登录身份类型
        TIsForcePasswordType		IsForcePwd;             //是否强制修改密码
        /// 使用不同账户登录时共用登录号
        union														
        {
            TClientNoType				ClientNo;			//客户号,代理客户号
            TOperatorNoType				OperatorNo;			//操作员号,代理操作员号
        };
        /// 对应所使用的登录账号的密码
        TLoginPasswordType			LoginPwd;				//登录密码
        /// 强制修改密码时的新密码
        TLoginPasswordType			NewPwd;					//强制修改密码登录时,新修改密码
        TOtpPassType				OtpPass;                //otp认证密码
        TEsSizeType                 CaLen;                  //CA信息长度，IsCaLogin为'Y'时，本字段有效
        TCaInfoType					CaInfo;					//CA登录时填写,IsCaLogin为'Y'时，本字段有效
    };
    //登录应答结构
    struct TEsLoginRspField
    {
        TIsCaLoginType				IsCaLogin;              //是否CA认证
        TIsForcePasswordType		IsForcePwd;             //是否强制修改密码
        TLoginNoType				LoginNo;				//登录号            
        TLoginNameType				LoginName;				//登录端帐号简称
        TReservedInfoType			ReservedInfo;			//客户预留信息,客户自己识别后台系统
        TDateTimeType				LastLoginDateTime;		//上次登录时间
        TDateTimeType				LastLogoutDateTime;		//上次登出时间
        TIpType						LastLoginIp;			//上次登录ip
        TPortType					LastLoginPort;			//上次登录port
        TMachineInfoType			LastLoginMachineInfo;	//上次登录机器信息
        TDateTimeType				ServerDateTime;			//系统当前时间(客户端校时)
    };


    //报单请求结构
    struct TEsOrderInsertReqField
    {
        TClientNoType				ClientNo;
        TCommodityNoType			CommodityNo;            //商品代码
        TContractNoType				ContractNo;             //合约代码
        TOrderTypeType				OrderType;				//委托类型
        TOrderWayType				OrderWay;				//委托方式,单客户不用关注本字段
        TOrderModeType				OrderMode;				//委托模式
        TDateTimeType				ValidDateTime;			//有效日期(GTD情况下使用)
        TIsRiskOrderType			IsRiskOrder;			//风险报单
        TDirectType					Direct;					//买入卖出
        TOffsetType					Offset;					//开仓平仓
        THedgeType					Hedge;					//投机保值
        TTradePriceType				OrderPrice;				//委托价格
        TTradePriceType				TriggerPrice;			//触发价格
        TTradeVolType				OrderVol;				//委托数量
        TTradeVolType				MinMatchVol;			//最小成交量

		TRandomise					Randomise;						//冰山单是否随机量发出 2012-11-2
		TTradeVolType				MinClipSize;					//冰山单最小随机量
		TTradeVolType				MaxClipSize;					//冰山单最大随机量
        
        TOrderSaveIntType			SaveInt;                //客户保留字段1
        TOrderSaveDoubleType		SaveDouble;             //客户保留字段2
        TOrderSaveStringType		SaveString;             //客户保留字段3
        
	public:
		TEsOrderInsertReqField()
		{
			memset(this, 0, sizeof(TEsOrderInsertReqField));
		}
    };

    //报单应答结构
    struct TEsOrderInsertRspField
    {
        TStreamIdType				OrderStreamId;					//委托流号
        TOrderIdType				OrderId;						//委托号
        TFeLocalNoType				LocalNo;						//本地号
        TTradeNoType				TradeNo;						//客户交易帐号

        TOperatorNoType				InsertNo;						//下单人
        TDateTimeType				InsertDateTime;					//下单时间
        TOrderStateType				OrderState;						//委托状态
		TUpperNoType				UpperNo;						//使用上手(会员号)
        TEsOrderInsertReqField      ReqData;                        //报单请求数据
    };

    //委托状态变更通知
    struct TEsOrderStateNoticeField
    {	
        TOrderTypeType				OrderType;						//委托类型
        TOffsetType					Offset;							//开平类型
        THedgeType					Hedge;							//投机保值类型

        TTradePriceType				OrderPrice;				        //委托价
        TTradePriceType				TriggerPrice;                   //触发价
        TTradeVolType				OrderVol;						//委托数量

        TStreamIdType				OrderStreamId;                  //委托流号,每个状态通知唯一
        TOrderIdType				OrderId;                        //委托ID
        TFeLocalNoType				LocalNo;                        //本地号
        TSystemNoType				SystemNo;                       //系统号

        TOperatorNoType				UpdateNo;		                //操作员编号
        TDateTimeType				UpdateDateTime;					//操作时间
        TOrderStateType				OrderState;                     //委托状态
        TTradePriceType				MatchPrice;                     //成交均价
        TTradeVolType				MatchVol;                       //成交数量
        TErrorCodeType				ErrorCode;                      //包含错误时对应错误码

        TFeLocalNoType				ActionLocalNo;                  //报单操作的本地号
        TEsOrderInsertReqField      ReqData;                        //报单请求数据
	TSystemNoType				ExchangeSystemNo;				//交易所系统号

	TErrorTextType				ErrorText;						//原始错误信息.2015-09-15增加
    };

    //委托信息变更通知
    struct TEsOrderInfoNoticeField
    {
        TEsOrderInsertReqField	ReqData;                            //报单的请求数据

        TStreamIdType				OrderStreamId;                  //委托流号
        TOrderIdType				OrderId;                        //委托ID
        TFeLocalNoType				LocalNo;                        //本地号
        TSystemNoType				SystemNo;                       //系统号
        TSystemNoType				ExchangeSystemNo;				//交易所系统号            
        TTradeNoType				TradeNo;                        //交易账号
        
        TOperatorNoType				InsertNo;                       //录入操作员号
        TDateTimeType				InsertDateTime;                 //录入时间
        TOperatorNoType				UpdateNo;						//最后一次变更人
        TDateTimeType				UpdateDateTime;					//最后一次变更时间
        TOrderStateType				OrderState;                     //委托状态
        TTradePriceType				MatchPrice;                     //成交价格
        TTradeVolType				MatchVol;                       //成交数量
        TErrorCodeType				ErrorCode;						//最后一次操作错误信息码
	TErrorTextType				ErrorText;						//原始错误信息.2015-09-15增加
    
        TFeLocalNoType				ActionLocalNo;                  //报单操作的本地号
        TOrderInputType				OrderInput;						//是否录单
        TDeletedType				Deleted;                        //是否删除
        TAddOneType                             AddOne;                 //T+1标志
        
        TSystemNoType				ParentSystemNo;	
		TUpperNoType				UpperNo;//上手号。
    };

    //撤单请求结构
    struct TEsOrderDeleteReqField
    {
        TOrderIdType				OrderId;                        //委托ID
    };

    //撤单应答结构
    //typedef TEsOrderStateNoticeField TEsOrderDeleteRspField;
    struct  TEsOrderDeleteRspField
    {
        TEsOrderStateNoticeField    OrderStateField;

        TEsOrderInsertReqField      ReqData;                        //报单请求数据
    };

    //改单请求结构
    struct TEsOrderModifyReqField
    {
        TOrderIdType				OrderId;                        //委托ID
        TTradePriceType				OrderPrice;				        //委托价格
        TTradePriceType				TriggerPrice;                   //触发价格
        TTradeVolType				OrderVol;	                    //委托数量
    };

    //改单应答结构
    //typedef TEsOrderStateNoticeField TEsOrderModifyRspField;
    struct TEsOrderModifyRspField
    {
        TEsOrderStateNoticeField    OrderStateField;

        TEsOrderInsertReqField      ReqData;                        //报单请求数据
    };

    //成交状态通知
    struct TEsMatchStateNoticeField
    {
        TStreamIdType				MatchStreamId;              //成交流号
        TClientNoType				ClientNo;                   //客户号
        TSystemNoType				SystemNo;                   //系统号
        TMatchNoType				MatchNo;                    //成交号
        TMatchModeType				MatchMode;                  //成交模式
        TMatchWayType				MatchWay;                   //成交方式式
        TTradePriceType				MatchPrice;                 //成交价
        TTradeVolType				MatchVol;                   //成交数量
        TDateTimeType				MatchDateTime;              //成交时间
        TMoneyValueType				MatchFee;                   //成交费用
        TCurrencyNoType				CurrencyNo;					//手续费币种
        TAddOneType					AddOne;						//T+1标记
        TManualFeeType				ManualFee;					//手工手续费
        TDeletedType				Deleted;                    //删除标志
        TOrderIdType				OrderId;                    //委托ID
        TOrderIdType				MatchId;                    //成交ID
        TTradePriceType				CoverPrice;                 //平仓价格
    };

    //成交信息通知
    struct TEsMatchInfoNoticeField
    {
        TEsMatchStateNoticeField    StateData;                  //成交状态
        TCommodityNoType			CommodityNo;				//跨品种套利需要
        TContractNoType				ContractNo;					//跨期套利需要
        TDirectType					Direct;						//套利报单需要
        TOffsetType					Offset;						//互换报单需要
    };

    struct TEsOrderQryReqField
    {
        TStreamIdType				OrderStreamId;					//查询条件返回大于此流号的委托数据
        TClientNoType				ClientNo;                       //客户号
        TExchangeNoType				ExchangeNo;                     //交易所
        TCommodityNoType			CommodityNo;                    //商品
        TContractNoType				ContractNo;                     //合约
        TOrderTypeType				OrderType;						//委托类型
        TOrderModeType				OrderMode;						//委托模式
        TIsRiskOrderType			IsRiskOrder;					//风险报单
        THedgeType					Hedge;							//投机保值
        TOrderIdType				OrderId;                        //委托ID
        TFeLocalNoType				LocalNo;                        //本地号
        TSystemNoType				SystemNo;                       //系统号
        TOperatorNoType				OperNo;							//下单人或操作人号
        TDateTimeType				BeginInsertDateTime;            //起始时间
        TDateTimeType				EndInsertDateTime;              //结束时间
        TOrderStateType				OrderState;                     //委托状态
    };
    //委托数据应答命令
    typedef TEsOrderInfoNoticeField TEsOrderDataQryRspField;

    //成交查询请求命令
    struct TMatchQryReqField
    {
        TStreamIdType				MatchStreamId;              //成交流号
        TClientNoType				ClientNo;                   //客户号
        TSystemNoType				SystemNo;                   //系统号
        TMatchNoType				MatchNo;                    //成交号
        TDateTimeType				BeginMatchDateTime;         //起始时间
        TDateTimeType				EndMatchDateTime;           //结束时间
        TExchangeNoType				ExchangeNo;                 //交易所
        TCommodityNoType			CommodityNo;				//跨品种套利需要
        TContractNoType				ContractNo;					//跨期套利需要
    };

    //成交数据应答命令
    typedef TEsMatchInfoNoticeField TEsMatchDataQryRspField;

    //资金查询请求结构
    struct TEsMoneyQryReqField
    {
        TClientNoType				ClientNo;                   //客户号
    };

    //资金查询应答结构(注意次结构与资金变化通知结构的关系)
    struct TEsMoneyQryRspField
    {
        TClientNoType				ClientNo;                   //客户号
        TCurrencyNoType				CurrencyNo;                 //货币编号
        TMoneyValueType				YAvailable;					//昨可用
        TMoneyValueType				YCanCashOut;				//昨可提
        TMoneyValueType				YMoney;						//昨账面
        TMoneyValueType				YBalance;					//昨权益
        TMoneyValueType				YUnExpiredProfit;			//昨未结平盈
        TMoneyValueType				Adjust;						//资金调整0
        TMoneyValueType				CashIn;						//入金1
        TMoneyValueType				CashOut;					//出金2
        TMoneyValueType				Fee;						//手续费3
        TMoneyValueType				Frozen;						//冻结资金4
        TMoneyValueType				CoverProfit;				//逐笔平盈5
        TMoneyValueType				DayCoverProfit;				//盯市平盈6
        TMoneyValueType				FloatProfit;				//逐笔浮盈7
        TMoneyValueType				DayFloatProfit;				//盯市浮盈8
        TMoneyValueType				UnExpiredProfit;			//未结平盈9
        TMoneyValueType				Premium;					//权利金10
        TMoneyValueType				Deposit;					//保证金11
        TMoneyValueType				KeepDeposit;				//维持保证金12
        TMoneyValueType				Pledge;						//质押资金13
        TMoneyValueType				TAvailable;					//可用资金14
        TMoneyValueType				Discount;					//贴现金额15
        TMoneyValueType				TradeFee;					//交易手续费16
        TMoneyValueType				DeliveryFee;				//交割手续费17
        TMoneyValueType				ExchangeFee;				//汇兑手续费18
        TMoneyValueType				FrozenDeposit;				//冻结保证金19
        TMoneyValueType				FrozenFee;					//冻结手续费20
        TMoneyValueType				NewFloatProfit;				//浮盈(无LME)21
        TMoneyValueType				LmeFloatProfit;				//LME浮盈22
        TMoneyValueType				OptionMarketValue;			//期权市值23
        TMoneyValueType				OriCash;					//币种原始出入金24(非自动汇兑资金)
        TMoneyValueType             TMoney;                     //今资金
        TMoneyValueType		        TBalance;					//今权益
        TMoneyValueType		        TCanCashOut;				//今可提
        TMoneyValueType		        RiskRate;					//风险率
        TMoneyValueType		        AccountMarketValue;			//账户市值
		TMoneyValueType             AuthMoney;					//授信资金25  历史累计
		TMoneyValueType				TransitMoney;				//在途可用资金27
    };
    //资金变化通知结构
	struct TMoneyChgItem
	{
		TMoneyChgType				MoneyChg;
		TMoneyValueType				MoneyValue;
	};

    struct TEsMoneyChgNoticeField
    {
        TClientNoType				ClientNo;                   //客户号
        TCurrencyNoType				CurrencyNo;                 //货币编号
        u_short						MoneyChgNum;                //资金变化项的个数
        TMoneyChgItem				MoneyItem[1];				//资金变化内容
    };

    //持仓查询请求结构
    struct TEsHoldQryReqField
    {
        TClientNoType				ClientNo;                   //客户号
        TExchangeNoType				ExchangeNo;                 //交易所
        TCommodityNoType			CommodityNo;                //商品
        TContractNoType				ContractNo;                 //合约
    };
    //持仓查询应答结构
    struct TEsHoldQryRspField
    {
        THoldKeyIdType				HoldKeyId;                  //持仓关键字
        TClientNoType				ClientNo;                   //客户号
        TCommodityNoType			CommodityNo;                //商品
        TContractNoType				ContractNo;                 //合约
        TDirectType					Direct;                     //买卖方向
        THedgeType					Hedge;                      //投机保值
        TTradePriceType				TradePrice;                 //持仓均价
        TTradeVolType				TradeVol;                   //持仓量
        TQuotePriceType				YSettlePrice;               //昨结算价
        TQuotePriceType				TNewPrice;                  //最新价
        TDateTimeType				MatchDateTime;              //成交时间
        TMatchNoType				MatchNo;                    //成交号
        TMoneyValueType				Deposit;                    //保证金
        TMoneyValueType				KeepDeposit;                //维持保证金
		TUpperNoType				UpperNo;					//持仓上手号
    };

    //商品查询请求结构
    struct TEsCommodityQryReqField
    {
    };
    //商品查询应答结构
    struct TEsCommodityQryRspField
    {
        TExchangeNoType				ExchangeNo;				//交易所
        TCommodityTypeType			CommodityType;			//商品类型
        TCommodityNoType			CommodityNo;			//商品
        TCommodityNoType			RelateCommodityNo;		//依赖合约
        TCommodityNameType			CommodityName;          //商品名称
        TCommodityAttributeType		CommodityAttribute;     //商品属性
        TCommodityStateType			CommodityState;         //商品状态
        TProductDotType				ProductDot;             //每手乘数
        TUpperTickType				UpperTick;              //最小变动价分子
        TLowerTickType				LowerTick;              //最小变动价分母
        TCurrencyNoType				CurrencyNo;				//商品使用币种
        TDeliveryModeType			DeliveryMode;			//交割方式
        TDeliveryDaysType			DeliveryDays;           //交割日偏移
        TDepositCalculateModeType	DepositCalculateMode;	//保证金计算方式
        TTradeVolType				MaxSingleOrderVol;		//单笔最大下单量
        TTradeVolType				MaxHoldVol;				//最大持仓量
        TTimeType					AddOneTime;				//T+1时间,大于此时间为T+1数据
        TDirectType					CmbDirect;				//组合买卖方向(第一腿)
        TCoverModeType				CoverMode;              //平仓方式
    };

    //商品状态变化通知结构
    struct TEsCommodityStateModNoticeField
    {
        TCommodityNoType			CommodityNo;					//上边三个字段为商品关键字
        TCommodityStateType			CommodityState;
        TTradeVolType				MaxSingleOrderVol;				//单笔最大下单量
        TTradeVolType				MaxHoldVol;						//最大持仓量
    };

    //合约查询请求结构
    struct TEsContractQryReqField
    {
        TCommodityNoType			CommodityNo;            //商品
        TContractLastDays			LastDays;		        //临近日期数

    };
    //合约查询应答结构
    struct TEsContractQryRspField
    {
        TCommodityNoType			CommodityNo;			//商品
        TContractNoType				ContractNo;				//合约
        TContractNameType			ContractName;			//合约名称
        TContractTypeType			ContractType;			//合约类型
        TContractStateType			ContractState;			//合约状态
        TDateType					ExpiryDate;				//到期日
        TDateType					LastTradeDate;			//最后交易日
        TDateType					FirstNoticeDate;		//首次通知日
    };

    //合约增加通知结构
    typedef TEsContractQryRspField	TEsContractAddNoticeField;

    //客户密码修改请求结构
    struct TEsClientPasswordModifyReqField
    {
        TClientNoType				ClientNo;               //客户号
        TPasswordTypeType			PasswordType;           //密码类型
        TLoginPasswordType			OldPassword;			//操作员修改客户密码时,有权限操作员可以不填写旧密码					
        TLoginPasswordType			NewPassword;            //新密码
    };
    //客户密码修改应答结构
    struct TEsClientPasswordModifyRspField
    {
        TClientNoType				ClientNo;               //客户号
        TPasswordTypeType			PasswordType;           //密码类型
    };

    //操作员密码修改请求结构
    struct TEsOperatorPasswordModifyReqField
    {
        TOperatorNoType				OperatorNo;				//操作员号
        TLoginPasswordType			OldPassword;		    //旧密码
        TLoginPasswordType			NewPassword;			//新密码
    };
    //操作员密码修改应答结构
    struct TEsOperatorPasswordModifyRspField
    {
        TOperatorNoType				OperatorNo;			    //操作员号
    };

    //市场查询请求结构
    struct TEsExchangeQryReqField
    {
    };
    //市场查询应答结构
    struct TEsExchangeQryRspField
    {
        TExchangeNoType				ExchangeNo;		        //交易所
        TExchangeNameType			ExchangeName;		    //交易所名称
        TExchangeStateType			ExchangeState;		    //交易所状态
    };

    //市场状态修改通知结构
    struct TEsExchangeStateModifyNoticeField
    {
        TExchangeNoType				ExchangeNo;
        TExchangeStateType			ExchangeState;
    };

    //操作员下属客户查询请求结构
    struct TEsOperatorClientQryReqField
    {
        TOperatorNoType				OperatorNo;			    //操作员号
    };
    //操作员下属客户查询应答结构
    struct TEsOperatorClientQryRspField
    {
        TClientNoType				ClientNo;			    //客户号
    };

    //历史委托查询请求结构
    struct TEsHisOrderQryReqField
    {
        TClientNoType				ClientNo;				//客户号
        TDateType					BeginDate;				//起始日期，必填
        TDateType					EndDate;				//结束日期，必填
    };

    //历史委托查询应答结构
    struct TEsHisOrderQryRspField
    {
        TEsOrderInfoNoticeField     Data;				    //委托数据	
        TDateType					Date;                   //委托日期
    };

    //历史成交查询请求结构
    struct TEsHisMatchQryReqField
    {
        TClientNoType				ClientNo;				//客户号
        TDateType					BeginDate;				//起始日期，必填
        TDateType					EndDate;				//结束日期，必填
        TContainTotleType			IsContainTotle;			//是否包含合计值
    };
    //历史成交查询应答结构
    struct TEsHisMatchQryRspField
    {
        TDateType					Date;				    //结算日期
        TClientNoType				ClientNo;				//客户号
        TMatchNoType				SettleNo;				//结算用成交编号
        TCommodityNoType			CommodityNo;			//商品
        TContractNoType				ContractNo;				//合约
        TMatchWayType				MatchWay;				//成交方式
        TDirectType					Direct;                 //买卖方向
        TOffsetType					Offset;                 //开平类型
        TTradeVolType				MatchVol;               //成交数量
        TTradePriceType				MatchPrice;             //成交价格
        TMoneyValueType				Premium;                //权利金
		TMoneyValueType				Turnover;				//成交金额
		TMoneyValueType				ClientFee;				//客户手续费
		TGroupNoType				GroupNo;				//结算分组
		TMoneyValueType				ManualFee;				//人工手续费
        TCurrencyNoType				CurrencyNo;             //币种
        TCurrencyNoType				CommodityCurrencyNo;    //品种币种
        TIsRiskOrderType			IsRiskOrder;            //是否风险报单
        TSystemNoType				SystemNo;               //系统号
        TMatchNoType				MatchNo;                //成交号
        TStreamIdType				MatchStreamID;          //成交流号
        TDateTimeType				MatchDateTime;          //成交时间
        TMatchModeType				MatchMode;              //是否风险报单
        TOrderTypeType				OrderType;              //委托类型
        TTradePriceType				CoverPrice;             //平仓价格
		TTradePriceType				CoverProfit;			//平仓盈亏
		TUpperNoType				UpperNo;				//历史成交上手号

    };

    //委托变更流程查询请求命令
    struct TEsOrderProcessQryReqField
    {
        TOrderIdType				OrderId;                //委托ID
    };

    //委托变更流程查询应答命令
    typedef TEsOrderStateNoticeField TEsOrderProcessQryRspField;

    //历史委托流程查询请求结构
    struct TEsHisOrderProcessQryReqField
    {
        TOrderIdType				OrderId;                //委托ID
        TDateType					Date;                   //查询日期
    };

    //历史委托流程查询应答结构
    struct TEsHisOrderProcessQryRspField
    {
        TEsOrderProcessQryRspField  Data;                   //委托流程数据
        TDateType			        Date;                   //日期
    };

    //出金入金查询请求结构
    struct TEsCashOperQryReqField
    {
        TClientNoType				ClientNo;               //客户号
    };
    //出金入金查询应答结构
    struct TEsCashOperQryRspField
    {
        TEsCashOperQryReqField      ReqData;                //查询请求数据
        TCashSerialIdType			SerialId;               //出入金流水号
        TCashStateType				CashState;              //出入金状态
        TDateTimeType				OperDateTime;           //操作时间
        TOperatorNoType				OperatorNo;             //操作人
        TDateTimeType				CheckDateTime;          //审核时间
        TOperatorNoType				CheckOperatorNo;        //审核人

        TCashTypeType				CashType;               //出入金类型
        TCashModeType				CashMode;               //出入金方式
        TCurrencyNoType				CurrencyNo;             //货币编号
        TMoneyValueType				CashValue;              //操作金额
        TCashRemarkType				CashRemark;             //备注
        //20120616增加
        TBankType					ClientBank;				//客户银行标识
        TAccountType				ClientAccount;			//客户银行账户
        TLWFlagType					ClientLWFlag;			//客户本外币账户标识
        TBankType					CompanyBank;			//公司银行标识
        TAccountType				CompanyAccount;			//公司银行账户
        TLWFlagType					CompanyLWFlag;			//公司本外币账户标识
    };

	//出金入金操作请求结构
	struct TEsCashOperReqField
	{
		TClientNoType				ClientNo;				//客户号
		TCashTypeType				CashType;				//出入金类型
		TCashModeType				CashMode;				//出入金方式
		TCurrencyNoType				CurrencyNo;				//货币编号
		TMoneyValueType				CashValue;				//操作金额
		TCashRemarkType				CashRemark;				//备注
		TBankType					ClientBank;				//客户银行标识
		TAccountType				ClientAccount;			//客户银行账户
		TLWFlagType					ClientLWFlag;			//客户本外币账户标识
		TBankType					CompanyBank;			//公司银行标识
		TAccountType				CompanyAccount;			//公司银行账户
		TLWFlagType					CompanyLWFlag;			//公司本外币账户标识
	};

	//出金入金操作应答结构
	struct TEsCashOperRspField
	{
		TEsCashOperReqField			ReqData;				//出入金操作请求数据
		TCashSerialIdType			SerialId;				//出入金流水号
		TCashStateType				CashState;				//出入金状态
		TDateTimeType				OperDateTime;			//操作时间
		TOperatorNoType				OperatorNo;				//操作人
		TDateTimeType				CheckDateTime;			//审核时间
		TOperatorNoType				CheckOperatorNo;		//审核人
	};

	//出金入金操作通知结构
	typedef TEsCashOperRspField TEsCashOperNoticeField;

	//出金入金审核请求结构
	struct TEsCashCheckReqField
	{
		TCashSerialIdType			SerialId;				//出入金流水号
		TCashStateType				CashState;				//出入金状态
		TForceCashOutFlagType		ForceCashOutFlag;		//是否强制出金标记
	};

	//出金入金审核应答结构
	typedef TEsCashOperRspField TEsCashCheckRspField;

	//出金入金审核通知结构
	typedef TEsCashOperRspField TEsCashCheckNoticeField;

    //资金调整查询请求结构
    struct TEsAdjustQryReqField
    {
        TClientNoType				ClientNo;               //客户号
    };

    //资金调整查询应答结构
    struct TEsAdjustQryRspField
    {
        TEsAdjustQryReqField        ReqData;                //查询请求数据
        TAdjustSerialIdType			SerialId;               //出入金流水号
        TAdjustStateType			AdjustState;            //资金调整状态   
        TDateTimeType				OperDateTime;           //操作时间
        TOperatorNoType				OperatorNo;             //操作人
        TDateTimeType				CheckDateTime;          //审核时间
        TOperatorNoType				CheckOperatorNo;        //审核人

        TAdjustTypeType				AdjustType;             //资金调整类型
        TCurrencyNoType				CurrencyNo;             //货币编号
        TMoneyValueType				AdjustValue;            //操作金额
        TAdjustRemarkType			AdjustRemark;           //备注
        //20120616增加
        TBankType					ClientBank;				//银行标识
        TAccountType				ClientAccount;			//银行账户
        TLWFlagType					ClientLWFlag;			//本外币账户标识
        TBankType					CompanyBank;			//银行标识
        TAccountType				CompanyAccount;			//银行账户
        TLWFlagType					CompanyLWFlag;			//本外币账户标识
    };

    //历史出入金查询请求结构
    struct TEsHisCashOperQryReqField
    {
        TClientNoType				ClientNo;				//客户号
        TDateType					BeginDate;				//起始日期
        TDateType					EndDate;				//终止日期
    };

    //历史出入金查询应答结构
    struct TEsHisCashOperQryRspField
    {
        TEsCashOperQryRspField		Data;
        TDateType					Date;
    };

    //历史资金调整查询请求结构
    struct TEsHisAdjustQryReqField
    {
        TClientNoType				ClientNo;				//客户号
        TDateType					BeginDate;				//起始日期
        TDateType					EndDate;				//终止日期
    };
    //历史资金调整查询应答结构
    struct TEsHisAdjustQryRspField
    {
        TEsAdjustQryRspField		Data;
        TDateType					Date;
    };

    //客户认证密码验证请求结构
    struct TEsClientPasswordAuthReqField
    {
        TClientNoType				ClientNo;
        TLoginPasswordType			Password;
    };
    //客户认证密码验证应答结构
    struct TEsClientPasswordAuthRspField
    {
        TClientNoType				ClientNo;
    };

    //币种查询请求结构
    struct TEsCurrencyQryReqField
    {
    };
    //币种查询应答结构
    struct TEsCurrencyQryRspField
    {
        TCurrencyNoType				CurrencyNo;
        TCurrencyNameType			CurrencyName;
        TIsPrimaryCurrencyType		IsPrimary;
        TCurrencyGroupFlagType		CurrencyGroup;
        TExchangeRateType			ExchangeRate;
    };

    //删除委托通知结构
    struct TEsOrderRemoveNoticeField
    {
        TClientNoType               ClientNo;
        TOrderIdType				OrderId;
    };

    //删除成交通知结构
    struct TEsMatchRemoveNoticeField
    {
        TClientNoType               ClientNo;
        TSystemNoType				SystemNo;
        TMatchNoType				MatchNo;
        TOrderIdType				MatchId;
    };

    //汇率变更通知
    struct TEsExchangeRateModifyNoticeField
    {
        TCurrencyNoType				CurrencyNo;
        TExchangeRateType			ExchangeRate;
    };

	//监控事件查询请求结构
	struct TEsMonitorEventQryReqField
	{
	};

	//监控事件查询应答结构
	struct TEsMonitorEventQryRspField
	{
		TEventTypeType				EventType;
		TEventLevelType				EventLevel;
		TEventSourceType			EventSource;
		TEventContentType			EventContent;
		TEventSerialIdType			SerialId;
		TDateTimeType				EventDateTime;	
	};

	//监控事件通知结构
	typedef TEsMonitorEventQryRspField	TEsMonitorEventNoticeField;

	//港交所做市商报价请求---客户端用
	struct TEsHKMarketOrderReq
	{
		TClientNoType					ClientNo;
		TCommodityNoType				CommodityNo;
		TContractNoType					ContractNo;

		TOrderTypeType					OrderType;						//委托类型
		TOrderModeType					OrderMode;						//委托模式
		TDateTimeType					ValidDateTime;

		TTradePriceType					BuyPrice;
		TTradePriceType					SellPrice;

		TTradeVolType					BuyVol;
		TTradeVolType					SellVol;

		THKMarketOperType				BuyOper;
		THKMarketOperType				SellOper;

		TOrderIdType					BuyOrderID;
		TOrderIdType					SellOrderID;

		TOrderSaveStringType			SaveString;
	};
	typedef TEsHKMarketOrderReq TEsHKMarketOrderRsp;

	//客户计算参数查询请求结构
	struct TClientCountRentQryReq
	{
		TClientNoType				ClientNo;
		TCommodityNoType			CommodityNo;
		TContractNoType				ContractNo;			//可填空
		TMatchWayType				MatchWay;
	};
	//客户结算参数查询应答结构
	struct TClientCountRentQryRsp
	{
		TClientCountRentQryReq		ReqData;

		TMoneyValueType				BFee;
		TMoneyValueType				DFee;
		TCurrencyNoType				CurrencyNo;

		TDepositModeType			DepositMode;		//仅比例和定额
		TMoneyValueType				Deposit;			//正常保证金
		TMoneyValueType				LockDeposit;		//锁仓保证金
		TMoneyValueType				KeepDeposit;		//维持保证金
		TMatchWayType				MatchWay;
	};

	struct TEsQryLmeContractRspField
	{
		TContractNoType					ContractNo;
		TLmeCheckType					LmeCheck;
		TDateType						Date;
		TTimeType						Time;
	};

	typedef TEsQryLmeContractRspField TEsLmeContractNotice;

	struct TEsHisHoldQryReqField
	{
		TClientNoType				ClientNo;
		TDateType					Date;
	};

	struct TEsHisHoldQryRspField
	{
		TSerialIdType				SerialID;
		TDateType					Date;
		TDateType					OpenDate;
		TClientNoType				ClientNo;
		TMatchNoType				HoldNo;
		TCommodityNoType			CommodityNo;
		TContractNoType				ContractNo;
		TMatchWayType				MatchWay;
		TDirectType					Direct;
		TTradeVolType				HoldVol;
		TTradePriceType				HoldPrice;
		TTradePriceType				SettlePrice;
		TMoneyValueType				ClientDeposit;
		TMoneyValueType				KeepClientDeposit;
		TMoneyValueType				UpperDeposit;
		TMoneyValueType				KeepUpperDeposit;
		TMoneyValueType				HoldProfit;
		TUpperNoType				UpperNo;
		TGroupNoType				GroupNo;
		TCurrencyNoType				CurrencyNo;
		TMoneyValueType				MarketValue;
	};

	struct TEsHisMoneyQryReqField
	{
		TClientNoType				ClientNo;
		TDateType					Date;
	};
	struct TEsHisMoneyQryRspField
	{
		TDateType					Date;
		TClientNoType				ClientNo;
		TCurrencyNoType				CurrencyNo;
		TMoneyValueType				yMoney;
		TMoneyValueType				yBalance;
		TMoneyValueType				CashIn;
		TMoneyValueType				CashOut;
		TMoneyValueType				Adjust;
		TMoneyValueType				Pledged;
		TMoneyValueType				ClientFee;								//包含交割手续费
		TMoneyValueType				sClientFee;
		TMoneyValueType				ExchangeFee;							//2012-05-22 汇兑手续费
		TMoneyValueType				UpperFee;								//包含交割手续费
		TMoneyValueType				sUpperFee;
		TMoneyValueType				NetFee;
		TMoneyValueType				Premium;
		TMoneyValueType				CoverProfit;							//不含平仓盈亏
		TMoneyValueType				DelivProfit;
		TMoneyValueType				UnExpiredProfit;
		TMoneyValueType				HoldProfit;								//不含LME持仓盈亏
		TMoneyValueType				LmeHoldProfit;							//2012-05-22 LME持仓盈亏
		TMoneyValueType				Discount;								//2012-05-22 LME贴现
		TMoneyValueType				OptionMarketValue;						//2012-05-22 期权市值
		TMoneyValueType				OriCash;								//2012-05-22 币种原始出入金
		TMoneyValueType				ClientDeposit;
		TMoneyValueType				KeepClientDeposit;
		TMoneyValueType				UpperDeposit;							//2011-12-22
		TMoneyValueType				KeepUpperDeposit;
		TMoneyValueType				FrozenClientDepsoit;
		TMoneyValueType				FrozenKeepClientDeposit;
		TMoneyValueType				FrozenUpperDeposit;
		TMoneyValueType				FrozenKeepUpperDeposit;					//2011-12-22
		TMoneyValueType				Money;
		TMoneyValueType				Balance;
		TMoneyValueType				MarketValue;							//2012-05-22 账户市值
		TMoneyValueType				Available;
		TMoneyValueType				Available2;
		TMoneyValueType				Extractable;
		TGroupNoType				GroupNo;								//结算组编号
		TExchangeRateType			ExchangeRate;

		TMoneyValueType				AuthMoney;

		TMoneyValueType				SpanClientDeposit;
		TMoneyValueType				SpanKeepClientDeposit;
	};
}

#pragma pack(pop)

#endif
