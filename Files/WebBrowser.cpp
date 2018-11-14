
struct WebBrowser_ShutDown_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UEAWebKitBrowser::ShutDown()
{
	static UFieldFunc* pFnShutDown = NULL;
	if(!pFnShutDown)
		pFnShutDown = UObject::FindFunction("Function WebBrowser.EAWebKitBrowser.ShutDown");

	WebBrowser_ShutDown_Parms ShutDown_Parms;
	pFnShutDown->FunctionFlags |= ~0x400;
	ProcessEvent(pFnShutDown,NULL,&ShutDown_Parms,NULL);
	pFnShutDown->FunctionFlags |= 0x400;
	return ShutDown_Parms.ReturnValue;
}

struct WebBrowser_Close_Parms
{
	class UEAWebKitSession*                            i_pSession;                                       		// 0x000000 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000004 (0x0004) [0x00000001] 
};

bool UEAWebKitBrowser::Close(class UEAWebKitSession* i_pSession)
{
	static UFieldFunc* pFnClose = NULL;
	if(!pFnClose)
		pFnClose = UObject::FindFunction("Function WebBrowser.EAWebKitBrowser.Close");

	WebBrowser_Close_Parms Close_Parms;
	Close_Parms.i_pSession = i_pSession;
	pFnClose->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClose,NULL,&Close_Parms,NULL);
	pFnClose->FunctionFlags |= 0x400;
	return Close_Parms.ReturnValue;
}

struct WebBrowser_GetInstance_Parms
{
	class UEAWebKitBrowser*                            ReturnValue;                                      		// 0x000000 (0x0004)              
};

class UEAWebKitBrowser* UEAWebKitBrowser::GetInstance()
{
	static UFieldFunc* pFnGetInstance = NULL;
	if(!pFnGetInstance)
		pFnGetInstance = UObject::FindFunction("Function WebBrowser.EAWebKitBrowser.GetInstance");

	WebBrowser_GetInstance_Parms GetInstance_Parms;
	pFnGetInstance->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetInstance,NULL,&GetInstance_Parms,NULL);
	pFnGetInstance->FunctionFlags |= 0x400;
	return GetInstance_Parms.ReturnValue;
}

struct WebBrowser_Open_Parms
{
	class UEAWebKitCallbackInterface*                  i_pCallback;                                      		// 0x000000 (0x0008)              
	class UEAWebKitSession*                            ReturnValue;                                      		// 0x000008 (0x0004)              
};

class UEAWebKitSession* UEAWebKitBrowser::Open(class UEAWebKitCallbackInterface* i_pCallback)
{
	static UFieldFunc* pFnOpen = NULL;
	if(!pFnOpen)
		pFnOpen = UObject::FindFunction("Function WebBrowser.EAWebKitBrowser.Open");

	WebBrowser_Open_Parms Open_Parms;
	Open_Parms.i_pCallback = i_pCallback;
	pFnOpen->FunctionFlags |= ~0x400;
	ProcessEvent(pFnOpen,NULL,&Open_Parms,NULL);
	pFnOpen->FunctionFlags |= 0x400;
	return Open_Parms.ReturnValue;
}

struct WebBrowser_Initialize_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UEAWebKitBrowser::Initialize()
{
	static UFieldFunc* pFnInitialize = NULL;
	if(!pFnInitialize)
		pFnInitialize = UObject::FindFunction("Function WebBrowser.EAWebKitBrowser.Initialize");

	WebBrowser_Initialize_Parms Initialize_Parms;
	pFnInitialize->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInitialize,NULL,&Initialize_Parms,NULL);
	pFnInitialize->FunctionFlags |= 0x400;
	return Initialize_Parms.ReturnValue;
}

struct WebBrowser_NavigateForward_Parms
{
};

void UEAWebKitSession::NavigateForward()
{
	static UFieldFunc* pFnNavigateForward = NULL;
	if(!pFnNavigateForward)
		pFnNavigateForward = UObject::FindFunction("Function WebBrowser.EAWebKitSession.NavigateForward");

	WebBrowser_NavigateForward_Parms NavigateForward_Parms;
	pFnNavigateForward->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNavigateForward,NULL,&NavigateForward_Parms,NULL);
	pFnNavigateForward->FunctionFlags |= 0x400;
}

struct WebBrowser_NavigateUrl_Parms
{
	struct FString                                     i_sURL;                                           		// 0x000000 (0x000C)              
};

void UEAWebKitSession::NavigateUrl(struct FString i_sURL)
{
	static UFieldFunc* pFnNavigateUrl = NULL;
	if(!pFnNavigateUrl)
		pFnNavigateUrl = UObject::FindFunction("Function WebBrowser.EAWebKitSession.NavigateUrl");

	WebBrowser_NavigateUrl_Parms NavigateUrl_Parms;
	memcpy(&NavigateUrl_Parms.i_sURL,&i_sURL,0xC);
	pFnNavigateUrl->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNavigateUrl,NULL,&NavigateUrl_Parms,NULL);
	pFnNavigateUrl->FunctionFlags |= 0x400;
}

struct WebBrowser_Close_Parms
{
};

void UEAWebKitSession::Close()
{
	static UFieldFunc* pFnClose = NULL;
	if(!pFnClose)
		pFnClose = UObject::FindFunction("Function WebBrowser.EAWebKitSession.Close");

	WebBrowser_Close_Parms Close_Parms;
	pFnClose->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClose,NULL,&Close_Parms,NULL);
	pFnClose->FunctionFlags |= 0x400;
}

struct WebBrowser_NavigateBack_Parms
{
};

void UEAWebKitSession::NavigateBack()
{
	static UFieldFunc* pFnNavigateBack = NULL;
	if(!pFnNavigateBack)
		pFnNavigateBack = UObject::FindFunction("Function WebBrowser.EAWebKitSession.NavigateBack");

	WebBrowser_NavigateBack_Parms NavigateBack_Parms;
	pFnNavigateBack->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNavigateBack,NULL,&NavigateBack_Parms,NULL);
	pFnNavigateBack->FunctionFlags |= 0x400;
}
