
/*
-----------------------------------------------------------------
 - Classes
-----------------------------------------------------------------
*/
//0x000000 (0x000158 - 0x000158)
//AKAudioDevice[0x103557E0]
class UAKAudioDevice : public UAudioDevice
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class AKAudio.AKAudioDevice");
		return pClassPointer;
	};
};
UClass* UAKAudioDevice::pClassPointer = NULL;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif