
/*
-----------------------------------------------------------------
 - Structs
-----------------------------------------------------------------
*/
//0x000018
//WebKitExposedFunction[0x1D093DC0]
struct FWebKitExposedFunction
{
	struct FString                                     Name;                                             		// 0x000000 (0x000C)              
	struct FScriptDelegate                             DelegateFunction;                                 		// 0x00000C (0x000C)              
};

/*
-----------------------------------------------------------------
 - Classes
-----------------------------------------------------------------
*/
//0x000030 (0x000070 - 0x000040)
//EAWebKitBrowser[0x10355320]
class UEAWebKitBrowser : public UObject
{
public:
	DWORD                                              VfTable_FTickableObject;                          		// 0x000040 (0x0004)              
	unsigned long                                      m_bInitialized : 1;                               		// 0x000044 (0x0004) [0x00000001] 
	DWORD                                              m_pWKCallbacks;                                   		// 0x000048 (0x0004)              
	DWORD                                              m_pWKSystems;                                     		// 0x00004C (0x0004)              
	DWORD                                              m_pWKLib;                                         		// 0x000050 (0x0004)              
	DWORD                                              m_pLibrary;                                       		// 0x000054 (0x0004)              
	TArray<class UEAWebKitSession*>                    m_pSessions;                                      		// 0x000058 (0x000C)              
	DWORD                                              m_pTransport;                                     		// 0x000064 (0x0004)              
	DWORD                                              m_pDataTransport;                                 		// 0x000068 (0x0004)              
	DWORD                                              m_pSocketTransport;                               		// 0x00006C (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class WebBrowser.EAWebKitBrowser");
		return pClassPointer;
	};

public:
	bool ShutDown();//WebBrowser.EAWebKitBrowser.ShutDown
	bool Close(class UEAWebKitSession* i_pSession);//WebBrowser.EAWebKitBrowser.Close
	class UEAWebKitBrowser* GetInstance();//WebBrowser.EAWebKitBrowser.GetInstance
	class UEAWebKitSession* Open(class UEAWebKitCallbackInterface* i_pCallback);//WebBrowser.EAWebKitBrowser.Open
	bool Initialize();//WebBrowser.EAWebKitBrowser.Initialize
};
UClass* UEAWebKitBrowser::pClassPointer = NULL;

//0x000000 (0x000040 - 0x000040)
//EAWebKitCallbackInterface[0x103551F0]
class UEAWebKitCallbackInterface : public UInterface
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class WebBrowser.EAWebKitCallbackInterface");
		return pClassPointer;
	};
};
UClass* UEAWebKitCallbackInterface::pClassPointer = NULL;

//0x0000AC (0x0000EC - 0x000040)
//EAWebKitSession[0x103550C0]
class UEAWebKitSession : public UObject
{
public:
	DWORD                                              m_pCurrentView;                                   		// 0x000040 (0x0004)              
	DWORD                                              m_pSurface;                                       		// 0x000044 (0x0004)              
	DWORD                                              m_pJSCallback;                                    		// 0x000048 (0x0004)              
	class UTexture*                                    m_pTexture;                                       		// 0x00004C (0x0004)              
	TArray<class UTexture*>                            m_pReferencedTextures;                            		// 0x000050 (0x000C)              
	int                                                m_nKeyModifiers;                                  		// 0x00005C (0x0004)              
	int                                                m_nMouseButton;                                   		// 0x000060 (0x0004)              
	class UEAWebKitCallbackInterface*                  m_pCallback;                                      		// 0x000064 (0x0004)              
	unsigned char                                      _0x000068[0x4];                                   		// 0x000068 (0x0004) ALIGNEMENT
	float                                              m_fLeftX;                                         		// 0x00006C (0x0004)              
	float                                              m_fRightX;                                        		// 0x000070 (0x0004)              
	float                                              m_fLeftY;                                         		// 0x000074 (0x0004)              
	float                                              m_fRightY;                                        		// 0x000078 (0x0004)              
	float                                              m_fScrollXRemainder;                              		// 0x00007C (0x0004)              
	float                                              m_fScrollYRemainder;                              		// 0x000080 (0x0004)              
	float                                              m_fMouseXRemainder;                               		// 0x000084 (0x0004)              
	float                                              m_fMouseYRemainder;                               		// 0x000088 (0x0004)              
	int                                                m_nNavigationDirection;                           		// 0x00008C (0x0004)              
	float                                              m_fNavigationTimer;                               		// 0x000090 (0x0004)              
	float                                              m_fNavigationTimerDuration;                       		// 0x000094 (0x0004)              
	unsigned long                                      m_bEnableStickControl : 1;                        		// 0x000098 (0x0004) [0x00000001] 
	float                                              m_fStickDeadZone;                                 		// 0x00009C (0x0004)              
	float                                              m_fNavigationMinTimer;                            		// 0x0000A0 (0x0004)              
	float                                              m_fNavigationTimerDecrease;                       		// 0x0000A4 (0x0004)              
	float                                              m_fNavigationMaxTimer;                            		// 0x0000A8 (0x0004)              
	float                                              m_fHalfStickMoveSpeed;                            		// 0x0000AC (0x0004)              
	float                                              m_fFullStickMoveSpeed;                            		// 0x0000B0 (0x0004)              
	float                                              m_fHalfStickScrollSpeed;                          		// 0x0000B4 (0x0004)              
	float                                              m_fFullStickScrollSpeed;                          		// 0x0000B8 (0x0004)              
	TArray<struct FString>                             m_URIWhitelist;                                   		// 0x0000BC (0x000C)              
	TArray<struct FString>                             m_URIBlacklist;                                   		// 0x0000C8 (0x000C)              
	TArray<struct FWebKitExposedFunction>              m_ExposedFunction;                                		// 0x0000D4 (0x000C)              
	struct FString                                     m_sCallbackURL;                                   		// 0x0000E0 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class WebBrowser.EAWebKitSession");
		return pClassPointer;
	};

public:
	void NavigateForward();//WebBrowser.EAWebKitSession.NavigateForward
	void NavigateUrl(struct FString i_sURL);//WebBrowser.EAWebKitSession.NavigateUrl
	void Close();//WebBrowser.EAWebKitSession.Close
	void NavigateBack();//WebBrowser.EAWebKitSession.NavigateBack
};
UClass* UEAWebKitSession::pClassPointer = NULL;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif