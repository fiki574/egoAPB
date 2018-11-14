
/*
-----------------------------------------------------------------
 - UEnum
-----------------------------------------------------------------
*/
enum GFxTimingMode
{
	TM_Game = 0,
	TM_Real = 1,
	TM_MAX = 2,
};
enum GFxRenderTextureMode
{
	RTM_Opaque = 0,
	RTM_Alpha = 1,
	RTM_AlphaComposite = 2,
	RTM_MAX = 3,
};
enum ASType
{
	AS_Undefined = 0,
	AS_Null = 1,
	AS_Number = 2,
	AS_Int = 3,
	AS_UInt = 4,
	AS_String = 5,
	AS_Boolean = 6,
	AS_MAX = 7,
};
enum GFxScaleMode
{
	SM_NoScale = 0,
	SM_ShowAll = 1,
	SM_ExactFit = 2,
	SM_NoBorder = 3,
	SM_MAX = 4,
};
enum GFxAlign
{
	Align_Center = 0,
	Align_TopCenter = 1,
	Align_BottomCenter = 2,
	Align_CenterLeft = 3,
	Align_CenterRight = 4,
	Align_TopLeft = 5,
	Align_TopRight = 6,
	Align_BottomLeft = 7,
	Align_BottomRight = 8,
	Align_MAX = 9,
};
enum FlashTextureRescale
{
	FlashTextureScale_High = 0,
	FlashTextureScale_Low = 1,
	FlashTextureScale_NextLow = 2,
	FlashTextureScale_Mult4 = 3,
	FlashTextureScale_None = 4,
	FlashTextureScale_MAX = 5,
};

/*
-----------------------------------------------------------------
 - Structs
-----------------------------------------------------------------
*/
//0x000010
//ExternalTexture[0x1D095620]
struct FExternalTexture
{
	struct FString                                     Resource;                                         		// 0x000000 (0x000C)              
	class UTexture*                                    Texture;                                          		// 0x00000C (0x0004)              
};
//0x000018
//SoundThemeBinding[0x1D095688]
struct FSoundThemeBinding
{
	struct FName                                       ThemeName;                                        		// 0x000000 (0x0008)              
	class UUISoundTheme*                               Theme;                                            		// 0x000008 (0x0004)              
	struct FString                                     ThemeClassName;                                   		// 0x00000C (0x000C)              
};
//0x000098
//GFxDataStoreBinding[0x1D0956F0]
struct FGFxDataStoreBinding
{
	struct FUIDataStoreBinding                         DataSource;                                       		// 0x000000 (0x0030)              
	struct FString                                     VarPath;                                          		// 0x000030 (0x000C)              
	struct FString                                     ModelId;                                          		// 0x00003C (0x000C)              
	struct FString                                     ControlId;                                        		// 0x000048 (0x000C)              
	unsigned long                                      bEditable : 1;                                    		// 0x000054 (0x0004) [0x00000001] 
	TArray<struct FName>                               CellTags;                                         		// 0x000058 (0x000C)              
	TArray<unsigned char>                              ModelIdUtf8;                                      		// 0x000064 (0x000C)              
	TArray<unsigned char>                              ControlIdUtf8;                                    		// 0x000070 (0x000C)              
	class UUIListElementProvider*                      ListDataProvider;                                 		// 0x00007C (0x0004)              
	unsigned char                                      _0x000080[0x4];                                   		// 0x000080 (0x0004) ALIGNEMENT
	TArray<struct FName>                               FullCellTags;                                     		// 0x000084 (0x000C)              
	DWORD                                              ModelRef;                                         		// 0x000090 (0x0004)              
	DWORD                                              ControlRef;                                       		// 0x000094 (0x0004)              
};
//0x00001C
//GFxWidgetBinding[0x1D095758]
struct FGFxWidgetBinding
{
	struct FName                                       WidgetName;                                       		// 0x000000 (0x0008)              
	struct FString                                     WidgetPath;                                       		// 0x000008 (0x000C)              
	class UClass*                                      WidgetClass;                                      		// 0x000014 (0x0004)              
	unsigned long                                      bOptional : 1;                                    		// 0x000018 (0x0004) [0x00000001] 
	unsigned long                                      bLoaded : 1;                                      		// 0x000018 (0x0004) [0x00000002] 
};
//0x00001C
//ASValue[0x1D0957C0]
struct FASValue
{
	unsigned char                                      Type;                                             		// 0x000000 (0x0001)              PROPERTY: ASType
	unsigned char                                      _0x000001[0x3];                                   		// 0x000001 (0x0003) MISSED OFFSET
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
	float                                              N;                                                		// 0x000008 (0x0004)              
	int                                                I;                                                		// 0x00000C (0x0004)              
	struct FString                                     S;                                                		// 0x000010 (0x000C)              
};
//0x00000C
//GCReference[0x1D095828]
struct FGCReference
{
	class UObject*                                     m_object;                                         		// 0x000000 (0x0004)              
	int                                                m_count;                                          		// 0x000004 (0x0004)              
	int                                                m_statid;                                         		// 0x000008 (0x0004)              
};
//0x00002C
//ASDisplayInfo[0x1D095890]
struct FASDisplayInfo
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
	float                                              Z;                                                		// 0x000008 (0x0004)              
	float                                              Rotation;                                         		// 0x00000C (0x0004)              
	float                                              XRotation;                                        		// 0x000010 (0x0004)              
	float                                              YRotation;                                        		// 0x000014 (0x0004)              
	float                                              XScale;                                           		// 0x000018 (0x0004)              
	float                                              YScale;                                           		// 0x00001C (0x0004)              
	float                                              ZScale;                                           		// 0x000020 (0x0004)              
	float                                              Alpha;                                            		// 0x000024 (0x0004)              
	unsigned long                                      Visible : 1;                                      		// 0x000028 (0x0004) [0x00000001] 
	unsigned long                                      hasX : 1;                                         		// 0x000028 (0x0004) [0x00000002] 
	unsigned long                                      hasY : 1;                                         		// 0x000028 (0x0004) [0x00000004] 
	unsigned long                                      hasZ : 1;                                         		// 0x000028 (0x0004) [0x00000008] 
	unsigned long                                      hasRotation : 1;                                  		// 0x000028 (0x0004) [0x00000010] 
	unsigned long                                      hasXRotation : 1;                                 		// 0x000028 (0x0004) [0x00000020] 
	unsigned long                                      hasYRotation : 1;                                 		// 0x000028 (0x0004) [0x00000040] 
	unsigned long                                      hasXScale : 1;                                    		// 0x000028 (0x0004) [0x00000080] 
	unsigned long                                      hasYScale : 1;                                    		// 0x000028 (0x0004) [0x00000100] 
	unsigned long                                      hasZScale : 1;                                    		// 0x000028 (0x0004) [0x00000200] 
	unsigned long                                      hasAlpha : 1;                                     		// 0x000028 (0x0004) [0x00000400] 
	unsigned long                                      hasVisible : 1;                                   		// 0x000028 (0x0004) [0x00000800] 
};
//0x000020
//ASColorTransform[0x1D0958F8]
struct FASColorTransform
{
	struct FLinearColor                                Multiply;                                         		// 0x000000 (0x0010)              
	struct FLinearColor                                Add;                                              		// 0x000010 (0x0010)              
};

/*
-----------------------------------------------------------------
 - Classes
-----------------------------------------------------------------
*/
//0x000010 (0x000050 - 0x000040)
//GFxEngine[0x10356D40]
class UGFxEngine : public UObject
{
public:
	TArray<struct FGCReference>                        GCReferences;                                     		// 0x000040 (0x000C)              
	int                                                RefCount;                                         		// 0x00004C (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxEngine");
		return pClassPointer;
	};
};
UClass* UGFxEngine::pClassPointer = NULL;

//0x000000 (0x000040 - 0x000040)
//GFxFSCmdHandler[0x10356C10]
class UGFxFSCmdHandler : public UObject
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxFSCmdHandler");
		return pClassPointer;
	};

public:
	bool FSCommand(class UGFxMoviePlayer* Movie,class UGFxEvent_FSCommand* Event,struct FString Cmd,struct FString Arg);//GFxUI.GFxFSCmdHandler.FSCommand
};
UClass* UGFxFSCmdHandler::pClassPointer = NULL;

//0x000008 (0x00007C - 0x000074)
//GFxInteraction[0x10356AE0]
class UGFxInteraction : public UInteraction
{
public:
	DWORD                                              VfTable_FCallbackEventDevice;                     		// 0x000074 (0x0004)              
	unsigned long                                      bFakeMobileTouches : 1;                           		// 0x000078 (0x0004) [0x00000001] 

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxInteraction");
		return pClassPointer;
	};

public:
	class UGFxMoviePlayer* GetFocusMovie(int ControllerId);//GFxUI.GFxInteraction.GetFocusMovie
	void NotifyPlayerAdded(int PlayerIndex,class ULocalPlayer* AddedPlayer);//GFxUI.GFxInteraction.NotifyPlayerAdded
	void NotifySplitscreenLayoutChanged();//GFxUI.GFxInteraction.NotifySplitscreenLayoutChanged
	void NotifyPlayerRemoved(int PlayerIndex,class ULocalPlayer* RemovedPlayer);//GFxUI.GFxInteraction.NotifyPlayerRemoved
	void CloseAllMoviePlayers();//GFxUI.GFxInteraction.CloseAllMoviePlayers
	void NotifyGameSessionEnded();//GFxUI.GFxInteraction.NotifyGameSessionEnded
};
UClass* UGFxInteraction::pClassPointer = NULL;

//0x000148 (0x000188 - 0x000040)
//GFxMoviePlayer[0x103569B0]
class UGFxMoviePlayer : public UObject
{
public:
	DWORD                                              pMovie;                                           		// 0x000040 (0x0004)              
	DWORD                                              pCaptureKeys;                                     		// 0x000044 (0x0004)              
	DWORD                                              pFocusIgnoreKeys;                                 		// 0x000048 (0x0004)              
	unsigned char                                      ASUClasses[0x3C];                                 		// 0x00004C (0x003C)              UNKNOWN PROPERTY: MapProperty
	unsigned char                                      ASUObjects[0x3C];                                 		// 0x000088 (0x003C)              UNKNOWN PROPERTY: MapProperty
	int                                                NextASUObject;                                    		// 0x0000C4 (0x0004)              
	class USwfMovie*                                   MovieInfo;                                        		// 0x0000C8 (0x0004)              
	unsigned long                                      bMovieIsOpen : 1;                                 		// 0x0000CC (0x0004) [0x00000001] 
	unsigned long                                      bDisplayWithHudOff : 1;                           		// 0x0000CC (0x0004) [0x00000002] 
	unsigned long                                      bEnableGammaCorrection : 1;                       		// 0x0000CC (0x0004) [0x00000004] 
	unsigned long                                      bWidgetsInitializedThisFrame : 1;                 		// 0x0000CC (0x0004) [0x00000008] 
	unsigned long                                      bLogUnhandedWidgetInitializations : 1;            		// 0x0000CC (0x0004) [0x00000010] 
	unsigned long                                      bAllowInput : 1;                                  		// 0x0000CC (0x0004) [0x00000020] 
	unsigned long                                      bAllowFocus : 1;                                  		// 0x0000CC (0x0004) [0x00000040] 
	unsigned long                                      bAutoPlay : 1;                                    		// 0x0000CC (0x0004) [0x00000080] 
	unsigned long                                      bPauseGameWhileActive : 1;                        		// 0x0000CC (0x0004) [0x00000100] 
	unsigned long                                      bDisableWorldRendering : 1;                       		// 0x0000CC (0x0004) [0x00000200] 
	unsigned long                                      bCaptureWorldRendering : 1;                       		// 0x0000CC (0x0004) [0x00000400] 
	unsigned long                                      bCloseOnLevelChange : 1;                          		// 0x0000CC (0x0004) [0x00000800] 
	unsigned long                                      bOnlyOwnerFocusable : 1;                          		// 0x0000CC (0x0004) [0x00001000] 
	unsigned long                                      bForceFullViewport : 1;                           		// 0x0000CC (0x0004) [0x00002000] 
	unsigned long                                      bDiscardNonOwnerInput : 1;                        		// 0x0000CC (0x0004) [0x00004000] 
	unsigned long                                      bCaptureInput : 1;                                		// 0x0000CC (0x0004) [0x00008000] 
	unsigned long                                      bCaptureMouseInput : 1;                           		// 0x0000CC (0x0004) [0x00010000] 
	unsigned long                                      bShowGameCursor : 1;                              		// 0x0000CC (0x0004) [0x00020000] 
	unsigned long                                      bIgnoreMouseInput : 1;                            		// 0x0000CC (0x0004) [0x00040000] 
	unsigned long                                      bIsSplitscreenLayoutModified : 1;                 		// 0x0000CC (0x0004) [0x00080000] 
	unsigned long                                      bShowHardwareMouseCursor : 1;                     		// 0x0000CC (0x0004) [0x00100000] 
	unsigned long                                      bIgnoreAdvancedScaling : 1;                       		// 0x0000CC (0x0004) [0x00200000] 
	unsigned long                                      bBlurLesserMovies : 1;                            		// 0x0000CC (0x0004) [0x00400000] 
	unsigned long                                      bHideLesserMovies : 1;                            		// 0x0000CC (0x0004) [0x00800000] 
	unsigned long                                      bIsPriorityBlurred : 1;                           		// 0x0000CC (0x0004) [0x01000000] 
	unsigned long                                      bIsPriorityHidden : 1;                            		// 0x0000CC (0x0004) [0x02000000] 
	unsigned long                                      bIgnoreVisibilityEffect : 1;                      		// 0x0000CC (0x0004) [0x04000000] 
	unsigned long                                      bIgnoreBlurEffect : 1;                            		// 0x0000CC (0x0004) [0x08000000] 
	class UTextureRenderTarget2D*                      RenderTexture;                                    		// 0x0000D0 (0x0004)              
	int                                                LocalPlayerOwnerIndex;                            		// 0x0000D4 (0x0004)              
	class UObject*                                     ExternalInterface;                                		// 0x0000D8 (0x0004)              
	TArray<struct FName>                               CaptureKeys;                                      		// 0x0000DC (0x000C)              
	TArray<struct FName>                               FocusIgnoreKeys;                                  		// 0x0000E8 (0x000C)              
	TArray<struct FExternalTexture>                    ExternalTextures;                                 		// 0x0000F4 (0x000C)              
	TArray<struct FSoundThemeBinding>                  SoundThemes;                                      		// 0x000100 (0x000C)              
	unsigned char                                      TimingMode;                                       		// 0x00010C (0x0001)              PROPERTY: GFxTimingMode
	unsigned char                                      RenderTextureMode;                                		// 0x00010D (0x0001)              PROPERTY: GFxRenderTextureMode
	unsigned char                                      Priority;                                         		// 0x00010E (0x0001)              PROPERTY: 
	unsigned char                                      _0x00010F[0x1];                                   		// 0x00010F (0x0001) MISSED OFFSET
	TArray<struct FGFxDataStoreBinding>                DataStoreBindings;                                		// 0x000110 (0x000C)              
	class UGFxDataStoreSubscriber*                     DataStoreSubscriber;                              		// 0x00011C (0x0004)              
	TArray<struct FGFxWidgetBinding>                   WidgetBindings;                                   		// 0x000120 (0x000C)              
	unsigned char                                      WidgetPathBindings[0x3C];                         		// 0x00012C (0x003C)              UNKNOWN PROPERTY: MapProperty
	class UGFxObject*                                  SplitscreenLayoutObject;                          		// 0x000168 (0x0004)              
	int                                                SplitscreenLayoutYAdjust;                         		// 0x00016C (0x0004)              
	TArray<class UObject*>                             DelegateReferences;                               		// 0x000170 (0x000C)              
	struct FScriptDelegate                             __OnPostAdvance__Delegate;                        		// 0x00017C (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxMoviePlayer");
		return pClassPointer;
	};

public:
	void FlushPlayerInput(bool capturekeysonly);//GFxUI.GFxMoviePlayer.FlushPlayerInput
	void ActionScriptSetFunction(class UGFxObject* Object,struct FString Member);//GFxUI.GFxMoviePlayer.ActionScriptSetFunction
	void SetVariableString(struct FString Path,struct FString S);//GFxUI.GFxMoviePlayer.SetVariableString
	void RefreshDataStoreBindings();//GFxUI.GFxMoviePlayer.RefreshDataStoreBindings
	void UpdateSplitscreenLayout();//GFxUI.GFxMoviePlayer.UpdateSplitscreenLayout
	int GetAVMVersion();//GFxUI.GFxMoviePlayer.GetAVMVersion
	void ApplyPriorityEffect(bool bRequestedBlurState,bool bRequestedHiddenState);//GFxUI.GFxMoviePlayer.ApplyPriorityEffect
	class UGameViewportClient* GetGameViewportClient();//GFxUI.GFxMoviePlayer.GetGameViewportClient
	void SetMovieInfo(class USwfMovie* Data);//GFxUI.GFxMoviePlayer.SetMovieInfo
	void SetViewport(int X,int Y,int Width,int Height);//GFxUI.GFxMoviePlayer.SetViewport
	void ApplyPriorityVisibilityEffect(bool bRemoveEffect);//GFxUI.GFxMoviePlayer.ApplyPriorityVisibilityEffect
	void OnFocusGained(int LocalPlayerIndex);//GFxUI.GFxMoviePlayer.OnFocusGained
	class UGFxObject* CreateObject(struct FString ASClass,class UClass* Type,TArray<struct FASValue> args);//GFxUI.GFxMoviePlayer.CreateObject
	class ULocalPlayer* GetLP();//GFxUI.GFxMoviePlayer.GetLP
	class UGFxObject* ActionScriptConstructor(struct FString ClassName);//GFxUI.GFxMoviePlayer.ActionScriptConstructor
	struct FString ActionScriptString(struct FString Path);//GFxUI.GFxMoviePlayer.ActionScriptString
	void OnCleanup(bool bUnload);//GFxUI.GFxMoviePlayer.OnCleanup
	void PlaySoundFromTheme(class UGFxObject* EventSource,struct FName EventName,struct FName SoundThemeName);//GFxUI.GFxMoviePlayer.PlaySoundFromTheme
	int ActionScriptInt(struct FString Path);//GFxUI.GFxMoviePlayer.ActionScriptInt
	void PostWidgetInit();//GFxUI.GFxMoviePlayer.PostWidgetInit
	bool WidgetUnloaded(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget);//GFxUI.GFxMoviePlayer.WidgetUnloaded
	void AddCaptureKey(struct FName Key);//GFxUI.GFxMoviePlayer.AddCaptureKey
	void ConsoleCommand(struct FString Command);//GFxUI.GFxMoviePlayer.ConsoleCommand
	bool Start(bool StartPaused);//GFxUI.GFxMoviePlayer.Start
	class UGFxObject* GetVariableObject(struct FString Path,class UClass* Type);//GFxUI.GFxMoviePlayer.GetVariableObject
	bool GetVariableFloatArray(struct FString Path,int Index,TArray<float>* Arg);//GFxUI.GFxMoviePlayer.GetVariableFloatArray
	bool GetVariableBool(struct FString Path);//GFxUI.GFxMoviePlayer.GetVariableBool
	void SetWidgetPathBinding(class UGFxObject* WidgetToBind,struct FName Path);//GFxUI.GFxMoviePlayer.SetWidgetPathBinding
	void OnPostAdvance(float DeltaTime);//GFxUI.GFxMoviePlayer.OnPostAdvance
	void AddFocusIgnoreKey(struct FName Key);//GFxUI.GFxMoviePlayer.AddFocusIgnoreKey
	void SetMovieCanReceiveInput(bool bCanReceiveInput);//GFxUI.GFxMoviePlayer.SetMovieCanReceiveInput
	void SetMovieCanReceiveFocus(bool bCanReceiveFocus);//GFxUI.GFxMoviePlayer.SetMovieCanReceiveFocus
	void SetExternalInterface(class UObject* H);//GFxUI.GFxMoviePlayer.SetExternalInterface
	void ConditionalClearPause();//GFxUI.GFxMoviePlayer.ConditionalClearPause
	void OnClose();//GFxUI.GFxMoviePlayer.OnClose
	void SetPause(bool bPausePlayback);//GFxUI.GFxMoviePlayer.SetPause
	bool SetVariableIntArray(struct FString Path,int Index,TArray<int> Arg);//GFxUI.GFxMoviePlayer.SetVariableIntArray
	bool SetVariableFloatArray(struct FString Path,int Index,TArray<float> Arg);//GFxUI.GFxMoviePlayer.SetVariableFloatArray
	void SetVariable(struct FString Path,struct FASValue Arg);//GFxUI.GFxMoviePlayer.SetVariable
	bool SetVariableArray(struct FString Path,int Index,TArray<struct FASValue> Arg);//GFxUI.GFxMoviePlayer.SetVariableArray
	void RemoveAllDelegates(class UObject* TargetObject);//GFxUI.GFxMoviePlayer.RemoveAllDelegates
	void Close(bool Unload);//GFxUI.GFxMoviePlayer.Close
	struct FString GetVariableString(struct FString Path);//GFxUI.GFxMoviePlayer.GetVariableString
	bool GetVariableIntArray(struct FString Path,int Index,TArray<int>* Arg);//GFxUI.GFxMoviePlayer.GetVariableIntArray
	void SetTimingMode(unsigned char Mode);//GFxUI.GFxMoviePlayer.SetTimingMode
	void SetVariableInt(struct FString Path,int I);//GFxUI.GFxMoviePlayer.SetVariableInt
	void PublishDataStoreValues();//GFxUI.GFxMoviePlayer.PublishDataStoreValues
	void SetVariableNumber(struct FString Path,float F);//GFxUI.GFxMoviePlayer.SetVariableNumber
	bool GetVariableStringArray(struct FString Path,int Index,TArray<struct FString>* Arg);//GFxUI.GFxMoviePlayer.GetVariableStringArray
	bool SetVariableStringArray(struct FString Path,int Index,TArray<struct FString> Arg);//GFxUI.GFxMoviePlayer.SetVariableStringArray
	void Init(class ULocalPlayer* LocPlay);//GFxUI.GFxMoviePlayer.Init
	class APlayerController* GetPC();//GFxUI.GFxMoviePlayer.GetPC
	bool SetExternalTexture(struct FString Resource,class UTexture* Texture,bool bUpdateScale);//GFxUI.GFxMoviePlayer.SetExternalTexture
	float ActionScriptFloat(struct FString Path);//GFxUI.GFxMoviePlayer.ActionScriptFloat
	void RemoveDelegate(class UObject* TargetObject,struct FName FunctionName);//GFxUI.GFxMoviePlayer.RemoveDelegate
	void SetPriority(unsigned char NewPriority);//GFxUI.GFxMoviePlayer.SetPriority
	class UGFxObject* CreateArray();//GFxUI.GFxMoviePlayer.CreateArray
	void SetPerspective3D(FMatrix* matPersp);//GFxUI.GFxMoviePlayer.SetPerspective3D
	void ActionScriptVoid(struct FString Path);//GFxUI.GFxMoviePlayer.ActionScriptVoid
	struct FASValue GetVariable(struct FString Path);//GFxUI.GFxMoviePlayer.GetVariable
	void ApplyPriorityBlurEffect(bool bRemoveEffect);//GFxUI.GFxMoviePlayer.ApplyPriorityBlurEffect
	void SetAlignment(unsigned char A);//GFxUI.GFxMoviePlayer.SetAlignment
	float GetVariableNumber(struct FString Path);//GFxUI.GFxMoviePlayer.GetVariableNumber
	class UGFxObject* ActionScriptObject(struct FString Path);//GFxUI.GFxMoviePlayer.ActionScriptObject
	void SetViewScaleMode(unsigned char SM);//GFxUI.GFxMoviePlayer.SetViewScaleMode
	int GetVariableInt(struct FString Path);//GFxUI.GFxMoviePlayer.GetVariableInt
	void SetView3D(FMatrix* matView);//GFxUI.GFxMoviePlayer.SetView3D
	void SetVariableObject(struct FString Path,class UGFxObject* Object);//GFxUI.GFxMoviePlayer.SetVariableObject
	void PostAdvance(float DeltaTime);//GFxUI.GFxMoviePlayer.PostAdvance
	void SetVariableBool(struct FString Path,bool B);//GFxUI.GFxMoviePlayer.SetVariableBool
	void GetVisibleFrameRect(float* x0,float* y0,float* X1,float* Y1);//GFxUI.GFxMoviePlayer.GetVisibleFrameRect
	bool GetVariableArray(struct FString Path,int Index,TArray<struct FASValue>* Arg);//GFxUI.GFxMoviePlayer.GetVariableArray
	void ClearCaptureKeys();//GFxUI.GFxMoviePlayer.ClearCaptureKeys
	bool WidgetInitialized(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget);//GFxUI.GFxMoviePlayer.WidgetInitialized
	void Advance(float Time);//GFxUI.GFxMoviePlayer.Advance
	void ClearFocusIgnoreKeys();//GFxUI.GFxMoviePlayer.ClearFocusIgnoreKeys
	void CleanupDelegates();//GFxUI.GFxMoviePlayer.CleanupDelegates
	void OnFocusLost(int LocalPlayerIndex);//GFxUI.GFxMoviePlayer.OnFocusLost
	struct FASValue Invoke(struct FString method,TArray<struct FASValue> args);//GFxUI.GFxMoviePlayer.Invoke
};
UClass* UGFxMoviePlayer::pClassPointer = NULL;

//0x00003C (0x00007C - 0x000040)
//GFxObject[0x10356880]
class UGFxObject : public UObject
{
public:
	int                                                Value[0xC];                                       		// 0x000040 (0x0030)              
	TArray<struct FGFxWidgetBinding>                   SubWidgetBindings;                                		// 0x000070 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxObject");
		return pClassPointer;
	};

public:
	struct FString GetElementString(int Index);//GFxUI.GFxObject.GetElementString
	struct FASValue Invoke(struct FString Member,TArray<struct FASValue> args);//GFxUI.GFxObject.Invoke
	int GetInt(struct FString Member);//GFxUI.GFxObject.GetInt
	void SetFunction(struct FString Member,struct FScriptDelegate functionDelegate);//GFxUI.GFxObject.SetFunction
	void GotoAndStop(struct FString frame);//GFxUI.GFxObject.GotoAndStop
	void SetFloat(struct FString Member,float F);//GFxUI.GFxObject.SetFloat
	class UGFxObject* CreateEmptyMovieClip(struct FString instanceName,int depth,class UClass* Type);//GFxUI.GFxObject.CreateEmptyMovieClip
	int GetElementInt(int Index);//GFxUI.GFxObject.GetElementInt
	float ActionScriptFloat(struct FString method);//GFxUI.GFxObject.ActionScriptFloat
	struct FASDisplayInfo GetDisplayInfo();//GFxUI.GFxObject.GetDisplayInfo
	bool GetBool(struct FString Member);//GFxUI.GFxObject.GetBool
	class UGFxObject* ActionScriptObject(struct FString Path);//GFxUI.GFxObject.ActionScriptObject
	void GotoAndStopI(int frame);//GFxUI.GFxObject.GotoAndStopI
	void SetElementMemberFloat(int Index,struct FString Member,float F);//GFxUI.GFxObject.SetElementMemberFloat
	void SetVisible(bool Visible);//GFxUI.GFxObject.SetVisible
	struct FASDisplayInfo GetElementDisplayInfo(int Index);//GFxUI.GFxObject.GetElementDisplayInfo
	bool GetPosition(float* X,float* Y);//GFxUI.GFxObject.GetPosition
	void SetElement(int Index,struct FASValue Arg);//GFxUI.GFxObject.SetElement
	class UGFxObject* GetElementObject(int Index,class UClass* Type);//GFxUI.GFxObject.GetElementObject
	void SetObject(struct FString Member,class UGFxObject* Val);//GFxUI.GFxObject.SetObject
	void SetElementColorTransform(int Index,struct FASColorTransform cxform);//GFxUI.GFxObject.SetElementColorTransform
	void ActionScriptVoid(struct FString method);//GFxUI.GFxObject.ActionScriptVoid
	void SetElementDisplayInfo(int Index,struct FASDisplayInfo D);//GFxUI.GFxObject.SetElementDisplayInfo
	struct FString GetString(struct FString Member);//GFxUI.GFxObject.GetString
	void SetColorTransform(struct FASColorTransform cxform);//GFxUI.GFxObject.SetColorTransform
	struct FString GetText();//GFxUI.GFxObject.GetText
	int GetElementMemberInt(int Index,struct FString Member);//GFxUI.GFxObject.GetElementMemberInt
	void ActionScriptSetFunction(struct FString Member);//GFxUI.GFxObject.ActionScriptSetFunction
	void SetText(struct FString Text,class UTranslationContext* InContext);//GFxUI.GFxObject.SetText
	void SetDisplayInfo(struct FASDisplayInfo D);//GFxUI.GFxObject.SetDisplayInfo
	void ActionScriptSetFunctionOn(class UGFxObject* Target,struct FString Member);//GFxUI.GFxObject.ActionScriptSetFunctionOn
	void SetElementVisible(int Index,bool Visible);//GFxUI.GFxObject.SetElementVisible
	void SetElementString(int Index,struct FString S);//GFxUI.GFxObject.SetElementString
	void SetDisplayMatrix(FMatrix M);//GFxUI.GFxObject.SetDisplayMatrix
	void Set(struct FString Member,struct FASValue Arg);//GFxUI.GFxObject.Set
	struct FString ActionScriptString(struct FString method);//GFxUI.GFxObject.ActionScriptString
	int ActionScriptInt(struct FString method);//GFxUI.GFxObject.ActionScriptInt
	struct FASValue GetElementMember(int Index,struct FString Member);//GFxUI.GFxObject.GetElementMember
	TArray<class UGFxObject*> ActionScriptArray(struct FString Path);//GFxUI.GFxObject.ActionScriptArray
	void SetString(struct FString Member,struct FString S,class UTranslationContext* InContext);//GFxUI.GFxObject.SetString
	bool GetElementMemberBool(int Index,struct FString Member);//GFxUI.GFxObject.GetElementMemberBool
	bool WidgetUnloaded(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget);//GFxUI.GFxObject.WidgetUnloaded
	struct FASValue GetElement(int Index);//GFxUI.GFxObject.GetElement
	bool WidgetInitialized(struct FName WidgetName,struct FName WidgetPath,class UGFxObject* Widget);//GFxUI.GFxObject.WidgetInitialized
	void SetElementMember(int Index,struct FString Member,struct FASValue Arg);//GFxUI.GFxObject.SetElementMember
	void SetPosition(float X,float Y);//GFxUI.GFxObject.SetPosition
	void GotoAndPlayI(int frame);//GFxUI.GFxObject.GotoAndPlayI
	void SetElementFloat(int Index,float F);//GFxUI.GFxObject.SetElementFloat
	FMatrix GetDisplayMatrix3D();//GFxUI.GFxObject.GetDisplayMatrix3D
	float GetElementFloat(int Index);//GFxUI.GFxObject.GetElementFloat
	void SetDisplayMatrix3D(FMatrix M);//GFxUI.GFxObject.SetDisplayMatrix3D
	void SetInt(struct FString Member,int I);//GFxUI.GFxObject.SetInt
	struct FString TranslateString(struct FString StringToTranslate,class UTranslationContext* InContext);//GFxUI.GFxObject.TranslateString
	float GetFloat(struct FString Member);//GFxUI.GFxObject.GetFloat
	void SetElementPosition(int Index,float X,float Y);//GFxUI.GFxObject.SetElementPosition
	class UGFxObject* GetElementMemberObject(int Index,struct FString Member,class UClass* Type);//GFxUI.GFxObject.GetElementMemberObject
	struct FString GetElementMemberString(int Index,struct FString Member);//GFxUI.GFxObject.GetElementMemberString
	void SetElementInt(int Index,int I);//GFxUI.GFxObject.SetElementInt
	bool GetElementBool(int Index);//GFxUI.GFxObject.GetElementBool
	void SetElementDisplayMatrix(int Index,FMatrix M);//GFxUI.GFxObject.SetElementDisplayMatrix
	struct FASColorTransform GetColorTransform();//GFxUI.GFxObject.GetColorTransform
	void GotoAndPlay(struct FString frame);//GFxUI.GFxObject.GotoAndPlay
	struct FASValue Get(struct FString Member);//GFxUI.GFxObject.Get
	void SetElementMemberBool(int Index,struct FString Member,bool B);//GFxUI.GFxObject.SetElementMemberBool
	void SetElementObject(int Index,class UGFxObject* Val);//GFxUI.GFxObject.SetElementObject
	void SetElementMemberString(int Index,struct FString Member,struct FString S);//GFxUI.GFxObject.SetElementMemberString
	void SetBool(struct FString Member,bool B);//GFxUI.GFxObject.SetBool
	class UGFxObject* GetObject(struct FString Member,class UClass* Type);//GFxUI.GFxObject.GetObject
	void SetElementBool(int Index,bool B);//GFxUI.GFxObject.SetElementBool
	class UGFxObject* AttachMovie(struct FString symbolname,struct FString instanceName,int depth,class UClass* Type);//GFxUI.GFxObject.AttachMovie
	FMatrix GetDisplayMatrix();//GFxUI.GFxObject.GetDisplayMatrix
	FMatrix GetElementDisplayMatrix(int Index);//GFxUI.GFxObject.GetElementDisplayMatrix
	float GetElementMemberFloat(int Index,struct FString Member);//GFxUI.GFxObject.GetElementMemberFloat
	void SetElementMemberObject(int Index,struct FString Member,class UGFxObject* Val);//GFxUI.GFxObject.SetElementMemberObject
	void SetElementMemberInt(int Index,struct FString Member,int I);//GFxUI.GFxObject.SetElementMemberInt
};
UClass* UGFxObject::pClassPointer = NULL;

//0x00000C (0x000088 - 0x00007C)
//GFxClikWidget[0x10356750]
class UGFxClikWidget : public UGFxObject
{
public:
	struct FScriptDelegate                             __EventListener__Delegate;                        		// 0x00007C (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxClikWidget");
		return pClassPointer;
	};

public:
	void SetListener(class UGFxObject* O,struct FString Member,struct FScriptDelegate Listener);//GFxUI.GFxClikWidget.SetListener
	struct FString GetEventStringFromTypename(struct FName Typename);//GFxUI.GFxClikWidget.GetEventStringFromTypename
	void AddEventListener(struct FName Type,struct FScriptDelegate Listener,bool useCapture,int listenerPriority,bool useWeakReference);//GFxUI.GFxClikWidget.AddEventListener
	void EventListener(class UGFxObject* Data);//GFxUI.GFxClikWidget.EventListener
	void removeEventListener(struct FString Type,struct FScriptDelegate Listener);//GFxUI.GFxClikWidget.removeEventListener
	void ASRemoveAllEventListeners(struct FString Event);//GFxUI.GFxClikWidget.ASRemoveAllEventListeners
	void RemoveAllEventListeners(struct FString Event);//GFxUI.GFxClikWidget.RemoveAllEventListeners
	void ASAddEventListener(struct FString Type,class UGFxObject* O,struct FString func);//GFxUI.GFxClikWidget.ASAddEventListener
	void AS3AddEventListener(struct FString Type,struct FScriptDelegate Listener,bool useCapture,int listenerPriority,bool useWeakReference);//GFxUI.GFxClikWidget.AS3AddEventListener
	void AS3RemoveEventListener(struct FString Type,struct FScriptDelegate Listener);//GFxUI.GFxClikWidget.AS3RemoveEventListener
};
UClass* UGFxClikWidget::pClassPointer = NULL;

//0x000030 (0x000070 - 0x000040)
//GFxRawData[0x10356620]
class UGFxRawData : public UObject
{
public:
	TArray<unsigned char>                              RawData;                                          		// 0x000040 (0x000C)              
	TArray<struct FString>                             ReferencedSwfs;                                   		// 0x00004C (0x000C)              
	TArray<class UObject*>                             References;                                       		// 0x000058 (0x000C)              
	TArray<class UObject*>                             UserReferences;                                   		// 0x000064 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxRawData");
		return pClassPointer;
	};
};
UClass* UGFxRawData::pClassPointer = NULL;

//0x000020 (0x000090 - 0x000070)
//SwfMovie[0x103564F0]
class USwfMovie : public UGFxRawData
{
public:
	unsigned long                                      bUsesFontlib : 1;                                 		// 0x000070 (0x0004) [0x00000001] 
	unsigned long                                      bSetSRGBOnImportedTextures : 1;                   		// 0x000070 (0x0004) [0x00000002] 
	unsigned long                                      bPackTextures : 1;                                		// 0x000070 (0x0004) [0x00000004] 
	unsigned long                                      bForceSquarePacking : 1;                          		// 0x000070 (0x0004) [0x00000008] 
	int                                                PackTextureSize;                                  		// 0x000074 (0x0004)              
	unsigned char                                      TextureRescale;                                   		// 0x000078 (0x0001)              PROPERTY: FlashTextureRescale
	unsigned char                                      _0x000079[0x3];                                   		// 0x000079 (0x0003) MISSED OFFSET
	struct FString                                     TextureFormat;                                    		// 0x00007C (0x000C)              
	int                                                RTTextures;                                       		// 0x000088 (0x0004)              
	int                                                RTVideoTextures;                                  		// 0x00008C (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.SwfMovie");
		return pClassPointer;
	};
};
UClass* USwfMovie::pClassPointer = NULL;

//0x000000 (0x000090 - 0x000090)
//FlashMovie[0x103563C0]
class UFlashMovie : public USwfMovie
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.FlashMovie");
		return pClassPointer;
	};
};
UClass* UFlashMovie::pClassPointer = NULL;

//0x000008 (0x0000B4 - 0x0000AC)
//GFxAction_CloseMovie[0x10356290]
class UGFxAction_CloseMovie : public USequenceAction
{
public:
	class UGFxMoviePlayer*                             Movie;                                            		// 0x0000AC (0x0004)              
	unsigned long                                      bUnload : 1;                                      		// 0x0000B0 (0x0004) [0x00000001] 

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxAction_CloseMovie");
		return pClassPointer;
	};

public:
	bool IsValidLevelSequenceObject();//GFxUI.GFxAction_CloseMovie.IsValidLevelSequenceObject
};
UClass* UGFxAction_CloseMovie::pClassPointer = NULL;

//0x000010 (0x0000BC - 0x0000AC)
//GFxAction_GetVariable[0x10356160]
class UGFxAction_GetVariable : public USequenceAction
{
public:
	class UGFxMoviePlayer*                             Movie;                                            		// 0x0000AC (0x0004)              
	struct FString                                     Variable;                                         		// 0x0000B0 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxAction_GetVariable");
		return pClassPointer;
	};

public:
	bool IsValidLevelSequenceObject();//GFxUI.GFxAction_GetVariable.IsValidLevelSequenceObject
};
UClass* UGFxAction_GetVariable::pClassPointer = NULL;

//0x00001C (0x0000C8 - 0x0000AC)
//GFxAction_Invoke[0x10356030]
class UGFxAction_Invoke : public USequenceAction
{
public:
	class UGFxMoviePlayer*                             Movie;                                            		// 0x0000AC (0x0004)              
	struct FString                                     MethodName;                                       		// 0x0000B0 (0x000C)              
	TArray<struct FASValue>                            arguments;                                        		// 0x0000BC (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxAction_Invoke");
		return pClassPointer;
	};

public:
	bool IsValidLevelSequenceObject();//GFxUI.GFxAction_Invoke.IsValidLevelSequenceObject
};
UClass* UGFxAction_Invoke::pClassPointer = NULL;

//0x000030 (0x0000DC - 0x0000AC)
//GFxAction_OpenMovie[0x10355F00]
class UGFxAction_OpenMovie : public USequenceAction
{
public:
	class USwfMovie*                                   Movie;                                            		// 0x0000AC (0x0004)              
	class UClass*                                      MoviePlayerClass;                                 		// 0x0000B0 (0x0004)              
	class UGFxMoviePlayer*                             MoviePlayer;                                      		// 0x0000B4 (0x0004)              
	unsigned long                                      bTakeFocus : 1;                                   		// 0x0000B8 (0x0004) [0x00000001] 
	unsigned long                                      bCaptureInput : 1;                                		// 0x0000B8 (0x0004) [0x00000002] 
	unsigned long                                      bStartPaused : 1;                                 		// 0x0000B8 (0x0004) [0x00000004] 
	unsigned long                                      bEnableGammaCorrection : 1;                       		// 0x0000B8 (0x0004) [0x00000008] 
	unsigned long                                      bDisplayWithHudOff : 1;                           		// 0x0000B8 (0x0004) [0x00000010] 
	unsigned char                                      RenderTextureMode;                                		// 0x0000BC (0x0001)              PROPERTY: GFxRenderTextureMode
	unsigned char                                      _0x0000BD[0x3];                                   		// 0x0000BD (0x0003) MISSED OFFSET
	class UTextureRenderTarget2D*                      RenderTexture;                                    		// 0x0000C0 (0x0004)              
	TArray<struct FName>                               CaptureKeys;                                      		// 0x0000C4 (0x000C)              
	TArray<struct FName>                               FocusIgnoreKeys;                                  		// 0x0000D0 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxAction_OpenMovie");
		return pClassPointer;
	};

public:
	bool IsValidLevelSequenceObject();//GFxUI.GFxAction_OpenMovie.IsValidLevelSequenceObject
};
UClass* UGFxAction_OpenMovie::pClassPointer = NULL;

//0x000010 (0x0000BC - 0x0000AC)
//GFxAction_SetCaptureKeys[0x10355DD0]
class UGFxAction_SetCaptureKeys : public USequenceAction
{
public:
	class UGFxMoviePlayer*                             Movie;                                            		// 0x0000AC (0x0004)              
	TArray<struct FName>                               CaptureKeys;                                      		// 0x0000B0 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxAction_SetCaptureKeys");
		return pClassPointer;
	};
};
UClass* UGFxAction_SetCaptureKeys::pClassPointer = NULL;

//0x000010 (0x0000BC - 0x0000AC)
//GFxAction_SetVariable[0x10355CA0]
class UGFxAction_SetVariable : public USequenceAction
{
public:
	class UGFxMoviePlayer*                             Movie;                                            		// 0x0000AC (0x0004)              
	struct FString                                     Variable;                                         		// 0x0000B0 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxAction_SetVariable");
		return pClassPointer;
	};

public:
	bool IsValidLevelSequenceObject();//GFxUI.GFxAction_SetVariable.IsValidLevelSequenceObject
};
UClass* UGFxAction_SetVariable::pClassPointer = NULL;

//0x000014 (0x0000DC - 0x0000C8)
//GFxEvent_FSCommand[0x10355B70]
class UGFxEvent_FSCommand : public USequenceEvent
{
public:
	class USwfMovie*                                   Movie;                                            		// 0x0000C8 (0x0004)              
	struct FString                                     FSCommand;                                        		// 0x0000CC (0x000C)              
	class UGFxFSCmdHandler_Kismet*                     Handler;                                          		// 0x0000D8 (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxEvent_FSCommand");
		return pClassPointer;
	};
};
UClass* UGFxEvent_FSCommand::pClassPointer = NULL;

//0x000000 (0x000040 - 0x000040)
//GFxFSCmdHandler_Kismet[0x10355A40]
class UGFxFSCmdHandler_Kismet : public UGFxFSCmdHandler
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxFSCmdHandler_Kismet");
		return pClassPointer;
	};

public:
	bool FSCommand(class UGFxMoviePlayer* Movie,class UGFxEvent_FSCommand* Event,struct FString Cmd,struct FString Arg);//GFxUI.GFxFSCmdHandler_Kismet.FSCommand
};
UClass* UGFxFSCmdHandler_Kismet::pClassPointer = NULL;

//0x000008 (0x000048 - 0x000040)
//GFxDataStoreSubscriber[0x10355910]
class UGFxDataStoreSubscriber : public UObject
{
public:
	DWORD                                              VfTable_IUIDataStorePublisher;                    		// 0x000040 (0x0004)              
	class UGFxMoviePlayer*                             Movie;                                            		// 0x000044 (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class GFxUI.GFxDataStoreSubscriber");
		return pClassPointer;
	};

public:
	bool SaveSubscriberValue(TArray<class UUIDataStore*>* out_BoundDataStores,int BindingIndex);//GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue
	struct FString GetDataStoreBinding(int BindingIndex);//GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding
	void SetDataStoreBinding(struct FString MarkupText,int BindingIndex);//GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding
	void ClearBoundDataStores();//GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores
	void GetBoundDataStores(TArray<class UUIDataStore*>* out_BoundDataStores);//GFxUI.GFxDataStoreSubscriber.GetBoundDataStores
	void PublishValues();//GFxUI.GFxDataStoreSubscriber.PublishValues
	void NotifyDataStoreValueUpdated(class UUIDataStore* SourceDataStore,bool bValuesInvalidated,struct FName PropertyTag,class UUIDataProvider* SourceProvider,int ArrayIndex);//GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated
	bool RefreshSubscriberValue(int BindingIndex);//GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue
};
UClass* UGFxDataStoreSubscriber::pClassPointer = NULL;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif