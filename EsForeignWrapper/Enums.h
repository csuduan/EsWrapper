#pragma once
using namespace System;
namespace EsForeignWrapper
{

	/// <summary>
	/// 是否CA认证类型
	/// </summary>
	public enum struct EnumIsCaLoginType
	{
		//CA认证方式
		CA_LOGIN = 'Y',
		//非CA认证方式
		NOT_CA_LOGIN = 'N'
	};

	/// <summary>
	/// 是否强制修改密码类型
	/// </summary>
	public enum struct EnumIsForcePasswordType
	{
		//强制修改密码
		FORCE_PWD = 'Y',
		//非强制修改密码
		NOT_FORCE_PWD = 'N'
	};

	/// <summary>
	/// 登录身份类型
	/// </summary>
	public enum struct EnumEsLoginIdentityType
	{
		//下单客户端
		IDENTITY_CLIENT = 'c',
		//下单人端
		IDENTITY_TCLIENT = 'd',
		//经纪人端
		IDENTITY_BROKER = 'b',
		//交易员端
		IDENTITY_TRADER = 't',
		//柜台管理端
		IDENTITY_MANAGER = 'm'
	};

	/// <summary>
	/// 是否基币类型
	/// </summary>
	public enum struct EnumIsPrimaryCurrencyType
	{
		//是基币
		CURRENCY_PRIMARY_YES = 'Y',
		//不是基币
		CURRENCY_PRIMARY_NO = 'N'
	};

	/// <summary>
	/// 币种组标志(同一币种组，资金共享)
	/// </summary>
	public enum struct EnumCurrencyGroupFlagType
	{
		//币种组A
		CURRENCY_GROUP_A = 'A',
		//币种组B
		CURRENCY_GROUP_B = 'B',
		//币种组C
		CURRENCY_GROUP_C = 'C',
		//币种组D
		CURRENCY_GROUP_D = 'D',
		//币种组E
		CURRENCY_GROUP_E = 'E'
	};

	/// <summary>
	/// 市场状态类型
	/// </summary>
	public enum struct EnumExchangeStateType
	{
		//市场允许交易
		EXCHANGE_STATE_YES = 'Y',
		//市场禁止交易
		EXCHANGE_STATE_NO = 'N',
		//市场只可平仓
		EXCHANGE_STATE_COVER = 'C'
	};

	/// <summary>
	/// 平仓方式类型
	/// </summary>
	public enum struct EnumCoverModeType
	{
		//不区分开平
		COVER_MODE_NONE = 'N',
		//平仓未了结
		COVER_MODE_UNFINISHED = 'U',
		//开仓和平仓
		COVER_MODE_OPENCOVER = 'C',
		//开仓、平仓和平今
		COVER_MODE_COVERTODAY = 'T'
	};

	/// <summary>
	/// 商品类型类型
	/// </summary>
	public enum struct EnumCommodityTypeType
	{
		//现货
		COMMODITY_TYPE_GOODS = 'G',
		//期货
		COMMODITY_TYPE_FUTURE = 'F',
		//期权
		COMMODITY_TYPE_OPTION = 'O',
		//跨期套利
		COMMODITY_TYPE_SPREAD_MONTH = 'M',
		//跨品种套利
		COMMODITY_TYPE_SPREAD_COMMODITY = 'C'
	};

	/// <summary>
	/// 商品状态类型
	/// </summary>
	public enum struct EnumCommodityStateType
	{
		//商品允许交易
		COMMODITY_STATE_YES = 'Y',
		//商品禁止交易
		COMMODITY_STATE_NO = 'N',
		//商品只可平仓
		COMMODITY_STATE_COVER = 'C'
	};

	/// <summary>
	/// 交割方式类型
	/// </summary>
	public enum struct EnumDeliveryModeType
	{
		//实物交割
		DELIVERY_MODE_GOODS = 'G',
		//现金交割
		DELIVERY_MODE_CASH = 'C',
		//期权行权
		DELIVERY_MODE_EXECUTE = 'E'
	};

	/// <summary>
	/// 持仓计算方式
	/// </summary>
	public enum struct EnumDepositCalculateModeType
	{
		//正常
		DEPOSIT_CALCULATE_MODE_NORMAL = 'N',
		//合约净持仓
		DEPOSIT_CALCULATE_MODE_CLEAN = 'C',
		//品种锁仓
		DEPOSIT_CALCULATE_MODE_LOCK = 'L'
	};

	/// <summary>
	/// 合约类型类型
	/// </summary>
	public enum struct EnumContractTypeType
	{
		//单腿合约
		CONTRACT_TYPE_SINGLE = '0',
		//跨期套利
		CONTRACT_TYPE_SPREAD = '1',
		//互换套利
		CONTRACT_TYPE_SWAP = '2',
		//跨品种套利
		CONTRACT_TYPE_COMMODITY = '3'
	};
	/// <summary>
	/// 合约状态类型
	/// </summary>
	public enum struct EnumContractStateType
	{
		//合约允许交易
		CONTRACT_STATE_YES = 'Y',
		//合约禁止交易
		CONTRACT_STATE_NO = 'N',
		//合约只可平仓
		CONTRACT_STATE_COVER = 'C'
	};
	/// <summary>
	/// 客户状态
	/// </summary>
	public enum struct EnumClientStateType
	{
		//正常
		CLIENT_STATE_NORMAL = 'N',
		//销户
		CLIENT_STATE_CANCEL = 'C'
	};
	/// <summary>
	/// 客户类型类型
	/// </summary>
	public enum struct EnumClientTypeType
	{
		//个人客户
		CLIENT_TYPE_PERSON = 'P',
		//机构客户
		CLIENT_TYPE_ORGANIZATION = 'O'
	};
	/// <summary>
	/// 客户交易状态类型
	/// </summary>
	public enum struct EnumClientTradeStateType
	{
		//正常交易
		CLIENT_TRADE_YES = 'Y',
		//禁止登录
		CLIENT_TRADE_NO = 'N',
		//只可查询
		CLIENT_TRADE_QUERY = 'Q',
		//只可平仓
		CLIENT_TRADE_COVER = 'C',
		//冻结
		CLIENT_TRADE_FROZEN = 'F'
	};
	/// <summary>
	/// 客户行情状态类型
	/// </summary>
	public enum struct EnumClientQuoteStateType
	{
		//正常登录
		CLIENT_QUOTE_YES = 'Y',
		//禁止登录
		CLIENT_QUOTE_NO = 'N'
	};
	/// <summary>
	/// 操作员状态类型
	/// </summary>
	public enum struct EnumOperatorStateType
	{
		//正常交易
		OPERATOR_TRADE_YES = 'Y',
		//禁止登录
		OPERATOR_TRADE_NO = 'N',
		//只可登录查询
		OPERATOR_TRADE_QUERY = 'Q',
		//只可平仓
		OPERATOR_TRADE_COVER = 'C'
	};

	/// <summary>
	/// 操作员登录方式
	/// </summary>
	public enum struct EnumOperatorLoginType
	{
		//能够登录客户前置
		OPERATOR_LOGIN_EVERY_FRONT = 'Y',
		//不能登录客户前置
		OPERATOR_LOGIN_NOT_EVERY_FRONT = 'N'
	};

	/// <summary>
	/// 客户组类型类型
	/// </summary>
	public enum struct EnumGroupTypeType
	{
		//交易分组(一个客户可以分配到多个分组)
		GROUP_TYPE_TRADE = 'T',
		//结算分组(一个客户只可以分配到一个结算分组)
		GROUP_TYPE_SETTLE = 'S',
		//手续费参数组(一个客户只可以分配到一个手续费组)
		GROUP_TYPE_FEERENT = 'F',
		//保证金参数组(一个客户只可以分配到一个保证金组)
		GROUP_TYPE_DEPOSITRENT = 'D',
		//资金共享组(一个客户只可以分配到一个资金共享组,同一资金共享组的客户交易能够互相占用资金)
		GROUP_TYPE_MONEY = 'M'
	};

	/// <summary>
	/// 密码类型
	/// </summary>
	public enum struct EnumPasswordTypeType
	{
		//交易密码
		PASSWORD_TYPE_TRADE = 'T',
		//行情密码
		PASSWORD_TYPE_QUOTE = 'Q',
		//认证密码
		PASSWORD_TYPE_AUTH = 'A'
	};

	/// <summary>
	/// 委托类型
	/// </summary>
	public enum struct EnumOrderType
	{
		//限价
		ORDER_TYPE_LIMIT = '1',
		//市价
		ORDER_TYPE_MARKET = '2',
		//限价止损
		ORDER_TYPE_STOP_LIMIT = '3',
		//市价止损
		ORDER_TYPE_STOP_MARKET = '4'
	};
	/// <summary>
	/// 委托方式
	/// </summary>
	public enum struct EnumOrderWayType
	{
		//自助电子单
		ORDER_WAY_SELF_ETRADER = 'E',
		//代理电子单
		ORDER_WAY_PROXY_ETRADER = 'P',
		//外部电子单(外部电子系统下单，本系统录入)
		ORDER_WAY_JTRADER = 'J',
		//人工录入单(外部其他方式下单，本系统录入)
		ORDER_WAY_MANUAL = 'M',
		//carry单
		ORDER_WAY_CARRY = 'C',
		//程式化报单
		ORDER_WAY_PROGRAM = 'S'
	};

	/// <summary>
	/// 委托模式类型
	/// </summary>
	public enum struct EnumOrderModeType
	{
		//FOK
		ORDER_MODE_FOK = '1',
		//FAK或IOC
		ORDER_MODE_FAK = '2',
		//当日有效
		ORDER_MODE_GFD = '3',
		//取消前有效
		ORDER_MODE_GTC = '4',
		//指定日期前有效
		ORDER_MODE_GTD = '5'
	};
	/// <summary>
	/// 成交方式
	/// </summary>
	public enum struct EnumMatchWayType
	{
		//所有
		MATCH_WAY_ALL = 'A',
		//自助电子单
		MATCH_WAY_SELF_ETRADER = 'E',
		//代理电子单
		MATCH_WAY_PROXY_ETRADER = 'P',
		//外部电子单(外部电子系统下单，本系统录入)
		MATCH_WAY_JTRADER = 'J',
		//人工录入单(外部其他方式下单，本系统录入)
		MATCH_WAY_MANUAL = 'M',
		//carry单
		MATCH_WAY_CARRY = 'C',
		//交割单
		MATCH_WAY_DELIVERY = 'D',
		//程式化单
		MATCH_WAY_PROGRAM = 'S'
	};
	/// <summary>
	/// 是否风险报单
	/// </summary>
	public enum struct EnumIsRiskOrderType
	{
		//是风险报单
		RISK_ORDER_YES = 'Y',
		//不是风险报单
		RISK_ORDER_NO = 'N'
	};
	/// <summary>
	/// 买卖类型
	/// </summary>
	public enum struct EnumDirectType
	{
		//买入
		DIRECT_BUY = 'B',
		//卖出
		DIRECT_SELL = 'S'
	};
	/// <summary>
	/// 开平类型
	/// </summary>
	public enum struct EnumOffsetType
	{
		//无
		OFFSET_NONE = 'N',
		//开仓
		OFFSET_OPEN = 'O',
		//平仓
		OFFSET_COVER = 'C',
		//平今
		OFFSET_COVER_TODAY = 'T'
	};
	/// <summary>
	/// 投机保值类型
	/// </summary>
	public enum struct EnumHedgeType
	{
		//无
		HEDGE_NONE = 'N',
		//投机
		HEDGE_T = 'T',
		//保值
		HEDGE_B = 'B'

	};
	/// <summary>
	/// 委托录入类型
	/// </summary>
	public enum struct EnumOrderInputType
	{
		//是
		ORDER_INPUT_YES = 'Y',
		//否
		ORDER_INPUT_NO = 'N'
	};
	/// <summary>
	/// T+1成交
	/// </summary>
	public enum struct EnumAddOneType
	{
		//T+1成交
		ADD_ONE_YES = 'Y',
		//非T+1成交
		ADD_ONE_NO = 'N'

	};
	/// <summary>
	/// 人工填写手续费
	/// </summary>
	public enum struct EnumManualFeeType
	{    //人工
		MANUALFEE_YES = 'Y',
		//自动
		MANUALFEE_NO = 'N'

	};
	/// <summary>
	/// 委托状态类型
	/// </summary>
	public enum struct EnumOrderStateType
	{//指令失败
		ORDER_STATE_FAIL = '0',
		//已受理
		ORDER_STATE_ACCEPT = '1',
		//已挂起
		ORDER_STATE_SUPPENDED = '2',
		//已排队
		ORDER_STATE_QUEUED = '3',
		//待撤消(排队临时状态)
		ORDER_STATE_DELETEING = '4',
		//待修改(排队临时状态)
		ORDER_STATE_MODIFYING = '5',
		//部分撤单
		ORDER_STATE_PARTDELETED = '6',
		//完全撤单
		ORDER_STATE_DELETED = '7',
		//部分成交
		ORDER_STATE_PARTFINISHED = '8',
		//完全成交
		ORDER_STATE_FINISHED = '9'
	};
	/// <summary>
	/// 成交方式类型
	/// </summary>
	public enum struct EnumMatchModeType
	{    //正常
		MATCH_MODE_NORMAL = 'N',
		//更新委托
		MATCH_MODE_UPDATE = 'U',
		//其他
		MATCH_MODE_OTHER = 'O'
	};
	/// <summary>
	/// 交易帐号类型类型
	/// </summary>
	public enum struct EnumTradeNoTypeType
	{
		//常规类型
		TRADENO_NORMAL = 'N',
		//投机
		TRADENO_TOUJI = 'T',
		//保值
		TRADENO_BAOZHI = 'B',
		//套利
		TRADENO_SPREAD = 'S'
	};
	/// <summary>
	/// 出入金类型
	/// </summary>
	public enum struct EnumCashTypeType
	{    //出金
		CASH_TYPE_OUT = 'O',
		//入金
		CASH_TYPE_IN = 'I'
	};

	/// <summary>
	/// 出入金状态
	/// </summary>
	public enum struct EnumCashStateType
	{ //未审核
		CASH_STATE_NOT_CHECK = 'N',
		//已审核
		CASH_STATE_CHECK = 'Y',
		//审核未通过
		CASH_STATE_FAIL = 'F'
	};


	/// <summary>
	/// 出入金方式
	/// </summary>
	public enum struct EnumCashModeType
	{    //转账
		CASH_MODE_A = 'A',
		//支票
		CASH_MODE_B = 'B',
		//现金
		CASH_MODE_C = 'C',
		//换汇
		CASH_MODE_E = 'E'
	};


	/// <summary>
	/// 是否强制出金标记
	/// </summary>
	public enum struct EnumForceCashOutFlagType
	{	//强制出金，资金不足时，允许出金
		FORCE_CASH_OUT_YES = 'Y',
		//不强制出金,资金不足时，不允许出金
		FORCE_CASH_OUT_NO = 'N'

	};


	/// <summary>
	/// 资金调整状态
	/// </summary>
	public enum struct EnumAdjustStateType
	{    //未审核
		ADJUST_STATE_NOT_CHECK = 'N',
		//已审核
		ADJUST_STATE_CHECK = 'Y',
		//审核未通过
		ADJUST_STATE_FAIL = 'F'
	};


	/// <summary>
	/// 资金变化字段类型(从低位到高位,每位对应一个变化字段)
	/// </summary>
	public enum struct EnumTMoneyChgType
	{
		//资金调整                                                                 
		MONEY_CHG_ADJUST = 0x00000001,
		//入金                                                                     
		MONEY_CHG_CASHIN = 0x00000002,
		//出金                                                                     
		MONEY_CHG_CASHOUT = 0x00000004,
		//手续费                                                                   
		MONEY_CHG_FEE = 0x00000008,
		//冻结资金                                                                 
		MONEY_CHG_FROZEN = 0x00000010,
		//逐笔平盈                                                                 
		MONEY_CHG_COVERPROFIT = 0x00000020,
		//盯市平盈                                                                 
		MONEY_CHG_DAYCVERPROFIT = 0x00000040,
		//逐笔浮盈                                                                 
		MONEY_CHG_FLOATPROFIT = 0x00000080,
		//盯市浮盈                                                                 
		MONEY_CHG_DAYFLOATPROFIT = 0x00000100,
		//未结平盈                                                                 
		MONEY_CHG_UNEXPIREDPROFIT = 0x00000200,
		//权利金                                                                   
		MONEY_CHG_PREMIUM = 0x00000400,
		//保证金                                                                   
		MONEY_CHG_DEPOSIT = 0x00000800,
		//维持保证金                                                               
		MONEY_CHG_KEEPDEPOSIT = 0x00001000,
		//质押资金                                                                 
		MONEY_CHG_PLEDGE = 0x00002000,
		//可用资金                                                                 
		MONEY_CHG_TAVAILABLE = 0x00004000,
		//贴现金额
		MONEY_CHG_Discount = 0x00008000,
		//交易手续费
		MONEY_CHG_TradeFee = 0x00010000,
		//交割手续费
		MONEY_CHG_DeliveryFee = 0x00020000,
		//汇兑手续费
		MONEY_CHG_ExchangeFee = 0x00040000,
		//冻结保证金
		MONEY_CHG_FrozenDeposit = 0x00080000,
		//冻结手续费
		MONEY_CHG_FrozenFee = 0x00100000,
		//浮盈(无LME)
		MONEY_CHG_NewFloatProfit = 0x00200000,
		//LME浮盈
		MONEY_CHG_LmeFloatProfit = 0x00400000,
		//期权市值
		MONEY_CHG_OptionMarketValue = 0x00800000,
		//币种原始出入金
		MONEY_CHG_OriCash = 0x01000000,
		//今资金        
		MONEY_CHG_TMoney = 0x02000000,
		//今权益
		MONEY_CHG_TBalance = 0x04000000,
		//今可提
		MONEY_CHG_TCanCashOut = 0x08000000,
		//风险率
		MONEY_CHG_RiskRate = 0x10000000,
		//账户市值
		MONEY_CHG_AccountMarketValue = 0x20000000
	};


	/// <summary>
	/// 消息接收者类型
	/// </summary>
	public enum struct EnumMessageReceiverType
	{    //指定客户
		MESSAGE_RECEIVER_CLIENT = 'C',
		//指定客户组
		MESSAGE_RECEIVER_GROUP = 'G',
		//所有客户
		MESSAGE_RECEIVER_ALL = 'A'
	};


	/// <summary>
	/// 保证金计算方式
	/// </summary>
	public enum struct EnumDepositModeType
	{    //比例
		DEPOSIT_MODE_B = '1',
		//定额
		DEPOSIT_MODE_D = '2',
		//差值比例
		DEPOSIT_MODE_CB = '3',
		//差值定额
		DEPOSIT_MODE_CD = '4',
		//折扣
		DEPOSIT_MODE_Z = '5'

	};



	/// <summary>
	/// 日志类型类型
	/// </summary>
	public enum struct EnumLogTypeType
	{
		//登录日志
		LOGTYPE_LOGIN = '1'
	};


	/// <summary>
	/// 委托成交删除标记
	/// </summary>
	public enum struct EnumDeletedType
	{
		//是
		DEL_YES = 'Y',
		//否
		DEL_NO = 'N',
		//隐藏
		DEL_DISAPPEAR = 'D'
	};

	/// <summary>
	/// 是否包含合计值
	/// </summary>
	public enum struct EnumContainTotleType
	{
		//包含
		ContainTotle_Yes = 'Y',
		//不包含
		ContainTotle_No = 'N'
	};

	/// <summary>
	/// 本外币标识
	/// </summary>
	public enum struct EnumLWFlagType
	{    //境内人民币账户
		LWFlag_L = 'L',
		//客户境内外币账户
		LWFlag_W = 'W',
		//公司境内外币账户
		LJFFlag_J = 'J',
		//公司境外外币账户
		LJFFlag_F = 'F'
	};

	/// <summary>
	/// 监控事件类型类型
	/// </summary>
	public enum struct EnumEventTypeType
	{	//常规事件
		EVENT_TYPE_Y = 'Y',
		//非常规事件
		EVENT_TYPE_N = 'N'

	};

	/// <summary>
	/// 监控事件等级类型
	/// </summary>
	public enum struct EnumEventLevelType
	{	//正常
		EVENT_TYPE_NORMAL = 'N',
		//警报
		EVENT_TYPE_WARNNING = 'W',
		//错误
		EVENT_TYPE_ERROR = 'E'
	};

	/// <summary>
	/// 港交所报单操作类型
	/// </summary>
	public enum struct EnumHKMarketOperType
	{
		MarketOper_None = '\0',
		//下单
		MarketOper_Insert = 'I',
		//改单
		MarketOper_Modify = 'M',
		//撤单
		MarketOper_Delete = 'D'
	};
}
