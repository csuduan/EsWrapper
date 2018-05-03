#pragma once

namespace EsForeignWrapper
{
    //Quot delegate
	public delegate void RspQuotLogin(int err, String^ errtext);
	public delegate void ChannelLost(int err, String^ errtext);
	public delegate void StkQuot(StkData^ pData);
	public delegate void RspHistoryQuot(StkHisData^ pHisData);
	public delegate void RspTraceData(StkTraceData^ pTraceData);
	public delegate void RspMarketInfo(WMarketInfo^ pMarketInfo, int bLast);

	//Trade delegate
	public delegate void RspOpen();
	public delegate void RspClose();
	public delegate void RspLogin(LoginRspField^ pLoginRspField, int errCode, int iReqID);
	public delegate void RspInitFinished(int errCode);
	public delegate void RspLogOut(int errCode,  int iReqID);
	
	
	public delegate void RspOrderInsert( OrderInsertRspField^ pOrderInsertRspField, int errCode, int iReqID);
	public delegate void RspOrderModify( OrderModifyRspField^ rsp, int errCode,int iReqID);
	public delegate void RspOrderDeleteError(int errCode, int iReqID);
	public delegate void RspQryOrder(OrderInfoNoticeField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RspHistOrderQry( HisOrderQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RtnOrderState( OrderStateNoticeField^ rsp);
	public delegate void RtnOrderInfo( OrderInfoNoticeField^ rsp);

	public delegate void RspMatchQry(MatchInfoNoticeField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RtnMatchState( MatchStateNoticeField^ rsp);
	public delegate void RtnMatchInfo( MatchInfoNoticeField^ rsp);
	public delegate void RspHistMatchQry( HisMatchQryRspField^ rsp, bool islast, int errCode,  int iReqID);

	public delegate void QryContract( ContractQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RtnOrderRemove( OrderRemoveNoticeField^ rsp);
	public delegate void RtnMatchRemove( MatchRemoveNoticeField^ rsp);

	public delegate void QryMoney(MoneyQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RspCashOperQry(CashOperQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void QryHold(HoldQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void QryCommodity(CommodityQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RspQryCurrency(CurrencyQryRspField^ rsp, bool islast, int errCode,  int iReqID);
	public delegate void RtnExchangeState(ExchangeStateModifyNoticeField^ rsp);


};
