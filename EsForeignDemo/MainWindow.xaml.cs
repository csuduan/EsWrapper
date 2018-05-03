using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace EsForeignDemo
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private EsQuotTest testQuot = new EsQuotTest();
        private EsTradeTest testTrade = new EsTradeTest();
        public MainWindow()
        {
            InitializeComponent();            
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

            testQuot.Start();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            testQuot.stop();
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            testTrade.Start();
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            //testTrade.Order();
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            testTrade.stop();
        }

        private void btnBuy_Click(object sender, RoutedEventArgs e)
        {
            testTrade.Order(tbContract.Text,tbVolume.Text,tbPrice.Text,"BUY");
        }

        private void btnSell_Click(object sender, RoutedEventArgs e)
        {
            testTrade.Order(tbContract.Text, tbVolume.Text, tbPrice.Text, "SELL");
        }

        private void btnDelete_Click(object sender, RoutedEventArgs e)
        {
            testTrade.DeleteOrder(tbOrderId.Text);

        }

        private void btnQryOrder_Click(object sender, RoutedEventArgs e)
        {
            testTrade.QryOrder();
            
        }

        private void btnQryTrade_Click(object sender, RoutedEventArgs e)
        {
            testTrade.QryMatch();
        }

        private void btnQryHold_Click(object sender, RoutedEventArgs e)
        {
            testTrade.QryHold();
        }


        private void btnQryMoney_Click(object sender, RoutedEventArgs e)
        {
            testTrade.QryMoney();
        }


        private void btnQryCommodity_Click(object sender, RoutedEventArgs e)
        {
            testTrade.QryCommodity();
        }

        private void btnQryCurrency_Click(object sender, RoutedEventArgs e)
        {
            testTrade.QryCurrency();

        }

    }
}
