#ifndef _ESUNNY_FOREIGN_TRADE_API_
#define _ESUNNY_FOREIGN_TRADE_API_

#include "EsForeignApiStruct.h"
#ifdef linux
#define __cdecl
#endif

namespace ESForeign
{
    //交易数据处理的回调处理类，当有数据到达本地时，API会回调本类中对应的接口
    //回调函数不能有阻塞性操作
    //OnRsp开头的函数为发送请求后对应的应答，OnRtn开头的函数为服务器主动推送数据
    class IEsunnyTradeSpi
    {
    public:
        ////////////////////////////////////////
        /// \fn    ~IEsunnyTradeSpi
        /// \brief 纯虚类，需要派生
        /// \return   
        ////////////////////////////////////////
        virtual ~IEsunnyTradeSpi() {};

        ////////////////////////////////////////
        /// \fn    OnOpen
        /// \brief 与服务器建立连接时调用
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnOpen() = 0;

        ////////////////////////////////////////
        /// \fn    OnClose
        /// \brief 与服务器断开连接时调用
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnClose() = 0;

        ////////////////////////////////////////
        /// \fn    OnLogin
        /// \brief 发送Login登陆成功时收到服务器登陆响应调用
        /// \param const TEsLoginRspField & rsp
        /// \param int iReqID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnInitFinished
        /// \brief 发送Login成功后，收到OnLogin应答成功后收到初始化操作完成
        ///        所有的业务操作需要在本响应errCode为0（成功）后可进行
        /// \param int errCode 错误码，0-成功，其他值-错误的原因代码
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnInitFinished(int errCode) = 0;

        ////////////////////////////////////////
        /// \fn    OnLogOut
        /// \brief 收到登出应答调用
        /// \param int errCode
        /// \param const int iReqID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnLogOut(int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspSetPassword
        /// \brief  修改客户密码时应答，返回信息包括修改密码详细内容
        /// \param const TEsClientPasswordModifyRspField & rsp
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspSetPassword(const TEsClientPasswordModifyRspField* rsp, int errCode, const int iReqID){};

        ////////////////////////////////////////
        /// \fn    OnRspSetOperPassword
        /// \brief 修改操作员密码时应答，返回信息包括修改密码详细内容
        /// \param const TEsOperatorPasswordModifyRspField & rsp
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspSetOperPassword(const TEsOperatorPasswordModifyRspField* rsp, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryMoney
        /// \brief 资金查询应答
        /// \param TEsMoneyQryRspField * rsp 查询完成时，指针为空，未完成时包含查询结果
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnMoney
        /// \brief 资金变化推送通知
        /// \param TEsMoneyChgNoticeField & rsp 资金变化详细信息
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnMoney(const TEsMoneyChgNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashOperQry
        /// \brief 出金入金查询应答
        /// \param TEsCashOperRspField * rsp查询完成时，指针为空，未完成时包含查询结果
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspCashOperQry(const TEsCashOperQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspCashOper
        /// \brief 出金入金操作应答
        /// \param TEsCashOperRspField * rsp 出入金操作的详细结果
		/// \param const int iReqID 对应发送请求的ID
		/// \note   不要在此函数中同步执行非强制出金的CashCheck
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspCashOper(const TEsCashOperRspField* rsp, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnCashOper
		/// \brief 出金入金操作推送通知
		/// \param TEsCashOperNoticeField & rsp 出入金操作的详细信息
		/// \return   void __cdecl
		/// \note   不要在此函数中同步执行非强制出金的CashCheck
        ////////////////////////////////////////
        virtual void __cdecl OnRtnCashOper(const TEsCashOperNoticeField& rsp) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspCashCheck
        /// \brief 出金入金审核应答
        /// \param TEsCashCheckRspField * rsp 出入金审核的详细结果
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspCashCheck(const TEsCashCheckRspField* rsp, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnCashCheck
        /// \brief 出金入金审核推送通知
        /// \param TEsCashCheckNoticeField & rsp 出入金审核的详细信息
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnCashCheck(const TEsCashCheckNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashAdjustQry
        /// \brief 资金调整查询应答
        /// \param TEsAdjustOperRspField * rsp 查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspCashAdjustQry(const TEsAdjustQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspOrderInsert
        /// \brief 报单请求的应答
        /// \param TEsOrderInsertRspField & rsp 报单请求的详细结果，会返回委托号及本地号
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspOrderModify
        /// \brief 改单请求的应答，出错时会收到本应答
        /// \param TEsOrderModifyRspField & rsp
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspOrderDelete
        /// \brief 撤单请求的应答，出错时会收到本应答
        /// \param TEsOrderDeleteRspField & rsp
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    OnRspQryOrder
        /// \brief 委托查询应答
        /// \param TEsOrderDataQryRspField * rsp 委托查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspHistOrderQry
        /// \brief 历史委托查询应答
        /// \param TEsHisOrderQryRspField * rsp 历史委托查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnOrderState
        /// \brief 委托变化通知，委托状态变化时回调
        /// \param TEsOrderStateNoticeField & rsp 委托详细数据
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnOrderState(const TEsOrderStateNoticeField& rsp) = 0;
        
        ////////////////////////////////////////
        /// \fn    OnRtnOrderInfo
        /// \brief 委托信息变化通知，委托信息变化时回调
        /// \param TEsOrderInfoNoticeField & rsp 委托信息详细数据
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspMatchQry
        /// \brief  成交查询应答
        /// \param TEsMatchDataQryRspField * rsp 成交查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnMatchState
        /// \brief 成交变化推送通知
        /// \param TEsMatchStateNoticeField & rsp 成交详细数据
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnMatchState(const TEsMatchStateNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRtnMatchInfo
        /// \brief 成交信息变化推送通知
        /// \param TEsMatchInfoNoticeField & rsp 成交信息详细数据
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspHistMatchQry
        /// \brief 历史成交查询应答
        /// \param TEsHisMatchQryRspField * rsp 历史成交查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryHold
        /// \brief 持仓查询应答
        /// \param TEsHoldQryRspField * rsp 持仓查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnHold
        /// \brief 持仓变化推送通知，暂时未用
        /// \param TEsHoldQryRspField & rsp 持仓详细信息
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnHold(const TEsHoldQryRspField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnQryExchangeState
        /// \brief 市场状态查询应答
        /// \param TEsExchangeQryRspField * rsp 市场状态详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnQryExchangeState(const TEsExchangeQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnExchangeState
        /// \brief 市场状态变更推送通知
        /// \param TEsExchangeQryRspField & rsp 市场状态详细信息
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnQryCommodity
        /// \brief 商品查询应答
        /// \param TEsCommodityQryRspField * rsp 商品详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryContract
        /// \brief 合约查询应答
        /// \param TEsContractQryRspField * rsp 合约详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnQryContract(const TEsContractQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryClient
        /// \brief 交易员下属客户信息查询应答
        /// \param TEsOperatorClientQryRspField * rsp 下属客户详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnQryClient(const TEsOperatorClientQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};


        ////////////////////////////////////////
        /// \fn    OnRspHistCashOperQry
        /// \brief 历史出金入金查询应答
        /// \param const TEsHisCashQryRspField * rsp
        /// \param TEsIsLastType islast
        /// \param int errCode
        /// \param const int iReqID
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspHistCashOperQry(const TEsHisCashOperQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashAdjustQry
        /// \brief 历史资金调整查询应答
        /// \param TEsAdjustOperRspField * rsp 查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspHistCashAdjustQry(const TEsHisAdjustQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspAuthClient
        /// \brief 用户密码验证请求应答
        /// \param const TEsLoginRspField * rsp
        /// \param int errCode
        /// \param const int iReqID
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspAuthClient(const TEsClientPasswordAuthRspField* rsp, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspQryCurrency
        /// \brief 查询货币币种信息应答
        /// \param const TEsCurrencyQryRspField * rsp
        /// \param int errCode
        /// \param const int iReqID
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnExchangeRateMod
        /// \brief 币种汇率变化通知
        /// \param const TEsCurrencyQryRspField * rsp
        /// \param TEsIsLastType islast
        /// \param int errCode
        /// \param const int iReqID
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnExchangeRateMod(const TEsExchangeRateModifyNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnOrderRemove
        /// \brief 委托删除通知
        /// \param const TEsOrderRemoveNoticeField & rsp
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnMatchRemove
        /// \brief 成交删除通知
        /// \param const TEsMatchRemoveNoticeField & rsp
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnMatchRemove(const TEsMatchRemoveNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnCommodityState
        /// \brief 商品状态变化通知
        /// \param const TEsCommodityStateModNotice & rsp
        /// \return void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl OnRtnCommodityState(const TEsCommodityStateModNoticeField& rsp) {};

		////////////////////////////////////////
		/// \fn    OnRtnContractAdd
		/// \brief 合约添加通知
		/// \param const TEsContractAddNoticeField & rsp
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnContractAdd(const TEsContractAddNoticeField& rsp) {};
		
		////////////////////////////////////////
		/// \fn    OnRspQryMonitorEvent
		/// \brief 查询监控事件应答
		/// \param const TEsMonitorEventQryRspField * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryMonitorEvent(const TEsMonitorEventQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

		////////////////////////////////////////
		/// \fn    OnRtnMonitorEvent
		/// \brief 监控事件通知
		/// \param const TEsMonitorEventNoticeField & rsp
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnMonitorEvent(const TEsMonitorEventNoticeField& rsp) {};

		////////////////////////////////////////
		/// \fn    OnRspMarketOrderInsert
		/// \brief 港交所做市商下单应答
		/// \param const TEsHKMarketOrderRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspHKMarketOrder(const TEsHKMarketOrderRsp* rsp,int errCode,const int iReqID) {};

		////////////////////////////////////////
		/// \fn    OnRspQryClientCountRent
		/// \brief 查询计算参数应答.
		/// \param const TClientCountRentQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryClientCountRent(const TClientCountRentQryRsp* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
		////////////////////////////////////////
		/// \fn    OnRspQryLmeContract
		/// \brief 查询LME到期日应答.
		/// \param const TClientCountRentQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryLmeContract(const TEsQryLmeContractRspField *rsp, int errCode, const int iReqID){};
		////////////////////////////////////////
		/// \fn    OnRtnLmeContract
		/// \brief LME到期日通知.
		/// \param const TLmeContractNotice * rsp
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRtnLmeContract(const TEsLmeContractNotice *info){};
		////////////////////////////////////////
		/// \fn    OnRspQryHisHold
		/// \brief 查询历史持仓应答.
		/// \param const THisHoldQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryHisHold(const TEsHisHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
		////////////////////////////////////////
		/// \fn    OnRspQryHisMoney
		/// \brief 查询历史资金应答.
		/// \param const THisHoldQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void __cdecl
		////////////////////////////////////////
		virtual void __cdecl OnRspQryHisMoney(const TEsHisMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
    };

    class IEsunnyTradeApi
    {
    public:
        ////////////////////////////////////////
        /// \fn    ~IEsunnyFeTradeApi
        /// \brief 虚析构函数，通过IEsunnyFeTradeApi指针能够删除交易API实例，
        /// 删除交易API实例时，推荐使用Free函数
        /// \return   
        ////////////////////////////////////////
        virtual ~IEsunnyTradeApi(){};

        ////////////////////////////////////////
        /// \fn    SetSpi
        /// \brief 设置回调数据接口，认证API通过后，需要调用本接口设置回调处理类
        /// \param IEsunnyTradeSpi * spi
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl SetSpi(IEsunnyTradeSpi* spi) = 0;

        ////////////////////////////////////////
        /// \fn    Free
        /// \brief 释放当前api会话
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl Free() = 0;

        ////////////////////////////////////////
        /// \fn    GetErrcodeDesc
        /// \brief 获取错误码的中文描述(多字节编码)
        /// \param int iErrcode
        /// \return   const char* __cdecl
        ////////////////////////////////////////
        virtual const char* __cdecl GetErrcodeDesc(int iErrcode) = 0;

        ////////////////////////////////////////
        /// \fn    Open
        /// \brief 连接交易服务器，返回成功只表明成功发出连接请求，是否建立连接需要
        /// 调用IsOpen函数
        /// \param TEsAddressField & addr
        /// \return   bool __cdecl
        ////////////////////////////////////////
        virtual bool __cdecl Open(const TEsAddressField& addr) = 0;

        ////////////////////////////////////////
        /// \fn    Close
        /// \brief 关闭交易服务器连接
        /// \return   void __cdecl
        ////////////////////////////////////////
        virtual void __cdecl Close() = 0;

        ////////////////////////////////////////
        /// \fn    IsOpen
        /// \brief 获取是否与交易服务器建立连接
        /// \return   bool __cdecl
        ////////////////////////////////////////
        virtual bool __cdecl IsOpen() = 0;

        ////////////////////////////////////////
        /// \fn    Login
        /// \brief 发送登录请求，暂时支持单客户登陆
        /// \param TEsLoginReq & req
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl Login(const TEsLoginReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    Login
		/// \brief 发送二次认证授权码
		/// \param TEsLoginReq & req
		/// \return   int __cdecl
		////////////////////////////////////////
		virtual int __cdecl SetVertificateCode(const TVertificateCodeType CertificateCode, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    LogOut
        /// \brief 发送退出请求
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl LogOut(int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    SetPassword
        /// \brief 修改客户密码
        /// \param TEsSetPassReqField & req
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl SetPassword(const TEsClientPasswordModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    SetOperPassword
        /// \brief 修改操作员密码，暂时未用
        /// \param const TEsOperatorPasswordModifyReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl SetOperPassword(const TEsOperatorPasswordModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryClients
        /// \brief 查询交易员下属客户，暂时未用
        /// \param const TOperatorClientQryReq & qryClients
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryClients(const TEsOperatorClientQryReqField& qryClients, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryMoney
        /// \brief 查询客户资金
        /// \param const TMoneyQryReq & qryMoney
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryMoney(const TEsMoneyQryReqField& qryMoney, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryOrder
        /// \brief 查询客户委托，查询所有数据 流号填0
        /// \param const TOrderQryReq & qryOrder
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryOrder(const TEsOrderQryReqField& qryOrder, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryMatch
        /// \brief 查询客户成交
        /// \param const TMatchQryReq & qryMatch
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryMatch(const TMatchQryReqField& qryMatch, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHold
        /// \brief 查询持仓
        /// \param const THoldQryReq & qryHold
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryHold(const TEsHoldQryReqField& qryHold, int& iReqID) = 0;


        ////////////////////////////////////////
        /// \fn    QryExchangeState
        /// \brief 查询交易所状态
        /// \param const TExchangeQryReq & qryExg
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryExchangeState(const TEsExchangeQryReqField& qryExg, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCommodity
        /// \brief 查询交易商品
        /// \param const TCommodityQryReq & qryCmdy
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryCommodity(const TEsCommodityQryReqField& qryCmdy, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryContract
        /// \brief 查询合约
        /// \param const TContractQryReq & qryCntr
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryContract(const TEsContractQryReqField& qryCntr, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderInsert
        /// \brief 报单请求
        /// \param TEsOrderInsertReqField & req
        /// \param int * pReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl OrderInsert(const TEsOrderInsertReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderModify
        /// \brief 改单请求
        /// \param TEsOrderModifyReqField & req
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl OrderModify(const TEsOrderModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderDelete
        /// \brief 撤单请求
        /// \param TEsOrderDeleteReqField & req
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl OrderDelete(const TEsOrderDeleteReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistOrder
        /// \brief 历史委托查询
        /// \param TEsHisOrderQryReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryHistOrder(const TEsHisOrderQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistMatch
        /// \brief 历史成交查询
        /// \param TEsHisMatchQryReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryHistMatch(const TEsHisMatchQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCashOper
        /// \brief 出金入金查询
        /// \param TEsCashOperQryReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryCashOper(const TEsCashOperQryReqField& req, int& iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    CashOper
        /// \brief 出金入金操作请求
        /// \param TEsCashOperReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl CashOper(const TEsCashOperReqField& req, int& iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    CashCheck
        /// \brief 出金入金审核请求
        /// \param TEsCashCheckReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl CashCheck(const TEsCashCheckReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCachAdjust
        /// \brief 资金调整查询
        /// \param TEsAdjustQryReqField & req
        /// \param int & iReqID
        /// \return   int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryCachAdjust(const TEsAdjustQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistCashOper
        /// \brief 历史出金入金查询
        /// \param const TEsHisCashQryReqField & req
        /// \param int & iReqID
        /// \return int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryHistCashOper(const TEsHisCashOperQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistCachAdjust
        /// \brief 历史资金调整查询
        /// \param const THisAdjustQryReq & req
        /// \param int & iReqID
        /// \return int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl QryHistCachAdjust(const TEsHisAdjustQryReqField& req, int& iReqID) = 0;     

        ////////////////////////////////////////
        /// \fn    AuthUserPassword
        /// \brief 验证用户名密码
        /// \param const TEsLoginReqField & req
        /// \param int & iReqID
        /// \return int __cdecl
        ////////////////////////////////////////
        virtual int __cdecl AuthClient(const TEsClientPasswordAuthReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCurrency
        /// \brief 查询货币币种信息
        /// \param const TEsCurrencyQryReqField & req
        /// \param int & iReqID
        /// \return int __cdecl
        ////////////////////////////////////////
		virtual int __cdecl QryCurrency(const TEsCurrencyQryReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    GetCertCodeExpireDate
		/// \brief 获取认证码过期日期
		/// \param TDateType & expireDate
		/// \return int __cdecl
		////////////////////////////////////////
		virtual int __cdecl GetCertCodeExpireDate(TDateType& expireDate) = 0;

		////////////////////////////////////////
		/// \fn    QryMonitorEvent
		/// \brief 查询监控事件
		/// \param const TEsMonitorEventQryReqField & req
		/// \param int & iReqID
		/// \return int __cdecl
		////////////////////////////////////////
		virtual int __cdecl QryMonitorEvent(const TEsMonitorEventQryReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    HKMarketOrderInsert
		/// \brief 下港交所做市商报单
		/// \param const THKMarketOrderReq & req
		/// \param int & iReqID
		/// \return int __cdecl
		////////////////////////////////////////
		virtual int __cdecl HKMarketOrderOperator(const ESForeign::TEsHKMarketOrderReq& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn QryCountRent
		/// \brief 客户计算参数查询
		/// \param const TClientCountRentReq &req
		/// \param int &iReqID
		///\return int __cdecl
		///////////////////////////////////////
		virtual int __cdecl QryCountRent(const ESForeign::TClientCountRentQryReq &req, int & iReqID) = 0;
		///////////////////////////////////////
		/// \fn QryLmeContract
		/// \brief LME到期日查询
		/// \param int &iReqID
		/// \return int __cdecl
		//////////////////////////////////////
		virtual int __cdecl QryLmeContract(int &iReqID) = 0;

		//////////////////////////////////////
		/// \fn QryHisHold
		/// \brief 查询历史持仓
		/// \param const THisHoldQryReq &req
		/// \param int &iReqID
		/// \return int __cdecl
		/////////////////////////////////////
		virtual int __cdecl QryHisHold(const ESForeign::TEsHisHoldQryReqField &req, int &iReqID) = 0;

		//////////////////////////////////////
		/// \fn QryHisHold
		/// \brief 查询历史资金.
		/// \param const THisMoneyQryReq &req
		/// \param int &iReqID
		/// \return int __cdecl
		//////////////////////////////////////
		virtual int __cdecl QryHisMoney(const ESForeign::TEsHisMoneyQryReqField &req, int &iReqID) = 0;


    };
}

extern "C"
{
    ////////////////////////////////////////
    /// \fn    GetEsunnyForeignApiVersion
    /// \brief 获取API当前版本
    /// \param ESForeign::TEsVersionType version 版本详细信息
    /// \return   void __cdecl
    ////////////////////////////////////////
    void __cdecl GetEsunnyForeignApiVersion(ESForeign::TEsVersionType version);

    ////////////////////////////////////////
    /// \fn    CreateEsunnyForeignTradeApi
    /// \brief 
    /// \param ESForeign::TEsCertInfoType cert 认证码
    /// \param ESForeign::TEsLogPathType path  日志路径
    /// \param int * pRetCode 错误码，输出参数，需要传入保存错误码的变量地址，其中高16位为保留信息
    ///        低16位为错误码，获取实际错误码需要对高16位清零
    /// \return   ESForeign::IEsunnyTradeApi* __cdecl 返回交易API实例的指针，如果认证失败，返回NULL，错误码保存在
    ///           pRetCode指向内容的低16位
    ////////////////////////////////////////
    ESForeign::IEsunnyTradeApi* __cdecl CreateEsunnyForeignTradeApi(ESForeign::TEsCertInfoType cert, int* pRetCode, 
		ESForeign::TEsLogPathType path, ESForeign::TEsAppIDType appID);

    ////////////////////////////////////////
    /// \fn    DelEsunnyForeignTradeApi
    /// \brief 通过CreateEsunnyForeignTradeApi创建的交易实例通过本接口释放资源
    /// \param ESForeign::IEsunnyTradeApi * pAPI
    /// \return   void __cdecl
    ////////////////////////////////////////
    void __cdecl DelEsunnyForeignTradeApi(ESForeign::IEsunnyTradeApi* pAPI);
}


#endif
