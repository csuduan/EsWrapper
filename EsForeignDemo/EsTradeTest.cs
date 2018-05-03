using EsForeignWrapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows;

namespace EsForeignDemo
{
    public class EsTradeTest
    {
        private EsTradeApi trade = null;
        private string username = "C1385";
        private string pwd = "123123";
        private int requestId = 0;
        public void Start() {

            //易盛模拟盘
            //string APPID = "67338859E3A72F71581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D7749635E59";
            //string CER = "C7833C7AE258DB7174AADD371C6BCC7C659DEA0C1BE1425CA76D75D96007A7267AFE4CBF4CAA52FD1EFE57BEF5308F29445061B3CAE2B5C1090D22E5AF1CA4CBFA09C85289E65EAE627862A264D8F95D30D8D766857003C2581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963D050C47BED3ED850EB24DD23CBAEB147374BDA8B40E4214C581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D77496354E606ACCBE47772";
            //string username = "Q184876996";
            //string pwd = "477796";
            //123.15.58.21：7070

            //新永安模拟盘
            //string APPID = "BAEF21E7DB295FBDBF0EBAF9A9EC9C55581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D7749635E59";
            //string CER = "C7833C7AE258DB7174AADD371C6BCC7C659DEA0C1BE1425CA76D75D96007A7267AFE4CBF4CAA52FD1EFE57BEF5308F298EA16AAF1A0EC584B5F7DA7EDE31A4208F0C4F93323BA3A021EBAC0A10A1C8D7E6AC33C20D057FB9F46A17DB8A69C9DD581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963D050C47BED3ED850EB24DD23CBAEB147374BDA8B40E4214C581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D77496354E606ACCBE47772";
            //string username = "C1385";
            //string pwd = "123123";
            //122.224.221.238: 57802

            string APPID = "BAEF21E7DB295FBDBF0EBAF9A9EC9C55581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D7749635E59";
            string CER = "C7833C7AE258DB7174AADD371C6BCC7C659DEA0C1BE1425CA76D75D96007A7267AFE4CBF4CAA52FD1EFE57BEF5308F298EA16AAF1A0EC584B5F7DA7EDE31A4208F0C4F93323BA3A021EBAC0A10A1C8D7E6AC33C20D057FB9F46A17DB8A69C9DD581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963D050C47BED3ED850EB24DD23CBAEB147374BDA8B40E4214C581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D774963581A4E022D77496354E606ACCBE47772";



            try
            {
                trade = new EsTradeApi(CER, "esLogs", APPID);
                trade.OnRspOpen += OnRspOpen;
                trade.OnRspLogin += OnRspLogin;
                trade.OnRspClose += OnRspClose;
                trade.OnRspInitFinished += OnRspInitFinished;
                trade.OnRspOrderInsert += OnRspOrderInsert;
                trade.OnRtnOrderState += OnRtnOrderState;
                trade.OnRtnMatchState += OnRtnMatchState;
                trade.OnRtnMatchInfo += OnRtnMatchInfo;
                trade.OnRtnOrderInfo += OnRtnOrderInfo;
                trade.OnRtnOrderRemove += OnRtnOrderRemove;
                trade.OnRspOrderDeleteError += OnRspOrderDeleteError;



                trade.OnRtnExchangeState += OnRtnExchangeState;
                trade.OnQryCommodity += OnQryCommodity;
                trade.OnQryHold += OnQryHold;
                trade.OnQryMoney += OnQryMoney;
                trade.OnRspQryCurrency += OnRspQryCurrency;

                trade.OnRspQryOrder += OnRspQryOrder;
                trade.OnRspHistOrderQry += OnRspHistOrderQry;
                trade.OnRspMatchQry += OnRspMatchQry;
                trade.OnRspHistMatchQry += OnRspHistMatchQry;

                AddressField address = new AddressField();
                address.Ip = "122.224.221.238";
                address.Port = 57802;


                if (!trade.Open(address))
                {
                    Console.WriteLine("open fail");
                    return;
                }




            }
            catch (Exception ex)
            {

                Console.WriteLine("create err:" + ex.Message + "msg");
                return;
            }

        }
        public void stop()
        {
            if (trade == null)
                return;

            //trade.LogOut(requestId++);
            trade.Free();



        }

        public void Verificate(string ceriCode)
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }

            int ret = trade.SetVertificateCode(ceriCode, requestId);
            Console.WriteLine("验证结果:" + trade.GetErrcodeDesc(ret));
        }

        public void DeleteOrder(string orderId)
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }
            int ret = trade.OrderDelete(Convert.ToInt32(orderId), requestId);
            Console.WriteLine("撤单结果:" + trade.GetErrcodeDesc(ret));
        }

        public void Order(string contract, string volume, string price, string dir)
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }


            string[] contractArray = contract.Split(' ');
            if (contractArray.Length != 2)
            {
                Console.WriteLine("无效的合约！" + contract);
                return;

            }


            OrderInsertReqField orderInsertReqField = new OrderInsertReqField();
            orderInsertReqField.ClientNo = username;
            orderInsertReqField.CommodityNo = contractArray[0];
            orderInsertReqField.ContractNo = contractArray[1];
            if (string.IsNullOrWhiteSpace(price))
                orderInsertReqField.OrderType = (Byte)EnumOrderType.ORDER_TYPE_MARKET;
            else
            {
                orderInsertReqField.OrderType = (Byte)EnumOrderType.ORDER_TYPE_LIMIT;
                orderInsertReqField.OrderPrice = Convert.ToDouble(price);
            }

            if (dir.ToUpper() == "BUY")
                orderInsertReqField.Direct = (Byte)EnumDirectType.DIRECT_BUY;
            else
                orderInsertReqField.Direct = (Byte)EnumDirectType.DIRECT_SELL;


            orderInsertReqField.Offset = (Byte)EnumOffsetType.OFFSET_OPEN;
            orderInsertReqField.Hedge = (Byte)EnumHedgeType.HEDGE_T;

            orderInsertReqField.IsRiskOrder = (Byte)EnumIsRiskOrderType.RISK_ORDER_NO;
            orderInsertReqField.OrderMode = (Byte)EnumOrderModeType.ORDER_MODE_GFD;
            orderInsertReqField.OrderWay = (Byte)EnumOrderWayType.ORDER_WAY_PROXY_ETRADER;

            orderInsertReqField.OrderVol = Convert.ToInt32(volume);

            int ret = trade.OrderInsert(orderInsertReqField, requestId);
            if (ret != 0)
            {
                Console.WriteLine("报单失败");
                return;
            }
            Console.WriteLine("报单完成");
        }

        public void QryOrder()
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }
            OrderQryReqField req = new OrderQryReqField();
            trade.QryOrder(req, requestId);

            HisOrderQryReqField req1 = new HisOrderQryReqField();
            req1.BeginDate = "20180101";
            req1.EndDate = "20180425";
            trade.QryHistOrder(req1,requestId);

            
        }
        public void QryMatch()
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }

            MatchQryReqField req = new MatchQryReqField();
            trade.QryMatch(req,requestId);

            HisMatchQryReqField req1 = new HisMatchQryReqField();
            req1.BeginDate = "20180101";
            req1.EndDate = "20180425";
            trade.QryHistMatch(req1,requestId);
        }
        public void QryHold()
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }

            HoldQryReqField req = new HoldQryReqField();
            //req.ClientNo = username;
            //req.CommodityNo = "CBOT";
            int ret = trade.QryHold(req, requestId);
            
            Console.WriteLine("持仓查询结果:" + trade.GetErrcodeDesc(ret));
        }

        public void QryMoney()
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }
            MoneyQryReqField req = new MoneyQryReqField();
            //req.ClientNo = username;
            trade.QryMoney(req, requestId);
        }



        public void QryCommodity()
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }
            CommodityQryReqField req = new CommodityQryReqField();
            trade.QryCommodity(req, requestId);
        }

        public void QryCurrency()
        {
            if (trade == null || trade.IsOpen() == false)
            {
                Console.WriteLine("交易未连接");
                return;
            }
            CurrencyQryReqField req = new CurrencyQryReqField();
            trade.QryCurrency(req, requestId);
        }



        private void OnRspOpen()
        {
            Console.WriteLine("连接打开");



            LoginReqField loginReqField = new LoginReqField();
            loginReqField.IsCaLogin = (Byte)EnumIsCaLoginType.NOT_CA_LOGIN;
            loginReqField.Identity = (Byte)EnumEsLoginIdentityType.IDENTITY_CLIENT;
            loginReqField.IsForcePwd = (Byte)EnumIsForcePasswordType.NOT_FORCE_PWD;
            loginReqField.ClientNo = username;
            loginReqField.LoginPwd = pwd;


            int ret = trade.Login(loginReqField, requestId++);
            if (ret != 0)
            {
                Console.WriteLine("登陆失败");
                return;
            }
        }
        private void OnRspClose()
        {
            Console.WriteLine("连接关闭");
        }
        private void OnRspLogin(LoginRspField pLoginRspField, int errCode, int iReqID)
        {

            Console.WriteLine("登陆结果：" + trade.GetErrcodeDesc(errCode));
            if (errCode == 27)
            {
                Application.Current.Dispatcher.Invoke(()=>{
                    VerfiWin win = new VerfiWin(this);
                    win.ShowDialog();
                });
                
               
            }



        }

        private void OnRspInitFinished(int errCode)
        {
            
            Console.WriteLine("初始化结束,结果:" + trade.GetErrcodeDesc(errCode) );
        }

        private void OnRspOrderInsert(OrderInsertRspField pOrderInsertRspField, int errCode, int iReqID)
        {
            //注意此处orderId与回报中不一致
            if (errCode != 0)
                Console.WriteLine("插入报单失败" + trade.GetErrcodeDesc(errCode));
            else
                Console.WriteLine($"插入报单成功:{pOrderInsertRspField.InsertDateTime} {pOrderInsertRspField.OrderId} {((EnumOrderStateType)pOrderInsertRspField.OrderState).ToString()} {pOrderInsertRspField.ReqData.CommodityNo} {pOrderInsertRspField.ReqData.ContractNo} {pOrderInsertRspField.ReqData.Direct} {pOrderInsertRspField.ReqData.OrderVol} {pOrderInsertRspField.ReqData.OrderPrice}");
        }
        private void OnRtnOrderState(OrderStateNoticeField rsp)
        {
            Console.WriteLine($"委托状态: {rsp.UpdateDateTime} {rsp.ErrorCode}  {rsp.OrderId} {((EnumOrderStateType)rsp.OrderState).ToString()}");
        }
        private void OnRtnMatchState(MatchStateNoticeField rsp)
        {
            Console.WriteLine($"成交状态: {rsp.MatchDateTime}{rsp.OrderId}  {(EnumOrderStateType)rsp.MatchPrice}");
        }

        public void OnRtnMatchInfo(MatchInfoNoticeField rsp)
        {
            Console.WriteLine($"成交信息:{rsp.CommodityNo} {rsp.ContractNo}");
        }
        public void OnRtnOrderInfo(OrderInfoNoticeField rsp)
        {
            Console.WriteLine($"委托信息:");
        }

        private void OnRtnOrderRemove(OrderRemoveNoticeField rsp)
        {
            Console.WriteLine($"撤单回报: {rsp.OrderId}");
        }

        private void OnQryMoney(MoneyQryRspField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"资金：{rsp.CurrencyNo} 市值[{rsp.AccountMarketValue}] 可用[{rsp.TAvailable}] 入金[ {rsp.CashIn}]  出金[{rsp.CashOut}]");
        }


        private void OnQryHold(HoldQryRspField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"持仓：{rsp.CommodityNo} {rsp.ContractNo} {((EnumDirectType)rsp.Direct).ToString()} {rsp.TradeVol}  {rsp.YSettlePrice} {rsp.TNewPrice}");
        }

        int count = 0;
        private void OnQryCommodity(CommodityQryRspField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"商品查询结果{count++}:{rsp.ExchangeNo} {rsp.CommodityName} {rsp.CommodityNo} {rsp.RelateCommodityNo} {rsp.CurrencyNo}  {rsp.ProductDot} {rsp.UpperTick}/{rsp.LowerTick} {rsp.AddOneTime}");
            else
                count = 0;

        }

        private void OnRspQryCurrency(CurrencyQryRspField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"货币信息：{rsp.CurrencyGroup} {rsp.CurrencyName} {rsp.CurrencyNo} {rsp.IsPrimary} {rsp.ExchangeRate}");
        }

        private void OnRtnExchangeState(ExchangeStateModifyNoticeField rsp)
        {
            Console.WriteLine($"交易所状态变化: {rsp.ExchangeNo} {rsp.ExchangeState}");
        }

        private void OnRspHistMatchQry(HisMatchQryRspField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"成交历史查询：{rsp.Date} {rsp.CommodityNo} {rsp.ContractNo} {((EnumDirectType)rsp.Direct).ToString()} {rsp.MatchVol} {rsp.MatchDateTime}");
        }

        private void OnRspMatchQry(MatchInfoNoticeField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"成交查询：{rsp.CommodityNo} {rsp.ContractNo} {((EnumDirectType)rsp.Direct).ToString()} {rsp.StateData.OrderId} {rsp.StateData.MatchVol} {rsp.StateData.MatchDateTime}");
        }
        private void OnRspQryOrder(OrderInfoNoticeField rsp, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
                Console.WriteLine($"委托查询：{rsp.SystemNo} {rsp.OrderState} {rsp.ReqData.CommodityNo} {rsp.ReqData.ContractNo} {rsp.ReqData.Direct} {rsp.ReqData.OrderVol} {rsp.ReqData.OrderPrice} {rsp.InsertDateTime}");
        }
        private void OnRspHistOrderQry(HisOrderQryRspField rsp1, bool islast, int errCode, int iReqID)
        {
            if (islast == false)
            {
                OrderInfoNoticeField rsp = rsp1.Data;
                Console.WriteLine($"委托查询：{rsp.SystemNo} {rsp.OrderState} {rsp.ReqData.CommodityNo} {rsp.ReqData.ContractNo} {rsp.ReqData.Direct} {rsp.ReqData.OrderVol} {rsp.ReqData.OrderPrice} {rsp.InsertDateTime}");
            }
        }

        private void OnRspOrderDeleteError(int errCode, int iReqID)
        {
            Console.WriteLine("撤单失败："+trade.GetErrcodeDesc(errCode));
        }

    }
}
