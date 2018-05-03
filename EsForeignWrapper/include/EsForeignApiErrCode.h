#ifndef _ESUNNY_FOREIGN_API_ErrCODE_H_
#define _ESUNNY_FOREIGN_API_ErrCODE_H_

#include "EsForeignApiType.h"

namespace ESForeign
{
    ///////////////////////////////////////////////////////////////////////////
    //未知错误
    const TErrorCodeType Err_Unknown								= -1;
    //成功
    const TErrorCodeType Err_Succeed								= 0;

    ///////////////////////////////////////////////////////////////////////////
    //登录版本不允许
    const TErrorCodeType Err_Login_Version						= 1;
    //登录类型不允许
    const TErrorCodeType Err_Login_Type							= 2;
    //CA登录方式错误
    const TErrorCodeType Err_Login_Ca							= 3;
    //请修改密码登录
    const TErrorCodeType Err_Login_ForcePwd						= 4;
    //登录身份不允许
    const TErrorCodeType Err_Login_Identity						= 5;
    //登录名不存在
    const TErrorCodeType Err_Login_LoginNo						= 6;
    //登录密码错
    const TErrorCodeType Err_Login_Password						= 7;
    //禁止登录
    const TErrorCodeType Err_Login_Forbidden						= 8;
    //登陆数超限
    const TErrorCodeType Err_Login_Count							= 9;
    //第三方认证失败
    const TErrorCodeType Err_Otp									= 10;
    //未连接或者网络错误
    const TErrorCodeType Err_Network_Disconnected					= 11;
    //应答中不包含有效数据
    const TErrorCodeType Err_No_Valid_Data   					    = 12;
    //未登陆成功，没有操作权限
    const TErrorCodeType Err_Not_Login   					        = 13;
    //没有权限操作该用户
    const TErrorCodeType Err_No_Such_Client_Rights		        = 14;
    //没有本操作的权限
    const TErrorCodeType Err_No_Oper_Rights		                = 15;
    //初始化数据出错1
    const TErrorCodeType Err_Init_FAIL1		                = 16;
    //初始化数据出错2
    const TErrorCodeType Err_Init_FAIL2		                = 17;
    //初始化数据出错3
    const TErrorCodeType Err_Init_FAIL3		                = 18;
    //未成功初始化
    const TErrorCodeType Err_Init_Unsuccess	                = 19;
    //认证码已过期
    const TErrorCodeType Err_Cert_Expired	                = 20;
    //用户已经登录，请断开后再登陆
    const TErrorCodeType Err_User_Has_Logged                = 21;
    //发送频率过高，请稍后再试
    const TErrorCodeType Err_Req_Too_Much                   = 22;
    //数据查询不完整，请稍后再试
    const TErrorCodeType Err_Qry_Incomplete                 = 23;
	//应用程序ID与认证码不符
	const TErrorCodeType Err_Cert_APPID						= 24;
	//被强制退出。
	const TErrorCodeType Err_Force_Logout					= 25;
	//品种检查失败
	const TErrorCodeType Err_Err_Commodity					= 26;
	//需要二次认证
	const TErrorCodeType Err_Login_SECCERTIFI = 27;
	//已经登录成功，无法发送二次认证。
	const TErrorCodeType Err_Certificate_Logined = 28;
	// 二次认证失败
	const TErrorCodeType Err_Login_SecCertFailed = 29;
	//二次认证超时
	const TErrorCodeType Err_Login_SecCertTimeout = 30;

    ///////////////////////////////////////////////////////////////////////////
    //查询合约失败 无此品种
    const TErrorCodeType Err_Contract_Qry							= 101;
	//查询持仓没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_Hold_QryNoEnd							= 102;
	//查询计算参数没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_CountRent_QryNoEnd						= 103;
	//查询委托没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_Order_QryNoEnd							= 104;
	//查询成交没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_Match_QryNoEnd							= 105;
	//查询LME到期日没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_LmeContract_QryNoEnd					= 106;
	//查询历史委托没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_HisOrder_QryNoEnd						= 107;
	//查询历史成交没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_HisMatch_QryNoEnd						= 108;
	//查询历史持仓没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_HisHold_QryNoEnd						= 109;
	//查询历史资金没有返回结束，无法进行下一次查询
	const TErrorCodeType Err_HisMoney_QryNoEnd						= 110;
    ///////////////////////////////////////////////////////////////////////////
    //下单无此合约
    const TErrorCodeType Err_Order_Contract						= 201;
    //上手不存在
    const TErrorCodeType Err_Order_Upper							= 202;
    //此状态不能撤单
    const TErrorCodeType Err_Order_State							= 203;
    //合约禁止交易
    const TErrorCodeType Err_Contract_NoTrade						= 204;
    //合约禁止开仓
    const TErrorCodeType Err_Contract_NoOpen						= 205;
    //委托超出最大下单量
    const TErrorCodeType Err_MaxOrderVol							= 206;
    //持仓超出最大数量
    const TErrorCodeType Err_MaxHoldVol							= 207;
    //客户禁止交易
    const TErrorCodeType Err_Client_NoTrade						= 208;
    //客户禁止开仓
    const TErrorCodeType Err_Client_NoOpen						= 209;
    //下单资金不足
    const TErrorCodeType Err_Money_NotEnough						= 210;
    //LME未准备就绪
    const TErrorCodeType Err_LME_Check							= 211;
    //已删除报单不能转移
    const TErrorCodeType Err_CanNotMove_DeletedOrder				= 212;
    //强平单不能撤销
    const TErrorCodeType Err_CanNotDelete_RiskOrder				= 213;
    //客户号不存在
    const TErrorCodeType Err_Order_ClientNoExist					= 214;
    //订单号不正确
    const TErrorCodeType Err_OrderID_InCorrect                  = 215;
	//录入成交数量不合法
	const TErrorCodeType Error_MatchInput_Vol						= 216;
	//录入成交找不到委托
	const TErrorCodeType Error_Order_NoExist						= 217;
	//强平单不能修改
	const TErrorCodeType Error_CanNotModify_RiskOrder				= 218;
	//平仓方式错误
	const TErrorCodeType Error_CoverMode							= 219;

    ///////////////////////////////////////////////////////////////////////////
    //数据库操作错误
    const TErrorCodeType Err_Database								= 301;


    //-----服务器处理错误码
    //登录时服务器版本错误
    const TErrorCodeType	Err_Login_VersionErr				    = 401;		
    //登录时上手号错误                                            
    const TErrorCodeType	Err_Login_UpNOErr					    = 402;		
    //登录时上手客户号错误			                              
    const TErrorCodeType	Err_Login_UpUserErr					    = 403;			
    //交易数据包转换错误                                          
    const TErrorCodeType	Err_Trade_Trans						    = 404;		
    //交易数据包发送错误                                          
    const TErrorCodeType	Err_Trade_Send						    = 405;	
    //上手网关未就绪                                              
    const TErrorCodeType	Err_Trade_APINoReady				    = 406;		
    //上手网关撤单失败                                            
    const TErrorCodeType	Err_Trade_APIFail					    = 407;		
    //系统正在进行强制初始化                                      
    const TErrorCodeType	Err_Trade_Initing					    = 408;		
    //被上手拒绝                                                  
    const TErrorCodeType	Err_Trade_RejectByUpper				    = 409;	
    //市场或品种不许交易                                          
    const TErrorCodeType	Err_Trade_TransWNOFind				    = 410;		
    //报单类型不被支持                                            
    const TErrorCodeType	Err_Trade_InvalidOrderType			    = 411;		
    //价格错误                                                    
    const TErrorCodeType	Err_Trade_PriceErr					    = 412;		
    //报单类型错误                                                
    const TErrorCodeType	Err_Trade_UnknownOrderType			    = 413;		
    //合约错误                                                    
    const TErrorCodeType	Err_Trade_UnknownContract			    = 414;		
    //交易所未就绪                                                
    const TErrorCodeType	Err_Trade_ServerUnConnect			    = 415;		
    //报单不存在
    const TErrorCodeType	Err_Trade_UnknownOrder				    = 416;		
    //报单状态不允许                                              
    const TErrorCodeType	Err_Trade_InvalidState				    = 417;		
    //交易所不支持改单                                            
    const TErrorCodeType	Err_Trade_AmendDisabled				    = 418;		
    //数量不合法                                                  
    const TErrorCodeType	Err_Trade_InvalidVolume				    = 419;		
    //此类型不许修改                                              
    const TErrorCodeType	Err_Trade_InvalidAmendOrderType		    = 420;		
    //账户和用户不匹配                                            
    const TErrorCodeType	Err_Trade_UnknownAccount			    = 421;		
    //错误的方向，买卖不明                                        
    const TErrorCodeType	Err_Trade_ErrDirect					    = 422;		
    //不支持的商品类型                                            
    const TErrorCodeType	Err_Trade_InvalidCommodityType		    = 423;		
    //非法的报单模式                                              
    const TErrorCodeType	Err_Trade_InvalidMode				    = 424;
	//	港交所保单操作类型错误.
	const TErrorCodeType	Err_Trade_InvalidOperType				= 425;
	// 报单时有效期填写不正确
	const TErrorCodeType	Err_Trade_InvalidDate = 426;
	// 填写的小数数值非法
	const TErrorCodeType	Err_Trade_InvalidDouble = 427;


    //前置机返回的错误码
    //版本号不符合前置机要求
    const TErrorCodeType    Err_Frnt_Version                = 501;
    //身份错误, 前置不允许前置登录
    const TErrorCodeType    Err_Frnt_Identity                = 502;
    //发送给服务器失败
    const TErrorCodeType    Err_Frnt_SendServer                = 503;
    //不被支持的命令
    const TErrorCodeType    Err_Frnt_CMDNotAllow                = 504;
    //客户没有权限
    const TErrorCodeType  Err_Frnt_NORight                = 505;
    //系统号错误
    const TErrorCodeType    Err_Frnt_SysNOErr                = 506;
    //未登录无权限
    const TErrorCodeType  Err_Frnt_NOLogin                = 508;
    //前置登录客户数超限
    const TErrorCodeType  Err_Frnt_ClientFull                    = 509;
    //前置不允许该类型客户登陆
    const TErrorCodeType  Err_Frnt_IsNotClient                = 510;
    //前置没有准备好
    const TErrorCodeType  Err_Frnt_NoReady                = 511;
	//前置没所需数据
	const TErrorCodeType  Err_Frnt_NoData				  = 512;
	//客户应用没有授权
	const TErrorCodeType  Err_Frnt_APPNotAllow			  = 513;

    //认证错误信息
    //认证码错误
    const TErrorCodeType  Err_Cert_Incorrect              = 600;
    //日志文件初始化失败
    const TErrorCodeType  Err_Open_Log_Init_Failed        = 601;
    //日志文件打开失败
    const TErrorCodeType  Err_Open_Log_Failed             = 602;
	//用户无此权限
	const TErrorCodeType  Error_No_SuchRights			  = 603;
	//委托方式错误
	const TErrorCodeType  Error_No_SuchOrderWay			  = 604;
	//开平标志错误
	const TErrorCodeType  Error_No_SuchOffset			  = 605;
	//持仓不足平
	const TErrorCodeType Err_Trade_CoverNoHold = 606;

	///////////////////////////////////////////////////////////////////////////
	//动态令牌时间同步失败
	const TErrorCodeType Error_Otp_SyncTime				  = 700;


	//////////////////////////////////////////////////////////////////////////
	//出金入金操作金额错误
	const TErrorCodeType Error_CashOper_Value			= 800;
	//出金入金审核序列号错误
	const TErrorCodeType Error_CashCheck_SerialID		= 810;
	//出金入金审核无资金信息
	const TErrorCodeType Error_CashCheck_NoMoneyInfo	= 811;
	//出金入金审核资金不足
	const TErrorCodeType Error_CashCheck_MoneyNotEnough	= 812;
}

#endif
