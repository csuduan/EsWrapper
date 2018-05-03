#ifndef ESUNNY_QUOT_H
#define ESUNNY_QUOT_H

#ifdef linux
#define __cdecl
#endif

const int ESUNNY_QUOT_ERR_SUCCESS				=  0; //成功
const int ESUNNY_QUOT_ERR_CONNFAIL				= -1; //连接失败
const int ESUNNY_QUOT_ERR_SETSOCK				= -2; //设置连接属性失败
const int ESUNNY_QUOT_ERR_NOCONN				= -3; //未连接
const int ESUNNY_QUOT_ERR_NOLOGGED				= -4; //未登录
const int ESUNNY_QUOT_ERR_NOCONTRACT			= -5; //未找到此合约代码
const int ESUNNY_QUOT_ERR_DATEINCORRECT			= -6; //日期不正确
const int ESUNNY_QUOT_ERR_SUBNUMEXCEED			= -7; //行情订阅数量超限
const int ESUNNY_QUOT_ERR_SUBFREQUENCYEXCEED	= -8; //行情订阅频率超限

#pragma	pack(1)
struct STKDATA //即时数据结构
{
	char	Market[40];		//市场中文名
	char	Code[66];		//合约代码

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

	float	Ask[10];			//申卖价
	float	AskVol[10];		//申卖量
	float	Bid[10];			//申买价
	float	BidVol[10];		//申买量			

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

struct HISTORYDATA //历史数据
{  
	char	time[20];	//时间,形如：2009-06-01 08:00:00
	float	fOpen;		//开盘
	float	fHigh;		//最高
	float	fLow;			//最低
	float	fClose;		//收盘
	float	fVolume;		//成交量(手)
	float	fAmount;		//成交额(元)
};

struct STKHISDATA	//品种历史数据
{
	char			Market[40];	//市场中文名
	char			Code[66];	//品种代码
	short			nPeriod;	//周期
	short			nCount;		//历史数据数目
	struct HISTORYDATA	HisData[1];
};

struct STOCKTRACEDATA  //成交明细
{
	char	time[20];	//时间,形如：2009-06-01 08:00:00
	float	m_NewPrice;		//最新价
	float	m_Volume;		//总量
	float	m_Amount;		//持仓
	float	m_BuyPrice;		//委买价
	float	m_SellPrice;	//委卖价
	float	m_BuyVol;		//申买量
	float	m_SellVol;		//申卖量
};

struct STKTRACEDATA //品种明细
{
	char			Market[40];	//市场中文名
	char			Code[66];	//品种代码
	unsigned short	nCount;		//记录数目
	struct STOCKTRACEDATA	TraceData[1];
};

struct StockInfo//合约信息
{
	char    szCode[66];     //合约代码
    char	szName[128];  //中文名称
    unsigned char	Precision;    //精度，小数点位数	
};

struct MarketInfo//单个市场的合约信息
{
	char			Market[40];	//市场中文名
	unsigned short stocknum;//合约数目
	struct StockInfo	stockdata[1];//合约信息数据
};

class IEsunnyQuotClient
{
public:
	/**
	*连接行情数据服务器IP及端口
	* @param ip 服务器的IP
	* @param port 服务器的端口
	* @return 0表示连接成功，否则失败
	*/
	virtual int __cdecl Connect(const char *ip,int port)=0;
	
	/**
	*断开当前连接
	*/
	virtual void __cdecl DisConnect()=0;

	/**
	*登录行情数据服务器
	* @param user 登录用户名
	* @param password 登录密码
	* @return 0表示登录指令发送成功，否则发送失败，是否登录成功通过回调OnRspLogin
	*/
	virtual int __cdecl Login(const char *user,const char *password)=0;

	/**
	*请求/取消订阅品种即时行情
	* @param market 市场中文名,目前随意填写
	* @param stk 合约代码
	* @param need 1表示订阅，0表示取消订阅
	* @return 0表示订阅请求成功，否则失败，成功之后将会在OnStkQuot中收到品种的即时行情
	*/
	virtual int __cdecl RequestQuot(const char *market,const char *stk,int need)=0;

	/**
	*请求品种历史行情
	* @param market 市场中文名,目前随意填写
	* @param stk 合约代码
	* @param period 周期 1：1分钟，2：5分钟，3：60分钟，4：日线
	* @return 0表示请求成功，否则失败，历史数据结果在OnRspHistoryQuot返回
	*/
	virtual int __cdecl RequestHistory(const char *market,const char *stk,int period)=0;

	/**
	*请求品种明细数据
	* @param market 市场中文名,目前随意填写
	* @param stk 合约代码
	* @param date 要请求明细的日期，形如20090901
	* @return 0表示请求成功，否则失败，历史数据结果在OnRspTraceData返回
	*/
	virtual int __cdecl RequestTrace(const char *market,const char *stk,const char *date)=0;

	/**
	*针对订阅品种比较多时，先循环调用AddReqStk，最后调用一次SendReqStk
	* @param market 市场中文名,目前随意填写
	* @param stk 合约代码
	* @param need 1表示订阅，0表示取消订阅
	* @return 0表示订阅请求成功，否则失败，成功之后将会在OnStkQuot中收到品种的即时行情
	*/
	virtual int __cdecl AddReqStk(const char *market,const char *stk,int need)=0;
	/**
	*给服务器发送品种订阅请求
	* @return 0表示订阅请求成功，否则失败，成功之后将会在OnStkQuot中收到品种的即时行情
	*/
	virtual int __cdecl SendReqStk()=0;
	/**
	*初始化API密钥
	* @param secretkey 密钥
	* @param option 1表示需要订阅期权品种，0表示不需要订阅期权
	* @return 0表示成功，否则失败
	*/
	virtual int __cdecl InitSecretKey(const char *secretkey,int option)=0;
};

class IEsunnyQuotNotify
{
public:
	/**
	*登录反馈回调函数
	* @param err 错误号 0表示登录成功，否则失败
	* @param errtext 错误信息
	* @return 0表示成功，否则失败
	*/
	virtual int __cdecl OnRspLogin(int err,const char *errtext)=0;

	/**
	*物理连接出错回调函数
	* @param err 错误号 
	* @param errtext 错误信息
	* @return 0表示成功，否则失败
	*/
	virtual int __cdecl OnChannelLost(int err,const char *errtext)=0;

	/**
	*即时行情回调函数
	* @param pData 行情结构指针
	* @return 0表示成功，否则失败
	*/
	virtual int __cdecl OnStkQuot(struct STKDATA *pData)=0;

	/**
	*历史行情反馈回调函数
	* @param pHisData 历史行情数据结构指针
	* @return 0表示成功，否则失败
	*/
	virtual int __cdecl OnRspHistoryQuot(struct STKHISDATA *pHisData)=0;

	/**
	*明细数据反馈回调函数
	* @param pTraceData 明细数据结构指针
	* @return 0表示成功，否则失败
	*/
	virtual int __cdecl OnRspTraceData(struct STKTRACEDATA *pTraceData)=0;
	/**
	*市场信息包反馈函数，收到市场信息表示数据已经初始化完成了！
	* @param pMarketInfo 市场信息数据指针
	* @param bLast 是否为最后一个市场，bLast为1表示是最后一个，0表示后面还有市场数据
	* @return 0表示成功，否则失败,
	*/
	virtual int __cdecl OnRspMarketInfo(struct MarketInfo *pMarketInfo,int bLast)=0;
};

//---------------- API 接口函数

//创建接口指针(使用前调用)
IEsunnyQuotClient * __cdecl CreateEsunnyQuotClient(IEsunnyQuotNotify * notify);

//释放接口指针(使用后调用)
void __cdecl DelEsunnyQuotClient(IEsunnyQuotClient * client);
#pragma	pack()

#endif