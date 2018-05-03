#ifndef _ESUNNY_FOREIGN_TRADE_API_TYPE_H
#define _ESUNNY_FOREIGN_TRADE_API_TYPE_H

namespace ESForeign
{
    //认证信息
    typedef char TEsCertInfoType[401];

    //日志路径
    typedef char TEsLogPathType[1024];

    //版本信息
    typedef char TEsVersionType[51];

	//应用程序ID
	typedef char TEsAppIDType[101];

    //登陆机器信息，主要包括mac地址
    typedef char					TMachineInfoType[201];

    typedef unsigned char  u_char;
    typedef	unsigned short u_short;

    //长度类型
    typedef unsigned int TEsSizeType;

    ///////////////////////////////////////////////////////////////////////////
    //错误号类型(0-表示成功)，错误号定义参见Protocol_Error.h
    typedef int						TErrorCodeType;
    //成功
    const TErrorCodeType			ERROR_SUCCEED					= 0;

	//错误信息
	typedef char					TErrorTextType[51];

    //是否查询结束
    typedef bool TEsIsLastType;

    ///////////////////////////////////////////////////////////////////////////
    //是否CA认证类型
    typedef char					TIsCaLoginType;
    //CA认证方式
    const TIsCaLoginType			CA_LOGIN						= 'Y';
    //非CA认证方式
    const TIsCaLoginType			NOT_CA_LOGIN					= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //是否强制修改密码类型
    typedef char					TIsForcePasswordType;
    //强制修改密码
    const TIsForcePasswordType		FORCE_PWD						= 'Y';
    //非强制修改密码
    const TIsForcePasswordType		NOT_FORCE_PWD					= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //登录身份类型
    typedef char					TEsLoginIdentityType;
    //下单客户端
    const TEsLoginIdentityType		IDENTITY_CLIENT					= 'c';
    //下单人端
    const TEsLoginIdentityType		IDENTITY_TCLIENT				= 'd';
    //经纪人端
    const TEsLoginIdentityType		IDENTITY_BROKER					= 'b';
    //交易员端
    const TEsLoginIdentityType		IDENTITY_TRADER					= 't';
    //柜台管理端
    const TEsLoginIdentityType		IDENTITY_MANAGER				= 'm';

    ///////////////////////////////////////////////////////////////////////////
    //登录名类型
    typedef char					TLoginNoType[21];
    //登录名称类型(客户简称,操作员名称)
    typedef char					TLoginNameType[21];
    //登录密码类型
    typedef	char					TLoginPasswordType[21];
    //otp密码
    typedef char					TOtpPassType[21];

    ///////////////////////////////////////////////////////////////////////////
    //Ip地址类型(ipv4最大15位,ipv6最大长度39位)
    typedef char					TIpType[41];

    ///////////////////////////////////////////////////////////////////////////
    //port端口类型
    typedef u_short					TPortType;

    ///////////////////////////////////////////////////////////////////////////
    //CA认证数据流类型(放在数据包结尾,通过数据包长度获取数据长度)
    typedef char					TCaInfoType[1];

    ///////////////////////////////////////////////////////////////////////////
    //客户预留信息类型
    typedef char					TReservedInfoType[51];

    ///////////////////////////////////////////////////////////////////////////
    //客户编号类型
    typedef char					TClientNoType[21];

    ///////////////////////////////////////////////////////////////////////////
    //操作员编号类型
    typedef char					TOperatorNoType[11];
    //操作员名称类型
    typedef char					TOperatorNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //日期和时间类型(格式 yyyy-MM-dd hh:nn:ss)
    typedef char					TDateTimeType[21];
    //日期类型(格式 yyyy-MM-dd)
    typedef char					TDateType[11];
    //时间类型(格式 hh:nn:ss)
    typedef char					TTimeType[11];
	///////////////////////////////////////////////////////////////////////////
	//二次认证验证码类型
	typedef char					TVertificateCodeType[11];

    ///////////////////////////////////////////////////////////////////////////
    //货币编号类型
    typedef char					TCurrencyNoType[11];
    //货币名称类型
    typedef char					TCurrencyNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //是否基币类型
    typedef char					TIsPrimaryCurrencyType;
    //是基币
    const TIsPrimaryCurrencyType	CURRENCY_PRIMARY_YES			= 'Y';
    //不是基币
    const TIsPrimaryCurrencyType	CURRENCY_PRIMARY_NO				= 'N';

    ///////////////////////////////////////////////////////////////////////////
	//币种组标志(同一币种组，资金共享)
	typedef char					TCurrencyGroupFlagType;
	//币种组A
	const TCurrencyGroupFlagType			CURRENCY_GROUP_A				= 'A';
	//币种组B
	const TCurrencyGroupFlagType			CURRENCY_GROUP_B				= 'B';
	//币种组C
	const TCurrencyGroupFlagType			CURRENCY_GROUP_C				= 'C';
	//币种组D
	const TCurrencyGroupFlagType			CURRENCY_GROUP_D				= 'D';
	//币种组E
	const TCurrencyGroupFlagType			CURRENCY_GROUP_E				= 'E';
	
    ///////////////////////////////////////////////////////////////////////////
    //汇率(1当前货币换算多少基币)
    typedef double					TExchangeRateType;

    ///////////////////////////////////////////////////////////////////////////
    //市场编号类型
    typedef char					TExchangeNoType[11];
    //市场名称类型
    typedef char					TExchangeNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //市场状态类型
    typedef char					TExchangeStateType;
    //市场允许交易
    const TExchangeStateType		EXCHANGE_STATE_YES				= 'Y';
    //市场禁止交易
    const TExchangeStateType		EXCHANGE_STATE_NO				= 'N';
    //市场只可平仓
    const TExchangeStateType		EXCHANGE_STATE_COVER			= 'C';

    ///////////////////////////////////////////////////////////////////////////
    //平仓方式类型
    typedef char					TCoverModeType;
    //不区分开平
    const TCoverModeType			COVER_MODE_NONE					= 'N';
    //平仓未了结
    const TCoverModeType			COVER_MODE_UNFINISHED			= 'U';
    //开仓和平仓
    const TCoverModeType			COVER_MODE_OPENCOVER			= 'C';
    //开仓、平仓和平今
    const TCoverModeType			COVER_MODE_COVERTODAY			= 'T';

    ///////////////////////////////////////////////////////////////////////////
    //商品编号类型(同一市场内不唯一  市场+商品类型+商品 唯一)
    typedef char					TCommodityNoType[11];
    //商品名称类型
    typedef char					TCommodityNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //商品类型类型
    typedef char					TCommodityTypeType;
    //现货
    const TCommodityTypeType		COMMODITY_TYPE_GOODS			= 'G';
    //期货
    const TCommodityTypeType		COMMODITY_TYPE_FUTURE			= 'F';
    //期权
    const TCommodityTypeType		COMMODITY_TYPE_OPTION			= 'O';
    //跨期套利
    const TCommodityTypeType		COMMODITY_TYPE_SPREAD_MONTH		= 'M';
    //跨品种套利
    const TCommodityTypeType		COMMODITY_TYPE_SPREAD_COMMODITY	= 'C';

    ///////////////////////////////////////////////////////////////////////////
    //商品属性类型
    typedef char					TCommodityAttributeType[21];

    ///////////////////////////////////////////////////////////////////////////
    //商品状态类型
    typedef char					TCommodityStateType;
    //商品允许交易
    const TCommodityStateType		COMMODITY_STATE_YES				= 'Y';
    //商品禁止交易
    const TCommodityStateType		COMMODITY_STATE_NO				= 'N';
    //商品只可平仓
    const TCommodityStateType		COMMODITY_STATE_COVER			= 'C';

    ///////////////////////////////////////////////////////////////////////////
    //每手乘数类型(美国国债是小数,LIFFE小黄金小数)
    typedef double					TProductDotType;

    ///////////////////////////////////////////////////////////////////////////
    //最小变动价分子类型
    typedef double					TUpperTickType;

    ///////////////////////////////////////////////////////////////////////////
    //最小变动价分母类型(非分数报价为1)
    typedef int						TLowerTickType;

    ///////////////////////////////////////////////////////////////////////////
    //交割方式类型
    typedef char					TDeliveryModeType;
    //实物交割
    const TDeliveryModeType			DELIVERY_MODE_GOODS				= 'G';
    //现金交割
    const TDeliveryModeType			DELIVERY_MODE_CASH				= 'C';
    //期权行权
    const TDeliveryModeType			DELIVERY_MODE_EXECUTE			= 'E';

    ///////////////////////////////////////////////////////////////////////////
    //交割日偏移类型(0即等同于最后交易日)
    typedef int						TDeliveryDaysType;

    ///////////////////////////////////////////////////////////////////////////
    //持仓计算方式
    typedef char					TDepositCalculateModeType;
    //正常
    const TDepositCalculateModeType	DEPOSIT_CALCULATE_MODE_NORMAL	= 'N';
    //合约净持仓
    const TDepositCalculateModeType	DEPOSIT_CALCULATE_MODE_CLEAN	= 'C';
    //品种锁仓
    const TDepositCalculateModeType DEPOSIT_CALCULATE_MODE_LOCK		= 'L';

    ///////////////////////////////////////////////////////////////////////////
    //合约编号类型
    typedef char					TContractNoType[71];
    //合约名称类型
    typedef char					TContractNameType[21];
    //合约到期日天数(合约还有几天到期)
    typedef int						TContractLastDays;

    ///////////////////////////////////////////////////////////////////////////
    //合约类型类型
    typedef char					TContractTypeType;
    //单腿合约
    const TContractTypeType			CONTRACT_TYPE_SINGLE			= '0';
    //跨期套利
    const TContractTypeType			CONTRACT_TYPE_SPREAD			= '1';
    //互换套利
    const TContractTypeType			CONTRACT_TYPE_SWAP				= '2';
    //跨品种套利
    const TContractTypeType			CONTRACT_TYPE_COMMODITY			= '3';

    ///////////////////////////////////////////////////////////////////////////
    //合约状态类型
    typedef char					TContractStateType;
    //合约允许交易
    const TContractStateType		CONTRACT_STATE_YES				= 'Y';
    //合约禁止交易
    const TContractStateType		CONTRACT_STATE_NO				= 'N';
    //合约只可平仓
    const TContractStateType		CONTRACT_STATE_COVER			= 'C';

    ///////////////////////////////////////////////////////////////////////////
    //行情价格类型
    typedef double					TQuotePriceType;

    ///////////////////////////////////////////////////////////////////////////
    //行情数量类型
    typedef int						TQuoteVolType;

    ///////////////////////////////////////////////////////////////////////////
    //客户简称类型
    typedef char					TClientShortNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //客户状态
    typedef char					TClientStateType;
    //正常
    const TClientStateType			CLIENT_STATE_NORMAL				= 'N';
    //销户
    const TClientStateType			CLIENT_STATE_CANCEL				= 'C';

    ///////////////////////////////////////////////////////////////////////////
    //客户类型类型
    typedef char					TClientTypeType;
    //个人客户
    const TClientTypeType			CLIENT_TYPE_PERSON				= 'P';
    //机构客户
    const TClientTypeType			CLIENT_TYPE_ORGANIZATION		= 'O';

    ///////////////////////////////////////////////////////////////////////////
    //移动电话类型
    typedef char					TMobilePhoneType[21];

    ///////////////////////////////////////////////////////////////////////////
    //客户交易状态类型
    typedef char					TClientTradeStateType;
    //正常交易
    const TClientTradeStateType		CLIENT_TRADE_YES				= 'Y';
    //禁止登录
    const TClientTradeStateType		CLIENT_TRADE_NO					= 'N';
    //只可查询
    const TClientTradeStateType		CLIENT_TRADE_QUERY				= 'Q';
    //只可平仓
    const TClientTradeStateType		CLIENT_TRADE_COVER				= 'C';
    //冻结
    const TClientTradeStateType		CLIENT_TRADE_FROZEN				= 'F';

    ///////////////////////////////////////////////////////////////////////////
    //登陆数类型(0-255,0相当于禁止登录)
    typedef unsigned char			TLoginCountType;

    ///////////////////////////////////////////////////////////////////////////
    //下单人类型
    typedef char					TDealManType[21];
    //下单人证件类型
    typedef char					TDealManIdType[21];

    ///////////////////////////////////////////////////////////////////////////
    //客户行情状态类型
    typedef char					TClientQuoteStateType;
    //正常登录
    const TClientQuoteStateType		CLIENT_QUOTE_YES				= 'Y';
    //禁止登录
    const TClientQuoteStateType		CLIENT_QUOTE_NO					= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //客户全称类型
    typedef char					TClientFullNameType[101];

    ///////////////////////////////////////////////////////////////////////////
    //证件号码类型
    typedef char					TIdentityNoType[21];

    ///////////////////////////////////////////////////////////////////////////
    //地址类型
    typedef char					TAddressType[101];

    ///////////////////////////////////////////////////////////////////////////
    //邮编号码类型
    typedef char					TPostNoType[21];

    ///////////////////////////////////////////////////////////////////////////
    //客户结算信息备注类型
    typedef char					TClientInfoRemark[201];

    ///////////////////////////////////////////////////////////////////////////
    //操作员状态类型
    typedef char					TOperatorStateType;
    //正常交易
    const TOperatorStateType		OPERATOR_TRADE_YES				= 'Y';
    //禁止登录
    const TOperatorStateType		OPERATOR_TRADE_NO				= 'N';
    //只可登录查询
    const TOperatorStateType		OPERATOR_TRADE_QUERY			= 'Q';
    //只可平仓
    const TOperatorStateType		OPERATOR_TRADE_COVER			= 'C';

    ///////////////////////////////////////////////////////////////////////////
    //操作员登录方式
    typedef char					TOperatorLoginType;
    //能够登录客户前置
    const TOperatorLoginType		OPERATOR_LOGIN_EVERY_FRONT		= 'Y';
    //不能登录客户前置
    const TOperatorLoginType		OPERATOR_LOGIN_NOT_EVERY_FRONT	= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //客户组帐号类型
    typedef char					TGroupNoType[11];
    //客户组名称类型
    typedef char					TGroupNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //客户组类型类型
    typedef char					TGroupTypeType;
    //交易分组(一个客户可以分配到多个分组)
    const TGroupTypeType			GROUP_TYPE_TRADE				= 'T';
    //结算分组(一个客户只可以分配到一个结算分组)
    const TGroupTypeType			GROUP_TYPE_SETTLE				= 'S';
    //手续费参数组(一个客户只可以分配到一个手续费组)
    const TGroupTypeType			GROUP_TYPE_FEERENT				= 'F';
    //保证金参数组(一个客户只可以分配到一个保证金组)
    const TGroupTypeType			GROUP_TYPE_DEPOSITRENT			= 'D';
    //资金共享组(一个客户只可以分配到一个资金共享组,同一资金共享组的客户交易能够互相占用资金)
    const TGroupTypeType			GROUP_TYPE_MONEY				= 'M';

    ///////////////////////////////////////////////////////////////////////////
    //角色编号类型
    typedef char					TRoleNoType[11];
    //角色名称类型
    typedef char					TRoleNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //角色编号类型
    typedef int						TRightIdType;
    //角色名称类型
    typedef char					TRightNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //密码类型
    typedef char					TPasswordTypeType;
    //交易密码
    const TPasswordTypeType			PASSWORD_TYPE_TRADE				= 'T';
    //行情密码
    const TPasswordTypeType			PASSWORD_TYPE_QUOTE				= 'Q';
    //认证密码
    const TPasswordTypeType			PASSWORD_TYPE_AUTH				= 'A';

    ///////////////////////////////////////////////////////////////////////////
    //委托保存数据(整数)类型
    typedef int						TOrderSaveIntType;
    //委托保存数据(浮点数)类型
    typedef double					TOrderSaveDoubleType;
    //委托保存数据(字符串)类型
    typedef char					TOrderSaveStringType[51];
	///////////////////////////////////////////////////////////////////////////
	//上手号
	typedef char					TUpperNoType[11];

    ///////////////////////////////////////////////////////////////////////////
    //委托类型
    typedef char					TOrderTypeType;
    //限价
    const TOrderTypeType			ORDER_TYPE_LIMIT				= '1';
    //市价
    const TOrderTypeType			ORDER_TYPE_MARKET				= '2';
    //限价止损
    const TOrderTypeType			ORDER_TYPE_STOP_LIMIT			= '3';
    //市价止损
    const TOrderTypeType			ORDER_TYPE_STOP_MARKET			= '4';

	//冰山单
	const TOrderTypeType			ORDER_TYPE_ICEBERG				= '9';
	//影子单
	const TOrderTypeType			ORDER_TYPE_GHOST				= 'A';

    ///////////////////////////////////////////////////////////////////////////
    //委托方式
    typedef char					TOrderWayType;
    //自助电子单
    const char						ORDER_WAY_SELF_ETRADER			= 'E';
    //代理电子单
    const char						ORDER_WAY_PROXY_ETRADER			= 'P';
    //外部电子单(外部电子系统下单，本系统录入)
    const char						ORDER_WAY_JTRADER				= 'J';
    //人工录入单(外部其他方式下单，本系统录入)
    const char						ORDER_WAY_MANUAL				= 'M';
    //carry单
    const char						ORDER_WAY_CARRY					= 'C';
    //程式化报单
    const char						ORDER_WAY_PROGRAM				= 'S';

    ///////////////////////////////////////////////////////////////////////////
    //委托模式类型
    typedef char					TOrderModeType;
    //FOK
    const TOrderModeType			ORDER_MODE_FOK					= '1';
    //FAK或IOC
    const TOrderModeType			ORDER_MODE_FAK					= '2';
    //当日有效
    const TOrderModeType			ORDER_MODE_GFD					= '3';
    //取消前有效
    const TOrderModeType			ORDER_MODE_GTC					= '4';
    //指定日期前有效
    const TOrderModeType			ORDER_MODE_GTD					= '5';

    //////////////////////////////////////////////////////////////////////////
    //冰山单是否随机量发送
    typedef char                                        TRandomise;
    const TRandomise                            RANDOM_YES                                      =	'Y';	
    const TRandomise                            RANDOM_NO                                       =	'N';	    
    
    ///////////////////////////////////////////////////////////////////////////
    //成交方式
    typedef char					TMatchWayType;
    //所有
    const char						MATCH_WAY_ALL					= 'A';
    //自助电子单
    const char						MATCH_WAY_SELF_ETRADER			= 'E';
    //代理电子单
    const char						MATCH_WAY_PROXY_ETRADER			= 'P';
    //外部电子单(外部电子系统下单，本系统录入)
    const char						MATCH_WAY_JTRADER				= 'J';
    //人工录入单(外部其他方式下单，本系统录入)
    const char						MATCH_WAY_MANUAL				= 'M';
    //carry单
    const char						MATCH_WAY_CARRY					= 'C';
    //交割单
    const char						MATCH_WAY_DELIVERY				= 'D';
    //程式化单
    const char						MATCH_WAY_PROGRAM				= 'S';


    ///////////////////////////////////////////////////////////////////////////
    //是否风险报单
    typedef char					TIsRiskOrderType;
    //是风险报单
    const TIsRiskOrderType			RISK_ORDER_YES					= 'Y';
    //不是风险报单
    const TIsRiskOrderType			RISK_ORDER_NO					= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //买卖类型
    typedef char					TDirectType;
    //买入
    const TDirectType				DIRECT_BUY						= 'B';
    //卖出
    const TDirectType				DIRECT_SELL						= 'S';

    ///////////////////////////////////////////////////////////////////////////
    //开平类型
    typedef char					TOffsetType;
    //无
    const TOffsetType				OFFSET_NONE						= 'N';
    //开仓
    const TOffsetType				OFFSET_OPEN						= 'O';
    //平仓
    const TOffsetType				OFFSET_COVER					= 'C';
    //平今
    const TOffsetType				OFFSET_COVER_TODAY				= 'T';

    ///////////////////////////////////////////////////////////////////////////
    //投机保值类型
    typedef char					THedgeType;
    //无
    const THedgeType				HEDGE_NONE						= 'N';
    //投机
    const THedgeType				HEDGE_T							= 'T';
    //保值
    const THedgeType				HEDGE_B							= 'B';

    ///////////////////////////////////////////////////////////////////////////
    //交易价格类型
    typedef double					TTradePriceType;
    //交易数量类型
    typedef int						TTradeVolType;

    ///////////////////////////////////////////////////////////////////////////
    //委托编号类型(每个交易服务器内唯一标志,由服务器生成)
    typedef int						TOrderIdType;
    //本地编号类型(每个交易服务器内唯一标志,由服务器生成)
    typedef char					TLocalNoType[21];
    //系统编号类型(上级交易所报单唯一标志,不同交易所可能会重复)
    typedef char					TSystemNoType[64];
    //成交编号
    typedef char					TMatchNoType[71];
    //本地编号类型(每个交易服务器内唯一标志,由服务器生成)
    typedef char					TFeLocalNoType[sizeof(TLocalNoType) + 1];

    ///////////////////////////////////////////////////////////////////////////
    //委托录入类型
    typedef char					TOrderInputType;
    //是
    const TOrderInputType			ORDER_INPUT_YES					= 'Y';
    //否
    const TOrderInputType			ORDER_INPUT_NO					= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //T+1成交
    typedef char					TAddOneType;
    //T+1成交
    const TAddOneType				ADD_ONE_YES						= 'Y';
    //非T+1成交
    const TAddOneType				ADD_ONE_NO						= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //人工填写手续费
    typedef char					TManualFeeType;
    //人工
    const TManualFeeType			MANUALFEE_YES					= 'Y';
    //自动
    const TManualFeeType			MANUALFEE_NO					= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //委托状态类型
    typedef char					TOrderStateType;
    //指令失败
    const TOrderStateType			ORDER_STATE_FAIL				= '0';
    //已受理
    const TOrderStateType			ORDER_STATE_ACCEPT				= '1';
    //已挂起
    const TOrderStateType			ORDER_STATE_SUPPENDED			= '2';
    //已排队
    const TOrderStateType			ORDER_STATE_QUEUED				= '3';
    //待撤消(排队临时状态)
    const TOrderStateType			ORDER_STATE_DELETEING			= '4';
    //待修改(排队临时状态)
    const TOrderStateType			ORDER_STATE_MODIFYING			= '5';
    //部分撤单
    const TOrderStateType			ORDER_STATE_PARTDELETED			= '6';
    //完全撤单
    const TOrderStateType			ORDER_STATE_DELETED				= '7';
    //部分成交
    const TOrderStateType			ORDER_STATE_PARTFINISHED		= '8';
    //完全成交
    const TOrderStateType			ORDER_STATE_FINISHED			= '9';

    ///////////////////////////////////////////////////////////////////////////
    //成交方式类型
    typedef char					TMatchModeType;
    //正常
    const TMatchModeType			MATCH_MODE_NORMAL				= 'N';
    //更新委托
    const TMatchModeType			MATCH_MODE_UPDATE				= 'U';
    //其他
    const TMatchModeType			MATCH_MODE_OTHER				= 'O';

    ///////////////////////////////////////////////////////////////////////////
    //数据流号类型
    typedef unsigned int			TStreamIdType;

    ///////////////////////////////////////////////////////////////////////////
    //交易帐号类型类型
    typedef char					TTradeNoTypeType;
    //常规类型
    const TTradeNoTypeType			TRADENO_NORMAL					= 'N';
    //投机
    const TTradeNoTypeType			TRADENO_TOUJI					= 'T';
    //保值
    const TTradeNoTypeType			TRADENO_BAOZHI					= 'B';
    //套利
    const TTradeNoTypeType			TRADENO_SPREAD					= 'S';

    ///////////////////////////////////////////////////////////////////////////
    //交易帐号类型
    typedef char					TTradeNoType[21];

    ///////////////////////////////////////////////////////////////////////////
    //资金类型
    typedef double					TMoneyValueType;

    ///////////////////////////////////////////////////////////////////////////
    //持仓关键字类型(历史持仓全局唯一,当日持仓每次查询唯一)
    typedef int						THoldKeyIdType;
    //交割关键字类型(当日交割数据全局唯一)
    typedef int						TDeliveryKeyIdType;

    ///////////////////////////////////////////////////////////////////////////
    //出入金流水号类型
    typedef int						TCashSerialIdType;
    //资金调整流水号类型
    typedef int						TAdjustSerialIdType;

    ///////////////////////////////////////////////////////////////////////////
    //出入金类型
    typedef char					TCashTypeType;
    //出金
    const TCashTypeType				CASH_TYPE_OUT					= 'O';
    //入金
    const TCashTypeType				CASH_TYPE_IN					= 'I';

    //出入金状态
    typedef char					TCashStateType;
    //未审核
    const TCashStateType			CASH_STATE_NOT_CHECK			= 'N';
    //已审核
    const TCashStateType			CASH_STATE_CHECK				= 'Y';
    //审核未通过
    const TCashStateType			CASH_STATE_FAIL					= 'F';

    ///////////////////////////////////////////////////////////////////////////
    //出入金方式
    typedef char					TCashModeType;
    //转账
    const TCashModeType				CASH_MODE_A						= 'A';
    //支票
    const TCashModeType				CASH_MODE_B						= 'B';
    //现金
    const TCashModeType				CASH_MODE_C						= 'C';
    //换汇
    const TCashModeType				CASH_MODE_E						= 'E';

    ///////////////////////////////////////////////////////////////////////////
    //出入金备注
    typedef char					TCashRemarkType[101];


	///////////////////////////////////////////////////////////////////////////
	//是否强制出金标记
	typedef char					TForceCashOutFlagType;
	//强制出金，资金不足时，允许出金
	const TForceCashOutFlagType	FORCE_CASH_OUT_YES			= 'Y';
	//不强制出金,资金不足时，不允许出金
	const TForceCashOutFlagType	FORCE_CASH_OUT_NO			= 'N';


    //资金调整状态
    typedef char					TAdjustStateType;
    //未审核
    const TAdjustStateType			ADJUST_STATE_NOT_CHECK			= 'N';
    //已审核
    const TAdjustStateType			ADJUST_STATE_CHECK				= 'Y';
    //审核未通过
    const TAdjustStateType			ADJUST_STATE_FAIL				= 'F';

    ///////////////////////////////////////////////////////////////////////////
    //资金调整类型类型
    typedef char					TAdjustTypeType;

    ///////////////////////////////////////////////////////////////////////////
    //资金调整备注类型
    typedef char					TAdjustRemarkType[101];

    ///////////////////////////////////////////////////////////////////////////
    //资金变化字段类型(从低位到高位,每位对应一个变化字段)
    typedef unsigned int			TMoneyChgType;
	//资金调整                                                                 
	const TMoneyChgType				MONEY_CHG_ADJUST				= 0x00000001;
	//入金                                                                     
	const TMoneyChgType				MONEY_CHG_CASHIN				= 0x00000002;
	//出金                                                                     
	const TMoneyChgType				MONEY_CHG_CASHOUT   			= 0x00000004;
	//手续费                                                                   
	const TMoneyChgType				MONEY_CHG_FEE					= 0x00000008;
	//冻结资金                                                                 
	const TMoneyChgType				MONEY_CHG_FROZEN				= 0x00000010;
	//逐笔平盈                                                                 
	const TMoneyChgType				MONEY_CHG_COVERPROFIT			= 0x00000020;
	//盯市平盈                                                                 
	const TMoneyChgType				MONEY_CHG_DAYCVERPROFIT			= 0x00000040;
	//逐笔浮盈                                                                 
	const TMoneyChgType				MONEY_CHG_FLOATPROFIT			= 0x00000080;
	//盯市浮盈                                                                 
	const TMoneyChgType				MONEY_CHG_DAYFLOATPROFIT		= 0x00000100;
	//未结平盈                                                                 
	const TMoneyChgType				MONEY_CHG_UNEXPIREDPROFIT		= 0x00000200;
	//权利金                                                                   
	const TMoneyChgType				MONEY_CHG_PREMIUM				= 0x00000400;
	//保证金                                                                   
	const TMoneyChgType				MONEY_CHG_DEPOSIT				= 0x00000800;
	//维持保证金                                                               
	const TMoneyChgType				MONEY_CHG_KEEPDEPOSIT			= 0x00001000;
	//质押资金                                                                 
	const TMoneyChgType				MONEY_CHG_PLEDGE				= 0x00002000;
	//可用资金                                                                 
	const TMoneyChgType				MONEY_CHG_TAVAILABLE			= 0x00004000;
    //贴现金额
    const TMoneyChgType				MONEY_CHG_Discount              = 0x00008000;
    //交易手续费
    const TMoneyChgType				MONEY_CHG_TradeFee              = 0x00010000;
    //交割手续费
    const TMoneyChgType				MONEY_CHG_DeliveryFee           = 0x00020000;
    //汇兑手续费
    const TMoneyChgType				MONEY_CHG_ExchangeFee           = 0x00040000;
    //冻结保证金
    const TMoneyChgType				MONEY_CHG_FrozenDeposit         = 0x00080000;
    //冻结手续费
    const TMoneyChgType				MONEY_CHG_FrozenFee             = 0x00100000;
    //浮盈(无LME)
    const TMoneyChgType				MONEY_CHG_NewFloatProfit        = 0x00200000;
    //LME浮盈
    const TMoneyChgType				MONEY_CHG_LmeFloatProfit        = 0x00400000;
    //期权市值
    const TMoneyChgType				MONEY_CHG_OptionMarketValue     = 0x00800000;
    //币种原始出入金
    const TMoneyChgType				MONEY_CHG_OriCash               = 0x01000000;
	//授信资金
	const TMoneyChgType				MONEY_CHG_AuthMoneyValue		= 0x02000000;
	//在途可用
	const TMoneyChgType				MONEY_CHG_TransitMoneyValue		= 0x08000000;
    //今资金        
    const TMoneyChgType				MONEY_CHG_TMoney                = 0x04000000;
    //今权益
    const TMoneyChgType				MONEY_CHG_TBalance              = 0x10000000;
    //今可提
    const TMoneyChgType				MONEY_CHG_TCanCashOut           = 0x20000000;
    //风险率
    const TMoneyChgType				MONEY_CHG_RiskRate              = 0x40000000;
    //账户市值
    const TMoneyChgType				MONEY_CHG_AccountMarketValue    = 0x80000000;

    ///////////////////////////////////////////////////////////////////////////
    //消息接收者类型
    typedef char					TMessageReceiverType;
    //指定客户
    const TMessageReceiverType		MESSAGE_RECEIVER_CLIENT			= 'C';
    //指定客户组
    const TMessageReceiverType		MESSAGE_RECEIVER_GROUP			= 'G';
    //所有客户
    const TMessageReceiverType		MESSAGE_RECEIVER_ALL			= 'A';

    ///////////////////////////////////////////////////////////////////////////
    //Mac地址类型
    typedef char					TMacAddressType[51];

    ///////////////////////////////////////////////////////////////////////////
    //保证金计算方式
    typedef char					TDepositModeType;
    //比例
    const TDepositModeType			DEPOSIT_MODE_B					= '1';
    //定额
    const TDepositModeType			DEPOSIT_MODE_D					= '2';
    //差值比例
    const TDepositModeType			DEPOSIT_MODE_CB					= '3';
    //差值定额
    const TDepositModeType			DEPOSIT_MODE_CD					= '4';
    //折扣
    const TDepositModeType			DEPOSIT_MODE_Z					= '5';

    ///////////////////////////////////////////////////////////////////////////
    //日志类型类型
    typedef char					TLogTypeType;
    //登录日志
    const TLogTypeType				LOGTYPE_LOGIN					= '1';

    ///////////////////////////////////////////////////////////////////////////
    //日志内容类型
    typedef char					TLogContentType[501];
    //日志流水号类型
    typedef int						TSerialIdType;

    ///////////////////////////////////////////////////////////////////////////
    //委托成交删除标记
    typedef char					TDeletedType;
    //是
    const TDeletedType				DEL_YES							= 'Y';
    //否
    const TDeletedType				DEL_NO							= 'N';
    //隐藏
    const TDeletedType				DEL_DISAPPEAR					= 'D';

    ///////////////////////////////////////////////////////////////////////////
    //是否包含合计值
    typedef char					TContainTotleType;
    //包含
    const TContainTotleType			ContainTotle_Yes			= 'Y';
    //不包含
    const TContainTotleType			ContainTotle_No				= 'N';

    ///////////////////////////////////////////////////////////////////////////
    //银行标识
    typedef char					TBankType[3];

    ///////////////////////////////////////////////////////////////////////////
    //银行名称
    typedef char					TBankNameType[21];

    ///////////////////////////////////////////////////////////////////////////
    //银行账号
    typedef char					TAccountType[51];

    ///////////////////////////////////////////////////////////////////////////
    //本外币标识
    typedef char					TLWFlagType;
    //境内人民币账户
    const TLWFlagType				LWFlag_L						= 'L';
    //客户境内外币账户
    const TLWFlagType				LWFlag_W						= 'W';
    //公司境内外币账户
    const TLWFlagType				LJFFlag_J						= 'J';
    //公司境外外币账户
    const TLWFlagType				LJFFlag_F						= 'F';

	///////////////////////////////////////////////////////////////////////////
	//监控事件编号类型
	typedef int						TEventSerialIdType;

	///////////////////////////////////////////////////////////////////////////
	//监控事件类型类型
	typedef char					TEventTypeType;
	//常规事件
	const TEventTypeType			EVENT_TYPE_Y					= 'Y';
	//非常规事件
	const TEventTypeType			EVENT_TYPE_N					= 'N';

	///////////////////////////////////////////////////////////////////////////
	//监控事件等级类型
	typedef char					TEventLevelType;
	//正常
	const TEventLevelType			EVENT_TYPE_NORMAL				= 'N';
	//警报
	const TEventLevelType			EVENT_TYPE_WARNNING				= 'W';
	//错误
	const TEventLevelType			EVENT_TYPE_ERROR				= 'E';

	///////////////////////////////////////////////////////////////////////////
	//事件来源类型
	typedef char					TEventSourceType[21];

	///////////////////////////////////////////////////////////////////////////
	//事件内容类型
	typedef char					TEventContentType[201];

	//////////////////////////////////////////////////////////////////////////
	//港交所报单操作类型
	typedef char					THKMarketOperType;
	const THKMarketOperType			MarketOper_None = '\0';
	//下单
	const THKMarketOperType			MarketOper_Insert = 'I';
	//改单
	const THKMarketOperType			MarketOper_Modify = 'M';
	//撤单
	const THKMarketOperType			MarketOper_Delete = 'D';

	//////////////////////////////////////////////////////////////////////////
	//持仓关键字类型
	typedef int						THoldKeyNoType;

	///////////////////////////////////////////////////////////////////////////
	//LME验证结果
	typedef char					TLmeCheckType;
	//验证通过
	const TLmeCheckType				LME_CHECK_YES = 'Y';
	//验证不通过
	const TLmeCheckType				LME_CHECK_NO = 'N';
	/////////////////////////////////////////////////////////////////////////
}



#endif
