
/*
-----------------------------------------------------------------
 - UEnum
-----------------------------------------------------------------
*/
enum ELinkMode
{
	MODE_Text = 0,
	MODE_Line = 1,
	MODE_Binary = 2,
	MODE_MAX = 3,
};
enum ELineMode
{
	LMODE_auto = 0,
	LMODE_DOS = 1,
	LMODE_UNIX = 2,
	LMODE_MAC = 3,
	LMODE_MAX = 4,
};
enum EReceiveMode
{
	RMODE_Manual = 0,
	RMODE_Event = 1,
	RMODE_MAX = 2,
};
enum ELinkState
{
	STATE_Initialized = 0,
	STATE_Ready = 1,
	STATE_Listening = 2,
	STATE_Connecting = 3,
	STATE_Connected = 4,
	STATE_ListenClosePending = 5,
	STATE_ConnectClosePending = 6,
	STATE_ListenClosing = 7,
	STATE_ConnectClosing = 8,
	STATE_MAX = 9,
};
enum EMeshBeaconPacketType
{
	MB_Packet_UnknownType = 0,
	MB_Packet_ClientNewConnectionRequest = 1,
	MB_Packet_ClientBeginBandwidthTest = 2,
	MB_Packet_ClientCreateNewSessionResponse = 3,
	MB_Packet_HostNewConnectionResponse = 4,
	MB_Packet_HostBandwidthTestRequest = 5,
	MB_Packet_HostCompletedBandwidthTest = 6,
	MB_Packet_HostTravelRequest = 7,
	MB_Packet_HostCreateNewSessionRequest = 8,
	MB_Packet_DummyData = 9,
	MB_Packet_Heartbeat = 10,
	MB_Packet_MAX = 11,
};
enum EMeshBeaconConnectionResult
{
	MB_ConnectionResult_Succeeded = 0,
	MB_ConnectionResult_Duplicate = 1,
	MB_ConnectionResult_Timeout = 2,
	MB_ConnectionResult_Error = 3,
	MB_ConnectionResult_MAX = 4,
};
enum EMeshBeaconBandwidthTestState
{
	MB_BandwidthTestState_NotStarted = 0,
	MB_BandwidthTestState_RequestPending = 1,
	MB_BandwidthTestState_StartPending = 2,
	MB_BandwidthTestState_InProgress = 3,
	MB_BandwidthTestState_Completed = 4,
	MB_BandwidthTestState_Incomplete = 5,
	MB_BandwidthTestState_Timeout = 6,
	MB_BandwidthTestState_Error = 7,
	MB_BandwidthTestState_MAX = 8,
};
enum EMeshBeaconBandwidthTestResult
{
	MB_BandwidthTestResult_Succeeded = 0,
	MB_BandwidthTestResult_Timeout = 1,
	MB_BandwidthTestResult_Error = 2,
	MB_BandwidthTestResult_MAX = 3,
};
enum EMeshBeaconBandwidthTestType
{
	MB_BandwidthTestType_Upstream = 0,
	MB_BandwidthTestType_Downstream = 1,
	MB_BandwidthTestType_RoundtripLatency = 2,
	MB_BandwidthTestType_MAX = 3,
};
enum EMeshBeaconClientState
{
	MBCS_None = 0,
	MBCS_Connecting = 1,
	MBCS_Connected = 2,
	MBCS_ConnectionFailed = 3,
	MBCS_AwaitingResponse = 4,
	MBCS_Closed = 5,
	MBCS_MAX = 6,
};
enum EReservationPacketType
{
	RPT_UnknownPacketType = 0,
	RPT_ClientReservationRequest = 1,
	RPT_ClientReservationUpdateRequest = 2,
	RPT_ClientCancellationRequest = 3,
	RPT_HostReservationResponse = 4,
	RPT_HostReservationCountUpdate = 5,
	RPT_HostTravelRequest = 6,
	RPT_HostIsReady = 7,
	RPT_HostHasCancelled = 8,
	RPT_Heartbeat = 9,
	RPT_MAX = 10,
};
enum EPartyReservationResult
{
	PRR_GeneralError = 0,
	PRR_PartyLimitReached = 1,
	PRR_IncorrectPlayerCount = 2,
	PRR_RequestTimedOut = 3,
	PRR_ReservationDuplicate = 4,
	PRR_ReservationNotFound = 5,
	PRR_ReservationAccepted = 6,
	PRR_ReservationDenied = 7,
	PRR_MAX = 8,
};
enum EPartyBeaconClientState
{
	PBCS_None = 0,
	PBCS_Connecting = 1,
	PBCS_Connected = 2,
	PBCS_ConnectionFailed = 3,
	PBCS_AwaitingResponse = 4,
	PBCS_Closed = 5,
	PBCS_MAX = 6,
};
enum EPartyBeaconClientRequest
{
	PBClientRequest_NewReservation = 0,
	PBClientRequest_UpdateReservation = 1,
	PBClientRequest_MAX = 2,
};
enum EPartyBeaconHostState
{
	PBHS_AllowReservations = 0,
	PBHS_DenyReservations = 1,
	PBHS_MAX = 2,
};
enum ERequestType
{
	Request_GET = 0,
	Request_POST = 1,
	Request_MAX = 2,
};

/*
-----------------------------------------------------------------
 - Structs
-----------------------------------------------------------------
*/
//0x000008
//IpAddr[0x1D0959C8]
struct FIpAddr
{
	int                                                Addr;                                             		// 0x000000 (0x0004)              
	int                                                Port;                                             		// 0x000004 (0x0004)              
};
//0x00000C
//ConnectionBandwidthStats[0x1D095A30]
struct FConnectionBandwidthStats
{
	int                                                UpstreamRate;                                     		// 0x000000 (0x0004)              
	int                                                DownstreamRate;                                   		// 0x000004 (0x0004)              
	int                                                RoundtripLatency;                                 		// 0x000008 (0x0004)              
};
//0x000010
//PlayerMember[0x1D095A98]
struct FPlayerMember
{
	int                                                TeamNum;                                          		// 0x000000 (0x0004)              
	int                                                Skill;                                            		// 0x000004 (0x0004)              
	struct FUniqueNetId                                NetId;                                            		// 0x000008 (0x0008)              
};
//0x000024
//ClientConnectionRequest[0x1D095B00]
struct FClientConnectionRequest
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	unsigned char                                      NatType;                                          		// 0x000008 (0x0001)              PROPERTY: ENATType
	unsigned char                                      _0x000009[0x3];                                   		// 0x000009 (0x0003) MISSED OFFSET
	unsigned long                                      bCanHostVs : 1;                                   		// 0x00000C (0x0004) [0x00000001] 
	float                                              GoodHostRatio;                                    		// 0x000010 (0x0004)              
	TArray<struct FConnectionBandwidthStats>           BandwidthHistory;                                 		// 0x000014 (0x000C)              
	int                                                MinutesSinceLastTest;                             		// 0x000020 (0x0004)              
};
//0x000014
//ClientBandwidthTestData[0x1D095B68]
struct FClientBandwidthTestData
{
	unsigned char                                      TestType;                                         		// 0x000000 (0x0001)              PROPERTY: EMeshBeaconBandwidthTestType
	unsigned char                                      CurrentState;                                     		// 0x000001 (0x0001)              PROPERTY: EMeshBeaconBandwidthTestState
	unsigned char                                      _0x000002[0x2];                                   		// 0x000002 (0x0002) MISSED OFFSET
	int                                                NumBytesToSendTotal;                              		// 0x000004 (0x0004)              
	int                                                NumBytesSentTotal;                                		// 0x000008 (0x0004)              
	int                                                NumBytesSentLast;                                 		// 0x00000C (0x0004)              
	float                                              ElapsedTestTime;                                  		// 0x000010 (0x0004)              
};
//0x000028
//ClientConnectionBandwidthTestData[0x1D095BD0]
struct FClientConnectionBandwidthTestData
{
	unsigned char                                      CurrentState;                                     		// 0x000000 (0x0001)              PROPERTY: EMeshBeaconBandwidthTestState
	unsigned char                                      TestType;                                         		// 0x000001 (0x0001)              PROPERTY: EMeshBeaconBandwidthTestType
	unsigned char                                      _0x000002[0x2];                                   		// 0x000002 (0x0002) MISSED OFFSET
	int                                                BytesTotalNeeded;                                 		// 0x000004 (0x0004)              
	int                                                BytesReceived;                                    		// 0x000008 (0x0004)              
	double                                             RequestTestStartTime;                             		// 0x00000C (0x0008)              
	double                                             TestStartTime;                                    		// 0x000014 (0x0008)              
	struct FConnectionBandwidthStats                   BandwidthStats;                                   		// 0x00001C (0x000C)              
};
//0x000058
//ClientMeshBeaconConnection[0x1D095D08]
struct FClientMeshBeaconConnection
{
	struct FUniqueNetId                                PlayerNetId;                                      		// 0x000000 (0x0008)              
	float                                              ElapsedHeartbeatTime;                             		// 0x000008 (0x0004)              
	DWORD                                              Socket;                                           		// 0x00000C (0x0004)              
	unsigned long                                      bConnectionAccepted : 1;                          		// 0x000010 (0x0004) [0x00000001] 
	struct FClientConnectionBandwidthTestData          BandwidthTest;                                    		// 0x000014 (0x0028)              
	unsigned char                                      NatType;                                          		// 0x00003C (0x0001)              PROPERTY: ENATType
	unsigned char                                      _0x00003D[0x3];                                   		// 0x00003D (0x0003) MISSED OFFSET
	unsigned long                                      bCanHostVs : 1;                                   		// 0x000040 (0x0004) [0x00000001] 
	float                                              GoodHostRatio;                                    		// 0x000044 (0x0004)              
	TArray<struct FConnectionBandwidthStats>           BandwidthHistory;                                 		// 0x000048 (0x000C)              
	int                                                MinutesSinceLastTest;                             		// 0x000054 (0x0004)              
};
//0x000024
//PlayerReservation[0x1D095CA0]
struct FPlayerReservation
{
	struct FUniqueNetId                                NetId;                                            		// 0x000000 (0x0008)              
	int                                                Skill;                                            		// 0x000008 (0x0004)              
	int                                                XpLevel;                                          		// 0x00000C (0x0004)              
	double                                             Mu;                                               		// 0x000010 (0x0008)              
	double                                             Sigma;                                            		// 0x000018 (0x0008)              
	float                                              ElapsedSessionTime;                               		// 0x000020 (0x0004)              
};
//0x000018
//PartyReservation[0x1D095C38]
struct FPartyReservation
{
	int                                                TeamNum;                                          		// 0x000000 (0x0004)              
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000004 (0x0008)              
	TArray<struct FPlayerReservation>                  PartyMembers;                                     		// 0x00000C (0x000C)              
};
//0x000010
//ClientBeaconConnection[0x1D093EF8]
struct FClientBeaconConnection
{
	struct FUniqueNetId                                PartyLeader;                                      		// 0x000000 (0x0008)              
	float                                              ElapsedHeartbeatTime;                             		// 0x000008 (0x0004)              
	DWORD                                              Socket;                                           		// 0x00000C (0x0004)              
};

/*
-----------------------------------------------------------------
 - Classes
-----------------------------------------------------------------
*/
//0x00000C (0x00004C - 0x000040)
//ClientBeaconAddressResolver[0x10358040]
class UClientBeaconAddressResolver : public UObject
{
public:
	int                                                BeaconPort;                                       		// 0x000040 (0x0004)              
	struct FName                                       BeaconName;                                       		// 0x000044 (0x0008)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.ClientBeaconAddressResolver");
		return pClassPointer;
	};
};
UClass* UClientBeaconAddressResolver::pClassPointer = NULL;

//0x000018 (0x000278 - 0x000260)
//InternetLink[0x10357DE0]
class AInternetLink : public AInfo
{
public:
	unsigned char                                      LinkMode;                                         		// 0x000260 (0x0001)              PROPERTY: ELinkMode
	unsigned char                                      InLineMode;                                       		// 0x000261 (0x0001)              PROPERTY: ELineMode
	unsigned char                                      OutLineMode;                                      		// 0x000262 (0x0001)              PROPERTY: ELineMode
	unsigned char                                      ReceiveMode;                                      		// 0x000263 (0x0001)              PROPERTY: EReceiveMode
	DWORD                                              Socket;                                           		// 0x000264 (0x0004)              
	int                                                Port;                                             		// 0x000268 (0x0004)              
	DWORD                                              RemoteSocket;                                     		// 0x00026C (0x0004)              
	DWORD                                              PrivateResolveInfo;                               		// 0x000270 (0x0004)              
	int                                                DataPending;                                      		// 0x000274 (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.InternetLink");
		return pClassPointer;
	};

public:
	bool StringToIpAddr(struct FString str,struct FIpAddr* Addr);//IpDrv.InternetLink.StringToIpAddr
	int GetLastError();//IpDrv.InternetLink.GetLastError
	void ResolveFailed();//IpDrv.InternetLink.ResolveFailed
	struct FString IpAddrToString(struct FIpAddr Arg);//IpDrv.InternetLink.IpAddrToString
	void Resolved(struct FIpAddr Addr);//IpDrv.InternetLink.Resolved
	bool ParseURL(struct FString URL,struct FString* Addr,int* PortNum,struct FString* LevelName,struct FString* EntryName);//IpDrv.InternetLink.ParseURL
	void GetLocalIP(struct FIpAddr* Arg);//IpDrv.InternetLink.GetLocalIP
	void Resolve(struct FString Domain);//IpDrv.InternetLink.Resolve
	bool IsDataPending();//IpDrv.InternetLink.IsDataPending
};
UClass* AInternetLink::pClassPointer = NULL;

//0x000028 (0x0002A0 - 0x000278)
//TcpLink[0x10357CB0]
class ATcpLink : public AInternetLink
{
public:
	unsigned char                                      LinkState;                                        		// 0x000278 (0x0001)              PROPERTY: ELinkState
	unsigned char                                      _0x000279[0x3];                                   		// 0x000279 (0x0003) MISSED OFFSET
	struct FIpAddr                                     RemoteAddr;                                       		// 0x00027C (0x0008)              
	class UClass*                                      AcceptClass;                                      		// 0x000284 (0x0004)              
	TArray<unsigned char>                              SendFIFO;                                         		// 0x000288 (0x000C)              
	struct FString                                     RecvBuf;                                          		// 0x000294 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.TcpLink");
		return pClassPointer;
	};

public:
	bool Open(struct FIpAddr Addr);//IpDrv.TcpLink.Open
	int SendBinary(int Count,unsigned char* B);//IpDrv.TcpLink.SendBinary
	void ReceivedText(struct FString Text);//IpDrv.TcpLink.ReceivedText
	void Opened();//IpDrv.TcpLink.Opened
	void Accepted();//IpDrv.TcpLink.Accepted
	bool Close();//IpDrv.TcpLink.Close
	int SendText(struct FString str);//IpDrv.TcpLink.SendText
	int BindPort(int PortNum,bool bUseNextAvailable);//IpDrv.TcpLink.BindPort
	void ReceivedLine(struct FString Line);//IpDrv.TcpLink.ReceivedLine
	bool Listen();//IpDrv.TcpLink.Listen
	int ReadBinary(int Count,unsigned char* B);//IpDrv.TcpLink.ReadBinary
	void ReceivedBinary(int Count,unsigned char* B);//IpDrv.TcpLink.ReceivedBinary
	void Closed();//IpDrv.TcpLink.Closed
	int ReadText(struct FString* str);//IpDrv.TcpLink.ReadText
	bool IsConnected();//IpDrv.TcpLink.IsConnected
};
UClass* ATcpLink::pClassPointer = NULL;

//0x00003C (0x00007C - 0x000040)
//MeshBeacon[0x10357B80]
class UMeshBeacon : public UObject
{
public:
	DWORD                                              VfTable_FTickableObject;                          		// 0x000040 (0x0004)              
	int                                                MeshBeaconPort;                                   		// 0x000044 (0x0004)              
	DWORD                                              Socket;                                           		// 0x000048 (0x0004)              
	unsigned long                                      bIsInTick : 1;                                    		// 0x00004C (0x0004) [0x00000001] 
	unsigned long                                      bWantsDeferredDestroy : 1;                        		// 0x00004C (0x0004) [0x00000002] 
	unsigned long                                      bShouldTick : 1;                                  		// 0x00004C (0x0004) [0x00000004] 
	float                                              HeartbeatTimeout;                                 		// 0x000050 (0x0004)              
	float                                              ElapsedHeartbeatTime;                             		// 0x000054 (0x0004)              
	struct FName                                       BeaconName;                                       		// 0x000058 (0x0008)              
	int                                                SocketSendBufferSize;                             		// 0x000060 (0x0004)              
	int                                                SocketReceiveBufferSize;                          		// 0x000064 (0x0004)              
	int                                                MaxBandwidthTestBufferSize;                       		// 0x000068 (0x0004)              
	int                                                MinBandwidthTestBufferSize;                       		// 0x00006C (0x0004)              
	float                                              MaxBandwidthTestSendTime;                         		// 0x000070 (0x0004)              
	float                                              MaxBandwidthTestReceiveTime;                      		// 0x000074 (0x0004)              
	int                                                MaxBandwidthHistoryEntries;                       		// 0x000078 (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.MeshBeacon");
		return pClassPointer;
	};

public:
	void DestroyBeacon();//IpDrv.MeshBeacon.DestroyBeacon
};
UClass* UMeshBeacon::pClassPointer = NULL;

//0x0000A0 (0x00011C - 0x00007C)
//MeshBeaconClient[0x10357A50]
class UMeshBeaconClient : public UMeshBeacon
{
public:
	struct FOnlineGameSearchResult                     HostPendingRequest;                               		// 0x00007C (0x0008)              
	struct FClientConnectionRequest                    ClientPendingRequest;                             		// 0x000084 (0x0024)              
	struct FClientBandwidthTestData                    CurrentBandwidthTest;                             		// 0x0000A8 (0x0014)              
	unsigned char                                      ClientBeaconState;                                		// 0x0000BC (0x0001)              PROPERTY: EMeshBeaconClientState
	unsigned char                                      ClientBeaconRequestType;                          		// 0x0000BD (0x0001)              PROPERTY: EMeshBeaconPacketType
	unsigned char                                      _0x0000BE[0x2];                                   		// 0x0000BE (0x0002) MISSED OFFSET
	float                                              ConnectionRequestTimeout;                         		// 0x0000C0 (0x0004)              
	float                                              ConnectionRequestElapsedTime;                     		// 0x0000C4 (0x0004)              
	struct FString                                     ResolverClassName;                                		// 0x0000C8 (0x000C)              
	class UClass*                                      ResolverClass;                                    		// 0x0000D4 (0x0004)              
	class UClientBeaconAddressResolver*                Resolver;                                         		// 0x0000D8 (0x0004)              
	unsigned long                                      bUsingRegisteredAddr : 1;                         		// 0x0000DC (0x0004) [0x00000001] 
	struct FScriptDelegate                             __OnConnectionRequestResult__Delegate;            		// 0x0000E0 (0x000C)              
	struct FScriptDelegate                             __OnReceivedBandwidthTestRequest__Delegate;       		// 0x0000EC (0x000C)              
	struct FScriptDelegate                             __OnReceivedBandwidthTestResults__Delegate;       		// 0x0000F8 (0x000C)              
	struct FScriptDelegate                             __OnTravelRequestReceived__Delegate;              		// 0x000104 (0x000C)              
	struct FScriptDelegate                             __OnCreateNewSessionRequestReceived__Delegate;    		// 0x000110 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.MeshBeaconClient");
		return pClassPointer;
	};

public:
	void OnConnectionRequestResult(unsigned char ConnectionResult);//IpDrv.MeshBeaconClient.OnConnectionRequestResult
	bool RequestConnection(struct FOnlineGameSearchResult* DesiredHost,struct FClientConnectionRequest* ClientRequest,bool bRegisterSecureAddress);//IpDrv.MeshBeaconClient.RequestConnection
	void OnCreateNewSessionRequestReceived(struct FName SessionName,class UClass* SearchClass,TArray<struct FPlayerMember>* Players);//IpDrv.MeshBeaconClient.OnCreateNewSessionRequestReceived
	void OnTravelRequestReceived(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo);//IpDrv.MeshBeaconClient.OnTravelRequestReceived
	bool SendHostNewGameSessionResponse(bool bSuccess,struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo);//IpDrv.MeshBeaconClient.SendHostNewGameSessionResponse
	void DebugRender(class UCanvas* Canvas);//IpDrv.MeshBeaconClient.DebugRender
	bool BeginBandwidthTest(unsigned char TestType,int TestBufferSize);//IpDrv.MeshBeaconClient.BeginBandwidthTest
	void DestroyBeacon();//IpDrv.MeshBeaconClient.DestroyBeacon
	void OnReceivedBandwidthTestResults(unsigned char TestType,unsigned char TestResult,struct FConnectionBandwidthStats* BandwidthStats);//IpDrv.MeshBeaconClient.OnReceivedBandwidthTestResults
	void DumpInfo();//IpDrv.MeshBeaconClient.DumpInfo
	void OnReceivedBandwidthTestRequest(unsigned char TestType);//IpDrv.MeshBeaconClient.OnReceivedBandwidthTestRequest
};
UClass* UMeshBeaconClient::pClassPointer = NULL;

//0x000064 (0x0000E0 - 0x00007C)
//MeshBeaconHost[0x10357920]
class UMeshBeaconHost : public UMeshBeacon
{
public:
	TArray<struct FClientMeshBeaconConnection>         ClientConnections;                                		// 0x00007C (0x000C)              
	TArray<struct FUniqueNetId>                        PendingPlayerConnections;                         		// 0x000088 (0x000C)              
	struct FUniqueNetId                                OwningPlayerId;                                   		// 0x000094 (0x0008)              
	unsigned long                                      bAllowBandwidthTesting : 1;                       		// 0x00009C (0x0004) [0x00000001] 
	int                                                ConnectionBacklog;                                		// 0x0000A0 (0x0004)              
	struct FScriptDelegate                             __OnReceivedClientConnectionRequest__Delegate;    		// 0x0000A4 (0x000C)              
	struct FScriptDelegate                             __OnStartedBandwidthTest__Delegate;               		// 0x0000B0 (0x000C)              
	struct FScriptDelegate                             __OnFinishedBandwidthTest__Delegate;              		// 0x0000BC (0x000C)              
	struct FScriptDelegate                             __OnAllPendingPlayersConnected__Delegate;         		// 0x0000C8 (0x000C)              
	struct FScriptDelegate                             __OnReceivedClientCreateNewSessionResult__Delegate;		// 0x0000D4 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.MeshBeaconHost");
		return pClassPointer;
	};

public:
	void OnReceivedClientConnectionRequest(struct FClientMeshBeaconConnection* NewClientConnection);//IpDrv.MeshBeaconHost.OnReceivedClientConnectionRequest
	bool HasInProgressBandwidthTest();//IpDrv.MeshBeaconHost.HasInProgressBandwidthTest
	void CancelPendingBandwidthTests();//IpDrv.MeshBeaconHost.CancelPendingBandwidthTests
	void DebugRender(class UCanvas* Canvas,struct FUniqueNetId CurOptimalHostId);//IpDrv.MeshBeaconHost.DebugRender
	bool RequestClientBandwidthTest(struct FUniqueNetId PlayerNetId,unsigned char TestType,int TestBufferSize);//IpDrv.MeshBeaconHost.RequestClientBandwidthTest
	void DestroyBeacon();//IpDrv.MeshBeaconHost.DestroyBeacon
	bool RequestClientCreateNewSession(struct FUniqueNetId PlayerNetId,struct FName SessionName,class UClass* SearchClass,TArray<struct FPlayerMember>* Players);//IpDrv.MeshBeaconHost.RequestClientCreateNewSession
	void DumpConnections();//IpDrv.MeshBeaconHost.DumpConnections
	bool HasPendingBandwidthTest();//IpDrv.MeshBeaconHost.HasPendingBandwidthTest
	int GetConnectionIndexForPlayer(struct FUniqueNetId PlayerNetId);//IpDrv.MeshBeaconHost.GetConnectionIndexForPlayer
	void OnFinishedBandwidthTest(struct FUniqueNetId PlayerNetId,unsigned char TestType,unsigned char TestResult,struct FConnectionBandwidthStats* BandwidthStats);//IpDrv.MeshBeaconHost.OnFinishedBandwidthTest
	void SetPendingPlayerConnections(TArray<struct FUniqueNetId>* Players);//IpDrv.MeshBeaconHost.SetPendingPlayerConnections
	void OnStartedBandwidthTest(struct FUniqueNetId PlayerNetId,unsigned char TestType);//IpDrv.MeshBeaconHost.OnStartedBandwidthTest
	bool InitHostBeacon(struct FUniqueNetId InOwningPlayerId);//IpDrv.MeshBeaconHost.InitHostBeacon
	void CancelInProgressBandwidthTests();//IpDrv.MeshBeaconHost.CancelInProgressBandwidthTests
	void OnAllPendingPlayersConnected();//IpDrv.MeshBeaconHost.OnAllPendingPlayersConnected
	void TellClientsToTravel(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo);//IpDrv.MeshBeaconHost.TellClientsToTravel
	void OnReceivedClientCreateNewSessionResult(bool bSucceeded,struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo);//IpDrv.MeshBeaconHost.OnReceivedClientCreateNewSessionResult
	bool AllPlayersConnected(TArray<struct FUniqueNetId>* Players);//IpDrv.MeshBeaconHost.AllPlayersConnected
	void AllowBandwidthTesting(bool bEnabled);//IpDrv.MeshBeaconHost.AllowBandwidthTesting
};
UClass* UMeshBeaconHost::pClassPointer = NULL;

//0x000014 (0x000110 - 0x0000FC)
//OnlineSubsystemCommonImpl[0x103576C0]
class UOnlineSubsystemCommonImpl : public UOnlineSubsystem
{
public:
	DWORD                                              VoiceEngine;                                      		// 0x0000FC (0x0004)              
	int                                                MaxLocalTalkers;                                  		// 0x000100 (0x0004)              
	int                                                MaxRemoteTalkers;                                 		// 0x000104 (0x0004)              
	unsigned long                                      bIsUsingSpeechRecognition : 1;                    		// 0x000108 (0x0004) [0x00000001] 
	class UOnlineGameInterfaceImpl*                    GameInterfaceImpl;                                		// 0x00010C (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.OnlineSubsystemCommonImpl");
		return pClassPointer;
	};

public:
	void GetRegisteredPlayers(struct FName SessionName,TArray<struct FUniqueNetId>* OutRegisteredPlayers);//IpDrv.OnlineSubsystemCommonImpl.GetRegisteredPlayers
	struct FString GetPlayerNicknameFromIndex(int UserIndex);//IpDrv.OnlineSubsystemCommonImpl.GetPlayerNicknameFromIndex
	bool IsPlayerInSession(struct FName SessionName,struct FUniqueNetId PlayerID);//IpDrv.OnlineSubsystemCommonImpl.IsPlayerInSession
};
UClass* UOnlineSubsystemCommonImpl::pClassPointer = NULL;

//0x000178 (0x0001B8 - 0x000040)
//OnlineGameInterfaceImpl[0x103577F0]
class UOnlineGameInterfaceImpl : public UObject
{
public:
	class UOnlineSubsystemCommonImpl*                  OwningSubsystem;                                  		// 0x000040 (0x0004)              
	class UOnlineGameSettings*                         GameSettings;                                     		// 0x000044 (0x0004)              
	class UOnlineGameSearch*                           GameSearch;                                       		// 0x000048 (0x0004)              
	TArray<struct FScriptDelegate>                     CreateOnlineGameCompleteDelegates;                		// 0x00004C (0x000C)              
	TArray<struct FScriptDelegate>                     UpdateOnlineGameCompleteDelegates;                		// 0x000058 (0x000C)              
	TArray<struct FScriptDelegate>                     DestroyOnlineGameCompleteDelegates;               		// 0x000064 (0x000C)              
	TArray<struct FScriptDelegate>                     JoinOnlineGameCompleteDelegates;                  		// 0x000070 (0x000C)              
	TArray<struct FScriptDelegate>                     MigrateOnlineGameCompleteDelegates;               		// 0x00007C (0x000C)              
	TArray<struct FScriptDelegate>                     JoinMigratedOnlineGameCompleteDelegates;          		// 0x000088 (0x000C)              
	TArray<struct FScriptDelegate>                     RecalculateSkillRatingCompleteDelegates;          		// 0x000094 (0x000C)              
	TArray<struct FScriptDelegate>                     StartOnlineGameCompleteDelegates;                 		// 0x0000A0 (0x000C)              
	TArray<struct FScriptDelegate>                     EndOnlineGameCompleteDelegates;                   		// 0x0000AC (0x000C)              
	TArray<struct FScriptDelegate>                     FindOnlineGamesCompleteDelegates;                 		// 0x0000B8 (0x000C)              
	TArray<struct FScriptDelegate>                     CancelFindOnlineGamesCompleteDelegates;           		// 0x0000C4 (0x000C)              
	unsigned char                                      LanBeaconState;                                   		// 0x0000D0 (0x0001)              PROPERTY: ELanBeaconState
	unsigned char                                      LanNonce[0x8];                                    		// 0x0000D1 (0x0008)              PROPERTY: 
	unsigned char                                      _0x0000D9[0x3];                                   		// 0x0000D9 (0x0003) MISSED OFFSET
	int                                                LanAnnouncePort;                                  		// 0x0000DC (0x0004)              
	int                                                LanGameUniqueId;                                  		// 0x0000E0 (0x0004)              
	int                                                LanPacketPlatformMask;                            		// 0x0000E4 (0x0004)              
	float                                              LanQueryTimeLeft;                                 		// 0x0000E8 (0x0004)              
	float                                              LanQueryTimeout;                                  		// 0x0000EC (0x0004)              
	DWORD                                              LanBeacon;                                        		// 0x0000F0 (0x0004)              
	DWORD                                              SessionInfo;                                      		// 0x0000F4 (0x0004)              
	struct FScriptDelegate                             __OnFindOnlineGamesComplete__Delegate;            		// 0x0000F8 (0x000C)              
	struct FScriptDelegate                             __OnCreateOnlineGameComplete__Delegate;           		// 0x000104 (0x000C)              
	struct FScriptDelegate                             __OnUpdateOnlineGameComplete__Delegate;           		// 0x000110 (0x000C)              
	struct FScriptDelegate                             __OnDestroyOnlineGameComplete__Delegate;          		// 0x00011C (0x000C)              
	struct FScriptDelegate                             __OnCancelFindOnlineGamesComplete__Delegate;      		// 0x000128 (0x000C)              
	struct FScriptDelegate                             __OnJoinOnlineGameComplete__Delegate;             		// 0x000134 (0x000C)              
	struct FScriptDelegate                             __OnRegisterPlayerComplete__Delegate;             		// 0x000140 (0x000C)              
	struct FScriptDelegate                             __OnUnregisterPlayerComplete__Delegate;           		// 0x00014C (0x000C)              
	struct FScriptDelegate                             __OnStartOnlineGameComplete__Delegate;            		// 0x000158 (0x000C)              
	struct FScriptDelegate                             __OnEndOnlineGameComplete__Delegate;              		// 0x000164 (0x000C)              
	struct FScriptDelegate                             __OnArbitrationRegistrationComplete__Delegate;    		// 0x000170 (0x000C)              
	struct FScriptDelegate                             __OnGameInviteAccepted__Delegate;                 		// 0x00017C (0x000C)              
	struct FScriptDelegate                             __OnRecalculateSkillRatingComplete__Delegate;     		// 0x000188 (0x000C)              
	struct FScriptDelegate                             __OnMigrateOnlineGameComplete__Delegate;          		// 0x000194 (0x000C)              
	struct FScriptDelegate                             __OnJoinMigratedOnlineGameComplete__Delegate;     		// 0x0001A0 (0x000C)              
	struct FScriptDelegate                             __OnQosStatusChanged__Delegate;                   		// 0x0001AC (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.OnlineGameInterfaceImpl");
		return pClassPointer;
	};

public:
	void AddRecalculateSkillRatingCompleteDelegate(struct FScriptDelegate RecalculateSkillRatingCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddRecalculateSkillRatingCompleteDelegate
	void AddArbitrationRegistrationCompleteDelegate(struct FScriptDelegate ArbitrationRegistrationCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddArbitrationRegistrationCompleteDelegate
	bool FreeSearchResults(class UOnlineGameSearch* Search);//IpDrv.OnlineGameInterfaceImpl.FreeSearchResults
	void AddGameInviteAcceptedDelegate(unsigned char LocalUserNum,struct FScriptDelegate GameInviteAcceptedDelegate);//IpDrv.OnlineGameInterfaceImpl.AddGameInviteAcceptedDelegate
	void ClearStartOnlineGameCompleteDelegate(struct FScriptDelegate StartOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearStartOnlineGameCompleteDelegate
	bool DestroyOnlineGame(struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.DestroyOnlineGame
	void OnJoinOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnJoinOnlineGameComplete
	void OnRecalculateSkillRatingComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnRecalculateSkillRatingComplete
	void AddDestroyOnlineGameCompleteDelegate(struct FScriptDelegate DestroyOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddDestroyOnlineGameCompleteDelegate
	void OnMigrateOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnMigrateOnlineGameComplete
	class UOnlineGameSearch* GetGameSearch();//IpDrv.OnlineGameInterfaceImpl.GetGameSearch
	class UOnlineGameSettings* GetGameSettings(struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.GetGameSettings
	void AddStartOnlineGameCompleteDelegate(struct FScriptDelegate StartOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddStartOnlineGameCompleteDelegate
	TArray<struct FOnlineArbitrationRegistrant> GetArbitratedPlayers(struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.GetArbitratedPlayers
	bool QueryNonAdvertisedData(int StartAt,int NumberToQuery);//IpDrv.OnlineGameInterfaceImpl.QueryNonAdvertisedData
	void OnQosStatusChanged(int NumComplete,int NumTotal);//IpDrv.OnlineGameInterfaceImpl.OnQosStatusChanged
	void AddRegisterPlayerCompleteDelegate(struct FScriptDelegate RegisterPlayerCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddRegisterPlayerCompleteDelegate
	void ClearFindOnlineGamesCompleteDelegate(struct FScriptDelegate FindOnlineGamesCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearFindOnlineGamesCompleteDelegate
	void AddQosStatusChangedDelegate(struct FScriptDelegate QosStatusChangedDelegate);//IpDrv.OnlineGameInterfaceImpl.AddQosStatusChangedDelegate
	bool UnregisterPlayers(struct FName SessionName,TArray<struct FUniqueNetId>* Players);//IpDrv.OnlineGameInterfaceImpl.UnregisterPlayers
	bool JoinMigratedOnlineGame(unsigned char PlayerNum,struct FName SessionName,struct FOnlineGameSearchResult* DesiredGame);//IpDrv.OnlineGameInterfaceImpl.JoinMigratedOnlineGame
	bool RegisterPlayers(struct FName SessionName,TArray<struct FUniqueNetId>* Players);//IpDrv.OnlineGameInterfaceImpl.RegisterPlayers
	void OnCancelFindOnlineGamesComplete(bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnCancelFindOnlineGamesComplete
	void AddJoinMigratedOnlineGameCompleteDelegate(struct FScriptDelegate JoinMigratedOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddJoinMigratedOnlineGameCompleteDelegate
	bool MigrateOnlineGame(unsigned char HostingPlayerNum,struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.MigrateOnlineGame
	void ClearQosStatusChangedDelegate(struct FScriptDelegate QosStatusChangedDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearQosStatusChangedDelegate
	bool GetResolvedConnectString(struct FName SessionName,struct FString* ConnectInfo);//IpDrv.OnlineGameInterfaceImpl.GetResolvedConnectString
	void AddFindOnlineGamesCompleteDelegate(struct FScriptDelegate FindOnlineGamesCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddFindOnlineGamesCompleteDelegate
	bool UnregisterPlayer(struct FName SessionName,struct FUniqueNetId PlayerID);//IpDrv.OnlineGameInterfaceImpl.UnregisterPlayer
	bool UpdateOnlineGame(struct FName SessionName,class UOnlineGameSettings* UpdatedGameSettings,bool bShouldRefreshOnlineData);//IpDrv.OnlineGameInterfaceImpl.UpdateOnlineGame
	bool ReadPlatformSpecificSessionInfo(struct FOnlineGameSearchResult* DesiredGame,unsigned char* PlatformSpecificInfo);//IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfo
	bool StartOnlineGame(struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.StartOnlineGame
	bool RegisterPlayer(struct FName SessionName,struct FUniqueNetId PlayerID,bool bWasInvited);//IpDrv.OnlineGameInterfaceImpl.RegisterPlayer
	void ClearGameInviteAcceptedDelegate(unsigned char LocalUserNum,struct FScriptDelegate GameInviteAcceptedDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearGameInviteAcceptedDelegate
	void ClearRecalculateSkillRatingCompleteDelegate(struct FScriptDelegate RecalculateSkillRatingGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearRecalculateSkillRatingCompleteDelegate
	void ClearUpdateOnlineGameCompleteDelegate(struct FScriptDelegate UpdateOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearUpdateOnlineGameCompleteDelegate
	void OnUpdateOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnUpdateOnlineGameComplete
	void ClearEndOnlineGameCompleteDelegate(struct FScriptDelegate EndOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearEndOnlineGameCompleteDelegate
	bool BindPlatformSpecificSessionToSearch(unsigned char SearchingPlayerNum,class UOnlineGameSearch* SearchSettings,unsigned char* PlatformSpecificInfo);//IpDrv.OnlineGameInterfaceImpl.BindPlatformSpecificSessionToSearch
	void ClearCancelFindOnlineGamesCompleteDelegate(struct FScriptDelegate CancelFindOnlineGamesCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearCancelFindOnlineGamesCompleteDelegate
	bool FindOnlineGames(unsigned char SearchingPlayerNum,class UOnlineGameSearch* SearchSettings);//IpDrv.OnlineGameInterfaceImpl.FindOnlineGames
	bool RegisterForArbitration(struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.RegisterForArbitration
	void OnGameInviteAccepted(struct FOnlineGameSearchResult* InviteResult);//IpDrv.OnlineGameInterfaceImpl.OnGameInviteAccepted
	void OnArbitrationRegistrationComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnArbitrationRegistrationComplete
	void OnFindOnlineGamesComplete(bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnFindOnlineGamesComplete
	bool ReadPlatformSpecificSessionInfoBySessionName(struct FName SessionName,unsigned char* PlatformSpecificInfo);//IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfoBySessionName
	bool AcceptGameInvite(unsigned char LocalUserNum,struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.AcceptGameInvite
	void ClearArbitrationRegistrationCompleteDelegate(struct FScriptDelegate ArbitrationRegistrationCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearArbitrationRegistrationCompleteDelegate
	bool RecalculateSkillRating(struct FName SessionName,TArray<struct FUniqueNetId>* Players);//IpDrv.OnlineGameInterfaceImpl.RecalculateSkillRating
	void OnCreateOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnCreateOnlineGameComplete
	void OnJoinMigratedOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnJoinMigratedOnlineGameComplete
	bool CreateOnlineGame(unsigned char HostingPlayerNum,struct FName SessionName,class UOnlineGameSettings* NewGameSettings);//IpDrv.OnlineGameInterfaceImpl.CreateOnlineGame
	void AddUnregisterPlayerCompleteDelegate(struct FScriptDelegate UnregisterPlayerCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddUnregisterPlayerCompleteDelegate
	void AddEndOnlineGameCompleteDelegate(struct FScriptDelegate EndOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddEndOnlineGameCompleteDelegate
	void OnUnregisterPlayerComplete(struct FName SessionName,struct FUniqueNetId PlayerID,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnUnregisterPlayerComplete
	void OnStartOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnStartOnlineGameComplete
	void AddUpdateOnlineGameCompleteDelegate(struct FScriptDelegate UpdateOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddUpdateOnlineGameCompleteDelegate
	void ClearJoinMigratedOnlineGameCompleteDelegate(struct FScriptDelegate JoinMigratedOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearJoinMigratedOnlineGameCompleteDelegate
	bool CancelFindOnlineGames();//IpDrv.OnlineGameInterfaceImpl.CancelFindOnlineGames
	bool EndOnlineGame(struct FName SessionName);//IpDrv.OnlineGameInterfaceImpl.EndOnlineGame
	void AddCreateOnlineGameCompleteDelegate(struct FScriptDelegate CreateOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddCreateOnlineGameCompleteDelegate
	void OnEndOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnEndOnlineGameComplete
	void AddMigrateOnlineGameCompleteDelegate(struct FScriptDelegate MigrateOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddMigrateOnlineGameCompleteDelegate
	void AddCancelFindOnlineGamesCompleteDelegate(struct FScriptDelegate CancelFindOnlineGamesCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddCancelFindOnlineGamesCompleteDelegate
	void ClearCreateOnlineGameCompleteDelegate(struct FScriptDelegate CreateOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearCreateOnlineGameCompleteDelegate
	void ClearUnregisterPlayerCompleteDelegate(struct FScriptDelegate UnregisterPlayerCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearUnregisterPlayerCompleteDelegate
	void AddJoinOnlineGameCompleteDelegate(struct FScriptDelegate JoinOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.AddJoinOnlineGameCompleteDelegate
	void OnRegisterPlayerComplete(struct FName SessionName,struct FUniqueNetId PlayerID,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnRegisterPlayerComplete
	void ClearMigrateOnlineGameCompleteDelegate(struct FScriptDelegate MigrateOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearMigrateOnlineGameCompleteDelegate
	void ClearRegisterPlayerCompleteDelegate(struct FScriptDelegate RegisterPlayerCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearRegisterPlayerCompleteDelegate
	void ClearJoinOnlineGameCompleteDelegate(struct FScriptDelegate JoinOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearJoinOnlineGameCompleteDelegate
	bool JoinOnlineGame(unsigned char PlayerNum,struct FName SessionName,struct FOnlineGameSearchResult* DesiredGame);//IpDrv.OnlineGameInterfaceImpl.JoinOnlineGame
	void ClearDestroyOnlineGameCompleteDelegate(struct FScriptDelegate DestroyOnlineGameCompleteDelegate);//IpDrv.OnlineGameInterfaceImpl.ClearDestroyOnlineGameCompleteDelegate
	void OnDestroyOnlineGameComplete(struct FName SessionName,bool bWasSuccessful);//IpDrv.OnlineGameInterfaceImpl.OnDestroyOnlineGameComplete
};
UClass* UOnlineGameInterfaceImpl::pClassPointer = NULL;

//0x00002C (0x00006C - 0x000040)
//PartyBeacon[0x10357590]
class UPartyBeacon : public UObject
{
public:
	DWORD                                              VfTable_FTickableObject;                          		// 0x000040 (0x0004)              
	int                                                PartyBeaconPort;                                  		// 0x000044 (0x0004)              
	DWORD                                              Socket;                                           		// 0x000048 (0x0004)              
	unsigned long                                      bIsInTick : 1;                                    		// 0x00004C (0x0004) [0x00000001] 
	unsigned long                                      bWantsDeferredDestroy : 1;                        		// 0x00004C (0x0004) [0x00000002] 
	unsigned long                                      bShouldTick : 1;                                  		// 0x00004C (0x0004) [0x00000004] 
	float                                              HeartbeatTimeout;                                 		// 0x000050 (0x0004)              
	float                                              ElapsedHeartbeatTime;                             		// 0x000054 (0x0004)              
	struct FName                                       BeaconName;                                       		// 0x000058 (0x0008)              
	struct FScriptDelegate                             __OnDestroyComplete__Delegate;                    		// 0x000060 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.PartyBeacon");
		return pClassPointer;
	};

public:
	void DestroyBeacon();//IpDrv.PartyBeacon.DestroyBeacon
	void OnDestroyComplete();//IpDrv.PartyBeacon.OnDestroyComplete
};
UClass* UPartyBeacon::pClassPointer = NULL;

//0x00007C (0x0000E8 - 0x00006C)
//PartyBeaconClient[0x10357460]
class UPartyBeaconClient : public UPartyBeacon
{
public:
	struct FOnlineGameSearchResult                     HostPendingRequest;                               		// 0x00006C (0x0008)              
	struct FPartyReservation                           PendingRequest;                                   		// 0x000074 (0x0018)              
	unsigned char                                      ClientBeaconState;                                		// 0x00008C (0x0001)              PROPERTY: EPartyBeaconClientState
	unsigned char                                      ClientBeaconRequestType;                          		// 0x00008D (0x0001)              PROPERTY: EPartyBeaconClientRequest
	unsigned char                                      _0x00008E[0x2];                                   		// 0x00008E (0x0002) MISSED OFFSET
	float                                              ReservationRequestTimeout;                        		// 0x000090 (0x0004)              
	float                                              ReservationRequestElapsedTime;                    		// 0x000094 (0x0004)              
	struct FString                                     ResolverClassName;                                		// 0x000098 (0x000C)              
	class UClass*                                      ResolverClass;                                    		// 0x0000A4 (0x0004)              
	class UClientBeaconAddressResolver*                Resolver;                                         		// 0x0000A8 (0x0004)              
	struct FScriptDelegate                             __OnReservationRequestComplete__Delegate;         		// 0x0000AC (0x000C)              
	struct FScriptDelegate                             __OnReservationCountUpdated__Delegate;            		// 0x0000B8 (0x000C)              
	struct FScriptDelegate                             __OnTravelRequestReceived__Delegate;              		// 0x0000C4 (0x000C)              
	struct FScriptDelegate                             __OnHostIsReady__Delegate;                        		// 0x0000D0 (0x000C)              
	struct FScriptDelegate                             __OnHostHasCancelled__Delegate;                   		// 0x0000DC (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.PartyBeaconClient");
		return pClassPointer;
	};

public:
	void OnHostHasCancelled();//IpDrv.PartyBeaconClient.OnHostHasCancelled
	void OnTravelRequestReceived(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo);//IpDrv.PartyBeaconClient.OnTravelRequestReceived
	void OnHostIsReady();//IpDrv.PartyBeaconClient.OnHostIsReady
	void OnReservationRequestComplete(unsigned char ReservationResult);//IpDrv.PartyBeaconClient.OnReservationRequestComplete
	bool CancelReservation(struct FUniqueNetId CancellingPartyLeader);//IpDrv.PartyBeaconClient.CancelReservation
	bool RequestReservation(struct FOnlineGameSearchResult* DesiredHost,struct FUniqueNetId RequestingPartyLeader,TArray<struct FPlayerReservation>* Players);//IpDrv.PartyBeaconClient.RequestReservation
	void OnReservationCountUpdated(int ReservationRemaining);//IpDrv.PartyBeaconClient.OnReservationCountUpdated
	bool RequestReservationUpdate(struct FOnlineGameSearchResult* DesiredHost,struct FUniqueNetId RequestingPartyLeader,TArray<struct FPlayerReservation>* PlayersToAdd);//IpDrv.PartyBeaconClient.RequestReservationUpdate
	void DestroyBeacon();//IpDrv.PartyBeaconClient.DestroyBeacon
};
UClass* UPartyBeaconClient::pClassPointer = NULL;

//0x000068 (0x0000D4 - 0x00006C)
//PartyBeaconHost[0x10357330]
class UPartyBeaconHost : public UPartyBeacon
{
public:
	TArray<struct FClientBeaconConnection>             Clients;                                          		// 0x00006C (0x000C)              
	int                                                NumTeams;                                         		// 0x000078 (0x0004)              
	int                                                NumPlayersPerTeam;                                		// 0x00007C (0x0004)              
	int                                                NumReservations;                                  		// 0x000080 (0x0004)              
	int                                                NumConsumedReservations;                          		// 0x000084 (0x0004)              
	TArray<struct FPartyReservation>                   Reservations;                                     		// 0x000088 (0x000C)              
	struct FName                                       OnlineSessionName;                                		// 0x000094 (0x0008)              
	int                                                ConnectionBacklog;                                		// 0x00009C (0x0004)              
	int                                                ForceTeamNum;                                     		// 0x0000A0 (0x0004)              
	int                                                ReservedHostTeamNum;                              		// 0x0000A4 (0x0004)              
	unsigned long                                      bBestFitTeamAssignment : 1;                       		// 0x0000A8 (0x0004) [0x00000001] 
	unsigned char                                      BeaconState;                                      		// 0x0000AC (0x0001)              PROPERTY: EPartyBeaconHostState
	unsigned char                                      _0x0000AD[0x3];                                   		// 0x0000AD (0x0003) MISSED OFFSET
	struct FScriptDelegate                             __OnReservationChange__Delegate;                  		// 0x0000B0 (0x000C)              
	struct FScriptDelegate                             __OnReservationsFull__Delegate;                   		// 0x0000BC (0x000C)              
	struct FScriptDelegate                             __OnClientCancellationReceived__Delegate;         		// 0x0000C8 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.PartyBeaconHost");
		return pClassPointer;
	};

public:
	bool InitHostBeacon(int InNumTeams,int InNumPlayersPerTeam,int InNumReservations,struct FName InSessionName,int InForceTeamNum);//IpDrv.PartyBeaconHost.InitHostBeacon
	void TellClientsToTravel(struct FName SessionName,class UClass* SearchClass,unsigned char* PlatformSpecificInfo);//IpDrv.PartyBeaconHost.TellClientsToTravel
	void TellClientsHostHasCancelled();//IpDrv.PartyBeaconHost.TellClientsHostHasCancelled
	unsigned char AddPartyReservationEntry(struct FUniqueNetId PartyLeader,TArray<struct FPlayerReservation>* PlayerMembers,int TeamNum,bool bIsHost);//IpDrv.PartyBeaconHost.AddPartyReservationEntry
	void UnregisterPartyMembers();//IpDrv.PartyBeaconHost.UnregisterPartyMembers
	void AppendReservationSkillsToSearch(class UOnlineGameSearch* Search);//IpDrv.PartyBeaconHost.AppendReservationSkillsToSearch
	bool AreReservationsFull();//IpDrv.PartyBeaconHost.AreReservationsFull
	void RegisterPartyMembers();//IpDrv.PartyBeaconHost.RegisterPartyMembers
	unsigned char UpdatePartyReservationEntry(struct FUniqueNetId PartyLeader,TArray<struct FPlayerReservation>* PlayerMembers);//IpDrv.PartyBeaconHost.UpdatePartyReservationEntry
	void TellClientsHostIsReady();//IpDrv.PartyBeaconHost.TellClientsHostIsReady
	void PauseReservationRequests(bool bPause);//IpDrv.PartyBeaconHost.PauseReservationRequests
	void DumpReservations();//IpDrv.PartyBeaconHost.DumpReservations
	void OnClientCancellationReceived(struct FUniqueNetId PartyLeader);//IpDrv.PartyBeaconHost.OnClientCancellationReceived
	void HandlePlayerLogout(struct FUniqueNetId PlayerID,bool bMaintainParty);//IpDrv.PartyBeaconHost.HandlePlayerLogout
	void GetPartyLeaders(TArray<struct FUniqueNetId>* PartyLeaders);//IpDrv.PartyBeaconHost.GetPartyLeaders
	void UnregisterParty(struct FUniqueNetId PartyLeader);//IpDrv.PartyBeaconHost.UnregisterParty
	int GetMaxAvailableTeamSize();//IpDrv.PartyBeaconHost.GetMaxAvailableTeamSize
	void OnReservationsFull();//IpDrv.PartyBeaconHost.OnReservationsFull
	void GetPlayers(TArray<struct FUniqueNetId>* Players);//IpDrv.PartyBeaconHost.GetPlayers
	void OnReservationChange();//IpDrv.PartyBeaconHost.OnReservationChange
	int GetExistingReservation(struct FUniqueNetId* PartyLeader);//IpDrv.PartyBeaconHost.GetExistingReservation
	void DestroyBeacon();//IpDrv.PartyBeaconHost.DestroyBeacon
};
UClass* UPartyBeaconHost::pClassPointer = NULL;

//0x0000BC (0x0000FC - 0x000040)
//WebRequest[0x10356FA0]
class UWebRequest : public UObject
{
public:
	struct FString                                     RemoteAddr;                                       		// 0x000040 (0x000C)              
	struct FString                                     URI;                                              		// 0x00004C (0x000C)              
	struct FString                                     UserName;                                         		// 0x000058 (0x000C)              
	struct FString                                     Password;                                         		// 0x000064 (0x000C)              
	int                                                ContentLength;                                    		// 0x000070 (0x0004)              
	struct FString                                     ContentType;                                      		// 0x000074 (0x000C)              
	unsigned char                                      RequestType;                                      		// 0x000080 (0x0001)              PROPERTY: ERequestType
	unsigned char                                      _0x000081[0x3];                                   		// 0x000081 (0x0003) MISSED OFFSET
	struct FMap_Mirror                                 HeaderMap;                                        		// 0x000084 (0x003C)              
	struct FMap_Mirror                                 VariableMap;                                      		// 0x0000C0 (0x003C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.WebRequest");
		return pClassPointer;
	};

public:
	void AddHeader(struct FString HeaderName,struct FString Value);//IpDrv.WebRequest.AddHeader
	void GetHeaders(TArray<struct FString>* Headers);//IpDrv.WebRequest.GetHeaders
	int GetVariableCount(struct FString VariableName);//IpDrv.WebRequest.GetVariableCount
	void Dump();//IpDrv.WebRequest.Dump
	void ProcessHeaderString(struct FString S);//IpDrv.WebRequest.ProcessHeaderString
	struct FString EncodeBase64(struct FString Decoded);//IpDrv.WebRequest.EncodeBase64
	void AddVariable(struct FString VariableName,struct FString Value);//IpDrv.WebRequest.AddVariable
	int GetHexDigit(struct FString D);//IpDrv.WebRequest.GetHexDigit
	struct FString GetVariable(struct FString VariableName,struct FString DefaultValue);//IpDrv.WebRequest.GetVariable
	struct FString GetVariableNumber(struct FString VariableName,int Number,struct FString DefaultValue);//IpDrv.WebRequest.GetVariableNumber
	struct FString DecodeBase64(struct FString Encoded);//IpDrv.WebRequest.DecodeBase64
	void DecodeFormData(struct FString Data);//IpDrv.WebRequest.DecodeFormData
	void GetVariables(TArray<struct FString>* varNames);//IpDrv.WebRequest.GetVariables
	struct FString GetHeader(struct FString HeaderName,struct FString DefaultValue);//IpDrv.WebRequest.GetHeader
};
UClass* UWebRequest::pClassPointer = NULL;

//0x000068 (0x0000A8 - 0x000040)
//WebResponse[0x10356E70]
class UWebResponse : public UObject
{
public:
	TArray<struct FString>                             Headers;                                          		// 0x000040 (0x000C)              
	struct FMap_Mirror                                 ReplacementMap;                                   		// 0x00004C (0x003C)              
	struct FString                                     IncludePath;                                      		// 0x000088 (0x000C)              
	struct FString                                     CharSet;                                          		// 0x000094 (0x000C)              
	class AWebConnection*                              Connection;                                       		// 0x0000A0 (0x0004)              
	unsigned long                                      bSentText : 1;                                    		// 0x0000A4 (0x0004) [0x00000001] 
	unsigned long                                      bSentResponse : 1;                                		// 0x0000A4 (0x0004) [0x00000002] 

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.WebResponse");
		return pClassPointer;
	};

public:
	bool IncludeBinaryFile(struct FString Filename);//IpDrv.WebResponse.IncludeBinaryFile
	void FailAuthentication(struct FString Realm);//IpDrv.WebResponse.FailAuthentication
	void Subst(struct FString Variable,struct FString Value,bool bClear);//IpDrv.WebResponse.Subst
	void SendStandardHeaders(struct FString ContentType,bool bCache);//IpDrv.WebResponse.SendStandardHeaders
	void SendText(struct FString Text,bool bNoCRLF);//IpDrv.WebResponse.SendText
	void ClearSubst();//IpDrv.WebResponse.ClearSubst
	void HTTPHeader(struct FString Header);//IpDrv.WebResponse.HTTPHeader
	void SendBinary(int Count,unsigned char* B);//IpDrv.WebResponse.SendBinary
	void AddHeader(struct FString Header,bool bReplace);//IpDrv.WebResponse.AddHeader
	bool SentText();//IpDrv.WebResponse.SentText
	bool IncludeUHTM(struct FString Filename);//IpDrv.WebResponse.IncludeUHTM
	void HTTPResponse(struct FString Header);//IpDrv.WebResponse.HTTPResponse
	bool SentResponse();//IpDrv.WebResponse.SentResponse
	void Redirect(struct FString URL);//IpDrv.WebResponse.Redirect
	bool FileExists(struct FString Filename);//IpDrv.WebResponse.FileExists
	struct FString GetHTTPExpiration(int OffsetSeconds);//IpDrv.WebResponse.GetHTTPExpiration
	void SendHeaders();//IpDrv.WebResponse.SendHeaders
	bool SendCachedFile(struct FString Filename,struct FString ContentType);//IpDrv.WebResponse.SendCachedFile
	void HTTPError(int ErrorNum,struct FString Data);//IpDrv.WebResponse.HTTPError
	void Dump();//IpDrv.WebResponse.Dump
	struct FString LoadParsedUHTM(struct FString Filename);//IpDrv.WebResponse.LoadParsedUHTM
};
UClass* UWebResponse::pClassPointer = NULL;

//0x000000 (0x000054 - 0x000054)
//HelloWeb[0x216E2270]
class UHelloWeb : public UWebApplication
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.HelloWeb");
		return pClassPointer;
	};

public:
	void Init();//IpDrv.HelloWeb.Init
	void Query(class UWebRequest* Request,class UWebResponse* Response);//IpDrv.HelloWeb.Query
};
UClass* UHelloWeb::pClassPointer = NULL;

//0x000014 (0x000054 - 0x000040)
//WebApplication[0x216E2140]
class UWebApplication : public UObject
{
public:
	class AWorldInfo*                                  WorldInfo;                                        		// 0x000040 (0x0004)              
	class AWebServer*                                  WebServer;                                        		// 0x000044 (0x0004)              
	struct FString                                     Path;                                             		// 0x000048 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.WebApplication");
		return pClassPointer;
	};

public:
	void Query(class UWebRequest* Request,class UWebResponse* Response);//IpDrv.WebApplication.Query
	void PostQuery(class UWebRequest* Request,class UWebResponse* Response);//IpDrv.WebApplication.PostQuery
	void Init();//IpDrv.WebApplication.Init
	bool PreQuery(class UWebRequest* Request,class UWebResponse* Response);//IpDrv.WebApplication.PreQuery
	void CleanupApp();//IpDrv.WebApplication.CleanupApp
	void Cleanup();//IpDrv.WebApplication.Cleanup
};
UClass* UWebApplication::pClassPointer = NULL;

//0x000000 (0x000054 - 0x000054)
//ImageServer[0x216E2010]
class UImageServer : public UWebApplication
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.ImageServer");
		return pClassPointer;
	};

public:
	void Query(class UWebRequest* Request,class UWebResponse* Response);//IpDrv.ImageServer.Query
};
UClass* UImageServer::pClassPointer = NULL;

//0x000030 (0x0002D0 - 0x0002A0)
//WebConnection[0x216E1EE0]
class AWebConnection : public ATcpLink
{
public:
	class AWebServer*                                  WebServer;                                        		// 0x0002A0 (0x0004)              
	struct FString                                     ReceivedData;                                     		// 0x0002A4 (0x000C)              
	class UWebRequest*                                 Request;                                          		// 0x0002B0 (0x0004)              
	class UWebResponse*                                Response;                                         		// 0x0002B4 (0x0004)              
	class UWebApplication*                             Application;                                      		// 0x0002B8 (0x0004)              
	unsigned long                                      bDelayCleanup : 1;                                		// 0x0002BC (0x0004) [0x00000001] 
	int                                                RawBytesExpecting;                                		// 0x0002C0 (0x0004)              
	int                                                MaxValueLength;                                   		// 0x0002C4 (0x0004)              
	int                                                MaxLineLength;                                    		// 0x0002C8 (0x0004)              
	int                                                ConnID;                                           		// 0x0002CC (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.WebConnection");
		return pClassPointer;
	};

public:
	void Closed();//IpDrv.WebConnection.Closed
	void ProcessHead(struct FString S);//IpDrv.WebConnection.ProcessHead
	void ProcessPost(struct FString S);//IpDrv.WebConnection.ProcessPost
	void Accepted();//IpDrv.WebConnection.Accepted
	void EndOfHeaders();//IpDrv.WebConnection.EndOfHeaders
	void Cleanup();//IpDrv.WebConnection.Cleanup
	void ReceivedLine(struct FString S);//IpDrv.WebConnection.ReceivedLine
	void CheckRawBytes();//IpDrv.WebConnection.CheckRawBytes
	void ProcessGet(struct FString S);//IpDrv.WebConnection.ProcessGet
	void ReceivedText(struct FString Text);//IpDrv.WebConnection.ReceivedText
	bool IsHanging();//IpDrv.WebConnection.IsHanging
	void CreateResponseObject();//IpDrv.WebConnection.CreateResponseObject
	void Timer();//IpDrv.WebConnection.Timer
};
UClass* AWebConnection::pClassPointer = NULL;

//0x00014C (0x0003EC - 0x0002A0)
//WebServer[0x216E1DB0]
class AWebServer : public ATcpLink
{
public:
	struct FString                                     ServerName;                                       		// 0x0002A0 (0x000C)              
	struct FString                                     Applications[0xA];                                		// 0x0002AC (0x0078)              
	struct FString                                     ApplicationPaths[0xA];                            		// 0x000324 (0x0078)              
	unsigned long                                      bEnabled : 1;                                     		// 0x00039C (0x0004) [0x00000001] 
	int                                                ListenPort;                                       		// 0x0003A0 (0x0004)              
	int                                                MaxConnections;                                   		// 0x0003A4 (0x0004)              
	int                                                DefaultApplication;                               		// 0x0003A8 (0x0004)              
	int                                                ExpirationSeconds;                                		// 0x0003AC (0x0004)              
	struct FString                                     ServerURL;                                        		// 0x0003B0 (0x000C)              
	class UWebApplication*                             ApplicationObjects[0xA];                          		// 0x0003BC (0x0028)              
	int                                                ConnectionCount;                                  		// 0x0003E4 (0x0004)              
	int                                                ConnID;                                           		// 0x0003E8 (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.WebServer");
		return pClassPointer;
	};

public:
	void PostBeginPlay();//IpDrv.WebServer.PostBeginPlay
	void GainedChild(class AActor* C);//IpDrv.WebServer.GainedChild
	void LostChild(class AActor* C);//IpDrv.WebServer.LostChild
	class UWebApplication* GetApplication(struct FString URI,struct FString* SubURI);//IpDrv.WebServer.GetApplication
	void Destroyed();//IpDrv.WebServer.Destroyed
};
UClass* AWebServer::pClassPointer = NULL;

//0x0000A0 (0x000B14 - 0x000A74)
//HTTPDownload[0x10357F10]
class UHTTPDownload : public UDownload
{
public:
	struct FString                                     RedirectToURL;                                    		// 0x00004C (0x000C)              
	unsigned long                                      UseCompression : 1;                               		// 0x000058 (0x0004) [0x00000001] 
	unsigned char                                      _0x00005C[0xA18];                                 		// 0x00005C (0x0A18) MISSED OFFSET
	struct FString                                     ProxyServerHost;                                  		// 0x000A74 (0x000C)              
	int                                                ProxyServerPort;                                  		// 0x000A80 (0x0004)              
	unsigned long                                      MaxRedirection : 1;                               		// 0x000A84 (0x0004) [0x00000001] 
	float                                              ConnectionTimeout;                                		// 0x000A88 (0x0004)              
	unsigned char                                      _0x000A8C[0x88];                                  		// 0x000A8C (0x0088) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.HTTPDownload");
		return pClassPointer;
	};
};
UClass* UHTTPDownload::pClassPointer = NULL;

//0x00001C (0x009034 - 0x009018)
//TcpipConnection[0x10357200]
class UTcpipConnection : public UNetConnection
{
public:
	unsigned char                                      _0x009018[0x1C];                                  		// 0x009018 (0x001C) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.TcpipConnection");
		return pClassPointer;
	};
};
UClass* UTcpipConnection::pClassPointer = NULL;

//0x0000D8 (0x0002DC - 0x000204)
//TcpNetDriver[0x103570D0]
class UTcpNetDriver : public UNetDriver
{
public:
	unsigned long                                      AllowPlayerPortUnreach : 1;                       		// 0x000204 (0x0004) [0x00000001] 
	unsigned long                                      LogPortUnreach : 1;                               		// 0x000208 (0x0004) [0x00000001] 
	unsigned char                                      _0x00020C[0xD0];                                  		// 0x00020C (0x00D0) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class IpDrv.TcpNetDriver");
		return pClassPointer;
	};
};
UClass* UTcpNetDriver::pClassPointer = NULL;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif