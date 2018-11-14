
/*
-----------------------------------------------------------------
 - Classes
-----------------------------------------------------------------
*/
//0x000184 (0x0001D8 - 0x000054)
//WindowsClient[0x103556B0]
class UWindowsClient : public UClient
{
public:
	unsigned char                                      _0x000054[0x13C];                                 		// 0x000054 (0x013C) MISSED OFFSET
	class UClass*                                      AudioDeviceClass;                                 		// 0x000190 (0x0004)              
	unsigned char                                      _0x000194[0x2C];                                  		// 0x000194 (0x002C) MISSED OFFSET
	int                                                AllowJoystickInput;                               		// 0x0001C0 (0x0004)              
	unsigned char                                      _0x0001C4[0x14];                                  		// 0x0001C4 (0x0014) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class WinDrv.WindowsClient");
		return pClassPointer;
	};
};
UClass* UWindowsClient::pClassPointer = NULL;

//0x000000 (0x000054 - 0x000054)
//XnaForceFeedbackManager[0x10355580]
class UXnaForceFeedbackManager : public UForceFeedbackManager
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class WinDrv.XnaForceFeedbackManager");
		return pClassPointer;
	};
};
UClass* UXnaForceFeedbackManager::pClassPointer = NULL;

//0x000000 (0x0001D8 - 0x0001D8)
//WindowsVSClient[0x10355450]
class UWindowsVSClient : public UWindowsClient
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class WinDrv.WindowsVSClient");
		return pClassPointer;
	};
};
UClass* UWindowsVSClient::pClassPointer = NULL;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif