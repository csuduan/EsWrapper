#include "stdafx.h"
#include "EsTrade.h"
#include <exception>   

namespace EsForeignWrapper
{
#pragma region API函数实现
	EsTradeApi::EsTradeApi(String^ cer, String^ logPath, String^ appId)
	{
		//char *frontAddress = (char*)(void*)Marshal::StringToHGlobalAnsi(pszFrontAddress);
		char *pcer = (char*)(void*)Marshal::StringToHGlobalAnsi(cer);
		char *pAppId = (char*)(void*)Marshal::StringToHGlobalAnsi(appId);
		char *plogPath = (char*)(void*)Marshal::StringToHGlobalAnsi(logPath);
		int pRetCode = -1;
		//创建API
		this->pIEsunnyTradeApi = CreateEsunnyForeignTradeApi(pcer, &pRetCode, plogPath, pAppId);
		if (pIEsunnyTradeApi == NULL) {
			throw gcnew Exception("CreateEsunnyForeignTradeApi ERROR,Code:" + pRetCode);
		}

		//创建SPI
		this->pIEsunnyTradeSpi = new EsTradeSpi(this);
		//设置SPI
		this->pIEsunnyTradeApi->SetSpi(this->pIEsunnyTradeSpi);


	}
	EsTradeApi::~EsTradeApi() {
	}

	void EsTradeApi::Free()
	{
		//断开连接
		this->pIEsunnyTradeApi->Close();
		//销毁实例
		this->pIEsunnyTradeApi->Free();
	}

	String^  EsTradeApi::GetErrcodeDesc(int iErrcode)
	{
		return gcnew String(this->pIEsunnyTradeApi->GetErrcodeDesc(iErrcode));

	}

	bool EsTradeApi::Open(AddressField^ addr)
	{
		bool isOpen = this->pIEsunnyTradeApi->IsOpen();
		if (isOpen == false) {
			Console::WriteLine("EsTradeApi未连接，开始连接...");
			TEsAddressField addrField;
			Marshal::StructureToPtr(addr, IntPtr(&addrField), true);
			isOpen=this->pIEsunnyTradeApi->Open(addrField);
		}
		return isOpen;
	}



	bool EsTradeApi::IsOpen()
	{
		return this->pIEsunnyTradeApi->IsOpen();
	}

	int EsTradeApi::Login(LoginReqField^ loginReqField, int iReqID)
	{

		TEsLoginReqField  req;
		Marshal::StructureToPtr(loginReqField, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->Login(req, iReqID);
	}

	int EsTradeApi::LogOut(int iReqID)
	{
		return this->pIEsunnyTradeApi->LogOut(iReqID);
	}

	int  EsTradeApi::SetVertificateCode(String^ certificateCode, int iReqID)
	{
		char *pcer = (char*)(void*)Marshal::StringToHGlobalAnsi(certificateCode);
		return this->pIEsunnyTradeApi->SetVertificateCode(pcer,iReqID);
	}

	String^  EsTradeApi::GetCertCodeExpireDate()
	{
		char pexpireDate[11];		
		this->pIEsunnyTradeApi->GetCertCodeExpireDate(pexpireDate);
		String^ ret = Marshal::PtrToStringAnsi(IntPtr(&pexpireDate));
		return ret;

	}



	int  EsTradeApi::OrderInsert(OrderInsertReqField^ orderInsertReqField, int iReqID)
	{
		TEsOrderInsertReqField req;
		Marshal::StructureToPtr(orderInsertReqField, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->OrderInsert(req, iReqID);

	}

	int  EsTradeApi::OrderDelete(int orderId, int iReqID)
	{
		TEsOrderDeleteReqField req;
		req.OrderId = orderId;
		return this->pIEsunnyTradeApi->OrderDelete(req,iReqID);
	}

	int EsTradeApi::QryMoney(MoneyQryReqField^ qryMoney, int iReqID)
	{
		TEsMoneyQryReqField req;
		Marshal::StructureToPtr(qryMoney, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryMoney(req,iReqID);
	}

	int  EsTradeApi::QryOrder(OrderQryReqField^ qryOrder, int iReqID)
	{
		TEsOrderQryReqField req;
		Marshal::StructureToPtr(qryOrder, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryOrder(req, iReqID);
	}
	int  EsTradeApi::QryMatch(MatchQryReqField^ qryMatch, int iReqID)
	{
		TMatchQryReqField req;
		Marshal::StructureToPtr(qryMatch, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryMatch(req, iReqID);
	}
	int   EsTradeApi::QryHold(HoldQryReqField^ qryHold, int iReqID)
	{
		TEsHoldQryReqField req;
		Marshal::StructureToPtr(qryHold, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryHold(req, iReqID);
	}

	int  EsTradeApi::QryCommodity(CommodityQryReqField^ qryCmdy, int iReqID)
	{
		TEsCommodityQryReqField req;
		Marshal::StructureToPtr(qryCmdy, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryCommodity(req, iReqID);
	}

	int   EsTradeApi::QryHistOrder(HisOrderQryReqField^ qryOrder, int iReqID)
	{
		TEsHisOrderQryReqField req;
		Marshal::StructureToPtr(qryOrder, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryHistOrder(req, iReqID);
	}

	int  EsTradeApi::QryHistMatch(HisMatchQryReqField^ qryMatch, int iReqID)
	{
		TEsHisMatchQryReqField req;
		Marshal::StructureToPtr(qryMatch, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryHistMatch(req, iReqID);
	}

	int EsTradeApi::QryCurrency(CurrencyQryReqField^ qryCurrency, int iReqID)
	{
		TEsCurrencyQryReqField req;
		Marshal::StructureToPtr(qryCurrency, IntPtr(&req), true);
		return this->pIEsunnyTradeApi->QryCurrency(req, iReqID);
	}



#pragma endregion


#pragma region SPI函数实现
	//纯虚类，需要派生
	EsTradeSpi::~EsTradeSpi()
	{
		Console::WriteLine("EsTradeSpi销毁");
	}


	//与服务器建立连接时调用
	void EsTradeSpi::OnOpen()
	{
		Console::WriteLine("EsTradeSpi连接回调");
		this->esTradeApi->OnRspOpen();
	}


	//与服务器断开连接时调用
	void EsTradeSpi::OnClose()
	{
		this->esTradeApi->OnRspClose();
	}


	//发送Login登陆成功时收到服务器登陆响应调用
	void EsTradeSpi::OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspLogin(TypeConverter<LoginRspField^,  TEsLoginRspField>::ToManagedType((TEsLoginRspField *)rsp),errCode,iReqID);
	}


	/// \brief 发送Login成功后，收到OnLogin应答成功后收到初始化操作完成
	///        所有的业务操作需要在本响应errCode为0（成功）后可进行
	/// \param int errCode 错误码，0-成功，其他值-错误的原因代码
	void EsTradeSpi::OnInitFinished(int errCode)
	{
		this->esTradeApi->OnRspInitFinished(errCode);
	}


	/// \brief 收到登出应答调用
	void EsTradeSpi::OnLogOut(int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspLogOut(errCode,iReqID);
	}



	/// \brief 资金查询应答
	void EsTradeSpi::OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnQryMoney(TypeConverter<MoneyQryRspField^, TEsMoneyQryRspField>::ToManagedType((TEsMoneyQryRspField *)rsp),islast,errCode,iReqID);
	}




	////////////////////////////////////////
	/// \fn    OnRspOrderInsert
	/// \brief 报单请求的应答
	/// \param TEsOrderInsertRspField & rsp 报单请求的详细结果，会返回委托号及本地号
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspOrderInsert(TypeConverter<OrderInsertRspField^, TEsOrderInsertRspField>::ToManagedType((TEsOrderInsertRspField *)rsp),errCode,iReqID);
	}

	////////////////////////////////////////
	/// \fn    OnRspOrderModify
	/// \brief 改单请求的应答，出错时会收到本应答
	/// \param TEsOrderModifyRspField & rsp
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void  EsTradeSpi::OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspOrderModify(TypeConverter<OrderModifyRspField^, TEsOrderModifyRspField>::ToManagedType((TEsOrderModifyRspField *)rsp), errCode, iReqID);
	}

	////////////////////////////////////////
	/// \fn    OnRspOrderDelete
	/// \brief 撤单请求的应答，出错时会收到本应答
	/// \param TEsOrderDeleteRspField & rsp
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspOrderDeleteError( errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnRspQryOrder
	/// \brief 委托查询应答
	/// \param TEsOrderDataQryRspField * rsp 委托查询结果，查询完成时，指针为空
	/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspQryOrder(TypeConverter<OrderDataQryRspField^, TEsOrderDataQryRspField>::ToManagedType((TEsOrderDataQryRspField *)rsp),islast, errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnRspHistOrderQry
	/// \brief 历史委托查询应答
	/// \param TEsHisOrderQryRspField * rsp 历史委托查询结果，查询完成时，指针为空
	/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspHistOrderQry(TypeConverter<HisOrderQryRspField^, TEsHisOrderQryRspField>::ToManagedType((TEsHisOrderQryRspField *)rsp), islast, errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnRtnOrderState
	/// \brief 委托变化通知，委托状态变化时回调
	/// \param TEsOrderStateNoticeField & rsp 委托详细数据
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnOrderState(const TEsOrderStateNoticeField& rsp)
	{
		this->esTradeApi->OnRtnOrderState(TypeConverter<OrderStateNoticeField^, TEsOrderStateNoticeField>::ToManagedType((TEsOrderStateNoticeField *)&rsp));

	}

	////////////////////////////////////////
	/// \fn    OnRtnOrderInfo
	/// \brief 委托信息变化通知，委托信息变化时回调
	/// \param TEsOrderInfoNoticeField & rsp 委托信息详细数据
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp)
	{
		this->esTradeApi->OnRtnOrderInfo(TypeConverter<OrderInfoNoticeField^, TEsOrderInfoNoticeField>::ToManagedType((TEsOrderInfoNoticeField *)&rsp));
	}

	////////////////////////////////////////
	/// \fn    OnRspMatchQry
	/// \brief  成交查询应答
	/// \param TEsMatchDataQryRspField * rsp 成交查询结果，查询完成时，指针为空
	/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspMatchQry(TypeConverter<MatchDataQryRspField^, TEsMatchDataQryRspField>::ToManagedType((TEsMatchDataQryRspField *)rsp), islast, errCode, iReqID);
	}

	////////////////////////////////////////
	/// \fn    OnRtnMatchState
	/// \brief 成交变化推送通知
	/// \param TEsMatchStateNoticeField & rsp 成交详细数据
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnMatchState(const TEsMatchStateNoticeField& rsp)
	{
		this->esTradeApi->OnRtnMatchState(TypeConverter<MatchStateNoticeField^, TEsMatchStateNoticeField>::ToManagedType((TEsMatchStateNoticeField *)&rsp));

	}

	////////////////////////////////////////
	/// \fn    OnRtnMatchInfo
	/// \brief 成交信息变化推送通知
	/// \param TEsMatchInfoNoticeField & rsp 成交信息详细数据
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp)
	{
		this->esTradeApi->OnRtnMatchInfo(TypeConverter<MatchInfoNoticeField^, TEsMatchInfoNoticeField>::ToManagedType((TEsMatchInfoNoticeField *)&rsp));

	}

	////////////////////////////////////////
	/// \fn    OnRspHistMatchQry
	/// \brief 历史成交查询应答
	/// \param TEsHisMatchQryRspField * rsp 历史成交查询结果，查询完成时，指针为空
	/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspHistMatchQry(TypeConverter<HisMatchQryRspField^, TEsHisMatchQryRspField>::ToManagedType((TEsHisMatchQryRspField *)rsp), islast, errCode, iReqID);

	}

	////////////////////////////////////////
	/// \fn    OnQryHold
	/// \brief 持仓查询应答
	/// \param TEsHoldQryRspField * rsp 持仓查询结果，查询完成时，指针为空
	/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnQryHold(TypeConverter<HoldQryRspField^, TEsHoldQryRspField>::ToManagedType((TEsHoldQryRspField *)rsp), islast, errCode, iReqID);
	}


	////////////////////////////////////////
	/// \fn    OnRtnExchangeState
	/// \brief 市场状态变更推送通知
	/// \param TEsExchangeQryRspField & rsp 市场状态详细信息
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp)
	{
		this->esTradeApi->OnRtnExchangeState(TypeConverter<ExchangeStateModifyNoticeField^, TEsExchangeStateModifyNoticeField>::ToManagedType((TEsExchangeStateModifyNoticeField *)&rsp));
	
	}


	////////////////////////////////////////
	/// \fn    OnQryCommodity
	/// \brief 商品查询应答
	/// \param TEsCommodityQryRspField * rsp 商品详细信息，查询完成时，指针为空
	/// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
	/// \param const int iReqID 对应发送请求的ID
	/// \return   void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnQryCommodity(TypeConverter<CommodityQryRspField^, TEsCommodityQryRspField>::ToManagedType((TEsCommodityQryRspField *)rsp), islast, errCode, iReqID);
	}



	////////////////////////////////////////
	/// \fn    OnRspQryCurrency
	/// \brief 查询货币币种信息应答
	/// \param const TEsCurrencyQryRspField * rsp
	/// \param int errCode
	/// \param const int iReqID
	/// \return void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID)
	{
		this->esTradeApi->OnRspQryCurrency(TypeConverter<CurrencyQryRspField^, TEsCurrencyQryRspField>::ToManagedType((TEsCurrencyQryRspField *)rsp), islast, errCode, iReqID);
	}



	////////////////////////////////////////
	/// \fn    OnRtnOrderRemove
	/// \brief 委托删除通知
	/// \param const TEsOrderRemoveNoticeField & rsp
	/// \return void __cdecl
	////////////////////////////////////////
	void EsTradeSpi::OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp)
	{
		this->esTradeApi->OnRtnOrderRemove(TypeConverter<OrderRemoveNoticeField^, TEsOrderRemoveNoticeField>::ToManagedType((TEsOrderRemoveNoticeField *)&rsp));
	}





#pragma endregion
}
