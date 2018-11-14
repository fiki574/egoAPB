
struct IpDrv_StringToIpAddr_Parms
{
	struct FString                                     str;                                              		// 0x000000 (0x000C)              
	struct FIpAddr                                     Addr;                                             		// 0x00000C (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool AInternetLink::StringToIpAddr(struct FString str,struct FIpAddr* Addr)
{
	static UFieldFunc* pFnStringToIpAddr = NULL;
	if(!pFnStringToIpAddr)
		pFnStringToIpAddr = UObject::FindFunction("Function IpDrv.InternetLink.StringToIpAddr");

	IpDrv_StringToIpAddr_Parms StringToIpAddr_Parms;
	memcpy(&StringToIpAddr_Parms.str,&str,0xC);
	pFnStringToIpAddr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnStringToIpAddr,NULL,&StringToIpAddr_Parms,NULL);
	pFnStringToIpAddr->FunctionFlags |= 0x400;
	if(Addr)
		memcpy(Addr,&StringToIpAddr_Parms.Addr,0x8);
	return StringToIpAddr_Parms.ReturnValue;
}

struct IpDrv_GetLastError_Parms
{
	int                                                ReturnValue;                                      		// 0x000000 (0x0004)              
};

int AInternetLink::GetLastError()
{
	static UFieldFunc* pFnGetLastError = NULL;
	if(!pFnGetLastError)
		pFnGetLastError = UObject::FindFunction("Function IpDrv.InternetLink.GetLastError");

	IpDrv_GetLastError_Parms GetLastError_Parms;
	pFnGetLastError->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetLastError,NULL,&GetLastError_Parms,NULL);
	pFnGetLastError->FunctionFlags |= 0x400;
	return GetLastError_Parms.ReturnValue;
}

struct IpDrv_ResolveFailed_Parms
{
};

void AInternetLink::ResolveFailed()
{
	static UFieldFunc* pFnResolveFailed = NULL;
	if(!pFnResolveFailed)
		pFnResolveFailed = UObject::FindFunction("Function IpDrv.InternetLink.ResolveFailed");

	IpDrv_ResolveFailed_Parms ResolveFailed_Parms;
	ProcessEvent(pFnResolveFailed,NULL,&ResolveFailed_Parms,NULL);
}

struct IpDrv_IpAddrToString_Parms
{
	struct FIpAddr                                     Arg;                                              		// 0x000000 (0x0008)              
	struct FString                                     ReturnValue;                                      		// 0x000008 (0x000C)              
};

struct FString AInternetLink::IpAddrToString(struct FIpAddr Arg)
{
	static UFieldFunc* pFnIpAddrToString = NULL;
	if(!pFnIpAddrToString)
		pFnIpAddrToString = UObject::FindFunction("Function IpDrv.InternetLink.IpAddrToString");

	IpDrv_IpAddrToString_Parms IpAddrToString_Parms;
	memcpy(&IpAddrToString_Parms.Arg,&Arg,0x8);
	pFnIpAddrToString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIpAddrToString,NULL,&IpAddrToString_Parms,NULL);
	pFnIpAddrToString->FunctionFlags |= 0x400;
	return IpAddrToString_Parms.ReturnValue;
}

struct IpDrv_Resolved_Parms
{
	struct FIpAddr                                     Addr;                                             		// 0x000000 (0x0008)              
};

void AInternetLink::Resolved(struct FIpAddr Addr)
{
	static UFieldFunc* pFnResolved = NULL;
	if(!pFnResolved)
		pFnResolved = UObject::FindFunction("Function IpDrv.InternetLink.Resolved");

	IpDrv_Resolved_Parms Resolved_Parms;
	memcpy(&Resolved_Parms.Addr,&Addr,0x8);
	ProcessEvent(pFnResolved,NULL,&Resolved_Parms,NULL);
}

struct IpDrv_ParseURL_Parms
{
	struct FString                                     URL;                                              		// 0x000000 (0x000C)              
	struct FString                                     Addr;                                             		// 0x00000C (0x000C)              
	int                                                PortNum;                                          		// 0x000018 (0x0004)              
	struct FString                                     LevelName;                                        		// 0x00001C (0x000C)              
	struct FString                                     EntryName;                                        		// 0x000028 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000034 (0x0004) [0x00000001] 
};

bool AInternetLink::ParseURL(struct FString URL,struct FString* Addr,int* PortNum,struct FString* LevelName,struct FString* EntryName)
{
	static UFieldFunc* pFnParseURL = NULL;
	if(!pFnParseURL)
		pFnParseURL = UObject::FindFunction("Function IpDrv.InternetLink.ParseURL");

	IpDrv_ParseURL_Parms ParseURL_Parms;
	memcpy(&ParseURL_Parms.URL,&URL,0xC);
	pFnParseURL->FunctionFlags |= ~0x400;
	ProcessEvent(pFnParseURL,NULL,&ParseURL_Parms,NULL);
	pFnParseURL->FunctionFlags |= 0x400;
	if(Addr)
		memcpy(Addr,&ParseURL_Parms.Addr,0xC);
	if(PortNum)
		*PortNum = ParseURL_Parms.PortNum;
	if(LevelName)
		memcpy(LevelName,&ParseURL_Parms.LevelName,0xC);
	if(EntryName)
		memcpy(EntryName,&ParseURL_Parms.EntryName,0xC);
	return ParseURL_Parms.ReturnValue;
}

struct IpDrv_GetLocalIP_Parms
{
	struct FIpAddr                                     Arg;                                              		// 0x000000 (0x0008)              
};

void AInternetLink::GetLocalIP(struct FIpAddr* Arg)
{
	static UFieldFunc* pFnGetLocalIP = NULL;
	if(!pFnGetLocalIP)
		pFnGetLocalIP = UObject::FindFunction("Function IpDrv.InternetLink.GetLocalIP");

	IpDrv_GetLocalIP_Parms GetLocalIP_Parms;
	pFnGetLocalIP->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetLocalIP,NULL,&GetLocalIP_Parms,NULL);
	pFnGetLocalIP->FunctionFlags |= 0x400;
	if(Arg)
		memcpy(Arg,&GetLocalIP_Parms.Arg,0x8);
}

struct IpDrv_Resolve_Parms
{
	struct FString                                     Domain;                                           		// 0x000000 (0x000C)              
};

void AInternetLink::Resolve(struct FString Domain)
{
	static UFieldFunc* pFnResolve = NULL;
	if(!pFnResolve)
		pFnResolve = UObject::FindFunction("Function IpDrv.InternetLink.Resolve");

	IpDrv_Resolve_Parms Resolve_Parms;
	memcpy(&Resolve_Parms.Domain,&Domain,0xC);
	pFnResolve->FunctionFlags |= ~0x400;
	ProcessEvent(pFnResolve,NULL,&Resolve_Parms,NULL);
	pFnResolve->FunctionFlags |= 0x400;
}

struct IpDrv_IsDataPending_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool AInternetLink::IsDataPending()
{
	static UFieldFunc* pFnIsDataPending = NULL;
	if(!pFnIsDataPending)
		pFnIsDataPending = UObject::FindFunction("Function IpDrv.InternetLink.IsDataPending");

	IpDrv_IsDataPending_Parms IsDataPending_Parms;
	pFnIsDataPending->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsDataPending,NULL,&IsDataPending_Parms,NULL);
	pFnIsDataPending->FunctionFlags |= 0x400;
	return IsDataPending_Parms.ReturnValue;
}

struct IpDrv_Open_Parms
{
	struct FIpAddr                                     Addr;                                             		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool ATcpLink::Open(struct FIpAddr Addr)
{
	static UFieldFunc* pFnOpen = NULL;
	if(!pFnOpen)
		pFnOpen = UObject::FindFunction("Function IpDrv.TcpLink.Open");

	IpDrv_Open_Parms Open_Parms;
	memcpy(&Open_Parms.Addr,&Addr,0x8);
	pFnOpen->FunctionFlags |= ~0x400;
	ProcessEvent(pFnOpen,NULL,&Open_Parms,NULL);
	pFnOpen->FunctionFlags |= 0x400;
	return Open_Parms.ReturnValue;
}

struct IpDrv_SendBinary_Parms
{
	int                                                Count;                                            		// 0x000000 (0x0004)              
	unsigned char                                      B[0xFF];                                          		// 0x000004 (0x00FF)              
	unsigned char                                      _0x000103[0x1];                                   		// 0x000103 (0x0001) ALIGNEMENT
	int                                                ReturnValue;                                      		// 0x000104 (0x0004)              
};

int ATcpLink::SendBinary(int Count,unsigned char* B)
{
	static UFieldFunc* pFnSendBinary = NULL;
	if(!pFnSendBinary)
		pFnSendBinary = UObject::FindFunction("Function IpDrv.TcpLink.SendBinary");

	IpDrv_SendBinary_Parms SendBinary_Parms;
	SendBinary_Parms.Count = Count;
	memcpy(&SendBinary_Parms.B,&B,0xFF);
	pFnSendBinary->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSendBinary,NULL,&SendBinary_Parms,NULL);
	pFnSendBinary->FunctionFlags |= 0x400;
	return SendBinary_Parms.ReturnValue;
}

struct IpDrv_ReceivedText_Parms
{
	struct FString                                     Text;                                             		// 0x000000 (0x000C)              
};

void ATcpLink::ReceivedText(struct FString Text)
{
	static UFieldFunc* pFnReceivedText = NULL;
	if(!pFnReceivedText)
		pFnReceivedText = UObject::FindFunction("Function IpDrv.TcpLink.ReceivedText");

	IpDrv_ReceivedText_Parms ReceivedText_Parms;
	memcpy(&ReceivedText_Parms.Text,&Text,0xC);
	ProcessEvent(pFnReceivedText,NULL,&ReceivedText_Parms,NULL);
}

struct IpDrv_Opened_Parms
{
};

void ATcpLink::Opened()
{
	static UFieldFunc* pFnOpened = NULL;
	if(!pFnOpened)
		pFnOpened = UObject::FindFunction("Function IpDrv.TcpLink.Opened");

	IpDrv_Opened_Parms Opened_Parms;
	ProcessEvent(pFnOpened,NULL,&Opened_Parms,NULL);
}

struct IpDrv_Accepted_Parms
{
};

void ATcpLink::Accepted()
{
	static UFieldFunc* pFnAccepted = NULL;
	if(!pFnAccepted)
		pFnAccepted = UObject::FindFunction("Function IpDrv.TcpLink.Accepted");

	IpDrv_Accepted_Parms Accepted_Parms;
	ProcessEvent(pFnAccepted,NULL,&Accepted_Parms,NULL);
}

struct IpDrv_Close_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool ATcpLink::Close()
{
	static UFieldFunc* pFnClose = NULL;
	if(!pFnClose)
		pFnClose = UObject::FindFunction("Function IpDrv.TcpLink.Close");

	IpDrv_Close_Parms Close_Parms;
	pFnClose->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClose,NULL,&Close_Parms,NULL);
	pFnClose->FunctionFlags |= 0x400;
	return Close_Parms.ReturnValue;
}

struct IpDrv_SendText_Parms
{
	struct FString                                     str;                                              		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int ATcpLink::SendText(struct FString str)
{
	static UFieldFunc* pFnSendText = NULL;
	if(!pFnSendText)
		pFnSendText = UObject::FindFunction("Function IpDrv.TcpLink.SendText");

	IpDrv_SendText_Parms SendText_Parms;
	memcpy(&SendText_Parms.str,&str,0xC);
	pFnSendText->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSendText,NULL,&SendText_Parms,NULL);
	pFnSendText->FunctionFlags |= 0x400;
	return SendText_Parms.ReturnValue;
}

struct IpDrv_BindPort_Parms
{
	int                                                PortNum;                                          		// 0x000000 (0x0004)              
	unsigned long                                      bUseNextAvailable : 1;                            		// 0x000004 (0x0004) [0x00000001] 
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int ATcpLink::BindPort(int PortNum,bool bUseNextAvailable)
{
	static UFieldFunc* pFnBindPort = NULL;
	if(!pFnBindPort)
		pFnBindPort = UObject::FindFunction("Function IpDrv.TcpLink.BindPort");

	IpDrv_BindPort_Parms BindPort_Parms;
	BindPort_Parms.PortNum = PortNum;
	BindPort_Parms.bUseNextAvailable = bUseNextAvailable;
	pFnBindPort->FunctionFlags |= ~0x400;
	ProcessEvent(pFnBindPort,NULL,&BindPort_Parms,NULL);
	pFnBindPort->FunctionFlags |= 0x400;
	return BindPort_Parms.ReturnValue;
}

struct IpDrv_ReceivedLine_Parms
{
	struct FString                                     Line;                                             		// 0x000000 (0x000C)              
};

void ATcpLink::ReceivedLine(struct FString Line)
{
	static UFieldFunc* pFnReceivedLine = NULL;
	if(!pFnReceivedLine)
		pFnReceivedLine = UObject::FindFunction("Function IpDrv.TcpLink.ReceivedLine");

	IpDrv_ReceivedLine_Parms ReceivedLine_Parms;
	memcpy(&ReceivedLine_Parms.Line,&Line,0xC);
	ProcessEvent(pFnReceivedLine,NULL,&ReceivedLine_Parms,NULL);
}

struct IpDrv_Listen_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool ATcpLink::Listen()
{
	static UFieldFunc* pFnListen = NULL;
	if(!pFnListen)
		pFnListen = UObject::FindFunction("Function IpDrv.TcpLink.Listen");

	IpDrv_Listen_Parms Listen_Parms;
	pFnListen->FunctionFlags |= ~0x400;
	ProcessEvent(pFnListen,NULL,&Listen_Parms,NULL);
	pFnListen->FunctionFlags |= 0x400;
	return Listen_Parms.ReturnValue;
}

struct IpDrv_ReadBinary_Parms
{
	int                                                Count;                                            		// 0x000000 (0x0004)              
	unsigned char                                      B[0xFF];                                          		// 0x000004 (0x00FF)              
	unsigned char                                      _0x000103[0x1];                                   		// 0x000103 (0x0001) ALIGNEMENT
	int                                                ReturnValue;                                      		// 0x000104 (0x0004)              
};

int ATcpLink::ReadBinary(int Count,unsigned char* B)
{
	static UFieldFunc* pFnReadBinary = NULL;
	if(!pFnReadBinary)
		pFnReadBinary = UObject::FindFunction("Function IpDrv.TcpLink.ReadBinary");

	IpDrv_ReadBinary_Parms ReadBinary_Parms;
	ReadBinary_Parms.Count = Count;
	pFnReadBinary->FunctionFlags |= ~0x400;
	ProcessEvent(pFnReadBinary,NULL,&ReadBinary_Parms,NULL);
	pFnReadBinary->FunctionFlags |= 0x400;
	if(B)
		memcpy(B,&ReadBinary_Parms.B,0xFF);
	return ReadBinary_Parms.ReturnValue;
}

struct IpDrv_ReceivedBinary_Parms
{
	int                                                Count;                                            		// 0x000000 (0x0004)              
	unsigned char                                      B[0xFF];                                          		// 0x000004 (0x00FF)              
};

void ATcpLink::ReceivedBinary(int Count,unsigned char* B)
{
	static UFieldFunc* pFnReceivedBinary = NULL;
	if(!pFnReceivedBinary)
		pFnReceivedBinary = UObject::FindFunction("Function IpDrv.TcpLink.ReceivedBinary");

	IpDrv_ReceivedBinary_Parms ReceivedBinary_Parms;
	ReceivedBinary_Parms.Count = Count;
	memcpy(&ReceivedBinary_Parms.B,&B,0xFF);
	ProcessEvent(pFnReceivedBinary,NULL,&ReceivedBinary_Parms,NULL);
}

struct IpDrv_Closed_Parms
{
};

void ATcpLink::Closed()
{
	static UFieldFunc* pFnClosed = NULL;
	if(!pFnClosed)
		pFnClosed = UObject::FindFunction("Function IpDrv.TcpLink.Closed");

	IpDrv_Closed_Parms Closed_Parms;
	ProcessEvent(pFnClosed,NULL,&Closed_Parms,NULL);
}

struct IpDrv_ReadText_Parms
{
	struct FString                                     str;                                              		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int ATcpLink::ReadText(struct FString* str)
{
	static UFieldFunc* pFnReadText = NULL;
	if(!pFnReadText)
		pFnReadText = UObject::FindFunction("Function IpDrv.TcpLink.ReadText");

	IpDrv_ReadText_Parms ReadText_Parms;
	pFnReadText->FunctionFlags |= ~0x400;
	ProcessEvent(pFnReadText,NULL,&ReadText_Parms,NULL);
	pFnReadText->FunctionFlags |= 0x400;
	if(str)
		memcpy(str,&ReadText_Parms.str,0xC);
	return ReadText_Parms.ReturnValue;
}

struct IpDrv_IsConnected_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool ATcpLink::IsConnected()
{
	static UFieldFunc* pFnIsConnected = NULL;
	if(!pFnIsConnected)
		pFnIsConnected = UObject::FindFunction("Function IpDrv.TcpLink.IsConnected");

	IpDrv_IsConnected_Parms IsConnected_Parms;
	pFnIsConnected->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsConnected,NULL,&IsConnected_Parms,NULL);
	pFnIsConnected->FunctionFlags |= 0x400;
	return IsConnected_Parms.ReturnValue;
}

struct IpDrv_DestroyBeacon_Parms
{
};

void UMeshBeacon::DestroyBeacon()
{
	static UFieldFunc* pFnDestroyBeacon = NULL;
	if(!pFnDestroyBeacon)
		pFnDestroyBeacon = UObject::FindFunction("Function IpDrv.MeshBeacon.DestroyBeacon");

	IpDrv_DestroyBeacon_Parms DestroyBeacon_Parms;
	pFnDestroyBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyBeacon,NULL,&DestroyBeacon_Parms,NULL);
	pFnDestroyBeacon->FunctionFlags |= 0x400;
}

struct IpDrv_OnConnectionRequestResult_Parms
{
	unsigned char                                      ConnectionResult;                                 		// 0x000000 (0x0001)              
};

void UMeshBeaconClient::OnConnectionRequestResult(unsigned char ConnectionResult)
{
	static UFieldFunc* pFnOnConnectionRequestResult = NULL;
	if(!pFnOnConnectionRequestResult)
		pFnOnConnectionRequestResult = UObject::FindFunction("Function IpDrv.MeshBeaconClient.OnConnectionRequestResult");

	IpDrv_OnConnectionRequestResult_Parms OnConnectionRequestResult_Parms;
	OnConnectionRequestResult_Parms.ConnectionResult = ConnectionResult;
	ProcessEvent(pFnOnConnectionRequestResult,NULL,&OnConnectionRequestResult_Parms,NULL);
}

struct IpDrv_RequestConnection_Parms
{
	struct FOnlineGameSearchResult                     DesiredHost;                                      		// 0x000000 (0x0008)              
	struct FClientConnectionRequest                    ClientRequest;                                    		// 0x000008 (0x0024)              
	unsigned long                                      bRegisterSecureAddress : 1;                       		// 0x00002C (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000030 (0x0004) [0x00000001] 
};

bool UMeshBeaconClient::RequestConnection(struct FOnlineGameSearchResult* DesiredHost,struct FClientConnectionRequest* ClientRequest,bool bRegisterSecureAddress)
{
	static UFieldFunc* pFnRequestConnection = NULL;
	if(!pFnRequestConnection)
		pFnRequestConnection = UObject::FindFunction("Function IpDrv.MeshBeaconClient.RequestConnection");

	IpDrv_RequestConnection_Parms RequestConnection_Parms;
	RequestConnection_Parms.bRegisterSecureAddress = bRegisterSecureAddress;
	pFnRequestConnection->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRequestConnection,NULL,&RequestConnection_Parms,NULL);
	pFnRequestConnection->FunctionFlags |= 0x400;
	if(DesiredHost)
		memcpy(DesiredHost,&RequestConnection_Parms.DesiredHost,0x8);
	if(ClientRequest)
		memcpy(ClientRequest,&RequestConnection_Parms.ClientRequest,0x24);
	return RequestConnection_Parms.ReturnValue;
}

struct IpDrv_OnCreateNewSessionRequestReceived_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x000008 (0x0004)              
	TArray<struct FPlayerMember>                       Players;                                          		// 0x00000C (0x000C)              
};

void UMeshBeaconClient::OnCreateNewSessionRequestReceived(struct FName SessionName,class UClass* SearchClass,TArray<struct FPlayerMember>* Players)
{
	static UFieldFunc* pFnOnCreateNewSessionRequestReceived = NULL;
	if(!pFnOnCreateNewSessionRequestReceived)
		pFnOnCreateNewSessionRequestReceived = UObject::FindFunction("Function IpDrv.MeshBeaconClient.OnCreateNewSessionRequestReceived");

	IpDrv_OnCreateNewSessionRequestReceived_Parms OnCreateNewSessionRequestReceived_Parms;
	memcpy(&OnCreateNewSessionRequestReceived_Parms.SessionName,&SessionName,0x8);
	OnCreateNewSessionRequestReceived_Parms.SearchClass = SearchClass;
	ProcessEvent(pFnOnCreateNewSessionRequestReceived,NULL,&OnCreateNewSessionRequestReceived_Parms,NULL);
	if(Players)
		memcpy(Players,&OnCreateNewSessionRequestReceived_Parms.Players,0xC);
}

struct IpDrv_OnTravelRequestReceived_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x000008 (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x00000C (0x0050)              
};

void UMeshBeaconClient::OnTravelRequestReceived(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnOnTravelRequestReceived = NULL;
	if(!pFnOnTravelRequestReceived)
		pFnOnTravelRequestReceived = UObject::FindFunction("Function IpDrv.MeshBeaconClient.OnTravelRequestReceived");

	IpDrv_OnTravelRequestReceived_Parms OnTravelRequestReceived_Parms;
	memcpy(&OnTravelRequestReceived_Parms.SessionName,&SessionName,0x8);
	OnTravelRequestReceived_Parms.SearchClass = SearchClass;
	ProcessEvent(pFnOnTravelRequestReceived,NULL,&OnTravelRequestReceived_Parms,NULL);
	if(PlatformSpecificInfo)
		memcpy(PlatformSpecificInfo,&OnTravelRequestReceived_Parms.PlatformSpecificInfo,0x50);
}

struct IpDrv_SendHostNewGameSessionResponse_Parms
{
	unsigned long                                      bSuccess : 1;                                     		// 0x000000 (0x0004) [0x00000001] 
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x00000C (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x000010 (0x0050)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000060 (0x0004) [0x00000001] 
};

bool UMeshBeaconClient::SendHostNewGameSessionResponse(bool bSuccess,struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnSendHostNewGameSessionResponse = NULL;
	if(!pFnSendHostNewGameSessionResponse)
		pFnSendHostNewGameSessionResponse = UObject::FindFunction("Function IpDrv.MeshBeaconClient.SendHostNewGameSessionResponse");

	IpDrv_SendHostNewGameSessionResponse_Parms SendHostNewGameSessionResponse_Parms;
	SendHostNewGameSessionResponse_Parms.bSuccess = bSuccess;
	memcpy(&SendHostNewGameSessionResponse_Parms.SessionName,&SessionName,0x8);
	SendHostNewGameSessionResponse_Parms.SearchClass = SearchClass;
	pFnSendHostNewGameSessionResponse->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSendHostNewGameSessionResponse,NULL,&SendHostNewGameSessionResponse_Parms,NULL);
	pFnSendHostNewGameSessionResponse->FunctionFlags |= 0x400;
	if(PlatformSpecificInfo)
		memcpy(PlatformSpecificInfo,&SendHostNewGameSessionResponse_Parms.PlatformSpecificInfo,0x50);
	return SendHostNewGameSessionResponse_Parms.ReturnValue;
}

struct IpDrv_DebugRender_Parms
{
	class UCanvas*                                     Canvas;                                           		// 0x000000 (0x0004)              
	//int                                                HistoryIdx;                                       		// 0x000004 (0x0004)              
	//float                                              XL;                                               		// 0x000008 (0x0004)              
	//float                                              YL;                                               		// 0x00000C (0x0004)              
	//float                                              Offset;                                           		// 0x000010 (0x0004)              
};

void UMeshBeaconClient::DebugRender(class UCanvas* Canvas)
{
	static UFieldFunc* pFnDebugRender = NULL;
	if(!pFnDebugRender)
		pFnDebugRender = UObject::FindFunction("Function IpDrv.MeshBeaconClient.DebugRender");

	IpDrv_DebugRender_Parms DebugRender_Parms;
	DebugRender_Parms.Canvas = Canvas;
	ProcessEvent(pFnDebugRender,NULL,&DebugRender_Parms,NULL);
}

struct IpDrv_BeginBandwidthTest_Parms
{
	unsigned char                                      TestType;                                         		// 0x000000 (0x0001)              
	int                                                TestBufferSize;                                   		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UMeshBeaconClient::BeginBandwidthTest(unsigned char TestType,int TestBufferSize)
{
	static UFieldFunc* pFnBeginBandwidthTest = NULL;
	if(!pFnBeginBandwidthTest)
		pFnBeginBandwidthTest = UObject::FindFunction("Function IpDrv.MeshBeaconClient.BeginBandwidthTest");

	IpDrv_BeginBandwidthTest_Parms BeginBandwidthTest_Parms;
	BeginBandwidthTest_Parms.TestType = TestType;
	BeginBandwidthTest_Parms.TestBufferSize = TestBufferSize;
	pFnBeginBandwidthTest->FunctionFlags |= ~0x400;
	ProcessEvent(pFnBeginBandwidthTest,NULL,&BeginBandwidthTest_Parms,NULL);
	pFnBeginBandwidthTest->FunctionFlags |= 0x400;
	return BeginBandwidthTest_Parms.ReturnValue;
}

struct IpDrv_DestroyBeacon_Parms
{
};

void UMeshBeaconClient::DestroyBeacon()
{
	static UFieldFunc* pFnDestroyBeacon = NULL;
	if(!pFnDestroyBeacon)
		pFnDestroyBeacon = UObject::FindFunction("Function IpDrv.MeshBeaconClient.DestroyBeacon");

	IpDrv_DestroyBeacon_Parms DestroyBeacon_Parms;
	pFnDestroyBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyBeacon,NULL,&DestroyBeacon_Parms,NULL);
	pFnDestroyBeacon->FunctionFlags |= 0x400;
}

struct IpDrv_OnReceivedBandwidthTestResults_Parms
{
	unsigned char                                      TestType;                                         		// 0x000000 (0x0001)              
	unsigned char                                      TestResult;                                       		// 0x000001 (0x0001)              
	unsigned char                                      _0x000002[0x2];                                   		// 0x000002 (0x0002) ALIGNEMENT
	struct FConnectionBandwidthStats                   BandwidthStats;                                   		// 0x000004 (0x000C)              
};

void UMeshBeaconClient::OnReceivedBandwidthTestResults(unsigned char TestType,unsigned char TestResult,struct FConnectionBandwidthStats* BandwidthStats)
{
	static UFieldFunc* pFnOnReceivedBandwidthTestResults = NULL;
	if(!pFnOnReceivedBandwidthTestResults)
		pFnOnReceivedBandwidthTestResults = UObject::FindFunction("Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestResults");

	IpDrv_OnReceivedBandwidthTestResults_Parms OnReceivedBandwidthTestResults_Parms;
	OnReceivedBandwidthTestResults_Parms.TestType = TestType;
	OnReceivedBandwidthTestResults_Parms.TestResult = TestResult;
	ProcessEvent(pFnOnReceivedBandwidthTestResults,NULL,&OnReceivedBandwidthTestResults_Parms,NULL);
	if(BandwidthStats)
		memcpy(BandwidthStats,&OnReceivedBandwidthTestResults_Parms.BandwidthStats,0xC);
}

struct IpDrv_DumpInfo_Parms
{
	//int                                                HistoryIdx;                                       		// 0x000000 (0x0004)              
};

void UMeshBeaconClient::DumpInfo()
{
	static UFieldFunc* pFnDumpInfo = NULL;
	if(!pFnDumpInfo)
		pFnDumpInfo = UObject::FindFunction("Function IpDrv.MeshBeaconClient.DumpInfo");

	IpDrv_DumpInfo_Parms DumpInfo_Parms;
	ProcessEvent(pFnDumpInfo,NULL,&DumpInfo_Parms,NULL);
}

struct IpDrv_OnReceivedBandwidthTestRequest_Parms
{
	unsigned char                                      TestType;                                         		// 0x000000 (0x0001)              
};

void UMeshBeaconClient::OnReceivedBandwidthTestRequest(unsigned char TestType)
{
	static UFieldFunc* pFnOnReceivedBandwidthTestRequest = NULL;
	if(!pFnOnReceivedBandwidthTestRequest)
		pFnOnReceivedBandwidthTestRequest = UObject::FindFunction("Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestRequest");

	IpDrv_OnReceivedBandwidthTestRequest_Parms OnReceivedBandwidthTestRequest_Parms;
	OnReceivedBandwidthTestRequest_Parms.TestType = TestType;
	ProcessEvent(pFnOnReceivedBandwidthTestRequest,NULL,&OnReceivedBandwidthTestRequest_Parms,NULL);
}

struct IpDrv_OnReceivedClientConnectionRequest_Parms
{
	struct FClientMeshBeaconConnection                 NewClientConnection;                              		// 0x000000 (0x0058)              
};

void UMeshBeaconHost::OnReceivedClientConnectionRequest(struct FClientMeshBeaconConnection* NewClientConnection)
{
	static UFieldFunc* pFnOnReceivedClientConnectionRequest = NULL;
	if(!pFnOnReceivedClientConnectionRequest)
		pFnOnReceivedClientConnectionRequest = UObject::FindFunction("Function IpDrv.MeshBeaconHost.OnReceivedClientConnectionRequest");

	IpDrv_OnReceivedClientConnectionRequest_Parms OnReceivedClientConnectionRequest_Parms;
	ProcessEvent(pFnOnReceivedClientConnectionRequest,NULL,&OnReceivedClientConnectionRequest_Parms,NULL);
	if(NewClientConnection)
		memcpy(NewClientConnection,&OnReceivedClientConnectionRequest_Parms.NewClientConnection,0x58);
}

struct IpDrv_HasInProgressBandwidthTest_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UMeshBeaconHost::HasInProgressBandwidthTest()
{
	static UFieldFunc* pFnHasInProgressBandwidthTest = NULL;
	if(!pFnHasInProgressBandwidthTest)
		pFnHasInProgressBandwidthTest = UObject::FindFunction("Function IpDrv.MeshBeaconHost.HasInProgressBandwidthTest");

	IpDrv_HasInProgressBandwidthTest_Parms HasInProgressBandwidthTest_Parms;
	pFnHasInProgressBandwidthTest->FunctionFlags |= ~0x400;
	ProcessEvent(pFnHasInProgressBandwidthTest,NULL,&HasInProgressBandwidthTest_Parms,NULL);
	pFnHasInProgressBandwidthTest->FunctionFlags |= 0x400;
	return HasInProgressBandwidthTest_Parms.ReturnValue;
}

struct IpDrv_CancelPendingBandwidthTests_Parms
{
};

void UMeshBeaconHost::CancelPendingBandwidthTests()
{
	static UFieldFunc* pFnCancelPendingBandwidthTests = NULL;
	if(!pFnCancelPendingBandwidthTests)
		pFnCancelPendingBandwidthTests = UObject::FindFunction("Function IpDrv.MeshBeaconHost.CancelPendingBandwidthTests");

	IpDrv_CancelPendingBandwidthTests_Parms CancelPendingBandwidthTests_Parms;
	pFnCancelPendingBandwidthTests->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCancelPendingBandwidthTests,NULL,&CancelPendingBandwidthTests_Parms,NULL);
	pFnCancelPendingBandwidthTests->FunctionFlags |= 0x400;
}

struct IpDrv_DebugRender_Parms
{
	class UCanvas*                                     Canvas;                                           		// 0x000000 (0x0004)              
	struct FUniqueNetId                                CurOptimalHostId;                                 		// 0x000004 (0x0008)              
	//int                                                ClientIdx;                                        		// 0x00000C (0x0004)              
	//int                                                HistoryIdx;                                       		// 0x000010 (0x0004)              
	//struct FUniqueNetId                                NetId;                                            		// 0x000014 (0x0008)              
	//float                                              XL;                                               		// 0x00001C (0x0004)              
	//float                                              YL;                                               		// 0x000020 (0x0004)              
	//float                                              Offset;                                           		// 0x000024 (0x0004)              
};

void UMeshBeaconHost::DebugRender(class UCanvas* Canvas,struct FUniqueNetId CurOptimalHostId)
{
	static UFieldFunc* pFnDebugRender = NULL;
	if(!pFnDebugRender)
		pFnDebugRender = UObject::FindFunction("Function IpDrv.MeshBeaconHost.DebugRender");

	IpDrv_DebugRender_Parms DebugRender_Parms;
	DebugRender_Parms.Canvas = Canvas;
	memcpy(&DebugRender_Parms.CurOptimalHostId,&CurOptimalHostId,0x8);
	ProcessEvent(pFnDebugRender,NULL,&DebugRender_Parms,NULL);
}

struct IpDrv_RequestClientBandwidthTest_Parms
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	unsigned char                                      TestType;                                         		// 0x000008 (0x0001)              
	unsigned char                                      _0x000009[0x3];                                   		// 0x000009 (0x0003) ALIGNEMENT
	int                                                TestBufferSize;                                   		// 0x00000C (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UMeshBeaconHost::RequestClientBandwidthTest(struct FUniqueNetId PlayerNetId,unsigned char TestType,int TestBufferSize)
{
	static UFieldFunc* pFnRequestClientBandwidthTest = NULL;
	if(!pFnRequestClientBandwidthTest)
		pFnRequestClientBandwidthTest = UObject::FindFunction("Function IpDrv.MeshBeaconHost.RequestClientBandwidthTest");

	IpDrv_RequestClientBandwidthTest_Parms RequestClientBandwidthTest_Parms;
	memcpy(&RequestClientBandwidthTest_Parms.PlayerNetId,&PlayerNetId,0x8);
	RequestClientBandwidthTest_Parms.TestType = TestType;
	RequestClientBandwidthTest_Parms.TestBufferSize = TestBufferSize;
	pFnRequestClientBandwidthTest->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRequestClientBandwidthTest,NULL,&RequestClientBandwidthTest_Parms,NULL);
	pFnRequestClientBandwidthTest->FunctionFlags |= 0x400;
	return RequestClientBandwidthTest_Parms.ReturnValue;
}

struct IpDrv_DestroyBeacon_Parms
{
};

void UMeshBeaconHost::DestroyBeacon()
{
	static UFieldFunc* pFnDestroyBeacon = NULL;
	if(!pFnDestroyBeacon)
		pFnDestroyBeacon = UObject::FindFunction("Function IpDrv.MeshBeaconHost.DestroyBeacon");

	IpDrv_DestroyBeacon_Parms DestroyBeacon_Parms;
	pFnDestroyBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyBeacon,NULL,&DestroyBeacon_Parms,NULL);
	pFnDestroyBeacon->FunctionFlags |= 0x400;
}

struct IpDrv_RequestClientCreateNewSession_Parms
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	struct FName                                       SessionName;                                      		// 0x000008 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x000010 (0x0004)              
	TArray<struct FPlayerMember>                       Players;                                          		// 0x000014 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000020 (0x0004) [0x00000001] 
};

bool UMeshBeaconHost::RequestClientCreateNewSession(struct FUniqueNetId PlayerNetId,struct FName SessionName,class UClass* SearchClass,TArray<struct FPlayerMember>* Players)
{
	static UFieldFunc* pFnRequestClientCreateNewSession = NULL;
	if(!pFnRequestClientCreateNewSession)
		pFnRequestClientCreateNewSession = UObject::FindFunction("Function IpDrv.MeshBeaconHost.RequestClientCreateNewSession");

	IpDrv_RequestClientCreateNewSession_Parms RequestClientCreateNewSession_Parms;
	memcpy(&RequestClientCreateNewSession_Parms.PlayerNetId,&PlayerNetId,0x8);
	memcpy(&RequestClientCreateNewSession_Parms.SessionName,&SessionName,0x8);
	RequestClientCreateNewSession_Parms.SearchClass = SearchClass;
	pFnRequestClientCreateNewSession->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRequestClientCreateNewSession,NULL,&RequestClientCreateNewSession_Parms,NULL);
	pFnRequestClientCreateNewSession->FunctionFlags |= 0x400;
	if(Players)
		memcpy(Players,&RequestClientCreateNewSession_Parms.Players,0xC);
	return RequestClientCreateNewSession_Parms.ReturnValue;
}

struct IpDrv_DumpConnections_Parms
{
	//int                                                ClientIdx;                                        		// 0x000000 (0x0004)              
	//int                                                HistoryIdx;                                       		// 0x000004 (0x0004)              
	//struct FUniqueNetId                                NetId;                                            		// 0x000008 (0x0008)              
};

void UMeshBeaconHost::DumpConnections()
{
	static UFieldFunc* pFnDumpConnections = NULL;
	if(!pFnDumpConnections)
		pFnDumpConnections = UObject::FindFunction("Function IpDrv.MeshBeaconHost.DumpConnections");

	IpDrv_DumpConnections_Parms DumpConnections_Parms;
	ProcessEvent(pFnDumpConnections,NULL,&DumpConnections_Parms,NULL);
}

struct IpDrv_HasPendingBandwidthTest_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UMeshBeaconHost::HasPendingBandwidthTest()
{
	static UFieldFunc* pFnHasPendingBandwidthTest = NULL;
	if(!pFnHasPendingBandwidthTest)
		pFnHasPendingBandwidthTest = UObject::FindFunction("Function IpDrv.MeshBeaconHost.HasPendingBandwidthTest");

	IpDrv_HasPendingBandwidthTest_Parms HasPendingBandwidthTest_Parms;
	pFnHasPendingBandwidthTest->FunctionFlags |= ~0x400;
	ProcessEvent(pFnHasPendingBandwidthTest,NULL,&HasPendingBandwidthTest_Parms,NULL);
	pFnHasPendingBandwidthTest->FunctionFlags |= 0x400;
	return HasPendingBandwidthTest_Parms.ReturnValue;
}

struct IpDrv_GetConnectionIndexForPlayer_Parms
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UMeshBeaconHost::GetConnectionIndexForPlayer(struct FUniqueNetId PlayerNetId)
{
	static UFieldFunc* pFnGetConnectionIndexForPlayer = NULL;
	if(!pFnGetConnectionIndexForPlayer)
		pFnGetConnectionIndexForPlayer = UObject::FindFunction("Function IpDrv.MeshBeaconHost.GetConnectionIndexForPlayer");

	IpDrv_GetConnectionIndexForPlayer_Parms GetConnectionIndexForPlayer_Parms;
	memcpy(&GetConnectionIndexForPlayer_Parms.PlayerNetId,&PlayerNetId,0x8);
	pFnGetConnectionIndexForPlayer->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetConnectionIndexForPlayer,NULL,&GetConnectionIndexForPlayer_Parms,NULL);
	pFnGetConnectionIndexForPlayer->FunctionFlags |= 0x400;
	return GetConnectionIndexForPlayer_Parms.ReturnValue;
}

struct IpDrv_OnFinishedBandwidthTest_Parms
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	unsigned char                                      TestType;                                         		// 0x000008 (0x0001)              
	unsigned char                                      TestResult;                                       		// 0x000009 (0x0001)              
	unsigned char                                      _0x00000A[0x2];                                   		// 0x00000A (0x0002) ALIGNEMENT
	struct FConnectionBandwidthStats                   BandwidthStats;                                   		// 0x00000C (0x000C)              
};

void UMeshBeaconHost::OnFinishedBandwidthTest(struct FUniqueNetId PlayerNetId,unsigned char TestType,unsigned char TestResult,struct FConnectionBandwidthStats* BandwidthStats)
{
	static UFieldFunc* pFnOnFinishedBandwidthTest = NULL;
	if(!pFnOnFinishedBandwidthTest)
		pFnOnFinishedBandwidthTest = UObject::FindFunction("Function IpDrv.MeshBeaconHost.OnFinishedBandwidthTest");

	IpDrv_OnFinishedBandwidthTest_Parms OnFinishedBandwidthTest_Parms;
	memcpy(&OnFinishedBandwidthTest_Parms.PlayerNetId,&PlayerNetId,0x8);
	OnFinishedBandwidthTest_Parms.TestType = TestType;
	OnFinishedBandwidthTest_Parms.TestResult = TestResult;
	ProcessEvent(pFnOnFinishedBandwidthTest,NULL,&OnFinishedBandwidthTest_Parms,NULL);
	if(BandwidthStats)
		memcpy(BandwidthStats,&OnFinishedBandwidthTest_Parms.BandwidthStats,0xC);
}

struct IpDrv_SetPendingPlayerConnections_Parms
{
	TArray<struct FUniqueNetId>                        Players;                                          		// 0x000000 (0x000C)              
};

void UMeshBeaconHost::SetPendingPlayerConnections(TArray<struct FUniqueNetId>* Players)
{
	static UFieldFunc* pFnSetPendingPlayerConnections = NULL;
	if(!pFnSetPendingPlayerConnections)
		pFnSetPendingPlayerConnections = UObject::FindFunction("Function IpDrv.MeshBeaconHost.SetPendingPlayerConnections");

	IpDrv_SetPendingPlayerConnections_Parms SetPendingPlayerConnections_Parms;
	ProcessEvent(pFnSetPendingPlayerConnections,NULL,&SetPendingPlayerConnections_Parms,NULL);
	if(Players)
		memcpy(Players,&SetPendingPlayerConnections_Parms.Players,0xC);
}

struct IpDrv_OnStartedBandwidthTest_Parms
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	unsigned char                                      TestType;                                         		// 0x000008 (0x0001)              
};

void UMeshBeaconHost::OnStartedBandwidthTest(struct FUniqueNetId PlayerNetId,unsigned char TestType)
{
	static UFieldFunc* pFnOnStartedBandwidthTest = NULL;
	if(!pFnOnStartedBandwidthTest)
		pFnOnStartedBandwidthTest = UObject::FindFunction("Function IpDrv.MeshBeaconHost.OnStartedBandwidthTest");

	IpDrv_OnStartedBandwidthTest_Parms OnStartedBandwidthTest_Parms;
	memcpy(&OnStartedBandwidthTest_Parms.PlayerNetId,&PlayerNetId,0x8);
	OnStartedBandwidthTest_Parms.TestType = TestType;
	ProcessEvent(pFnOnStartedBandwidthTest,NULL,&OnStartedBandwidthTest_Parms,NULL);
}

struct IpDrv_InitHostBeacon_Parms
{
	struct FUniqueNetId                                InOwningPlayerId;                                 		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UMeshBeaconHost::InitHostBeacon(struct FUniqueNetId InOwningPlayerId)
{
	static UFieldFunc* pFnInitHostBeacon = NULL;
	if(!pFnInitHostBeacon)
		pFnInitHostBeacon = UObject::FindFunction("Function IpDrv.MeshBeaconHost.InitHostBeacon");

	IpDrv_InitHostBeacon_Parms InitHostBeacon_Parms;
	memcpy(&InitHostBeacon_Parms.InOwningPlayerId,&InOwningPlayerId,0x8);
	pFnInitHostBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInitHostBeacon,NULL,&InitHostBeacon_Parms,NULL);
	pFnInitHostBeacon->FunctionFlags |= 0x400;
	return InitHostBeacon_Parms.ReturnValue;
}

struct IpDrv_CancelInProgressBandwidthTests_Parms
{
};

void UMeshBeaconHost::CancelInProgressBandwidthTests()
{
	static UFieldFunc* pFnCancelInProgressBandwidthTests = NULL;
	if(!pFnCancelInProgressBandwidthTests)
		pFnCancelInProgressBandwidthTests = UObject::FindFunction("Function IpDrv.MeshBeaconHost.CancelInProgressBandwidthTests");

	IpDrv_CancelInProgressBandwidthTests_Parms CancelInProgressBandwidthTests_Parms;
	pFnCancelInProgressBandwidthTests->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCancelInProgressBandwidthTests,NULL,&CancelInProgressBandwidthTests_Parms,NULL);
	pFnCancelInProgressBandwidthTests->FunctionFlags |= 0x400;
}

struct IpDrv_OnAllPendingPlayersConnected_Parms
{
};

void UMeshBeaconHost::OnAllPendingPlayersConnected()
{
	static UFieldFunc* pFnOnAllPendingPlayersConnected = NULL;
	if(!pFnOnAllPendingPlayersConnected)
		pFnOnAllPendingPlayersConnected = UObject::FindFunction("Function IpDrv.MeshBeaconHost.OnAllPendingPlayersConnected");

	IpDrv_OnAllPendingPlayersConnected_Parms OnAllPendingPlayersConnected_Parms;
	ProcessEvent(pFnOnAllPendingPlayersConnected,NULL,&OnAllPendingPlayersConnected_Parms,NULL);
}

struct IpDrv_TellClientsToTravel_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x000008 (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x00000C (0x0050)              
};

void UMeshBeaconHost::TellClientsToTravel(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnTellClientsToTravel = NULL;
	if(!pFnTellClientsToTravel)
		pFnTellClientsToTravel = UObject::FindFunction("Function IpDrv.MeshBeaconHost.TellClientsToTravel");

	IpDrv_TellClientsToTravel_Parms TellClientsToTravel_Parms;
	memcpy(&TellClientsToTravel_Parms.SessionName,&SessionName,0x8);
	TellClientsToTravel_Parms.SearchClass = SearchClass;
	pFnTellClientsToTravel->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTellClientsToTravel,NULL,&TellClientsToTravel_Parms,NULL);
	pFnTellClientsToTravel->FunctionFlags |= 0x400;
	if(PlatformSpecificInfo)
		memcpy(PlatformSpecificInfo,&TellClientsToTravel_Parms.PlatformSpecificInfo,0x50);
}

struct IpDrv_OnReceivedClientCreateNewSessionResult_Parms
{
	unsigned long                                      bSucceeded : 1;                                   		// 0x000000 (0x0004) [0x00000001] 
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x00000C (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x000010 (0x0050)              
};

void UMeshBeaconHost::OnReceivedClientCreateNewSessionResult(bool bSucceeded,struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnOnReceivedClientCreateNewSessionResult = NULL;
	if(!pFnOnReceivedClientCreateNewSessionResult)
		pFnOnReceivedClientCreateNewSessionResult = UObject::FindFunction("Function IpDrv.MeshBeaconHost.OnReceivedClientCreateNewSessionResult");

	IpDrv_OnReceivedClientCreateNewSessionResult_Parms OnReceivedClientCreateNewSessionResult_Parms;
	OnReceivedClientCreateNewSessionResult_Parms.bSucceeded = bSucceeded;
	memcpy(&OnReceivedClientCreateNewSessionResult_Parms.SessionName,&SessionName,0x8);
	OnReceivedClientCreateNewSessionResult_Parms.SearchClass = SearchClass;
	ProcessEvent(pFnOnReceivedClientCreateNewSessionResult,NULL,&OnReceivedClientCreateNewSessionResult_Parms,NULL);
	if(PlatformSpecificInfo)
		memcpy(PlatformSpecificInfo,&OnReceivedClientCreateNewSessionResult_Parms.PlatformSpecificInfo,0x50);
}

struct IpDrv_AllPlayersConnected_Parms
{
	TArray<struct FUniqueNetId>                        Players;                                          		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UMeshBeaconHost::AllPlayersConnected(TArray<struct FUniqueNetId>* Players)
{
	static UFieldFunc* pFnAllPlayersConnected = NULL;
	if(!pFnAllPlayersConnected)
		pFnAllPlayersConnected = UObject::FindFunction("Function IpDrv.MeshBeaconHost.AllPlayersConnected");

	IpDrv_AllPlayersConnected_Parms AllPlayersConnected_Parms;
	pFnAllPlayersConnected->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAllPlayersConnected,NULL,&AllPlayersConnected_Parms,NULL);
	pFnAllPlayersConnected->FunctionFlags |= 0x400;
	if(Players)
		memcpy(Players,&AllPlayersConnected_Parms.Players,0xC);
	return AllPlayersConnected_Parms.ReturnValue;
}

struct IpDrv_AllowBandwidthTesting_Parms
{
	unsigned long                                      bEnabled : 1;                                     		// 0x000000 (0x0004) [0x00000001] 
};

void UMeshBeaconHost::AllowBandwidthTesting(bool bEnabled)
{
	static UFieldFunc* pFnAllowBandwidthTesting = NULL;
	if(!pFnAllowBandwidthTesting)
		pFnAllowBandwidthTesting = UObject::FindFunction("Function IpDrv.MeshBeaconHost.AllowBandwidthTesting");

	IpDrv_AllowBandwidthTesting_Parms AllowBandwidthTesting_Parms;
	AllowBandwidthTesting_Parms.bEnabled = bEnabled;
	ProcessEvent(pFnAllowBandwidthTesting,NULL,&AllowBandwidthTesting_Parms,NULL);
}

struct IpDrv_GetRegisteredPlayers_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	TArray<struct FUniqueNetId>                        OutRegisteredPlayers;                             		// 0x000008 (0x000C)              
	//int                                                Idx;                                              		// 0x000014 (0x0004)              
	//int                                                PlayerIdx;                                        		// 0x000018 (0x0004)              
};

void UOnlineSubsystemCommonImpl::GetRegisteredPlayers(struct FName SessionName,TArray<struct FUniqueNetId>* OutRegisteredPlayers)
{
	static UFieldFunc* pFnGetRegisteredPlayers = NULL;
	if(!pFnGetRegisteredPlayers)
		pFnGetRegisteredPlayers = UObject::FindFunction("Function IpDrv.OnlineSubsystemCommonImpl.GetRegisteredPlayers");

	IpDrv_GetRegisteredPlayers_Parms GetRegisteredPlayers_Parms;
	memcpy(&GetRegisteredPlayers_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnGetRegisteredPlayers,NULL,&GetRegisteredPlayers_Parms,NULL);
	if(OutRegisteredPlayers)
		memcpy(OutRegisteredPlayers,&GetRegisteredPlayers_Parms.OutRegisteredPlayers,0xC);
}

struct IpDrv_GetPlayerNicknameFromIndex_Parms
{
	int                                                UserIndex;                                        		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UOnlineSubsystemCommonImpl::GetPlayerNicknameFromIndex(int UserIndex)
{
	static UFieldFunc* pFnGetPlayerNicknameFromIndex = NULL;
	if(!pFnGetPlayerNicknameFromIndex)
		pFnGetPlayerNicknameFromIndex = UObject::FindFunction("Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerNicknameFromIndex");

	IpDrv_GetPlayerNicknameFromIndex_Parms GetPlayerNicknameFromIndex_Parms;
	GetPlayerNicknameFromIndex_Parms.UserIndex = UserIndex;
	ProcessEvent(pFnGetPlayerNicknameFromIndex,NULL,&GetPlayerNicknameFromIndex_Parms,NULL);
	return GetPlayerNicknameFromIndex_Parms.ReturnValue;
}

struct IpDrv_IsPlayerInSession_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                PlayerID;                                         		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UOnlineSubsystemCommonImpl::IsPlayerInSession(struct FName SessionName,struct FUniqueNetId PlayerID)
{
	static UFieldFunc* pFnIsPlayerInSession = NULL;
	if(!pFnIsPlayerInSession)
		pFnIsPlayerInSession = UObject::FindFunction("Function IpDrv.OnlineSubsystemCommonImpl.IsPlayerInSession");

	IpDrv_IsPlayerInSession_Parms IsPlayerInSession_Parms;
	memcpy(&IsPlayerInSession_Parms.SessionName,&SessionName,0x8);
	memcpy(&IsPlayerInSession_Parms.PlayerID,&PlayerID,0x8);
	pFnIsPlayerInSession->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsPlayerInSession,NULL,&IsPlayerInSession_Parms,NULL);
	pFnIsPlayerInSession->FunctionFlags |= 0x400;
	return IsPlayerInSession_Parms.ReturnValue;
}

struct IpDrv_AddRecalculateSkillRatingCompleteDelegate_Parms
{
	struct FScriptDelegate                             RecalculateSkillRatingCompleteDelegate;           		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddRecalculateSkillRatingCompleteDelegate(struct FScriptDelegate RecalculateSkillRatingCompleteDelegate)
{
	static UFieldFunc* pFnAddRecalculateSkillRatingCompleteDelegate = NULL;
	if(!pFnAddRecalculateSkillRatingCompleteDelegate)
		pFnAddRecalculateSkillRatingCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddRecalculateSkillRatingCompleteDelegate");

	IpDrv_AddRecalculateSkillRatingCompleteDelegate_Parms AddRecalculateSkillRatingCompleteDelegate_Parms;
	memcpy(&AddRecalculateSkillRatingCompleteDelegate_Parms.RecalculateSkillRatingCompleteDelegate,&RecalculateSkillRatingCompleteDelegate,0xC);
	ProcessEvent(pFnAddRecalculateSkillRatingCompleteDelegate,NULL,&AddRecalculateSkillRatingCompleteDelegate_Parms,NULL);
}

struct IpDrv_AddArbitrationRegistrationCompleteDelegate_Parms
{
	struct FScriptDelegate                             ArbitrationRegistrationCompleteDelegate;          		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddArbitrationRegistrationCompleteDelegate(struct FScriptDelegate ArbitrationRegistrationCompleteDelegate)
{
	static UFieldFunc* pFnAddArbitrationRegistrationCompleteDelegate = NULL;
	if(!pFnAddArbitrationRegistrationCompleteDelegate)
		pFnAddArbitrationRegistrationCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddArbitrationRegistrationCompleteDelegate");

	IpDrv_AddArbitrationRegistrationCompleteDelegate_Parms AddArbitrationRegistrationCompleteDelegate_Parms;
	memcpy(&AddArbitrationRegistrationCompleteDelegate_Parms.ArbitrationRegistrationCompleteDelegate,&ArbitrationRegistrationCompleteDelegate,0xC);
	ProcessEvent(pFnAddArbitrationRegistrationCompleteDelegate,NULL,&AddArbitrationRegistrationCompleteDelegate_Parms,NULL);
}

struct IpDrv_FreeSearchResults_Parms
{
	class UOnlineGameSearch*                           Search;                                           		// 0x000000 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000004 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::FreeSearchResults(class UOnlineGameSearch* Search)
{
	static UFieldFunc* pFnFreeSearchResults = NULL;
	if(!pFnFreeSearchResults)
		pFnFreeSearchResults = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.FreeSearchResults");

	IpDrv_FreeSearchResults_Parms FreeSearchResults_Parms;
	FreeSearchResults_Parms.Search = Search;
	pFnFreeSearchResults->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFreeSearchResults,NULL,&FreeSearchResults_Parms,NULL);
	pFnFreeSearchResults->FunctionFlags |= 0x400;
	return FreeSearchResults_Parms.ReturnValue;
}

struct IpDrv_AddGameInviteAcceptedDelegate_Parms
{
	unsigned char                                      LocalUserNum;                                     		// 0x000000 (0x0001)              
	struct FScriptDelegate                             GameInviteAcceptedDelegate;                       		// 0x000004 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddGameInviteAcceptedDelegate(unsigned char LocalUserNum,struct FScriptDelegate GameInviteAcceptedDelegate)
{
	static UFieldFunc* pFnAddGameInviteAcceptedDelegate = NULL;
	if(!pFnAddGameInviteAcceptedDelegate)
		pFnAddGameInviteAcceptedDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddGameInviteAcceptedDelegate");

	IpDrv_AddGameInviteAcceptedDelegate_Parms AddGameInviteAcceptedDelegate_Parms;
	AddGameInviteAcceptedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy(&AddGameInviteAcceptedDelegate_Parms.GameInviteAcceptedDelegate,&GameInviteAcceptedDelegate,0xC);
	ProcessEvent(pFnAddGameInviteAcceptedDelegate,NULL,&AddGameInviteAcceptedDelegate_Parms,NULL);
}

struct IpDrv_ClearStartOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             StartOnlineGameCompleteDelegate;                  		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearStartOnlineGameCompleteDelegate(struct FScriptDelegate StartOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearStartOnlineGameCompleteDelegate = NULL;
	if(!pFnClearStartOnlineGameCompleteDelegate)
		pFnClearStartOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearStartOnlineGameCompleteDelegate");

	IpDrv_ClearStartOnlineGameCompleteDelegate_Parms ClearStartOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearStartOnlineGameCompleteDelegate_Parms.StartOnlineGameCompleteDelegate,&StartOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearStartOnlineGameCompleteDelegate,NULL,&ClearStartOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_DestroyOnlineGame_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::DestroyOnlineGame(struct FName SessionName)
{
	static UFieldFunc* pFnDestroyOnlineGame = NULL;
	if(!pFnDestroyOnlineGame)
		pFnDestroyOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.DestroyOnlineGame");

	IpDrv_DestroyOnlineGame_Parms DestroyOnlineGame_Parms;
	memcpy(&DestroyOnlineGame_Parms.SessionName,&SessionName,0x8);
	pFnDestroyOnlineGame->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyOnlineGame,NULL,&DestroyOnlineGame_Parms,NULL);
	pFnDestroyOnlineGame->FunctionFlags |= 0x400;
	return DestroyOnlineGame_Parms.ReturnValue;
}

struct IpDrv_OnJoinOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnJoinOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnJoinOnlineGameComplete = NULL;
	if(!pFnOnJoinOnlineGameComplete)
		pFnOnJoinOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnJoinOnlineGameComplete");

	IpDrv_OnJoinOnlineGameComplete_Parms OnJoinOnlineGameComplete_Parms;
	memcpy(&OnJoinOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnJoinOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnJoinOnlineGameComplete,NULL,&OnJoinOnlineGameComplete_Parms,NULL);
}

struct IpDrv_OnRecalculateSkillRatingComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnRecalculateSkillRatingComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnRecalculateSkillRatingComplete = NULL;
	if(!pFnOnRecalculateSkillRatingComplete)
		pFnOnRecalculateSkillRatingComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnRecalculateSkillRatingComplete");

	IpDrv_OnRecalculateSkillRatingComplete_Parms OnRecalculateSkillRatingComplete_Parms;
	memcpy(&OnRecalculateSkillRatingComplete_Parms.SessionName,&SessionName,0x8);
	OnRecalculateSkillRatingComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnRecalculateSkillRatingComplete,NULL,&OnRecalculateSkillRatingComplete_Parms,NULL);
}

struct IpDrv_AddDestroyOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             DestroyOnlineGameCompleteDelegate;                		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddDestroyOnlineGameCompleteDelegate(struct FScriptDelegate DestroyOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddDestroyOnlineGameCompleteDelegate = NULL;
	if(!pFnAddDestroyOnlineGameCompleteDelegate)
		pFnAddDestroyOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddDestroyOnlineGameCompleteDelegate");

	IpDrv_AddDestroyOnlineGameCompleteDelegate_Parms AddDestroyOnlineGameCompleteDelegate_Parms;
	memcpy(&AddDestroyOnlineGameCompleteDelegate_Parms.DestroyOnlineGameCompleteDelegate,&DestroyOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddDestroyOnlineGameCompleteDelegate,NULL,&AddDestroyOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_OnMigrateOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnMigrateOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnMigrateOnlineGameComplete = NULL;
	if(!pFnOnMigrateOnlineGameComplete)
		pFnOnMigrateOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnMigrateOnlineGameComplete");

	IpDrv_OnMigrateOnlineGameComplete_Parms OnMigrateOnlineGameComplete_Parms;
	memcpy(&OnMigrateOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnMigrateOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnMigrateOnlineGameComplete,NULL,&OnMigrateOnlineGameComplete_Parms,NULL);
}

struct IpDrv_GetGameSearch_Parms
{
	class UOnlineGameSearch*                           ReturnValue;                                      		// 0x000000 (0x0004)              
};

class UOnlineGameSearch* UOnlineGameInterfaceImpl::GetGameSearch()
{
	static UFieldFunc* pFnGetGameSearch = NULL;
	if(!pFnGetGameSearch)
		pFnGetGameSearch = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.GetGameSearch");

	IpDrv_GetGameSearch_Parms GetGameSearch_Parms;
	ProcessEvent(pFnGetGameSearch,NULL,&GetGameSearch_Parms,NULL);
	return GetGameSearch_Parms.ReturnValue;
}

struct IpDrv_GetGameSettings_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UOnlineGameSettings*                         ReturnValue;                                      		// 0x000008 (0x0004)              
};

class UOnlineGameSettings* UOnlineGameInterfaceImpl::GetGameSettings(struct FName SessionName)
{
	static UFieldFunc* pFnGetGameSettings = NULL;
	if(!pFnGetGameSettings)
		pFnGetGameSettings = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.GetGameSettings");

	IpDrv_GetGameSettings_Parms GetGameSettings_Parms;
	memcpy(&GetGameSettings_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnGetGameSettings,NULL,&GetGameSettings_Parms,NULL);
	return GetGameSettings_Parms.ReturnValue;
}

struct IpDrv_AddStartOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             StartOnlineGameCompleteDelegate;                  		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddStartOnlineGameCompleteDelegate(struct FScriptDelegate StartOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddStartOnlineGameCompleteDelegate = NULL;
	if(!pFnAddStartOnlineGameCompleteDelegate)
		pFnAddStartOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddStartOnlineGameCompleteDelegate");

	IpDrv_AddStartOnlineGameCompleteDelegate_Parms AddStartOnlineGameCompleteDelegate_Parms;
	memcpy(&AddStartOnlineGameCompleteDelegate_Parms.StartOnlineGameCompleteDelegate,&StartOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddStartOnlineGameCompleteDelegate,NULL,&AddStartOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_GetArbitratedPlayers_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	TArray<struct FOnlineArbitrationRegistrant>        ReturnValue;                                      		// 0x000008 (0x000C)              
};

TArray<struct FOnlineArbitrationRegistrant> UOnlineGameInterfaceImpl::GetArbitratedPlayers(struct FName SessionName)
{
	static UFieldFunc* pFnGetArbitratedPlayers = NULL;
	if(!pFnGetArbitratedPlayers)
		pFnGetArbitratedPlayers = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.GetArbitratedPlayers");

	IpDrv_GetArbitratedPlayers_Parms GetArbitratedPlayers_Parms;
	memcpy(&GetArbitratedPlayers_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnGetArbitratedPlayers,NULL,&GetArbitratedPlayers_Parms,NULL);
	return GetArbitratedPlayers_Parms.ReturnValue;
}

struct IpDrv_QueryNonAdvertisedData_Parms
{
	int                                                StartAt;                                          		// 0x000000 (0x0004)              
	int                                                NumberToQuery;                                    		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::QueryNonAdvertisedData(int StartAt,int NumberToQuery)
{
	static UFieldFunc* pFnQueryNonAdvertisedData = NULL;
	if(!pFnQueryNonAdvertisedData)
		pFnQueryNonAdvertisedData = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.QueryNonAdvertisedData");

	IpDrv_QueryNonAdvertisedData_Parms QueryNonAdvertisedData_Parms;
	QueryNonAdvertisedData_Parms.StartAt = StartAt;
	QueryNonAdvertisedData_Parms.NumberToQuery = NumberToQuery;
	ProcessEvent(pFnQueryNonAdvertisedData,NULL,&QueryNonAdvertisedData_Parms,NULL);
	return QueryNonAdvertisedData_Parms.ReturnValue;
}

struct IpDrv_OnQosStatusChanged_Parms
{
	int                                                NumComplete;                                      		// 0x000000 (0x0004)              
	int                                                NumTotal;                                         		// 0x000004 (0x0004)              
};

void UOnlineGameInterfaceImpl::OnQosStatusChanged(int NumComplete,int NumTotal)
{
	static UFieldFunc* pFnOnQosStatusChanged = NULL;
	if(!pFnOnQosStatusChanged)
		pFnOnQosStatusChanged = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnQosStatusChanged");

	IpDrv_OnQosStatusChanged_Parms OnQosStatusChanged_Parms;
	OnQosStatusChanged_Parms.NumComplete = NumComplete;
	OnQosStatusChanged_Parms.NumTotal = NumTotal;
	ProcessEvent(pFnOnQosStatusChanged,NULL,&OnQosStatusChanged_Parms,NULL);
}

struct IpDrv_AddRegisterPlayerCompleteDelegate_Parms
{
	struct FScriptDelegate                             RegisterPlayerCompleteDelegate;                   		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddRegisterPlayerCompleteDelegate(struct FScriptDelegate RegisterPlayerCompleteDelegate)
{
	static UFieldFunc* pFnAddRegisterPlayerCompleteDelegate = NULL;
	if(!pFnAddRegisterPlayerCompleteDelegate)
		pFnAddRegisterPlayerCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddRegisterPlayerCompleteDelegate");

	IpDrv_AddRegisterPlayerCompleteDelegate_Parms AddRegisterPlayerCompleteDelegate_Parms;
	memcpy(&AddRegisterPlayerCompleteDelegate_Parms.RegisterPlayerCompleteDelegate,&RegisterPlayerCompleteDelegate,0xC);
	ProcessEvent(pFnAddRegisterPlayerCompleteDelegate,NULL,&AddRegisterPlayerCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearFindOnlineGamesCompleteDelegate_Parms
{
	struct FScriptDelegate                             FindOnlineGamesCompleteDelegate;                  		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearFindOnlineGamesCompleteDelegate(struct FScriptDelegate FindOnlineGamesCompleteDelegate)
{
	static UFieldFunc* pFnClearFindOnlineGamesCompleteDelegate = NULL;
	if(!pFnClearFindOnlineGamesCompleteDelegate)
		pFnClearFindOnlineGamesCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearFindOnlineGamesCompleteDelegate");

	IpDrv_ClearFindOnlineGamesCompleteDelegate_Parms ClearFindOnlineGamesCompleteDelegate_Parms;
	memcpy(&ClearFindOnlineGamesCompleteDelegate_Parms.FindOnlineGamesCompleteDelegate,&FindOnlineGamesCompleteDelegate,0xC);
	ProcessEvent(pFnClearFindOnlineGamesCompleteDelegate,NULL,&ClearFindOnlineGamesCompleteDelegate_Parms,NULL);
}

struct IpDrv_AddQosStatusChangedDelegate_Parms
{
	struct FScriptDelegate                             QosStatusChangedDelegate;                         		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddQosStatusChangedDelegate(struct FScriptDelegate QosStatusChangedDelegate)
{
	static UFieldFunc* pFnAddQosStatusChangedDelegate = NULL;
	if(!pFnAddQosStatusChangedDelegate)
		pFnAddQosStatusChangedDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddQosStatusChangedDelegate");

	IpDrv_AddQosStatusChangedDelegate_Parms AddQosStatusChangedDelegate_Parms;
	memcpy(&AddQosStatusChangedDelegate_Parms.QosStatusChangedDelegate,&QosStatusChangedDelegate,0xC);
	ProcessEvent(pFnAddQosStatusChangedDelegate,NULL,&AddQosStatusChangedDelegate_Parms,NULL);
}

struct IpDrv_UnregisterPlayers_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	TArray<struct FUniqueNetId>                        Players;                                          		// 0x000008 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::UnregisterPlayers(struct FName SessionName,TArray<struct FUniqueNetId>* Players)
{
	static UFieldFunc* pFnUnregisterPlayers = NULL;
	if(!pFnUnregisterPlayers)
		pFnUnregisterPlayers = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.UnregisterPlayers");

	IpDrv_UnregisterPlayers_Parms UnregisterPlayers_Parms;
	memcpy(&UnregisterPlayers_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnUnregisterPlayers,NULL,&UnregisterPlayers_Parms,NULL);
	if(Players)
		memcpy(Players,&UnregisterPlayers_Parms.Players,0xC);
	return UnregisterPlayers_Parms.ReturnValue;
}

struct IpDrv_JoinMigratedOnlineGame_Parms
{
	unsigned char                                      PlayerNum;                                        		// 0x000000 (0x0001)              
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	struct FOnlineGameSearchResult                     DesiredGame;                                      		// 0x00000C (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::JoinMigratedOnlineGame(unsigned char PlayerNum,struct FName SessionName,struct FOnlineGameSearchResult* DesiredGame)
{
	static UFieldFunc* pFnJoinMigratedOnlineGame = NULL;
	if(!pFnJoinMigratedOnlineGame)
		pFnJoinMigratedOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.JoinMigratedOnlineGame");

	IpDrv_JoinMigratedOnlineGame_Parms JoinMigratedOnlineGame_Parms;
	JoinMigratedOnlineGame_Parms.PlayerNum = PlayerNum;
	memcpy(&JoinMigratedOnlineGame_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnJoinMigratedOnlineGame,NULL,&JoinMigratedOnlineGame_Parms,NULL);
	if(DesiredGame)
		memcpy(DesiredGame,&JoinMigratedOnlineGame_Parms.DesiredGame,0x8);
	return JoinMigratedOnlineGame_Parms.ReturnValue;
}

struct IpDrv_RegisterPlayers_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	TArray<struct FUniqueNetId>                        Players;                                          		// 0x000008 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::RegisterPlayers(struct FName SessionName,TArray<struct FUniqueNetId>* Players)
{
	static UFieldFunc* pFnRegisterPlayers = NULL;
	if(!pFnRegisterPlayers)
		pFnRegisterPlayers = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.RegisterPlayers");

	IpDrv_RegisterPlayers_Parms RegisterPlayers_Parms;
	memcpy(&RegisterPlayers_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnRegisterPlayers,NULL,&RegisterPlayers_Parms,NULL);
	if(Players)
		memcpy(Players,&RegisterPlayers_Parms.Players,0xC);
	return RegisterPlayers_Parms.ReturnValue;
}

struct IpDrv_OnCancelFindOnlineGamesComplete_Parms
{
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000000 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnCancelFindOnlineGamesComplete(bool bWasSuccessful)
{
	static UFieldFunc* pFnOnCancelFindOnlineGamesComplete = NULL;
	if(!pFnOnCancelFindOnlineGamesComplete)
		pFnOnCancelFindOnlineGamesComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnCancelFindOnlineGamesComplete");

	IpDrv_OnCancelFindOnlineGamesComplete_Parms OnCancelFindOnlineGamesComplete_Parms;
	OnCancelFindOnlineGamesComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnCancelFindOnlineGamesComplete,NULL,&OnCancelFindOnlineGamesComplete_Parms,NULL);
}

struct IpDrv_AddJoinMigratedOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             JoinMigratedOnlineGameCompleteDelegate;           		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddJoinMigratedOnlineGameCompleteDelegate(struct FScriptDelegate JoinMigratedOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddJoinMigratedOnlineGameCompleteDelegate = NULL;
	if(!pFnAddJoinMigratedOnlineGameCompleteDelegate)
		pFnAddJoinMigratedOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddJoinMigratedOnlineGameCompleteDelegate");

	IpDrv_AddJoinMigratedOnlineGameCompleteDelegate_Parms AddJoinMigratedOnlineGameCompleteDelegate_Parms;
	memcpy(&AddJoinMigratedOnlineGameCompleteDelegate_Parms.JoinMigratedOnlineGameCompleteDelegate,&JoinMigratedOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddJoinMigratedOnlineGameCompleteDelegate,NULL,&AddJoinMigratedOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_MigrateOnlineGame_Parms
{
	unsigned char                                      HostingPlayerNum;                                 		// 0x000000 (0x0001)              
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::MigrateOnlineGame(unsigned char HostingPlayerNum,struct FName SessionName)
{
	static UFieldFunc* pFnMigrateOnlineGame = NULL;
	if(!pFnMigrateOnlineGame)
		pFnMigrateOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.MigrateOnlineGame");

	IpDrv_MigrateOnlineGame_Parms MigrateOnlineGame_Parms;
	MigrateOnlineGame_Parms.HostingPlayerNum = HostingPlayerNum;
	memcpy(&MigrateOnlineGame_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnMigrateOnlineGame,NULL,&MigrateOnlineGame_Parms,NULL);
	return MigrateOnlineGame_Parms.ReturnValue;
}

struct IpDrv_ClearQosStatusChangedDelegate_Parms
{
	struct FScriptDelegate                             QosStatusChangedDelegate;                         		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearQosStatusChangedDelegate(struct FScriptDelegate QosStatusChangedDelegate)
{
	static UFieldFunc* pFnClearQosStatusChangedDelegate = NULL;
	if(!pFnClearQosStatusChangedDelegate)
		pFnClearQosStatusChangedDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearQosStatusChangedDelegate");

	IpDrv_ClearQosStatusChangedDelegate_Parms ClearQosStatusChangedDelegate_Parms;
	memcpy(&ClearQosStatusChangedDelegate_Parms.QosStatusChangedDelegate,&QosStatusChangedDelegate,0xC);
	ProcessEvent(pFnClearQosStatusChangedDelegate,NULL,&ClearQosStatusChangedDelegate_Parms,NULL);
}

struct IpDrv_GetResolvedConnectString_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	struct FString                                     ConnectInfo;                                      		// 0x000008 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::GetResolvedConnectString(struct FName SessionName,struct FString* ConnectInfo)
{
	static UFieldFunc* pFnGetResolvedConnectString = NULL;
	if(!pFnGetResolvedConnectString)
		pFnGetResolvedConnectString = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.GetResolvedConnectString");

	IpDrv_GetResolvedConnectString_Parms GetResolvedConnectString_Parms;
	memcpy(&GetResolvedConnectString_Parms.SessionName,&SessionName,0x8);
	pFnGetResolvedConnectString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetResolvedConnectString,NULL,&GetResolvedConnectString_Parms,NULL);
	pFnGetResolvedConnectString->FunctionFlags |= 0x400;
	if(ConnectInfo)
		memcpy(ConnectInfo,&GetResolvedConnectString_Parms.ConnectInfo,0xC);
	return GetResolvedConnectString_Parms.ReturnValue;
}

struct IpDrv_AddFindOnlineGamesCompleteDelegate_Parms
{
	struct FScriptDelegate                             FindOnlineGamesCompleteDelegate;                  		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddFindOnlineGamesCompleteDelegate(struct FScriptDelegate FindOnlineGamesCompleteDelegate)
{
	static UFieldFunc* pFnAddFindOnlineGamesCompleteDelegate = NULL;
	if(!pFnAddFindOnlineGamesCompleteDelegate)
		pFnAddFindOnlineGamesCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddFindOnlineGamesCompleteDelegate");

	IpDrv_AddFindOnlineGamesCompleteDelegate_Parms AddFindOnlineGamesCompleteDelegate_Parms;
	memcpy(&AddFindOnlineGamesCompleteDelegate_Parms.FindOnlineGamesCompleteDelegate,&FindOnlineGamesCompleteDelegate,0xC);
	ProcessEvent(pFnAddFindOnlineGamesCompleteDelegate,NULL,&AddFindOnlineGamesCompleteDelegate_Parms,NULL);
}

struct IpDrv_UnregisterPlayer_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                PlayerID;                                         		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::UnregisterPlayer(struct FName SessionName,struct FUniqueNetId PlayerID)
{
	static UFieldFunc* pFnUnregisterPlayer = NULL;
	if(!pFnUnregisterPlayer)
		pFnUnregisterPlayer = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.UnregisterPlayer");

	IpDrv_UnregisterPlayer_Parms UnregisterPlayer_Parms;
	memcpy(&UnregisterPlayer_Parms.SessionName,&SessionName,0x8);
	memcpy(&UnregisterPlayer_Parms.PlayerID,&PlayerID,0x8);
	ProcessEvent(pFnUnregisterPlayer,NULL,&UnregisterPlayer_Parms,NULL);
	return UnregisterPlayer_Parms.ReturnValue;
}

struct IpDrv_UpdateOnlineGame_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UOnlineGameSettings*                         UpdatedGameSettings;                              		// 0x000008 (0x0004)              
	unsigned long                                      bShouldRefreshOnlineData : 1;                     		// 0x00000C (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::UpdateOnlineGame(struct FName SessionName,class UOnlineGameSettings* UpdatedGameSettings,bool bShouldRefreshOnlineData)
{
	static UFieldFunc* pFnUpdateOnlineGame = NULL;
	if(!pFnUpdateOnlineGame)
		pFnUpdateOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.UpdateOnlineGame");

	IpDrv_UpdateOnlineGame_Parms UpdateOnlineGame_Parms;
	memcpy(&UpdateOnlineGame_Parms.SessionName,&SessionName,0x8);
	UpdateOnlineGame_Parms.UpdatedGameSettings = UpdatedGameSettings;
	UpdateOnlineGame_Parms.bShouldRefreshOnlineData = bShouldRefreshOnlineData;
	ProcessEvent(pFnUpdateOnlineGame,NULL,&UpdateOnlineGame_Parms,NULL);
	return UpdateOnlineGame_Parms.ReturnValue;
}

struct IpDrv_ReadPlatformSpecificSessionInfo_Parms
{
	struct FOnlineGameSearchResult                     DesiredGame;                                      		// 0x000000 (0x0008)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x000008 (0x0050)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000058 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::ReadPlatformSpecificSessionInfo(struct FOnlineGameSearchResult* DesiredGame,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnReadPlatformSpecificSessionInfo = NULL;
	if(!pFnReadPlatformSpecificSessionInfo)
		pFnReadPlatformSpecificSessionInfo = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfo");

	IpDrv_ReadPlatformSpecificSessionInfo_Parms ReadPlatformSpecificSessionInfo_Parms;
	pFnReadPlatformSpecificSessionInfo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnReadPlatformSpecificSessionInfo,NULL,&ReadPlatformSpecificSessionInfo_Parms,NULL);
	pFnReadPlatformSpecificSessionInfo->FunctionFlags |= 0x400;
	if(DesiredGame)
		memcpy(DesiredGame,&ReadPlatformSpecificSessionInfo_Parms.DesiredGame,0x8);
	if(PlatformSpecificInfo)
		memcpy(PlatformSpecificInfo,&ReadPlatformSpecificSessionInfo_Parms.PlatformSpecificInfo,0x50);
	return ReadPlatformSpecificSessionInfo_Parms.ReturnValue;
}

struct IpDrv_StartOnlineGame_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::StartOnlineGame(struct FName SessionName)
{
	static UFieldFunc* pFnStartOnlineGame = NULL;
	if(!pFnStartOnlineGame)
		pFnStartOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.StartOnlineGame");

	IpDrv_StartOnlineGame_Parms StartOnlineGame_Parms;
	memcpy(&StartOnlineGame_Parms.SessionName,&SessionName,0x8);
	pFnStartOnlineGame->FunctionFlags |= ~0x400;
	ProcessEvent(pFnStartOnlineGame,NULL,&StartOnlineGame_Parms,NULL);
	pFnStartOnlineGame->FunctionFlags |= 0x400;
	return StartOnlineGame_Parms.ReturnValue;
}

struct IpDrv_RegisterPlayer_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                PlayerID;                                         		// 0x000008 (0x0008)              
	unsigned long                                      bWasInvited : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::RegisterPlayer(struct FName SessionName,struct FUniqueNetId PlayerID,bool bWasInvited)
{
	static UFieldFunc* pFnRegisterPlayer = NULL;
	if(!pFnRegisterPlayer)
		pFnRegisterPlayer = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.RegisterPlayer");

	IpDrv_RegisterPlayer_Parms RegisterPlayer_Parms;
	memcpy(&RegisterPlayer_Parms.SessionName,&SessionName,0x8);
	memcpy(&RegisterPlayer_Parms.PlayerID,&PlayerID,0x8);
	RegisterPlayer_Parms.bWasInvited = bWasInvited;
	ProcessEvent(pFnRegisterPlayer,NULL,&RegisterPlayer_Parms,NULL);
	return RegisterPlayer_Parms.ReturnValue;
}

struct IpDrv_ClearGameInviteAcceptedDelegate_Parms
{
	unsigned char                                      LocalUserNum;                                     		// 0x000000 (0x0001)              
	struct FScriptDelegate                             GameInviteAcceptedDelegate;                       		// 0x000004 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearGameInviteAcceptedDelegate(unsigned char LocalUserNum,struct FScriptDelegate GameInviteAcceptedDelegate)
{
	static UFieldFunc* pFnClearGameInviteAcceptedDelegate = NULL;
	if(!pFnClearGameInviteAcceptedDelegate)
		pFnClearGameInviteAcceptedDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearGameInviteAcceptedDelegate");

	IpDrv_ClearGameInviteAcceptedDelegate_Parms ClearGameInviteAcceptedDelegate_Parms;
	ClearGameInviteAcceptedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy(&ClearGameInviteAcceptedDelegate_Parms.GameInviteAcceptedDelegate,&GameInviteAcceptedDelegate,0xC);
	ProcessEvent(pFnClearGameInviteAcceptedDelegate,NULL,&ClearGameInviteAcceptedDelegate_Parms,NULL);
}

struct IpDrv_ClearRecalculateSkillRatingCompleteDelegate_Parms
{
	struct FScriptDelegate                             RecalculateSkillRatingGameCompleteDelegate;       		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearRecalculateSkillRatingCompleteDelegate(struct FScriptDelegate RecalculateSkillRatingGameCompleteDelegate)
{
	static UFieldFunc* pFnClearRecalculateSkillRatingCompleteDelegate = NULL;
	if(!pFnClearRecalculateSkillRatingCompleteDelegate)
		pFnClearRecalculateSkillRatingCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearRecalculateSkillRatingCompleteDelegate");

	IpDrv_ClearRecalculateSkillRatingCompleteDelegate_Parms ClearRecalculateSkillRatingCompleteDelegate_Parms;
	memcpy(&ClearRecalculateSkillRatingCompleteDelegate_Parms.RecalculateSkillRatingGameCompleteDelegate,&RecalculateSkillRatingGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearRecalculateSkillRatingCompleteDelegate,NULL,&ClearRecalculateSkillRatingCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearUpdateOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             UpdateOnlineGameCompleteDelegate;                 		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearUpdateOnlineGameCompleteDelegate(struct FScriptDelegate UpdateOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearUpdateOnlineGameCompleteDelegate = NULL;
	if(!pFnClearUpdateOnlineGameCompleteDelegate)
		pFnClearUpdateOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearUpdateOnlineGameCompleteDelegate");

	IpDrv_ClearUpdateOnlineGameCompleteDelegate_Parms ClearUpdateOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearUpdateOnlineGameCompleteDelegate_Parms.UpdateOnlineGameCompleteDelegate,&UpdateOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearUpdateOnlineGameCompleteDelegate,NULL,&ClearUpdateOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_OnUpdateOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnUpdateOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnUpdateOnlineGameComplete = NULL;
	if(!pFnOnUpdateOnlineGameComplete)
		pFnOnUpdateOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnUpdateOnlineGameComplete");

	IpDrv_OnUpdateOnlineGameComplete_Parms OnUpdateOnlineGameComplete_Parms;
	memcpy(&OnUpdateOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnUpdateOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnUpdateOnlineGameComplete,NULL,&OnUpdateOnlineGameComplete_Parms,NULL);
}

struct IpDrv_ClearEndOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             EndOnlineGameCompleteDelegate;                    		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearEndOnlineGameCompleteDelegate(struct FScriptDelegate EndOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearEndOnlineGameCompleteDelegate = NULL;
	if(!pFnClearEndOnlineGameCompleteDelegate)
		pFnClearEndOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearEndOnlineGameCompleteDelegate");

	IpDrv_ClearEndOnlineGameCompleteDelegate_Parms ClearEndOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearEndOnlineGameCompleteDelegate_Parms.EndOnlineGameCompleteDelegate,&EndOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearEndOnlineGameCompleteDelegate,NULL,&ClearEndOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_BindPlatformSpecificSessionToSearch_Parms
{
	unsigned char                                      SearchingPlayerNum;                               		// 0x000000 (0x0001)              
	class UOnlineGameSearch*                           SearchSettings;                                   		// 0x000004 (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x000008 (0x0050)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000058 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::BindPlatformSpecificSessionToSearch(unsigned char SearchingPlayerNum,class UOnlineGameSearch* SearchSettings,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnBindPlatformSpecificSessionToSearch = NULL;
	if(!pFnBindPlatformSpecificSessionToSearch)
		pFnBindPlatformSpecificSessionToSearch = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.BindPlatformSpecificSessionToSearch");

	IpDrv_BindPlatformSpecificSessionToSearch_Parms BindPlatformSpecificSessionToSearch_Parms;
	BindPlatformSpecificSessionToSearch_Parms.SearchingPlayerNum = SearchingPlayerNum;
	BindPlatformSpecificSessionToSearch_Parms.SearchSettings = SearchSettings;
	memcpy(&BindPlatformSpecificSessionToSearch_Parms.PlatformSpecificInfo,&PlatformSpecificInfo,0x50);
	pFnBindPlatformSpecificSessionToSearch->FunctionFlags |= ~0x400;
	ProcessEvent(pFnBindPlatformSpecificSessionToSearch,NULL,&BindPlatformSpecificSessionToSearch_Parms,NULL);
	pFnBindPlatformSpecificSessionToSearch->FunctionFlags |= 0x400;
	return BindPlatformSpecificSessionToSearch_Parms.ReturnValue;
}

struct IpDrv_ClearCancelFindOnlineGamesCompleteDelegate_Parms
{
	struct FScriptDelegate                             CancelFindOnlineGamesCompleteDelegate;            		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearCancelFindOnlineGamesCompleteDelegate(struct FScriptDelegate CancelFindOnlineGamesCompleteDelegate)
{
	static UFieldFunc* pFnClearCancelFindOnlineGamesCompleteDelegate = NULL;
	if(!pFnClearCancelFindOnlineGamesCompleteDelegate)
		pFnClearCancelFindOnlineGamesCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearCancelFindOnlineGamesCompleteDelegate");

	IpDrv_ClearCancelFindOnlineGamesCompleteDelegate_Parms ClearCancelFindOnlineGamesCompleteDelegate_Parms;
	memcpy(&ClearCancelFindOnlineGamesCompleteDelegate_Parms.CancelFindOnlineGamesCompleteDelegate,&CancelFindOnlineGamesCompleteDelegate,0xC);
	ProcessEvent(pFnClearCancelFindOnlineGamesCompleteDelegate,NULL,&ClearCancelFindOnlineGamesCompleteDelegate_Parms,NULL);
}

struct IpDrv_FindOnlineGames_Parms
{
	unsigned char                                      SearchingPlayerNum;                               		// 0x000000 (0x0001)              
	class UOnlineGameSearch*                           SearchSettings;                                   		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::FindOnlineGames(unsigned char SearchingPlayerNum,class UOnlineGameSearch* SearchSettings)
{
	static UFieldFunc* pFnFindOnlineGames = NULL;
	if(!pFnFindOnlineGames)
		pFnFindOnlineGames = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.FindOnlineGames");

	IpDrv_FindOnlineGames_Parms FindOnlineGames_Parms;
	FindOnlineGames_Parms.SearchingPlayerNum = SearchingPlayerNum;
	FindOnlineGames_Parms.SearchSettings = SearchSettings;
	pFnFindOnlineGames->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFindOnlineGames,NULL,&FindOnlineGames_Parms,NULL);
	pFnFindOnlineGames->FunctionFlags |= 0x400;
	return FindOnlineGames_Parms.ReturnValue;
}

struct IpDrv_RegisterForArbitration_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::RegisterForArbitration(struct FName SessionName)
{
	static UFieldFunc* pFnRegisterForArbitration = NULL;
	if(!pFnRegisterForArbitration)
		pFnRegisterForArbitration = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.RegisterForArbitration");

	IpDrv_RegisterForArbitration_Parms RegisterForArbitration_Parms;
	memcpy(&RegisterForArbitration_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnRegisterForArbitration,NULL,&RegisterForArbitration_Parms,NULL);
	return RegisterForArbitration_Parms.ReturnValue;
}

struct IpDrv_OnGameInviteAccepted_Parms
{
	struct FOnlineGameSearchResult                     InviteResult;                                     		// 0x000000 (0x0008)              
};

void UOnlineGameInterfaceImpl::OnGameInviteAccepted(struct FOnlineGameSearchResult* InviteResult)
{
	static UFieldFunc* pFnOnGameInviteAccepted = NULL;
	if(!pFnOnGameInviteAccepted)
		pFnOnGameInviteAccepted = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnGameInviteAccepted");

	IpDrv_OnGameInviteAccepted_Parms OnGameInviteAccepted_Parms;
	ProcessEvent(pFnOnGameInviteAccepted,NULL,&OnGameInviteAccepted_Parms,NULL);
	if(InviteResult)
		memcpy(InviteResult,&OnGameInviteAccepted_Parms.InviteResult,0x8);
}

struct IpDrv_OnArbitrationRegistrationComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnArbitrationRegistrationComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnArbitrationRegistrationComplete = NULL;
	if(!pFnOnArbitrationRegistrationComplete)
		pFnOnArbitrationRegistrationComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnArbitrationRegistrationComplete");

	IpDrv_OnArbitrationRegistrationComplete_Parms OnArbitrationRegistrationComplete_Parms;
	memcpy(&OnArbitrationRegistrationComplete_Parms.SessionName,&SessionName,0x8);
	OnArbitrationRegistrationComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnArbitrationRegistrationComplete,NULL,&OnArbitrationRegistrationComplete_Parms,NULL);
}

struct IpDrv_OnFindOnlineGamesComplete_Parms
{
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000000 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnFindOnlineGamesComplete(bool bWasSuccessful)
{
	static UFieldFunc* pFnOnFindOnlineGamesComplete = NULL;
	if(!pFnOnFindOnlineGamesComplete)
		pFnOnFindOnlineGamesComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnFindOnlineGamesComplete");

	IpDrv_OnFindOnlineGamesComplete_Parms OnFindOnlineGamesComplete_Parms;
	OnFindOnlineGamesComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnFindOnlineGamesComplete,NULL,&OnFindOnlineGamesComplete_Parms,NULL);
}

struct IpDrv_ReadPlatformSpecificSessionInfoBySessionName_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x000008 (0x0050)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000058 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::ReadPlatformSpecificSessionInfoBySessionName(struct FName SessionName,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnReadPlatformSpecificSessionInfoBySessionName = NULL;
	if(!pFnReadPlatformSpecificSessionInfoBySessionName)
		pFnReadPlatformSpecificSessionInfoBySessionName = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfoBySessionName");

	IpDrv_ReadPlatformSpecificSessionInfoBySessionName_Parms ReadPlatformSpecificSessionInfoBySessionName_Parms;
	memcpy(&ReadPlatformSpecificSessionInfoBySessionName_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnReadPlatformSpecificSessionInfoBySessionName,NULL,&ReadPlatformSpecificSessionInfoBySessionName_Parms,NULL);
	if(PlatformSpecificInfo)
		memcpy(PlatformSpecificInfo,&ReadPlatformSpecificSessionInfoBySessionName_Parms.PlatformSpecificInfo,0x50);
	return ReadPlatformSpecificSessionInfoBySessionName_Parms.ReturnValue;
}

struct IpDrv_AcceptGameInvite_Parms
{
	unsigned char                                      LocalUserNum;                                     		// 0x000000 (0x0001)              
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::AcceptGameInvite(unsigned char LocalUserNum,struct FName SessionName)
{
	static UFieldFunc* pFnAcceptGameInvite = NULL;
	if(!pFnAcceptGameInvite)
		pFnAcceptGameInvite = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AcceptGameInvite");

	IpDrv_AcceptGameInvite_Parms AcceptGameInvite_Parms;
	AcceptGameInvite_Parms.LocalUserNum = LocalUserNum;
	memcpy(&AcceptGameInvite_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnAcceptGameInvite,NULL,&AcceptGameInvite_Parms,NULL);
	return AcceptGameInvite_Parms.ReturnValue;
}

struct IpDrv_ClearArbitrationRegistrationCompleteDelegate_Parms
{
	struct FScriptDelegate                             ArbitrationRegistrationCompleteDelegate;          		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearArbitrationRegistrationCompleteDelegate(struct FScriptDelegate ArbitrationRegistrationCompleteDelegate)
{
	static UFieldFunc* pFnClearArbitrationRegistrationCompleteDelegate = NULL;
	if(!pFnClearArbitrationRegistrationCompleteDelegate)
		pFnClearArbitrationRegistrationCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearArbitrationRegistrationCompleteDelegate");

	IpDrv_ClearArbitrationRegistrationCompleteDelegate_Parms ClearArbitrationRegistrationCompleteDelegate_Parms;
	memcpy(&ClearArbitrationRegistrationCompleteDelegate_Parms.ArbitrationRegistrationCompleteDelegate,&ArbitrationRegistrationCompleteDelegate,0xC);
	ProcessEvent(pFnClearArbitrationRegistrationCompleteDelegate,NULL,&ClearArbitrationRegistrationCompleteDelegate_Parms,NULL);
}

struct IpDrv_RecalculateSkillRating_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	TArray<struct FUniqueNetId>                        Players;                                          		// 0x000008 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::RecalculateSkillRating(struct FName SessionName,TArray<struct FUniqueNetId>* Players)
{
	static UFieldFunc* pFnRecalculateSkillRating = NULL;
	if(!pFnRecalculateSkillRating)
		pFnRecalculateSkillRating = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.RecalculateSkillRating");

	IpDrv_RecalculateSkillRating_Parms RecalculateSkillRating_Parms;
	memcpy(&RecalculateSkillRating_Parms.SessionName,&SessionName,0x8);
	ProcessEvent(pFnRecalculateSkillRating,NULL,&RecalculateSkillRating_Parms,NULL);
	if(Players)
		memcpy(Players,&RecalculateSkillRating_Parms.Players,0xC);
	return RecalculateSkillRating_Parms.ReturnValue;
}

struct IpDrv_OnCreateOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnCreateOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnCreateOnlineGameComplete = NULL;
	if(!pFnOnCreateOnlineGameComplete)
		pFnOnCreateOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnCreateOnlineGameComplete");

	IpDrv_OnCreateOnlineGameComplete_Parms OnCreateOnlineGameComplete_Parms;
	memcpy(&OnCreateOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnCreateOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnCreateOnlineGameComplete,NULL,&OnCreateOnlineGameComplete_Parms,NULL);
}

struct IpDrv_OnJoinMigratedOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnJoinMigratedOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnJoinMigratedOnlineGameComplete = NULL;
	if(!pFnOnJoinMigratedOnlineGameComplete)
		pFnOnJoinMigratedOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnJoinMigratedOnlineGameComplete");

	IpDrv_OnJoinMigratedOnlineGameComplete_Parms OnJoinMigratedOnlineGameComplete_Parms;
	memcpy(&OnJoinMigratedOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnJoinMigratedOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnJoinMigratedOnlineGameComplete,NULL,&OnJoinMigratedOnlineGameComplete_Parms,NULL);
}

struct IpDrv_CreateOnlineGame_Parms
{
	unsigned char                                      HostingPlayerNum;                                 		// 0x000000 (0x0001)              
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	class UOnlineGameSettings*                         NewGameSettings;                                  		// 0x00000C (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::CreateOnlineGame(unsigned char HostingPlayerNum,struct FName SessionName,class UOnlineGameSettings* NewGameSettings)
{
	static UFieldFunc* pFnCreateOnlineGame = NULL;
	if(!pFnCreateOnlineGame)
		pFnCreateOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.CreateOnlineGame");

	IpDrv_CreateOnlineGame_Parms CreateOnlineGame_Parms;
	CreateOnlineGame_Parms.HostingPlayerNum = HostingPlayerNum;
	memcpy(&CreateOnlineGame_Parms.SessionName,&SessionName,0x8);
	CreateOnlineGame_Parms.NewGameSettings = NewGameSettings;
	pFnCreateOnlineGame->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCreateOnlineGame,NULL,&CreateOnlineGame_Parms,NULL);
	pFnCreateOnlineGame->FunctionFlags |= 0x400;
	return CreateOnlineGame_Parms.ReturnValue;
}

struct IpDrv_AddUnregisterPlayerCompleteDelegate_Parms
{
	struct FScriptDelegate                             UnregisterPlayerCompleteDelegate;                 		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddUnregisterPlayerCompleteDelegate(struct FScriptDelegate UnregisterPlayerCompleteDelegate)
{
	static UFieldFunc* pFnAddUnregisterPlayerCompleteDelegate = NULL;
	if(!pFnAddUnregisterPlayerCompleteDelegate)
		pFnAddUnregisterPlayerCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddUnregisterPlayerCompleteDelegate");

	IpDrv_AddUnregisterPlayerCompleteDelegate_Parms AddUnregisterPlayerCompleteDelegate_Parms;
	memcpy(&AddUnregisterPlayerCompleteDelegate_Parms.UnregisterPlayerCompleteDelegate,&UnregisterPlayerCompleteDelegate,0xC);
	ProcessEvent(pFnAddUnregisterPlayerCompleteDelegate,NULL,&AddUnregisterPlayerCompleteDelegate_Parms,NULL);
}

struct IpDrv_AddEndOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             EndOnlineGameCompleteDelegate;                    		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddEndOnlineGameCompleteDelegate(struct FScriptDelegate EndOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddEndOnlineGameCompleteDelegate = NULL;
	if(!pFnAddEndOnlineGameCompleteDelegate)
		pFnAddEndOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddEndOnlineGameCompleteDelegate");

	IpDrv_AddEndOnlineGameCompleteDelegate_Parms AddEndOnlineGameCompleteDelegate_Parms;
	memcpy(&AddEndOnlineGameCompleteDelegate_Parms.EndOnlineGameCompleteDelegate,&EndOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddEndOnlineGameCompleteDelegate,NULL,&AddEndOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_OnUnregisterPlayerComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                PlayerID;                                         		// 0x000008 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000010 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnUnregisterPlayerComplete(struct FName SessionName,struct FUniqueNetId PlayerID,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnUnregisterPlayerComplete = NULL;
	if(!pFnOnUnregisterPlayerComplete)
		pFnOnUnregisterPlayerComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnUnregisterPlayerComplete");

	IpDrv_OnUnregisterPlayerComplete_Parms OnUnregisterPlayerComplete_Parms;
	memcpy(&OnUnregisterPlayerComplete_Parms.SessionName,&SessionName,0x8);
	memcpy(&OnUnregisterPlayerComplete_Parms.PlayerID,&PlayerID,0x8);
	OnUnregisterPlayerComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnUnregisterPlayerComplete,NULL,&OnUnregisterPlayerComplete_Parms,NULL);
}

struct IpDrv_OnStartOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnStartOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnStartOnlineGameComplete = NULL;
	if(!pFnOnStartOnlineGameComplete)
		pFnOnStartOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnStartOnlineGameComplete");

	IpDrv_OnStartOnlineGameComplete_Parms OnStartOnlineGameComplete_Parms;
	memcpy(&OnStartOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnStartOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnStartOnlineGameComplete,NULL,&OnStartOnlineGameComplete_Parms,NULL);
}

struct IpDrv_AddUpdateOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             UpdateOnlineGameCompleteDelegate;                 		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddUpdateOnlineGameCompleteDelegate(struct FScriptDelegate UpdateOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddUpdateOnlineGameCompleteDelegate = NULL;
	if(!pFnAddUpdateOnlineGameCompleteDelegate)
		pFnAddUpdateOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddUpdateOnlineGameCompleteDelegate");

	IpDrv_AddUpdateOnlineGameCompleteDelegate_Parms AddUpdateOnlineGameCompleteDelegate_Parms;
	memcpy(&AddUpdateOnlineGameCompleteDelegate_Parms.UpdateOnlineGameCompleteDelegate,&UpdateOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddUpdateOnlineGameCompleteDelegate,NULL,&AddUpdateOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearJoinMigratedOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             JoinMigratedOnlineGameCompleteDelegate;           		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearJoinMigratedOnlineGameCompleteDelegate(struct FScriptDelegate JoinMigratedOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearJoinMigratedOnlineGameCompleteDelegate = NULL;
	if(!pFnClearJoinMigratedOnlineGameCompleteDelegate)
		pFnClearJoinMigratedOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearJoinMigratedOnlineGameCompleteDelegate");

	IpDrv_ClearJoinMigratedOnlineGameCompleteDelegate_Parms ClearJoinMigratedOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearJoinMigratedOnlineGameCompleteDelegate_Parms.JoinMigratedOnlineGameCompleteDelegate,&JoinMigratedOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearJoinMigratedOnlineGameCompleteDelegate,NULL,&ClearJoinMigratedOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_CancelFindOnlineGames_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::CancelFindOnlineGames()
{
	static UFieldFunc* pFnCancelFindOnlineGames = NULL;
	if(!pFnCancelFindOnlineGames)
		pFnCancelFindOnlineGames = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.CancelFindOnlineGames");

	IpDrv_CancelFindOnlineGames_Parms CancelFindOnlineGames_Parms;
	pFnCancelFindOnlineGames->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCancelFindOnlineGames,NULL,&CancelFindOnlineGames_Parms,NULL);
	pFnCancelFindOnlineGames->FunctionFlags |= 0x400;
	return CancelFindOnlineGames_Parms.ReturnValue;
}

struct IpDrv_EndOnlineGame_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::EndOnlineGame(struct FName SessionName)
{
	static UFieldFunc* pFnEndOnlineGame = NULL;
	if(!pFnEndOnlineGame)
		pFnEndOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.EndOnlineGame");

	IpDrv_EndOnlineGame_Parms EndOnlineGame_Parms;
	memcpy(&EndOnlineGame_Parms.SessionName,&SessionName,0x8);
	pFnEndOnlineGame->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEndOnlineGame,NULL,&EndOnlineGame_Parms,NULL);
	pFnEndOnlineGame->FunctionFlags |= 0x400;
	return EndOnlineGame_Parms.ReturnValue;
}

struct IpDrv_AddCreateOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             CreateOnlineGameCompleteDelegate;                 		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddCreateOnlineGameCompleteDelegate(struct FScriptDelegate CreateOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddCreateOnlineGameCompleteDelegate = NULL;
	if(!pFnAddCreateOnlineGameCompleteDelegate)
		pFnAddCreateOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddCreateOnlineGameCompleteDelegate");

	IpDrv_AddCreateOnlineGameCompleteDelegate_Parms AddCreateOnlineGameCompleteDelegate_Parms;
	memcpy(&AddCreateOnlineGameCompleteDelegate_Parms.CreateOnlineGameCompleteDelegate,&CreateOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddCreateOnlineGameCompleteDelegate,NULL,&AddCreateOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_OnEndOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnEndOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnEndOnlineGameComplete = NULL;
	if(!pFnOnEndOnlineGameComplete)
		pFnOnEndOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnEndOnlineGameComplete");

	IpDrv_OnEndOnlineGameComplete_Parms OnEndOnlineGameComplete_Parms;
	memcpy(&OnEndOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnEndOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnEndOnlineGameComplete,NULL,&OnEndOnlineGameComplete_Parms,NULL);
}

struct IpDrv_AddMigrateOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             MigrateOnlineGameCompleteDelegate;                		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddMigrateOnlineGameCompleteDelegate(struct FScriptDelegate MigrateOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddMigrateOnlineGameCompleteDelegate = NULL;
	if(!pFnAddMigrateOnlineGameCompleteDelegate)
		pFnAddMigrateOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddMigrateOnlineGameCompleteDelegate");

	IpDrv_AddMigrateOnlineGameCompleteDelegate_Parms AddMigrateOnlineGameCompleteDelegate_Parms;
	memcpy(&AddMigrateOnlineGameCompleteDelegate_Parms.MigrateOnlineGameCompleteDelegate,&MigrateOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddMigrateOnlineGameCompleteDelegate,NULL,&AddMigrateOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_AddCancelFindOnlineGamesCompleteDelegate_Parms
{
	struct FScriptDelegate                             CancelFindOnlineGamesCompleteDelegate;            		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddCancelFindOnlineGamesCompleteDelegate(struct FScriptDelegate CancelFindOnlineGamesCompleteDelegate)
{
	static UFieldFunc* pFnAddCancelFindOnlineGamesCompleteDelegate = NULL;
	if(!pFnAddCancelFindOnlineGamesCompleteDelegate)
		pFnAddCancelFindOnlineGamesCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddCancelFindOnlineGamesCompleteDelegate");

	IpDrv_AddCancelFindOnlineGamesCompleteDelegate_Parms AddCancelFindOnlineGamesCompleteDelegate_Parms;
	memcpy(&AddCancelFindOnlineGamesCompleteDelegate_Parms.CancelFindOnlineGamesCompleteDelegate,&CancelFindOnlineGamesCompleteDelegate,0xC);
	ProcessEvent(pFnAddCancelFindOnlineGamesCompleteDelegate,NULL,&AddCancelFindOnlineGamesCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearCreateOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             CreateOnlineGameCompleteDelegate;                 		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearCreateOnlineGameCompleteDelegate(struct FScriptDelegate CreateOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearCreateOnlineGameCompleteDelegate = NULL;
	if(!pFnClearCreateOnlineGameCompleteDelegate)
		pFnClearCreateOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearCreateOnlineGameCompleteDelegate");

	IpDrv_ClearCreateOnlineGameCompleteDelegate_Parms ClearCreateOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearCreateOnlineGameCompleteDelegate_Parms.CreateOnlineGameCompleteDelegate,&CreateOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearCreateOnlineGameCompleteDelegate,NULL,&ClearCreateOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearUnregisterPlayerCompleteDelegate_Parms
{
	struct FScriptDelegate                             UnregisterPlayerCompleteDelegate;                 		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearUnregisterPlayerCompleteDelegate(struct FScriptDelegate UnregisterPlayerCompleteDelegate)
{
	static UFieldFunc* pFnClearUnregisterPlayerCompleteDelegate = NULL;
	if(!pFnClearUnregisterPlayerCompleteDelegate)
		pFnClearUnregisterPlayerCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearUnregisterPlayerCompleteDelegate");

	IpDrv_ClearUnregisterPlayerCompleteDelegate_Parms ClearUnregisterPlayerCompleteDelegate_Parms;
	memcpy(&ClearUnregisterPlayerCompleteDelegate_Parms.UnregisterPlayerCompleteDelegate,&UnregisterPlayerCompleteDelegate,0xC);
	ProcessEvent(pFnClearUnregisterPlayerCompleteDelegate,NULL,&ClearUnregisterPlayerCompleteDelegate_Parms,NULL);
}

struct IpDrv_AddJoinOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             JoinOnlineGameCompleteDelegate;                   		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::AddJoinOnlineGameCompleteDelegate(struct FScriptDelegate JoinOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnAddJoinOnlineGameCompleteDelegate = NULL;
	if(!pFnAddJoinOnlineGameCompleteDelegate)
		pFnAddJoinOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.AddJoinOnlineGameCompleteDelegate");

	IpDrv_AddJoinOnlineGameCompleteDelegate_Parms AddJoinOnlineGameCompleteDelegate_Parms;
	memcpy(&AddJoinOnlineGameCompleteDelegate_Parms.JoinOnlineGameCompleteDelegate,&JoinOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnAddJoinOnlineGameCompleteDelegate,NULL,&AddJoinOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_OnRegisterPlayerComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                PlayerID;                                         		// 0x000008 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000010 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnRegisterPlayerComplete(struct FName SessionName,struct FUniqueNetId PlayerID,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnRegisterPlayerComplete = NULL;
	if(!pFnOnRegisterPlayerComplete)
		pFnOnRegisterPlayerComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnRegisterPlayerComplete");

	IpDrv_OnRegisterPlayerComplete_Parms OnRegisterPlayerComplete_Parms;
	memcpy(&OnRegisterPlayerComplete_Parms.SessionName,&SessionName,0x8);
	memcpy(&OnRegisterPlayerComplete_Parms.PlayerID,&PlayerID,0x8);
	OnRegisterPlayerComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnRegisterPlayerComplete,NULL,&OnRegisterPlayerComplete_Parms,NULL);
}

struct IpDrv_ClearMigrateOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             MigrateOnlineGameCompleteDelegate;                		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearMigrateOnlineGameCompleteDelegate(struct FScriptDelegate MigrateOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearMigrateOnlineGameCompleteDelegate = NULL;
	if(!pFnClearMigrateOnlineGameCompleteDelegate)
		pFnClearMigrateOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearMigrateOnlineGameCompleteDelegate");

	IpDrv_ClearMigrateOnlineGameCompleteDelegate_Parms ClearMigrateOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearMigrateOnlineGameCompleteDelegate_Parms.MigrateOnlineGameCompleteDelegate,&MigrateOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearMigrateOnlineGameCompleteDelegate,NULL,&ClearMigrateOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearRegisterPlayerCompleteDelegate_Parms
{
	struct FScriptDelegate                             RegisterPlayerCompleteDelegate;                   		// 0x000000 (0x000C)              
};

void UOnlineGameInterfaceImpl::ClearRegisterPlayerCompleteDelegate(struct FScriptDelegate RegisterPlayerCompleteDelegate)
{
	static UFieldFunc* pFnClearRegisterPlayerCompleteDelegate = NULL;
	if(!pFnClearRegisterPlayerCompleteDelegate)
		pFnClearRegisterPlayerCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearRegisterPlayerCompleteDelegate");

	IpDrv_ClearRegisterPlayerCompleteDelegate_Parms ClearRegisterPlayerCompleteDelegate_Parms;
	memcpy(&ClearRegisterPlayerCompleteDelegate_Parms.RegisterPlayerCompleteDelegate,&RegisterPlayerCompleteDelegate,0xC);
	ProcessEvent(pFnClearRegisterPlayerCompleteDelegate,NULL,&ClearRegisterPlayerCompleteDelegate_Parms,NULL);
}

struct IpDrv_ClearJoinOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             JoinOnlineGameCompleteDelegate;                   		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearJoinOnlineGameCompleteDelegate(struct FScriptDelegate JoinOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearJoinOnlineGameCompleteDelegate = NULL;
	if(!pFnClearJoinOnlineGameCompleteDelegate)
		pFnClearJoinOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearJoinOnlineGameCompleteDelegate");

	IpDrv_ClearJoinOnlineGameCompleteDelegate_Parms ClearJoinOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearJoinOnlineGameCompleteDelegate_Parms.JoinOnlineGameCompleteDelegate,&JoinOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearJoinOnlineGameCompleteDelegate,NULL,&ClearJoinOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_JoinOnlineGame_Parms
{
	unsigned char                                      PlayerNum;                                        		// 0x000000 (0x0001)              
	struct FName                                       SessionName;                                      		// 0x000004 (0x0008)              
	struct FOnlineGameSearchResult                     DesiredGame;                                      		// 0x00000C (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UOnlineGameInterfaceImpl::JoinOnlineGame(unsigned char PlayerNum,struct FName SessionName,struct FOnlineGameSearchResult* DesiredGame)
{
	static UFieldFunc* pFnJoinOnlineGame = NULL;
	if(!pFnJoinOnlineGame)
		pFnJoinOnlineGame = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.JoinOnlineGame");

	IpDrv_JoinOnlineGame_Parms JoinOnlineGame_Parms;
	JoinOnlineGame_Parms.PlayerNum = PlayerNum;
	memcpy(&JoinOnlineGame_Parms.SessionName,&SessionName,0x8);
	pFnJoinOnlineGame->FunctionFlags |= ~0x400;
	ProcessEvent(pFnJoinOnlineGame,NULL,&JoinOnlineGame_Parms,NULL);
	pFnJoinOnlineGame->FunctionFlags |= 0x400;
	if(DesiredGame)
		memcpy(DesiredGame,&JoinOnlineGame_Parms.DesiredGame,0x8);
	return JoinOnlineGame_Parms.ReturnValue;
}

struct IpDrv_ClearDestroyOnlineGameCompleteDelegate_Parms
{
	struct FScriptDelegate                             DestroyOnlineGameCompleteDelegate;                		// 0x000000 (0x000C)              
	//int                                                RemoveIndex;                                      		// 0x00000C (0x0004)              
};

void UOnlineGameInterfaceImpl::ClearDestroyOnlineGameCompleteDelegate(struct FScriptDelegate DestroyOnlineGameCompleteDelegate)
{
	static UFieldFunc* pFnClearDestroyOnlineGameCompleteDelegate = NULL;
	if(!pFnClearDestroyOnlineGameCompleteDelegate)
		pFnClearDestroyOnlineGameCompleteDelegate = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.ClearDestroyOnlineGameCompleteDelegate");

	IpDrv_ClearDestroyOnlineGameCompleteDelegate_Parms ClearDestroyOnlineGameCompleteDelegate_Parms;
	memcpy(&ClearDestroyOnlineGameCompleteDelegate_Parms.DestroyOnlineGameCompleteDelegate,&DestroyOnlineGameCompleteDelegate,0xC);
	ProcessEvent(pFnClearDestroyOnlineGameCompleteDelegate,NULL,&ClearDestroyOnlineGameCompleteDelegate_Parms,NULL);
}

struct IpDrv_OnDestroyOnlineGameComplete_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	unsigned long                                      bWasSuccessful : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UOnlineGameInterfaceImpl::OnDestroyOnlineGameComplete(struct FName SessionName,bool bWasSuccessful)
{
	static UFieldFunc* pFnOnDestroyOnlineGameComplete = NULL;
	if(!pFnOnDestroyOnlineGameComplete)
		pFnOnDestroyOnlineGameComplete = UObject::FindFunction("Function IpDrv.OnlineGameInterfaceImpl.OnDestroyOnlineGameComplete");

	IpDrv_OnDestroyOnlineGameComplete_Parms OnDestroyOnlineGameComplete_Parms;
	memcpy(&OnDestroyOnlineGameComplete_Parms.SessionName,&SessionName,0x8);
	OnDestroyOnlineGameComplete_Parms.bWasSuccessful = bWasSuccessful;
	ProcessEvent(pFnOnDestroyOnlineGameComplete,NULL,&OnDestroyOnlineGameComplete_Parms,NULL);
}

struct IpDrv_DestroyBeacon_Parms
{
};

void UPartyBeacon::DestroyBeacon()
{
	static UFieldFunc* pFnDestroyBeacon = NULL;
	if(!pFnDestroyBeacon)
		pFnDestroyBeacon = UObject::FindFunction("Function IpDrv.PartyBeacon.DestroyBeacon");

	IpDrv_DestroyBeacon_Parms DestroyBeacon_Parms;
	pFnDestroyBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyBeacon,NULL,&DestroyBeacon_Parms,NULL);
	pFnDestroyBeacon->FunctionFlags |= 0x400;
}

struct IpDrv_OnDestroyComplete_Parms
{
};

void UPartyBeacon::OnDestroyComplete()
{
	static UFieldFunc* pFnOnDestroyComplete = NULL;
	if(!pFnOnDestroyComplete)
		pFnOnDestroyComplete = UObject::FindFunction("Function IpDrv.PartyBeacon.OnDestroyComplete");

	IpDrv_OnDestroyComplete_Parms OnDestroyComplete_Parms;
	ProcessEvent(pFnOnDestroyComplete,NULL,&OnDestroyComplete_Parms,NULL);
}

struct IpDrv_OnHostHasCancelled_Parms
{
};

void UPartyBeaconClient::OnHostHasCancelled()
{
	static UFieldFunc* pFnOnHostHasCancelled = NULL;
	if(!pFnOnHostHasCancelled)
		pFnOnHostHasCancelled = UObject::FindFunction("Function IpDrv.PartyBeaconClient.OnHostHasCancelled");

	IpDrv_OnHostHasCancelled_Parms OnHostHasCancelled_Parms;
	ProcessEvent(pFnOnHostHasCancelled,NULL,&OnHostHasCancelled_Parms,NULL);
}

struct IpDrv_OnTravelRequestReceived_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x000008 (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x00000C (0x0050)              
};

void UPartyBeaconClient::OnTravelRequestReceived(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnOnTravelRequestReceived = NULL;
	if(!pFnOnTravelRequestReceived)
		pFnOnTravelRequestReceived = UObject::FindFunction("Function IpDrv.PartyBeaconClient.OnTravelRequestReceived");

	IpDrv_OnTravelRequestReceived_Parms OnTravelRequestReceived_Parms;
	memcpy(&OnTravelRequestReceived_Parms.SessionName,&SessionName,0x8);
	OnTravelRequestReceived_Parms.SearchClass = SearchClass;
	memcpy(&OnTravelRequestReceived_Parms.PlatformSpecificInfo,&PlatformSpecificInfo,0x50);
	ProcessEvent(pFnOnTravelRequestReceived,NULL,&OnTravelRequestReceived_Parms,NULL);
}

struct IpDrv_OnHostIsReady_Parms
{
};

void UPartyBeaconClient::OnHostIsReady()
{
	static UFieldFunc* pFnOnHostIsReady = NULL;
	if(!pFnOnHostIsReady)
		pFnOnHostIsReady = UObject::FindFunction("Function IpDrv.PartyBeaconClient.OnHostIsReady");

	IpDrv_OnHostIsReady_Parms OnHostIsReady_Parms;
	ProcessEvent(pFnOnHostIsReady,NULL,&OnHostIsReady_Parms,NULL);
}

struct IpDrv_OnReservationRequestComplete_Parms
{
	unsigned char                                      ReservationResult;                                		// 0x000000 (0x0001)              
};

void UPartyBeaconClient::OnReservationRequestComplete(unsigned char ReservationResult)
{
	static UFieldFunc* pFnOnReservationRequestComplete = NULL;
	if(!pFnOnReservationRequestComplete)
		pFnOnReservationRequestComplete = UObject::FindFunction("Function IpDrv.PartyBeaconClient.OnReservationRequestComplete");

	IpDrv_OnReservationRequestComplete_Parms OnReservationRequestComplete_Parms;
	OnReservationRequestComplete_Parms.ReservationResult = ReservationResult;
	ProcessEvent(pFnOnReservationRequestComplete,NULL,&OnReservationRequestComplete_Parms,NULL);
}

struct IpDrv_CancelReservation_Parms
{
	struct FUniqueNetId                                CancellingPartyLeader;                            		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UPartyBeaconClient::CancelReservation(struct FUniqueNetId CancellingPartyLeader)
{
	static UFieldFunc* pFnCancelReservation = NULL;
	if(!pFnCancelReservation)
		pFnCancelReservation = UObject::FindFunction("Function IpDrv.PartyBeaconClient.CancelReservation");

	IpDrv_CancelReservation_Parms CancelReservation_Parms;
	memcpy(&CancelReservation_Parms.CancellingPartyLeader,&CancellingPartyLeader,0x8);
	pFnCancelReservation->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCancelReservation,NULL,&CancelReservation_Parms,NULL);
	pFnCancelReservation->FunctionFlags |= 0x400;
	return CancelReservation_Parms.ReturnValue;
}

struct IpDrv_RequestReservation_Parms
{
	struct FOnlineGameSearchResult                     DesiredHost;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                RequestingPartyLeader;                            		// 0x000008 (0x0008)              
	TArray<struct FPlayerReservation>                  Players;                                          		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UPartyBeaconClient::RequestReservation(struct FOnlineGameSearchResult* DesiredHost,struct FUniqueNetId RequestingPartyLeader,TArray<struct FPlayerReservation>* Players)
{
	static UFieldFunc* pFnRequestReservation = NULL;
	if(!pFnRequestReservation)
		pFnRequestReservation = UObject::FindFunction("Function IpDrv.PartyBeaconClient.RequestReservation");

	IpDrv_RequestReservation_Parms RequestReservation_Parms;
	memcpy(&RequestReservation_Parms.RequestingPartyLeader,&RequestingPartyLeader,0x8);
	pFnRequestReservation->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRequestReservation,NULL,&RequestReservation_Parms,NULL);
	pFnRequestReservation->FunctionFlags |= 0x400;
	if(DesiredHost)
		memcpy(DesiredHost,&RequestReservation_Parms.DesiredHost,0x8);
	if(Players)
		memcpy(Players,&RequestReservation_Parms.Players,0xC);
	return RequestReservation_Parms.ReturnValue;
}

struct IpDrv_OnReservationCountUpdated_Parms
{
	int                                                ReservationRemaining;                             		// 0x000000 (0x0004)              
};

void UPartyBeaconClient::OnReservationCountUpdated(int ReservationRemaining)
{
	static UFieldFunc* pFnOnReservationCountUpdated = NULL;
	if(!pFnOnReservationCountUpdated)
		pFnOnReservationCountUpdated = UObject::FindFunction("Function IpDrv.PartyBeaconClient.OnReservationCountUpdated");

	IpDrv_OnReservationCountUpdated_Parms OnReservationCountUpdated_Parms;
	OnReservationCountUpdated_Parms.ReservationRemaining = ReservationRemaining;
	ProcessEvent(pFnOnReservationCountUpdated,NULL,&OnReservationCountUpdated_Parms,NULL);
}

struct IpDrv_RequestReservationUpdate_Parms
{
	struct FOnlineGameSearchResult                     DesiredHost;                                      		// 0x000000 (0x0008)              
	struct FUniqueNetId                                RequestingPartyLeader;                            		// 0x000008 (0x0008)              
	TArray<struct FPlayerReservation>                  PlayersToAdd;                                     		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UPartyBeaconClient::RequestReservationUpdate(struct FOnlineGameSearchResult* DesiredHost,struct FUniqueNetId RequestingPartyLeader,TArray<struct FPlayerReservation>* PlayersToAdd)
{
	static UFieldFunc* pFnRequestReservationUpdate = NULL;
	if(!pFnRequestReservationUpdate)
		pFnRequestReservationUpdate = UObject::FindFunction("Function IpDrv.PartyBeaconClient.RequestReservationUpdate");

	IpDrv_RequestReservationUpdate_Parms RequestReservationUpdate_Parms;
	memcpy(&RequestReservationUpdate_Parms.RequestingPartyLeader,&RequestingPartyLeader,0x8);
	pFnRequestReservationUpdate->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRequestReservationUpdate,NULL,&RequestReservationUpdate_Parms,NULL);
	pFnRequestReservationUpdate->FunctionFlags |= 0x400;
	if(DesiredHost)
		memcpy(DesiredHost,&RequestReservationUpdate_Parms.DesiredHost,0x8);
	if(PlayersToAdd)
		memcpy(PlayersToAdd,&RequestReservationUpdate_Parms.PlayersToAdd,0xC);
	return RequestReservationUpdate_Parms.ReturnValue;
}

struct IpDrv_DestroyBeacon_Parms
{
};

void UPartyBeaconClient::DestroyBeacon()
{
	static UFieldFunc* pFnDestroyBeacon = NULL;
	if(!pFnDestroyBeacon)
		pFnDestroyBeacon = UObject::FindFunction("Function IpDrv.PartyBeaconClient.DestroyBeacon");

	IpDrv_DestroyBeacon_Parms DestroyBeacon_Parms;
	pFnDestroyBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyBeacon,NULL,&DestroyBeacon_Parms,NULL);
	pFnDestroyBeacon->FunctionFlags |= 0x400;
}

struct IpDrv_InitHostBeacon_Parms
{
	int                                                InNumTeams;                                       		// 0x000000 (0x0004)              
	int                                                InNumPlayersPerTeam;                              		// 0x000004 (0x0004)              
	int                                                InNumReservations;                                		// 0x000008 (0x0004)              
	struct FName                                       InSessionName;                                    		// 0x00000C (0x0008)              
	int                                                InForceTeamNum;                                   		// 0x000014 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UPartyBeaconHost::InitHostBeacon(int InNumTeams,int InNumPlayersPerTeam,int InNumReservations,struct FName InSessionName,int InForceTeamNum)
{
	static UFieldFunc* pFnInitHostBeacon = NULL;
	if(!pFnInitHostBeacon)
		pFnInitHostBeacon = UObject::FindFunction("Function IpDrv.PartyBeaconHost.InitHostBeacon");

	IpDrv_InitHostBeacon_Parms InitHostBeacon_Parms;
	InitHostBeacon_Parms.InNumTeams = InNumTeams;
	InitHostBeacon_Parms.InNumPlayersPerTeam = InNumPlayersPerTeam;
	InitHostBeacon_Parms.InNumReservations = InNumReservations;
	memcpy(&InitHostBeacon_Parms.InSessionName,&InSessionName,0x8);
	InitHostBeacon_Parms.InForceTeamNum = InForceTeamNum;
	pFnInitHostBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInitHostBeacon,NULL,&InitHostBeacon_Parms,NULL);
	pFnInitHostBeacon->FunctionFlags |= 0x400;
	return InitHostBeacon_Parms.ReturnValue;
}

struct IpDrv_TellClientsToTravel_Parms
{
	struct FName                                       SessionName;                                      		// 0x000000 (0x0008)              
	class UClass*                                      SearchClass;                                      		// 0x000008 (0x0004)              
	unsigned char                                      PlatformSpecificInfo[0x50];                       		// 0x00000C (0x0050)              
};

void UPartyBeaconHost::TellClientsToTravel(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo)
{
	static UFieldFunc* pFnTellClientsToTravel = NULL;
	if(!pFnTellClientsToTravel)
		pFnTellClientsToTravel = UObject::FindFunction("Function IpDrv.PartyBeaconHost.TellClientsToTravel");

	IpDrv_TellClientsToTravel_Parms TellClientsToTravel_Parms;
	memcpy(&TellClientsToTravel_Parms.SessionName,&SessionName,0x8);
	TellClientsToTravel_Parms.SearchClass = SearchClass;
	memcpy(&TellClientsToTravel_Parms.PlatformSpecificInfo,&PlatformSpecificInfo,0x50);
	pFnTellClientsToTravel->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTellClientsToTravel,NULL,&TellClientsToTravel_Parms,NULL);
	pFnTellClientsToTravel->FunctionFlags |= 0x400;
}

struct IpDrv_TellClientsHostHasCancelled_Parms
{
};

void UPartyBeaconHost::TellClientsHostHasCancelled()
{
	static UFieldFunc* pFnTellClientsHostHasCancelled = NULL;
	if(!pFnTellClientsHostHasCancelled)
		pFnTellClientsHostHasCancelled = UObject::FindFunction("Function IpDrv.PartyBeaconHost.TellClientsHostHasCancelled");

	IpDrv_TellClientsHostHasCancelled_Parms TellClientsHostHasCancelled_Parms;
	pFnTellClientsHostHasCancelled->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTellClientsHostHasCancelled,NULL,&TellClientsHostHasCancelled_Parms,NULL);
	pFnTellClientsHostHasCancelled->FunctionFlags |= 0x400;
}

struct IpDrv_AddPartyReservationEntry_Parms
{
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000000 (0x0008)              
	TArray<struct FPlayerReservation>                  PlayerMembers;                                    		// 0x000008 (0x000C)              
	int                                                TeamNum;                                          		// 0x000014 (0x0004)              
	unsigned long                                      bIsHost : 1;                                      		// 0x000018 (0x0004) [0x00000001] 
	unsigned char                                      ReturnValue;                                      		// 0x00001C (0x0001)              
};

unsigned char UPartyBeaconHost::AddPartyReservationEntry(struct FUniqueNetId PartyLeader,TArray<struct FPlayerReservation>* PlayerMembers,int TeamNum,bool bIsHost)
{
	static UFieldFunc* pFnAddPartyReservationEntry = NULL;
	if(!pFnAddPartyReservationEntry)
		pFnAddPartyReservationEntry = UObject::FindFunction("Function IpDrv.PartyBeaconHost.AddPartyReservationEntry");

	IpDrv_AddPartyReservationEntry_Parms AddPartyReservationEntry_Parms;
	memcpy(&AddPartyReservationEntry_Parms.PartyLeader,&PartyLeader,0x8);
	AddPartyReservationEntry_Parms.TeamNum = TeamNum;
	AddPartyReservationEntry_Parms.bIsHost = bIsHost;
	pFnAddPartyReservationEntry->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddPartyReservationEntry,NULL,&AddPartyReservationEntry_Parms,NULL);
	pFnAddPartyReservationEntry->FunctionFlags |= 0x400;
	if(PlayerMembers)
		memcpy(PlayerMembers,&AddPartyReservationEntry_Parms.PlayerMembers,0xC);
	return AddPartyReservationEntry_Parms.ReturnValue;
}

struct IpDrv_UnregisterPartyMembers_Parms
{
	//int                                                Index;                                            		// 0x000000 (0x0004)              
	//int                                                PartyIndex;                                       		// 0x000004 (0x0004)              
	//class UOnlineSubsystem*                            OnlineSub;                                        		// 0x000008 (0x0004)              
	//struct FPlayerReservation                          PlayerRes;                                        		// 0x00000C (0x0024)              
};

void UPartyBeaconHost::UnregisterPartyMembers()
{
	static UFieldFunc* pFnUnregisterPartyMembers = NULL;
	if(!pFnUnregisterPartyMembers)
		pFnUnregisterPartyMembers = UObject::FindFunction("Function IpDrv.PartyBeaconHost.UnregisterPartyMembers");

	IpDrv_UnregisterPartyMembers_Parms UnregisterPartyMembers_Parms;
	ProcessEvent(pFnUnregisterPartyMembers,NULL,&UnregisterPartyMembers_Parms,NULL);
}

struct IpDrv_AppendReservationSkillsToSearch_Parms
{
	class UOnlineGameSearch*                           Search;                                           		// 0x000000 (0x0004)              
};

void UPartyBeaconHost::AppendReservationSkillsToSearch(class UOnlineGameSearch* Search)
{
	static UFieldFunc* pFnAppendReservationSkillsToSearch = NULL;
	if(!pFnAppendReservationSkillsToSearch)
		pFnAppendReservationSkillsToSearch = UObject::FindFunction("Function IpDrv.PartyBeaconHost.AppendReservationSkillsToSearch");

	IpDrv_AppendReservationSkillsToSearch_Parms AppendReservationSkillsToSearch_Parms;
	AppendReservationSkillsToSearch_Parms.Search = Search;
	pFnAppendReservationSkillsToSearch->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAppendReservationSkillsToSearch,NULL,&AppendReservationSkillsToSearch_Parms,NULL);
	pFnAppendReservationSkillsToSearch->FunctionFlags |= 0x400;
}

struct IpDrv_AreReservationsFull_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UPartyBeaconHost::AreReservationsFull()
{
	static UFieldFunc* pFnAreReservationsFull = NULL;
	if(!pFnAreReservationsFull)
		pFnAreReservationsFull = UObject::FindFunction("Function IpDrv.PartyBeaconHost.AreReservationsFull");

	IpDrv_AreReservationsFull_Parms AreReservationsFull_Parms;
	ProcessEvent(pFnAreReservationsFull,NULL,&AreReservationsFull_Parms,NULL);
	return AreReservationsFull_Parms.ReturnValue;
}

struct IpDrv_RegisterPartyMembers_Parms
{
	//int                                                Index;                                            		// 0x000000 (0x0004)              
	//int                                                PartyIndex;                                       		// 0x000004 (0x0004)              
	//class UOnlineSubsystem*                            OnlineSub;                                        		// 0x000008 (0x0004)              
	//class UOnlineRecentPlayersList*                    PlayersList;                                      		// 0x00000C (0x0004)              
	//TArray<struct FUniqueNetId>                        Members;                                          		// 0x000010 (0x000C)              
	//struct FPlayerReservation                          PlayerRes;                                        		// 0x00001C (0x0024)              
};

void UPartyBeaconHost::RegisterPartyMembers()
{
	static UFieldFunc* pFnRegisterPartyMembers = NULL;
	if(!pFnRegisterPartyMembers)
		pFnRegisterPartyMembers = UObject::FindFunction("Function IpDrv.PartyBeaconHost.RegisterPartyMembers");

	IpDrv_RegisterPartyMembers_Parms RegisterPartyMembers_Parms;
	ProcessEvent(pFnRegisterPartyMembers,NULL,&RegisterPartyMembers_Parms,NULL);
}

struct IpDrv_UpdatePartyReservationEntry_Parms
{
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000000 (0x0008)              
	TArray<struct FPlayerReservation>                  PlayerMembers;                                    		// 0x000008 (0x000C)              
	unsigned char                                      ReturnValue;                                      		// 0x000014 (0x0001)              
};

unsigned char UPartyBeaconHost::UpdatePartyReservationEntry(struct FUniqueNetId PartyLeader,TArray<struct FPlayerReservation>* PlayerMembers)
{
	static UFieldFunc* pFnUpdatePartyReservationEntry = NULL;
	if(!pFnUpdatePartyReservationEntry)
		pFnUpdatePartyReservationEntry = UObject::FindFunction("Function IpDrv.PartyBeaconHost.UpdatePartyReservationEntry");

	IpDrv_UpdatePartyReservationEntry_Parms UpdatePartyReservationEntry_Parms;
	memcpy(&UpdatePartyReservationEntry_Parms.PartyLeader,&PartyLeader,0x8);
	pFnUpdatePartyReservationEntry->FunctionFlags |= ~0x400;
	ProcessEvent(pFnUpdatePartyReservationEntry,NULL,&UpdatePartyReservationEntry_Parms,NULL);
	pFnUpdatePartyReservationEntry->FunctionFlags |= 0x400;
	if(PlayerMembers)
		memcpy(PlayerMembers,&UpdatePartyReservationEntry_Parms.PlayerMembers,0xC);
	return UpdatePartyReservationEntry_Parms.ReturnValue;
}

struct IpDrv_TellClientsHostIsReady_Parms
{
};

void UPartyBeaconHost::TellClientsHostIsReady()
{
	static UFieldFunc* pFnTellClientsHostIsReady = NULL;
	if(!pFnTellClientsHostIsReady)
		pFnTellClientsHostIsReady = UObject::FindFunction("Function IpDrv.PartyBeaconHost.TellClientsHostIsReady");

	IpDrv_TellClientsHostIsReady_Parms TellClientsHostIsReady_Parms;
	pFnTellClientsHostIsReady->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTellClientsHostIsReady,NULL,&TellClientsHostIsReady_Parms,NULL);
	pFnTellClientsHostIsReady->FunctionFlags |= 0x400;
}

struct IpDrv_PauseReservationRequests_Parms
{
	unsigned long                                      bPause : 1;                                       		// 0x000000 (0x0004) [0x00000001] 
};

void UPartyBeaconHost::PauseReservationRequests(bool bPause)
{
	static UFieldFunc* pFnPauseReservationRequests = NULL;
	if(!pFnPauseReservationRequests)
		pFnPauseReservationRequests = UObject::FindFunction("Function IpDrv.PartyBeaconHost.PauseReservationRequests");

	IpDrv_PauseReservationRequests_Parms PauseReservationRequests_Parms;
	PauseReservationRequests_Parms.bPause = bPause;
	pFnPauseReservationRequests->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPauseReservationRequests,NULL,&PauseReservationRequests_Parms,NULL);
	pFnPauseReservationRequests->FunctionFlags |= 0x400;
}

struct IpDrv_DumpReservations_Parms
{
	//int                                                PartyIndex;                                       		// 0x000000 (0x0004)              
	//int                                                MemberIndex;                                      		// 0x000004 (0x0004)              
	//struct FUniqueNetId                                NetId;                                            		// 0x000008 (0x0008)              
	//struct FPlayerReservation                          PlayerRes;                                        		// 0x000010 (0x0024)              
};

void UPartyBeaconHost::DumpReservations()
{
	static UFieldFunc* pFnDumpReservations = NULL;
	if(!pFnDumpReservations)
		pFnDumpReservations = UObject::FindFunction("Function IpDrv.PartyBeaconHost.DumpReservations");

	IpDrv_DumpReservations_Parms DumpReservations_Parms;
	ProcessEvent(pFnDumpReservations,NULL,&DumpReservations_Parms,NULL);
}

struct IpDrv_OnClientCancellationReceived_Parms
{
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000000 (0x0008)              
};

void UPartyBeaconHost::OnClientCancellationReceived(struct FUniqueNetId PartyLeader)
{
	static UFieldFunc* pFnOnClientCancellationReceived = NULL;
	if(!pFnOnClientCancellationReceived)
		pFnOnClientCancellationReceived = UObject::FindFunction("Function IpDrv.PartyBeaconHost.OnClientCancellationReceived");

	IpDrv_OnClientCancellationReceived_Parms OnClientCancellationReceived_Parms;
	memcpy(&OnClientCancellationReceived_Parms.PartyLeader,&PartyLeader,0x8);
	ProcessEvent(pFnOnClientCancellationReceived,NULL,&OnClientCancellationReceived_Parms,NULL);
}

struct IpDrv_HandlePlayerLogout_Parms
{
	struct FUniqueNetId                                PlayerID;                                         		// 0x000000 (0x0008)              
	unsigned long                                      bMaintainParty : 1;                               		// 0x000008 (0x0004) [0x00000001] 
};

void UPartyBeaconHost::HandlePlayerLogout(struct FUniqueNetId PlayerID,bool bMaintainParty)
{
	static UFieldFunc* pFnHandlePlayerLogout = NULL;
	if(!pFnHandlePlayerLogout)
		pFnHandlePlayerLogout = UObject::FindFunction("Function IpDrv.PartyBeaconHost.HandlePlayerLogout");

	IpDrv_HandlePlayerLogout_Parms HandlePlayerLogout_Parms;
	memcpy(&HandlePlayerLogout_Parms.PlayerID,&PlayerID,0x8);
	HandlePlayerLogout_Parms.bMaintainParty = bMaintainParty;
	pFnHandlePlayerLogout->FunctionFlags |= ~0x400;
	ProcessEvent(pFnHandlePlayerLogout,NULL,&HandlePlayerLogout_Parms,NULL);
	pFnHandlePlayerLogout->FunctionFlags |= 0x400;
}

struct IpDrv_GetPartyLeaders_Parms
{
	TArray<struct FUniqueNetId>                        PartyLeaders;                                     		// 0x000000 (0x000C)              
	//int                                                PartyIndex;                                       		// 0x00000C (0x0004)              
};

void UPartyBeaconHost::GetPartyLeaders(TArray<struct FUniqueNetId>* PartyLeaders)
{
	static UFieldFunc* pFnGetPartyLeaders = NULL;
	if(!pFnGetPartyLeaders)
		pFnGetPartyLeaders = UObject::FindFunction("Function IpDrv.PartyBeaconHost.GetPartyLeaders");

	IpDrv_GetPartyLeaders_Parms GetPartyLeaders_Parms;
	ProcessEvent(pFnGetPartyLeaders,NULL,&GetPartyLeaders_Parms,NULL);
	if(PartyLeaders)
		memcpy(PartyLeaders,&GetPartyLeaders_Parms.PartyLeaders,0xC);
}

struct IpDrv_UnregisterParty_Parms
{
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000000 (0x0008)              
	//int                                                PlayerIndex;                                      		// 0x000008 (0x0004)              
	//int                                                PartyIndex;                                       		// 0x00000C (0x0004)              
	//class UOnlineSubsystem*                            OnlineSub;                                        		// 0x000010 (0x0004)              
	//struct FPlayerReservation                          PlayerRes;                                        		// 0x000014 (0x0024)              
};

void UPartyBeaconHost::UnregisterParty(struct FUniqueNetId PartyLeader)
{
	static UFieldFunc* pFnUnregisterParty = NULL;
	if(!pFnUnregisterParty)
		pFnUnregisterParty = UObject::FindFunction("Function IpDrv.PartyBeaconHost.UnregisterParty");

	IpDrv_UnregisterParty_Parms UnregisterParty_Parms;
	memcpy(&UnregisterParty_Parms.PartyLeader,&PartyLeader,0x8);
	ProcessEvent(pFnUnregisterParty,NULL,&UnregisterParty_Parms,NULL);
}

struct IpDrv_GetMaxAvailableTeamSize_Parms
{
	int                                                ReturnValue;                                      		// 0x000000 (0x0004)              
};

int UPartyBeaconHost::GetMaxAvailableTeamSize()
{
	static UFieldFunc* pFnGetMaxAvailableTeamSize = NULL;
	if(!pFnGetMaxAvailableTeamSize)
		pFnGetMaxAvailableTeamSize = UObject::FindFunction("Function IpDrv.PartyBeaconHost.GetMaxAvailableTeamSize");

	IpDrv_GetMaxAvailableTeamSize_Parms GetMaxAvailableTeamSize_Parms;
	pFnGetMaxAvailableTeamSize->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetMaxAvailableTeamSize,NULL,&GetMaxAvailableTeamSize_Parms,NULL);
	pFnGetMaxAvailableTeamSize->FunctionFlags |= 0x400;
	return GetMaxAvailableTeamSize_Parms.ReturnValue;
}

struct IpDrv_OnReservationsFull_Parms
{
};

void UPartyBeaconHost::OnReservationsFull()
{
	static UFieldFunc* pFnOnReservationsFull = NULL;
	if(!pFnOnReservationsFull)
		pFnOnReservationsFull = UObject::FindFunction("Function IpDrv.PartyBeaconHost.OnReservationsFull");

	IpDrv_OnReservationsFull_Parms OnReservationsFull_Parms;
	ProcessEvent(pFnOnReservationsFull,NULL,&OnReservationsFull_Parms,NULL);
}

struct IpDrv_GetPlayers_Parms
{
	TArray<struct FUniqueNetId>                        Players;                                          		// 0x000000 (0x000C)              
	//int                                                PlayerIndex;                                      		// 0x00000C (0x0004)              
	//int                                                PartyIndex;                                       		// 0x000010 (0x0004)              
	//struct FPlayerReservation                          PlayerRes;                                        		// 0x000014 (0x0024)              
};

void UPartyBeaconHost::GetPlayers(TArray<struct FUniqueNetId>* Players)
{
	static UFieldFunc* pFnGetPlayers = NULL;
	if(!pFnGetPlayers)
		pFnGetPlayers = UObject::FindFunction("Function IpDrv.PartyBeaconHost.GetPlayers");

	IpDrv_GetPlayers_Parms GetPlayers_Parms;
	ProcessEvent(pFnGetPlayers,NULL,&GetPlayers_Parms,NULL);
	if(Players)
		memcpy(Players,&GetPlayers_Parms.Players,0xC);
}

struct IpDrv_OnReservationChange_Parms
{
};

void UPartyBeaconHost::OnReservationChange()
{
	static UFieldFunc* pFnOnReservationChange = NULL;
	if(!pFnOnReservationChange)
		pFnOnReservationChange = UObject::FindFunction("Function IpDrv.PartyBeaconHost.OnReservationChange");

	IpDrv_OnReservationChange_Parms OnReservationChange_Parms;
	ProcessEvent(pFnOnReservationChange,NULL,&OnReservationChange_Parms,NULL);
}

struct IpDrv_GetExistingReservation_Parms
{
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000000 (0x0008)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UPartyBeaconHost::GetExistingReservation(struct FUniqueNetId* PartyLeader)
{
	static UFieldFunc* pFnGetExistingReservation = NULL;
	if(!pFnGetExistingReservation)
		pFnGetExistingReservation = UObject::FindFunction("Function IpDrv.PartyBeaconHost.GetExistingReservation");

	IpDrv_GetExistingReservation_Parms GetExistingReservation_Parms;
	pFnGetExistingReservation->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetExistingReservation,NULL,&GetExistingReservation_Parms,NULL);
	pFnGetExistingReservation->FunctionFlags |= 0x400;
	if(PartyLeader)
		memcpy(PartyLeader,&GetExistingReservation_Parms.PartyLeader,0x8);
	return GetExistingReservation_Parms.ReturnValue;
}

struct IpDrv_DestroyBeacon_Parms
{
};

void UPartyBeaconHost::DestroyBeacon()
{
	static UFieldFunc* pFnDestroyBeacon = NULL;
	if(!pFnDestroyBeacon)
		pFnDestroyBeacon = UObject::FindFunction("Function IpDrv.PartyBeaconHost.DestroyBeacon");

	IpDrv_DestroyBeacon_Parms DestroyBeacon_Parms;
	pFnDestroyBeacon->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDestroyBeacon,NULL,&DestroyBeacon_Parms,NULL);
	pFnDestroyBeacon->FunctionFlags |= 0x400;
}

struct IpDrv_AddHeader_Parms
{
	struct FString                                     HeaderName;                                       		// 0x000000 (0x000C)              
	struct FString                                     Value;                                            		// 0x00000C (0x000C)              
};

void UWebRequest::AddHeader(struct FString HeaderName,struct FString Value)
{
	static UFieldFunc* pFnAddHeader = NULL;
	if(!pFnAddHeader)
		pFnAddHeader = UObject::FindFunction("Function IpDrv.WebRequest.AddHeader");

	IpDrv_AddHeader_Parms AddHeader_Parms;
	memcpy(&AddHeader_Parms.HeaderName,&HeaderName,0xC);
	memcpy(&AddHeader_Parms.Value,&Value,0xC);
	pFnAddHeader->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddHeader,NULL,&AddHeader_Parms,NULL);
	pFnAddHeader->FunctionFlags |= 0x400;
}

struct IpDrv_GetHeaders_Parms
{
	TArray<struct FString>                             Headers;                                          		// 0x000000 (0x000C)              
};

void UWebRequest::GetHeaders(TArray<struct FString>* Headers)
{
	static UFieldFunc* pFnGetHeaders = NULL;
	if(!pFnGetHeaders)
		pFnGetHeaders = UObject::FindFunction("Function IpDrv.WebRequest.GetHeaders");

	IpDrv_GetHeaders_Parms GetHeaders_Parms;
	pFnGetHeaders->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetHeaders,NULL,&GetHeaders_Parms,NULL);
	pFnGetHeaders->FunctionFlags |= 0x400;
	if(Headers)
		memcpy(Headers,&GetHeaders_Parms.Headers,0xC);
}

struct IpDrv_GetVariableCount_Parms
{
	struct FString                                     VariableName;                                     		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UWebRequest::GetVariableCount(struct FString VariableName)
{
	static UFieldFunc* pFnGetVariableCount = NULL;
	if(!pFnGetVariableCount)
		pFnGetVariableCount = UObject::FindFunction("Function IpDrv.WebRequest.GetVariableCount");

	IpDrv_GetVariableCount_Parms GetVariableCount_Parms;
	memcpy(&GetVariableCount_Parms.VariableName,&VariableName,0xC);
	pFnGetVariableCount->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableCount,NULL,&GetVariableCount_Parms,NULL);
	pFnGetVariableCount->FunctionFlags |= 0x400;
	return GetVariableCount_Parms.ReturnValue;
}

struct IpDrv_Dump_Parms
{
};

void UWebRequest::Dump()
{
	static UFieldFunc* pFnDump = NULL;
	if(!pFnDump)
		pFnDump = UObject::FindFunction("Function IpDrv.WebRequest.Dump");

	IpDrv_Dump_Parms Dump_Parms;
	pFnDump->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDump,NULL,&Dump_Parms,NULL);
	pFnDump->FunctionFlags |= 0x400;
}

struct IpDrv_ProcessHeaderString_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	//int                                                I;                                                		// 0x00000C (0x0004)              
};

void UWebRequest::ProcessHeaderString(struct FString S)
{
	static UFieldFunc* pFnProcessHeaderString = NULL;
	if(!pFnProcessHeaderString)
		pFnProcessHeaderString = UObject::FindFunction("Function IpDrv.WebRequest.ProcessHeaderString");

	IpDrv_ProcessHeaderString_Parms ProcessHeaderString_Parms;
	memcpy(&ProcessHeaderString_Parms.S,&S,0xC);
	ProcessEvent(pFnProcessHeaderString,NULL,&ProcessHeaderString_Parms,NULL);
}

struct IpDrv_EncodeBase64_Parms
{
	struct FString                                     Decoded;                                          		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UWebRequest::EncodeBase64(struct FString Decoded)
{
	static UFieldFunc* pFnEncodeBase64 = NULL;
	if(!pFnEncodeBase64)
		pFnEncodeBase64 = UObject::FindFunction("Function IpDrv.WebRequest.EncodeBase64");

	IpDrv_EncodeBase64_Parms EncodeBase64_Parms;
	memcpy(&EncodeBase64_Parms.Decoded,&Decoded,0xC);
	pFnEncodeBase64->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEncodeBase64,NULL,&EncodeBase64_Parms,NULL);
	pFnEncodeBase64->FunctionFlags |= 0x400;
	return EncodeBase64_Parms.ReturnValue;
}

struct IpDrv_AddVariable_Parms
{
	struct FString                                     VariableName;                                     		// 0x000000 (0x000C)              
	struct FString                                     Value;                                            		// 0x00000C (0x000C)              
};

void UWebRequest::AddVariable(struct FString VariableName,struct FString Value)
{
	static UFieldFunc* pFnAddVariable = NULL;
	if(!pFnAddVariable)
		pFnAddVariable = UObject::FindFunction("Function IpDrv.WebRequest.AddVariable");

	IpDrv_AddVariable_Parms AddVariable_Parms;
	memcpy(&AddVariable_Parms.VariableName,&VariableName,0xC);
	memcpy(&AddVariable_Parms.Value,&Value,0xC);
	pFnAddVariable->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddVariable,NULL,&AddVariable_Parms,NULL);
	pFnAddVariable->FunctionFlags |= 0x400;
}

struct IpDrv_GetHexDigit_Parms
{
	struct FString                                     D;                                                		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UWebRequest::GetHexDigit(struct FString D)
{
	static UFieldFunc* pFnGetHexDigit = NULL;
	if(!pFnGetHexDigit)
		pFnGetHexDigit = UObject::FindFunction("Function IpDrv.WebRequest.GetHexDigit");

	IpDrv_GetHexDigit_Parms GetHexDigit_Parms;
	memcpy(&GetHexDigit_Parms.D,&D,0xC);
	ProcessEvent(pFnGetHexDigit,NULL,&GetHexDigit_Parms,NULL);
	return GetHexDigit_Parms.ReturnValue;
}

struct IpDrv_GetVariable_Parms
{
	struct FString                                     VariableName;                                     		// 0x000000 (0x000C)              
	struct FString                                     DefaultValue;                                     		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UWebRequest::GetVariable(struct FString VariableName,struct FString DefaultValue)
{
	static UFieldFunc* pFnGetVariable = NULL;
	if(!pFnGetVariable)
		pFnGetVariable = UObject::FindFunction("Function IpDrv.WebRequest.GetVariable");

	IpDrv_GetVariable_Parms GetVariable_Parms;
	memcpy(&GetVariable_Parms.VariableName,&VariableName,0xC);
	memcpy(&GetVariable_Parms.DefaultValue,&DefaultValue,0xC);
	pFnGetVariable->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariable,NULL,&GetVariable_Parms,NULL);
	pFnGetVariable->FunctionFlags |= 0x400;
	return GetVariable_Parms.ReturnValue;
}

struct IpDrv_GetVariableNumber_Parms
{
	struct FString                                     VariableName;                                     		// 0x000000 (0x000C)              
	int                                                Number;                                           		// 0x00000C (0x0004)              
	struct FString                                     DefaultValue;                                     		// 0x000010 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00001C (0x000C)              
};

struct FString UWebRequest::GetVariableNumber(struct FString VariableName,int Number,struct FString DefaultValue)
{
	static UFieldFunc* pFnGetVariableNumber = NULL;
	if(!pFnGetVariableNumber)
		pFnGetVariableNumber = UObject::FindFunction("Function IpDrv.WebRequest.GetVariableNumber");

	IpDrv_GetVariableNumber_Parms GetVariableNumber_Parms;
	memcpy(&GetVariableNumber_Parms.VariableName,&VariableName,0xC);
	GetVariableNumber_Parms.Number = Number;
	memcpy(&GetVariableNumber_Parms.DefaultValue,&DefaultValue,0xC);
	pFnGetVariableNumber->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableNumber,NULL,&GetVariableNumber_Parms,NULL);
	pFnGetVariableNumber->FunctionFlags |= 0x400;
	return GetVariableNumber_Parms.ReturnValue;
}

struct IpDrv_DecodeBase64_Parms
{
	struct FString                                     Encoded;                                          		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UWebRequest::DecodeBase64(struct FString Encoded)
{
	static UFieldFunc* pFnDecodeBase64 = NULL;
	if(!pFnDecodeBase64)
		pFnDecodeBase64 = UObject::FindFunction("Function IpDrv.WebRequest.DecodeBase64");

	IpDrv_DecodeBase64_Parms DecodeBase64_Parms;
	memcpy(&DecodeBase64_Parms.Encoded,&Encoded,0xC);
	pFnDecodeBase64->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDecodeBase64,NULL,&DecodeBase64_Parms,NULL);
	pFnDecodeBase64->FunctionFlags |= 0x400;
	return DecodeBase64_Parms.ReturnValue;
}

struct IpDrv_DecodeFormData_Parms
{
	struct FString                                     Data;                                             		// 0x000000 (0x000C)              
	//struct FString                                     Token[0x2];                                       		// 0x00000C (0x0018)              
	//struct FString                                     ch;                                               		// 0x000024 (0x000C)              
	//int                                                I;                                                		// 0x000030 (0x0004)              
	//int                                                H1;                                               		// 0x000034 (0x0004)              
	//int                                                H2;                                               		// 0x000038 (0x0004)              
	//int                                                Limit;                                            		// 0x00003C (0x0004)              
	//int                                                T;                                                		// 0x000040 (0x0004)              
};

void UWebRequest::DecodeFormData(struct FString Data)
{
	static UFieldFunc* pFnDecodeFormData = NULL;
	if(!pFnDecodeFormData)
		pFnDecodeFormData = UObject::FindFunction("Function IpDrv.WebRequest.DecodeFormData");

	IpDrv_DecodeFormData_Parms DecodeFormData_Parms;
	memcpy(&DecodeFormData_Parms.Data,&Data,0xC);
	ProcessEvent(pFnDecodeFormData,NULL,&DecodeFormData_Parms,NULL);
}

struct IpDrv_GetVariables_Parms
{
	TArray<struct FString>                             varNames;                                         		// 0x000000 (0x000C)              
};

void UWebRequest::GetVariables(TArray<struct FString>* varNames)
{
	static UFieldFunc* pFnGetVariables = NULL;
	if(!pFnGetVariables)
		pFnGetVariables = UObject::FindFunction("Function IpDrv.WebRequest.GetVariables");

	IpDrv_GetVariables_Parms GetVariables_Parms;
	pFnGetVariables->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariables,NULL,&GetVariables_Parms,NULL);
	pFnGetVariables->FunctionFlags |= 0x400;
	if(varNames)
		memcpy(varNames,&GetVariables_Parms.varNames,0xC);
}

struct IpDrv_GetHeader_Parms
{
	struct FString                                     HeaderName;                                       		// 0x000000 (0x000C)              
	struct FString                                     DefaultValue;                                     		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UWebRequest::GetHeader(struct FString HeaderName,struct FString DefaultValue)
{
	static UFieldFunc* pFnGetHeader = NULL;
	if(!pFnGetHeader)
		pFnGetHeader = UObject::FindFunction("Function IpDrv.WebRequest.GetHeader");

	IpDrv_GetHeader_Parms GetHeader_Parms;
	memcpy(&GetHeader_Parms.HeaderName,&HeaderName,0xC);
	memcpy(&GetHeader_Parms.DefaultValue,&DefaultValue,0xC);
	pFnGetHeader->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetHeader,NULL,&GetHeader_Parms,NULL);
	pFnGetHeader->FunctionFlags |= 0x400;
	return GetHeader_Parms.ReturnValue;
}

struct IpDrv_IncludeBinaryFile_Parms
{
	struct FString                                     Filename;                                         		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UWebResponse::IncludeBinaryFile(struct FString Filename)
{
	static UFieldFunc* pFnIncludeBinaryFile = NULL;
	if(!pFnIncludeBinaryFile)
		pFnIncludeBinaryFile = UObject::FindFunction("Function IpDrv.WebResponse.IncludeBinaryFile");

	IpDrv_IncludeBinaryFile_Parms IncludeBinaryFile_Parms;
	memcpy(&IncludeBinaryFile_Parms.Filename,&Filename,0xC);
	pFnIncludeBinaryFile->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIncludeBinaryFile,NULL,&IncludeBinaryFile_Parms,NULL);
	pFnIncludeBinaryFile->FunctionFlags |= 0x400;
	return IncludeBinaryFile_Parms.ReturnValue;
}

struct IpDrv_FailAuthentication_Parms
{
	struct FString                                     Realm;                                            		// 0x000000 (0x000C)              
};

void UWebResponse::FailAuthentication(struct FString Realm)
{
	static UFieldFunc* pFnFailAuthentication = NULL;
	if(!pFnFailAuthentication)
		pFnFailAuthentication = UObject::FindFunction("Function IpDrv.WebResponse.FailAuthentication");

	IpDrv_FailAuthentication_Parms FailAuthentication_Parms;
	memcpy(&FailAuthentication_Parms.Realm,&Realm,0xC);
	ProcessEvent(pFnFailAuthentication,NULL,&FailAuthentication_Parms,NULL);
}

struct IpDrv_Subst_Parms
{
	struct FString                                     Variable;                                         		// 0x000000 (0x000C)              
	struct FString                                     Value;                                            		// 0x00000C (0x000C)              
	unsigned long                                      bClear : 1;                                       		// 0x000018 (0x0004) [0x00000001] 
};

void UWebResponse::Subst(struct FString Variable,struct FString Value,bool bClear)
{
	static UFieldFunc* pFnSubst = NULL;
	if(!pFnSubst)
		pFnSubst = UObject::FindFunction("Function IpDrv.WebResponse.Subst");

	IpDrv_Subst_Parms Subst_Parms;
	memcpy(&Subst_Parms.Variable,&Variable,0xC);
	memcpy(&Subst_Parms.Value,&Value,0xC);
	Subst_Parms.bClear = bClear;
	pFnSubst->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubst,NULL,&Subst_Parms,NULL);
	pFnSubst->FunctionFlags |= 0x400;
}

struct IpDrv_SendStandardHeaders_Parms
{
	struct FString                                     ContentType;                                      		// 0x000000 (0x000C)              
	unsigned long                                      bCache : 1;                                       		// 0x00000C (0x0004) [0x00000001] 
};

void UWebResponse::SendStandardHeaders(struct FString ContentType,bool bCache)
{
	static UFieldFunc* pFnSendStandardHeaders = NULL;
	if(!pFnSendStandardHeaders)
		pFnSendStandardHeaders = UObject::FindFunction("Function IpDrv.WebResponse.SendStandardHeaders");

	IpDrv_SendStandardHeaders_Parms SendStandardHeaders_Parms;
	memcpy(&SendStandardHeaders_Parms.ContentType,&ContentType,0xC);
	SendStandardHeaders_Parms.bCache = bCache;
	ProcessEvent(pFnSendStandardHeaders,NULL,&SendStandardHeaders_Parms,NULL);
}

struct IpDrv_SendText_Parms
{
	struct FString                                     Text;                                             		// 0x000000 (0x000C)              
	unsigned long                                      bNoCRLF : 1;                                      		// 0x00000C (0x0004) [0x00000001] 
};

void UWebResponse::SendText(struct FString Text,bool bNoCRLF)
{
	static UFieldFunc* pFnSendText = NULL;
	if(!pFnSendText)
		pFnSendText = UObject::FindFunction("Function IpDrv.WebResponse.SendText");

	IpDrv_SendText_Parms SendText_Parms;
	memcpy(&SendText_Parms.Text,&Text,0xC);
	SendText_Parms.bNoCRLF = bNoCRLF;
	ProcessEvent(pFnSendText,NULL,&SendText_Parms,NULL);
}

struct IpDrv_ClearSubst_Parms
{
};

void UWebResponse::ClearSubst()
{
	static UFieldFunc* pFnClearSubst = NULL;
	if(!pFnClearSubst)
		pFnClearSubst = UObject::FindFunction("Function IpDrv.WebResponse.ClearSubst");

	IpDrv_ClearSubst_Parms ClearSubst_Parms;
	pFnClearSubst->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClearSubst,NULL,&ClearSubst_Parms,NULL);
	pFnClearSubst->FunctionFlags |= 0x400;
}

struct IpDrv_HTTPHeader_Parms
{
	struct FString                                     Header;                                           		// 0x000000 (0x000C)              
};

void UWebResponse::HTTPHeader(struct FString Header)
{
	static UFieldFunc* pFnHTTPHeader = NULL;
	if(!pFnHTTPHeader)
		pFnHTTPHeader = UObject::FindFunction("Function IpDrv.WebResponse.HTTPHeader");

	IpDrv_HTTPHeader_Parms HTTPHeader_Parms;
	memcpy(&HTTPHeader_Parms.Header,&Header,0xC);
	ProcessEvent(pFnHTTPHeader,NULL,&HTTPHeader_Parms,NULL);
}

struct IpDrv_SendBinary_Parms
{
	int                                                Count;                                            		// 0x000000 (0x0004)              
	unsigned char                                      B[0xFF];                                          		// 0x000004 (0x00FF)              
};

void UWebResponse::SendBinary(int Count,unsigned char* B)
{
	static UFieldFunc* pFnSendBinary = NULL;
	if(!pFnSendBinary)
		pFnSendBinary = UObject::FindFunction("Function IpDrv.WebResponse.SendBinary");

	IpDrv_SendBinary_Parms SendBinary_Parms;
	SendBinary_Parms.Count = Count;
	memcpy(&SendBinary_Parms.B,&B,0xFF);
	ProcessEvent(pFnSendBinary,NULL,&SendBinary_Parms,NULL);
}

struct IpDrv_AddHeader_Parms
{
	struct FString                                     Header;                                           		// 0x000000 (0x000C)              
	unsigned long                                      bReplace : 1;                                     		// 0x00000C (0x0004) [0x00000001] 
	//int                                                I;                                                		// 0x000010 (0x0004)              
	//int                                                Idx;                                              		// 0x000014 (0x0004)              
	//struct FString                                     part;                                             		// 0x000018 (0x000C)              
	//struct FString                                     Entry;                                            		// 0x000024 (0x000C)              
};

void UWebResponse::AddHeader(struct FString Header,bool bReplace)
{
	static UFieldFunc* pFnAddHeader = NULL;
	if(!pFnAddHeader)
		pFnAddHeader = UObject::FindFunction("Function IpDrv.WebResponse.AddHeader");

	IpDrv_AddHeader_Parms AddHeader_Parms;
	memcpy(&AddHeader_Parms.Header,&Header,0xC);
	AddHeader_Parms.bReplace = bReplace;
	ProcessEvent(pFnAddHeader,NULL,&AddHeader_Parms,NULL);
}

struct IpDrv_SentText_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UWebResponse::SentText()
{
	static UFieldFunc* pFnSentText = NULL;
	if(!pFnSentText)
		pFnSentText = UObject::FindFunction("Function IpDrv.WebResponse.SentText");

	IpDrv_SentText_Parms SentText_Parms;
	ProcessEvent(pFnSentText,NULL,&SentText_Parms,NULL);
	return SentText_Parms.ReturnValue;
}

struct IpDrv_IncludeUHTM_Parms
{
	struct FString                                     Filename;                                         		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UWebResponse::IncludeUHTM(struct FString Filename)
{
	static UFieldFunc* pFnIncludeUHTM = NULL;
	if(!pFnIncludeUHTM)
		pFnIncludeUHTM = UObject::FindFunction("Function IpDrv.WebResponse.IncludeUHTM");

	IpDrv_IncludeUHTM_Parms IncludeUHTM_Parms;
	memcpy(&IncludeUHTM_Parms.Filename,&Filename,0xC);
	pFnIncludeUHTM->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIncludeUHTM,NULL,&IncludeUHTM_Parms,NULL);
	pFnIncludeUHTM->FunctionFlags |= 0x400;
	return IncludeUHTM_Parms.ReturnValue;
}

struct IpDrv_HTTPResponse_Parms
{
	struct FString                                     Header;                                           		// 0x000000 (0x000C)              
};

void UWebResponse::HTTPResponse(struct FString Header)
{
	static UFieldFunc* pFnHTTPResponse = NULL;
	if(!pFnHTTPResponse)
		pFnHTTPResponse = UObject::FindFunction("Function IpDrv.WebResponse.HTTPResponse");

	IpDrv_HTTPResponse_Parms HTTPResponse_Parms;
	memcpy(&HTTPResponse_Parms.Header,&Header,0xC);
	ProcessEvent(pFnHTTPResponse,NULL,&HTTPResponse_Parms,NULL);
}

struct IpDrv_SentResponse_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UWebResponse::SentResponse()
{
	static UFieldFunc* pFnSentResponse = NULL;
	if(!pFnSentResponse)
		pFnSentResponse = UObject::FindFunction("Function IpDrv.WebResponse.SentResponse");

	IpDrv_SentResponse_Parms SentResponse_Parms;
	ProcessEvent(pFnSentResponse,NULL,&SentResponse_Parms,NULL);
	return SentResponse_Parms.ReturnValue;
}

struct IpDrv_Redirect_Parms
{
	struct FString                                     URL;                                              		// 0x000000 (0x000C)              
};

void UWebResponse::Redirect(struct FString URL)
{
	static UFieldFunc* pFnRedirect = NULL;
	if(!pFnRedirect)
		pFnRedirect = UObject::FindFunction("Function IpDrv.WebResponse.Redirect");

	IpDrv_Redirect_Parms Redirect_Parms;
	memcpy(&Redirect_Parms.URL,&URL,0xC);
	ProcessEvent(pFnRedirect,NULL,&Redirect_Parms,NULL);
}

struct IpDrv_FileExists_Parms
{
	struct FString                                     Filename;                                         		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UWebResponse::FileExists(struct FString Filename)
{
	static UFieldFunc* pFnFileExists = NULL;
	if(!pFnFileExists)
		pFnFileExists = UObject::FindFunction("Function IpDrv.WebResponse.FileExists");

	IpDrv_FileExists_Parms FileExists_Parms;
	memcpy(&FileExists_Parms.Filename,&Filename,0xC);
	pFnFileExists->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFileExists,NULL,&FileExists_Parms,NULL);
	pFnFileExists->FunctionFlags |= 0x400;
	return FileExists_Parms.ReturnValue;
}

struct IpDrv_GetHTTPExpiration_Parms
{
	int                                                OffsetSeconds;                                    		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UWebResponse::GetHTTPExpiration(int OffsetSeconds)
{
	static UFieldFunc* pFnGetHTTPExpiration = NULL;
	if(!pFnGetHTTPExpiration)
		pFnGetHTTPExpiration = UObject::FindFunction("Function IpDrv.WebResponse.GetHTTPExpiration");

	IpDrv_GetHTTPExpiration_Parms GetHTTPExpiration_Parms;
	GetHTTPExpiration_Parms.OffsetSeconds = OffsetSeconds;
	pFnGetHTTPExpiration->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetHTTPExpiration,NULL,&GetHTTPExpiration_Parms,NULL);
	pFnGetHTTPExpiration->FunctionFlags |= 0x400;
	return GetHTTPExpiration_Parms.ReturnValue;
}

struct IpDrv_SendHeaders_Parms
{
	//struct FString                                     hdr;                                              		// 0x000000 (0x000C)              
};

void UWebResponse::SendHeaders()
{
	static UFieldFunc* pFnSendHeaders = NULL;
	if(!pFnSendHeaders)
		pFnSendHeaders = UObject::FindFunction("Function IpDrv.WebResponse.SendHeaders");

	IpDrv_SendHeaders_Parms SendHeaders_Parms;
	ProcessEvent(pFnSendHeaders,NULL,&SendHeaders_Parms,NULL);
}

struct IpDrv_SendCachedFile_Parms
{
	struct FString                                     Filename;                                         		// 0x000000 (0x000C)              
	struct FString                                     ContentType;                                      		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UWebResponse::SendCachedFile(struct FString Filename,struct FString ContentType)
{
	static UFieldFunc* pFnSendCachedFile = NULL;
	if(!pFnSendCachedFile)
		pFnSendCachedFile = UObject::FindFunction("Function IpDrv.WebResponse.SendCachedFile");

	IpDrv_SendCachedFile_Parms SendCachedFile_Parms;
	memcpy(&SendCachedFile_Parms.Filename,&Filename,0xC);
	memcpy(&SendCachedFile_Parms.ContentType,&ContentType,0xC);
	ProcessEvent(pFnSendCachedFile,NULL,&SendCachedFile_Parms,NULL);
	return SendCachedFile_Parms.ReturnValue;
}

struct IpDrv_HTTPError_Parms
{
	int                                                ErrorNum;                                         		// 0x000000 (0x0004)              
	struct FString                                     Data;                                             		// 0x000004 (0x000C)              
};

void UWebResponse::HTTPError(int ErrorNum,struct FString Data)
{
	static UFieldFunc* pFnHTTPError = NULL;
	if(!pFnHTTPError)
		pFnHTTPError = UObject::FindFunction("Function IpDrv.WebResponse.HTTPError");

	IpDrv_HTTPError_Parms HTTPError_Parms;
	HTTPError_Parms.ErrorNum = ErrorNum;
	memcpy(&HTTPError_Parms.Data,&Data,0xC);
	ProcessEvent(pFnHTTPError,NULL,&HTTPError_Parms,NULL);
}

struct IpDrv_Dump_Parms
{
};

void UWebResponse::Dump()
{
	static UFieldFunc* pFnDump = NULL;
	if(!pFnDump)
		pFnDump = UObject::FindFunction("Function IpDrv.WebResponse.Dump");

	IpDrv_Dump_Parms Dump_Parms;
	pFnDump->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDump,NULL,&Dump_Parms,NULL);
	pFnDump->FunctionFlags |= 0x400;
}

struct IpDrv_LoadParsedUHTM_Parms
{
	struct FString                                     Filename;                                         		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UWebResponse::LoadParsedUHTM(struct FString Filename)
{
	static UFieldFunc* pFnLoadParsedUHTM = NULL;
	if(!pFnLoadParsedUHTM)
		pFnLoadParsedUHTM = UObject::FindFunction("Function IpDrv.WebResponse.LoadParsedUHTM");

	IpDrv_LoadParsedUHTM_Parms LoadParsedUHTM_Parms;
	memcpy(&LoadParsedUHTM_Parms.Filename,&Filename,0xC);
	pFnLoadParsedUHTM->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLoadParsedUHTM,NULL,&LoadParsedUHTM_Parms,NULL);
	pFnLoadParsedUHTM->FunctionFlags |= 0x400;
	return LoadParsedUHTM_Parms.ReturnValue;
}

struct IpDrv_Init_Parms
{
};

void UHelloWeb::Init()
{
	static UFieldFunc* pFnInit = NULL;
	if(!pFnInit)
		pFnInit = UObject::FindFunction("Function IpDrv.HelloWeb.Init");

	IpDrv_Init_Parms Init_Parms;
	ProcessEvent(pFnInit,NULL,&Init_Parms,NULL);
}

struct IpDrv_Query_Parms
{
	class UWebRequest*                                 Request;                                          		// 0x000000 (0x0004)              
	class UWebResponse*                                Response;                                         		// 0x000004 (0x0004)              
	//int                                                I;                                                		// 0x000008 (0x0004)              
};

void UHelloWeb::Query(class UWebRequest* Request,class UWebResponse* Response)
{
	static UFieldFunc* pFnQuery = NULL;
	if(!pFnQuery)
		pFnQuery = UObject::FindFunction("Function IpDrv.HelloWeb.Query");

	IpDrv_Query_Parms Query_Parms;
	Query_Parms.Request = Request;
	Query_Parms.Response = Response;
	ProcessEvent(pFnQuery,NULL,&Query_Parms,NULL);
}

struct IpDrv_Query_Parms
{
	class UWebRequest*                                 Request;                                          		// 0x000000 (0x0004)              
	class UWebResponse*                                Response;                                         		// 0x000004 (0x0004)              
};

void UWebApplication::Query(class UWebRequest* Request,class UWebResponse* Response)
{
	static UFieldFunc* pFnQuery = NULL;
	if(!pFnQuery)
		pFnQuery = UObject::FindFunction("Function IpDrv.WebApplication.Query");

	IpDrv_Query_Parms Query_Parms;
	Query_Parms.Request = Request;
	Query_Parms.Response = Response;
	ProcessEvent(pFnQuery,NULL,&Query_Parms,NULL);
}

struct IpDrv_PostQuery_Parms
{
	class UWebRequest*                                 Request;                                          		// 0x000000 (0x0004)              
	class UWebResponse*                                Response;                                         		// 0x000004 (0x0004)              
};

void UWebApplication::PostQuery(class UWebRequest* Request,class UWebResponse* Response)
{
	static UFieldFunc* pFnPostQuery = NULL;
	if(!pFnPostQuery)
		pFnPostQuery = UObject::FindFunction("Function IpDrv.WebApplication.PostQuery");

	IpDrv_PostQuery_Parms PostQuery_Parms;
	PostQuery_Parms.Request = Request;
	PostQuery_Parms.Response = Response;
	ProcessEvent(pFnPostQuery,NULL,&PostQuery_Parms,NULL);
}

struct IpDrv_Init_Parms
{
};

void UWebApplication::Init()
{
	static UFieldFunc* pFnInit = NULL;
	if(!pFnInit)
		pFnInit = UObject::FindFunction("Function IpDrv.WebApplication.Init");

	IpDrv_Init_Parms Init_Parms;
	ProcessEvent(pFnInit,NULL,&Init_Parms,NULL);
}

struct IpDrv_PreQuery_Parms
{
	class UWebRequest*                                 Request;                                          		// 0x000000 (0x0004)              
	class UWebResponse*                                Response;                                         		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UWebApplication::PreQuery(class UWebRequest* Request,class UWebResponse* Response)
{
	static UFieldFunc* pFnPreQuery = NULL;
	if(!pFnPreQuery)
		pFnPreQuery = UObject::FindFunction("Function IpDrv.WebApplication.PreQuery");

	IpDrv_PreQuery_Parms PreQuery_Parms;
	PreQuery_Parms.Request = Request;
	PreQuery_Parms.Response = Response;
	ProcessEvent(pFnPreQuery,NULL,&PreQuery_Parms,NULL);
	return PreQuery_Parms.ReturnValue;
}

struct IpDrv_CleanupApp_Parms
{
};

void UWebApplication::CleanupApp()
{
	static UFieldFunc* pFnCleanupApp = NULL;
	if(!pFnCleanupApp)
		pFnCleanupApp = UObject::FindFunction("Function IpDrv.WebApplication.CleanupApp");

	IpDrv_CleanupApp_Parms CleanupApp_Parms;
	ProcessEvent(pFnCleanupApp,NULL,&CleanupApp_Parms,NULL);
}

struct IpDrv_Cleanup_Parms
{
};

void UWebApplication::Cleanup()
{
	static UFieldFunc* pFnCleanup = NULL;
	if(!pFnCleanup)
		pFnCleanup = UObject::FindFunction("Function IpDrv.WebApplication.Cleanup");

	IpDrv_Cleanup_Parms Cleanup_Parms;
	ProcessEvent(pFnCleanup,NULL,&Cleanup_Parms,NULL);
}

struct IpDrv_Query_Parms
{
	class UWebRequest*                                 Request;                                          		// 0x000000 (0x0004)              
	class UWebResponse*                                Response;                                         		// 0x000004 (0x0004)              
	//struct FString                                     Image;                                            		// 0x000008 (0x000C)              
};

void UImageServer::Query(class UWebRequest* Request,class UWebResponse* Response)
{
	static UFieldFunc* pFnQuery = NULL;
	if(!pFnQuery)
		pFnQuery = UObject::FindFunction("Function IpDrv.ImageServer.Query");

	IpDrv_Query_Parms Query_Parms;
	Query_Parms.Request = Request;
	Query_Parms.Response = Response;
	ProcessEvent(pFnQuery,NULL,&Query_Parms,NULL);
}

struct IpDrv_Closed_Parms
{
};

void AWebConnection::Closed()
{
	static UFieldFunc* pFnClosed = NULL;
	if(!pFnClosed)
		pFnClosed = UObject::FindFunction("Function IpDrv.WebConnection.Closed");

	IpDrv_Closed_Parms Closed_Parms;
	ProcessEvent(pFnClosed,NULL,&Closed_Parms,NULL);
}

struct IpDrv_ProcessHead_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
};

void AWebConnection::ProcessHead(struct FString S)
{
	static UFieldFunc* pFnProcessHead = NULL;
	if(!pFnProcessHead)
		pFnProcessHead = UObject::FindFunction("Function IpDrv.WebConnection.ProcessHead");

	IpDrv_ProcessHead_Parms ProcessHead_Parms;
	memcpy(&ProcessHead_Parms.S,&S,0xC);
	ProcessEvent(pFnProcessHead,NULL,&ProcessHead_Parms,NULL);
}

struct IpDrv_ProcessPost_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	//int                                                I;                                                		// 0x00000C (0x0004)              
};

void AWebConnection::ProcessPost(struct FString S)
{
	static UFieldFunc* pFnProcessPost = NULL;
	if(!pFnProcessPost)
		pFnProcessPost = UObject::FindFunction("Function IpDrv.WebConnection.ProcessPost");

	IpDrv_ProcessPost_Parms ProcessPost_Parms;
	memcpy(&ProcessPost_Parms.S,&S,0xC);
	ProcessEvent(pFnProcessPost,NULL,&ProcessPost_Parms,NULL);
}

struct IpDrv_Accepted_Parms
{
};

void AWebConnection::Accepted()
{
	static UFieldFunc* pFnAccepted = NULL;
	if(!pFnAccepted)
		pFnAccepted = UObject::FindFunction("Function IpDrv.WebConnection.Accepted");

	IpDrv_Accepted_Parms Accepted_Parms;
	ProcessEvent(pFnAccepted,NULL,&Accepted_Parms,NULL);
}

struct IpDrv_EndOfHeaders_Parms
{
};

void AWebConnection::EndOfHeaders()
{
	static UFieldFunc* pFnEndOfHeaders = NULL;
	if(!pFnEndOfHeaders)
		pFnEndOfHeaders = UObject::FindFunction("Function IpDrv.WebConnection.EndOfHeaders");

	IpDrv_EndOfHeaders_Parms EndOfHeaders_Parms;
	ProcessEvent(pFnEndOfHeaders,NULL,&EndOfHeaders_Parms,NULL);
}

struct IpDrv_Cleanup_Parms
{
};

void AWebConnection::Cleanup()
{
	static UFieldFunc* pFnCleanup = NULL;
	if(!pFnCleanup)
		pFnCleanup = UObject::FindFunction("Function IpDrv.WebConnection.Cleanup");

	IpDrv_Cleanup_Parms Cleanup_Parms;
	ProcessEvent(pFnCleanup,NULL,&Cleanup_Parms,NULL);
}

struct IpDrv_ReceivedLine_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
};

void AWebConnection::ReceivedLine(struct FString S)
{
	static UFieldFunc* pFnReceivedLine = NULL;
	if(!pFnReceivedLine)
		pFnReceivedLine = UObject::FindFunction("Function IpDrv.WebConnection.ReceivedLine");

	IpDrv_ReceivedLine_Parms ReceivedLine_Parms;
	memcpy(&ReceivedLine_Parms.S,&S,0xC);
	ProcessEvent(pFnReceivedLine,NULL,&ReceivedLine_Parms,NULL);
}

struct IpDrv_CheckRawBytes_Parms
{
};

void AWebConnection::CheckRawBytes()
{
	static UFieldFunc* pFnCheckRawBytes = NULL;
	if(!pFnCheckRawBytes)
		pFnCheckRawBytes = UObject::FindFunction("Function IpDrv.WebConnection.CheckRawBytes");

	IpDrv_CheckRawBytes_Parms CheckRawBytes_Parms;
	ProcessEvent(pFnCheckRawBytes,NULL,&CheckRawBytes_Parms,NULL);
}

struct IpDrv_ProcessGet_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	//int                                                I;                                                		// 0x00000C (0x0004)              
};

void AWebConnection::ProcessGet(struct FString S)
{
	static UFieldFunc* pFnProcessGet = NULL;
	if(!pFnProcessGet)
		pFnProcessGet = UObject::FindFunction("Function IpDrv.WebConnection.ProcessGet");

	IpDrv_ProcessGet_Parms ProcessGet_Parms;
	memcpy(&ProcessGet_Parms.S,&S,0xC);
	ProcessEvent(pFnProcessGet,NULL,&ProcessGet_Parms,NULL);
}

struct IpDrv_ReceivedText_Parms
{
	struct FString                                     Text;                                             		// 0x000000 (0x000C)              
	//int                                                I;                                                		// 0x00000C (0x0004)              
	//struct FString                                     S;                                                		// 0x000010 (0x000C)              
};

void AWebConnection::ReceivedText(struct FString Text)
{
	static UFieldFunc* pFnReceivedText = NULL;
	if(!pFnReceivedText)
		pFnReceivedText = UObject::FindFunction("Function IpDrv.WebConnection.ReceivedText");

	IpDrv_ReceivedText_Parms ReceivedText_Parms;
	memcpy(&ReceivedText_Parms.Text,&Text,0xC);
	ProcessEvent(pFnReceivedText,NULL,&ReceivedText_Parms,NULL);
}

struct IpDrv_IsHanging_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool AWebConnection::IsHanging()
{
	static UFieldFunc* pFnIsHanging = NULL;
	if(!pFnIsHanging)
		pFnIsHanging = UObject::FindFunction("Function IpDrv.WebConnection.IsHanging");

	IpDrv_IsHanging_Parms IsHanging_Parms;
	ProcessEvent(pFnIsHanging,NULL,&IsHanging_Parms,NULL);
	return IsHanging_Parms.ReturnValue;
}

struct IpDrv_CreateResponseObject_Parms
{
	//int                                                I;                                                		// 0x000000 (0x0004)              
};

void AWebConnection::CreateResponseObject()
{
	static UFieldFunc* pFnCreateResponseObject = NULL;
	if(!pFnCreateResponseObject)
		pFnCreateResponseObject = UObject::FindFunction("Function IpDrv.WebConnection.CreateResponseObject");

	IpDrv_CreateResponseObject_Parms CreateResponseObject_Parms;
	ProcessEvent(pFnCreateResponseObject,NULL,&CreateResponseObject_Parms,NULL);
}

struct IpDrv_Timer_Parms
{
};

void AWebConnection::Timer()
{
	static UFieldFunc* pFnTimer = NULL;
	if(!pFnTimer)
		pFnTimer = UObject::FindFunction("Function IpDrv.WebConnection.Timer");

	IpDrv_Timer_Parms Timer_Parms;
	ProcessEvent(pFnTimer,NULL,&Timer_Parms,NULL);
}

struct IpDrv_PostBeginPlay_Parms
{
	//int                                                I;                                                		// 0x000000 (0x0004)              
	//class UClass*                                      ApplicationClass;                                 		// 0x000004 (0x0004)              
	//struct FIpAddr                                     L;                                                		// 0x000008 (0x0008)              
	//struct FString                                     S;                                                		// 0x000010 (0x000C)              
};

void AWebServer::PostBeginPlay()
{
	static UFieldFunc* pFnPostBeginPlay = NULL;
	if(!pFnPostBeginPlay)
		pFnPostBeginPlay = UObject::FindFunction("Function IpDrv.WebServer.PostBeginPlay");

	IpDrv_PostBeginPlay_Parms PostBeginPlay_Parms;
	ProcessEvent(pFnPostBeginPlay,NULL,&PostBeginPlay_Parms,NULL);
}

struct IpDrv_GainedChild_Parms
{
	class AActor*                                      C;                                                		// 0x000000 (0x0004)              
};

void AWebServer::GainedChild(class AActor* C)
{
	static UFieldFunc* pFnGainedChild = NULL;
	if(!pFnGainedChild)
		pFnGainedChild = UObject::FindFunction("Function IpDrv.WebServer.GainedChild");

	IpDrv_GainedChild_Parms GainedChild_Parms;
	GainedChild_Parms.C = C;
	ProcessEvent(pFnGainedChild,NULL,&GainedChild_Parms,NULL);
}

struct IpDrv_LostChild_Parms
{
	class AActor*                                      C;                                                		// 0x000000 (0x0004)              
};

void AWebServer::LostChild(class AActor* C)
{
	static UFieldFunc* pFnLostChild = NULL;
	if(!pFnLostChild)
		pFnLostChild = UObject::FindFunction("Function IpDrv.WebServer.LostChild");

	IpDrv_LostChild_Parms LostChild_Parms;
	LostChild_Parms.C = C;
	ProcessEvent(pFnLostChild,NULL,&LostChild_Parms,NULL);
}

struct IpDrv_GetApplication_Parms
{
	struct FString                                     URI;                                              		// 0x000000 (0x000C)              
	struct FString                                     SubURI;                                           		// 0x00000C (0x000C)              
	class UWebApplication*                             ReturnValue;                                      		// 0x000018 (0x0004)              
	//int                                                I;                                                		// 0x00001C (0x0004)              
	//int                                                L;                                                		// 0x000020 (0x0004)              
};

class UWebApplication* AWebServer::GetApplication(struct FString URI,struct FString* SubURI)
{
	static UFieldFunc* pFnGetApplication = NULL;
	if(!pFnGetApplication)
		pFnGetApplication = UObject::FindFunction("Function IpDrv.WebServer.GetApplication");

	IpDrv_GetApplication_Parms GetApplication_Parms;
	memcpy(&GetApplication_Parms.URI,&URI,0xC);
	ProcessEvent(pFnGetApplication,NULL,&GetApplication_Parms,NULL);
	if(SubURI)
		memcpy(SubURI,&GetApplication_Parms.SubURI,0xC);
	return GetApplication_Parms.ReturnValue;
}

struct IpDrv_Destroyed_Parms
{
	//int                                                I;                                                		// 0x000000 (0x0004)              
};

void AWebServer::Destroyed()
{
	static UFieldFunc* pFnDestroyed = NULL;
	if(!pFnDestroyed)
		pFnDestroyed = UObject::FindFunction("Function IpDrv.WebServer.Destroyed");

	IpDrv_Destroyed_Parms Destroyed_Parms;
	ProcessEvent(pFnDestroyed,NULL,&Destroyed_Parms,NULL);
}
