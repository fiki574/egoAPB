
struct GFxUI_FSCommand_Parms
{
	class UGFxMoviePlayer*                             Movie;                                            		// 0x000000 (0x0004)              
	class UGFxEvent_FSCommand*                         Event;                                            		// 0x000004 (0x0004)              
	struct FString                                     Cmd;                                              		// 0x000008 (0x000C)              
	struct FString                                     Arg;                                              		// 0x000014 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000020 (0x0004) [0x00000001] 
};

bool UGFxFSCmdHandler::FSCommand(class UGFxMoviePlayer* Movie,class UGFxEvent_FSCommand* Event,struct FString Cmd,struct FString Arg)
{
	static UFieldFunc* pFnFSCommand = NULL;
	if(!pFnFSCommand)
		pFnFSCommand = UObject::FindFunction("Function GFxUI.GFxFSCmdHandler.FSCommand");

	GFxUI_FSCommand_Parms FSCommand_Parms;
	FSCommand_Parms.Movie = Movie;
	FSCommand_Parms.Event = Event;
	memcpy(&FSCommand_Parms.Cmd,&Cmd,0xC);
	memcpy(&FSCommand_Parms.Arg,&Arg,0xC);
	ProcessEvent(pFnFSCommand,NULL,&FSCommand_Parms,NULL);
	return FSCommand_Parms.ReturnValue;
}

struct GFxUI_GetFocusMovie_Parms
{
	int                                                ControllerId;                                     		// 0x000000 (0x0004)              
	class UGFxMoviePlayer*                             ReturnValue;                                      		// 0x000004 (0x0004)              
};

class UGFxMoviePlayer* UGFxInteraction::GetFocusMovie(int ControllerId)
{
	static UFieldFunc* pFnGetFocusMovie = NULL;
	if(!pFnGetFocusMovie)
		pFnGetFocusMovie = UObject::FindFunction("Function GFxUI.GFxInteraction.GetFocusMovie");

	GFxUI_GetFocusMovie_Parms GetFocusMovie_Parms;
	GetFocusMovie_Parms.ControllerId = ControllerId;
	pFnGetFocusMovie->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetFocusMovie,NULL,&GetFocusMovie_Parms,NULL);
	pFnGetFocusMovie->FunctionFlags |= 0x400;
	return GetFocusMovie_Parms.ReturnValue;
}

struct GFxUI_NotifyPlayerAdded_Parms
{
	int                                                PlayerIndex;                                      		// 0x000000 (0x0004)              
	class ULocalPlayer*                                AddedPlayer;                                      		// 0x000004 (0x0004)              
};

void UGFxInteraction::NotifyPlayerAdded(int PlayerIndex,class ULocalPlayer* AddedPlayer)
{
	static UFieldFunc* pFnNotifyPlayerAdded = NULL;
	if(!pFnNotifyPlayerAdded)
		pFnNotifyPlayerAdded = UObject::FindFunction("Function GFxUI.GFxInteraction.NotifyPlayerAdded");

	GFxUI_NotifyPlayerAdded_Parms NotifyPlayerAdded_Parms;
	NotifyPlayerAdded_Parms.PlayerIndex = PlayerIndex;
	NotifyPlayerAdded_Parms.AddedPlayer = AddedPlayer;
	pFnNotifyPlayerAdded->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotifyPlayerAdded,NULL,&NotifyPlayerAdded_Parms,NULL);
	pFnNotifyPlayerAdded->FunctionFlags |= 0x400;
}

struct GFxUI_NotifySplitscreenLayoutChanged_Parms
{
};

void UGFxInteraction::NotifySplitscreenLayoutChanged()
{
	static UFieldFunc* pFnNotifySplitscreenLayoutChanged = NULL;
	if(!pFnNotifySplitscreenLayoutChanged)
		pFnNotifySplitscreenLayoutChanged = UObject::FindFunction("Function GFxUI.GFxInteraction.NotifySplitscreenLayoutChanged");

	GFxUI_NotifySplitscreenLayoutChanged_Parms NotifySplitscreenLayoutChanged_Parms;
	pFnNotifySplitscreenLayoutChanged->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotifySplitscreenLayoutChanged,NULL,&NotifySplitscreenLayoutChanged_Parms,NULL);
	pFnNotifySplitscreenLayoutChanged->FunctionFlags |= 0x400;
}

struct GFxUI_NotifyPlayerRemoved_Parms
{
	int                                                PlayerIndex;                                      		// 0x000000 (0x0004)              
	class ULocalPlayer*                                RemovedPlayer;                                    		// 0x000004 (0x0004)              
};

void UGFxInteraction::NotifyPlayerRemoved(int PlayerIndex,class ULocalPlayer* RemovedPlayer)
{
	static UFieldFunc* pFnNotifyPlayerRemoved = NULL;
	if(!pFnNotifyPlayerRemoved)
		pFnNotifyPlayerRemoved = UObject::FindFunction("Function GFxUI.GFxInteraction.NotifyPlayerRemoved");

	GFxUI_NotifyPlayerRemoved_Parms NotifyPlayerRemoved_Parms;
	NotifyPlayerRemoved_Parms.PlayerIndex = PlayerIndex;
	NotifyPlayerRemoved_Parms.RemovedPlayer = RemovedPlayer;
	pFnNotifyPlayerRemoved->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotifyPlayerRemoved,NULL,&NotifyPlayerRemoved_Parms,NULL);
	pFnNotifyPlayerRemoved->FunctionFlags |= 0x400;
}

struct GFxUI_CloseAllMoviePlayers_Parms
{
};

void UGFxInteraction::CloseAllMoviePlayers()
{
	static UFieldFunc* pFnCloseAllMoviePlayers = NULL;
	if(!pFnCloseAllMoviePlayers)
		pFnCloseAllMoviePlayers = UObject::FindFunction("Function GFxUI.GFxInteraction.CloseAllMoviePlayers");

	GFxUI_CloseAllMoviePlayers_Parms CloseAllMoviePlayers_Parms;
	pFnCloseAllMoviePlayers->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCloseAllMoviePlayers,NULL,&CloseAllMoviePlayers_Parms,NULL);
	pFnCloseAllMoviePlayers->FunctionFlags |= 0x400;
}

struct GFxUI_NotifyGameSessionEnded_Parms
{
};

void UGFxInteraction::NotifyGameSessionEnded()
{
	static UFieldFunc* pFnNotifyGameSessionEnded = NULL;
	if(!pFnNotifyGameSessionEnded)
		pFnNotifyGameSessionEnded = UObject::FindFunction("Function GFxUI.GFxInteraction.NotifyGameSessionEnded");

	GFxUI_NotifyGameSessionEnded_Parms NotifyGameSessionEnded_Parms;
	pFnNotifyGameSessionEnded->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotifyGameSessionEnded,NULL,&NotifyGameSessionEnded_Parms,NULL);
	pFnNotifyGameSessionEnded->FunctionFlags |= 0x400;
}

struct GFxUI_FlushPlayerInput_Parms
{
	unsigned long                                      capturekeysonly : 1;                              		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::FlushPlayerInput(bool capturekeysonly)
{
	static UFieldFunc* pFnFlushPlayerInput = NULL;
	if(!pFnFlushPlayerInput)
		pFnFlushPlayerInput = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.FlushPlayerInput");

	GFxUI_FlushPlayerInput_Parms FlushPlayerInput_Parms;
	FlushPlayerInput_Parms.capturekeysonly = capturekeysonly;
	pFnFlushPlayerInput->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFlushPlayerInput,NULL,&FlushPlayerInput_Parms,NULL);
	pFnFlushPlayerInput->FunctionFlags |= 0x400;
}

struct GFxUI_ActionScriptSetFunction_Parms
{
	class UGFxObject*                                  Object;                                           		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
};

void UGFxMoviePlayer::ActionScriptSetFunction(class UGFxObject* Object,struct FString Member)
{
	static UFieldFunc* pFnActionScriptSetFunction = NULL;
	if(!pFnActionScriptSetFunction)
		pFnActionScriptSetFunction = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptSetFunction");

	GFxUI_ActionScriptSetFunction_Parms ActionScriptSetFunction_Parms;
	ActionScriptSetFunction_Parms.Object = Object;
	memcpy(&ActionScriptSetFunction_Parms.Member,&Member,0xC);
	pFnActionScriptSetFunction->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptSetFunction,NULL,&ActionScriptSetFunction_Parms,NULL);
	pFnActionScriptSetFunction->FunctionFlags |= 0x400;
}

struct GFxUI_SetVariableString_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	struct FString                                     S;                                                		// 0x00000C (0x000C)              
};

void UGFxMoviePlayer::SetVariableString(struct FString Path,struct FString S)
{
	static UFieldFunc* pFnSetVariableString = NULL;
	if(!pFnSetVariableString)
		pFnSetVariableString = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableString");

	GFxUI_SetVariableString_Parms SetVariableString_Parms;
	memcpy(&SetVariableString_Parms.Path,&Path,0xC);
	memcpy(&SetVariableString_Parms.S,&S,0xC);
	pFnSetVariableString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableString,NULL,&SetVariableString_Parms,NULL);
	pFnSetVariableString->FunctionFlags |= 0x400;
}

struct GFxUI_RefreshDataStoreBindings_Parms
{
};

void UGFxMoviePlayer::RefreshDataStoreBindings()
{
	static UFieldFunc* pFnRefreshDataStoreBindings = NULL;
	if(!pFnRefreshDataStoreBindings)
		pFnRefreshDataStoreBindings = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.RefreshDataStoreBindings");

	GFxUI_RefreshDataStoreBindings_Parms RefreshDataStoreBindings_Parms;
	pFnRefreshDataStoreBindings->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRefreshDataStoreBindings,NULL,&RefreshDataStoreBindings_Parms,NULL);
	pFnRefreshDataStoreBindings->FunctionFlags |= 0x400;
}

struct GFxUI_UpdateSplitscreenLayout_Parms
{
};

void UGFxMoviePlayer::UpdateSplitscreenLayout()
{
	static UFieldFunc* pFnUpdateSplitscreenLayout = NULL;
	if(!pFnUpdateSplitscreenLayout)
		pFnUpdateSplitscreenLayout = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.UpdateSplitscreenLayout");

	GFxUI_UpdateSplitscreenLayout_Parms UpdateSplitscreenLayout_Parms;
	pFnUpdateSplitscreenLayout->FunctionFlags |= ~0x400;
	ProcessEvent(pFnUpdateSplitscreenLayout,NULL,&UpdateSplitscreenLayout_Parms,NULL);
	pFnUpdateSplitscreenLayout->FunctionFlags |= 0x400;
}

struct GFxUI_GetAVMVersion_Parms
{
	int                                                ReturnValue;                                      		// 0x000000 (0x0004)              
};

int UGFxMoviePlayer::GetAVMVersion()
{
	static UFieldFunc* pFnGetAVMVersion = NULL;
	if(!pFnGetAVMVersion)
		pFnGetAVMVersion = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetAVMVersion");

	GFxUI_GetAVMVersion_Parms GetAVMVersion_Parms;
	pFnGetAVMVersion->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetAVMVersion,NULL,&GetAVMVersion_Parms,NULL);
	pFnGetAVMVersion->FunctionFlags |= 0x400;
	return GetAVMVersion_Parms.ReturnValue;
}

struct GFxUI_ApplyPriorityEffect_Parms
{
	unsigned long                                      bRequestedBlurState : 1;                          		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      bRequestedHiddenState : 1;                        		// 0x000004 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::ApplyPriorityEffect(bool bRequestedBlurState,bool bRequestedHiddenState)
{
	static UFieldFunc* pFnApplyPriorityEffect = NULL;
	if(!pFnApplyPriorityEffect)
		pFnApplyPriorityEffect = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ApplyPriorityEffect");

	GFxUI_ApplyPriorityEffect_Parms ApplyPriorityEffect_Parms;
	ApplyPriorityEffect_Parms.bRequestedBlurState = bRequestedBlurState;
	ApplyPriorityEffect_Parms.bRequestedHiddenState = bRequestedHiddenState;
	ProcessEvent(pFnApplyPriorityEffect,NULL,&ApplyPriorityEffect_Parms,NULL);
}

struct GFxUI_GetGameViewportClient_Parms
{
	class UGameViewportClient*                         ReturnValue;                                      		// 0x000000 (0x0004)              
};

class UGameViewportClient* UGFxMoviePlayer::GetGameViewportClient()
{
	static UFieldFunc* pFnGetGameViewportClient = NULL;
	if(!pFnGetGameViewportClient)
		pFnGetGameViewportClient = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetGameViewportClient");

	GFxUI_GetGameViewportClient_Parms GetGameViewportClient_Parms;
	pFnGetGameViewportClient->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetGameViewportClient,NULL,&GetGameViewportClient_Parms,NULL);
	pFnGetGameViewportClient->FunctionFlags |= 0x400;
	return GetGameViewportClient_Parms.ReturnValue;
}

struct GFxUI_SetMovieInfo_Parms
{
	class USwfMovie*                                   Data;                                             		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::SetMovieInfo(class USwfMovie* Data)
{
	static UFieldFunc* pFnSetMovieInfo = NULL;
	if(!pFnSetMovieInfo)
		pFnSetMovieInfo = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetMovieInfo");

	GFxUI_SetMovieInfo_Parms SetMovieInfo_Parms;
	SetMovieInfo_Parms.Data = Data;
	ProcessEvent(pFnSetMovieInfo,NULL,&SetMovieInfo_Parms,NULL);
}

struct GFxUI_SetViewport_Parms
{
	int                                                X;                                                		// 0x000000 (0x0004)              
	int                                                Y;                                                		// 0x000004 (0x0004)              
	int                                                Width;                                            		// 0x000008 (0x0004)              
	int                                                Height;                                           		// 0x00000C (0x0004)              
};

void UGFxMoviePlayer::SetViewport(int X,int Y,int Width,int Height)
{
	static UFieldFunc* pFnSetViewport = NULL;
	if(!pFnSetViewport)
		pFnSetViewport = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetViewport");

	GFxUI_SetViewport_Parms SetViewport_Parms;
	SetViewport_Parms.X = X;
	SetViewport_Parms.Y = Y;
	SetViewport_Parms.Width = Width;
	SetViewport_Parms.Height = Height;
	pFnSetViewport->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetViewport,NULL,&SetViewport_Parms,NULL);
	pFnSetViewport->FunctionFlags |= 0x400;
}

struct GFxUI_ApplyPriorityVisibilityEffect_Parms
{
	unsigned long                                      bRemoveEffect : 1;                                		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::ApplyPriorityVisibilityEffect(bool bRemoveEffect)
{
	static UFieldFunc* pFnApplyPriorityVisibilityEffect = NULL;
	if(!pFnApplyPriorityVisibilityEffect)
		pFnApplyPriorityVisibilityEffect = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ApplyPriorityVisibilityEffect");

	GFxUI_ApplyPriorityVisibilityEffect_Parms ApplyPriorityVisibilityEffect_Parms;
	ApplyPriorityVisibilityEffect_Parms.bRemoveEffect = bRemoveEffect;
	ProcessEvent(pFnApplyPriorityVisibilityEffect,NULL,&ApplyPriorityVisibilityEffect_Parms,NULL);
}

struct GFxUI_OnFocusGained_Parms
{
	int                                                LocalPlayerIndex;                                 		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::OnFocusGained(int LocalPlayerIndex)
{
	static UFieldFunc* pFnOnFocusGained = NULL;
	if(!pFnOnFocusGained)
		pFnOnFocusGained = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.OnFocusGained");

	GFxUI_OnFocusGained_Parms OnFocusGained_Parms;
	OnFocusGained_Parms.LocalPlayerIndex = LocalPlayerIndex;
	ProcessEvent(pFnOnFocusGained,NULL,&OnFocusGained_Parms,NULL);
}

struct GFxUI_CreateObject_Parms
{
	struct FString                                     ASClass;                                          		// 0x000000 (0x000C)              
	class UClass*                                      Type;                                             		// 0x00000C (0x0004)              
	TArray<struct FASValue>                            args;                                             		// 0x000010 (0x000C)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x00001C (0x0004)              
};

class UGFxObject* UGFxMoviePlayer::CreateObject(struct FString ASClass,class UClass* Type,TArray<struct FASValue> args)
{
	static UFieldFunc* pFnCreateObject = NULL;
	if(!pFnCreateObject)
		pFnCreateObject = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.CreateObject");

	GFxUI_CreateObject_Parms CreateObject_Parms;
	memcpy(&CreateObject_Parms.ASClass,&ASClass,0xC);
	CreateObject_Parms.Type = Type;
	memcpy(&CreateObject_Parms.args,&args,0xC);
	pFnCreateObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCreateObject,NULL,&CreateObject_Parms,NULL);
	pFnCreateObject->FunctionFlags |= 0x400;
	return CreateObject_Parms.ReturnValue;
}

struct GFxUI_GetLP_Parms
{
	class ULocalPlayer*                                ReturnValue;                                      		// 0x000000 (0x0004)              
	//class UEngine*                                     Eng;                                              		// 0x000004 (0x0004)              
};

class ULocalPlayer* UGFxMoviePlayer::GetLP()
{
	static UFieldFunc* pFnGetLP = NULL;
	if(!pFnGetLP)
		pFnGetLP = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetLP");

	GFxUI_GetLP_Parms GetLP_Parms;
	ProcessEvent(pFnGetLP,NULL,&GetLP_Parms,NULL);
	return GetLP_Parms.ReturnValue;
}

struct GFxUI_ActionScriptConstructor_Parms
{
	struct FString                                     ClassName;                                        		// 0x000000 (0x000C)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x00000C (0x0004)              
};

class UGFxObject* UGFxMoviePlayer::ActionScriptConstructor(struct FString ClassName)
{
	static UFieldFunc* pFnActionScriptConstructor = NULL;
	if(!pFnActionScriptConstructor)
		pFnActionScriptConstructor = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptConstructor");

	GFxUI_ActionScriptConstructor_Parms ActionScriptConstructor_Parms;
	memcpy(&ActionScriptConstructor_Parms.ClassName,&ClassName,0xC);
	pFnActionScriptConstructor->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptConstructor,NULL,&ActionScriptConstructor_Parms,NULL);
	pFnActionScriptConstructor->FunctionFlags |= 0x400;
	return ActionScriptConstructor_Parms.ReturnValue;
}

struct GFxUI_ActionScriptString_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UGFxMoviePlayer::ActionScriptString(struct FString Path)
{
	static UFieldFunc* pFnActionScriptString = NULL;
	if(!pFnActionScriptString)
		pFnActionScriptString = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptString");

	GFxUI_ActionScriptString_Parms ActionScriptString_Parms;
	memcpy(&ActionScriptString_Parms.Path,&Path,0xC);
	pFnActionScriptString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptString,NULL,&ActionScriptString_Parms,NULL);
	pFnActionScriptString->FunctionFlags |= 0x400;
	return ActionScriptString_Parms.ReturnValue;
}

struct GFxUI_OnCleanup_Parms
{
	unsigned long                                      bUnload : 1;                                      		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::OnCleanup(bool bUnload)
{
	static UFieldFunc* pFnOnCleanup = NULL;
	if(!pFnOnCleanup)
		pFnOnCleanup = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.OnCleanup");

	GFxUI_OnCleanup_Parms OnCleanup_Parms;
	OnCleanup_Parms.bUnload = bUnload;
	pFnOnCleanup->FunctionFlags |= ~0x400;
	ProcessEvent(pFnOnCleanup,NULL,&OnCleanup_Parms,NULL);
	pFnOnCleanup->FunctionFlags |= 0x400;
}

struct GFxUI_PlaySoundFromTheme_Parms
{
	class UGFxObject*                                  EventSource;                                      		// 0x000000 (0x0004)              
	struct FName                                       EventName;                                        		// 0x000004 (0x0008)              
	struct FName                                       SoundThemeName;                                   		// 0x00000C (0x0008)              
	//int                                                ThemeIndex;                                       		// 0x000014 (0x0004)              
	//class UUISoundTheme*                               Theme;                                            		// 0x000018 (0x0004)              
};

void UGFxMoviePlayer::PlaySoundFromTheme(class UGFxObject* EventSource,struct FName EventName,struct FName SoundThemeName)
{
	static UFieldFunc* pFnPlaySoundFromTheme = NULL;
	if(!pFnPlaySoundFromTheme)
		pFnPlaySoundFromTheme = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.PlaySoundFromTheme");

	GFxUI_PlaySoundFromTheme_Parms PlaySoundFromTheme_Parms;
	PlaySoundFromTheme_Parms.EventSource = EventSource;
	memcpy(&PlaySoundFromTheme_Parms.EventName,&EventName,0x8);
	memcpy(&PlaySoundFromTheme_Parms.SoundThemeName,&SoundThemeName,0x8);
	ProcessEvent(pFnPlaySoundFromTheme,NULL,&PlaySoundFromTheme_Parms,NULL);
}

struct GFxUI_ActionScriptInt_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UGFxMoviePlayer::ActionScriptInt(struct FString Path)
{
	static UFieldFunc* pFnActionScriptInt = NULL;
	if(!pFnActionScriptInt)
		pFnActionScriptInt = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptInt");

	GFxUI_ActionScriptInt_Parms ActionScriptInt_Parms;
	memcpy(&ActionScriptInt_Parms.Path,&Path,0xC);
	pFnActionScriptInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptInt,NULL,&ActionScriptInt_Parms,NULL);
	pFnActionScriptInt->FunctionFlags |= 0x400;
	return ActionScriptInt_Parms.ReturnValue;
}

struct GFxUI_PostWidgetInit_Parms
{
};

void UGFxMoviePlayer::PostWidgetInit()
{
	static UFieldFunc* pFnPostWidgetInit = NULL;
	if(!pFnPostWidgetInit)
		pFnPostWidgetInit = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.PostWidgetInit");

	GFxUI_PostWidgetInit_Parms PostWidgetInit_Parms;
	ProcessEvent(pFnPostWidgetInit,NULL,&PostWidgetInit_Parms,NULL);
}

struct GFxUI_WidgetUnloaded_Parms
{
	struct FName                                       WidgetName;                                       		// 0x000000 (0x0008)              
	struct FName                                       WidgetPath;                                       		// 0x000008 (0x0008)              
	class UGFxObject*                                  Widget;                                           		// 0x000010 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::WidgetUnloaded(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget)
{
	static UFieldFunc* pFnWidgetUnloaded = NULL;
	if(!pFnWidgetUnloaded)
		pFnWidgetUnloaded = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.WidgetUnloaded");

	GFxUI_WidgetUnloaded_Parms WidgetUnloaded_Parms;
	memcpy(&WidgetUnloaded_Parms.WidgetName,&WidgetName,0x8);
	memcpy(&WidgetUnloaded_Parms.WidgetPath,&WidgetPath,0x8);
	WidgetUnloaded_Parms.Widget = Widget;
	ProcessEvent(pFnWidgetUnloaded,NULL,&WidgetUnloaded_Parms,NULL);
	return WidgetUnloaded_Parms.ReturnValue;
}

struct GFxUI_AddCaptureKey_Parms
{
	struct FName                                       Key;                                              		// 0x000000 (0x0008)              
};

void UGFxMoviePlayer::AddCaptureKey(struct FName Key)
{
	static UFieldFunc* pFnAddCaptureKey = NULL;
	if(!pFnAddCaptureKey)
		pFnAddCaptureKey = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.AddCaptureKey");

	GFxUI_AddCaptureKey_Parms AddCaptureKey_Parms;
	memcpy(&AddCaptureKey_Parms.Key,&Key,0x8);
	pFnAddCaptureKey->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddCaptureKey,NULL,&AddCaptureKey_Parms,NULL);
	pFnAddCaptureKey->FunctionFlags |= 0x400;
}

struct GFxUI_ConsoleCommand_Parms
{
	struct FString                                     Command;                                          		// 0x000000 (0x000C)              
	//class APlayerController*                           PC;                                               		// 0x00000C (0x0004)              
};

void UGFxMoviePlayer::ConsoleCommand(struct FString Command)
{
	static UFieldFunc* pFnConsoleCommand = NULL;
	if(!pFnConsoleCommand)
		pFnConsoleCommand = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ConsoleCommand");

	GFxUI_ConsoleCommand_Parms ConsoleCommand_Parms;
	memcpy(&ConsoleCommand_Parms.Command,&Command,0xC);
	ProcessEvent(pFnConsoleCommand,NULL,&ConsoleCommand_Parms,NULL);
}

struct GFxUI_Start_Parms
{
	unsigned long                                      StartPaused : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000004 (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::Start(bool StartPaused)
{
	static UFieldFunc* pFnStart = NULL;
	if(!pFnStart)
		pFnStart = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.Start");

	GFxUI_Start_Parms Start_Parms;
	Start_Parms.StartPaused = StartPaused;
	pFnStart->FunctionFlags |= ~0x400;
	ProcessEvent(pFnStart,NULL,&Start_Parms,NULL);
	pFnStart->FunctionFlags |= 0x400;
	return Start_Parms.ReturnValue;
}

struct GFxUI_GetVariableObject_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	class UClass*                                      Type;                                             		// 0x00000C (0x0004)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x000010 (0x0004)              
};

class UGFxObject* UGFxMoviePlayer::GetVariableObject(struct FString Path,class UClass* Type)
{
	static UFieldFunc* pFnGetVariableObject = NULL;
	if(!pFnGetVariableObject)
		pFnGetVariableObject = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableObject");

	GFxUI_GetVariableObject_Parms GetVariableObject_Parms;
	memcpy(&GetVariableObject_Parms.Path,&Path,0xC);
	GetVariableObject_Parms.Type = Type;
	pFnGetVariableObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableObject,NULL,&GetVariableObject_Parms,NULL);
	pFnGetVariableObject->FunctionFlags |= 0x400;
	return GetVariableObject_Parms.ReturnValue;
}

struct GFxUI_GetVariableFloatArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<float>                                      Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::GetVariableFloatArray(struct FString Path,int Index,TArray<float>* Arg)
{
	static UFieldFunc* pFnGetVariableFloatArray = NULL;
	if(!pFnGetVariableFloatArray)
		pFnGetVariableFloatArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableFloatArray");

	GFxUI_GetVariableFloatArray_Parms GetVariableFloatArray_Parms;
	memcpy(&GetVariableFloatArray_Parms.Path,&Path,0xC);
	GetVariableFloatArray_Parms.Index = Index;
	pFnGetVariableFloatArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableFloatArray,NULL,&GetVariableFloatArray_Parms,NULL);
	pFnGetVariableFloatArray->FunctionFlags |= 0x400;
	if(Arg)
		memcpy(Arg,&GetVariableFloatArray_Parms.Arg,0xC);
	return GetVariableFloatArray_Parms.ReturnValue;
}

struct GFxUI_GetVariableBool_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::GetVariableBool(struct FString Path)
{
	static UFieldFunc* pFnGetVariableBool = NULL;
	if(!pFnGetVariableBool)
		pFnGetVariableBool = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableBool");

	GFxUI_GetVariableBool_Parms GetVariableBool_Parms;
	memcpy(&GetVariableBool_Parms.Path,&Path,0xC);
	pFnGetVariableBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableBool,NULL,&GetVariableBool_Parms,NULL);
	pFnGetVariableBool->FunctionFlags |= 0x400;
	return GetVariableBool_Parms.ReturnValue;
}

struct GFxUI_SetWidgetPathBinding_Parms
{
	class UGFxObject*                                  WidgetToBind;                                     		// 0x000000 (0x0004)              
	struct FName                                       Path;                                             		// 0x000004 (0x0008)              
};

void UGFxMoviePlayer::SetWidgetPathBinding(class UGFxObject* WidgetToBind,struct FName Path)
{
	static UFieldFunc* pFnSetWidgetPathBinding = NULL;
	if(!pFnSetWidgetPathBinding)
		pFnSetWidgetPathBinding = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetWidgetPathBinding");

	GFxUI_SetWidgetPathBinding_Parms SetWidgetPathBinding_Parms;
	SetWidgetPathBinding_Parms.WidgetToBind = WidgetToBind;
	memcpy(&SetWidgetPathBinding_Parms.Path,&Path,0x8);
	pFnSetWidgetPathBinding->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetWidgetPathBinding,NULL,&SetWidgetPathBinding_Parms,NULL);
	pFnSetWidgetPathBinding->FunctionFlags |= 0x400;
}

struct GFxUI_OnPostAdvance_Parms
{
	float                                              DeltaTime;                                        		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::OnPostAdvance(float DeltaTime)
{
	static UFieldFunc* pFnOnPostAdvance = NULL;
	if(!pFnOnPostAdvance)
		pFnOnPostAdvance = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.OnPostAdvance");

	GFxUI_OnPostAdvance_Parms OnPostAdvance_Parms;
	OnPostAdvance_Parms.DeltaTime = DeltaTime;
	ProcessEvent(pFnOnPostAdvance,NULL,&OnPostAdvance_Parms,NULL);
}

struct GFxUI_AddFocusIgnoreKey_Parms
{
	struct FName                                       Key;                                              		// 0x000000 (0x0008)              
};

void UGFxMoviePlayer::AddFocusIgnoreKey(struct FName Key)
{
	static UFieldFunc* pFnAddFocusIgnoreKey = NULL;
	if(!pFnAddFocusIgnoreKey)
		pFnAddFocusIgnoreKey = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.AddFocusIgnoreKey");

	GFxUI_AddFocusIgnoreKey_Parms AddFocusIgnoreKey_Parms;
	memcpy(&AddFocusIgnoreKey_Parms.Key,&Key,0x8);
	pFnAddFocusIgnoreKey->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddFocusIgnoreKey,NULL,&AddFocusIgnoreKey_Parms,NULL);
	pFnAddFocusIgnoreKey->FunctionFlags |= 0x400;
}

struct GFxUI_SetMovieCanReceiveInput_Parms
{
	unsigned long                                      bCanReceiveInput : 1;                             		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::SetMovieCanReceiveInput(bool bCanReceiveInput)
{
	static UFieldFunc* pFnSetMovieCanReceiveInput = NULL;
	if(!pFnSetMovieCanReceiveInput)
		pFnSetMovieCanReceiveInput = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetMovieCanReceiveInput");

	GFxUI_SetMovieCanReceiveInput_Parms SetMovieCanReceiveInput_Parms;
	SetMovieCanReceiveInput_Parms.bCanReceiveInput = bCanReceiveInput;
	pFnSetMovieCanReceiveInput->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetMovieCanReceiveInput,NULL,&SetMovieCanReceiveInput_Parms,NULL);
	pFnSetMovieCanReceiveInput->FunctionFlags |= 0x400;
}

struct GFxUI_SetMovieCanReceiveFocus_Parms
{
	unsigned long                                      bCanReceiveFocus : 1;                             		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::SetMovieCanReceiveFocus(bool bCanReceiveFocus)
{
	static UFieldFunc* pFnSetMovieCanReceiveFocus = NULL;
	if(!pFnSetMovieCanReceiveFocus)
		pFnSetMovieCanReceiveFocus = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetMovieCanReceiveFocus");

	GFxUI_SetMovieCanReceiveFocus_Parms SetMovieCanReceiveFocus_Parms;
	SetMovieCanReceiveFocus_Parms.bCanReceiveFocus = bCanReceiveFocus;
	pFnSetMovieCanReceiveFocus->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetMovieCanReceiveFocus,NULL,&SetMovieCanReceiveFocus_Parms,NULL);
	pFnSetMovieCanReceiveFocus->FunctionFlags |= 0x400;
}

struct GFxUI_SetExternalInterface_Parms
{
	class UObject*                                     H;                                                		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::SetExternalInterface(class UObject* H)
{
	static UFieldFunc* pFnSetExternalInterface = NULL;
	if(!pFnSetExternalInterface)
		pFnSetExternalInterface = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetExternalInterface");

	GFxUI_SetExternalInterface_Parms SetExternalInterface_Parms;
	SetExternalInterface_Parms.H = H;
	ProcessEvent(pFnSetExternalInterface,NULL,&SetExternalInterface_Parms,NULL);
}

struct GFxUI_ConditionalClearPause_Parms
{
	//class ULocalPlayer*                                LP;                                               		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::ConditionalClearPause()
{
	static UFieldFunc* pFnConditionalClearPause = NULL;
	if(!pFnConditionalClearPause)
		pFnConditionalClearPause = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ConditionalClearPause");

	GFxUI_ConditionalClearPause_Parms ConditionalClearPause_Parms;
	ProcessEvent(pFnConditionalClearPause,NULL,&ConditionalClearPause_Parms,NULL);
}

struct GFxUI_OnClose_Parms
{
};

void UGFxMoviePlayer::OnClose()
{
	static UFieldFunc* pFnOnClose = NULL;
	if(!pFnOnClose)
		pFnOnClose = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.OnClose");

	GFxUI_OnClose_Parms OnClose_Parms;
	ProcessEvent(pFnOnClose,NULL,&OnClose_Parms,NULL);
}

struct GFxUI_SetPause_Parms
{
	unsigned long                                      bPausePlayback : 1;                               		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::SetPause(bool bPausePlayback)
{
	static UFieldFunc* pFnSetPause = NULL;
	if(!pFnSetPause)
		pFnSetPause = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetPause");

	GFxUI_SetPause_Parms SetPause_Parms;
	SetPause_Parms.bPausePlayback = bPausePlayback;
	pFnSetPause->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetPause,NULL,&SetPause_Parms,NULL);
	pFnSetPause->FunctionFlags |= 0x400;
}

struct GFxUI_SetVariableIntArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<int>                                        Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::SetVariableIntArray(struct FString Path,int Index,TArray<int> Arg)
{
	static UFieldFunc* pFnSetVariableIntArray = NULL;
	if(!pFnSetVariableIntArray)
		pFnSetVariableIntArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableIntArray");

	GFxUI_SetVariableIntArray_Parms SetVariableIntArray_Parms;
	memcpy(&SetVariableIntArray_Parms.Path,&Path,0xC);
	SetVariableIntArray_Parms.Index = Index;
	memcpy(&SetVariableIntArray_Parms.Arg,&Arg,0xC);
	pFnSetVariableIntArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableIntArray,NULL,&SetVariableIntArray_Parms,NULL);
	pFnSetVariableIntArray->FunctionFlags |= 0x400;
	return SetVariableIntArray_Parms.ReturnValue;
}

struct GFxUI_SetVariableFloatArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<float>                                      Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::SetVariableFloatArray(struct FString Path,int Index,TArray<float> Arg)
{
	static UFieldFunc* pFnSetVariableFloatArray = NULL;
	if(!pFnSetVariableFloatArray)
		pFnSetVariableFloatArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableFloatArray");

	GFxUI_SetVariableFloatArray_Parms SetVariableFloatArray_Parms;
	memcpy(&SetVariableFloatArray_Parms.Path,&Path,0xC);
	SetVariableFloatArray_Parms.Index = Index;
	memcpy(&SetVariableFloatArray_Parms.Arg,&Arg,0xC);
	pFnSetVariableFloatArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableFloatArray,NULL,&SetVariableFloatArray_Parms,NULL);
	pFnSetVariableFloatArray->FunctionFlags |= 0x400;
	return SetVariableFloatArray_Parms.ReturnValue;
}

struct GFxUI_SetVariable_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	struct FASValue                                    Arg;                                              		// 0x00000C (0x001C)              
};

void UGFxMoviePlayer::SetVariable(struct FString Path,struct FASValue Arg)
{
	static UFieldFunc* pFnSetVariable = NULL;
	if(!pFnSetVariable)
		pFnSetVariable = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariable");

	GFxUI_SetVariable_Parms SetVariable_Parms;
	memcpy(&SetVariable_Parms.Path,&Path,0xC);
	memcpy(&SetVariable_Parms.Arg,&Arg,0x1C);
	pFnSetVariable->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariable,NULL,&SetVariable_Parms,NULL);
	pFnSetVariable->FunctionFlags |= 0x400;
}

struct GFxUI_SetVariableArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<struct FASValue>                            Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::SetVariableArray(struct FString Path,int Index,TArray<struct FASValue> Arg)
{
	static UFieldFunc* pFnSetVariableArray = NULL;
	if(!pFnSetVariableArray)
		pFnSetVariableArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableArray");

	GFxUI_SetVariableArray_Parms SetVariableArray_Parms;
	memcpy(&SetVariableArray_Parms.Path,&Path,0xC);
	SetVariableArray_Parms.Index = Index;
	memcpy(&SetVariableArray_Parms.Arg,&Arg,0xC);
	pFnSetVariableArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableArray,NULL,&SetVariableArray_Parms,NULL);
	pFnSetVariableArray->FunctionFlags |= 0x400;
	return SetVariableArray_Parms.ReturnValue;
}

struct GFxUI_RemoveAllDelegates_Parms
{
	class UObject*                                     TargetObject;                                     		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::RemoveAllDelegates(class UObject* TargetObject)
{
	static UFieldFunc* pFnRemoveAllDelegates = NULL;
	if(!pFnRemoveAllDelegates)
		pFnRemoveAllDelegates = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.RemoveAllDelegates");

	GFxUI_RemoveAllDelegates_Parms RemoveAllDelegates_Parms;
	RemoveAllDelegates_Parms.TargetObject = TargetObject;
	pFnRemoveAllDelegates->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRemoveAllDelegates,NULL,&RemoveAllDelegates_Parms,NULL);
	pFnRemoveAllDelegates->FunctionFlags |= 0x400;
}

struct GFxUI_Close_Parms
{
	unsigned long                                      Unload : 1;                                       		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::Close(bool Unload)
{
	static UFieldFunc* pFnClose = NULL;
	if(!pFnClose)
		pFnClose = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.Close");

	GFxUI_Close_Parms Close_Parms;
	Close_Parms.Unload = Unload;
	pFnClose->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClose,NULL,&Close_Parms,NULL);
	pFnClose->FunctionFlags |= 0x400;
}

struct GFxUI_GetVariableString_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UGFxMoviePlayer::GetVariableString(struct FString Path)
{
	static UFieldFunc* pFnGetVariableString = NULL;
	if(!pFnGetVariableString)
		pFnGetVariableString = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableString");

	GFxUI_GetVariableString_Parms GetVariableString_Parms;
	memcpy(&GetVariableString_Parms.Path,&Path,0xC);
	pFnGetVariableString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableString,NULL,&GetVariableString_Parms,NULL);
	pFnGetVariableString->FunctionFlags |= 0x400;
	return GetVariableString_Parms.ReturnValue;
}

struct GFxUI_GetVariableIntArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<int>                                        Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::GetVariableIntArray(struct FString Path,int Index,TArray<int>* Arg)
{
	static UFieldFunc* pFnGetVariableIntArray = NULL;
	if(!pFnGetVariableIntArray)
		pFnGetVariableIntArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableIntArray");

	GFxUI_GetVariableIntArray_Parms GetVariableIntArray_Parms;
	memcpy(&GetVariableIntArray_Parms.Path,&Path,0xC);
	GetVariableIntArray_Parms.Index = Index;
	pFnGetVariableIntArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableIntArray,NULL,&GetVariableIntArray_Parms,NULL);
	pFnGetVariableIntArray->FunctionFlags |= 0x400;
	if(Arg)
		memcpy(Arg,&GetVariableIntArray_Parms.Arg,0xC);
	return GetVariableIntArray_Parms.ReturnValue;
}

struct GFxUI_SetTimingMode_Parms
{
	unsigned char                                      Mode;                                             		// 0x000000 (0x0001)              
};

void UGFxMoviePlayer::SetTimingMode(unsigned char Mode)
{
	static UFieldFunc* pFnSetTimingMode = NULL;
	if(!pFnSetTimingMode)
		pFnSetTimingMode = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetTimingMode");

	GFxUI_SetTimingMode_Parms SetTimingMode_Parms;
	SetTimingMode_Parms.Mode = Mode;
	pFnSetTimingMode->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetTimingMode,NULL,&SetTimingMode_Parms,NULL);
	pFnSetTimingMode->FunctionFlags |= 0x400;
}

struct GFxUI_SetVariableInt_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                I;                                                		// 0x00000C (0x0004)              
};

void UGFxMoviePlayer::SetVariableInt(struct FString Path,int I)
{
	static UFieldFunc* pFnSetVariableInt = NULL;
	if(!pFnSetVariableInt)
		pFnSetVariableInt = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableInt");

	GFxUI_SetVariableInt_Parms SetVariableInt_Parms;
	memcpy(&SetVariableInt_Parms.Path,&Path,0xC);
	SetVariableInt_Parms.I = I;
	pFnSetVariableInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableInt,NULL,&SetVariableInt_Parms,NULL);
	pFnSetVariableInt->FunctionFlags |= 0x400;
}

struct GFxUI_PublishDataStoreValues_Parms
{
};

void UGFxMoviePlayer::PublishDataStoreValues()
{
	static UFieldFunc* pFnPublishDataStoreValues = NULL;
	if(!pFnPublishDataStoreValues)
		pFnPublishDataStoreValues = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.PublishDataStoreValues");

	GFxUI_PublishDataStoreValues_Parms PublishDataStoreValues_Parms;
	pFnPublishDataStoreValues->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPublishDataStoreValues,NULL,&PublishDataStoreValues_Parms,NULL);
	pFnPublishDataStoreValues->FunctionFlags |= 0x400;
}

struct GFxUI_SetVariableNumber_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	float                                              F;                                                		// 0x00000C (0x0004)              
};

void UGFxMoviePlayer::SetVariableNumber(struct FString Path,float F)
{
	static UFieldFunc* pFnSetVariableNumber = NULL;
	if(!pFnSetVariableNumber)
		pFnSetVariableNumber = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableNumber");

	GFxUI_SetVariableNumber_Parms SetVariableNumber_Parms;
	memcpy(&SetVariableNumber_Parms.Path,&Path,0xC);
	SetVariableNumber_Parms.F = F;
	pFnSetVariableNumber->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableNumber,NULL,&SetVariableNumber_Parms,NULL);
	pFnSetVariableNumber->FunctionFlags |= 0x400;
}

struct GFxUI_GetVariableStringArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<struct FString>                             Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::GetVariableStringArray(struct FString Path,int Index,TArray<struct FString>* Arg)
{
	static UFieldFunc* pFnGetVariableStringArray = NULL;
	if(!pFnGetVariableStringArray)
		pFnGetVariableStringArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableStringArray");

	GFxUI_GetVariableStringArray_Parms GetVariableStringArray_Parms;
	memcpy(&GetVariableStringArray_Parms.Path,&Path,0xC);
	GetVariableStringArray_Parms.Index = Index;
	pFnGetVariableStringArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableStringArray,NULL,&GetVariableStringArray_Parms,NULL);
	pFnGetVariableStringArray->FunctionFlags |= 0x400;
	if(Arg)
		memcpy(Arg,&GetVariableStringArray_Parms.Arg,0xC);
	return GetVariableStringArray_Parms.ReturnValue;
}

struct GFxUI_SetVariableStringArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<struct FString>                             Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::SetVariableStringArray(struct FString Path,int Index,TArray<struct FString> Arg)
{
	static UFieldFunc* pFnSetVariableStringArray = NULL;
	if(!pFnSetVariableStringArray)
		pFnSetVariableStringArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableStringArray");

	GFxUI_SetVariableStringArray_Parms SetVariableStringArray_Parms;
	memcpy(&SetVariableStringArray_Parms.Path,&Path,0xC);
	SetVariableStringArray_Parms.Index = Index;
	memcpy(&SetVariableStringArray_Parms.Arg,&Arg,0xC);
	pFnSetVariableStringArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableStringArray,NULL,&SetVariableStringArray_Parms,NULL);
	pFnSetVariableStringArray->FunctionFlags |= 0x400;
	return SetVariableStringArray_Parms.ReturnValue;
}

struct GFxUI_Init_Parms
{
	class ULocalPlayer*                                LocPlay;                                          		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::Init(class ULocalPlayer* LocPlay)
{
	static UFieldFunc* pFnInit = NULL;
	if(!pFnInit)
		pFnInit = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.Init");

	GFxUI_Init_Parms Init_Parms;
	Init_Parms.LocPlay = LocPlay;
	ProcessEvent(pFnInit,NULL,&Init_Parms,NULL);
}

struct GFxUI_GetPC_Parms
{
	class APlayerController*                           ReturnValue;                                      		// 0x000000 (0x0004)              
	//class ULocalPlayer*                                LocalPlayerOwner;                                 		// 0x000004 (0x0004)              
};

class APlayerController* UGFxMoviePlayer::GetPC()
{
	static UFieldFunc* pFnGetPC = NULL;
	if(!pFnGetPC)
		pFnGetPC = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetPC");

	GFxUI_GetPC_Parms GetPC_Parms;
	ProcessEvent(pFnGetPC,NULL,&GetPC_Parms,NULL);
	return GetPC_Parms.ReturnValue;
}

struct GFxUI_SetExternalTexture_Parms
{
	struct FString                                     Resource;                                         		// 0x000000 (0x000C)              
	class UTexture*                                    Texture;                                          		// 0x00000C (0x0004)              
	unsigned long                                      bUpdateScale : 1;                                 		// 0x000010 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::SetExternalTexture(struct FString Resource,class UTexture* Texture,bool bUpdateScale)
{
	static UFieldFunc* pFnSetExternalTexture = NULL;
	if(!pFnSetExternalTexture)
		pFnSetExternalTexture = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetExternalTexture");

	GFxUI_SetExternalTexture_Parms SetExternalTexture_Parms;
	memcpy(&SetExternalTexture_Parms.Resource,&Resource,0xC);
	SetExternalTexture_Parms.Texture = Texture;
	SetExternalTexture_Parms.bUpdateScale = bUpdateScale;
	pFnSetExternalTexture->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetExternalTexture,NULL,&SetExternalTexture_Parms,NULL);
	pFnSetExternalTexture->FunctionFlags |= 0x400;
	return SetExternalTexture_Parms.ReturnValue;
}

struct GFxUI_ActionScriptFloat_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UGFxMoviePlayer::ActionScriptFloat(struct FString Path)
{
	static UFieldFunc* pFnActionScriptFloat = NULL;
	if(!pFnActionScriptFloat)
		pFnActionScriptFloat = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptFloat");

	GFxUI_ActionScriptFloat_Parms ActionScriptFloat_Parms;
	memcpy(&ActionScriptFloat_Parms.Path,&Path,0xC);
	pFnActionScriptFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptFloat,NULL,&ActionScriptFloat_Parms,NULL);
	pFnActionScriptFloat->FunctionFlags |= 0x400;
	return ActionScriptFloat_Parms.ReturnValue;
}

struct GFxUI_RemoveDelegate_Parms
{
	class UObject*                                     TargetObject;                                     		// 0x000000 (0x0004)              
	struct FName                                       FunctionName;                                     		// 0x000004 (0x0008)              
};

void UGFxMoviePlayer::RemoveDelegate(class UObject* TargetObject,struct FName FunctionName)
{
	static UFieldFunc* pFnRemoveDelegate = NULL;
	if(!pFnRemoveDelegate)
		pFnRemoveDelegate = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.RemoveDelegate");

	GFxUI_RemoveDelegate_Parms RemoveDelegate_Parms;
	RemoveDelegate_Parms.TargetObject = TargetObject;
	memcpy(&RemoveDelegate_Parms.FunctionName,&FunctionName,0x8);
	pFnRemoveDelegate->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRemoveDelegate,NULL,&RemoveDelegate_Parms,NULL);
	pFnRemoveDelegate->FunctionFlags |= 0x400;
}

struct GFxUI_SetPriority_Parms
{
	unsigned char                                      NewPriority;                                      		// 0x000000 (0x0001)              
};

void UGFxMoviePlayer::SetPriority(unsigned char NewPriority)
{
	static UFieldFunc* pFnSetPriority = NULL;
	if(!pFnSetPriority)
		pFnSetPriority = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetPriority");

	GFxUI_SetPriority_Parms SetPriority_Parms;
	SetPriority_Parms.NewPriority = NewPriority;
	pFnSetPriority->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetPriority,NULL,&SetPriority_Parms,NULL);
	pFnSetPriority->FunctionFlags |= 0x400;
}

struct GFxUI_CreateArray_Parms
{
	class UGFxObject*                                  ReturnValue;                                      		// 0x000000 (0x0004)              
};

class UGFxObject* UGFxMoviePlayer::CreateArray()
{
	static UFieldFunc* pFnCreateArray = NULL;
	if(!pFnCreateArray)
		pFnCreateArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.CreateArray");

	GFxUI_CreateArray_Parms CreateArray_Parms;
	pFnCreateArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCreateArray,NULL,&CreateArray_Parms,NULL);
	pFnCreateArray->FunctionFlags |= 0x400;
	return CreateArray_Parms.ReturnValue;
}

struct GFxUI_SetPerspective3D_Parms
{
	FMatrix                                            matPersp;                                         		// 0x000000 (0x0040)              
};

void UGFxMoviePlayer::SetPerspective3D(FMatrix* matPersp)
{
	static UFieldFunc* pFnSetPerspective3D = NULL;
	if(!pFnSetPerspective3D)
		pFnSetPerspective3D = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetPerspective3D");

	GFxUI_SetPerspective3D_Parms SetPerspective3D_Parms;
	pFnSetPerspective3D->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetPerspective3D,NULL,&SetPerspective3D_Parms,NULL);
	pFnSetPerspective3D->FunctionFlags |= 0x400;
	if(matPersp)
		memcpy(matPersp,&SetPerspective3D_Parms.matPersp,0x40);
}

struct GFxUI_ActionScriptVoid_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
};

void UGFxMoviePlayer::ActionScriptVoid(struct FString Path)
{
	static UFieldFunc* pFnActionScriptVoid = NULL;
	if(!pFnActionScriptVoid)
		pFnActionScriptVoid = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptVoid");

	GFxUI_ActionScriptVoid_Parms ActionScriptVoid_Parms;
	memcpy(&ActionScriptVoid_Parms.Path,&Path,0xC);
	pFnActionScriptVoid->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptVoid,NULL,&ActionScriptVoid_Parms,NULL);
	pFnActionScriptVoid->FunctionFlags |= 0x400;
}

struct GFxUI_GetVariable_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	struct FASValue                                    ReturnValue;                                      		// 0x00000C (0x001C)              
};

struct FASValue UGFxMoviePlayer::GetVariable(struct FString Path)
{
	static UFieldFunc* pFnGetVariable = NULL;
	if(!pFnGetVariable)
		pFnGetVariable = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariable");

	GFxUI_GetVariable_Parms GetVariable_Parms;
	memcpy(&GetVariable_Parms.Path,&Path,0xC);
	pFnGetVariable->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariable,NULL,&GetVariable_Parms,NULL);
	pFnGetVariable->FunctionFlags |= 0x400;
	return GetVariable_Parms.ReturnValue;
}

struct GFxUI_ApplyPriorityBlurEffect_Parms
{
	unsigned long                                      bRemoveEffect : 1;                                		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::ApplyPriorityBlurEffect(bool bRemoveEffect)
{
	static UFieldFunc* pFnApplyPriorityBlurEffect = NULL;
	if(!pFnApplyPriorityBlurEffect)
		pFnApplyPriorityBlurEffect = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ApplyPriorityBlurEffect");

	GFxUI_ApplyPriorityBlurEffect_Parms ApplyPriorityBlurEffect_Parms;
	ApplyPriorityBlurEffect_Parms.bRemoveEffect = bRemoveEffect;
	ProcessEvent(pFnApplyPriorityBlurEffect,NULL,&ApplyPriorityBlurEffect_Parms,NULL);
}

struct GFxUI_SetAlignment_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
};

void UGFxMoviePlayer::SetAlignment(unsigned char A)
{
	static UFieldFunc* pFnSetAlignment = NULL;
	if(!pFnSetAlignment)
		pFnSetAlignment = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetAlignment");

	GFxUI_SetAlignment_Parms SetAlignment_Parms;
	SetAlignment_Parms.A = A;
	pFnSetAlignment->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetAlignment,NULL,&SetAlignment_Parms,NULL);
	pFnSetAlignment->FunctionFlags |= 0x400;
}

struct GFxUI_GetVariableNumber_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UGFxMoviePlayer::GetVariableNumber(struct FString Path)
{
	static UFieldFunc* pFnGetVariableNumber = NULL;
	if(!pFnGetVariableNumber)
		pFnGetVariableNumber = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableNumber");

	GFxUI_GetVariableNumber_Parms GetVariableNumber_Parms;
	memcpy(&GetVariableNumber_Parms.Path,&Path,0xC);
	pFnGetVariableNumber->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableNumber,NULL,&GetVariableNumber_Parms,NULL);
	pFnGetVariableNumber->FunctionFlags |= 0x400;
	return GetVariableNumber_Parms.ReturnValue;
}

struct GFxUI_ActionScriptObject_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x00000C (0x0004)              
};

class UGFxObject* UGFxMoviePlayer::ActionScriptObject(struct FString Path)
{
	static UFieldFunc* pFnActionScriptObject = NULL;
	if(!pFnActionScriptObject)
		pFnActionScriptObject = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ActionScriptObject");

	GFxUI_ActionScriptObject_Parms ActionScriptObject_Parms;
	memcpy(&ActionScriptObject_Parms.Path,&Path,0xC);
	pFnActionScriptObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptObject,NULL,&ActionScriptObject_Parms,NULL);
	pFnActionScriptObject->FunctionFlags |= 0x400;
	return ActionScriptObject_Parms.ReturnValue;
}

struct GFxUI_SetViewScaleMode_Parms
{
	unsigned char                                      SM;                                               		// 0x000000 (0x0001)              
};

void UGFxMoviePlayer::SetViewScaleMode(unsigned char SM)
{
	static UFieldFunc* pFnSetViewScaleMode = NULL;
	if(!pFnSetViewScaleMode)
		pFnSetViewScaleMode = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetViewScaleMode");

	GFxUI_SetViewScaleMode_Parms SetViewScaleMode_Parms;
	SetViewScaleMode_Parms.SM = SM;
	pFnSetViewScaleMode->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetViewScaleMode,NULL,&SetViewScaleMode_Parms,NULL);
	pFnSetViewScaleMode->FunctionFlags |= 0x400;
}

struct GFxUI_GetVariableInt_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UGFxMoviePlayer::GetVariableInt(struct FString Path)
{
	static UFieldFunc* pFnGetVariableInt = NULL;
	if(!pFnGetVariableInt)
		pFnGetVariableInt = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableInt");

	GFxUI_GetVariableInt_Parms GetVariableInt_Parms;
	memcpy(&GetVariableInt_Parms.Path,&Path,0xC);
	pFnGetVariableInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableInt,NULL,&GetVariableInt_Parms,NULL);
	pFnGetVariableInt->FunctionFlags |= 0x400;
	return GetVariableInt_Parms.ReturnValue;
}

struct GFxUI_SetView3D_Parms
{
	FMatrix                                            matView;                                          		// 0x000000 (0x0040)              
};

void UGFxMoviePlayer::SetView3D(FMatrix* matView)
{
	static UFieldFunc* pFnSetView3D = NULL;
	if(!pFnSetView3D)
		pFnSetView3D = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetView3D");

	GFxUI_SetView3D_Parms SetView3D_Parms;
	pFnSetView3D->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetView3D,NULL,&SetView3D_Parms,NULL);
	pFnSetView3D->FunctionFlags |= 0x400;
	if(matView)
		memcpy(matView,&SetView3D_Parms.matView,0x40);
}

struct GFxUI_SetVariableObject_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	class UGFxObject*                                  Object;                                           		// 0x00000C (0x0004)              
};

void UGFxMoviePlayer::SetVariableObject(struct FString Path,class UGFxObject* Object)
{
	static UFieldFunc* pFnSetVariableObject = NULL;
	if(!pFnSetVariableObject)
		pFnSetVariableObject = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableObject");

	GFxUI_SetVariableObject_Parms SetVariableObject_Parms;
	memcpy(&SetVariableObject_Parms.Path,&Path,0xC);
	SetVariableObject_Parms.Object = Object;
	pFnSetVariableObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableObject,NULL,&SetVariableObject_Parms,NULL);
	pFnSetVariableObject->FunctionFlags |= 0x400;
}

struct GFxUI_PostAdvance_Parms
{
	float                                              DeltaTime;                                        		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::PostAdvance(float DeltaTime)
{
	static UFieldFunc* pFnPostAdvance = NULL;
	if(!pFnPostAdvance)
		pFnPostAdvance = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.PostAdvance");

	GFxUI_PostAdvance_Parms PostAdvance_Parms;
	PostAdvance_Parms.DeltaTime = DeltaTime;
	pFnPostAdvance->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPostAdvance,NULL,&PostAdvance_Parms,NULL);
	pFnPostAdvance->FunctionFlags |= 0x400;
}

struct GFxUI_SetVariableBool_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	unsigned long                                      B : 1;                                            		// 0x00000C (0x0004) [0x00000001] 
};

void UGFxMoviePlayer::SetVariableBool(struct FString Path,bool B)
{
	static UFieldFunc* pFnSetVariableBool = NULL;
	if(!pFnSetVariableBool)
		pFnSetVariableBool = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.SetVariableBool");

	GFxUI_SetVariableBool_Parms SetVariableBool_Parms;
	memcpy(&SetVariableBool_Parms.Path,&Path,0xC);
	SetVariableBool_Parms.B = B;
	pFnSetVariableBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVariableBool,NULL,&SetVariableBool_Parms,NULL);
	pFnSetVariableBool->FunctionFlags |= 0x400;
}

struct GFxUI_GetVisibleFrameRect_Parms
{
	float                                              x0;                                               		// 0x000000 (0x0004)              
	float                                              y0;                                               		// 0x000004 (0x0004)              
	float                                              X1;                                               		// 0x000008 (0x0004)              
	float                                              Y1;                                               		// 0x00000C (0x0004)              
};

void UGFxMoviePlayer::GetVisibleFrameRect(float* x0,float* y0,float* X1,float* Y1)
{
	static UFieldFunc* pFnGetVisibleFrameRect = NULL;
	if(!pFnGetVisibleFrameRect)
		pFnGetVisibleFrameRect = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVisibleFrameRect");

	GFxUI_GetVisibleFrameRect_Parms GetVisibleFrameRect_Parms;
	pFnGetVisibleFrameRect->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVisibleFrameRect,NULL,&GetVisibleFrameRect_Parms,NULL);
	pFnGetVisibleFrameRect->FunctionFlags |= 0x400;
	if(x0)
		*x0 = GetVisibleFrameRect_Parms.x0;
	if(y0)
		*y0 = GetVisibleFrameRect_Parms.y0;
	if(X1)
		*X1 = GetVisibleFrameRect_Parms.X1;
	if(Y1)
		*Y1 = GetVisibleFrameRect_Parms.Y1;
}

struct GFxUI_GetVariableArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	int                                                Index;                                            		// 0x00000C (0x0004)              
	TArray<struct FASValue>                            Arg;                                              		// 0x000010 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::GetVariableArray(struct FString Path,int Index,TArray<struct FASValue>* Arg)
{
	static UFieldFunc* pFnGetVariableArray = NULL;
	if(!pFnGetVariableArray)
		pFnGetVariableArray = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.GetVariableArray");

	GFxUI_GetVariableArray_Parms GetVariableArray_Parms;
	memcpy(&GetVariableArray_Parms.Path,&Path,0xC);
	GetVariableArray_Parms.Index = Index;
	pFnGetVariableArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetVariableArray,NULL,&GetVariableArray_Parms,NULL);
	pFnGetVariableArray->FunctionFlags |= 0x400;
	if(Arg)
		memcpy(Arg,&GetVariableArray_Parms.Arg,0xC);
	return GetVariableArray_Parms.ReturnValue;
}

struct GFxUI_ClearCaptureKeys_Parms
{
};

void UGFxMoviePlayer::ClearCaptureKeys()
{
	static UFieldFunc* pFnClearCaptureKeys = NULL;
	if(!pFnClearCaptureKeys)
		pFnClearCaptureKeys = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ClearCaptureKeys");

	GFxUI_ClearCaptureKeys_Parms ClearCaptureKeys_Parms;
	pFnClearCaptureKeys->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClearCaptureKeys,NULL,&ClearCaptureKeys_Parms,NULL);
	pFnClearCaptureKeys->FunctionFlags |= 0x400;
}

struct GFxUI_WidgetInitialized_Parms
{
	struct FName                                       WidgetName;                                       		// 0x000000 (0x0008)              
	struct FName                                       WidgetPath;                                       		// 0x000008 (0x0008)              
	class UGFxObject*                                  Widget;                                           		// 0x000010 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UGFxMoviePlayer::WidgetInitialized(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget)
{
	static UFieldFunc* pFnWidgetInitialized = NULL;
	if(!pFnWidgetInitialized)
		pFnWidgetInitialized = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.WidgetInitialized");

	GFxUI_WidgetInitialized_Parms WidgetInitialized_Parms;
	memcpy(&WidgetInitialized_Parms.WidgetName,&WidgetName,0x8);
	memcpy(&WidgetInitialized_Parms.WidgetPath,&WidgetPath,0x8);
	WidgetInitialized_Parms.Widget = Widget;
	ProcessEvent(pFnWidgetInitialized,NULL,&WidgetInitialized_Parms,NULL);
	return WidgetInitialized_Parms.ReturnValue;
}

struct GFxUI_Advance_Parms
{
	float                                              Time;                                             		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::Advance(float Time)
{
	static UFieldFunc* pFnAdvance = NULL;
	if(!pFnAdvance)
		pFnAdvance = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.Advance");

	GFxUI_Advance_Parms Advance_Parms;
	Advance_Parms.Time = Time;
	pFnAdvance->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdvance,NULL,&Advance_Parms,NULL);
	pFnAdvance->FunctionFlags |= 0x400;
}

struct GFxUI_ClearFocusIgnoreKeys_Parms
{
};

void UGFxMoviePlayer::ClearFocusIgnoreKeys()
{
	static UFieldFunc* pFnClearFocusIgnoreKeys = NULL;
	if(!pFnClearFocusIgnoreKeys)
		pFnClearFocusIgnoreKeys = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.ClearFocusIgnoreKeys");

	GFxUI_ClearFocusIgnoreKeys_Parms ClearFocusIgnoreKeys_Parms;
	pFnClearFocusIgnoreKeys->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClearFocusIgnoreKeys,NULL,&ClearFocusIgnoreKeys_Parms,NULL);
	pFnClearFocusIgnoreKeys->FunctionFlags |= 0x400;
}

struct GFxUI_CleanupDelegates_Parms
{
};

void UGFxMoviePlayer::CleanupDelegates()
{
	static UFieldFunc* pFnCleanupDelegates = NULL;
	if(!pFnCleanupDelegates)
		pFnCleanupDelegates = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.CleanupDelegates");

	GFxUI_CleanupDelegates_Parms CleanupDelegates_Parms;
	pFnCleanupDelegates->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCleanupDelegates,NULL,&CleanupDelegates_Parms,NULL);
	pFnCleanupDelegates->FunctionFlags |= 0x400;
}

struct GFxUI_OnFocusLost_Parms
{
	int                                                LocalPlayerIndex;                                 		// 0x000000 (0x0004)              
};

void UGFxMoviePlayer::OnFocusLost(int LocalPlayerIndex)
{
	static UFieldFunc* pFnOnFocusLost = NULL;
	if(!pFnOnFocusLost)
		pFnOnFocusLost = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.OnFocusLost");

	GFxUI_OnFocusLost_Parms OnFocusLost_Parms;
	OnFocusLost_Parms.LocalPlayerIndex = LocalPlayerIndex;
	ProcessEvent(pFnOnFocusLost,NULL,&OnFocusLost_Parms,NULL);
}

struct GFxUI_Invoke_Parms
{
	struct FString                                     method;                                           		// 0x000000 (0x000C)              
	TArray<struct FASValue>                            args;                                             		// 0x00000C (0x000C)              
	struct FASValue                                    ReturnValue;                                      		// 0x000018 (0x001C)              
};

struct FASValue UGFxMoviePlayer::Invoke(struct FString method,TArray<struct FASValue> args)
{
	static UFieldFunc* pFnInvoke = NULL;
	if(!pFnInvoke)
		pFnInvoke = UObject::FindFunction("Function GFxUI.GFxMoviePlayer.Invoke");

	GFxUI_Invoke_Parms Invoke_Parms;
	memcpy(&Invoke_Parms.method,&method,0xC);
	memcpy(&Invoke_Parms.args,&args,0xC);
	pFnInvoke->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInvoke,NULL,&Invoke_Parms,NULL);
	pFnInvoke->FunctionFlags |= 0x400;
	return Invoke_Parms.ReturnValue;
}

struct GFxUI_GetElementString_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UGFxObject::GetElementString(int Index)
{
	static UFieldFunc* pFnGetElementString = NULL;
	if(!pFnGetElementString)
		pFnGetElementString = UObject::FindFunction("Function GFxUI.GFxObject.GetElementString");

	GFxUI_GetElementString_Parms GetElementString_Parms;
	GetElementString_Parms.Index = Index;
	pFnGetElementString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementString,NULL,&GetElementString_Parms,NULL);
	pFnGetElementString->FunctionFlags |= 0x400;
	return GetElementString_Parms.ReturnValue;
}

struct GFxUI_Invoke_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	TArray<struct FASValue>                            args;                                             		// 0x00000C (0x000C)              
	struct FASValue                                    ReturnValue;                                      		// 0x000018 (0x001C)              
};

struct FASValue UGFxObject::Invoke(struct FString Member,TArray<struct FASValue> args)
{
	static UFieldFunc* pFnInvoke = NULL;
	if(!pFnInvoke)
		pFnInvoke = UObject::FindFunction("Function GFxUI.GFxObject.Invoke");

	GFxUI_Invoke_Parms Invoke_Parms;
	memcpy(&Invoke_Parms.Member,&Member,0xC);
	memcpy(&Invoke_Parms.args,&args,0xC);
	pFnInvoke->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInvoke,NULL,&Invoke_Parms,NULL);
	pFnInvoke->FunctionFlags |= 0x400;
	return Invoke_Parms.ReturnValue;
}

struct GFxUI_GetInt_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UGFxObject::GetInt(struct FString Member)
{
	static UFieldFunc* pFnGetInt = NULL;
	if(!pFnGetInt)
		pFnGetInt = UObject::FindFunction("Function GFxUI.GFxObject.GetInt");

	GFxUI_GetInt_Parms GetInt_Parms;
	memcpy(&GetInt_Parms.Member,&Member,0xC);
	pFnGetInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetInt,NULL,&GetInt_Parms,NULL);
	pFnGetInt->FunctionFlags |= 0x400;
	return GetInt_Parms.ReturnValue;
}

struct GFxUI_SetFunction_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	struct FScriptDelegate                             functionDelegate;                                 		// 0x00000C (0x000C)              
};

void UGFxObject::SetFunction(struct FString Member,struct FScriptDelegate functionDelegate)
{
	static UFieldFunc* pFnSetFunction = NULL;
	if(!pFnSetFunction)
		pFnSetFunction = UObject::FindFunction("Function GFxUI.GFxObject.SetFunction");

	GFxUI_SetFunction_Parms SetFunction_Parms;
	memcpy(&SetFunction_Parms.Member,&Member,0xC);
	memcpy(&SetFunction_Parms.functionDelegate,&functionDelegate,0xC);
	pFnSetFunction->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetFunction,NULL,&SetFunction_Parms,NULL);
	pFnSetFunction->FunctionFlags |= 0x400;
}

struct GFxUI_GotoAndStop_Parms
{
	struct FString                                     frame;                                            		// 0x000000 (0x000C)              
};

void UGFxObject::GotoAndStop(struct FString frame)
{
	static UFieldFunc* pFnGotoAndStop = NULL;
	if(!pFnGotoAndStop)
		pFnGotoAndStop = UObject::FindFunction("Function GFxUI.GFxObject.GotoAndStop");

	GFxUI_GotoAndStop_Parms GotoAndStop_Parms;
	memcpy(&GotoAndStop_Parms.frame,&frame,0xC);
	pFnGotoAndStop->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGotoAndStop,NULL,&GotoAndStop_Parms,NULL);
	pFnGotoAndStop->FunctionFlags |= 0x400;
}

struct GFxUI_SetFloat_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	float                                              F;                                                		// 0x00000C (0x0004)              
};

void UGFxObject::SetFloat(struct FString Member,float F)
{
	static UFieldFunc* pFnSetFloat = NULL;
	if(!pFnSetFloat)
		pFnSetFloat = UObject::FindFunction("Function GFxUI.GFxObject.SetFloat");

	GFxUI_SetFloat_Parms SetFloat_Parms;
	memcpy(&SetFloat_Parms.Member,&Member,0xC);
	SetFloat_Parms.F = F;
	pFnSetFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetFloat,NULL,&SetFloat_Parms,NULL);
	pFnSetFloat->FunctionFlags |= 0x400;
}

struct GFxUI_CreateEmptyMovieClip_Parms
{
	struct FString                                     instanceName;                                     		// 0x000000 (0x000C)              
	int                                                depth;                                            		// 0x00000C (0x0004)              
	class UClass*                                      Type;                                             		// 0x000010 (0x0004)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x000014 (0x0004)              
};

class UGFxObject* UGFxObject::CreateEmptyMovieClip(struct FString instanceName,int depth,class UClass* Type)
{
	static UFieldFunc* pFnCreateEmptyMovieClip = NULL;
	if(!pFnCreateEmptyMovieClip)
		pFnCreateEmptyMovieClip = UObject::FindFunction("Function GFxUI.GFxObject.CreateEmptyMovieClip");

	GFxUI_CreateEmptyMovieClip_Parms CreateEmptyMovieClip_Parms;
	memcpy(&CreateEmptyMovieClip_Parms.instanceName,&instanceName,0xC);
	CreateEmptyMovieClip_Parms.depth = depth;
	CreateEmptyMovieClip_Parms.Type = Type;
	pFnCreateEmptyMovieClip->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCreateEmptyMovieClip,NULL,&CreateEmptyMovieClip_Parms,NULL);
	pFnCreateEmptyMovieClip->FunctionFlags |= 0x400;
	return CreateEmptyMovieClip_Parms.ReturnValue;
}

struct GFxUI_GetElementInt_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UGFxObject::GetElementInt(int Index)
{
	static UFieldFunc* pFnGetElementInt = NULL;
	if(!pFnGetElementInt)
		pFnGetElementInt = UObject::FindFunction("Function GFxUI.GFxObject.GetElementInt");

	GFxUI_GetElementInt_Parms GetElementInt_Parms;
	GetElementInt_Parms.Index = Index;
	pFnGetElementInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementInt,NULL,&GetElementInt_Parms,NULL);
	pFnGetElementInt->FunctionFlags |= 0x400;
	return GetElementInt_Parms.ReturnValue;
}

struct GFxUI_ActionScriptFloat_Parms
{
	struct FString                                     method;                                           		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UGFxObject::ActionScriptFloat(struct FString method)
{
	static UFieldFunc* pFnActionScriptFloat = NULL;
	if(!pFnActionScriptFloat)
		pFnActionScriptFloat = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptFloat");

	GFxUI_ActionScriptFloat_Parms ActionScriptFloat_Parms;
	memcpy(&ActionScriptFloat_Parms.method,&method,0xC);
	pFnActionScriptFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptFloat,NULL,&ActionScriptFloat_Parms,NULL);
	pFnActionScriptFloat->FunctionFlags |= 0x400;
	return ActionScriptFloat_Parms.ReturnValue;
}

struct GFxUI_GetDisplayInfo_Parms
{
	struct FASDisplayInfo                              ReturnValue;                                      		// 0x000000 (0x002C)              
};

struct FASDisplayInfo UGFxObject::GetDisplayInfo()
{
	static UFieldFunc* pFnGetDisplayInfo = NULL;
	if(!pFnGetDisplayInfo)
		pFnGetDisplayInfo = UObject::FindFunction("Function GFxUI.GFxObject.GetDisplayInfo");

	GFxUI_GetDisplayInfo_Parms GetDisplayInfo_Parms;
	pFnGetDisplayInfo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetDisplayInfo,NULL,&GetDisplayInfo_Parms,NULL);
	pFnGetDisplayInfo->FunctionFlags |= 0x400;
	return GetDisplayInfo_Parms.ReturnValue;
}

struct GFxUI_GetBool_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UGFxObject::GetBool(struct FString Member)
{
	static UFieldFunc* pFnGetBool = NULL;
	if(!pFnGetBool)
		pFnGetBool = UObject::FindFunction("Function GFxUI.GFxObject.GetBool");

	GFxUI_GetBool_Parms GetBool_Parms;
	memcpy(&GetBool_Parms.Member,&Member,0xC);
	pFnGetBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetBool,NULL,&GetBool_Parms,NULL);
	pFnGetBool->FunctionFlags |= 0x400;
	return GetBool_Parms.ReturnValue;
}

struct GFxUI_ActionScriptObject_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x00000C (0x0004)              
};

class UGFxObject* UGFxObject::ActionScriptObject(struct FString Path)
{
	static UFieldFunc* pFnActionScriptObject = NULL;
	if(!pFnActionScriptObject)
		pFnActionScriptObject = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptObject");

	GFxUI_ActionScriptObject_Parms ActionScriptObject_Parms;
	memcpy(&ActionScriptObject_Parms.Path,&Path,0xC);
	pFnActionScriptObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptObject,NULL,&ActionScriptObject_Parms,NULL);
	pFnActionScriptObject->FunctionFlags |= 0x400;
	return ActionScriptObject_Parms.ReturnValue;
}

struct GFxUI_GotoAndStopI_Parms
{
	int                                                frame;                                            		// 0x000000 (0x0004)              
};

void UGFxObject::GotoAndStopI(int frame)
{
	static UFieldFunc* pFnGotoAndStopI = NULL;
	if(!pFnGotoAndStopI)
		pFnGotoAndStopI = UObject::FindFunction("Function GFxUI.GFxObject.GotoAndStopI");

	GFxUI_GotoAndStopI_Parms GotoAndStopI_Parms;
	GotoAndStopI_Parms.frame = frame;
	pFnGotoAndStopI->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGotoAndStopI,NULL,&GotoAndStopI_Parms,NULL);
	pFnGotoAndStopI->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementMemberFloat_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	float                                              F;                                                		// 0x000010 (0x0004)              
};

void UGFxObject::SetElementMemberFloat(int Index,struct FString Member,float F)
{
	static UFieldFunc* pFnSetElementMemberFloat = NULL;
	if(!pFnSetElementMemberFloat)
		pFnSetElementMemberFloat = UObject::FindFunction("Function GFxUI.GFxObject.SetElementMemberFloat");

	GFxUI_SetElementMemberFloat_Parms SetElementMemberFloat_Parms;
	SetElementMemberFloat_Parms.Index = Index;
	memcpy(&SetElementMemberFloat_Parms.Member,&Member,0xC);
	SetElementMemberFloat_Parms.F = F;
	pFnSetElementMemberFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementMemberFloat,NULL,&SetElementMemberFloat_Parms,NULL);
	pFnSetElementMemberFloat->FunctionFlags |= 0x400;
}

struct GFxUI_SetVisible_Parms
{
	unsigned long                                      Visible : 1;                                      		// 0x000000 (0x0004) [0x00000001] 
};

void UGFxObject::SetVisible(bool Visible)
{
	static UFieldFunc* pFnSetVisible = NULL;
	if(!pFnSetVisible)
		pFnSetVisible = UObject::FindFunction("Function GFxUI.GFxObject.SetVisible");

	GFxUI_SetVisible_Parms SetVisible_Parms;
	SetVisible_Parms.Visible = Visible;
	pFnSetVisible->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetVisible,NULL,&SetVisible_Parms,NULL);
	pFnSetVisible->FunctionFlags |= 0x400;
}

struct GFxUI_GetElementDisplayInfo_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FASDisplayInfo                              ReturnValue;                                      		// 0x000004 (0x002C)              
};

struct FASDisplayInfo UGFxObject::GetElementDisplayInfo(int Index)
{
	static UFieldFunc* pFnGetElementDisplayInfo = NULL;
	if(!pFnGetElementDisplayInfo)
		pFnGetElementDisplayInfo = UObject::FindFunction("Function GFxUI.GFxObject.GetElementDisplayInfo");

	GFxUI_GetElementDisplayInfo_Parms GetElementDisplayInfo_Parms;
	GetElementDisplayInfo_Parms.Index = Index;
	pFnGetElementDisplayInfo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementDisplayInfo,NULL,&GetElementDisplayInfo_Parms,NULL);
	pFnGetElementDisplayInfo->FunctionFlags |= 0x400;
	return GetElementDisplayInfo_Parms.ReturnValue;
}

struct GFxUI_GetPosition_Parms
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UGFxObject::GetPosition(float* X,float* Y)
{
	static UFieldFunc* pFnGetPosition = NULL;
	if(!pFnGetPosition)
		pFnGetPosition = UObject::FindFunction("Function GFxUI.GFxObject.GetPosition");

	GFxUI_GetPosition_Parms GetPosition_Parms;
	pFnGetPosition->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetPosition,NULL,&GetPosition_Parms,NULL);
	pFnGetPosition->FunctionFlags |= 0x400;
	if(X)
		*X = GetPosition_Parms.X;
	if(Y)
		*Y = GetPosition_Parms.Y;
	return GetPosition_Parms.ReturnValue;
}

struct GFxUI_SetElement_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FASValue                                    Arg;                                              		// 0x000004 (0x001C)              
};

void UGFxObject::SetElement(int Index,struct FASValue Arg)
{
	static UFieldFunc* pFnSetElement = NULL;
	if(!pFnSetElement)
		pFnSetElement = UObject::FindFunction("Function GFxUI.GFxObject.SetElement");

	GFxUI_SetElement_Parms SetElement_Parms;
	SetElement_Parms.Index = Index;
	memcpy(&SetElement_Parms.Arg,&Arg,0x1C);
	pFnSetElement->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElement,NULL,&SetElement_Parms,NULL);
	pFnSetElement->FunctionFlags |= 0x400;
}

struct GFxUI_GetElementObject_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	class UClass*                                      Type;                                             		// 0x000004 (0x0004)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x000008 (0x0004)              
};

class UGFxObject* UGFxObject::GetElementObject(int Index,class UClass* Type)
{
	static UFieldFunc* pFnGetElementObject = NULL;
	if(!pFnGetElementObject)
		pFnGetElementObject = UObject::FindFunction("Function GFxUI.GFxObject.GetElementObject");

	GFxUI_GetElementObject_Parms GetElementObject_Parms;
	GetElementObject_Parms.Index = Index;
	GetElementObject_Parms.Type = Type;
	pFnGetElementObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementObject,NULL,&GetElementObject_Parms,NULL);
	pFnGetElementObject->FunctionFlags |= 0x400;
	return GetElementObject_Parms.ReturnValue;
}

struct GFxUI_SetObject_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	class UGFxObject*                                  Val;                                              		// 0x00000C (0x0004)              
};

void UGFxObject::SetObject(struct FString Member,class UGFxObject* Val)
{
	static UFieldFunc* pFnSetObject = NULL;
	if(!pFnSetObject)
		pFnSetObject = UObject::FindFunction("Function GFxUI.GFxObject.SetObject");

	GFxUI_SetObject_Parms SetObject_Parms;
	memcpy(&SetObject_Parms.Member,&Member,0xC);
	SetObject_Parms.Val = Val;
	pFnSetObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetObject,NULL,&SetObject_Parms,NULL);
	pFnSetObject->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementColorTransform_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FASColorTransform                           cxform;                                           		// 0x000004 (0x0020)              
};

void UGFxObject::SetElementColorTransform(int Index,struct FASColorTransform cxform)
{
	static UFieldFunc* pFnSetElementColorTransform = NULL;
	if(!pFnSetElementColorTransform)
		pFnSetElementColorTransform = UObject::FindFunction("Function GFxUI.GFxObject.SetElementColorTransform");

	GFxUI_SetElementColorTransform_Parms SetElementColorTransform_Parms;
	SetElementColorTransform_Parms.Index = Index;
	memcpy(&SetElementColorTransform_Parms.cxform,&cxform,0x20);
	pFnSetElementColorTransform->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementColorTransform,NULL,&SetElementColorTransform_Parms,NULL);
	pFnSetElementColorTransform->FunctionFlags |= 0x400;
}

struct GFxUI_ActionScriptVoid_Parms
{
	struct FString                                     method;                                           		// 0x000000 (0x000C)              
};

void UGFxObject::ActionScriptVoid(struct FString method)
{
	static UFieldFunc* pFnActionScriptVoid = NULL;
	if(!pFnActionScriptVoid)
		pFnActionScriptVoid = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptVoid");

	GFxUI_ActionScriptVoid_Parms ActionScriptVoid_Parms;
	memcpy(&ActionScriptVoid_Parms.method,&method,0xC);
	pFnActionScriptVoid->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptVoid,NULL,&ActionScriptVoid_Parms,NULL);
	pFnActionScriptVoid->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementDisplayInfo_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FASDisplayInfo                              D;                                                		// 0x000004 (0x002C)              
};

void UGFxObject::SetElementDisplayInfo(int Index,struct FASDisplayInfo D)
{
	static UFieldFunc* pFnSetElementDisplayInfo = NULL;
	if(!pFnSetElementDisplayInfo)
		pFnSetElementDisplayInfo = UObject::FindFunction("Function GFxUI.GFxObject.SetElementDisplayInfo");

	GFxUI_SetElementDisplayInfo_Parms SetElementDisplayInfo_Parms;
	SetElementDisplayInfo_Parms.Index = Index;
	memcpy(&SetElementDisplayInfo_Parms.D,&D,0x2C);
	pFnSetElementDisplayInfo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementDisplayInfo,NULL,&SetElementDisplayInfo_Parms,NULL);
	pFnSetElementDisplayInfo->FunctionFlags |= 0x400;
}

struct GFxUI_GetString_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UGFxObject::GetString(struct FString Member)
{
	static UFieldFunc* pFnGetString = NULL;
	if(!pFnGetString)
		pFnGetString = UObject::FindFunction("Function GFxUI.GFxObject.GetString");

	GFxUI_GetString_Parms GetString_Parms;
	memcpy(&GetString_Parms.Member,&Member,0xC);
	pFnGetString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetString,NULL,&GetString_Parms,NULL);
	pFnGetString->FunctionFlags |= 0x400;
	return GetString_Parms.ReturnValue;
}

struct GFxUI_SetColorTransform_Parms
{
	struct FASColorTransform                           cxform;                                           		// 0x000000 (0x0020)              
};

void UGFxObject::SetColorTransform(struct FASColorTransform cxform)
{
	static UFieldFunc* pFnSetColorTransform = NULL;
	if(!pFnSetColorTransform)
		pFnSetColorTransform = UObject::FindFunction("Function GFxUI.GFxObject.SetColorTransform");

	GFxUI_SetColorTransform_Parms SetColorTransform_Parms;
	memcpy(&SetColorTransform_Parms.cxform,&cxform,0x20);
	pFnSetColorTransform->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetColorTransform,NULL,&SetColorTransform_Parms,NULL);
	pFnSetColorTransform->FunctionFlags |= 0x400;
}

struct GFxUI_GetText_Parms
{
	struct FString                                     ReturnValue;                                      		// 0x000000 (0x000C)              
};

struct FString UGFxObject::GetText()
{
	static UFieldFunc* pFnGetText = NULL;
	if(!pFnGetText)
		pFnGetText = UObject::FindFunction("Function GFxUI.GFxObject.GetText");

	GFxUI_GetText_Parms GetText_Parms;
	pFnGetText->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetText,NULL,&GetText_Parms,NULL);
	pFnGetText->FunctionFlags |= 0x400;
	return GetText_Parms.ReturnValue;
}

struct GFxUI_GetElementMemberInt_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	int                                                ReturnValue;                                      		// 0x000010 (0x0004)              
};

int UGFxObject::GetElementMemberInt(int Index,struct FString Member)
{
	static UFieldFunc* pFnGetElementMemberInt = NULL;
	if(!pFnGetElementMemberInt)
		pFnGetElementMemberInt = UObject::FindFunction("Function GFxUI.GFxObject.GetElementMemberInt");

	GFxUI_GetElementMemberInt_Parms GetElementMemberInt_Parms;
	GetElementMemberInt_Parms.Index = Index;
	memcpy(&GetElementMemberInt_Parms.Member,&Member,0xC);
	pFnGetElementMemberInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementMemberInt,NULL,&GetElementMemberInt_Parms,NULL);
	pFnGetElementMemberInt->FunctionFlags |= 0x400;
	return GetElementMemberInt_Parms.ReturnValue;
}

struct GFxUI_ActionScriptSetFunction_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
};

void UGFxObject::ActionScriptSetFunction(struct FString Member)
{
	static UFieldFunc* pFnActionScriptSetFunction = NULL;
	if(!pFnActionScriptSetFunction)
		pFnActionScriptSetFunction = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptSetFunction");

	GFxUI_ActionScriptSetFunction_Parms ActionScriptSetFunction_Parms;
	memcpy(&ActionScriptSetFunction_Parms.Member,&Member,0xC);
	pFnActionScriptSetFunction->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptSetFunction,NULL,&ActionScriptSetFunction_Parms,NULL);
	pFnActionScriptSetFunction->FunctionFlags |= 0x400;
}

struct GFxUI_SetText_Parms
{
	struct FString                                     Text;                                             		// 0x000000 (0x000C)              
	class UTranslationContext*                         InContext;                                        		// 0x00000C (0x0004)              
};

void UGFxObject::SetText(struct FString Text,class UTranslationContext* InContext)
{
	static UFieldFunc* pFnSetText = NULL;
	if(!pFnSetText)
		pFnSetText = UObject::FindFunction("Function GFxUI.GFxObject.SetText");

	GFxUI_SetText_Parms SetText_Parms;
	memcpy(&SetText_Parms.Text,&Text,0xC);
	SetText_Parms.InContext = InContext;
	pFnSetText->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetText,NULL,&SetText_Parms,NULL);
	pFnSetText->FunctionFlags |= 0x400;
}

struct GFxUI_SetDisplayInfo_Parms
{
	struct FASDisplayInfo                              D;                                                		// 0x000000 (0x002C)              
};

void UGFxObject::SetDisplayInfo(struct FASDisplayInfo D)
{
	static UFieldFunc* pFnSetDisplayInfo = NULL;
	if(!pFnSetDisplayInfo)
		pFnSetDisplayInfo = UObject::FindFunction("Function GFxUI.GFxObject.SetDisplayInfo");

	GFxUI_SetDisplayInfo_Parms SetDisplayInfo_Parms;
	memcpy(&SetDisplayInfo_Parms.D,&D,0x2C);
	pFnSetDisplayInfo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetDisplayInfo,NULL,&SetDisplayInfo_Parms,NULL);
	pFnSetDisplayInfo->FunctionFlags |= 0x400;
}

struct GFxUI_ActionScriptSetFunctionOn_Parms
{
	class UGFxObject*                                  Target;                                           		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
};

void UGFxObject::ActionScriptSetFunctionOn(class UGFxObject* Target,struct FString Member)
{
	static UFieldFunc* pFnActionScriptSetFunctionOn = NULL;
	if(!pFnActionScriptSetFunctionOn)
		pFnActionScriptSetFunctionOn = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptSetFunctionOn");

	GFxUI_ActionScriptSetFunctionOn_Parms ActionScriptSetFunctionOn_Parms;
	ActionScriptSetFunctionOn_Parms.Target = Target;
	memcpy(&ActionScriptSetFunctionOn_Parms.Member,&Member,0xC);
	pFnActionScriptSetFunctionOn->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptSetFunctionOn,NULL,&ActionScriptSetFunctionOn_Parms,NULL);
	pFnActionScriptSetFunctionOn->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementVisible_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	unsigned long                                      Visible : 1;                                      		// 0x000004 (0x0004) [0x00000001] 
};

void UGFxObject::SetElementVisible(int Index,bool Visible)
{
	static UFieldFunc* pFnSetElementVisible = NULL;
	if(!pFnSetElementVisible)
		pFnSetElementVisible = UObject::FindFunction("Function GFxUI.GFxObject.SetElementVisible");

	GFxUI_SetElementVisible_Parms SetElementVisible_Parms;
	SetElementVisible_Parms.Index = Index;
	SetElementVisible_Parms.Visible = Visible;
	pFnSetElementVisible->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementVisible,NULL,&SetElementVisible_Parms,NULL);
	pFnSetElementVisible->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementString_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     S;                                                		// 0x000004 (0x000C)              
};

void UGFxObject::SetElementString(int Index,struct FString S)
{
	static UFieldFunc* pFnSetElementString = NULL;
	if(!pFnSetElementString)
		pFnSetElementString = UObject::FindFunction("Function GFxUI.GFxObject.SetElementString");

	GFxUI_SetElementString_Parms SetElementString_Parms;
	SetElementString_Parms.Index = Index;
	memcpy(&SetElementString_Parms.S,&S,0xC);
	pFnSetElementString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementString,NULL,&SetElementString_Parms,NULL);
	pFnSetElementString->FunctionFlags |= 0x400;
}

struct GFxUI_SetDisplayMatrix_Parms
{
	FMatrix                                            M;                                                		// 0x000000 (0x0040)              
};

void UGFxObject::SetDisplayMatrix(FMatrix M)
{
	static UFieldFunc* pFnSetDisplayMatrix = NULL;
	if(!pFnSetDisplayMatrix)
		pFnSetDisplayMatrix = UObject::FindFunction("Function GFxUI.GFxObject.SetDisplayMatrix");

	GFxUI_SetDisplayMatrix_Parms SetDisplayMatrix_Parms;
	memcpy(&SetDisplayMatrix_Parms.M,&M,0x40);
	pFnSetDisplayMatrix->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetDisplayMatrix,NULL,&SetDisplayMatrix_Parms,NULL);
	pFnSetDisplayMatrix->FunctionFlags |= 0x400;
}

struct GFxUI_Set_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	struct FASValue                                    Arg;                                              		// 0x00000C (0x001C)              
};

void UGFxObject::Set(struct FString Member,struct FASValue Arg)
{
	static UFieldFunc* pFnSet = NULL;
	if(!pFnSet)
		pFnSet = UObject::FindFunction("Function GFxUI.GFxObject.Set");

	GFxUI_Set_Parms Set_Parms;
	memcpy(&Set_Parms.Member,&Member,0xC);
	memcpy(&Set_Parms.Arg,&Arg,0x1C);
	pFnSet->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSet,NULL,&Set_Parms,NULL);
	pFnSet->FunctionFlags |= 0x400;
}

struct GFxUI_ActionScriptString_Parms
{
	struct FString                                     method;                                           		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UGFxObject::ActionScriptString(struct FString method)
{
	static UFieldFunc* pFnActionScriptString = NULL;
	if(!pFnActionScriptString)
		pFnActionScriptString = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptString");

	GFxUI_ActionScriptString_Parms ActionScriptString_Parms;
	memcpy(&ActionScriptString_Parms.method,&method,0xC);
	pFnActionScriptString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptString,NULL,&ActionScriptString_Parms,NULL);
	pFnActionScriptString->FunctionFlags |= 0x400;
	return ActionScriptString_Parms.ReturnValue;
}

struct GFxUI_ActionScriptInt_Parms
{
	struct FString                                     method;                                           		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UGFxObject::ActionScriptInt(struct FString method)
{
	static UFieldFunc* pFnActionScriptInt = NULL;
	if(!pFnActionScriptInt)
		pFnActionScriptInt = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptInt");

	GFxUI_ActionScriptInt_Parms ActionScriptInt_Parms;
	memcpy(&ActionScriptInt_Parms.method,&method,0xC);
	pFnActionScriptInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptInt,NULL,&ActionScriptInt_Parms,NULL);
	pFnActionScriptInt->FunctionFlags |= 0x400;
	return ActionScriptInt_Parms.ReturnValue;
}

struct GFxUI_GetElementMember_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	struct FASValue                                    ReturnValue;                                      		// 0x000010 (0x001C)              
};

struct FASValue UGFxObject::GetElementMember(int Index,struct FString Member)
{
	static UFieldFunc* pFnGetElementMember = NULL;
	if(!pFnGetElementMember)
		pFnGetElementMember = UObject::FindFunction("Function GFxUI.GFxObject.GetElementMember");

	GFxUI_GetElementMember_Parms GetElementMember_Parms;
	GetElementMember_Parms.Index = Index;
	memcpy(&GetElementMember_Parms.Member,&Member,0xC);
	pFnGetElementMember->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementMember,NULL,&GetElementMember_Parms,NULL);
	pFnGetElementMember->FunctionFlags |= 0x400;
	return GetElementMember_Parms.ReturnValue;
}

struct GFxUI_ActionScriptArray_Parms
{
	struct FString                                     Path;                                             		// 0x000000 (0x000C)              
	TArray<class UGFxObject*>                          ReturnValue;                                      		// 0x00000C (0x000C)              
};

TArray<class UGFxObject*> UGFxObject::ActionScriptArray(struct FString Path)
{
	static UFieldFunc* pFnActionScriptArray = NULL;
	if(!pFnActionScriptArray)
		pFnActionScriptArray = UObject::FindFunction("Function GFxUI.GFxObject.ActionScriptArray");

	GFxUI_ActionScriptArray_Parms ActionScriptArray_Parms;
	memcpy(&ActionScriptArray_Parms.Path,&Path,0xC);
	pFnActionScriptArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnActionScriptArray,NULL,&ActionScriptArray_Parms,NULL);
	pFnActionScriptArray->FunctionFlags |= 0x400;
	return ActionScriptArray_Parms.ReturnValue;
}

struct GFxUI_SetString_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	struct FString                                     S;                                                		// 0x00000C (0x000C)              
	class UTranslationContext*                         InContext;                                        		// 0x000018 (0x0004)              
};

void UGFxObject::SetString(struct FString Member,struct FString S,class UTranslationContext* InContext)
{
	static UFieldFunc* pFnSetString = NULL;
	if(!pFnSetString)
		pFnSetString = UObject::FindFunction("Function GFxUI.GFxObject.SetString");

	GFxUI_SetString_Parms SetString_Parms;
	memcpy(&SetString_Parms.Member,&Member,0xC);
	memcpy(&SetString_Parms.S,&S,0xC);
	SetString_Parms.InContext = InContext;
	pFnSetString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetString,NULL,&SetString_Parms,NULL);
	pFnSetString->FunctionFlags |= 0x400;
}

struct GFxUI_GetElementMemberBool_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UGFxObject::GetElementMemberBool(int Index,struct FString Member)
{
	static UFieldFunc* pFnGetElementMemberBool = NULL;
	if(!pFnGetElementMemberBool)
		pFnGetElementMemberBool = UObject::FindFunction("Function GFxUI.GFxObject.GetElementMemberBool");

	GFxUI_GetElementMemberBool_Parms GetElementMemberBool_Parms;
	GetElementMemberBool_Parms.Index = Index;
	memcpy(&GetElementMemberBool_Parms.Member,&Member,0xC);
	pFnGetElementMemberBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementMemberBool,NULL,&GetElementMemberBool_Parms,NULL);
	pFnGetElementMemberBool->FunctionFlags |= 0x400;
	return GetElementMemberBool_Parms.ReturnValue;
}

struct GFxUI_WidgetUnloaded_Parms
{
	struct FName                                       WidgetName;                                       		// 0x000000 (0x0008)              
	struct FName                                       WidgetPath;                                       		// 0x000008 (0x0008)              
	class UGFxObject*                                  Widget;                                           		// 0x000010 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UGFxObject::WidgetUnloaded(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget)
{
	static UFieldFunc* pFnWidgetUnloaded = NULL;
	if(!pFnWidgetUnloaded)
		pFnWidgetUnloaded = UObject::FindFunction("Function GFxUI.GFxObject.WidgetUnloaded");

	GFxUI_WidgetUnloaded_Parms WidgetUnloaded_Parms;
	memcpy(&WidgetUnloaded_Parms.WidgetName,&WidgetName,0x8);
	memcpy(&WidgetUnloaded_Parms.WidgetPath,&WidgetPath,0x8);
	WidgetUnloaded_Parms.Widget = Widget;
	ProcessEvent(pFnWidgetUnloaded,NULL,&WidgetUnloaded_Parms,NULL);
	return WidgetUnloaded_Parms.ReturnValue;
}

struct GFxUI_GetElement_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FASValue                                    ReturnValue;                                      		// 0x000004 (0x001C)              
};

struct FASValue UGFxObject::GetElement(int Index)
{
	static UFieldFunc* pFnGetElement = NULL;
	if(!pFnGetElement)
		pFnGetElement = UObject::FindFunction("Function GFxUI.GFxObject.GetElement");

	GFxUI_GetElement_Parms GetElement_Parms;
	GetElement_Parms.Index = Index;
	pFnGetElement->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElement,NULL,&GetElement_Parms,NULL);
	pFnGetElement->FunctionFlags |= 0x400;
	return GetElement_Parms.ReturnValue;
}

struct GFxUI_WidgetInitialized_Parms
{
	struct FName                                       WidgetName;                                       		// 0x000000 (0x0008)              
	struct FName                                       WidgetPath;                                       		// 0x000008 (0x0008)              
	class UGFxObject*                                  Widget;                                           		// 0x000010 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000014 (0x0004) [0x00000001] 
};

bool UGFxObject::WidgetInitialized(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget)
{
	static UFieldFunc* pFnWidgetInitialized = NULL;
	if(!pFnWidgetInitialized)
		pFnWidgetInitialized = UObject::FindFunction("Function GFxUI.GFxObject.WidgetInitialized");

	GFxUI_WidgetInitialized_Parms WidgetInitialized_Parms;
	memcpy(&WidgetInitialized_Parms.WidgetName,&WidgetName,0x8);
	memcpy(&WidgetInitialized_Parms.WidgetPath,&WidgetPath,0x8);
	WidgetInitialized_Parms.Widget = Widget;
	ProcessEvent(pFnWidgetInitialized,NULL,&WidgetInitialized_Parms,NULL);
	return WidgetInitialized_Parms.ReturnValue;
}

struct GFxUI_SetElementMember_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	struct FASValue                                    Arg;                                              		// 0x000010 (0x001C)              
};

void UGFxObject::SetElementMember(int Index,struct FString Member,struct FASValue Arg)
{
	static UFieldFunc* pFnSetElementMember = NULL;
	if(!pFnSetElementMember)
		pFnSetElementMember = UObject::FindFunction("Function GFxUI.GFxObject.SetElementMember");

	GFxUI_SetElementMember_Parms SetElementMember_Parms;
	SetElementMember_Parms.Index = Index;
	memcpy(&SetElementMember_Parms.Member,&Member,0xC);
	memcpy(&SetElementMember_Parms.Arg,&Arg,0x1C);
	pFnSetElementMember->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementMember,NULL,&SetElementMember_Parms,NULL);
	pFnSetElementMember->FunctionFlags |= 0x400;
}

struct GFxUI_SetPosition_Parms
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
};

void UGFxObject::SetPosition(float X,float Y)
{
	static UFieldFunc* pFnSetPosition = NULL;
	if(!pFnSetPosition)
		pFnSetPosition = UObject::FindFunction("Function GFxUI.GFxObject.SetPosition");

	GFxUI_SetPosition_Parms SetPosition_Parms;
	SetPosition_Parms.X = X;
	SetPosition_Parms.Y = Y;
	pFnSetPosition->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetPosition,NULL,&SetPosition_Parms,NULL);
	pFnSetPosition->FunctionFlags |= 0x400;
}

struct GFxUI_GotoAndPlayI_Parms
{
	int                                                frame;                                            		// 0x000000 (0x0004)              
};

void UGFxObject::GotoAndPlayI(int frame)
{
	static UFieldFunc* pFnGotoAndPlayI = NULL;
	if(!pFnGotoAndPlayI)
		pFnGotoAndPlayI = UObject::FindFunction("Function GFxUI.GFxObject.GotoAndPlayI");

	GFxUI_GotoAndPlayI_Parms GotoAndPlayI_Parms;
	GotoAndPlayI_Parms.frame = frame;
	pFnGotoAndPlayI->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGotoAndPlayI,NULL,&GotoAndPlayI_Parms,NULL);
	pFnGotoAndPlayI->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementFloat_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	float                                              F;                                                		// 0x000004 (0x0004)              
};

void UGFxObject::SetElementFloat(int Index,float F)
{
	static UFieldFunc* pFnSetElementFloat = NULL;
	if(!pFnSetElementFloat)
		pFnSetElementFloat = UObject::FindFunction("Function GFxUI.GFxObject.SetElementFloat");

	GFxUI_SetElementFloat_Parms SetElementFloat_Parms;
	SetElementFloat_Parms.Index = Index;
	SetElementFloat_Parms.F = F;
	pFnSetElementFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementFloat,NULL,&SetElementFloat_Parms,NULL);
	pFnSetElementFloat->FunctionFlags |= 0x400;
}

struct GFxUI_GetDisplayMatrix3D_Parms
{
	FMatrix                                            ReturnValue;                                      		// 0x000000 (0x0040)              
};

FMatrix UGFxObject::GetDisplayMatrix3D()
{
	static UFieldFunc* pFnGetDisplayMatrix3D = NULL;
	if(!pFnGetDisplayMatrix3D)
		pFnGetDisplayMatrix3D = UObject::FindFunction("Function GFxUI.GFxObject.GetDisplayMatrix3D");

	GFxUI_GetDisplayMatrix3D_Parms GetDisplayMatrix3D_Parms;
	pFnGetDisplayMatrix3D->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetDisplayMatrix3D,NULL,&GetDisplayMatrix3D_Parms,NULL);
	pFnGetDisplayMatrix3D->FunctionFlags |= 0x400;
	return GetDisplayMatrix3D_Parms.ReturnValue;
}

struct GFxUI_GetElementFloat_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UGFxObject::GetElementFloat(int Index)
{
	static UFieldFunc* pFnGetElementFloat = NULL;
	if(!pFnGetElementFloat)
		pFnGetElementFloat = UObject::FindFunction("Function GFxUI.GFxObject.GetElementFloat");

	GFxUI_GetElementFloat_Parms GetElementFloat_Parms;
	GetElementFloat_Parms.Index = Index;
	pFnGetElementFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementFloat,NULL,&GetElementFloat_Parms,NULL);
	pFnGetElementFloat->FunctionFlags |= 0x400;
	return GetElementFloat_Parms.ReturnValue;
}

struct GFxUI_SetDisplayMatrix3D_Parms
{
	FMatrix                                            M;                                                		// 0x000000 (0x0040)              
};

void UGFxObject::SetDisplayMatrix3D(FMatrix M)
{
	static UFieldFunc* pFnSetDisplayMatrix3D = NULL;
	if(!pFnSetDisplayMatrix3D)
		pFnSetDisplayMatrix3D = UObject::FindFunction("Function GFxUI.GFxObject.SetDisplayMatrix3D");

	GFxUI_SetDisplayMatrix3D_Parms SetDisplayMatrix3D_Parms;
	memcpy(&SetDisplayMatrix3D_Parms.M,&M,0x40);
	pFnSetDisplayMatrix3D->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetDisplayMatrix3D,NULL,&SetDisplayMatrix3D_Parms,NULL);
	pFnSetDisplayMatrix3D->FunctionFlags |= 0x400;
}

struct GFxUI_SetInt_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	int                                                I;                                                		// 0x00000C (0x0004)              
};

void UGFxObject::SetInt(struct FString Member,int I)
{
	static UFieldFunc* pFnSetInt = NULL;
	if(!pFnSetInt)
		pFnSetInt = UObject::FindFunction("Function GFxUI.GFxObject.SetInt");

	GFxUI_SetInt_Parms SetInt_Parms;
	memcpy(&SetInt_Parms.Member,&Member,0xC);
	SetInt_Parms.I = I;
	pFnSetInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetInt,NULL,&SetInt_Parms,NULL);
	pFnSetInt->FunctionFlags |= 0x400;
}

struct GFxUI_TranslateString_Parms
{
	struct FString                                     StringToTranslate;                                		// 0x000000 (0x000C)              
	class UTranslationContext*                         InContext;                                        		// 0x00000C (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000010 (0x000C)              
};

struct FString UGFxObject::TranslateString(struct FString StringToTranslate,class UTranslationContext* InContext)
{
	static UFieldFunc* pFnTranslateString = NULL;
	if(!pFnTranslateString)
		pFnTranslateString = UObject::FindFunction("Function GFxUI.GFxObject.TranslateString");

	GFxUI_TranslateString_Parms TranslateString_Parms;
	memcpy(&TranslateString_Parms.StringToTranslate,&StringToTranslate,0xC);
	TranslateString_Parms.InContext = InContext;
	pFnTranslateString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTranslateString,NULL,&TranslateString_Parms,NULL);
	pFnTranslateString->FunctionFlags |= 0x400;
	return TranslateString_Parms.ReturnValue;
}

struct GFxUI_GetFloat_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UGFxObject::GetFloat(struct FString Member)
{
	static UFieldFunc* pFnGetFloat = NULL;
	if(!pFnGetFloat)
		pFnGetFloat = UObject::FindFunction("Function GFxUI.GFxObject.GetFloat");

	GFxUI_GetFloat_Parms GetFloat_Parms;
	memcpy(&GetFloat_Parms.Member,&Member,0xC);
	pFnGetFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetFloat,NULL,&GetFloat_Parms,NULL);
	pFnGetFloat->FunctionFlags |= 0x400;
	return GetFloat_Parms.ReturnValue;
}

struct GFxUI_SetElementPosition_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	float                                              X;                                                		// 0x000004 (0x0004)              
	float                                              Y;                                                		// 0x000008 (0x0004)              
};

void UGFxObject::SetElementPosition(int Index,float X,float Y)
{
	static UFieldFunc* pFnSetElementPosition = NULL;
	if(!pFnSetElementPosition)
		pFnSetElementPosition = UObject::FindFunction("Function GFxUI.GFxObject.SetElementPosition");

	GFxUI_SetElementPosition_Parms SetElementPosition_Parms;
	SetElementPosition_Parms.Index = Index;
	SetElementPosition_Parms.X = X;
	SetElementPosition_Parms.Y = Y;
	pFnSetElementPosition->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementPosition,NULL,&SetElementPosition_Parms,NULL);
	pFnSetElementPosition->FunctionFlags |= 0x400;
}

struct GFxUI_GetElementMemberObject_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	class UClass*                                      Type;                                             		// 0x000010 (0x0004)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x000014 (0x0004)              
};

class UGFxObject* UGFxObject::GetElementMemberObject(int Index,struct FString Member,class UClass* Type)
{
	static UFieldFunc* pFnGetElementMemberObject = NULL;
	if(!pFnGetElementMemberObject)
		pFnGetElementMemberObject = UObject::FindFunction("Function GFxUI.GFxObject.GetElementMemberObject");

	GFxUI_GetElementMemberObject_Parms GetElementMemberObject_Parms;
	GetElementMemberObject_Parms.Index = Index;
	memcpy(&GetElementMemberObject_Parms.Member,&Member,0xC);
	GetElementMemberObject_Parms.Type = Type;
	pFnGetElementMemberObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementMemberObject,NULL,&GetElementMemberObject_Parms,NULL);
	pFnGetElementMemberObject->FunctionFlags |= 0x400;
	return GetElementMemberObject_Parms.ReturnValue;
}

struct GFxUI_GetElementMemberString_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000010 (0x000C)              
};

struct FString UGFxObject::GetElementMemberString(int Index,struct FString Member)
{
	static UFieldFunc* pFnGetElementMemberString = NULL;
	if(!pFnGetElementMemberString)
		pFnGetElementMemberString = UObject::FindFunction("Function GFxUI.GFxObject.GetElementMemberString");

	GFxUI_GetElementMemberString_Parms GetElementMemberString_Parms;
	GetElementMemberString_Parms.Index = Index;
	memcpy(&GetElementMemberString_Parms.Member,&Member,0xC);
	pFnGetElementMemberString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementMemberString,NULL,&GetElementMemberString_Parms,NULL);
	pFnGetElementMemberString->FunctionFlags |= 0x400;
	return GetElementMemberString_Parms.ReturnValue;
}

struct GFxUI_SetElementInt_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	int                                                I;                                                		// 0x000004 (0x0004)              
};

void UGFxObject::SetElementInt(int Index,int I)
{
	static UFieldFunc* pFnSetElementInt = NULL;
	if(!pFnSetElementInt)
		pFnSetElementInt = UObject::FindFunction("Function GFxUI.GFxObject.SetElementInt");

	GFxUI_SetElementInt_Parms SetElementInt_Parms;
	SetElementInt_Parms.Index = Index;
	SetElementInt_Parms.I = I;
	pFnSetElementInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementInt,NULL,&SetElementInt_Parms,NULL);
	pFnSetElementInt->FunctionFlags |= 0x400;
}

struct GFxUI_GetElementBool_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000004 (0x0004) [0x00000001] 
};

bool UGFxObject::GetElementBool(int Index)
{
	static UFieldFunc* pFnGetElementBool = NULL;
	if(!pFnGetElementBool)
		pFnGetElementBool = UObject::FindFunction("Function GFxUI.GFxObject.GetElementBool");

	GFxUI_GetElementBool_Parms GetElementBool_Parms;
	GetElementBool_Parms.Index = Index;
	pFnGetElementBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementBool,NULL,&GetElementBool_Parms,NULL);
	pFnGetElementBool->FunctionFlags |= 0x400;
	return GetElementBool_Parms.ReturnValue;
}

struct GFxUI_SetElementDisplayMatrix_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	unsigned char                                      _0x000004[0xC];                                   		// 0x000004 (0x000C) MISSED OFFSET
	FMatrix                                            M;                                                		// 0x000010 (0x0040)              
};

void UGFxObject::SetElementDisplayMatrix(int Index,FMatrix M)
{
	static UFieldFunc* pFnSetElementDisplayMatrix = NULL;
	if(!pFnSetElementDisplayMatrix)
		pFnSetElementDisplayMatrix = UObject::FindFunction("Function GFxUI.GFxObject.SetElementDisplayMatrix");

	GFxUI_SetElementDisplayMatrix_Parms SetElementDisplayMatrix_Parms;
	SetElementDisplayMatrix_Parms.Index = Index;
	memcpy(&SetElementDisplayMatrix_Parms.M,&M,0x40);
	pFnSetElementDisplayMatrix->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementDisplayMatrix,NULL,&SetElementDisplayMatrix_Parms,NULL);
	pFnSetElementDisplayMatrix->FunctionFlags |= 0x400;
}

struct GFxUI_GetColorTransform_Parms
{
	struct FASColorTransform                           ReturnValue;                                      		// 0x000000 (0x0020)              
};

struct FASColorTransform UGFxObject::GetColorTransform()
{
	static UFieldFunc* pFnGetColorTransform = NULL;
	if(!pFnGetColorTransform)
		pFnGetColorTransform = UObject::FindFunction("Function GFxUI.GFxObject.GetColorTransform");

	GFxUI_GetColorTransform_Parms GetColorTransform_Parms;
	pFnGetColorTransform->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetColorTransform,NULL,&GetColorTransform_Parms,NULL);
	pFnGetColorTransform->FunctionFlags |= 0x400;
	return GetColorTransform_Parms.ReturnValue;
}

struct GFxUI_GotoAndPlay_Parms
{
	struct FString                                     frame;                                            		// 0x000000 (0x000C)              
};

void UGFxObject::GotoAndPlay(struct FString frame)
{
	static UFieldFunc* pFnGotoAndPlay = NULL;
	if(!pFnGotoAndPlay)
		pFnGotoAndPlay = UObject::FindFunction("Function GFxUI.GFxObject.GotoAndPlay");

	GFxUI_GotoAndPlay_Parms GotoAndPlay_Parms;
	memcpy(&GotoAndPlay_Parms.frame,&frame,0xC);
	pFnGotoAndPlay->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGotoAndPlay,NULL,&GotoAndPlay_Parms,NULL);
	pFnGotoAndPlay->FunctionFlags |= 0x400;
}

struct GFxUI_Get_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	struct FASValue                                    ReturnValue;                                      		// 0x00000C (0x001C)              
};

struct FASValue UGFxObject::Get(struct FString Member)
{
	static UFieldFunc* pFnGet = NULL;
	if(!pFnGet)
		pFnGet = UObject::FindFunction("Function GFxUI.GFxObject.Get");

	GFxUI_Get_Parms Get_Parms;
	memcpy(&Get_Parms.Member,&Member,0xC);
	pFnGet->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGet,NULL,&Get_Parms,NULL);
	pFnGet->FunctionFlags |= 0x400;
	return Get_Parms.ReturnValue;
}

struct GFxUI_SetElementMemberBool_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	unsigned long                                      B : 1;                                            		// 0x000010 (0x0004) [0x00000001] 
};

void UGFxObject::SetElementMemberBool(int Index,struct FString Member,bool B)
{
	static UFieldFunc* pFnSetElementMemberBool = NULL;
	if(!pFnSetElementMemberBool)
		pFnSetElementMemberBool = UObject::FindFunction("Function GFxUI.GFxObject.SetElementMemberBool");

	GFxUI_SetElementMemberBool_Parms SetElementMemberBool_Parms;
	SetElementMemberBool_Parms.Index = Index;
	memcpy(&SetElementMemberBool_Parms.Member,&Member,0xC);
	SetElementMemberBool_Parms.B = B;
	pFnSetElementMemberBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementMemberBool,NULL,&SetElementMemberBool_Parms,NULL);
	pFnSetElementMemberBool->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementObject_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	class UGFxObject*                                  Val;                                              		// 0x000004 (0x0004)              
};

void UGFxObject::SetElementObject(int Index,class UGFxObject* Val)
{
	static UFieldFunc* pFnSetElementObject = NULL;
	if(!pFnSetElementObject)
		pFnSetElementObject = UObject::FindFunction("Function GFxUI.GFxObject.SetElementObject");

	GFxUI_SetElementObject_Parms SetElementObject_Parms;
	SetElementObject_Parms.Index = Index;
	SetElementObject_Parms.Val = Val;
	pFnSetElementObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementObject,NULL,&SetElementObject_Parms,NULL);
	pFnSetElementObject->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementMemberString_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	struct FString                                     S;                                                		// 0x000010 (0x000C)              
};

void UGFxObject::SetElementMemberString(int Index,struct FString Member,struct FString S)
{
	static UFieldFunc* pFnSetElementMemberString = NULL;
	if(!pFnSetElementMemberString)
		pFnSetElementMemberString = UObject::FindFunction("Function GFxUI.GFxObject.SetElementMemberString");

	GFxUI_SetElementMemberString_Parms SetElementMemberString_Parms;
	SetElementMemberString_Parms.Index = Index;
	memcpy(&SetElementMemberString_Parms.Member,&Member,0xC);
	memcpy(&SetElementMemberString_Parms.S,&S,0xC);
	pFnSetElementMemberString->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementMemberString,NULL,&SetElementMemberString_Parms,NULL);
	pFnSetElementMemberString->FunctionFlags |= 0x400;
}

struct GFxUI_SetBool_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	unsigned long                                      B : 1;                                            		// 0x00000C (0x0004) [0x00000001] 
};

void UGFxObject::SetBool(struct FString Member,bool B)
{
	static UFieldFunc* pFnSetBool = NULL;
	if(!pFnSetBool)
		pFnSetBool = UObject::FindFunction("Function GFxUI.GFxObject.SetBool");

	GFxUI_SetBool_Parms SetBool_Parms;
	memcpy(&SetBool_Parms.Member,&Member,0xC);
	SetBool_Parms.B = B;
	pFnSetBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetBool,NULL,&SetBool_Parms,NULL);
	pFnSetBool->FunctionFlags |= 0x400;
}

struct GFxUI_GetObject_Parms
{
	struct FString                                     Member;                                           		// 0x000000 (0x000C)              
	class UClass*                                      Type;                                             		// 0x00000C (0x0004)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x000010 (0x0004)              
};

class UGFxObject* UGFxObject::GetObject(struct FString Member,class UClass* Type)
{
	static UFieldFunc* pFnGetObject = NULL;
	if(!pFnGetObject)
		pFnGetObject = UObject::FindFunction("Function GFxUI.GFxObject.GetObject");

	GFxUI_GetObject_Parms GetObject_Parms;
	memcpy(&GetObject_Parms.Member,&Member,0xC);
	GetObject_Parms.Type = Type;
	pFnGetObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetObject,NULL,&GetObject_Parms,NULL);
	pFnGetObject->FunctionFlags |= 0x400;
	return GetObject_Parms.ReturnValue;
}

struct GFxUI_SetElementBool_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
};

void UGFxObject::SetElementBool(int Index,bool B)
{
	static UFieldFunc* pFnSetElementBool = NULL;
	if(!pFnSetElementBool)
		pFnSetElementBool = UObject::FindFunction("Function GFxUI.GFxObject.SetElementBool");

	GFxUI_SetElementBool_Parms SetElementBool_Parms;
	SetElementBool_Parms.Index = Index;
	SetElementBool_Parms.B = B;
	pFnSetElementBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementBool,NULL,&SetElementBool_Parms,NULL);
	pFnSetElementBool->FunctionFlags |= 0x400;
}

struct GFxUI_AttachMovie_Parms
{
	struct FString                                     symbolname;                                       		// 0x000000 (0x000C)              
	struct FString                                     instanceName;                                     		// 0x00000C (0x000C)              
	int                                                depth;                                            		// 0x000018 (0x0004)              
	class UClass*                                      Type;                                             		// 0x00001C (0x0004)              
	class UGFxObject*                                  ReturnValue;                                      		// 0x000020 (0x0004)              
};

class UGFxObject* UGFxObject::AttachMovie(struct FString symbolname,struct FString instanceName,int depth,class UClass* Type)
{
	static UFieldFunc* pFnAttachMovie = NULL;
	if(!pFnAttachMovie)
		pFnAttachMovie = UObject::FindFunction("Function GFxUI.GFxObject.AttachMovie");

	GFxUI_AttachMovie_Parms AttachMovie_Parms;
	memcpy(&AttachMovie_Parms.symbolname,&symbolname,0xC);
	memcpy(&AttachMovie_Parms.instanceName,&instanceName,0xC);
	AttachMovie_Parms.depth = depth;
	AttachMovie_Parms.Type = Type;
	pFnAttachMovie->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAttachMovie,NULL,&AttachMovie_Parms,NULL);
	pFnAttachMovie->FunctionFlags |= 0x400;
	return AttachMovie_Parms.ReturnValue;
}

struct GFxUI_GetDisplayMatrix_Parms
{
	FMatrix                                            ReturnValue;                                      		// 0x000000 (0x0040)              
};

FMatrix UGFxObject::GetDisplayMatrix()
{
	static UFieldFunc* pFnGetDisplayMatrix = NULL;
	if(!pFnGetDisplayMatrix)
		pFnGetDisplayMatrix = UObject::FindFunction("Function GFxUI.GFxObject.GetDisplayMatrix");

	GFxUI_GetDisplayMatrix_Parms GetDisplayMatrix_Parms;
	pFnGetDisplayMatrix->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetDisplayMatrix,NULL,&GetDisplayMatrix_Parms,NULL);
	pFnGetDisplayMatrix->FunctionFlags |= 0x400;
	return GetDisplayMatrix_Parms.ReturnValue;
}

struct GFxUI_GetElementDisplayMatrix_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	unsigned char                                      _0x000004[0xC];                                   		// 0x000004 (0x000C) MISSED OFFSET
	FMatrix                                            ReturnValue;                                      		// 0x000010 (0x0040)              
};

FMatrix UGFxObject::GetElementDisplayMatrix(int Index)
{
	static UFieldFunc* pFnGetElementDisplayMatrix = NULL;
	if(!pFnGetElementDisplayMatrix)
		pFnGetElementDisplayMatrix = UObject::FindFunction("Function GFxUI.GFxObject.GetElementDisplayMatrix");

	GFxUI_GetElementDisplayMatrix_Parms GetElementDisplayMatrix_Parms;
	GetElementDisplayMatrix_Parms.Index = Index;
	pFnGetElementDisplayMatrix->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementDisplayMatrix,NULL,&GetElementDisplayMatrix_Parms,NULL);
	pFnGetElementDisplayMatrix->FunctionFlags |= 0x400;
	return GetElementDisplayMatrix_Parms.ReturnValue;
}

struct GFxUI_GetElementMemberFloat_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	float                                              ReturnValue;                                      		// 0x000010 (0x0004)              
};

float UGFxObject::GetElementMemberFloat(int Index,struct FString Member)
{
	static UFieldFunc* pFnGetElementMemberFloat = NULL;
	if(!pFnGetElementMemberFloat)
		pFnGetElementMemberFloat = UObject::FindFunction("Function GFxUI.GFxObject.GetElementMemberFloat");

	GFxUI_GetElementMemberFloat_Parms GetElementMemberFloat_Parms;
	GetElementMemberFloat_Parms.Index = Index;
	memcpy(&GetElementMemberFloat_Parms.Member,&Member,0xC);
	pFnGetElementMemberFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetElementMemberFloat,NULL,&GetElementMemberFloat_Parms,NULL);
	pFnGetElementMemberFloat->FunctionFlags |= 0x400;
	return GetElementMemberFloat_Parms.ReturnValue;
}

struct GFxUI_SetElementMemberObject_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	class UGFxObject*                                  Val;                                              		// 0x000010 (0x0004)              
};

void UGFxObject::SetElementMemberObject(int Index,struct FString Member,class UGFxObject* Val)
{
	static UFieldFunc* pFnSetElementMemberObject = NULL;
	if(!pFnSetElementMemberObject)
		pFnSetElementMemberObject = UObject::FindFunction("Function GFxUI.GFxObject.SetElementMemberObject");

	GFxUI_SetElementMemberObject_Parms SetElementMemberObject_Parms;
	SetElementMemberObject_Parms.Index = Index;
	memcpy(&SetElementMemberObject_Parms.Member,&Member,0xC);
	SetElementMemberObject_Parms.Val = Val;
	pFnSetElementMemberObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementMemberObject,NULL,&SetElementMemberObject_Parms,NULL);
	pFnSetElementMemberObject->FunctionFlags |= 0x400;
}

struct GFxUI_SetElementMemberInt_Parms
{
	int                                                Index;                                            		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	int                                                I;                                                		// 0x000010 (0x0004)              
};

void UGFxObject::SetElementMemberInt(int Index,struct FString Member,int I)
{
	static UFieldFunc* pFnSetElementMemberInt = NULL;
	if(!pFnSetElementMemberInt)
		pFnSetElementMemberInt = UObject::FindFunction("Function GFxUI.GFxObject.SetElementMemberInt");

	GFxUI_SetElementMemberInt_Parms SetElementMemberInt_Parms;
	SetElementMemberInt_Parms.Index = Index;
	memcpy(&SetElementMemberInt_Parms.Member,&Member,0xC);
	SetElementMemberInt_Parms.I = I;
	pFnSetElementMemberInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetElementMemberInt,NULL,&SetElementMemberInt_Parms,NULL);
	pFnSetElementMemberInt->FunctionFlags |= 0x400;
}

struct GFxUI_SetListener_Parms
{
	class UGFxObject*                                  O;                                                		// 0x000000 (0x0004)              
	struct FString                                     Member;                                           		// 0x000004 (0x000C)              
	struct FScriptDelegate                             Listener;                                         		// 0x000010 (0x000C)              
};

void UGFxClikWidget::SetListener(class UGFxObject* O,struct FString Member,struct FScriptDelegate Listener)
{
	static UFieldFunc* pFnSetListener = NULL;
	if(!pFnSetListener)
		pFnSetListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.SetListener");

	GFxUI_SetListener_Parms SetListener_Parms;
	SetListener_Parms.O = O;
	memcpy(&SetListener_Parms.Member,&Member,0xC);
	memcpy(&SetListener_Parms.Listener,&Listener,0xC);
	ProcessEvent(pFnSetListener,NULL,&SetListener_Parms,NULL);
}

struct GFxUI_GetEventStringFromTypename_Parms
{
	struct FName                                       Typename;                                         		// 0x000000 (0x0008)              
	struct FString                                     ReturnValue;                                      		// 0x000008 (0x000C)              
	//struct FString                                     TypeString;                                       		// 0x000014 (0x000C)              
};

struct FString UGFxClikWidget::GetEventStringFromTypename(struct FName Typename)
{
	static UFieldFunc* pFnGetEventStringFromTypename = NULL;
	if(!pFnGetEventStringFromTypename)
		pFnGetEventStringFromTypename = UObject::FindFunction("Function GFxUI.GFxClikWidget.GetEventStringFromTypename");

	GFxUI_GetEventStringFromTypename_Parms GetEventStringFromTypename_Parms;
	memcpy(&GetEventStringFromTypename_Parms.Typename,&Typename,0x8);
	ProcessEvent(pFnGetEventStringFromTypename,NULL,&GetEventStringFromTypename_Parms,NULL);
	return GetEventStringFromTypename_Parms.ReturnValue;
}

struct GFxUI_AddEventListener_Parms
{
	struct FName                                       Type;                                             		// 0x000000 (0x0008)              
	struct FScriptDelegate                             Listener;                                         		// 0x000008 (0x000C)              
	unsigned long                                      useCapture : 1;                                   		// 0x000014 (0x0004) [0x00000001] 
	int                                                listenerPriority;                                 		// 0x000018 (0x0004)              
	unsigned long                                      useWeakReference : 1;                             		// 0x00001C (0x0004) [0x00000001] 
	//class UGFxObject*                                  O;                                                		// 0x000020 (0x0004)              
	//struct FString                                     TypeString;                                       		// 0x000024 (0x000C)              
};

void UGFxClikWidget::AddEventListener(struct FName Type,struct FScriptDelegate Listener,bool useCapture,int listenerPriority,bool useWeakReference)
{
	static UFieldFunc* pFnAddEventListener = NULL;
	if(!pFnAddEventListener)
		pFnAddEventListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.AddEventListener");

	GFxUI_AddEventListener_Parms AddEventListener_Parms;
	memcpy(&AddEventListener_Parms.Type,&Type,0x8);
	memcpy(&AddEventListener_Parms.Listener,&Listener,0xC);
	AddEventListener_Parms.useCapture = useCapture;
	AddEventListener_Parms.listenerPriority = listenerPriority;
	AddEventListener_Parms.useWeakReference = useWeakReference;
	ProcessEvent(pFnAddEventListener,NULL,&AddEventListener_Parms,NULL);
}

struct GFxUI_EventListener_Parms
{
	class UGFxObject*                                  Data;                                             		// 0x000000 (0x0004)              
};

void UGFxClikWidget::EventListener(class UGFxObject* Data)
{
	static UFieldFunc* pFnEventListener = NULL;
	if(!pFnEventListener)
		pFnEventListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.EventListener");

	GFxUI_EventListener_Parms EventListener_Parms;
	EventListener_Parms.Data = Data;
	ProcessEvent(pFnEventListener,NULL,&EventListener_Parms,NULL);
}

struct GFxUI_removeEventListener_Parms
{
	struct FString                                     Type;                                             		// 0x000000 (0x000C)              
	struct FScriptDelegate                             Listener;                                         		// 0x00000C (0x000C)              
};

void UGFxClikWidget::removeEventListener(struct FString Type,struct FScriptDelegate Listener)
{
	static UFieldFunc* pFnremoveEventListener = NULL;
	if(!pFnremoveEventListener)
		pFnremoveEventListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.removeEventListener");

	GFxUI_removeEventListener_Parms removeEventListener_Parms;
	memcpy(&removeEventListener_Parms.Type,&Type,0xC);
	memcpy(&removeEventListener_Parms.Listener,&Listener,0xC);
	ProcessEvent(pFnremoveEventListener,NULL,&removeEventListener_Parms,NULL);
}

struct GFxUI_ASRemoveAllEventListeners_Parms
{
	struct FString                                     Event;                                            		// 0x000000 (0x000C)              
};

void UGFxClikWidget::ASRemoveAllEventListeners(struct FString Event)
{
	static UFieldFunc* pFnASRemoveAllEventListeners = NULL;
	if(!pFnASRemoveAllEventListeners)
		pFnASRemoveAllEventListeners = UObject::FindFunction("Function GFxUI.GFxClikWidget.ASRemoveAllEventListeners");

	GFxUI_ASRemoveAllEventListeners_Parms ASRemoveAllEventListeners_Parms;
	memcpy(&ASRemoveAllEventListeners_Parms.Event,&Event,0xC);
	ProcessEvent(pFnASRemoveAllEventListeners,NULL,&ASRemoveAllEventListeners_Parms,NULL);
}

struct GFxUI_RemoveAllEventListeners_Parms
{
	struct FString                                     Event;                                            		// 0x000000 (0x000C)              
};

void UGFxClikWidget::RemoveAllEventListeners(struct FString Event)
{
	static UFieldFunc* pFnRemoveAllEventListeners = NULL;
	if(!pFnRemoveAllEventListeners)
		pFnRemoveAllEventListeners = UObject::FindFunction("Function GFxUI.GFxClikWidget.RemoveAllEventListeners");

	GFxUI_RemoveAllEventListeners_Parms RemoveAllEventListeners_Parms;
	memcpy(&RemoveAllEventListeners_Parms.Event,&Event,0xC);
	ProcessEvent(pFnRemoveAllEventListeners,NULL,&RemoveAllEventListeners_Parms,NULL);
}

struct GFxUI_ASAddEventListener_Parms
{
	struct FString                                     Type;                                             		// 0x000000 (0x000C)              
	class UGFxObject*                                  O;                                                		// 0x00000C (0x0004)              
	struct FString                                     func;                                             		// 0x000010 (0x000C)              
};

void UGFxClikWidget::ASAddEventListener(struct FString Type,class UGFxObject* O,struct FString func)
{
	static UFieldFunc* pFnASAddEventListener = NULL;
	if(!pFnASAddEventListener)
		pFnASAddEventListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.ASAddEventListener");

	GFxUI_ASAddEventListener_Parms ASAddEventListener_Parms;
	memcpy(&ASAddEventListener_Parms.Type,&Type,0xC);
	ASAddEventListener_Parms.O = O;
	memcpy(&ASAddEventListener_Parms.func,&func,0xC);
	ProcessEvent(pFnASAddEventListener,NULL,&ASAddEventListener_Parms,NULL);
}

struct GFxUI_AS3AddEventListener_Parms
{
	struct FString                                     Type;                                             		// 0x000000 (0x000C)              
	struct FScriptDelegate                             Listener;                                         		// 0x00000C (0x000C)              
	unsigned long                                      useCapture : 1;                                   		// 0x000018 (0x0004) [0x00000001] 
	int                                                listenerPriority;                                 		// 0x00001C (0x0004)              
	unsigned long                                      useWeakReference : 1;                             		// 0x000020 (0x0004) [0x00000001] 
};

void UGFxClikWidget::AS3AddEventListener(struct FString Type,struct FScriptDelegate Listener,bool useCapture,int listenerPriority,bool useWeakReference)
{
	static UFieldFunc* pFnAS3AddEventListener = NULL;
	if(!pFnAS3AddEventListener)
		pFnAS3AddEventListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.AS3AddEventListener");

	GFxUI_AS3AddEventListener_Parms AS3AddEventListener_Parms;
	memcpy(&AS3AddEventListener_Parms.Type,&Type,0xC);
	memcpy(&AS3AddEventListener_Parms.Listener,&Listener,0xC);
	AS3AddEventListener_Parms.useCapture = useCapture;
	AS3AddEventListener_Parms.listenerPriority = listenerPriority;
	AS3AddEventListener_Parms.useWeakReference = useWeakReference;
	ProcessEvent(pFnAS3AddEventListener,NULL,&AS3AddEventListener_Parms,NULL);
}

struct GFxUI_AS3RemoveEventListener_Parms
{
	struct FString                                     Type;                                             		// 0x000000 (0x000C)              
	struct FScriptDelegate                             Listener;                                         		// 0x00000C (0x000C)              
};

void UGFxClikWidget::AS3RemoveEventListener(struct FString Type,struct FScriptDelegate Listener)
{
	static UFieldFunc* pFnAS3RemoveEventListener = NULL;
	if(!pFnAS3RemoveEventListener)
		pFnAS3RemoveEventListener = UObject::FindFunction("Function GFxUI.GFxClikWidget.AS3RemoveEventListener");

	GFxUI_AS3RemoveEventListener_Parms AS3RemoveEventListener_Parms;
	memcpy(&AS3RemoveEventListener_Parms.Type,&Type,0xC);
	memcpy(&AS3RemoveEventListener_Parms.Listener,&Listener,0xC);
	ProcessEvent(pFnAS3RemoveEventListener,NULL,&AS3RemoveEventListener_Parms,NULL);
}

struct GFxUI_IsValidLevelSequenceObject_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UGFxAction_CloseMovie::IsValidLevelSequenceObject()
{
	static UFieldFunc* pFnIsValidLevelSequenceObject = NULL;
	if(!pFnIsValidLevelSequenceObject)
		pFnIsValidLevelSequenceObject = UObject::FindFunction("Function GFxUI.GFxAction_CloseMovie.IsValidLevelSequenceObject");

	GFxUI_IsValidLevelSequenceObject_Parms IsValidLevelSequenceObject_Parms;
	ProcessEvent(pFnIsValidLevelSequenceObject,NULL,&IsValidLevelSequenceObject_Parms,NULL);
	return IsValidLevelSequenceObject_Parms.ReturnValue;
}

struct GFxUI_IsValidLevelSequenceObject_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UGFxAction_GetVariable::IsValidLevelSequenceObject()
{
	static UFieldFunc* pFnIsValidLevelSequenceObject = NULL;
	if(!pFnIsValidLevelSequenceObject)
		pFnIsValidLevelSequenceObject = UObject::FindFunction("Function GFxUI.GFxAction_GetVariable.IsValidLevelSequenceObject");

	GFxUI_IsValidLevelSequenceObject_Parms IsValidLevelSequenceObject_Parms;
	ProcessEvent(pFnIsValidLevelSequenceObject,NULL,&IsValidLevelSequenceObject_Parms,NULL);
	return IsValidLevelSequenceObject_Parms.ReturnValue;
}

struct GFxUI_IsValidLevelSequenceObject_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UGFxAction_Invoke::IsValidLevelSequenceObject()
{
	static UFieldFunc* pFnIsValidLevelSequenceObject = NULL;
	if(!pFnIsValidLevelSequenceObject)
		pFnIsValidLevelSequenceObject = UObject::FindFunction("Function GFxUI.GFxAction_Invoke.IsValidLevelSequenceObject");

	GFxUI_IsValidLevelSequenceObject_Parms IsValidLevelSequenceObject_Parms;
	ProcessEvent(pFnIsValidLevelSequenceObject,NULL,&IsValidLevelSequenceObject_Parms,NULL);
	return IsValidLevelSequenceObject_Parms.ReturnValue;
}

struct GFxUI_IsValidLevelSequenceObject_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UGFxAction_OpenMovie::IsValidLevelSequenceObject()
{
	static UFieldFunc* pFnIsValidLevelSequenceObject = NULL;
	if(!pFnIsValidLevelSequenceObject)
		pFnIsValidLevelSequenceObject = UObject::FindFunction("Function GFxUI.GFxAction_OpenMovie.IsValidLevelSequenceObject");

	GFxUI_IsValidLevelSequenceObject_Parms IsValidLevelSequenceObject_Parms;
	ProcessEvent(pFnIsValidLevelSequenceObject,NULL,&IsValidLevelSequenceObject_Parms,NULL);
	return IsValidLevelSequenceObject_Parms.ReturnValue;
}

struct GFxUI_IsValidLevelSequenceObject_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UGFxAction_SetVariable::IsValidLevelSequenceObject()
{
	static UFieldFunc* pFnIsValidLevelSequenceObject = NULL;
	if(!pFnIsValidLevelSequenceObject)
		pFnIsValidLevelSequenceObject = UObject::FindFunction("Function GFxUI.GFxAction_SetVariable.IsValidLevelSequenceObject");

	GFxUI_IsValidLevelSequenceObject_Parms IsValidLevelSequenceObject_Parms;
	ProcessEvent(pFnIsValidLevelSequenceObject,NULL,&IsValidLevelSequenceObject_Parms,NULL);
	return IsValidLevelSequenceObject_Parms.ReturnValue;
}

struct GFxUI_FSCommand_Parms
{
	class UGFxMoviePlayer*                             Movie;                                            		// 0x000000 (0x0004)              
	class UGFxEvent_FSCommand*                         Event;                                            		// 0x000004 (0x0004)              
	struct FString                                     Cmd;                                              		// 0x000008 (0x000C)              
	struct FString                                     Arg;                                              		// 0x000014 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000020 (0x0004) [0x00000001] 
};

bool UGFxFSCmdHandler_Kismet::FSCommand(class UGFxMoviePlayer* Movie,class UGFxEvent_FSCommand* Event,struct FString Cmd,struct FString Arg)
{
	static UFieldFunc* pFnFSCommand = NULL;
	if(!pFnFSCommand)
		pFnFSCommand = UObject::FindFunction("Function GFxUI.GFxFSCmdHandler_Kismet.FSCommand");

	GFxUI_FSCommand_Parms FSCommand_Parms;
	FSCommand_Parms.Movie = Movie;
	FSCommand_Parms.Event = Event;
	memcpy(&FSCommand_Parms.Cmd,&Cmd,0xC);
	memcpy(&FSCommand_Parms.Arg,&Arg,0xC);
	pFnFSCommand->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFSCommand,NULL,&FSCommand_Parms,NULL);
	pFnFSCommand->FunctionFlags |= 0x400;
	return FSCommand_Parms.ReturnValue;
}

struct GFxUI_SaveSubscriberValue_Parms
{
	TArray<class UUIDataStore*>                        out_BoundDataStores;                              		// 0x000000 (0x000C)              
	int                                                BindingIndex;                                     		// 0x00000C (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UGFxDataStoreSubscriber::SaveSubscriberValue(TArray<class UUIDataStore*>* out_BoundDataStores,int BindingIndex)
{
	static UFieldFunc* pFnSaveSubscriberValue = NULL;
	if(!pFnSaveSubscriberValue)
		pFnSaveSubscriberValue = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue");

	GFxUI_SaveSubscriberValue_Parms SaveSubscriberValue_Parms;
	SaveSubscriberValue_Parms.BindingIndex = BindingIndex;
	pFnSaveSubscriberValue->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSaveSubscriberValue,NULL,&SaveSubscriberValue_Parms,NULL);
	pFnSaveSubscriberValue->FunctionFlags |= 0x400;
	if(out_BoundDataStores)
		memcpy(out_BoundDataStores,&SaveSubscriberValue_Parms.out_BoundDataStores,0xC);
	return SaveSubscriberValue_Parms.ReturnValue;
}

struct GFxUI_GetDataStoreBinding_Parms
{
	int                                                BindingIndex;                                     		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UGFxDataStoreSubscriber::GetDataStoreBinding(int BindingIndex)
{
	static UFieldFunc* pFnGetDataStoreBinding = NULL;
	if(!pFnGetDataStoreBinding)
		pFnGetDataStoreBinding = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding");

	GFxUI_GetDataStoreBinding_Parms GetDataStoreBinding_Parms;
	GetDataStoreBinding_Parms.BindingIndex = BindingIndex;
	pFnGetDataStoreBinding->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetDataStoreBinding,NULL,&GetDataStoreBinding_Parms,NULL);
	pFnGetDataStoreBinding->FunctionFlags |= 0x400;
	return GetDataStoreBinding_Parms.ReturnValue;
}

struct GFxUI_SetDataStoreBinding_Parms
{
	struct FString                                     MarkupText;                                       		// 0x000000 (0x000C)              
	int                                                BindingIndex;                                     		// 0x00000C (0x0004)              
};

void UGFxDataStoreSubscriber::SetDataStoreBinding(struct FString MarkupText,int BindingIndex)
{
	static UFieldFunc* pFnSetDataStoreBinding = NULL;
	if(!pFnSetDataStoreBinding)
		pFnSetDataStoreBinding = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding");

	GFxUI_SetDataStoreBinding_Parms SetDataStoreBinding_Parms;
	memcpy(&SetDataStoreBinding_Parms.MarkupText,&MarkupText,0xC);
	SetDataStoreBinding_Parms.BindingIndex = BindingIndex;
	pFnSetDataStoreBinding->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetDataStoreBinding,NULL,&SetDataStoreBinding_Parms,NULL);
	pFnSetDataStoreBinding->FunctionFlags |= 0x400;
}

struct GFxUI_ClearBoundDataStores_Parms
{
};

void UGFxDataStoreSubscriber::ClearBoundDataStores()
{
	static UFieldFunc* pFnClearBoundDataStores = NULL;
	if(!pFnClearBoundDataStores)
		pFnClearBoundDataStores = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores");

	GFxUI_ClearBoundDataStores_Parms ClearBoundDataStores_Parms;
	pFnClearBoundDataStores->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClearBoundDataStores,NULL,&ClearBoundDataStores_Parms,NULL);
	pFnClearBoundDataStores->FunctionFlags |= 0x400;
}

struct GFxUI_GetBoundDataStores_Parms
{
	TArray<class UUIDataStore*>                        out_BoundDataStores;                              		// 0x000000 (0x000C)              
};

void UGFxDataStoreSubscriber::GetBoundDataStores(TArray<class UUIDataStore*>* out_BoundDataStores)
{
	static UFieldFunc* pFnGetBoundDataStores = NULL;
	if(!pFnGetBoundDataStores)
		pFnGetBoundDataStores = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.GetBoundDataStores");

	GFxUI_GetBoundDataStores_Parms GetBoundDataStores_Parms;
	pFnGetBoundDataStores->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetBoundDataStores,NULL,&GetBoundDataStores_Parms,NULL);
	pFnGetBoundDataStores->FunctionFlags |= 0x400;
	if(out_BoundDataStores)
		memcpy(out_BoundDataStores,&GetBoundDataStores_Parms.out_BoundDataStores,0xC);
}

struct GFxUI_PublishValues_Parms
{
};

void UGFxDataStoreSubscriber::PublishValues()
{
	static UFieldFunc* pFnPublishValues = NULL;
	if(!pFnPublishValues)
		pFnPublishValues = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.PublishValues");

	GFxUI_PublishValues_Parms PublishValues_Parms;
	pFnPublishValues->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPublishValues,NULL,&PublishValues_Parms,NULL);
	pFnPublishValues->FunctionFlags |= 0x400;
}

struct GFxUI_NotifyDataStoreValueUpdated_Parms
{
	class UUIDataStore*                                SourceDataStore;                                  		// 0x000000 (0x0004)              
	unsigned long                                      bValuesInvalidated : 1;                           		// 0x000004 (0x0004) [0x00000001] 
	struct FName                                       PropertyTag;                                      		// 0x000008 (0x0008)              
	class UUIDataProvider*                             SourceProvider;                                   		// 0x000010 (0x0004)              
	int                                                ArrayIndex;                                       		// 0x000014 (0x0004)              
};

void UGFxDataStoreSubscriber::NotifyDataStoreValueUpdated(class UUIDataStore* SourceDataStore,bool bValuesInvalidated,struct FName PropertyTag,class UUIDataProvider* SourceProvider,int ArrayIndex)
{
	static UFieldFunc* pFnNotifyDataStoreValueUpdated = NULL;
	if(!pFnNotifyDataStoreValueUpdated)
		pFnNotifyDataStoreValueUpdated = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated");

	GFxUI_NotifyDataStoreValueUpdated_Parms NotifyDataStoreValueUpdated_Parms;
	NotifyDataStoreValueUpdated_Parms.SourceDataStore = SourceDataStore;
	NotifyDataStoreValueUpdated_Parms.bValuesInvalidated = bValuesInvalidated;
	memcpy(&NotifyDataStoreValueUpdated_Parms.PropertyTag,&PropertyTag,0x8);
	NotifyDataStoreValueUpdated_Parms.SourceProvider = SourceProvider;
	NotifyDataStoreValueUpdated_Parms.ArrayIndex = ArrayIndex;
	pFnNotifyDataStoreValueUpdated->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotifyDataStoreValueUpdated,NULL,&NotifyDataStoreValueUpdated_Parms,NULL);
	pFnNotifyDataStoreValueUpdated->FunctionFlags |= 0x400;
}

struct GFxUI_RefreshSubscriberValue_Parms
{
	int                                                BindingIndex;                                     		// 0x000000 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000004 (0x0004) [0x00000001] 
};

bool UGFxDataStoreSubscriber::RefreshSubscriberValue(int BindingIndex)
{
	static UFieldFunc* pFnRefreshSubscriberValue = NULL;
	if(!pFnRefreshSubscriberValue)
		pFnRefreshSubscriberValue = UObject::FindFunction("Function GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue");

	GFxUI_RefreshSubscriberValue_Parms RefreshSubscriberValue_Parms;
	RefreshSubscriberValue_Parms.BindingIndex = BindingIndex;
	pFnRefreshSubscriberValue->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRefreshSubscriberValue,NULL,&RefreshSubscriberValue_Parms,NULL);
	pFnRefreshSubscriberValue->FunctionFlags |= 0x400;
	return RefreshSubscriberValue_Parms.ReturnValue;
}
