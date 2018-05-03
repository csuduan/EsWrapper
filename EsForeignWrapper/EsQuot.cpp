#pragma once
#include "Stdafx.h"
#include "EsQuot.h"


namespace EsForeignWrapper
{
	EsQuotApi::EsQuotApi(String^ secretkey, int option)
	{
		this->errorID = -1024;
		this->bLogin = false;
		this->pQuotNotify = new	EsQuotSpi(this);
		this->pQuotClient = CreateEsunnyQuotClient(this->pQuotNotify);

		//³õÊ¼»¯APIÃØÔ¿
		this->pQuotClient->InitSecretKey((char*)(void*)Marshal::StringToHGlobalAnsi(secretkey), option);

	}

	EsQuotApi::~EsQuotApi()
	{
	}


	//API
	int EsQuotApi::Connect(String^ ip, int port)
	{
		return this->pQuotClient->Connect((char*)(void*)Marshal::StringToHGlobalAnsi(ip), port);
	}

	void EsQuotApi::DisConnect()
	{
		return this->pQuotClient->DisConnect();
	}

	void EsQuotApi::Free()
	{
		//this->pQuotClient->DisConnect();
		DelEsunnyQuotClient(this->pQuotClient);
	}

	int EsQuotApi::Login(String^ user, String^ password)
	{
		return this->pQuotClient->Login((char*)(void*)Marshal::StringToHGlobalAnsi(user), (char*)(void*)Marshal::StringToHGlobalAnsi(password));
	}


	int EsQuotApi::RequestQuot(String^ market, String^ stk, int need)
	{
		return this->pQuotClient->RequestQuot((char*)(void*)Marshal::StringToHGlobalAnsi(market), (char*)(void*)Marshal::StringToHGlobalAnsi(stk), need);
	}

	int EsQuotApi::RequestHistory(String^ market, String^ stk, int period)
	{
		return this->pQuotClient->RequestHistory((char*)(void*)Marshal::StringToHGlobalAnsi(market), (char*)(void*)Marshal::StringToHGlobalAnsi(stk), period);
	}

	int EsQuotApi::RequestTrace(String^ market, String^ stk, String^ date)
	{
		return this->pQuotClient->RequestTrace((char*)(void*)Marshal::StringToHGlobalAnsi(market), (char*)(void*)Marshal::StringToHGlobalAnsi(stk), (char*)(void*)Marshal::StringToHGlobalAnsi(date));
	}

	int EsQuotApi::AddReqStk(String^ market, String^ stk, int need)
	{
		return this->pQuotClient->AddReqStk((char*)(void*)Marshal::StringToHGlobalAnsi(market), (char*)(void*)Marshal::StringToHGlobalAnsi(stk), need);
	}

	int EsQuotApi::SendReqStk()
	{
		return this->pQuotClient->SendReqStk();
	}

	



	//SPI

	int EsQuotSpi::OnRspLogin(int err, const char *errtext)
	{
		this->client->OnRspLogin(err, gcnew String(errtext));		
		return 0;
	}

	int EsQuotSpi::OnChannelLost(int err, const char *errtext)
	{
		this->client->OnChannelLost(err, gcnew String(errtext));
		return 0;
	}

	int EsQuotSpi::OnStkQuot(struct STKDATA *pData)
	{
		this->client->OnStkQuot(TypeConverter<StkData^, STKDATA>::ToManagedType(pData));
		return 0;
	}

	int EsQuotSpi::OnRspHistoryQuot(struct STKHISDATA *pHisData)
	{
		if (pHisData != NULL)
		{
			array<HistoryData^>^ arrayEHISTORYDATA = gcnew array<HistoryData^>(pHisData->nCount);
			StkHisData^ mESTKHISDATA = gcnew StkHisData();
			mESTKHISDATA->Market = gcnew String(pHisData->Market);
			mESTKHISDATA->Code = gcnew String(pHisData->Code);
			mESTKHISDATA->nPeriod = pHisData->nPeriod;
			mESTKHISDATA->nCount = pHisData->nCount;
			mESTKHISDATA->HisData = arrayEHISTORYDATA;
			for (int i = 0; i < pHisData->nCount; i++)
			{
				arrayEHISTORYDATA[i] = TypeConverter<HistoryData^, HISTORYDATA>::ToManagedType(&pHisData->HisData[i]);
			}

			this->client->OnRspHistoryQuot(mESTKHISDATA);
		}

		return 0;
	}

	int EsQuotSpi::OnRspTraceData(struct STKTRACEDATA * pTraceData)
	{
		if (pTraceData != NULL)
		{
			array<StockTraceData^>^ arrayESTOCKTRACEDATA = gcnew array<StockTraceData^>(pTraceData->nCount);
			StkTraceData^ mESTKTRACEDATA = gcnew StkTraceData();
			mESTKTRACEDATA->Market = gcnew String(pTraceData->Market);
			mESTKTRACEDATA->Code = gcnew String(pTraceData->Code);
			mESTKTRACEDATA->nCount = pTraceData->nCount;
			mESTKTRACEDATA->TraceData = arrayESTOCKTRACEDATA;
			for (int i = 0; i < pTraceData->nCount; i++)
			{
				arrayESTOCKTRACEDATA[i] = TypeConverter<StockTraceData^, STOCKTRACEDATA>::ToManagedType(&pTraceData->TraceData[i]);
			}

			this->client->OnRspTraceData(mESTKTRACEDATA);
		}
		return 0;
	}

	int EsQuotSpi::OnRspMarketInfo(struct MarketInfo * pMarketInfo, int bLast)
	{
		if (pMarketInfo != NULL)
		{
			array<WStockInfo^>^ arrayEStockInfo = gcnew array<WStockInfo^>(pMarketInfo->stocknum);
			WMarketInfo^ mEMarketInfo = gcnew WMarketInfo();
			mEMarketInfo->Market = gcnew String(pMarketInfo->Market);
			mEMarketInfo->stocknum = pMarketInfo->stocknum;
			mEMarketInfo->stockdata = arrayEStockInfo;
			for (int i = 0; i < pMarketInfo->stocknum; i++)
			{
				arrayEStockInfo[i] = TypeConverter<WStockInfo^, StockInfo>::ToManagedType(&pMarketInfo->stockdata[i]);
			}

			this->client->OnRspMarketInfo(mEMarketInfo, bLast);
		}

		return 0;
	}

}

