using EsForeignWrapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;


namespace EsForeignDemo
{
    public class EsQuotTest
    {
        public EsQuotApi client = null;
        public void Start() {

            // 易盛模拟盘信息：
            // 1B4D4540668FDEE292CD734AEBD8389C3D07779C
            // 123.15.58.21：3331
            // "ESUNNY", "Es123456"

            // 新永安模拟盘信息
            // C1385 123123
            // 2F7971747F6D27664656516E463EE402046C59FD
            //122.224.221.238：57801
            //
            client = new EsQuotApi("2F7971747F6D27664656516E463EE402046C59FD", 1);
            client.OnRspLogin += OnRspLogin;
            client.OnRspHistoryQuot += OnRspHistoryQuot;
            client.OnChannelLost += OnChannelLost;
            client.OnRspMarketInfo += OnRspMarketInfo;
            client.OnRspTraceData += OnRspTraceData;
            client.OnStkQuot += OnStkQuot;




            //2.连接
            client.Connect("122.224.221.238", 57801);
            Thread.Sleep(1000);
            //3.登陆
            client.Login("C1385", "123456");
            

        }

        public void stop()
        {
            if (client == null)
                return;
            client.Free();
            client = null;

        }


        private  void OnStkQuot(StkData pData)
        {
            //throw new NotImplementedException();
            Console.WriteLine("收到行情数据，市场:{0} 合约:{1} 时间:"+pData.updatetime+" 价格:"+pData.New,pData.Market,pData.Code);
        }

        private  void OnRspTraceData(StkTraceData pTraceData)
        {
            Console.WriteLine("收到行明细:" + pTraceData.Code);
        }

        private  void OnRspMarketInfo(WMarketInfo pMarketInfo, int bLast)
        {
            Console.WriteLine("可订阅品种:" + pMarketInfo.Market);
        }

        private  void OnChannelLost(int err, string errtext)
        {
            Console.WriteLine("连接断开:" + errtext);
            //client.Dispose();
            //client = null;
        }

        private  void OnRspHistoryQuot(StkHisData pHisData)
        {
            Console.WriteLine("收到历史数据:"+pHisData.Code);
        }

        private  void OnRspLogin(int err, string errtext)
        {
            Console.WriteLine("登录结果:" + errtext);

            if (err == 0)
            {
                //请求历史行情
                client.RequestHistory("芝加哥商品交易所", "CBOT S 1805", 4);

                //请求明细数据
                int ret=client.RequestTrace("芝加哥商品交易所", "CBOT S 1807", "20180419");



                //订阅&批量订阅
                client.RequestQuot("芝加哥商品交易所", "CBOT S 1807", 1);
                client.AddReqStk("芝加哥商品交易所", "CBOT YK 1811", 1);
                client.AddReqStk("芝加哥商品交易所", "CBOT SM 1807", 1);
                client.SendReqStk();



            }
        }
    }
}
