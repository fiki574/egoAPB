
struct Core_VInterpTo_Parms
{
	FVector3                                           Current;                                          		// 0x000000 (0x000C)              
	FVector3                                           Target;                                           		// 0x00000C (0x000C)              
	float                                              DeltaTime;                                        		// 0x000018 (0x0004)              
	float                                              InterpSpeed;                                      		// 0x00001C (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x000020 (0x000C)              
};

FVector3 UObject::VInterpTo(FVector3 Current,FVector3 Target,float DeltaTime,float InterpSpeed)
{
	static UFieldFunc* pFnVInterpTo = NULL;
	if(!pFnVInterpTo)
		pFnVInterpTo = UObject::FindFunction("Function Core.Object.VInterpTo");

	Core_VInterpTo_Parms VInterpTo_Parms;
	memcpy(&VInterpTo_Parms.Current,&Current,0xC);
	memcpy(&VInterpTo_Parms.Target,&Target,0xC);
	VInterpTo_Parms.DeltaTime = DeltaTime;
	VInterpTo_Parms.InterpSpeed = InterpSpeed;
	pFnVInterpTo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVInterpTo,NULL,&VInterpTo_Parms,NULL);
	pFnVInterpTo->FunctionFlags |= 0x400;
	return VInterpTo_Parms.ReturnValue;
}

struct Core_QuatSlerp_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	struct FQuat                                       B;                                                		// 0x000010 (0x0010)              
	float                                              Alpha;                                            		// 0x000020 (0x0004)              
	unsigned long                                      bShortestPath : 1;                                		// 0x000024 (0x0004) [0x00000001] 
	unsigned char                                      _0x000028[0x8];                                   		// 0x000028 (0x0008) MISSED OFFSET
	struct FQuat                                       ReturnValue;                                      		// 0x000030 (0x0010)              
};

struct FQuat UObject::QuatSlerp(struct FQuat A,struct FQuat B,float Alpha,bool bShortestPath)
{
	static UFieldFunc* pFnQuatSlerp = NULL;
	if(!pFnQuatSlerp)
		pFnQuatSlerp = UObject::FindFunction("Function Core.Object.QuatSlerp");

	Core_QuatSlerp_Parms QuatSlerp_Parms;
	memcpy(&QuatSlerp_Parms.A,&A,0x10);
	memcpy(&QuatSlerp_Parms.B,&B,0x10);
	QuatSlerp_Parms.Alpha = Alpha;
	QuatSlerp_Parms.bShortestPath = bShortestPath;
	pFnQuatSlerp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatSlerp,NULL,&QuatSlerp_Parms,NULL);
	pFnQuatSlerp->FunctionFlags |= 0x400;
	return QuatSlerp_Parms.ReturnValue;
}

struct Core_Divide_VectorFloat_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FVector3 UObject::Divide_VectorFloat(FVector3 A,float B)
{
	static UFieldFunc* pFnDivide_VectorFloat = NULL;
	if(!pFnDivide_VectorFloat)
		pFnDivide_VectorFloat = UObject::FindFunction("Function Core.Object.Divide_VectorFloat");

	Core_Divide_VectorFloat_Parms Divide_VectorFloat_Parms;
	memcpy(&Divide_VectorFloat_Parms.A,&A,0xC);
	Divide_VectorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivide_VectorFloat->iNative;
	pFnDivide_VectorFloat->iNative = 0;
	pFnDivide_VectorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivide_VectorFloat,NULL,&Divide_VectorFloat_Parms,NULL);
	pFnDivide_VectorFloat->FunctionFlags |= 0x400;
	pFnDivide_VectorFloat->iNative = NativeIndex;
	return Divide_VectorFloat_Parms.ReturnValue;
}

struct Core_LessLess_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::LessLess_IntInt(int A,int B)
{
	static UFieldFunc* pFnLessLess_IntInt = NULL;
	if(!pFnLessLess_IntInt)
		pFnLessLess_IntInt = UObject::FindFunction("Function Core.Object.LessLess_IntInt");

	Core_LessLess_IntInt_Parms LessLess_IntInt_Parms;
	LessLess_IntInt_Parms.A = A;
	LessLess_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnLessLess_IntInt->iNative;
	pFnLessLess_IntInt->iNative = 0;
	pFnLessLess_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLessLess_IntInt,NULL,&LessLess_IntInt_Parms,NULL);
	pFnLessLess_IntInt->FunctionFlags |= 0x400;
	pFnLessLess_IntInt->iNative = NativeIndex;
	return LessLess_IntInt_Parms.ReturnValue;
}

struct Core_MultiplyEqual_RotatorFloat_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FRotator                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FRotator UObject::MultiplyEqual_RotatorFloat(FRotator* A,float B)
{
	static UFieldFunc* pFnMultiplyEqual_RotatorFloat = NULL;
	if(!pFnMultiplyEqual_RotatorFloat)
		pFnMultiplyEqual_RotatorFloat = UObject::FindFunction("Function Core.Object.MultiplyEqual_RotatorFloat");

	Core_MultiplyEqual_RotatorFloat_Parms MultiplyEqual_RotatorFloat_Parms;
	MultiplyEqual_RotatorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_RotatorFloat->iNative;
	pFnMultiplyEqual_RotatorFloat->iNative = 0;
	pFnMultiplyEqual_RotatorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_RotatorFloat,NULL,&MultiplyEqual_RotatorFloat_Parms,NULL);
	pFnMultiplyEqual_RotatorFloat->FunctionFlags |= 0x400;
	pFnMultiplyEqual_RotatorFloat->iNative = NativeIndex;
	if(A)
		memcpy(A,&MultiplyEqual_RotatorFloat_Parms.A,0xC);
	return MultiplyEqual_RotatorFloat_Parms.ReturnValue;
}

struct Core_FInterpEaseIn_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              Alpha;                                            		// 0x000008 (0x0004)              
	float                                              Exp;                                              		// 0x00000C (0x0004)              
	float                                              ReturnValue;                                      		// 0x000010 (0x0004)              
};

float UObject::FInterpEaseIn(float A,float B,float Alpha,float Exp)
{
	static UFieldFunc* pFnFInterpEaseIn = NULL;
	if(!pFnFInterpEaseIn)
		pFnFInterpEaseIn = UObject::FindFunction("Function Core.Object.FInterpEaseIn");

	Core_FInterpEaseIn_Parms FInterpEaseIn_Parms;
	FInterpEaseIn_Parms.A = A;
	FInterpEaseIn_Parms.B = B;
	FInterpEaseIn_Parms.Alpha = Alpha;
	FInterpEaseIn_Parms.Exp = Exp;
	ProcessEvent(pFnFInterpEaseIn,NULL,&FInterpEaseIn_Parms,NULL);
	return FInterpEaseIn_Parms.ReturnValue;
}

struct Core_PushState_Parms
{
	struct FName                                       NewState;                                         		// 0x000000 (0x0008)              
	struct FName                                       NewLabel;                                         		// 0x000008 (0x0008)              
};

void UObject::PushState(struct FName NewState,struct FName NewLabel)
{
	static UFieldFunc* pFnPushState = NULL;
	if(!pFnPushState)
		pFnPushState = UObject::FindFunction("Function Core.Object.PushState");

	Core_PushState_Parms PushState_Parms;
	memcpy(&PushState_Parms.NewState,&NewState,0x8);
	memcpy(&PushState_Parms.NewLabel,&NewLabel,0x8);
	pFnPushState->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPushState,NULL,&PushState_Parms,NULL);
	pFnPushState->FunctionFlags |= 0x400;
}

struct Core_Divide_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::Divide_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnDivide_DoubleDouble = NULL;
	if(!pFnDivide_DoubleDouble)
		pFnDivide_DoubleDouble = UObject::FindFunction("Function Core.Object.Divide_DoubleDouble");

	Core_Divide_DoubleDouble_Parms Divide_DoubleDouble_Parms;
	Divide_DoubleDouble_Parms.A = A;
	Divide_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnDivide_DoubleDouble->iNative;
	pFnDivide_DoubleDouble->iNative = 0;
	pFnDivide_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivide_DoubleDouble,NULL,&Divide_DoubleDouble_Parms,NULL);
	pFnDivide_DoubleDouble->FunctionFlags |= 0x400;
	pFnDivide_DoubleDouble->iNative = NativeIndex;
	return Divide_DoubleDouble_Parms.ReturnValue;
}

struct Core_InverseTransformVector_Parms
{
	FMatrix                                            TM;                                               		// 0x000000 (0x0040)              
	FVector3                                           A;                                                		// 0x000040 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00004C (0x000C)              
};

FVector3 UObject::InverseTransformVector(FMatrix TM,FVector3 A)
{
	static UFieldFunc* pFnInverseTransformVector = NULL;
	if(!pFnInverseTransformVector)
		pFnInverseTransformVector = UObject::FindFunction("Function Core.Object.InverseTransformVector");

	Core_InverseTransformVector_Parms InverseTransformVector_Parms;
	memcpy(&InverseTransformVector_Parms.TM,&TM,0x40);
	memcpy(&InverseTransformVector_Parms.A,&A,0xC);
	pFnInverseTransformVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInverseTransformVector,NULL,&InverseTransformVector_Parms,NULL);
	pFnInverseTransformVector->FunctionFlags |= 0x400;
	return InverseTransformVector_Parms.ReturnValue;
}

struct Core_DSqrt_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DSqrt(double A)
{
	static UFieldFunc* pFnDSqrt = NULL;
	if(!pFnDSqrt)
		pFnDSqrt = UObject::FindFunction("Function Core.Object.DSqrt");

	Core_DSqrt_Parms DSqrt_Parms;
	DSqrt_Parms.A = A;

	unsigned short NativeIndex = pFnDSqrt->iNative;
	pFnDSqrt->iNative = 0;
	pFnDSqrt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDSqrt,NULL,&DSqrt_Parms,NULL);
	pFnDSqrt->FunctionFlags |= 0x400;
	pFnDSqrt->iNative = NativeIndex;
	return DSqrt_Parms.ReturnValue;
}

struct Core_WarnInternal_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
};

void UObject::WarnInternal(struct FString S)
{
	static UFieldFunc* pFnWarnInternal = NULL;
	if(!pFnWarnInternal)
		pFnWarnInternal = UObject::FindFunction("Function Core.Object.WarnInternal");

	Core_WarnInternal_Parms WarnInternal_Parms;
	memcpy(&WarnInternal_Parms.S,&S,0xC);

	unsigned short NativeIndex = pFnWarnInternal->iNative;
	pFnWarnInternal->iNative = 0;
	pFnWarnInternal->FunctionFlags |= ~0x400;
	ProcessEvent(pFnWarnInternal,NULL,&WarnInternal_Parms,NULL);
	pFnWarnInternal->FunctionFlags |= 0x400;
	pFnWarnInternal->iNative = NativeIndex;
}

struct Core_DCos_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DCos(double A)
{
	static UFieldFunc* pFnDCos = NULL;
	if(!pFnDCos)
		pFnDCos = UObject::FindFunction("Function Core.Object.DCos");

	Core_DCos_Parms DCos_Parms;
	DCos_Parms.A = A;

	unsigned short NativeIndex = pFnDCos->iNative;
	pFnDCos->iNative = 0;
	pFnDCos->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDCos,NULL,&DCos_Parms,NULL);
	pFnDCos->FunctionFlags |= 0x400;
	pFnDCos->iNative = NativeIndex;
	return DCos_Parms.ReturnValue;
}

struct Core_MirrorVectorByNormal_Parms
{
	FVector3                                           InVect;                                           		// 0x000000 (0x000C)              
	FVector3                                           InNormal;                                         		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::MirrorVectorByNormal(FVector3 InVect,FVector3 InNormal)
{
	static UFieldFunc* pFnMirrorVectorByNormal = NULL;
	if(!pFnMirrorVectorByNormal)
		pFnMirrorVectorByNormal = UObject::FindFunction("Function Core.Object.MirrorVectorByNormal");

	Core_MirrorVectorByNormal_Parms MirrorVectorByNormal_Parms;
	memcpy(&MirrorVectorByNormal_Parms.InVect,&InVect,0xC);
	memcpy(&MirrorVectorByNormal_Parms.InNormal,&InNormal,0xC);

	unsigned short NativeIndex = pFnMirrorVectorByNormal->iNative;
	pFnMirrorVectorByNormal->iNative = 0;
	pFnMirrorVectorByNormal->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMirrorVectorByNormal,NULL,&MirrorVectorByNormal_Parms,NULL);
	pFnMirrorVectorByNormal->FunctionFlags |= 0x400;
	pFnMirrorVectorByNormal->iNative = NativeIndex;
	return MirrorVectorByNormal_Parms.ReturnValue;
}

struct Core_GetHeadingAngle_Parms
{
	FVector3                                           Dir;                                              		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
	//float                                              Angle;                                            		// 0x000010 (0x0004)              
};

float UObject::GetHeadingAngle(FVector3 Dir)
{
	static UFieldFunc* pFnGetHeadingAngle = NULL;
	if(!pFnGetHeadingAngle)
		pFnGetHeadingAngle = UObject::FindFunction("Function Core.Object.GetHeadingAngle");

	Core_GetHeadingAngle_Parms GetHeadingAngle_Parms;
	memcpy(&GetHeadingAngle_Parms.Dir,&Dir,0xC);
	ProcessEvent(pFnGetHeadingAngle,NULL,&GetHeadingAngle_Parms,NULL);
	return GetHeadingAngle_Parms.ReturnValue;
}

struct Core_QuatInvert_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	struct FQuat                                       ReturnValue;                                      		// 0x000010 (0x0010)              
};

struct FQuat UObject::QuatInvert(struct FQuat A)
{
	static UFieldFunc* pFnQuatInvert = NULL;
	if(!pFnQuatInvert)
		pFnQuatInvert = UObject::FindFunction("Function Core.Object.QuatInvert");

	Core_QuatInvert_Parms QuatInvert_Parms;
	memcpy(&QuatInvert_Parms.A,&A,0x10);
	pFnQuatInvert->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatInvert,NULL,&QuatInvert_Parms,NULL);
	pFnQuatInvert->FunctionFlags |= 0x400;
	return QuatInvert_Parms.ReturnValue;
}

struct Core_MultiplyEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::MultiplyEqual_FloatFloat(float* A,float B)
{
	static UFieldFunc* pFnMultiplyEqual_FloatFloat = NULL;
	if(!pFnMultiplyEqual_FloatFloat)
		pFnMultiplyEqual_FloatFloat = UObject::FindFunction("Function Core.Object.MultiplyEqual_FloatFloat");

	Core_MultiplyEqual_FloatFloat_Parms MultiplyEqual_FloatFloat_Parms;
	MultiplyEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_FloatFloat->iNative;
	pFnMultiplyEqual_FloatFloat->iNative = 0;
	pFnMultiplyEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_FloatFloat,NULL,&MultiplyEqual_FloatFloat_Parms,NULL);
	pFnMultiplyEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnMultiplyEqual_FloatFloat->iNative = NativeIndex;
	if(A)
		*A = MultiplyEqual_FloatFloat_Parms.A;
	return MultiplyEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_Concat_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UObject::Concat_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnConcat_StrStr = NULL;
	if(!pFnConcat_StrStr)
		pFnConcat_StrStr = UObject::FindFunction("Function Core.Object.Concat_StrStr");

	Core_Concat_StrStr_Parms Concat_StrStr_Parms;
	memcpy(&Concat_StrStr_Parms.A,&A,0xC);
	memcpy(&Concat_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnConcat_StrStr->iNative;
	pFnConcat_StrStr->iNative = 0;
	pFnConcat_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnConcat_StrStr,NULL,&Concat_StrStr_Parms,NULL);
	pFnConcat_StrStr->FunctionFlags |= 0x400;
	pFnConcat_StrStr->iNative = NativeIndex;
	return Concat_StrStr_Parms.ReturnValue;
}

struct Core_PathName_Parms
{
	class UObject*                                     CheckObject;                                      		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UObject::PathName(class UObject* CheckObject)
{
	static UFieldFunc* pFnPathName = NULL;
	if(!pFnPathName)
		pFnPathName = UObject::FindFunction("Function Core.Object.PathName");

	Core_PathName_Parms PathName_Parms;
	PathName_Parms.CheckObject = CheckObject;
	pFnPathName->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPathName,NULL,&PathName_Parms,NULL);
	pFnPathName->FunctionFlags |= 0x400;
	return PathName_Parms.ReturnValue;
}

struct Core_Right_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	int                                                I;                                                		// 0x00000C (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000010 (0x000C)              
};

struct FString UObject::Right(struct FString S,int I)
{
	static UFieldFunc* pFnRight = NULL;
	if(!pFnRight)
		pFnRight = UObject::FindFunction("Function Core.Object.Right");

	Core_Right_Parms Right_Parms;
	memcpy(&Right_Parms.S,&S,0xC);
	Right_Parms.I = I;

	unsigned short NativeIndex = pFnRight->iNative;
	pFnRight->iNative = 0;
	pFnRight->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRight,NULL,&Right_Parms,NULL);
	pFnRight->FunctionFlags |= 0x400;
	pFnRight->iNative = NativeIndex;
	return Right_Parms.ReturnValue;
}

struct Core_GetAngularFromDotDist_Parms
{
	FVector2                                           OutAngDist;                                       		// 0x000000 (0x0008)              
	FVector2                                           DotDist;                                          		// 0x000008 (0x0008)              
};

void UObject::GetAngularFromDotDist(FVector2* OutAngDist,FVector2 DotDist)
{
	static UFieldFunc* pFnGetAngularFromDotDist = NULL;
	if(!pFnGetAngularFromDotDist)
		pFnGetAngularFromDotDist = UObject::FindFunction("Function Core.Object.GetAngularFromDotDist");

	Core_GetAngularFromDotDist_Parms GetAngularFromDotDist_Parms;
	memcpy(&GetAngularFromDotDist_Parms.DotDist,&DotDist,0x8);
	pFnGetAngularFromDotDist->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetAngularFromDotDist,NULL,&GetAngularFromDotDist_Parms,NULL);
	pFnGetAngularFromDotDist->FunctionFlags |= 0x400;
	if(OutAngDist)
		memcpy(OutAngDist,&GetAngularFromDotDist_Parms.OutAngDist,0x8);
}

struct Core_SaveConfig_Parms
{
};

void UObject::SaveConfig()
{
	static UFieldFunc* pFnSaveConfig = NULL;
	if(!pFnSaveConfig)
		pFnSaveConfig = UObject::FindFunction("Function Core.Object.SaveConfig");

	Core_SaveConfig_Parms SaveConfig_Parms;

	unsigned short NativeIndex = pFnSaveConfig->iNative;
	pFnSaveConfig->iNative = 0;
	pFnSaveConfig->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSaveConfig,NULL,&SaveConfig_Parms,NULL);
	pFnSaveConfig->FunctionFlags |= 0x400;
	pFnSaveConfig->iNative = NativeIndex;
}

struct Core_MultiplyEqual_IntFloat_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::MultiplyEqual_IntFloat(int* A,float B)
{
	static UFieldFunc* pFnMultiplyEqual_IntFloat = NULL;
	if(!pFnMultiplyEqual_IntFloat)
		pFnMultiplyEqual_IntFloat = UObject::FindFunction("Function Core.Object.MultiplyEqual_IntFloat");

	Core_MultiplyEqual_IntFloat_Parms MultiplyEqual_IntFloat_Parms;
	MultiplyEqual_IntFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_IntFloat->iNative;
	pFnMultiplyEqual_IntFloat->iNative = 0;
	pFnMultiplyEqual_IntFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_IntFloat,NULL,&MultiplyEqual_IntFloat_Parms,NULL);
	pFnMultiplyEqual_IntFloat->FunctionFlags |= 0x400;
	pFnMultiplyEqual_IntFloat->iNative = NativeIndex;
	if(A)
		*A = MultiplyEqual_IntFloat_Parms.A;
	return MultiplyEqual_IntFloat_Parms.ReturnValue;
}

struct Core_FMin_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::FMin(float A,float B)
{
	static UFieldFunc* pFnFMin = NULL;
	if(!pFnFMin)
		pFnFMin = UObject::FindFunction("Function Core.Object.FMin");

	Core_FMin_Parms FMin_Parms;
	FMin_Parms.A = A;
	FMin_Parms.B = B;

	unsigned short NativeIndex = pFnFMin->iNative;
	pFnFMin->iNative = 0;
	pFnFMin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFMin,NULL,&FMin_Parms,NULL);
	pFnFMin->FunctionFlags |= 0x400;
	pFnFMin->iNative = NativeIndex;
	return FMin_Parms.ReturnValue;
}

struct Core_DAbs_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DAbs(double A)
{
	static UFieldFunc* pFnDAbs = NULL;
	if(!pFnDAbs)
		pFnDAbs = UObject::FindFunction("Function Core.Object.DAbs");

	Core_DAbs_Parms DAbs_Parms;
	DAbs_Parms.A = A;

	unsigned short NativeIndex = pFnDAbs->iNative;
	pFnDAbs->iNative = 0;
	pFnDAbs->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDAbs,NULL,&DAbs_Parms,NULL);
	pFnDAbs->FunctionFlags |= 0x400;
	pFnDAbs->iNative = NativeIndex;
	return DAbs_Parms.ReturnValue;
}

struct Core_DTan_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DTan(double A)
{
	static UFieldFunc* pFnDTan = NULL;
	if(!pFnDTan)
		pFnDTan = UObject::FindFunction("Function Core.Object.DTan");

	Core_DTan_Parms DTan_Parms;
	DTan_Parms.A = A;

	unsigned short NativeIndex = pFnDTan->iNative;
	pFnDTan->iNative = 0;
	pFnDTan->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDTan,NULL,&DTan_Parms,NULL);
	pFnDTan->FunctionFlags |= 0x400;
	pFnDTan->iNative = NativeIndex;
	return DTan_Parms.ReturnValue;
}

struct Core_SetUTracing_Parms
{
	unsigned long                                      bShouldUTrace : 1;                                		// 0x000000 (0x0004) [0x00000001] 
};

void UObject::SetUTracing(bool bShouldUTrace)
{
	static UFieldFunc* pFnSetUTracing = NULL;
	if(!pFnSetUTracing)
		pFnSetUTracing = UObject::FindFunction("Function Core.Object.SetUTracing");

	Core_SetUTracing_Parms SetUTracing_Parms;
	SetUTracing_Parms.bShouldUTrace = bShouldUTrace;
	pFnSetUTracing->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetUTracing,NULL,&SetUTracing_Parms,NULL);
	pFnSetUTracing->FunctionFlags |= 0x400;
}

struct Core_DAsin_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DAsin(double A)
{
	static UFieldFunc* pFnDAsin = NULL;
	if(!pFnDAsin)
		pFnDAsin = UObject::FindFunction("Function Core.Object.DAsin");

	Core_DAsin_Parms DAsin_Parms;
	DAsin_Parms.A = A;
	pFnDAsin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDAsin,NULL,&DAsin_Parms,NULL);
	pFnDAsin->FunctionFlags |= 0x400;
	return DAsin_Parms.ReturnValue;
}

struct Core_EqualEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnEqualEqual_DoubleDouble = NULL;
	if(!pFnEqualEqual_DoubleDouble)
		pFnEqualEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.EqualEqual_DoubleDouble");

	Core_EqualEqual_DoubleDouble_Parms EqualEqual_DoubleDouble_Parms;
	EqualEqual_DoubleDouble_Parms.A = A;
	EqualEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnEqualEqual_DoubleDouble->iNative;
	pFnEqualEqual_DoubleDouble->iNative = 0;
	pFnEqualEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_DoubleDouble,NULL,&EqualEqual_DoubleDouble_Parms,NULL);
	pFnEqualEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnEqualEqual_DoubleDouble->iNative = NativeIndex;
	return EqualEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_GetRangeValueByPct_Parms
{
	FVector2                                           Range;                                            		// 0x000000 (0x0008)              
	float                                              Pct;                                              		// 0x000008 (0x0004)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::GetRangeValueByPct(FVector2 Range,float Pct)
{
	static UFieldFunc* pFnGetRangeValueByPct = NULL;
	if(!pFnGetRangeValueByPct)
		pFnGetRangeValueByPct = UObject::FindFunction("Function Core.Object.GetRangeValueByPct");

	Core_GetRangeValueByPct_Parms GetRangeValueByPct_Parms;
	memcpy(&GetRangeValueByPct_Parms.Range,&Range,0x8);
	GetRangeValueByPct_Parms.Pct = Pct;
	ProcessEvent(pFnGetRangeValueByPct,NULL,&GetRangeValueByPct_Parms,NULL);
	return GetRangeValueByPct_Parms.ReturnValue;
}

struct Core_LessEqual_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::LessEqual_IntInt(int A,int B)
{
	static UFieldFunc* pFnLessEqual_IntInt = NULL;
	if(!pFnLessEqual_IntInt)
		pFnLessEqual_IntInt = UObject::FindFunction("Function Core.Object.LessEqual_IntInt");

	Core_LessEqual_IntInt_Parms LessEqual_IntInt_Parms;
	LessEqual_IntInt_Parms.A = A;
	LessEqual_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnLessEqual_IntInt->iNative;
	pFnLessEqual_IntInt->iNative = 0;
	pFnLessEqual_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLessEqual_IntInt,NULL,&LessEqual_IntInt_Parms,NULL);
	pFnLessEqual_IntInt->FunctionFlags |= 0x400;
	pFnLessEqual_IntInt->iNative = NativeIndex;
	return LessEqual_IntInt_Parms.ReturnValue;
}

struct Core_DMax_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::DMax(double A,double B)
{
	static UFieldFunc* pFnDMax = NULL;
	if(!pFnDMax)
		pFnDMax = UObject::FindFunction("Function Core.Object.DMax");

	Core_DMax_Parms DMax_Parms;
	DMax_Parms.A = A;
	DMax_Parms.B = B;

	unsigned short NativeIndex = pFnDMax->iNative;
	pFnDMax->iNative = 0;
	pFnDMax->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDMax,NULL,&DMax_Parms,NULL);
	pFnDMax->FunctionFlags |= 0x400;
	pFnDMax->iNative = NativeIndex;
	return DMax_Parms.ReturnValue;
}

struct Core_And_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::And_IntInt(int A,int B)
{
	static UFieldFunc* pFnAnd_IntInt = NULL;
	if(!pFnAnd_IntInt)
		pFnAnd_IntInt = UObject::FindFunction("Function Core.Object.And_IntInt");

	Core_And_IntInt_Parms And_IntInt_Parms;
	And_IntInt_Parms.A = A;
	And_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnAnd_IntInt->iNative;
	pFnAnd_IntInt->iNative = 0;
	pFnAnd_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAnd_IntInt,NULL,&And_IntInt_Parms,NULL);
	pFnAnd_IntInt->FunctionFlags |= 0x400;
	pFnAnd_IntInt->iNative = NativeIndex;
	return And_IntInt_Parms.ReturnValue;
}

struct Core_Less_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::Less_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnLess_DoubleDouble = NULL;
	if(!pFnLess_DoubleDouble)
		pFnLess_DoubleDouble = UObject::FindFunction("Function Core.Object.Less_DoubleDouble");

	Core_Less_DoubleDouble_Parms Less_DoubleDouble_Parms;
	Less_DoubleDouble_Parms.A = A;
	Less_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnLess_DoubleDouble->iNative;
	pFnLess_DoubleDouble->iNative = 0;
	pFnLess_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLess_DoubleDouble,NULL,&Less_DoubleDouble_Parms,NULL);
	pFnLess_DoubleDouble->FunctionFlags |= 0x400;
	pFnLess_DoubleDouble->iNative = NativeIndex;
	return Less_DoubleDouble_Parms.ReturnValue;
}

struct Core_VLerp_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	float                                              Alpha;                                            		// 0x000018 (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x00001C (0x000C)              
};

FVector3 UObject::VLerp(FVector3 A,FVector3 B,float Alpha)
{
	static UFieldFunc* pFnVLerp = NULL;
	if(!pFnVLerp)
		pFnVLerp = UObject::FindFunction("Function Core.Object.VLerp");

	Core_VLerp_Parms VLerp_Parms;
	memcpy(&VLerp_Parms.A,&A,0xC);
	memcpy(&VLerp_Parms.B,&B,0xC);
	VLerp_Parms.Alpha = Alpha;
	pFnVLerp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVLerp,NULL,&VLerp_Parms,NULL);
	pFnVLerp->FunctionFlags |= 0x400;
	return VLerp_Parms.ReturnValue;
}

struct Core_FCubicInterp_Parms
{
	float                                              P0;                                               		// 0x000000 (0x0004)              
	float                                              T0;                                               		// 0x000004 (0x0004)              
	float                                              P1;                                               		// 0x000008 (0x0004)              
	float                                              T1;                                               		// 0x00000C (0x0004)              
	float                                              A;                                                		// 0x000010 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000014 (0x0004)              
};

float UObject::FCubicInterp(float P0,float T0,float P1,float T1,float A)
{
	static UFieldFunc* pFnFCubicInterp = NULL;
	if(!pFnFCubicInterp)
		pFnFCubicInterp = UObject::FindFunction("Function Core.Object.FCubicInterp");

	Core_FCubicInterp_Parms FCubicInterp_Parms;
	FCubicInterp_Parms.P0 = P0;
	FCubicInterp_Parms.T0 = T0;
	FCubicInterp_Parms.P1 = P1;
	FCubicInterp_Parms.T1 = T1;
	FCubicInterp_Parms.A = A;
	pFnFCubicInterp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFCubicInterp,NULL,&FCubicInterp_Parms,NULL);
	pFnFCubicInterp->FunctionFlags |= 0x400;
	return FCubicInterp_Parms.ReturnValue;
}

struct Core_AddAdd_PreByte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000001 (0x0001)              
};

unsigned char UObject::AddAdd_PreByte(unsigned char* A)
{
	static UFieldFunc* pFnAddAdd_PreByte = NULL;
	if(!pFnAddAdd_PreByte)
		pFnAddAdd_PreByte = UObject::FindFunction("Function Core.Object.AddAdd_PreByte");

	Core_AddAdd_PreByte_Parms AddAdd_PreByte_Parms;

	unsigned short NativeIndex = pFnAddAdd_PreByte->iNative;
	pFnAddAdd_PreByte->iNative = 0;
	pFnAddAdd_PreByte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddAdd_PreByte,NULL,&AddAdd_PreByte_Parms,NULL);
	pFnAddAdd_PreByte->FunctionFlags |= 0x400;
	pFnAddAdd_PreByte->iNative = NativeIndex;
	if(A)
		*A = AddAdd_PreByte_Parms.A;
	return AddAdd_PreByte_Parms.ReturnValue;
}

struct Core_PointDistToLine_Parms
{
	FVector3                                           Point;                                            		// 0x000000 (0x000C)              
	FVector3                                           Line;                                             		// 0x00000C (0x000C)              
	FVector3                                           Origin;                                           		// 0x000018 (0x000C)              
	FVector3                                           OutClosestPoint;                                  		// 0x000024 (0x000C)              
	float                                              ReturnValue;                                      		// 0x000030 (0x0004)              
};

float UObject::PointDistToLine(FVector3 Point,FVector3 Line,FVector3 Origin,FVector3* OutClosestPoint)
{
	static UFieldFunc* pFnPointDistToLine = NULL;
	if(!pFnPointDistToLine)
		pFnPointDistToLine = UObject::FindFunction("Function Core.Object.PointDistToLine");

	Core_PointDistToLine_Parms PointDistToLine_Parms;
	memcpy(&PointDistToLine_Parms.Point,&Point,0xC);
	memcpy(&PointDistToLine_Parms.Line,&Line,0xC);
	memcpy(&PointDistToLine_Parms.Origin,&Origin,0xC);
	pFnPointDistToLine->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPointDistToLine,NULL,&PointDistToLine_Parms,NULL);
	pFnPointDistToLine->FunctionFlags |= 0x400;
	if(OutClosestPoint)
		memcpy(OutClosestPoint,&PointDistToLine_Parms.OutClosestPoint,0xC);
	return PointDistToLine_Parms.ReturnValue;
}

struct Core_ConcatEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UObject::ConcatEqual_StrStr(struct FString* A,struct FString B)
{
	static UFieldFunc* pFnConcatEqual_StrStr = NULL;
	if(!pFnConcatEqual_StrStr)
		pFnConcatEqual_StrStr = UObject::FindFunction("Function Core.Object.ConcatEqual_StrStr");

	Core_ConcatEqual_StrStr_Parms ConcatEqual_StrStr_Parms;
	memcpy(&ConcatEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnConcatEqual_StrStr->iNative;
	pFnConcatEqual_StrStr->iNative = 0;
	pFnConcatEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnConcatEqual_StrStr,NULL,&ConcatEqual_StrStr_Parms,NULL);
	pFnConcatEqual_StrStr->FunctionFlags |= 0x400;
	pFnConcatEqual_StrStr->iNative = NativeIndex;
	if(A)
		memcpy(A,&ConcatEqual_StrStr_Parms.A,0xC);
	return ConcatEqual_StrStr_Parms.ReturnValue;
}

struct Core_ClockwiseFrom_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::ClockwiseFrom_IntInt(int A,int B)
{
	static UFieldFunc* pFnClockwiseFrom_IntInt = NULL;
	if(!pFnClockwiseFrom_IntInt)
		pFnClockwiseFrom_IntInt = UObject::FindFunction("Function Core.Object.ClockwiseFrom_IntInt");

	Core_ClockwiseFrom_IntInt_Parms ClockwiseFrom_IntInt_Parms;
	ClockwiseFrom_IntInt_Parms.A = A;
	ClockwiseFrom_IntInt_Parms.B = B;
	pFnClockwiseFrom_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClockwiseFrom_IntInt,NULL,&ClockwiseFrom_IntInt_Parms,NULL);
	pFnClockwiseFrom_IntInt->FunctionFlags |= 0x400;
	return ClockwiseFrom_IntInt_Parms.ReturnValue;
}

struct Core_EqualEqual_InterfaceInterface_Parms
{
	class UInterface*                                  A;                                                		// 0x000000 (0x0008)              
	class UInterface*                                  B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_InterfaceInterface(class UInterface* A,class UInterface* B)
{
	static UFieldFunc* pFnEqualEqual_InterfaceInterface = NULL;
	if(!pFnEqualEqual_InterfaceInterface)
		pFnEqualEqual_InterfaceInterface = UObject::FindFunction("Function Core.Object.EqualEqual_InterfaceInterface");

	Core_EqualEqual_InterfaceInterface_Parms EqualEqual_InterfaceInterface_Parms;
	EqualEqual_InterfaceInterface_Parms.A = A;
	EqualEqual_InterfaceInterface_Parms.B = B;
	pFnEqualEqual_InterfaceInterface->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_InterfaceInterface,NULL,&EqualEqual_InterfaceInterface_Parms,NULL);
	pFnEqualEqual_InterfaceInterface->FunctionFlags |= 0x400;
	return EqualEqual_InterfaceInterface_Parms.ReturnValue;
}

struct Core_QuatFindBetween_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	unsigned char                                      _0x000018[0x8];                                   		// 0x000018 (0x0008) MISSED OFFSET
	struct FQuat                                       ReturnValue;                                      		// 0x000020 (0x0010)              
};

struct FQuat UObject::QuatFindBetween(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnQuatFindBetween = NULL;
	if(!pFnQuatFindBetween)
		pFnQuatFindBetween = UObject::FindFunction("Function Core.Object.QuatFindBetween");

	Core_QuatFindBetween_Parms QuatFindBetween_Parms;
	memcpy(&QuatFindBetween_Parms.A,&A,0xC);
	memcpy(&QuatFindBetween_Parms.B,&B,0xC);
	pFnQuatFindBetween->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatFindBetween,NULL,&QuatFindBetween_Parms,NULL);
	pFnQuatFindBetween->FunctionFlags |= 0x400;
	return QuatFindBetween_Parms.ReturnValue;
}

struct Core_RLerp_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	float                                              Alpha;                                            		// 0x000018 (0x0004)              
	unsigned long                                      bShortestPath : 1;                                		// 0x00001C (0x0004) [0x00000001] 
	FRotator                                           ReturnValue;                                      		// 0x000020 (0x000C)              
};

FRotator UObject::RLerp(FRotator A,FRotator B,float Alpha,bool bShortestPath)
{
	static UFieldFunc* pFnRLerp = NULL;
	if(!pFnRLerp)
		pFnRLerp = UObject::FindFunction("Function Core.Object.RLerp");

	Core_RLerp_Parms RLerp_Parms;
	memcpy(&RLerp_Parms.A,&A,0xC);
	memcpy(&RLerp_Parms.B,&B,0xC);
	RLerp_Parms.Alpha = Alpha;
	RLerp_Parms.bShortestPath = bShortestPath;
	pFnRLerp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRLerp,NULL,&RLerp_Parms,NULL);
	pFnRLerp->FunctionFlags |= 0x400;
	return RLerp_Parms.ReturnValue;
}

struct Core_AddEqual_RotatorRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FRotator UObject::AddEqual_RotatorRotator(FRotator* A,FRotator B)
{
	static UFieldFunc* pFnAddEqual_RotatorRotator = NULL;
	if(!pFnAddEqual_RotatorRotator)
		pFnAddEqual_RotatorRotator = UObject::FindFunction("Function Core.Object.AddEqual_RotatorRotator");

	Core_AddEqual_RotatorRotator_Parms AddEqual_RotatorRotator_Parms;
	memcpy(&AddEqual_RotatorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnAddEqual_RotatorRotator->iNative;
	pFnAddEqual_RotatorRotator->iNative = 0;
	pFnAddEqual_RotatorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddEqual_RotatorRotator,NULL,&AddEqual_RotatorRotator_Parms,NULL);
	pFnAddEqual_RotatorRotator->FunctionFlags |= 0x400;
	pFnAddEqual_RotatorRotator->iNative = NativeIndex;
	if(A)
		memcpy(A,&AddEqual_RotatorRotator_Parms.A,0xC);
	return AddEqual_RotatorRotator_Parms.ReturnValue;
}

struct Core_FMax_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::FMax(float A,float B)
{
	static UFieldFunc* pFnFMax = NULL;
	if(!pFnFMax)
		pFnFMax = UObject::FindFunction("Function Core.Object.FMax");

	Core_FMax_Parms FMax_Parms;
	FMax_Parms.A = A;
	FMax_Parms.B = B;

	unsigned short NativeIndex = pFnFMax->iNative;
	pFnFMax->iNative = 0;
	pFnFMax->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFMax,NULL,&FMax_Parms,NULL);
	pFnFMax->FunctionFlags |= 0x400;
	pFnFMax->iNative = NativeIndex;
	return FMax_Parms.ReturnValue;
}

struct Core_LessEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::LessEqual_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnLessEqual_StrStr = NULL;
	if(!pFnLessEqual_StrStr)
		pFnLessEqual_StrStr = UObject::FindFunction("Function Core.Object.LessEqual_StrStr");

	Core_LessEqual_StrStr_Parms LessEqual_StrStr_Parms;
	memcpy(&LessEqual_StrStr_Parms.A,&A,0xC);
	memcpy(&LessEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnLessEqual_StrStr->iNative;
	pFnLessEqual_StrStr->iNative = 0;
	pFnLessEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLessEqual_StrStr,NULL,&LessEqual_StrStr_Parms,NULL);
	pFnLessEqual_StrStr->FunctionFlags |= 0x400;
	pFnLessEqual_StrStr->iNative = NativeIndex;
	return LessEqual_StrStr_Parms.ReturnValue;
}

struct Core_MakeColor_Parms
{
	unsigned char                                      R;                                                		// 0x000000 (0x0001)              
	unsigned char                                      G;                                                		// 0x000001 (0x0001)              
	unsigned char                                      B;                                                		// 0x000002 (0x0001)              
	unsigned char                                      A;                                                		// 0x000003 (0x0001)              
	DWORD                                              ReturnValue;                                      		// 0x000004 (0x0004)              
	//DWORD                                              C;                                                		// 0x000008 (0x0004)              
};

DWORD UObject::MakeColor(unsigned char R,unsigned char G,unsigned char B,unsigned char A)
{
	static UFieldFunc* pFnMakeColor = NULL;
	if(!pFnMakeColor)
		pFnMakeColor = UObject::FindFunction("Function Core.Object.MakeColor");

	Core_MakeColor_Parms MakeColor_Parms;
	MakeColor_Parms.R = R;
	MakeColor_Parms.G = G;
	MakeColor_Parms.B = B;
	MakeColor_Parms.A = A;
	ProcessEvent(pFnMakeColor,NULL,&MakeColor_Parms,NULL);
	return MakeColor_Parms.ReturnValue;
}

struct Core_Localize_Parms
{
	struct FString                                     SectionName;                                      		// 0x000000 (0x000C)              
	struct FString                                     KeyName;                                          		// 0x00000C (0x000C)              
	struct FString                                     PackageName;                                      		// 0x000018 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000024 (0x000C)              
};

struct FString UObject::Localize(struct FString SectionName,struct FString KeyName,struct FString PackageName)
{
	static UFieldFunc* pFnLocalize = NULL;
	if(!pFnLocalize)
		pFnLocalize = UObject::FindFunction("Function Core.Object.Localize");

	Core_Localize_Parms Localize_Parms;
	memcpy(&Localize_Parms.SectionName,&SectionName,0xC);
	memcpy(&Localize_Parms.KeyName,&KeyName,0xC);
	memcpy(&Localize_Parms.PackageName,&PackageName,0xC);
	pFnLocalize->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLocalize,NULL,&Localize_Parms,NULL);
	pFnLocalize->FunctionFlags |= 0x400;
	return Localize_Parms.ReturnValue;
}

struct Core_DivideEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::DivideEqual_FloatFloat(float* A,float B)
{
	static UFieldFunc* pFnDivideEqual_FloatFloat = NULL;
	if(!pFnDivideEqual_FloatFloat)
		pFnDivideEqual_FloatFloat = UObject::FindFunction("Function Core.Object.DivideEqual_FloatFloat");

	Core_DivideEqual_FloatFloat_Parms DivideEqual_FloatFloat_Parms;
	DivideEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivideEqual_FloatFloat->iNative;
	pFnDivideEqual_FloatFloat->iNative = 0;
	pFnDivideEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivideEqual_FloatFloat,NULL,&DivideEqual_FloatFloat_Parms,NULL);
	pFnDivideEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnDivideEqual_FloatFloat->iNative = NativeIndex;
	if(A)
		*A = DivideEqual_FloatFloat_Parms.A;
	return DivideEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_Not_PreBool_Parms
{
	unsigned long                                      A : 1;                                            		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000004 (0x0004) [0x00000001] 
};

bool UObject::Not_PreBool(bool A)
{
	static UFieldFunc* pFnNot_PreBool = NULL;
	if(!pFnNot_PreBool)
		pFnNot_PreBool = UObject::FindFunction("Function Core.Object.Not_PreBool");

	Core_Not_PreBool_Parms Not_PreBool_Parms;
	Not_PreBool_Parms.A = A;

	unsigned short NativeIndex = pFnNot_PreBool->iNative;
	pFnNot_PreBool->iNative = 0;
	pFnNot_PreBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNot_PreBool,NULL,&Not_PreBool_Parms,NULL);
	pFnNot_PreBool->FunctionFlags |= 0x400;
	pFnNot_PreBool->iNative = NativeIndex;
	return Not_PreBool_Parms.ReturnValue;
}

struct Core_InverseTransformNormal_Parms
{
	FMatrix                                            TM;                                               		// 0x000000 (0x0040)              
	FVector3                                           A;                                                		// 0x000040 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00004C (0x000C)              
};

FVector3 UObject::InverseTransformNormal(FMatrix TM,FVector3 A)
{
	static UFieldFunc* pFnInverseTransformNormal = NULL;
	if(!pFnInverseTransformNormal)
		pFnInverseTransformNormal = UObject::FindFunction("Function Core.Object.InverseTransformNormal");

	Core_InverseTransformNormal_Parms InverseTransformNormal_Parms;
	memcpy(&InverseTransformNormal_Parms.TM,&TM,0x40);
	memcpy(&InverseTransformNormal_Parms.A,&A,0xC);
	pFnInverseTransformNormal->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInverseTransformNormal,NULL,&InverseTransformNormal_Parms,NULL);
	pFnInverseTransformNormal->FunctionFlags |= 0x400;
	return InverseTransformNormal_Parms.ReturnValue;
}

struct Core_IsUTracing_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UObject::IsUTracing()
{
	static UFieldFunc* pFnIsUTracing = NULL;
	if(!pFnIsUTracing)
		pFnIsUTracing = UObject::FindFunction("Function Core.Object.IsUTracing");

	Core_IsUTracing_Parms IsUTracing_Parms;
	pFnIsUTracing->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsUTracing,NULL,&IsUTracing_Parms,NULL);
	pFnIsUTracing->FunctionFlags |= 0x400;
	return IsUTracing_Parms.ReturnValue;
}

struct Core_ComplementEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::ComplementEqual_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnComplementEqual_FloatFloat = NULL;
	if(!pFnComplementEqual_FloatFloat)
		pFnComplementEqual_FloatFloat = UObject::FindFunction("Function Core.Object.ComplementEqual_FloatFloat");

	Core_ComplementEqual_FloatFloat_Parms ComplementEqual_FloatFloat_Parms;
	ComplementEqual_FloatFloat_Parms.A = A;
	ComplementEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnComplementEqual_FloatFloat->iNative;
	pFnComplementEqual_FloatFloat->iNative = 0;
	pFnComplementEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnComplementEqual_FloatFloat,NULL,&ComplementEqual_FloatFloat_Parms,NULL);
	pFnComplementEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnComplementEqual_FloatFloat->iNative = NativeIndex;
	return ComplementEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_Tan_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Tan(float A)
{
	static UFieldFunc* pFnTan = NULL;
	if(!pFnTan)
		pFnTan = UObject::FindFunction("Function Core.Object.Tan");

	Core_Tan_Parms Tan_Parms;
	Tan_Parms.A = A;

	unsigned short NativeIndex = pFnTan->iNative;
	pFnTan->iNative = 0;
	pFnTan->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTan,NULL,&Tan_Parms,NULL);
	pFnTan->FunctionFlags |= 0x400;
	pFnTan->iNative = NativeIndex;
	return Tan_Parms.ReturnValue;
}

struct Core_LessLess_VectorRotator_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::LessLess_VectorRotator(FVector3 A,FRotator B)
{
	static UFieldFunc* pFnLessLess_VectorRotator = NULL;
	if(!pFnLessLess_VectorRotator)
		pFnLessLess_VectorRotator = UObject::FindFunction("Function Core.Object.LessLess_VectorRotator");

	Core_LessLess_VectorRotator_Parms LessLess_VectorRotator_Parms;
	memcpy(&LessLess_VectorRotator_Parms.A,&A,0xC);
	memcpy(&LessLess_VectorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnLessLess_VectorRotator->iNative;
	pFnLessLess_VectorRotator->iNative = 0;
	pFnLessLess_VectorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLessLess_VectorRotator,NULL,&LessLess_VectorRotator_Parms,NULL);
	pFnLessLess_VectorRotator->FunctionFlags |= 0x400;
	pFnLessLess_VectorRotator->iNative = NativeIndex;
	return LessLess_VectorRotator_Parms.ReturnValue;
}

struct Core_Max_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Max(int A,int B)
{
	static UFieldFunc* pFnMax = NULL;
	if(!pFnMax)
		pFnMax = UObject::FindFunction("Function Core.Object.Max");

	Core_Max_Parms Max_Parms;
	Max_Parms.A = A;
	Max_Parms.B = B;

	unsigned short NativeIndex = pFnMax->iNative;
	pFnMax->iNative = 0;
	pFnMax->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMax,NULL,&Max_Parms,NULL);
	pFnMax->FunctionFlags |= 0x400;
	pFnMax->iNative = NativeIndex;
	return Max_Parms.ReturnValue;
}

struct Core_Add_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::Add_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnAdd_VectorVector = NULL;
	if(!pFnAdd_VectorVector)
		pFnAdd_VectorVector = UObject::FindFunction("Function Core.Object.Add_VectorVector");

	Core_Add_VectorVector_Parms Add_VectorVector_Parms;
	memcpy(&Add_VectorVector_Parms.A,&A,0xC);
	memcpy(&Add_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnAdd_VectorVector->iNative;
	pFnAdd_VectorVector->iNative = 0;
	pFnAdd_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdd_VectorVector,NULL,&Add_VectorVector_Parms,NULL);
	pFnAdd_VectorVector->FunctionFlags |= 0x400;
	pFnAdd_VectorVector->iNative = NativeIndex;
	return Add_VectorVector_Parms.ReturnValue;
}

struct Core_EqualEqual_FieldField_Parms
{
	class UField*                                      A;                                                		// 0x000000 (0x0004)              
	class UField*                                      B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_FieldField(class UField* A,class UField* B)
{
	static UFieldFunc* pFnEqualEqual_FieldField = NULL;
	if(!pFnEqualEqual_FieldField)
		pFnEqualEqual_FieldField = UObject::FindFunction("Function Core.Object.EqualEqual_FieldField");

	Core_EqualEqual_FieldField_Parms EqualEqual_FieldField_Parms;
	EqualEqual_FieldField_Parms.A = A;
	EqualEqual_FieldField_Parms.B = B;
	pFnEqualEqual_FieldField->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_FieldField,NULL,&EqualEqual_FieldField_Parms,NULL);
	pFnEqualEqual_FieldField->FunctionFlags |= 0x400;
	return EqualEqual_FieldField_Parms.ReturnValue;
}

struct Core_Lerp_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              Alpha;                                            		// 0x000008 (0x0004)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::Lerp(float A,float B,float Alpha)
{
	static UFieldFunc* pFnLerp = NULL;
	if(!pFnLerp)
		pFnLerp = UObject::FindFunction("Function Core.Object.Lerp");

	Core_Lerp_Parms Lerp_Parms;
	Lerp_Parms.A = A;
	Lerp_Parms.B = B;
	Lerp_Parms.Alpha = Alpha;

	unsigned short NativeIndex = pFnLerp->iNative;
	pFnLerp->iNative = 0;
	pFnLerp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLerp,NULL,&Lerp_Parms,NULL);
	pFnLerp->FunctionFlags |= 0x400;
	pFnLerp->iNative = NativeIndex;
	return Lerp_Parms.ReturnValue;
}

struct Core_MultiplyEqual_VectorFloat_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FVector3 UObject::MultiplyEqual_VectorFloat(FVector3* A,float B)
{
	static UFieldFunc* pFnMultiplyEqual_VectorFloat = NULL;
	if(!pFnMultiplyEqual_VectorFloat)
		pFnMultiplyEqual_VectorFloat = UObject::FindFunction("Function Core.Object.MultiplyEqual_VectorFloat");

	Core_MultiplyEqual_VectorFloat_Parms MultiplyEqual_VectorFloat_Parms;
	MultiplyEqual_VectorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_VectorFloat->iNative;
	pFnMultiplyEqual_VectorFloat->iNative = 0;
	pFnMultiplyEqual_VectorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_VectorFloat,NULL,&MultiplyEqual_VectorFloat_Parms,NULL);
	pFnMultiplyEqual_VectorFloat->FunctionFlags |= 0x400;
	pFnMultiplyEqual_VectorFloat->iNative = NativeIndex;
	if(A)
		memcpy(A,&MultiplyEqual_VectorFloat_Parms.A,0xC);
	return MultiplyEqual_VectorFloat_Parms.ReturnValue;
}

struct Core_SubtractSubtract_PreInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::SubtractSubtract_PreInt(int* A)
{
	static UFieldFunc* pFnSubtractSubtract_PreInt = NULL;
	if(!pFnSubtractSubtract_PreInt)
		pFnSubtractSubtract_PreInt = UObject::FindFunction("Function Core.Object.SubtractSubtract_PreInt");

	Core_SubtractSubtract_PreInt_Parms SubtractSubtract_PreInt_Parms;

	unsigned short NativeIndex = pFnSubtractSubtract_PreInt->iNative;
	pFnSubtractSubtract_PreInt->iNative = 0;
	pFnSubtractSubtract_PreInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractSubtract_PreInt,NULL,&SubtractSubtract_PreInt_Parms,NULL);
	pFnSubtractSubtract_PreInt->FunctionFlags |= 0x400;
	pFnSubtractSubtract_PreInt->iNative = NativeIndex;
	if(A)
		*A = SubtractSubtract_PreInt_Parms.A;
	return SubtractSubtract_PreInt_Parms.ReturnValue;
}

struct Core_Greater_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::Greater_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnGreater_FloatFloat = NULL;
	if(!pFnGreater_FloatFloat)
		pFnGreater_FloatFloat = UObject::FindFunction("Function Core.Object.Greater_FloatFloat");

	Core_Greater_FloatFloat_Parms Greater_FloatFloat_Parms;
	Greater_FloatFloat_Parms.A = A;
	Greater_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnGreater_FloatFloat->iNative;
	pFnGreater_FloatFloat->iNative = 0;
	pFnGreater_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreater_FloatFloat,NULL,&Greater_FloatFloat_Parms,NULL);
	pFnGreater_FloatFloat->FunctionFlags |= 0x400;
	pFnGreater_FloatFloat->iNative = NativeIndex;
	return Greater_FloatFloat_Parms.ReturnValue;
}

struct Core_Xor_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Xor_IntInt(int A,int B)
{
	static UFieldFunc* pFnXor_IntInt = NULL;
	if(!pFnXor_IntInt)
		pFnXor_IntInt = UObject::FindFunction("Function Core.Object.Xor_IntInt");

	Core_Xor_IntInt_Parms Xor_IntInt_Parms;
	Xor_IntInt_Parms.A = A;
	Xor_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnXor_IntInt->iNative;
	pFnXor_IntInt->iNative = 0;
	pFnXor_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnXor_IntInt,NULL,&Xor_IntInt_Parms,NULL);
	pFnXor_IntInt->FunctionFlags |= 0x400;
	pFnXor_IntInt->iNative = NativeIndex;
	return Xor_IntInt_Parms.ReturnValue;
}

struct Core_Normalize_Parms
{
	FRotator                                           Rot;                                              		// 0x000000 (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x00000C (0x000C)              
};

FRotator UObject::Normalize(FRotator Rot)
{
	static UFieldFunc* pFnNormalize = NULL;
	if(!pFnNormalize)
		pFnNormalize = UObject::FindFunction("Function Core.Object.Normalize");

	Core_Normalize_Parms Normalize_Parms;
	memcpy(&Normalize_Parms.Rot,&Rot,0xC);
	pFnNormalize->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNormalize,NULL,&Normalize_Parms,NULL);
	pFnNormalize->FunctionFlags |= 0x400;
	return Normalize_Parms.ReturnValue;
}

struct Core_Subtract_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::Subtract_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnSubtract_VectorVector = NULL;
	if(!pFnSubtract_VectorVector)
		pFnSubtract_VectorVector = UObject::FindFunction("Function Core.Object.Subtract_VectorVector");

	Core_Subtract_VectorVector_Parms Subtract_VectorVector_Parms;
	memcpy(&Subtract_VectorVector_Parms.A,&A,0xC);
	memcpy(&Subtract_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnSubtract_VectorVector->iNative;
	pFnSubtract_VectorVector->iNative = 0;
	pFnSubtract_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_VectorVector,NULL,&Subtract_VectorVector_Parms,NULL);
	pFnSubtract_VectorVector->FunctionFlags |= 0x400;
	pFnSubtract_VectorVector->iNative = NativeIndex;
	return Subtract_VectorVector_Parms.ReturnValue;
}

struct Core_DivideEqual_ByteByte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      B;                                                		// 0x000001 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000002 (0x0001)              
};

unsigned char UObject::DivideEqual_ByteByte(unsigned char* A,unsigned char B)
{
	static UFieldFunc* pFnDivideEqual_ByteByte = NULL;
	if(!pFnDivideEqual_ByteByte)
		pFnDivideEqual_ByteByte = UObject::FindFunction("Function Core.Object.DivideEqual_ByteByte");

	Core_DivideEqual_ByteByte_Parms DivideEqual_ByteByte_Parms;
	DivideEqual_ByteByte_Parms.B = B;

	unsigned short NativeIndex = pFnDivideEqual_ByteByte->iNative;
	pFnDivideEqual_ByteByte->iNative = 0;
	pFnDivideEqual_ByteByte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivideEqual_ByteByte,NULL,&DivideEqual_ByteByte_Parms,NULL);
	pFnDivideEqual_ByteByte->FunctionFlags |= 0x400;
	pFnDivideEqual_ByteByte->iNative = NativeIndex;
	if(A)
		*A = DivideEqual_ByteByte_Parms.A;
	return DivideEqual_ByteByte_Parms.ReturnValue;
}

struct Core_GetPerObjectConfigSections_Parms
{
	class UClass*                                      SearchClass;                                      		// 0x000000 (0x0004)              
	TArray<struct FString>                             out_SectionNames;                                 		// 0x000004 (0x000C)              
	class UObject*                                     ObjectOuter;                                      		// 0x000010 (0x0004)              
	int                                                MaxResults;                                       		// 0x000014 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::GetPerObjectConfigSections(class UClass* SearchClass,TArray<struct FString>* out_SectionNames,class UObject* ObjectOuter,int MaxResults)
{
	static UFieldFunc* pFnGetPerObjectConfigSections = NULL;
	if(!pFnGetPerObjectConfigSections)
		pFnGetPerObjectConfigSections = UObject::FindFunction("Function Core.Object.GetPerObjectConfigSections");

	Core_GetPerObjectConfigSections_Parms GetPerObjectConfigSections_Parms;
	GetPerObjectConfigSections_Parms.SearchClass = SearchClass;
	GetPerObjectConfigSections_Parms.ObjectOuter = ObjectOuter;
	GetPerObjectConfigSections_Parms.MaxResults = MaxResults;
	pFnGetPerObjectConfigSections->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetPerObjectConfigSections,NULL,&GetPerObjectConfigSections_Parms,NULL);
	pFnGetPerObjectConfigSections->FunctionFlags |= 0x400;
	if(out_SectionNames)
		memcpy(out_SectionNames,&GetPerObjectConfigSections_Parms.out_SectionNames,0xC);
	return GetPerObjectConfigSections_Parms.ReturnValue;
}

struct Core_NotEqual_BoolBool_Parms
{
	unsigned long                                      A : 1;                                            		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_BoolBool(bool A,bool B)
{
	static UFieldFunc* pFnNotEqual_BoolBool = NULL;
	if(!pFnNotEqual_BoolBool)
		pFnNotEqual_BoolBool = UObject::FindFunction("Function Core.Object.NotEqual_BoolBool");

	Core_NotEqual_BoolBool_Parms NotEqual_BoolBool_Parms;
	NotEqual_BoolBool_Parms.A = A;
	NotEqual_BoolBool_Parms.B = B;

	unsigned short NativeIndex = pFnNotEqual_BoolBool->iNative;
	pFnNotEqual_BoolBool->iNative = 0;
	pFnNotEqual_BoolBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_BoolBool,NULL,&NotEqual_BoolBool_Parms,NULL);
	pFnNotEqual_BoolBool->FunctionFlags |= 0x400;
	pFnNotEqual_BoolBool->iNative = NativeIndex;
	return NotEqual_BoolBool_Parms.ReturnValue;
}

struct Core_IsPendingKill_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UObject::IsPendingKill()
{
	static UFieldFunc* pFnIsPendingKill = NULL;
	if(!pFnIsPendingKill)
		pFnIsPendingKill = UObject::FindFunction("Function Core.Object.IsPendingKill");

	Core_IsPendingKill_Parms IsPendingKill_Parms;
	pFnIsPendingKill->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsPendingKill,NULL,&IsPendingKill_Parms,NULL);
	pFnIsPendingKill->FunctionFlags |= 0x400;
	return IsPendingKill_Parms.ReturnValue;
}

struct Core_BeginState_Parms
{
	struct FName                                       PreviousStateName;                                		// 0x000000 (0x0008)              
};

void UObject::BeginState(struct FName PreviousStateName)
{
	static UFieldFunc* pFnBeginState = NULL;
	if(!pFnBeginState)
		pFnBeginState = UObject::FindFunction("Function Core.Object.BeginState");

	Core_BeginState_Parms BeginState_Parms;
	memcpy(&BeginState_Parms.PreviousStateName,&PreviousStateName,0x8);
	ProcessEvent(pFnBeginState,NULL,&BeginState_Parms,NULL);
}

struct Core_Divide_RotatorFloat_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FRotator                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FRotator UObject::Divide_RotatorFloat(FRotator A,float B)
{
	static UFieldFunc* pFnDivide_RotatorFloat = NULL;
	if(!pFnDivide_RotatorFloat)
		pFnDivide_RotatorFloat = UObject::FindFunction("Function Core.Object.Divide_RotatorFloat");

	Core_Divide_RotatorFloat_Parms Divide_RotatorFloat_Parms;
	memcpy(&Divide_RotatorFloat_Parms.A,&A,0xC);
	Divide_RotatorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivide_RotatorFloat->iNative;
	pFnDivide_RotatorFloat->iNative = 0;
	pFnDivide_RotatorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivide_RotatorFloat,NULL,&Divide_RotatorFloat_Parms,NULL);
	pFnDivide_RotatorFloat->FunctionFlags |= 0x400;
	pFnDivide_RotatorFloat->iNative = NativeIndex;
	return Divide_RotatorFloat_Parms.ReturnValue;
}

struct Core_IsInState_Parms
{
	struct FName                                       TestState;                                        		// 0x000000 (0x0008)              
	unsigned long                                      bTestStateStack : 1;                              		// 0x000008 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UObject::IsInState(struct FName TestState,bool bTestStateStack)
{
	static UFieldFunc* pFnIsInState = NULL;
	if(!pFnIsInState)
		pFnIsInState = UObject::FindFunction("Function Core.Object.IsInState");

	Core_IsInState_Parms IsInState_Parms;
	memcpy(&IsInState_Parms.TestState,&TestState,0x8);
	IsInState_Parms.bTestStateStack = bTestStateStack;

	unsigned short NativeIndex = pFnIsInState->iNative;
	pFnIsInState->iNative = 0;
	pFnIsInState->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsInState,NULL,&IsInState_Parms,NULL);
	pFnIsInState->FunctionFlags |= 0x400;
	pFnIsInState->iNative = NativeIndex;
	return IsInState_Parms.ReturnValue;
}

struct Core_GetStateName_Parms
{
	struct FName                                       ReturnValue;                                      		// 0x000000 (0x0008)              
};

struct FName UObject::GetStateName()
{
	static UFieldFunc* pFnGetStateName = NULL;
	if(!pFnGetStateName)
		pFnGetStateName = UObject::FindFunction("Function Core.Object.GetStateName");

	Core_GetStateName_Parms GetStateName_Parms;

	unsigned short NativeIndex = pFnGetStateName->iNative;
	pFnGetStateName->iNative = 0;
	pFnGetStateName->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetStateName,NULL,&GetStateName_Parms,NULL);
	pFnGetStateName->FunctionFlags |= 0x400;
	pFnGetStateName->iNative = NativeIndex;
	return GetStateName_Parms.ReturnValue;
}

struct Core_SubtractEqual_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::SubtractEqual_VectorVector(FVector3* A,FVector3 B)
{
	static UFieldFunc* pFnSubtractEqual_VectorVector = NULL;
	if(!pFnSubtractEqual_VectorVector)
		pFnSubtractEqual_VectorVector = UObject::FindFunction("Function Core.Object.SubtractEqual_VectorVector");

	Core_SubtractEqual_VectorVector_Parms SubtractEqual_VectorVector_Parms;
	memcpy(&SubtractEqual_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnSubtractEqual_VectorVector->iNative;
	pFnSubtractEqual_VectorVector->iNative = 0;
	pFnSubtractEqual_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_VectorVector,NULL,&SubtractEqual_VectorVector_Parms,NULL);
	pFnSubtractEqual_VectorVector->FunctionFlags |= 0x400;
	pFnSubtractEqual_VectorVector->iNative = NativeIndex;
	if(A)
		memcpy(A,&SubtractEqual_VectorVector_Parms.A,0xC);
	return SubtractEqual_VectorVector_Parms.ReturnValue;
}

struct Core_EqualEqual_RotatorRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_RotatorRotator(FRotator A,FRotator B)
{
	static UFieldFunc* pFnEqualEqual_RotatorRotator = NULL;
	if(!pFnEqualEqual_RotatorRotator)
		pFnEqualEqual_RotatorRotator = UObject::FindFunction("Function Core.Object.EqualEqual_RotatorRotator");

	Core_EqualEqual_RotatorRotator_Parms EqualEqual_RotatorRotator_Parms;
	memcpy(&EqualEqual_RotatorRotator_Parms.A,&A,0xC);
	memcpy(&EqualEqual_RotatorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnEqualEqual_RotatorRotator->iNative;
	pFnEqualEqual_RotatorRotator->iNative = 0;
	pFnEqualEqual_RotatorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_RotatorRotator,NULL,&EqualEqual_RotatorRotator_Parms,NULL);
	pFnEqualEqual_RotatorRotator->FunctionFlags |= 0x400;
	pFnEqualEqual_RotatorRotator->iNative = NativeIndex;
	return EqualEqual_RotatorRotator_Parms.ReturnValue;
}

struct Core_StaticSaveConfig_Parms
{
};

void UObject::StaticSaveConfig()
{
	static UFieldFunc* pFnStaticSaveConfig = NULL;
	if(!pFnStaticSaveConfig)
		pFnStaticSaveConfig = UObject::FindFunction("Function Core.Object.StaticSaveConfig");

	Core_StaticSaveConfig_Parms StaticSaveConfig_Parms;
	pFnStaticSaveConfig->FunctionFlags |= ~0x400;
	ProcessEvent(pFnStaticSaveConfig,NULL,&StaticSaveConfig_Parms,NULL);
	pFnStaticSaveConfig->FunctionFlags |= 0x400;
}

struct Core_Mid_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	int                                                I;                                                		// 0x00000C (0x0004)              
	int                                                J;                                                		// 0x000010 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000014 (0x000C)              
};

struct FString UObject::Mid(struct FString S,int I,int J)
{
	static UFieldFunc* pFnMid = NULL;
	if(!pFnMid)
		pFnMid = UObject::FindFunction("Function Core.Object.Mid");

	Core_Mid_Parms Mid_Parms;
	memcpy(&Mid_Parms.S,&S,0xC);
	Mid_Parms.I = I;
	Mid_Parms.J = J;

	unsigned short NativeIndex = pFnMid->iNative;
	pFnMid->iNative = 0;
	pFnMid->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMid,NULL,&Mid_Parms,NULL);
	pFnMid->FunctionFlags |= 0x400;
	pFnMid->iNative = NativeIndex;
	return Mid_Parms.ReturnValue;
}

struct Core_Add_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Add_IntInt(int A,int B)
{
	static UFieldFunc* pFnAdd_IntInt = NULL;
	if(!pFnAdd_IntInt)
		pFnAdd_IntInt = UObject::FindFunction("Function Core.Object.Add_IntInt");

	Core_Add_IntInt_Parms Add_IntInt_Parms;
	Add_IntInt_Parms.A = A;
	Add_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnAdd_IntInt->iNative;
	pFnAdd_IntInt->iNative = 0;
	pFnAdd_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdd_IntInt,NULL,&Add_IntInt_Parms,NULL);
	pFnAdd_IntInt->FunctionFlags |= 0x400;
	pFnAdd_IntInt->iNative = NativeIndex;
	return Add_IntInt_Parms.ReturnValue;
}

struct Core_vect2d_Parms
{
	float                                              InX;                                              		// 0x000000 (0x0004)              
	float                                              InY;                                              		// 0x000004 (0x0004)              
	FVector2                                           ReturnValue;                                      		// 0x000008 (0x0008)              
	//FVector2                                           NewVect2d;                                        		// 0x000010 (0x0008)              
};

FVector2 UObject::vect2d(float InX,float InY)
{
	static UFieldFunc* pFnvect2d = NULL;
	if(!pFnvect2d)
		pFnvect2d = UObject::FindFunction("Function Core.Object.vect2d");

	Core_vect2d_Parms vect2d_Parms;
	vect2d_Parms.InX = InX;
	vect2d_Parms.InY = InY;
	ProcessEvent(pFnvect2d,NULL,&vect2d_Parms,NULL);
	return vect2d_Parms.ReturnValue;
}

struct Core_Exp_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Exp(float A)
{
	static UFieldFunc* pFnExp = NULL;
	if(!pFnExp)
		pFnExp = UObject::FindFunction("Function Core.Object.Exp");

	Core_Exp_Parms Exp_Parms;
	Exp_Parms.A = A;

	unsigned short NativeIndex = pFnExp->iNative;
	pFnExp->iNative = 0;
	pFnExp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnExp,NULL,&Exp_Parms,NULL);
	pFnExp->FunctionFlags |= 0x400;
	pFnExp->iNative = NativeIndex;
	return Exp_Parms.ReturnValue;
}

struct Core_DivideEqual_IntFloat_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::DivideEqual_IntFloat(int* A,float B)
{
	static UFieldFunc* pFnDivideEqual_IntFloat = NULL;
	if(!pFnDivideEqual_IntFloat)
		pFnDivideEqual_IntFloat = UObject::FindFunction("Function Core.Object.DivideEqual_IntFloat");

	Core_DivideEqual_IntFloat_Parms DivideEqual_IntFloat_Parms;
	DivideEqual_IntFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivideEqual_IntFloat->iNative;
	pFnDivideEqual_IntFloat->iNative = 0;
	pFnDivideEqual_IntFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivideEqual_IntFloat,NULL,&DivideEqual_IntFloat_Parms,NULL);
	pFnDivideEqual_IntFloat->FunctionFlags |= 0x400;
	pFnDivideEqual_IntFloat->iNative = NativeIndex;
	if(A)
		*A = DivideEqual_IntFloat_Parms.A;
	return DivideEqual_IntFloat_Parms.ReturnValue;
}

struct Core_Asc_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UObject::Asc(struct FString S)
{
	static UFieldFunc* pFnAsc = NULL;
	if(!pFnAsc)
		pFnAsc = UObject::FindFunction("Function Core.Object.Asc");

	Core_Asc_Parms Asc_Parms;
	memcpy(&Asc_Parms.S,&S,0xC);

	unsigned short NativeIndex = pFnAsc->iNative;
	pFnAsc->iNative = 0;
	pFnAsc->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAsc,NULL,&Asc_Parms,NULL);
	pFnAsc->FunctionFlags |= 0x400;
	pFnAsc->iNative = NativeIndex;
	return Asc_Parms.ReturnValue;
}

struct Core_NotEqual_FieldField_Parms
{
	class UField*                                      A;                                                		// 0x000000 (0x0004)              
	class UField*                                      B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_FieldField(class UField* A,class UField* B)
{
	static UFieldFunc* pFnNotEqual_FieldField = NULL;
	if(!pFnNotEqual_FieldField)
		pFnNotEqual_FieldField = UObject::FindFunction("Function Core.Object.NotEqual_FieldField");

	Core_NotEqual_FieldField_Parms NotEqual_FieldField_Parms;
	NotEqual_FieldField_Parms.A = A;
	NotEqual_FieldField_Parms.B = B;
	pFnNotEqual_FieldField->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_FieldField,NULL,&NotEqual_FieldField_Parms,NULL);
	pFnNotEqual_FieldField->FunctionFlags |= 0x400;
	return NotEqual_FieldField_Parms.ReturnValue;
}

struct Core_GetAngularDistance_Parms
{
	FVector2                                           OutAngularDist;                                   		// 0x000000 (0x0008)              
	FVector3                                           Direction;                                        		// 0x000008 (0x000C)              
	FVector3                                           AxisX;                                            		// 0x000014 (0x000C)              
	FVector3                                           AxisY;                                            		// 0x000020 (0x000C)              
	FVector3                                           AxisZ;                                            		// 0x00002C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000038 (0x0004) [0x00000001] 
};

bool UObject::GetAngularDistance(FVector2* OutAngularDist,FVector3 Direction,FVector3 AxisX,FVector3 AxisY,FVector3 AxisZ)
{
	static UFieldFunc* pFnGetAngularDistance = NULL;
	if(!pFnGetAngularDistance)
		pFnGetAngularDistance = UObject::FindFunction("Function Core.Object.GetAngularDistance");

	Core_GetAngularDistance_Parms GetAngularDistance_Parms;
	memcpy(&GetAngularDistance_Parms.Direction,&Direction,0xC);
	memcpy(&GetAngularDistance_Parms.AxisX,&AxisX,0xC);
	memcpy(&GetAngularDistance_Parms.AxisY,&AxisY,0xC);
	memcpy(&GetAngularDistance_Parms.AxisZ,&AxisZ,0xC);
	pFnGetAngularDistance->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetAngularDistance,NULL,&GetAngularDistance_Parms,NULL);
	pFnGetAngularDistance->FunctionFlags |= 0x400;
	if(OutAngularDist)
		memcpy(OutAngularDist,&GetAngularDistance_Parms.OutAngularDist,0x8);
	return GetAngularDistance_Parms.ReturnValue;
}

struct Core_AndAnd_BoolBool_Parms
{
	unsigned long                                      A : 1;                                            		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::AndAnd_BoolBool(bool A,bool B)
{
	static UFieldFunc* pFnAndAnd_BoolBool = NULL;
	if(!pFnAndAnd_BoolBool)
		pFnAndAnd_BoolBool = UObject::FindFunction("Function Core.Object.AndAnd_BoolBool");

	Core_AndAnd_BoolBool_Parms AndAnd_BoolBool_Parms;
	AndAnd_BoolBool_Parms.A = A;
	AndAnd_BoolBool_Parms.B = B;

	unsigned short NativeIndex = pFnAndAnd_BoolBool->iNative;
	pFnAndAnd_BoolBool->iNative = 0;
	pFnAndAnd_BoolBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAndAnd_BoolBool,NULL,&AndAnd_BoolBool_Parms,NULL);
	pFnAndAnd_BoolBool->FunctionFlags |= 0x400;
	pFnAndAnd_BoolBool->iNative = NativeIndex;
	return AndAnd_BoolBool_Parms.ReturnValue;
}

struct Core_DFloor_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::DFloor(double A)
{
	static UFieldFunc* pFnDFloor = NULL;
	if(!pFnDFloor)
		pFnDFloor = UObject::FindFunction("Function Core.Object.DFloor");

	Core_DFloor_Parms DFloor_Parms;
	DFloor_Parms.A = A;
	pFnDFloor->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDFloor,NULL,&DFloor_Parms,NULL);
	pFnDFloor->FunctionFlags |= 0x400;
	return DFloor_Parms.ReturnValue;
}

struct Core_VRand_Parms
{
	FVector3                                           ReturnValue;                                      		// 0x000000 (0x000C)              
};

FVector3 UObject::VRand()
{
	static UFieldFunc* pFnVRand = NULL;
	if(!pFnVRand)
		pFnVRand = UObject::FindFunction("Function Core.Object.VRand");

	Core_VRand_Parms VRand_Parms;

	unsigned short NativeIndex = pFnVRand->iNative;
	pFnVRand->iNative = 0;
	pFnVRand->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVRand,NULL,&VRand_Parms,NULL);
	pFnVRand->FunctionFlags |= 0x400;
	pFnVRand->iNative = NativeIndex;
	return VRand_Parms.ReturnValue;
}

struct Core_DivideEqual_VectorFloat_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FVector3 UObject::DivideEqual_VectorFloat(FVector3* A,float B)
{
	static UFieldFunc* pFnDivideEqual_VectorFloat = NULL;
	if(!pFnDivideEqual_VectorFloat)
		pFnDivideEqual_VectorFloat = UObject::FindFunction("Function Core.Object.DivideEqual_VectorFloat");

	Core_DivideEqual_VectorFloat_Parms DivideEqual_VectorFloat_Parms;
	DivideEqual_VectorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivideEqual_VectorFloat->iNative;
	pFnDivideEqual_VectorFloat->iNative = 0;
	pFnDivideEqual_VectorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivideEqual_VectorFloat,NULL,&DivideEqual_VectorFloat_Parms,NULL);
	pFnDivideEqual_VectorFloat->FunctionFlags |= 0x400;
	pFnDivideEqual_VectorFloat->iNative = NativeIndex;
	if(A)
		memcpy(A,&DivideEqual_VectorFloat_Parms.A,0xC);
	return DivideEqual_VectorFloat_Parms.ReturnValue;
}

struct Core_AddEqual_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::AddEqual_IntInt(int* A,int B)
{
	static UFieldFunc* pFnAddEqual_IntInt = NULL;
	if(!pFnAddEqual_IntInt)
		pFnAddEqual_IntInt = UObject::FindFunction("Function Core.Object.AddEqual_IntInt");

	Core_AddEqual_IntInt_Parms AddEqual_IntInt_Parms;
	AddEqual_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnAddEqual_IntInt->iNative;
	pFnAddEqual_IntInt->iNative = 0;
	pFnAddEqual_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddEqual_IntInt,NULL,&AddEqual_IntInt_Parms,NULL);
	pFnAddEqual_IntInt->FunctionFlags |= 0x400;
	pFnAddEqual_IntInt->iNative = NativeIndex;
	if(A)
		*A = AddEqual_IntInt_Parms.A;
	return AddEqual_IntInt_Parms.ReturnValue;
}

struct Core_PausedState_Parms
{
};

void UObject::PausedState()
{
	static UFieldFunc* pFnPausedState = NULL;
	if(!pFnPausedState)
		pFnPausedState = UObject::FindFunction("Function Core.Object.PausedState");

	Core_PausedState_Parms PausedState_Parms;
	ProcessEvent(pFnPausedState,NULL,&PausedState_Parms,NULL);
}

struct Core_Abs_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Abs(float A)
{
	static UFieldFunc* pFnAbs = NULL;
	if(!pFnAbs)
		pFnAbs = UObject::FindFunction("Function Core.Object.Abs");

	Core_Abs_Parms Abs_Parms;
	Abs_Parms.A = A;

	unsigned short NativeIndex = pFnAbs->iNative;
	pFnAbs->iNative = 0;
	pFnAbs->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAbs,NULL,&Abs_Parms,NULL);
	pFnAbs->FunctionFlags |= 0x400;
	pFnAbs->iNative = NativeIndex;
	return Abs_Parms.ReturnValue;
}

struct Core_Enable_Parms
{
	struct FName                                       ProbeFunc;                                        		// 0x000000 (0x0008)              
};

void UObject::Enable(struct FName ProbeFunc)
{
	static UFieldFunc* pFnEnable = NULL;
	if(!pFnEnable)
		pFnEnable = UObject::FindFunction("Function Core.Object.Enable");

	Core_Enable_Parms Enable_Parms;
	memcpy(&Enable_Parms.ProbeFunc,&ProbeFunc,0x8);

	unsigned short NativeIndex = pFnEnable->iNative;
	pFnEnable->iNative = 0;
	pFnEnable->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEnable,NULL,&Enable_Parms,NULL);
	pFnEnable->FunctionFlags |= 0x400;
	pFnEnable->iNative = NativeIndex;
}

struct Core_Multiply_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::Multiply_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnMultiply_FloatFloat = NULL;
	if(!pFnMultiply_FloatFloat)
		pFnMultiply_FloatFloat = UObject::FindFunction("Function Core.Object.Multiply_FloatFloat");

	Core_Multiply_FloatFloat_Parms Multiply_FloatFloat_Parms;
	Multiply_FloatFloat_Parms.A = A;
	Multiply_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiply_FloatFloat->iNative;
	pFnMultiply_FloatFloat->iNative = 0;
	pFnMultiply_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_FloatFloat,NULL,&Multiply_FloatFloat_Parms,NULL);
	pFnMultiply_FloatFloat->FunctionFlags |= 0x400;
	pFnMultiply_FloatFloat->iNative = NativeIndex;
	return Multiply_FloatFloat_Parms.ReturnValue;
}

struct Core_MultiplyEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::MultiplyEqual_DoubleDouble(double* A,double B)
{
	static UFieldFunc* pFnMultiplyEqual_DoubleDouble = NULL;
	if(!pFnMultiplyEqual_DoubleDouble)
		pFnMultiplyEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.MultiplyEqual_DoubleDouble");

	Core_MultiplyEqual_DoubleDouble_Parms MultiplyEqual_DoubleDouble_Parms;
	MultiplyEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_DoubleDouble->iNative;
	pFnMultiplyEqual_DoubleDouble->iNative = 0;
	pFnMultiplyEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_DoubleDouble,NULL,&MultiplyEqual_DoubleDouble_Parms,NULL);
	pFnMultiplyEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnMultiplyEqual_DoubleDouble->iNative = NativeIndex;
	if(A)
		*A = MultiplyEqual_DoubleDouble_Parms.A;
	return MultiplyEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_RotRand_Parms
{
	unsigned long                                      bRoll : 1;                                        		// 0x000000 (0x0004) [0x00000001] 
	FRotator                                           ReturnValue;                                      		// 0x000004 (0x000C)              
};

FRotator UObject::RotRand(bool bRoll)
{
	static UFieldFunc* pFnRotRand = NULL;
	if(!pFnRotRand)
		pFnRotRand = UObject::FindFunction("Function Core.Object.RotRand");

	Core_RotRand_Parms RotRand_Parms;
	RotRand_Parms.bRoll = bRoll;

	unsigned short NativeIndex = pFnRotRand->iNative;
	pFnRotRand->iNative = 0;
	pFnRotRand->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRotRand,NULL,&RotRand_Parms,NULL);
	pFnRotRand->FunctionFlags |= 0x400;
	pFnRotRand->iNative = NativeIndex;
	return RotRand_Parms.ReturnValue;
}

struct Core_VSizeSq_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::VSizeSq(FVector3 A)
{
	static UFieldFunc* pFnVSizeSq = NULL;
	if(!pFnVSizeSq)
		pFnVSizeSq = UObject::FindFunction("Function Core.Object.VSizeSq");

	Core_VSizeSq_Parms VSizeSq_Parms;
	memcpy(&VSizeSq_Parms.A,&A,0xC);
	pFnVSizeSq->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVSizeSq,NULL,&VSizeSq_Parms,NULL);
	pFnVSizeSq->FunctionFlags |= 0x400;
	return VSizeSq_Parms.ReturnValue;
}

struct Core_LogReturnFalse_Parms
{
	struct FString                                     logString;                                        		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UObject::LogReturnFalse(struct FString logString)
{
	static UFieldFunc* pFnLogReturnFalse = NULL;
	if(!pFnLogReturnFalse)
		pFnLogReturnFalse = UObject::FindFunction("Function Core.Object.LogReturnFalse");

	Core_LogReturnFalse_Parms LogReturnFalse_Parms;
	memcpy(&LogReturnFalse_Parms.logString,&logString,0xC);
	ProcessEvent(pFnLogReturnFalse,NULL,&LogReturnFalse_Parms,NULL);
	return LogReturnFalse_Parms.ReturnValue;
}

struct Core_SubtractSubtract_Byte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000001 (0x0001)              
};

unsigned char UObject::SubtractSubtract_Byte(unsigned char* A)
{
	static UFieldFunc* pFnSubtractSubtract_Byte = NULL;
	if(!pFnSubtractSubtract_Byte)
		pFnSubtractSubtract_Byte = UObject::FindFunction("Function Core.Object.SubtractSubtract_Byte");

	Core_SubtractSubtract_Byte_Parms SubtractSubtract_Byte_Parms;

	unsigned short NativeIndex = pFnSubtractSubtract_Byte->iNative;
	pFnSubtractSubtract_Byte->iNative = 0;
	pFnSubtractSubtract_Byte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractSubtract_Byte,NULL,&SubtractSubtract_Byte_Parms,NULL);
	pFnSubtractSubtract_Byte->FunctionFlags |= 0x400;
	pFnSubtractSubtract_Byte->iNative = NativeIndex;
	if(A)
		*A = SubtractSubtract_Byte_Parms.A;
	return SubtractSubtract_Byte_Parms.ReturnValue;
}

struct Core_Normal_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00000C (0x000C)              
};

FVector3 UObject::Normal(FVector3 A)
{
	static UFieldFunc* pFnNormal = NULL;
	if(!pFnNormal)
		pFnNormal = UObject::FindFunction("Function Core.Object.Normal");

	Core_Normal_Parms Normal_Parms;
	memcpy(&Normal_Parms.A,&A,0xC);

	unsigned short NativeIndex = pFnNormal->iNative;
	pFnNormal->iNative = 0;
	pFnNormal->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNormal,NULL,&Normal_Parms,NULL);
	pFnNormal->FunctionFlags |= 0x400;
	pFnNormal->iNative = NativeIndex;
	return Normal_Parms.ReturnValue;
}

struct Core_DLerp_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             Alpha;                                            		// 0x000010 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000018 (0x0008)              
};

double UObject::DLerp(double A,double B,double Alpha)
{
	static UFieldFunc* pFnDLerp = NULL;
	if(!pFnDLerp)
		pFnDLerp = UObject::FindFunction("Function Core.Object.DLerp");

	Core_DLerp_Parms DLerp_Parms;
	DLerp_Parms.A = A;
	DLerp_Parms.B = B;
	DLerp_Parms.Alpha = Alpha;

	unsigned short NativeIndex = pFnDLerp->iNative;
	pFnDLerp->iNative = 0;
	pFnDLerp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDLerp,NULL,&DLerp_Parms,NULL);
	pFnDLerp->FunctionFlags |= 0x400;
	pFnDLerp->iNative = NativeIndex;
	return DLerp_Parms.ReturnValue;
}

struct Core_Disable_Parms
{
	struct FName                                       ProbeFunc;                                        		// 0x000000 (0x0008)              
};

void UObject::Disable(struct FName ProbeFunc)
{
	static UFieldFunc* pFnDisable = NULL;
	if(!pFnDisable)
		pFnDisable = UObject::FindFunction("Function Core.Object.Disable");

	Core_Disable_Parms Disable_Parms;
	memcpy(&Disable_Parms.ProbeFunc,&ProbeFunc,0x8);

	unsigned short NativeIndex = pFnDisable->iNative;
	pFnDisable->iNative = 0;
	pFnDisable->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDisable,NULL,&Disable_Parms,NULL);
	pFnDisable->FunctionFlags |= 0x400;
	pFnDisable->iNative = NativeIndex;
}

struct Core_Cross_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::Cross_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnCross_VectorVector = NULL;
	if(!pFnCross_VectorVector)
		pFnCross_VectorVector = UObject::FindFunction("Function Core.Object.Cross_VectorVector");

	Core_Cross_VectorVector_Parms Cross_VectorVector_Parms;
	memcpy(&Cross_VectorVector_Parms.A,&A,0xC);
	memcpy(&Cross_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnCross_VectorVector->iNative;
	pFnCross_VectorVector->iNative = 0;
	pFnCross_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCross_VectorVector,NULL,&Cross_VectorVector_Parms,NULL);
	pFnCross_VectorVector->FunctionFlags |= 0x400;
	pFnCross_VectorVector->iNative = NativeIndex;
	return Cross_VectorVector_Parms.ReturnValue;
}

struct Core_ClampLength_Parms
{
	FVector3                                           V;                                                		// 0x000000 (0x000C)              
	float                                              MaxLength;                                        		// 0x00000C (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FVector3 UObject::ClampLength(FVector3 V,float MaxLength)
{
	static UFieldFunc* pFnClampLength = NULL;
	if(!pFnClampLength)
		pFnClampLength = UObject::FindFunction("Function Core.Object.ClampLength");

	Core_ClampLength_Parms ClampLength_Parms;
	memcpy(&ClampLength_Parms.V,&V,0xC);
	ClampLength_Parms.MaxLength = MaxLength;
	pFnClampLength->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClampLength,NULL,&ClampLength_Parms,NULL);
	pFnClampLength->FunctionFlags |= 0x400;
	return ClampLength_Parms.ReturnValue;
}

struct Core_Round_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::Round(float A)
{
	static UFieldFunc* pFnRound = NULL;
	if(!pFnRound)
		pFnRound = UObject::FindFunction("Function Core.Object.Round");

	Core_Round_Parms Round_Parms;
	Round_Parms.A = A;

	unsigned short NativeIndex = pFnRound->iNative;
	pFnRound->iNative = 0;
	pFnRound->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRound,NULL,&Round_Parms,NULL);
	pFnRound->FunctionFlags |= 0x400;
	pFnRound->iNative = NativeIndex;
	return Round_Parms.ReturnValue;
}

struct Core_IsUserBuild_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UObject::IsUserBuild()
{
	static UFieldFunc* pFnIsUserBuild = NULL;
	if(!pFnIsUserBuild)
		pFnIsUserBuild = UObject::FindFunction("Function Core.Object.IsUserBuild");

	Core_IsUserBuild_Parms IsUserBuild_Parms;
	pFnIsUserBuild->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsUserBuild,NULL,&IsUserBuild_Parms,NULL);
	pFnIsUserBuild->FunctionFlags |= 0x400;
	return IsUserBuild_Parms.ReturnValue;
}

struct Core_QuatFromAxisAndAngle_Parms
{
	FVector3                                           Axis;                                             		// 0x000000 (0x000C)              
	float                                              Angle;                                            		// 0x00000C (0x0004)              
	struct FQuat                                       ReturnValue;                                      		// 0x000010 (0x0010)              
};

struct FQuat UObject::QuatFromAxisAndAngle(FVector3 Axis,float Angle)
{
	static UFieldFunc* pFnQuatFromAxisAndAngle = NULL;
	if(!pFnQuatFromAxisAndAngle)
		pFnQuatFromAxisAndAngle = UObject::FindFunction("Function Core.Object.QuatFromAxisAndAngle");

	Core_QuatFromAxisAndAngle_Parms QuatFromAxisAndAngle_Parms;
	memcpy(&QuatFromAxisAndAngle_Parms.Axis,&Axis,0xC);
	QuatFromAxisAndAngle_Parms.Angle = Angle;
	pFnQuatFromAxisAndAngle->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatFromAxisAndAngle,NULL,&QuatFromAxisAndAngle_Parms,NULL);
	pFnQuatFromAxisAndAngle->FunctionFlags |= 0x400;
	return QuatFromAxisAndAngle_Parms.ReturnValue;
}

struct Core_PointDistToPlane_Parms
{
	FVector3                                           Point;                                            		// 0x000000 (0x000C)              
	FRotator                                           Orientation;                                      		// 0x00000C (0x000C)              
	FVector3                                           Origin;                                           		// 0x000018 (0x000C)              
	FVector3                                           out_ClosestPoint;                                 		// 0x000024 (0x000C)              
	float                                              ReturnValue;                                      		// 0x000030 (0x0004)              
	//FVector3                                           AxisX;                                            		// 0x000034 (0x000C)              
	//FVector3                                           AxisY;                                            		// 0x000040 (0x000C)              
	//FVector3                                           AxisZ;                                            		// 0x00004C (0x000C)              
	//FVector3                                           PointNoZ;                                         		// 0x000058 (0x000C)              
	//FVector3                                           OriginNoZ;                                        		// 0x000064 (0x000C)              
	//float                                              fPointZ;                                          		// 0x000070 (0x0004)              
	//float                                              fProjDistToAxis;                                  		// 0x000074 (0x0004)              
};

float UObject::PointDistToPlane(FVector3 Point,FRotator Orientation,FVector3 Origin,FVector3* out_ClosestPoint)
{
	static UFieldFunc* pFnPointDistToPlane = NULL;
	if(!pFnPointDistToPlane)
		pFnPointDistToPlane = UObject::FindFunction("Function Core.Object.PointDistToPlane");

	Core_PointDistToPlane_Parms PointDistToPlane_Parms;
	memcpy(&PointDistToPlane_Parms.Point,&Point,0xC);
	memcpy(&PointDistToPlane_Parms.Orientation,&Orientation,0xC);
	memcpy(&PointDistToPlane_Parms.Origin,&Origin,0xC);
	ProcessEvent(pFnPointDistToPlane,NULL,&PointDistToPlane_Parms,NULL);
	if(out_ClosestPoint)
		memcpy(out_ClosestPoint,&PointDistToPlane_Parms.out_ClosestPoint,0xC);
	return PointDistToPlane_Parms.ReturnValue;
}

struct Core_Add_RotatorRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FRotator UObject::Add_RotatorRotator(FRotator A,FRotator B)
{
	static UFieldFunc* pFnAdd_RotatorRotator = NULL;
	if(!pFnAdd_RotatorRotator)
		pFnAdd_RotatorRotator = UObject::FindFunction("Function Core.Object.Add_RotatorRotator");

	Core_Add_RotatorRotator_Parms Add_RotatorRotator_Parms;
	memcpy(&Add_RotatorRotator_Parms.A,&A,0xC);
	memcpy(&Add_RotatorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnAdd_RotatorRotator->iNative;
	pFnAdd_RotatorRotator->iNative = 0;
	pFnAdd_RotatorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdd_RotatorRotator,NULL,&Add_RotatorRotator_Parms,NULL);
	pFnAdd_RotatorRotator->FunctionFlags |= 0x400;
	pFnAdd_RotatorRotator->iNative = NativeIndex;
	return Add_RotatorRotator_Parms.ReturnValue;
}

struct Core_FloatToByte_Parms
{
	float                                              inputFloat;                                       		// 0x000000 (0x0004)              
	unsigned long                                      bSigned : 1;                                      		// 0x000004 (0x0004) [0x00000001] 
	unsigned char                                      ReturnValue;                                      		// 0x000008 (0x0001)              
};

unsigned char UObject::FloatToByte(float inputFloat,bool bSigned)
{
	static UFieldFunc* pFnFloatToByte = NULL;
	if(!pFnFloatToByte)
		pFnFloatToByte = UObject::FindFunction("Function Core.Object.FloatToByte");

	Core_FloatToByte_Parms FloatToByte_Parms;
	FloatToByte_Parms.inputFloat = inputFloat;
	FloatToByte_Parms.bSigned = bSigned;
	ProcessEvent(pFnFloatToByte,NULL,&FloatToByte_Parms,NULL);
	return FloatToByte_Parms.ReturnValue;
}

struct Core_GreaterEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::GreaterEqual_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnGreaterEqual_FloatFloat = NULL;
	if(!pFnGreaterEqual_FloatFloat)
		pFnGreaterEqual_FloatFloat = UObject::FindFunction("Function Core.Object.GreaterEqual_FloatFloat");

	Core_GreaterEqual_FloatFloat_Parms GreaterEqual_FloatFloat_Parms;
	GreaterEqual_FloatFloat_Parms.A = A;
	GreaterEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnGreaterEqual_FloatFloat->iNative;
	pFnGreaterEqual_FloatFloat->iNative = 0;
	pFnGreaterEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterEqual_FloatFloat,NULL,&GreaterEqual_FloatFloat_Parms,NULL);
	pFnGreaterEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnGreaterEqual_FloatFloat->iNative = NativeIndex;
	return GreaterEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_GreaterGreater_VectorRotator_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::GreaterGreater_VectorRotator(FVector3 A,FRotator B)
{
	static UFieldFunc* pFnGreaterGreater_VectorRotator = NULL;
	if(!pFnGreaterGreater_VectorRotator)
		pFnGreaterGreater_VectorRotator = UObject::FindFunction("Function Core.Object.GreaterGreater_VectorRotator");

	Core_GreaterGreater_VectorRotator_Parms GreaterGreater_VectorRotator_Parms;
	memcpy(&GreaterGreater_VectorRotator_Parms.A,&A,0xC);
	memcpy(&GreaterGreater_VectorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnGreaterGreater_VectorRotator->iNative;
	pFnGreaterGreater_VectorRotator->iNative = 0;
	pFnGreaterGreater_VectorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterGreater_VectorRotator,NULL,&GreaterGreater_VectorRotator_Parms,NULL);
	pFnGreaterGreater_VectorRotator->FunctionFlags |= 0x400;
	pFnGreaterGreater_VectorRotator->iNative = NativeIndex;
	return GreaterGreater_VectorRotator_Parms.ReturnValue;
}

struct Core_RDiff_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	float                                              ReturnValue;                                      		// 0x000018 (0x0004)              
};

float UObject::RDiff(FRotator A,FRotator B)
{
	static UFieldFunc* pFnRDiff = NULL;
	if(!pFnRDiff)
		pFnRDiff = UObject::FindFunction("Function Core.Object.RDiff");

	Core_RDiff_Parms RDiff_Parms;
	memcpy(&RDiff_Parms.A,&A,0xC);
	memcpy(&RDiff_Parms.B,&B,0xC);
	pFnRDiff->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRDiff,NULL,&RDiff_Parms,NULL);
	pFnRDiff->FunctionFlags |= 0x400;
	return RDiff_Parms.ReturnValue;
}

struct Core_Subtract_LinearColorLinearColor_Parms
{
	struct FLinearColor                                A;                                                		// 0x000000 (0x0010)              
	struct FLinearColor                                B;                                                		// 0x000010 (0x0010)              
	struct FLinearColor                                ReturnValue;                                      		// 0x000020 (0x0010)              
};

struct FLinearColor UObject::Subtract_LinearColorLinearColor(struct FLinearColor A,struct FLinearColor B)
{
	static UFieldFunc* pFnSubtract_LinearColorLinearColor = NULL;
	if(!pFnSubtract_LinearColorLinearColor)
		pFnSubtract_LinearColorLinearColor = UObject::FindFunction("Function Core.Object.Subtract_LinearColorLinearColor");

	Core_Subtract_LinearColorLinearColor_Parms Subtract_LinearColorLinearColor_Parms;
	memcpy(&Subtract_LinearColorLinearColor_Parms.A,&A,0x10);
	memcpy(&Subtract_LinearColorLinearColor_Parms.B,&B,0x10);
	ProcessEvent(pFnSubtract_LinearColorLinearColor,NULL,&Subtract_LinearColorLinearColor_Parms,NULL);
	return Subtract_LinearColorLinearColor_Parms.ReturnValue;
}

struct Core_NotEqual_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnNotEqual_VectorVector = NULL;
	if(!pFnNotEqual_VectorVector)
		pFnNotEqual_VectorVector = UObject::FindFunction("Function Core.Object.NotEqual_VectorVector");

	Core_NotEqual_VectorVector_Parms NotEqual_VectorVector_Parms;
	memcpy(&NotEqual_VectorVector_Parms.A,&A,0xC);
	memcpy(&NotEqual_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnNotEqual_VectorVector->iNative;
	pFnNotEqual_VectorVector->iNative = 0;
	pFnNotEqual_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_VectorVector,NULL,&NotEqual_VectorVector_Parms,NULL);
	pFnNotEqual_VectorVector->FunctionFlags |= 0x400;
	pFnNotEqual_VectorVector->iNative = NativeIndex;
	return NotEqual_VectorVector_Parms.ReturnValue;
}

struct Core_Multiply_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Multiply_IntInt(int A,int B)
{
	static UFieldFunc* pFnMultiply_IntInt = NULL;
	if(!pFnMultiply_IntInt)
		pFnMultiply_IntInt = UObject::FindFunction("Function Core.Object.Multiply_IntInt");

	Core_Multiply_IntInt_Parms Multiply_IntInt_Parms;
	Multiply_IntInt_Parms.A = A;
	Multiply_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnMultiply_IntInt->iNative;
	pFnMultiply_IntInt->iNative = 0;
	pFnMultiply_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_IntInt,NULL,&Multiply_IntInt_Parms,NULL);
	pFnMultiply_IntInt->FunctionFlags |= 0x400;
	pFnMultiply_IntInt->iNative = NativeIndex;
	return Multiply_IntInt_Parms.ReturnValue;
}

struct Core_SubtractEqual_RotatorRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FRotator UObject::SubtractEqual_RotatorRotator(FRotator* A,FRotator B)
{
	static UFieldFunc* pFnSubtractEqual_RotatorRotator = NULL;
	if(!pFnSubtractEqual_RotatorRotator)
		pFnSubtractEqual_RotatorRotator = UObject::FindFunction("Function Core.Object.SubtractEqual_RotatorRotator");

	Core_SubtractEqual_RotatorRotator_Parms SubtractEqual_RotatorRotator_Parms;
	memcpy(&SubtractEqual_RotatorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnSubtractEqual_RotatorRotator->iNative;
	pFnSubtractEqual_RotatorRotator->iNative = 0;
	pFnSubtractEqual_RotatorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_RotatorRotator,NULL,&SubtractEqual_RotatorRotator_Parms,NULL);
	pFnSubtractEqual_RotatorRotator->FunctionFlags |= 0x400;
	pFnSubtractEqual_RotatorRotator->iNative = NativeIndex;
	if(A)
		memcpy(A,&SubtractEqual_RotatorRotator_Parms.A,0xC);
	return SubtractEqual_RotatorRotator_Parms.ReturnValue;
}

struct Core_FindDeltaAngle_Parms
{
	float                                              A1;                                               		// 0x000000 (0x0004)              
	float                                              A2;                                               		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
	//float                                              Delta;                                            		// 0x00000C (0x0004)              
};

float UObject::FindDeltaAngle(float A1,float A2)
{
	static UFieldFunc* pFnFindDeltaAngle = NULL;
	if(!pFnFindDeltaAngle)
		pFnFindDeltaAngle = UObject::FindFunction("Function Core.Object.FindDeltaAngle");

	Core_FindDeltaAngle_Parms FindDeltaAngle_Parms;
	FindDeltaAngle_Parms.A1 = A1;
	FindDeltaAngle_Parms.A2 = A2;
	ProcessEvent(pFnFindDeltaAngle,NULL,&FindDeltaAngle_Parms,NULL);
	return FindDeltaAngle_Parms.ReturnValue;
}

struct Core_SubtractEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::SubtractEqual_FloatFloat(float* A,float B)
{
	static UFieldFunc* pFnSubtractEqual_FloatFloat = NULL;
	if(!pFnSubtractEqual_FloatFloat)
		pFnSubtractEqual_FloatFloat = UObject::FindFunction("Function Core.Object.SubtractEqual_FloatFloat");

	Core_SubtractEqual_FloatFloat_Parms SubtractEqual_FloatFloat_Parms;
	SubtractEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnSubtractEqual_FloatFloat->iNative;
	pFnSubtractEqual_FloatFloat->iNative = 0;
	pFnSubtractEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_FloatFloat,NULL,&SubtractEqual_FloatFloat_Parms,NULL);
	pFnSubtractEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnSubtractEqual_FloatFloat->iNative = NativeIndex;
	if(A)
		*A = SubtractEqual_FloatFloat_Parms.A;
	return SubtractEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_Cos_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Cos(float A)
{
	static UFieldFunc* pFnCos = NULL;
	if(!pFnCos)
		pFnCos = UObject::FindFunction("Function Core.Object.Cos");

	Core_Cos_Parms Cos_Parms;
	Cos_Parms.A = A;

	unsigned short NativeIndex = pFnCos->iNative;
	pFnCos->iNative = 0;
	pFnCos->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCos,NULL,&Cos_Parms,NULL);
	pFnCos->FunctionFlags |= 0x400;
	pFnCos->iNative = NativeIndex;
	return Cos_Parms.ReturnValue;
}

struct Core_Multiply_RotatorFloat_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FRotator                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FRotator UObject::Multiply_RotatorFloat(FRotator A,float B)
{
	static UFieldFunc* pFnMultiply_RotatorFloat = NULL;
	if(!pFnMultiply_RotatorFloat)
		pFnMultiply_RotatorFloat = UObject::FindFunction("Function Core.Object.Multiply_RotatorFloat");

	Core_Multiply_RotatorFloat_Parms Multiply_RotatorFloat_Parms;
	memcpy(&Multiply_RotatorFloat_Parms.A,&A,0xC);
	Multiply_RotatorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiply_RotatorFloat->iNative;
	pFnMultiply_RotatorFloat->iNative = 0;
	pFnMultiply_RotatorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_RotatorFloat,NULL,&Multiply_RotatorFloat_Parms,NULL);
	pFnMultiply_RotatorFloat->FunctionFlags |= 0x400;
	pFnMultiply_RotatorFloat->iNative = NativeIndex;
	return Multiply_RotatorFloat_Parms.ReturnValue;
}

struct Core_DAcos_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DAcos(double A)
{
	static UFieldFunc* pFnDAcos = NULL;
	if(!pFnDAcos)
		pFnDAcos = UObject::FindFunction("Function Core.Object.DAcos");

	Core_DAcos_Parms DAcos_Parms;
	DAcos_Parms.A = A;
	pFnDAcos->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDAcos,NULL,&DAcos_Parms,NULL);
	pFnDAcos->FunctionFlags |= 0x400;
	return DAcos_Parms.ReturnValue;
}

struct Core_SubtractEqual_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::SubtractEqual_IntInt(int* A,int B)
{
	static UFieldFunc* pFnSubtractEqual_IntInt = NULL;
	if(!pFnSubtractEqual_IntInt)
		pFnSubtractEqual_IntInt = UObject::FindFunction("Function Core.Object.SubtractEqual_IntInt");

	Core_SubtractEqual_IntInt_Parms SubtractEqual_IntInt_Parms;
	SubtractEqual_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnSubtractEqual_IntInt->iNative;
	pFnSubtractEqual_IntInt->iNative = 0;
	pFnSubtractEqual_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_IntInt,NULL,&SubtractEqual_IntInt_Parms,NULL);
	pFnSubtractEqual_IntInt->FunctionFlags |= 0x400;
	pFnSubtractEqual_IntInt->iNative = NativeIndex;
	if(A)
		*A = SubtractEqual_IntInt_Parms.A;
	return SubtractEqual_IntInt_Parms.ReturnValue;
}

struct Core_Subtract_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::Subtract_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnSubtract_FloatFloat = NULL;
	if(!pFnSubtract_FloatFloat)
		pFnSubtract_FloatFloat = UObject::FindFunction("Function Core.Object.Subtract_FloatFloat");

	Core_Subtract_FloatFloat_Parms Subtract_FloatFloat_Parms;
	Subtract_FloatFloat_Parms.A = A;
	Subtract_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnSubtract_FloatFloat->iNative;
	pFnSubtract_FloatFloat->iNative = 0;
	pFnSubtract_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_FloatFloat,NULL,&Subtract_FloatFloat_Parms,NULL);
	pFnSubtract_FloatFloat->FunctionFlags |= 0x400;
	pFnSubtract_FloatFloat->iNative = NativeIndex;
	return Subtract_FloatFloat_Parms.ReturnValue;
}

struct Core_Multiply_ColorFloat_Parms
{
	DWORD                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	DWORD                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

DWORD UObject::Multiply_ColorFloat(DWORD A,float B)
{
	static UFieldFunc* pFnMultiply_ColorFloat = NULL;
	if(!pFnMultiply_ColorFloat)
		pFnMultiply_ColorFloat = UObject::FindFunction("Function Core.Object.Multiply_ColorFloat");

	Core_Multiply_ColorFloat_Parms Multiply_ColorFloat_Parms;
	memcpy(&Multiply_ColorFloat_Parms.A,&A,0x4);
	Multiply_ColorFloat_Parms.B = B;
	ProcessEvent(pFnMultiply_ColorFloat,NULL,&Multiply_ColorFloat_Parms,NULL);
	return Multiply_ColorFloat_Parms.ReturnValue;
}

struct Core_IsChildState_Parms
{
	struct FName                                       TestState;                                        		// 0x000000 (0x0008)              
	struct FName                                       TestParentState;                                  		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::IsChildState(struct FName TestState,struct FName TestParentState)
{
	static UFieldFunc* pFnIsChildState = NULL;
	if(!pFnIsChildState)
		pFnIsChildState = UObject::FindFunction("Function Core.Object.IsChildState");

	Core_IsChildState_Parms IsChildState_Parms;
	memcpy(&IsChildState_Parms.TestState,&TestState,0x8);
	memcpy(&IsChildState_Parms.TestParentState,&TestParentState,0x8);
	pFnIsChildState->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsChildState,NULL,&IsChildState_Parms,NULL);
	pFnIsChildState->FunctionFlags |= 0x400;
	return IsChildState_Parms.ReturnValue;
}

struct Core_DAtan_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::DAtan(double A,double B)
{
	static UFieldFunc* pFnDAtan = NULL;
	if(!pFnDAtan)
		pFnDAtan = UObject::FindFunction("Function Core.Object.DAtan");

	Core_DAtan_Parms DAtan_Parms;
	DAtan_Parms.A = A;
	DAtan_Parms.B = B;

	unsigned short NativeIndex = pFnDAtan->iNative;
	pFnDAtan->iNative = 0;
	pFnDAtan->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDAtan,NULL,&DAtan_Parms,NULL);
	pFnDAtan->FunctionFlags |= 0x400;
	pFnDAtan->iNative = NativeIndex;
	return DAtan_Parms.ReturnValue;
}

struct Core_AddAdd_Int_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::AddAdd_Int(int* A)
{
	static UFieldFunc* pFnAddAdd_Int = NULL;
	if(!pFnAddAdd_Int)
		pFnAddAdd_Int = UObject::FindFunction("Function Core.Object.AddAdd_Int");

	Core_AddAdd_Int_Parms AddAdd_Int_Parms;

	unsigned short NativeIndex = pFnAddAdd_Int->iNative;
	pFnAddAdd_Int->iNative = 0;
	pFnAddAdd_Int->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddAdd_Int,NULL,&AddAdd_Int_Parms,NULL);
	pFnAddAdd_Int->FunctionFlags |= 0x400;
	pFnAddAdd_Int->iNative = NativeIndex;
	if(A)
		*A = AddAdd_Int_Parms.A;
	return AddAdd_Int_Parms.ReturnValue;
}

struct Core_AddAdd_Byte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000001 (0x0001)              
};

unsigned char UObject::AddAdd_Byte(unsigned char* A)
{
	static UFieldFunc* pFnAddAdd_Byte = NULL;
	if(!pFnAddAdd_Byte)
		pFnAddAdd_Byte = UObject::FindFunction("Function Core.Object.AddAdd_Byte");

	Core_AddAdd_Byte_Parms AddAdd_Byte_Parms;

	unsigned short NativeIndex = pFnAddAdd_Byte->iNative;
	pFnAddAdd_Byte->iNative = 0;
	pFnAddAdd_Byte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddAdd_Byte,NULL,&AddAdd_Byte_Parms,NULL);
	pFnAddAdd_Byte->FunctionFlags |= 0x400;
	pFnAddAdd_Byte->iNative = NativeIndex;
	if(A)
		*A = AddAdd_Byte_Parms.A;
	return AddAdd_Byte_Parms.ReturnValue;
}

struct Core_FInterpTo_Parms
{
	float                                              Current;                                          		// 0x000000 (0x0004)              
	float                                              Target;                                           		// 0x000004 (0x0004)              
	float                                              DeltaTime;                                        		// 0x000008 (0x0004)              
	float                                              InterpSpeed;                                      		// 0x00000C (0x0004)              
	float                                              ReturnValue;                                      		// 0x000010 (0x0004)              
};

float UObject::FInterpTo(float Current,float Target,float DeltaTime,float InterpSpeed)
{
	static UFieldFunc* pFnFInterpTo = NULL;
	if(!pFnFInterpTo)
		pFnFInterpTo = UObject::FindFunction("Function Core.Object.FInterpTo");

	Core_FInterpTo_Parms FInterpTo_Parms;
	FInterpTo_Parms.Current = Current;
	FInterpTo_Parms.Target = Target;
	FInterpTo_Parms.DeltaTime = DeltaTime;
	FInterpTo_Parms.InterpSpeed = InterpSpeed;
	pFnFInterpTo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFInterpTo,NULL,&FInterpTo_Parms,NULL);
	pFnFInterpTo->FunctionFlags |= 0x400;
	return FInterpTo_Parms.ReturnValue;
}

struct Core_NotEqual_InterfaceInterface_Parms
{
	class UInterface*                                  A;                                                		// 0x000000 (0x0008)              
	class UInterface*                                  B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_InterfaceInterface(class UInterface* A,class UInterface* B)
{
	static UFieldFunc* pFnNotEqual_InterfaceInterface = NULL;
	if(!pFnNotEqual_InterfaceInterface)
		pFnNotEqual_InterfaceInterface = UObject::FindFunction("Function Core.Object.NotEqual_InterfaceInterface");

	Core_NotEqual_InterfaceInterface_Parms NotEqual_InterfaceInterface_Parms;
	NotEqual_InterfaceInterface_Parms.A = A;
	NotEqual_InterfaceInterface_Parms.B = B;
	pFnNotEqual_InterfaceInterface->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_InterfaceInterface,NULL,&NotEqual_InterfaceInterface_Parms,NULL);
	pFnNotEqual_InterfaceInterface->FunctionFlags |= 0x400;
	return NotEqual_InterfaceInterface_Parms.ReturnValue;
}

struct Core_Multiply_FloatColor_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	DWORD                                              B;                                                		// 0x000004 (0x0004)              
	DWORD                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

DWORD UObject::Multiply_FloatColor(float A,DWORD B)
{
	static UFieldFunc* pFnMultiply_FloatColor = NULL;
	if(!pFnMultiply_FloatColor)
		pFnMultiply_FloatColor = UObject::FindFunction("Function Core.Object.Multiply_FloatColor");

	Core_Multiply_FloatColor_Parms Multiply_FloatColor_Parms;
	Multiply_FloatColor_Parms.A = A;
	memcpy(&Multiply_FloatColor_Parms.B,&B,0x4);
	ProcessEvent(pFnMultiply_FloatColor,NULL,&Multiply_FloatColor_Parms,NULL);
	return Multiply_FloatColor_Parms.ReturnValue;
}

struct Core_MultiplyMultiply_FloatFloat_Parms
{
	float                                              Base;                                             		// 0x000000 (0x0004)              
	float                                              Exp;                                              		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::MultiplyMultiply_FloatFloat(float Base,float Exp)
{
	static UFieldFunc* pFnMultiplyMultiply_FloatFloat = NULL;
	if(!pFnMultiplyMultiply_FloatFloat)
		pFnMultiplyMultiply_FloatFloat = UObject::FindFunction("Function Core.Object.MultiplyMultiply_FloatFloat");

	Core_MultiplyMultiply_FloatFloat_Parms MultiplyMultiply_FloatFloat_Parms;
	MultiplyMultiply_FloatFloat_Parms.Base = Base;
	MultiplyMultiply_FloatFloat_Parms.Exp = Exp;

	unsigned short NativeIndex = pFnMultiplyMultiply_FloatFloat->iNative;
	pFnMultiplyMultiply_FloatFloat->iNative = 0;
	pFnMultiplyMultiply_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyMultiply_FloatFloat,NULL,&MultiplyMultiply_FloatFloat_Parms,NULL);
	pFnMultiplyMultiply_FloatFloat->FunctionFlags |= 0x400;
	pFnMultiplyMultiply_FloatFloat->iNative = NativeIndex;
	return MultiplyMultiply_FloatFloat_Parms.ReturnValue;
}

struct Core_FInterpEaseOut_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              Alpha;                                            		// 0x000008 (0x0004)              
	float                                              Exp;                                              		// 0x00000C (0x0004)              
	float                                              ReturnValue;                                      		// 0x000010 (0x0004)              
};

float UObject::FInterpEaseOut(float A,float B,float Alpha,float Exp)
{
	static UFieldFunc* pFnFInterpEaseOut = NULL;
	if(!pFnFInterpEaseOut)
		pFnFInterpEaseOut = UObject::FindFunction("Function Core.Object.FInterpEaseOut");

	Core_FInterpEaseOut_Parms FInterpEaseOut_Parms;
	FInterpEaseOut_Parms.A = A;
	FInterpEaseOut_Parms.B = B;
	FInterpEaseOut_Parms.Alpha = Alpha;
	FInterpEaseOut_Parms.Exp = Exp;
	ProcessEvent(pFnFInterpEaseOut,NULL,&FInterpEaseOut_Parms,NULL);
	return FInterpEaseOut_Parms.ReturnValue;
}

struct Core_FInterpEaseInOut_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              Alpha;                                            		// 0x000008 (0x0004)              
	float                                              Exp;                                              		// 0x00000C (0x0004)              
	float                                              ReturnValue;                                      		// 0x000010 (0x0004)              
};

float UObject::FInterpEaseInOut(float A,float B,float Alpha,float Exp)
{
	static UFieldFunc* pFnFInterpEaseInOut = NULL;
	if(!pFnFInterpEaseInOut)
		pFnFInterpEaseInOut = UObject::FindFunction("Function Core.Object.FInterpEaseInOut");

	Core_FInterpEaseInOut_Parms FInterpEaseInOut_Parms;
	FInterpEaseInOut_Parms.A = A;
	FInterpEaseInOut_Parms.B = B;
	FInterpEaseInOut_Parms.Alpha = Alpha;
	FInterpEaseInOut_Parms.Exp = Exp;
	pFnFInterpEaseInOut->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFInterpEaseInOut,NULL,&FInterpEaseInOut_Parms,NULL);
	pFnFInterpEaseInOut->FunctionFlags |= 0x400;
	return FInterpEaseInOut_Parms.ReturnValue;
}

struct Core_Multiply_VectorFloat_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FVector3                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FVector3 UObject::Multiply_VectorFloat(FVector3 A,float B)
{
	static UFieldFunc* pFnMultiply_VectorFloat = NULL;
	if(!pFnMultiply_VectorFloat)
		pFnMultiply_VectorFloat = UObject::FindFunction("Function Core.Object.Multiply_VectorFloat");

	Core_Multiply_VectorFloat_Parms Multiply_VectorFloat_Parms;
	memcpy(&Multiply_VectorFloat_Parms.A,&A,0xC);
	Multiply_VectorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiply_VectorFloat->iNative;
	pFnMultiply_VectorFloat->iNative = 0;
	pFnMultiply_VectorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_VectorFloat,NULL,&Multiply_VectorFloat_Parms,NULL);
	pFnMultiply_VectorFloat->FunctionFlags |= 0x400;
	pFnMultiply_VectorFloat->iNative = NativeIndex;
	return Multiply_VectorFloat_Parms.ReturnValue;
}

struct Core_VSize_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::VSize(FVector3 A)
{
	static UFieldFunc* pFnVSize = NULL;
	if(!pFnVSize)
		pFnVSize = UObject::FindFunction("Function Core.Object.VSize");

	Core_VSize_Parms VSize_Parms;
	memcpy(&VSize_Parms.A,&A,0xC);

	unsigned short NativeIndex = pFnVSize->iNative;
	pFnVSize->iNative = 0;
	pFnVSize->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVSize,NULL,&VSize_Parms,NULL);
	pFnVSize->FunctionFlags |= 0x400;
	pFnVSize->iNative = NativeIndex;
	return VSize_Parms.ReturnValue;
}

struct Core_Loge_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Loge(float A)
{
	static UFieldFunc* pFnLoge = NULL;
	if(!pFnLoge)
		pFnLoge = UObject::FindFunction("Function Core.Object.Loge");

	Core_Loge_Parms Loge_Parms;
	Loge_Parms.A = A;

	unsigned short NativeIndex = pFnLoge->iNative;
	pFnLoge->iNative = 0;
	pFnLoge->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLoge,NULL,&Loge_Parms,NULL);
	pFnLoge->FunctionFlags |= 0x400;
	pFnLoge->iNative = NativeIndex;
	return Loge_Parms.ReturnValue;
}

struct Core_Subtract_RotatorRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FRotator UObject::Subtract_RotatorRotator(FRotator A,FRotator B)
{
	static UFieldFunc* pFnSubtract_RotatorRotator = NULL;
	if(!pFnSubtract_RotatorRotator)
		pFnSubtract_RotatorRotator = UObject::FindFunction("Function Core.Object.Subtract_RotatorRotator");

	Core_Subtract_RotatorRotator_Parms Subtract_RotatorRotator_Parms;
	memcpy(&Subtract_RotatorRotator_Parms.A,&A,0xC);
	memcpy(&Subtract_RotatorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnSubtract_RotatorRotator->iNative;
	pFnSubtract_RotatorRotator->iNative = 0;
	pFnSubtract_RotatorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_RotatorRotator,NULL,&Subtract_RotatorRotator_Parms,NULL);
	pFnSubtract_RotatorRotator->FunctionFlags |= 0x400;
	pFnSubtract_RotatorRotator->iNative = NativeIndex;
	return Subtract_RotatorRotator_Parms.ReturnValue;
}

struct Core_FPctByRange_Parms
{
	float                                              Value;                                            		// 0x000000 (0x0004)              
	float                                              InMin;                                            		// 0x000004 (0x0004)              
	float                                              InMax;                                            		// 0x000008 (0x0004)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::FPctByRange(float Value,float InMin,float InMax)
{
	static UFieldFunc* pFnFPctByRange = NULL;
	if(!pFnFPctByRange)
		pFnFPctByRange = UObject::FindFunction("Function Core.Object.FPctByRange");

	Core_FPctByRange_Parms FPctByRange_Parms;
	FPctByRange_Parms.Value = Value;
	FPctByRange_Parms.InMin = InMin;
	FPctByRange_Parms.InMax = InMax;
	ProcessEvent(pFnFPctByRange,NULL,&FPctByRange_Parms,NULL);
	return FPctByRange_Parms.ReturnValue;
}

struct Core_AddEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::AddEqual_FloatFloat(float* A,float B)
{
	static UFieldFunc* pFnAddEqual_FloatFloat = NULL;
	if(!pFnAddEqual_FloatFloat)
		pFnAddEqual_FloatFloat = UObject::FindFunction("Function Core.Object.AddEqual_FloatFloat");

	Core_AddEqual_FloatFloat_Parms AddEqual_FloatFloat_Parms;
	AddEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnAddEqual_FloatFloat->iNative;
	pFnAddEqual_FloatFloat->iNative = 0;
	pFnAddEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddEqual_FloatFloat,NULL,&AddEqual_FloatFloat_Parms,NULL);
	pFnAddEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnAddEqual_FloatFloat->iNative = NativeIndex;
	if(A)
		*A = AddEqual_FloatFloat_Parms.A;
	return AddEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_EndState_Parms
{
	struct FName                                       NextStateName;                                    		// 0x000000 (0x0008)              
};

void UObject::EndState(struct FName NextStateName)
{
	static UFieldFunc* pFnEndState = NULL;
	if(!pFnEndState)
		pFnEndState = UObject::FindFunction("Function Core.Object.EndState");

	Core_EndState_Parms EndState_Parms;
	memcpy(&EndState_Parms.NextStateName,&NextStateName,0x8);
	ProcessEvent(pFnEndState,NULL,&EndState_Parms,NULL);
}

struct Core_Multiply_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::Multiply_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnMultiply_DoubleDouble = NULL;
	if(!pFnMultiply_DoubleDouble)
		pFnMultiply_DoubleDouble = UObject::FindFunction("Function Core.Object.Multiply_DoubleDouble");

	Core_Multiply_DoubleDouble_Parms Multiply_DoubleDouble_Parms;
	Multiply_DoubleDouble_Parms.A = A;
	Multiply_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnMultiply_DoubleDouble->iNative;
	pFnMultiply_DoubleDouble->iNative = 0;
	pFnMultiply_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_DoubleDouble,NULL,&Multiply_DoubleDouble_Parms,NULL);
	pFnMultiply_DoubleDouble->FunctionFlags |= 0x400;
	pFnMultiply_DoubleDouble->iNative = NativeIndex;
	return Multiply_DoubleDouble_Parms.ReturnValue;
}

struct Core_GetPackageName_Parms
{
	struct FName                                       ReturnValue;                                      		// 0x000000 (0x0008)              
	//class UObject*                                     O;                                                		// 0x000008 (0x0004)              
};

struct FName UObject::GetPackageName()
{
	static UFieldFunc* pFnGetPackageName = NULL;
	if(!pFnGetPackageName)
		pFnGetPackageName = UObject::FindFunction("Function Core.Object.GetPackageName");

	Core_GetPackageName_Parms GetPackageName_Parms;
	ProcessEvent(pFnGetPackageName,NULL,&GetPackageName_Parms,NULL);
	return GetPackageName_Parms.ReturnValue;
}

struct Core_PointInBox_Parms
{
	FVector3                                           Point;                                            		// 0x000000 (0x000C)              
	FVector3                                           Location;                                         		// 0x00000C (0x000C)              
	FVector3                                           Extent;                                           		// 0x000018 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000024 (0x0004) [0x00000001] 
	//FVector3                                           MinBox;                                           		// 0x000028 (0x000C)              
	//FVector3                                           MaxBox;                                           		// 0x000034 (0x000C)              
};

bool UObject::PointInBox(FVector3 Point,FVector3 Location,FVector3 Extent)
{
	static UFieldFunc* pFnPointInBox = NULL;
	if(!pFnPointInBox)
		pFnPointInBox = UObject::FindFunction("Function Core.Object.PointInBox");

	Core_PointInBox_Parms PointInBox_Parms;
	memcpy(&PointInBox_Parms.Point,&Point,0xC);
	memcpy(&PointInBox_Parms.Location,&Location,0xC);
	memcpy(&PointInBox_Parms.Extent,&Extent,0xC);
	ProcessEvent(pFnPointInBox,NULL,&PointInBox_Parms,NULL);
	return PointInBox_Parms.ReturnValue;
}

struct Core_Less_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::Less_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnLess_FloatFloat = NULL;
	if(!pFnLess_FloatFloat)
		pFnLess_FloatFloat = UObject::FindFunction("Function Core.Object.Less_FloatFloat");

	Core_Less_FloatFloat_Parms Less_FloatFloat_Parms;
	Less_FloatFloat_Parms.A = A;
	Less_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnLess_FloatFloat->iNative;
	pFnLess_FloatFloat->iNative = 0;
	pFnLess_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLess_FloatFloat,NULL,&Less_FloatFloat_Parms,NULL);
	pFnLess_FloatFloat->FunctionFlags |= 0x400;
	pFnLess_FloatFloat->iNative = NativeIndex;
	return Less_FloatFloat_Parms.ReturnValue;
}

struct Core_Subtract_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::Subtract_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnSubtract_DoubleDouble = NULL;
	if(!pFnSubtract_DoubleDouble)
		pFnSubtract_DoubleDouble = UObject::FindFunction("Function Core.Object.Subtract_DoubleDouble");

	Core_Subtract_DoubleDouble_Parms Subtract_DoubleDouble_Parms;
	Subtract_DoubleDouble_Parms.A = A;
	Subtract_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnSubtract_DoubleDouble->iNative;
	pFnSubtract_DoubleDouble->iNative = 0;
	pFnSubtract_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_DoubleDouble,NULL,&Subtract_DoubleDouble_Parms,NULL);
	pFnSubtract_DoubleDouble->FunctionFlags |= 0x400;
	pFnSubtract_DoubleDouble->iNative = NativeIndex;
	return Subtract_DoubleDouble_Parms.ReturnValue;
}

struct Core_MultiplyEqual_ByteFloat_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000008 (0x0001)              
};

unsigned char UObject::MultiplyEqual_ByteFloat(unsigned char* A,float B)
{
	static UFieldFunc* pFnMultiplyEqual_ByteFloat = NULL;
	if(!pFnMultiplyEqual_ByteFloat)
		pFnMultiplyEqual_ByteFloat = UObject::FindFunction("Function Core.Object.MultiplyEqual_ByteFloat");

	Core_MultiplyEqual_ByteFloat_Parms MultiplyEqual_ByteFloat_Parms;
	MultiplyEqual_ByteFloat_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_ByteFloat->iNative;
	pFnMultiplyEqual_ByteFloat->iNative = 0;
	pFnMultiplyEqual_ByteFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_ByteFloat,NULL,&MultiplyEqual_ByteFloat_Parms,NULL);
	pFnMultiplyEqual_ByteFloat->FunctionFlags |= 0x400;
	pFnMultiplyEqual_ByteFloat->iNative = NativeIndex;
	if(A)
		*A = MultiplyEqual_ByteFloat_Parms.A;
	return MultiplyEqual_ByteFloat_Parms.ReturnValue;
}

struct Core_Less_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::Less_IntInt(int A,int B)
{
	static UFieldFunc* pFnLess_IntInt = NULL;
	if(!pFnLess_IntInt)
		pFnLess_IntInt = UObject::FindFunction("Function Core.Object.Less_IntInt");

	Core_Less_IntInt_Parms Less_IntInt_Parms;
	Less_IntInt_Parms.A = A;
	Less_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnLess_IntInt->iNative;
	pFnLess_IntInt->iNative = 0;
	pFnLess_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLess_IntInt,NULL,&Less_IntInt_Parms,NULL);
	pFnLess_IntInt->FunctionFlags |= 0x400;
	pFnLess_IntInt->iNative = NativeIndex;
	return Less_IntInt_Parms.ReturnValue;
}

struct Core_ToHex_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UObject::ToHex(int A)
{
	static UFieldFunc* pFnToHex = NULL;
	if(!pFnToHex)
		pFnToHex = UObject::FindFunction("Function Core.Object.ToHex");

	Core_ToHex_Parms ToHex_Parms;
	ToHex_Parms.A = A;
	pFnToHex->FunctionFlags |= ~0x400;
	ProcessEvent(pFnToHex,NULL,&ToHex_Parms,NULL);
	pFnToHex->FunctionFlags |= 0x400;
	return ToHex_Parms.ReturnValue;
}

struct Core_TransformVectorByRotation_Parms
{
	FRotator                                           SourceRotation;                                   		// 0x000000 (0x000C)              
	FVector3                                           SourceVector;                                     		// 0x00000C (0x000C)              
	unsigned long                                      bInverse : 1;                                     		// 0x000018 (0x0004) [0x00000001] 
	FVector3                                           ReturnValue;                                      		// 0x00001C (0x000C)              
};

FVector3 UObject::TransformVectorByRotation(FRotator SourceRotation,FVector3 SourceVector,bool bInverse)
{
	static UFieldFunc* pFnTransformVectorByRotation = NULL;
	if(!pFnTransformVectorByRotation)
		pFnTransformVectorByRotation = UObject::FindFunction("Function Core.Object.TransformVectorByRotation");

	Core_TransformVectorByRotation_Parms TransformVectorByRotation_Parms;
	memcpy(&TransformVectorByRotation_Parms.SourceRotation,&SourceRotation,0xC);
	memcpy(&TransformVectorByRotation_Parms.SourceVector,&SourceVector,0xC);
	TransformVectorByRotation_Parms.bInverse = bInverse;
	pFnTransformVectorByRotation->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTransformVectorByRotation,NULL,&TransformVectorByRotation_Parms,NULL);
	pFnTransformVectorByRotation->FunctionFlags |= 0x400;
	return TransformVectorByRotation_Parms.ReturnValue;
}

struct Core_Atan_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::Atan(float A,float B)
{
	static UFieldFunc* pFnAtan = NULL;
	if(!pFnAtan)
		pFnAtan = UObject::FindFunction("Function Core.Object.Atan");

	Core_Atan_Parms Atan_Parms;
	Atan_Parms.A = A;
	Atan_Parms.B = B;

	unsigned short NativeIndex = pFnAtan->iNative;
	pFnAtan->iNative = 0;
	pFnAtan->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAtan,NULL,&Atan_Parms,NULL);
	pFnAtan->FunctionFlags |= 0x400;
	pFnAtan->iNative = NativeIndex;
	return Atan_Parms.ReturnValue;
}

struct Core_Greater_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::Greater_IntInt(int A,int B)
{
	static UFieldFunc* pFnGreater_IntInt = NULL;
	if(!pFnGreater_IntInt)
		pFnGreater_IntInt = UObject::FindFunction("Function Core.Object.Greater_IntInt");

	Core_Greater_IntInt_Parms Greater_IntInt_Parms;
	Greater_IntInt_Parms.A = A;
	Greater_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnGreater_IntInt->iNative;
	pFnGreater_IntInt->iNative = 0;
	pFnGreater_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreater_IntInt,NULL,&Greater_IntInt_Parms,NULL);
	pFnGreater_IntInt->FunctionFlags |= 0x400;
	pFnGreater_IntInt->iNative = NativeIndex;
	return Greater_IntInt_Parms.ReturnValue;
}

struct Core_SubtractSubtract_PreByte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000001 (0x0001)              
};

unsigned char UObject::SubtractSubtract_PreByte(unsigned char* A)
{
	static UFieldFunc* pFnSubtractSubtract_PreByte = NULL;
	if(!pFnSubtractSubtract_PreByte)
		pFnSubtractSubtract_PreByte = UObject::FindFunction("Function Core.Object.SubtractSubtract_PreByte");

	Core_SubtractSubtract_PreByte_Parms SubtractSubtract_PreByte_Parms;

	unsigned short NativeIndex = pFnSubtractSubtract_PreByte->iNative;
	pFnSubtractSubtract_PreByte->iNative = 0;
	pFnSubtractSubtract_PreByte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractSubtract_PreByte,NULL,&SubtractSubtract_PreByte_Parms,NULL);
	pFnSubtractSubtract_PreByte->FunctionFlags |= 0x400;
	pFnSubtractSubtract_PreByte->iNative = NativeIndex;
	if(A)
		*A = SubtractSubtract_PreByte_Parms.A;
	return SubtractSubtract_PreByte_Parms.ReturnValue;
}

struct Core_DivideEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::DivideEqual_DoubleDouble(double* A,double B)
{
	static UFieldFunc* pFnDivideEqual_DoubleDouble = NULL;
	if(!pFnDivideEqual_DoubleDouble)
		pFnDivideEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.DivideEqual_DoubleDouble");

	Core_DivideEqual_DoubleDouble_Parms DivideEqual_DoubleDouble_Parms;
	DivideEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnDivideEqual_DoubleDouble->iNative;
	pFnDivideEqual_DoubleDouble->iNative = 0;
	pFnDivideEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivideEqual_DoubleDouble,NULL,&DivideEqual_DoubleDouble_Parms,NULL);
	pFnDivideEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnDivideEqual_DoubleDouble->iNative = NativeIndex;
	if(A)
		*A = DivideEqual_DoubleDouble_Parms.A;
	return DivideEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_At_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UObject::At_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnAt_StrStr = NULL;
	if(!pFnAt_StrStr)
		pFnAt_StrStr = UObject::FindFunction("Function Core.Object.At_StrStr");

	Core_At_StrStr_Parms At_StrStr_Parms;
	memcpy(&At_StrStr_Parms.A,&A,0xC);
	memcpy(&At_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnAt_StrStr->iNative;
	pFnAt_StrStr->iNative = 0;
	pFnAt_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAt_StrStr,NULL,&At_StrStr_Parms,NULL);
	pFnAt_StrStr->FunctionFlags |= 0x400;
	pFnAt_StrStr->iNative = NativeIndex;
	return At_StrStr_Parms.ReturnValue;
}

struct Core_LogInternal_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	struct FName                                       Tag;                                              		// 0x00000C (0x0008)              
};

void UObject::LogInternal(struct FString S,struct FName Tag)
{
	static UFieldFunc* pFnLogInternal = NULL;
	if(!pFnLogInternal)
		pFnLogInternal = UObject::FindFunction("Function Core.Object.LogInternal");

	Core_LogInternal_Parms LogInternal_Parms;
	memcpy(&LogInternal_Parms.S,&S,0xC);
	memcpy(&LogInternal_Parms.Tag,&Tag,0x8);

	unsigned short NativeIndex = pFnLogInternal->iNative;
	pFnLogInternal->iNative = 0;
	pFnLogInternal->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLogInternal,NULL,&LogInternal_Parms,NULL);
	pFnLogInternal->FunctionFlags |= 0x400;
	pFnLogInternal->iNative = NativeIndex;
}

struct Core_AddEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::AddEqual_DoubleDouble(double* A,double B)
{
	static UFieldFunc* pFnAddEqual_DoubleDouble = NULL;
	if(!pFnAddEqual_DoubleDouble)
		pFnAddEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.AddEqual_DoubleDouble");

	Core_AddEqual_DoubleDouble_Parms AddEqual_DoubleDouble_Parms;
	AddEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnAddEqual_DoubleDouble->iNative;
	pFnAddEqual_DoubleDouble->iNative = 0;
	pFnAddEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddEqual_DoubleDouble,NULL,&AddEqual_DoubleDouble_Parms,NULL);
	pFnAddEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnAddEqual_DoubleDouble->iNative = NativeIndex;
	if(A)
		*A = AddEqual_DoubleDouble_Parms.A;
	return AddEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_Complement_PreInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::Complement_PreInt(int A)
{
	static UFieldFunc* pFnComplement_PreInt = NULL;
	if(!pFnComplement_PreInt)
		pFnComplement_PreInt = UObject::FindFunction("Function Core.Object.Complement_PreInt");

	Core_Complement_PreInt_Parms Complement_PreInt_Parms;
	Complement_PreInt_Parms.A = A;

	unsigned short NativeIndex = pFnComplement_PreInt->iNative;
	pFnComplement_PreInt->iNative = 0;
	pFnComplement_PreInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnComplement_PreInt,NULL,&Complement_PreInt_Parms,NULL);
	pFnComplement_PreInt->FunctionFlags |= 0x400;
	pFnComplement_PreInt->iNative = NativeIndex;
	return Complement_PreInt_Parms.ReturnValue;
}

struct Core_EqualEqual_NameName_Parms
{
	struct FName                                       A;                                                		// 0x000000 (0x0008)              
	struct FName                                       B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_NameName(struct FName A,struct FName B)
{
	static UFieldFunc* pFnEqualEqual_NameName = NULL;
	if(!pFnEqualEqual_NameName)
		pFnEqualEqual_NameName = UObject::FindFunction("Function Core.Object.EqualEqual_NameName");

	Core_EqualEqual_NameName_Parms EqualEqual_NameName_Parms;
	memcpy(&EqualEqual_NameName_Parms.A,&A,0x8);
	memcpy(&EqualEqual_NameName_Parms.B,&B,0x8);

	unsigned short NativeIndex = pFnEqualEqual_NameName->iNative;
	pFnEqualEqual_NameName->iNative = 0;
	pFnEqualEqual_NameName->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_NameName,NULL,&EqualEqual_NameName_Parms,NULL);
	pFnEqualEqual_NameName->FunctionFlags |= 0x400;
	pFnEqualEqual_NameName->iNative = NativeIndex;
	return EqualEqual_NameName_Parms.ReturnValue;
}

struct Core_Multiply_FloatRotator_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	FRotator                                           B;                                                		// 0x000004 (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FRotator UObject::Multiply_FloatRotator(float A,FRotator B)
{
	static UFieldFunc* pFnMultiply_FloatRotator = NULL;
	if(!pFnMultiply_FloatRotator)
		pFnMultiply_FloatRotator = UObject::FindFunction("Function Core.Object.Multiply_FloatRotator");

	Core_Multiply_FloatRotator_Parms Multiply_FloatRotator_Parms;
	Multiply_FloatRotator_Parms.A = A;
	memcpy(&Multiply_FloatRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnMultiply_FloatRotator->iNative;
	pFnMultiply_FloatRotator->iNative = 0;
	pFnMultiply_FloatRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_FloatRotator,NULL,&Multiply_FloatRotator_Parms,NULL);
	pFnMultiply_FloatRotator->FunctionFlags |= 0x400;
	pFnMultiply_FloatRotator->iNative = NativeIndex;
	return Multiply_FloatRotator_Parms.ReturnValue;
}

struct Core_DLoge_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DLoge(double A)
{
	static UFieldFunc* pFnDLoge = NULL;
	if(!pFnDLoge)
		pFnDLoge = UObject::FindFunction("Function Core.Object.DLoge");

	Core_DLoge_Parms DLoge_Parms;
	DLoge_Parms.A = A;

	unsigned short NativeIndex = pFnDLoge->iNative;
	pFnDLoge->iNative = 0;
	pFnDLoge->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDLoge,NULL,&DLoge_Parms,NULL);
	pFnDLoge->FunctionFlags |= 0x400;
	pFnDLoge->iNative = NativeIndex;
	return DLoge_Parms.ReturnValue;
}

struct Core_GreaterGreaterGreater_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::GreaterGreaterGreater_IntInt(int A,int B)
{
	static UFieldFunc* pFnGreaterGreaterGreater_IntInt = NULL;
	if(!pFnGreaterGreaterGreater_IntInt)
		pFnGreaterGreaterGreater_IntInt = UObject::FindFunction("Function Core.Object.GreaterGreaterGreater_IntInt");

	Core_GreaterGreaterGreater_IntInt_Parms GreaterGreaterGreater_IntInt_Parms;
	GreaterGreaterGreater_IntInt_Parms.A = A;
	GreaterGreaterGreater_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnGreaterGreaterGreater_IntInt->iNative;
	pFnGreaterGreaterGreater_IntInt->iNative = 0;
	pFnGreaterGreaterGreater_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterGreaterGreater_IntInt,NULL,&GreaterGreaterGreater_IntInt_Parms,NULL);
	pFnGreaterGreaterGreater_IntInt->FunctionFlags |= 0x400;
	pFnGreaterGreaterGreater_IntInt->iNative = NativeIndex;
	return GreaterGreaterGreater_IntInt_Parms.ReturnValue;
}

struct Core_DRound_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::DRound(double A)
{
	static UFieldFunc* pFnDRound = NULL;
	if(!pFnDRound)
		pFnDRound = UObject::FindFunction("Function Core.Object.DRound");

	Core_DRound_Parms DRound_Parms;
	DRound_Parms.A = A;

	unsigned short NativeIndex = pFnDRound->iNative;
	pFnDRound->iNative = 0;
	pFnDRound->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDRound,NULL,&DRound_Parms,NULL);
	pFnDRound->FunctionFlags |= 0x400;
	pFnDRound->iNative = NativeIndex;
	return DRound_Parms.ReturnValue;
}

struct Core_QuatProduct_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	struct FQuat                                       B;                                                		// 0x000010 (0x0010)              
	struct FQuat                                       ReturnValue;                                      		// 0x000020 (0x0010)              
};

struct FQuat UObject::QuatProduct(struct FQuat A,struct FQuat B)
{
	static UFieldFunc* pFnQuatProduct = NULL;
	if(!pFnQuatProduct)
		pFnQuatProduct = UObject::FindFunction("Function Core.Object.QuatProduct");

	Core_QuatProduct_Parms QuatProduct_Parms;
	memcpy(&QuatProduct_Parms.A,&A,0x10);
	memcpy(&QuatProduct_Parms.B,&B,0x10);
	pFnQuatProduct->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatProduct,NULL,&QuatProduct_Parms,NULL);
	pFnQuatProduct->FunctionFlags |= 0x400;
	return QuatProduct_Parms.ReturnValue;
}

struct Core_ClampRotAxis_Parms
{
	int                                                ViewAxis;                                         		// 0x000000 (0x0004)              
	int                                                out_DeltaViewAxis;                                		// 0x000004 (0x0004)              
	int                                                MaxLimit;                                         		// 0x000008 (0x0004)              
	int                                                MinLimit;                                         		// 0x00000C (0x0004)              
	//int                                                DesiredViewAxis;                                  		// 0x000010 (0x0004)              
};

void UObject::ClampRotAxis(int ViewAxis,int* out_DeltaViewAxis,int MaxLimit,int MinLimit)
{
	static UFieldFunc* pFnClampRotAxis = NULL;
	if(!pFnClampRotAxis)
		pFnClampRotAxis = UObject::FindFunction("Function Core.Object.ClampRotAxis");

	Core_ClampRotAxis_Parms ClampRotAxis_Parms;
	ClampRotAxis_Parms.ViewAxis = ViewAxis;
	ClampRotAxis_Parms.MaxLimit = MaxLimit;
	ClampRotAxis_Parms.MinLimit = MinLimit;
	ProcessEvent(pFnClampRotAxis,NULL,&ClampRotAxis_Parms,NULL);
	if(out_DeltaViewAxis)
		*out_DeltaViewAxis = ClampRotAxis_Parms.out_DeltaViewAxis;
}

struct Core_GetUnAxes_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           X;                                                		// 0x00000C (0x000C)              
	FVector3                                           Y;                                                		// 0x000018 (0x000C)              
	FVector3                                           Z;                                                		// 0x000024 (0x000C)              
};

void UObject::GetUnAxes(FRotator A,FVector3* X,FVector3* Y,FVector3* Z)
{
	static UFieldFunc* pFnGetUnAxes = NULL;
	if(!pFnGetUnAxes)
		pFnGetUnAxes = UObject::FindFunction("Function Core.Object.GetUnAxes");

	Core_GetUnAxes_Parms GetUnAxes_Parms;
	memcpy(&GetUnAxes_Parms.A,&A,0xC);

	unsigned short NativeIndex = pFnGetUnAxes->iNative;
	pFnGetUnAxes->iNative = 0;
	pFnGetUnAxes->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetUnAxes,NULL,&GetUnAxes_Parms,NULL);
	pFnGetUnAxes->FunctionFlags |= 0x400;
	pFnGetUnAxes->iNative = NativeIndex;
	if(X)
		memcpy(X,&GetUnAxes_Parms.X,0xC);
	if(Y)
		memcpy(Y,&GetUnAxes_Parms.Y,0xC);
	if(Z)
		memcpy(Z,&GetUnAxes_Parms.Z,0xC);
}

struct Core_NotEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnNotEqual_FloatFloat = NULL;
	if(!pFnNotEqual_FloatFloat)
		pFnNotEqual_FloatFloat = UObject::FindFunction("Function Core.Object.NotEqual_FloatFloat");

	Core_NotEqual_FloatFloat_Parms NotEqual_FloatFloat_Parms;
	NotEqual_FloatFloat_Parms.A = A;
	NotEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnNotEqual_FloatFloat->iNative;
	pFnNotEqual_FloatFloat->iNative = 0;
	pFnNotEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_FloatFloat,NULL,&NotEqual_FloatFloat_Parms,NULL);
	pFnNotEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnNotEqual_FloatFloat->iNative = NativeIndex;
	return NotEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_Add_ColorColor_Parms
{
	DWORD                                              A;                                                		// 0x000000 (0x0004)              
	DWORD                                              B;                                                		// 0x000004 (0x0004)              
	DWORD                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

DWORD UObject::Add_ColorColor(DWORD A,DWORD B)
{
	static UFieldFunc* pFnAdd_ColorColor = NULL;
	if(!pFnAdd_ColorColor)
		pFnAdd_ColorColor = UObject::FindFunction("Function Core.Object.Add_ColorColor");

	Core_Add_ColorColor_Parms Add_ColorColor_Parms;
	memcpy(&Add_ColorColor_Parms.A,&A,0x4);
	memcpy(&Add_ColorColor_Parms.B,&B,0x4);
	ProcessEvent(pFnAdd_ColorColor,NULL,&Add_ColorColor_Parms,NULL);
	return Add_ColorColor_Parms.ReturnValue;
}

struct Core_GreaterEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::GreaterEqual_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnGreaterEqual_DoubleDouble = NULL;
	if(!pFnGreaterEqual_DoubleDouble)
		pFnGreaterEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.GreaterEqual_DoubleDouble");

	Core_GreaterEqual_DoubleDouble_Parms GreaterEqual_DoubleDouble_Parms;
	GreaterEqual_DoubleDouble_Parms.A = A;
	GreaterEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnGreaterEqual_DoubleDouble->iNative;
	pFnGreaterEqual_DoubleDouble->iNative = 0;
	pFnGreaterEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterEqual_DoubleDouble,NULL,&GreaterEqual_DoubleDouble_Parms,NULL);
	pFnGreaterEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnGreaterEqual_DoubleDouble->iNative = NativeIndex;
	return GreaterEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_DClamp_Parms
{
	double                                             V;                                                		// 0x000000 (0x0008)              
	double                                             A;                                                		// 0x000008 (0x0008)              
	double                                             B;                                                		// 0x000010 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000018 (0x0008)              
};

double UObject::DClamp(double V,double A,double B)
{
	static UFieldFunc* pFnDClamp = NULL;
	if(!pFnDClamp)
		pFnDClamp = UObject::FindFunction("Function Core.Object.DClamp");

	Core_DClamp_Parms DClamp_Parms;
	DClamp_Parms.V = V;
	DClamp_Parms.A = A;
	DClamp_Parms.B = B;

	unsigned short NativeIndex = pFnDClamp->iNative;
	pFnDClamp->iNative = 0;
	pFnDClamp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDClamp,NULL,&DClamp_Parms,NULL);
	pFnDClamp->FunctionFlags |= 0x400;
	pFnDClamp->iNative = NativeIndex;
	return DClamp_Parms.ReturnValue;
}

struct Core_NotifyReferenceToObject_Parms
{
	class UObject*                                     RefObject;                                        		// 0x000000 (0x0004)              
};

void UObject::NotifyReferenceToObject(class UObject* RefObject)
{
	static UFieldFunc* pFnNotifyReferenceToObject = NULL;
	if(!pFnNotifyReferenceToObject)
		pFnNotifyReferenceToObject = UObject::FindFunction("Function Core.Object.NotifyReferenceToObject");

	Core_NotifyReferenceToObject_Parms NotifyReferenceToObject_Parms;
	NotifyReferenceToObject_Parms.RefObject = RefObject;
	pFnNotifyReferenceToObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotifyReferenceToObject,NULL,&NotifyReferenceToObject_Parms,NULL);
	pFnNotifyReferenceToObject->FunctionFlags |= 0x400;
}

struct Core_EqualEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnEqualEqual_StrStr = NULL;
	if(!pFnEqualEqual_StrStr)
		pFnEqualEqual_StrStr = UObject::FindFunction("Function Core.Object.EqualEqual_StrStr");

	Core_EqualEqual_StrStr_Parms EqualEqual_StrStr_Parms;
	memcpy(&EqualEqual_StrStr_Parms.A,&A,0xC);
	memcpy(&EqualEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnEqualEqual_StrStr->iNative;
	pFnEqualEqual_StrStr->iNative = 0;
	pFnEqualEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_StrStr,NULL,&EqualEqual_StrStr_Parms,NULL);
	pFnEqualEqual_StrStr->FunctionFlags |= 0x400;
	pFnEqualEqual_StrStr->iNative = NativeIndex;
	return EqualEqual_StrStr_Parms.ReturnValue;
}

struct Core_GotoState_Parms
{
	struct FName                                       NewState;                                         		// 0x000000 (0x0008)              
	struct FName                                       Label;                                            		// 0x000008 (0x0008)              
	unsigned long                                      bForceEvents : 1;                                 		// 0x000010 (0x0004) [0x00000001] 
	unsigned long                                      bKeepStack : 1;                                   		// 0x000014 (0x0004) [0x00000001] 
};

void UObject::GotoState(struct FName NewState,struct FName Label,bool bForceEvents,bool bKeepStack)
{
	static UFieldFunc* pFnGotoState = NULL;
	if(!pFnGotoState)
		pFnGotoState = UObject::FindFunction("Function Core.Object.GotoState");

	Core_GotoState_Parms GotoState_Parms;
	memcpy(&GotoState_Parms.NewState,&NewState,0x8);
	memcpy(&GotoState_Parms.Label,&Label,0x8);
	GotoState_Parms.bForceEvents = bForceEvents;
	GotoState_Parms.bKeepStack = bKeepStack;

	unsigned short NativeIndex = pFnGotoState->iNative;
	pFnGotoState->iNative = 0;
	pFnGotoState->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGotoState,NULL,&GotoState_Parms,NULL);
	pFnGotoState->FunctionFlags |= 0x400;
	pFnGotoState->iNative = NativeIndex;
}

struct Core_MultiplyMultiply_DoubleDouble_Parms
{
	double                                             Base;                                             		// 0x000000 (0x0008)              
	double                                             Exp;                                              		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::MultiplyMultiply_DoubleDouble(double Base,double Exp)
{
	static UFieldFunc* pFnMultiplyMultiply_DoubleDouble = NULL;
	if(!pFnMultiplyMultiply_DoubleDouble)
		pFnMultiplyMultiply_DoubleDouble = UObject::FindFunction("Function Core.Object.MultiplyMultiply_DoubleDouble");

	Core_MultiplyMultiply_DoubleDouble_Parms MultiplyMultiply_DoubleDouble_Parms;
	MultiplyMultiply_DoubleDouble_Parms.Base = Base;
	MultiplyMultiply_DoubleDouble_Parms.Exp = Exp;

	unsigned short NativeIndex = pFnMultiplyMultiply_DoubleDouble->iNative;
	pFnMultiplyMultiply_DoubleDouble->iNative = 0;
	pFnMultiplyMultiply_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyMultiply_DoubleDouble,NULL,&MultiplyMultiply_DoubleDouble_Parms,NULL);
	pFnMultiplyMultiply_DoubleDouble->FunctionFlags |= 0x400;
	pFnMultiplyMultiply_DoubleDouble->iNative = NativeIndex;
	return MultiplyMultiply_DoubleDouble_Parms.ReturnValue;
}

struct Core_GetEnum_Parms
{
	class UField*                                      E;                                                		// 0x000000 (0x0004)              
	int                                                I;                                                		// 0x000004 (0x0004)              
	struct FName                                       ReturnValue;                                      		// 0x000008 (0x0008)              
};

struct FName UObject::GetEnum(class UField* E,int I)
{
	static UFieldFunc* pFnGetEnum = NULL;
	if(!pFnGetEnum)
		pFnGetEnum = UObject::FindFunction("Function Core.Object.GetEnum");

	Core_GetEnum_Parms GetEnum_Parms;
	GetEnum_Parms.E = E;
	GetEnum_Parms.I = I;
	pFnGetEnum->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetEnum,NULL,&GetEnum_Parms,NULL);
	pFnGetEnum->FunctionFlags |= 0x400;
	return GetEnum_Parms.ReturnValue;
}

struct Core_DivideEqual_RotatorFloat_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	float                                              B;                                                		// 0x00000C (0x0004)              
	FRotator                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FRotator UObject::DivideEqual_RotatorFloat(FRotator* A,float B)
{
	static UFieldFunc* pFnDivideEqual_RotatorFloat = NULL;
	if(!pFnDivideEqual_RotatorFloat)
		pFnDivideEqual_RotatorFloat = UObject::FindFunction("Function Core.Object.DivideEqual_RotatorFloat");

	Core_DivideEqual_RotatorFloat_Parms DivideEqual_RotatorFloat_Parms;
	DivideEqual_RotatorFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivideEqual_RotatorFloat->iNative;
	pFnDivideEqual_RotatorFloat->iNative = 0;
	pFnDivideEqual_RotatorFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivideEqual_RotatorFloat,NULL,&DivideEqual_RotatorFloat_Parms,NULL);
	pFnDivideEqual_RotatorFloat->FunctionFlags |= 0x400;
	pFnDivideEqual_RotatorFloat->iNative = NativeIndex;
	if(A)
		memcpy(A,&DivideEqual_RotatorFloat_Parms.A,0xC);
	return DivideEqual_RotatorFloat_Parms.ReturnValue;
}

struct Core_NotEqual_RotatorRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FRotator                                           B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_RotatorRotator(FRotator A,FRotator B)
{
	static UFieldFunc* pFnNotEqual_RotatorRotator = NULL;
	if(!pFnNotEqual_RotatorRotator)
		pFnNotEqual_RotatorRotator = UObject::FindFunction("Function Core.Object.NotEqual_RotatorRotator");

	Core_NotEqual_RotatorRotator_Parms NotEqual_RotatorRotator_Parms;
	memcpy(&NotEqual_RotatorRotator_Parms.A,&A,0xC);
	memcpy(&NotEqual_RotatorRotator_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnNotEqual_RotatorRotator->iNative;
	pFnNotEqual_RotatorRotator->iNative = 0;
	pFnNotEqual_RotatorRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_RotatorRotator,NULL,&NotEqual_RotatorRotator_Parms,NULL);
	pFnNotEqual_RotatorRotator->FunctionFlags |= 0x400;
	pFnNotEqual_RotatorRotator->iNative = NativeIndex;
	return NotEqual_RotatorRotator_Parms.ReturnValue;
}

struct Core_ProjectOnTo_Parms
{
	FVector3                                           X;                                                		// 0x000000 (0x000C)              
	FVector3                                           Y;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::ProjectOnTo(FVector3 X,FVector3 Y)
{
	static UFieldFunc* pFnProjectOnTo = NULL;
	if(!pFnProjectOnTo)
		pFnProjectOnTo = UObject::FindFunction("Function Core.Object.ProjectOnTo");

	Core_ProjectOnTo_Parms ProjectOnTo_Parms;
	memcpy(&ProjectOnTo_Parms.X,&X,0xC);
	memcpy(&ProjectOnTo_Parms.Y,&Y,0xC);

	unsigned short NativeIndex = pFnProjectOnTo->iNative;
	pFnProjectOnTo->iNative = 0;
	pFnProjectOnTo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnProjectOnTo,NULL,&ProjectOnTo_Parms,NULL);
	pFnProjectOnTo->FunctionFlags |= 0x400;
	pFnProjectOnTo->iNative = NativeIndex;
	return ProjectOnTo_Parms.ReturnValue;
}

struct Core_Greater_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::Greater_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnGreater_DoubleDouble = NULL;
	if(!pFnGreater_DoubleDouble)
		pFnGreater_DoubleDouble = UObject::FindFunction("Function Core.Object.Greater_DoubleDouble");

	Core_Greater_DoubleDouble_Parms Greater_DoubleDouble_Parms;
	Greater_DoubleDouble_Parms.A = A;
	Greater_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnGreater_DoubleDouble->iNative;
	pFnGreater_DoubleDouble->iNative = 0;
	pFnGreater_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreater_DoubleDouble,NULL,&Greater_DoubleDouble_Parms,NULL);
	pFnGreater_DoubleDouble->FunctionFlags |= 0x400;
	pFnGreater_DoubleDouble->iNative = NativeIndex;
	return Greater_DoubleDouble_Parms.ReturnValue;
}

struct Core_FFloor_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::FFloor(float A)
{
	static UFieldFunc* pFnFFloor = NULL;
	if(!pFnFFloor)
		pFnFFloor = UObject::FindFunction("Function Core.Object.FFloor");

	Core_FFloor_Parms FFloor_Parms;
	FFloor_Parms.A = A;
	pFnFFloor->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFFloor,NULL,&FFloor_Parms,NULL);
	pFnFFloor->FunctionFlags |= 0x400;
	return FFloor_Parms.ReturnValue;
}

struct Core_RInterpTo_Parms
{
	FRotator                                           Current;                                          		// 0x000000 (0x000C)              
	FRotator                                           Target;                                           		// 0x00000C (0x000C)              
	float                                              DeltaTime;                                        		// 0x000018 (0x0004)              
	float                                              InterpSpeed;                                      		// 0x00001C (0x0004)              
	FRotator                                           ReturnValue;                                      		// 0x000020 (0x000C)              
};

FRotator UObject::RInterpTo(FRotator Current,FRotator Target,float DeltaTime,float InterpSpeed)
{
	static UFieldFunc* pFnRInterpTo = NULL;
	if(!pFnRInterpTo)
		pFnRInterpTo = UObject::FindFunction("Function Core.Object.RInterpTo");

	Core_RInterpTo_Parms RInterpTo_Parms;
	memcpy(&RInterpTo_Parms.Current,&Current,0xC);
	memcpy(&RInterpTo_Parms.Target,&Target,0xC);
	RInterpTo_Parms.DeltaTime = DeltaTime;
	RInterpTo_Parms.InterpSpeed = InterpSpeed;
	pFnRInterpTo->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRInterpTo,NULL,&RInterpTo_Parms,NULL);
	pFnRInterpTo->FunctionFlags |= 0x400;
	return RInterpTo_Parms.ReturnValue;
}

struct Core_Len_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UObject::Len(struct FString S)
{
	static UFieldFunc* pFnLen = NULL;
	if(!pFnLen)
		pFnLen = UObject::FindFunction("Function Core.Object.Len");

	Core_Len_Parms Len_Parms;
	memcpy(&Len_Parms.S,&S,0xC);

	unsigned short NativeIndex = pFnLen->iNative;
	pFnLen->iNative = 0;
	pFnLen->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLen,NULL,&Len_Parms,NULL);
	pFnLen->FunctionFlags |= 0x400;
	pFnLen->iNative = NativeIndex;
	return Len_Parms.ReturnValue;
}

struct Core_NotEqual_ObjectObject_Parms
{
	class UObject*                                     A;                                                		// 0x000000 (0x0004)              
	class UObject*                                     B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_ObjectObject(class UObject* A,class UObject* B)
{
	static UFieldFunc* pFnNotEqual_ObjectObject = NULL;
	if(!pFnNotEqual_ObjectObject)
		pFnNotEqual_ObjectObject = UObject::FindFunction("Function Core.Object.NotEqual_ObjectObject");

	Core_NotEqual_ObjectObject_Parms NotEqual_ObjectObject_Parms;
	NotEqual_ObjectObject_Parms.A = A;
	NotEqual_ObjectObject_Parms.B = B;

	unsigned short NativeIndex = pFnNotEqual_ObjectObject->iNative;
	pFnNotEqual_ObjectObject->iNative = 0;
	pFnNotEqual_ObjectObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_ObjectObject,NULL,&NotEqual_ObjectObject_Parms,NULL);
	pFnNotEqual_ObjectObject->FunctionFlags |= 0x400;
	pFnNotEqual_ObjectObject->iNative = NativeIndex;
	return NotEqual_ObjectObject_Parms.ReturnValue;
}

struct Core_GetFuncName_Parms
{
	struct FName                                       ReturnValue;                                      		// 0x000000 (0x0008)              
};

struct FName UObject::GetFuncName()
{
	static UFieldFunc* pFnGetFuncName = NULL;
	if(!pFnGetFuncName)
		pFnGetFuncName = UObject::FindFunction("Function Core.Object.GetFuncName");

	Core_GetFuncName_Parms GetFuncName_Parms;
	pFnGetFuncName->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetFuncName,NULL,&GetFuncName_Parms,NULL);
	pFnGetFuncName->FunctionFlags |= 0x400;
	return GetFuncName_Parms.ReturnValue;
}

struct Core_AtEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UObject::AtEqual_StrStr(struct FString* A,struct FString B)
{
	static UFieldFunc* pFnAtEqual_StrStr = NULL;
	if(!pFnAtEqual_StrStr)
		pFnAtEqual_StrStr = UObject::FindFunction("Function Core.Object.AtEqual_StrStr");

	Core_AtEqual_StrStr_Parms AtEqual_StrStr_Parms;
	memcpy(&AtEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnAtEqual_StrStr->iNative;
	pFnAtEqual_StrStr->iNative = 0;
	pFnAtEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAtEqual_StrStr,NULL,&AtEqual_StrStr_Parms,NULL);
	pFnAtEqual_StrStr->FunctionFlags |= 0x400;
	pFnAtEqual_StrStr->iNative = NativeIndex;
	if(A)
		memcpy(A,&AtEqual_StrStr_Parms.A,0xC);
	return AtEqual_StrStr_Parms.ReturnValue;
}

struct Core_GetAngularDegreesFromRadians_Parms
{
	FVector2                                           OutFOV;                                           		// 0x000000 (0x0008)              
};

void UObject::GetAngularDegreesFromRadians(FVector2* OutFOV)
{
	static UFieldFunc* pFnGetAngularDegreesFromRadians = NULL;
	if(!pFnGetAngularDegreesFromRadians)
		pFnGetAngularDegreesFromRadians = UObject::FindFunction("Function Core.Object.GetAngularDegreesFromRadians");

	Core_GetAngularDegreesFromRadians_Parms GetAngularDegreesFromRadians_Parms;
	ProcessEvent(pFnGetAngularDegreesFromRadians,NULL,&GetAngularDegreesFromRadians_Parms,NULL);
	if(OutFOV)
		memcpy(OutFOV,&GetAngularDegreesFromRadians_Parms.OutFOV,0x8);
}

struct Core_Percent_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::Percent_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnPercent_FloatFloat = NULL;
	if(!pFnPercent_FloatFloat)
		pFnPercent_FloatFloat = UObject::FindFunction("Function Core.Object.Percent_FloatFloat");

	Core_Percent_FloatFloat_Parms Percent_FloatFloat_Parms;
	Percent_FloatFloat_Parms.A = A;
	Percent_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnPercent_FloatFloat->iNative;
	pFnPercent_FloatFloat->iNative = 0;
	pFnPercent_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPercent_FloatFloat,NULL,&Percent_FloatFloat_Parms,NULL);
	pFnPercent_FloatFloat->FunctionFlags |= 0x400;
	pFnPercent_FloatFloat->iNative = NativeIndex;
	return Percent_FloatFloat_Parms.ReturnValue;
}

struct Core_NotEqual_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_IntInt(int A,int B)
{
	static UFieldFunc* pFnNotEqual_IntInt = NULL;
	if(!pFnNotEqual_IntInt)
		pFnNotEqual_IntInt = UObject::FindFunction("Function Core.Object.NotEqual_IntInt");

	Core_NotEqual_IntInt_Parms NotEqual_IntInt_Parms;
	NotEqual_IntInt_Parms.A = A;
	NotEqual_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnNotEqual_IntInt->iNative;
	pFnNotEqual_IntInt->iNative = 0;
	pFnNotEqual_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_IntInt,NULL,&NotEqual_IntInt_Parms,NULL);
	pFnNotEqual_IntInt->FunctionFlags |= 0x400;
	pFnNotEqual_IntInt->iNative = NativeIndex;
	return NotEqual_IntInt_Parms.ReturnValue;
}

struct Core_QuatFromRotator_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	unsigned char                                      _0x00000C[0x4];                                   		// 0x00000C (0x0004) MISSED OFFSET
	struct FQuat                                       ReturnValue;                                      		// 0x000010 (0x0010)              
};

struct FQuat UObject::QuatFromRotator(FRotator A)
{
	static UFieldFunc* pFnQuatFromRotator = NULL;
	if(!pFnQuatFromRotator)
		pFnQuatFromRotator = UObject::FindFunction("Function Core.Object.QuatFromRotator");

	Core_QuatFromRotator_Parms QuatFromRotator_Parms;
	memcpy(&QuatFromRotator_Parms.A,&A,0xC);
	pFnQuatFromRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatFromRotator,NULL,&QuatFromRotator_Parms,NULL);
	pFnQuatFromRotator->FunctionFlags |= 0x400;
	return QuatFromRotator_Parms.ReturnValue;
}

struct Core_ClampRotAxisFromRange_Parms
{
	int                                                Current;                                          		// 0x000000 (0x0004)              
	int                                                Min;                                              		// 0x000004 (0x0004)              
	int                                                Max;                                              		// 0x000008 (0x0004)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
	//int                                                Delta;                                            		// 0x000010 (0x0004)              
	//int                                                Center;                                           		// 0x000014 (0x0004)              
};

int UObject::ClampRotAxisFromRange(int Current,int Min,int Max)
{
	static UFieldFunc* pFnClampRotAxisFromRange = NULL;
	if(!pFnClampRotAxisFromRange)
		pFnClampRotAxisFromRange = UObject::FindFunction("Function Core.Object.ClampRotAxisFromRange");

	Core_ClampRotAxisFromRange_Parms ClampRotAxisFromRange_Parms;
	ClampRotAxisFromRange_Parms.Current = Current;
	ClampRotAxisFromRange_Parms.Min = Min;
	ClampRotAxisFromRange_Parms.Max = Max;
	ProcessEvent(pFnClampRotAxisFromRange,NULL,&ClampRotAxisFromRange_Parms,NULL);
	return ClampRotAxisFromRange_Parms.ReturnValue;
}

struct Core_Subtract_PreFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Subtract_PreFloat(float A)
{
	static UFieldFunc* pFnSubtract_PreFloat = NULL;
	if(!pFnSubtract_PreFloat)
		pFnSubtract_PreFloat = UObject::FindFunction("Function Core.Object.Subtract_PreFloat");

	Core_Subtract_PreFloat_Parms Subtract_PreFloat_Parms;
	Subtract_PreFloat_Parms.A = A;

	unsigned short NativeIndex = pFnSubtract_PreFloat->iNative;
	pFnSubtract_PreFloat->iNative = 0;
	pFnSubtract_PreFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_PreFloat,NULL,&Subtract_PreFloat_Parms,NULL);
	pFnSubtract_PreFloat->FunctionFlags |= 0x400;
	pFnSubtract_PreFloat->iNative = NativeIndex;
	return Subtract_PreFloat_Parms.ReturnValue;
}

struct Core_GreaterEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::GreaterEqual_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnGreaterEqual_StrStr = NULL;
	if(!pFnGreaterEqual_StrStr)
		pFnGreaterEqual_StrStr = UObject::FindFunction("Function Core.Object.GreaterEqual_StrStr");

	Core_GreaterEqual_StrStr_Parms GreaterEqual_StrStr_Parms;
	memcpy(&GreaterEqual_StrStr_Parms.A,&A,0xC);
	memcpy(&GreaterEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnGreaterEqual_StrStr->iNative;
	pFnGreaterEqual_StrStr->iNative = 0;
	pFnGreaterEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterEqual_StrStr,NULL,&GreaterEqual_StrStr_Parms,NULL);
	pFnGreaterEqual_StrStr->FunctionFlags |= 0x400;
	pFnGreaterEqual_StrStr->iNative = NativeIndex;
	return GreaterEqual_StrStr_Parms.ReturnValue;
}

struct Core_Asin_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Asin(float A)
{
	static UFieldFunc* pFnAsin = NULL;
	if(!pFnAsin)
		pFnAsin = UObject::FindFunction("Function Core.Object.Asin");

	Core_Asin_Parms Asin_Parms;
	Asin_Parms.A = A;
	pFnAsin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAsin,NULL,&Asin_Parms,NULL);
	pFnAsin->FunctionFlags |= 0x400;
	return Asin_Parms.ReturnValue;
}

struct Core_EqualEqual_ObjectObject_Parms
{
	class UObject*                                     A;                                                		// 0x000000 (0x0004)              
	class UObject*                                     B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_ObjectObject(class UObject* A,class UObject* B)
{
	static UFieldFunc* pFnEqualEqual_ObjectObject = NULL;
	if(!pFnEqualEqual_ObjectObject)
		pFnEqualEqual_ObjectObject = UObject::FindFunction("Function Core.Object.EqualEqual_ObjectObject");

	Core_EqualEqual_ObjectObject_Parms EqualEqual_ObjectObject_Parms;
	EqualEqual_ObjectObject_Parms.A = A;
	EqualEqual_ObjectObject_Parms.B = B;

	unsigned short NativeIndex = pFnEqualEqual_ObjectObject->iNative;
	pFnEqualEqual_ObjectObject->iNative = 0;
	pFnEqualEqual_ObjectObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_ObjectObject,NULL,&EqualEqual_ObjectObject_Parms,NULL);
	pFnEqualEqual_ObjectObject->FunctionFlags |= 0x400;
	pFnEqualEqual_ObjectObject->iNative = NativeIndex;
	return EqualEqual_ObjectObject_Parms.ReturnValue;
}

struct Core_ClampRotAxisFromBase_Parms
{
	int                                                Current;                                          		// 0x000000 (0x0004)              
	int                                                Center;                                           		// 0x000004 (0x0004)              
	int                                                MaxDelta;                                         		// 0x000008 (0x0004)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
	//int                                                DeltaFromCenter;                                  		// 0x000010 (0x0004)              
};

int UObject::ClampRotAxisFromBase(int Current,int Center,int MaxDelta)
{
	static UFieldFunc* pFnClampRotAxisFromBase = NULL;
	if(!pFnClampRotAxisFromBase)
		pFnClampRotAxisFromBase = UObject::FindFunction("Function Core.Object.ClampRotAxisFromBase");

	Core_ClampRotAxisFromBase_Parms ClampRotAxisFromBase_Parms;
	ClampRotAxisFromBase_Parms.Current = Current;
	ClampRotAxisFromBase_Parms.Center = Center;
	ClampRotAxisFromBase_Parms.MaxDelta = MaxDelta;
	ProcessEvent(pFnClampRotAxisFromBase,NULL,&ClampRotAxisFromBase_Parms,NULL);
	return ClampRotAxisFromBase_Parms.ReturnValue;
}

struct Core_Or_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Or_IntInt(int A,int B)
{
	static UFieldFunc* pFnOr_IntInt = NULL;
	if(!pFnOr_IntInt)
		pFnOr_IntInt = UObject::FindFunction("Function Core.Object.Or_IntInt");

	Core_Or_IntInt_Parms Or_IntInt_Parms;
	Or_IntInt_Parms.A = A;
	Or_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnOr_IntInt->iNative;
	pFnOr_IntInt->iNative = 0;
	pFnOr_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnOr_IntInt,NULL,&Or_IntInt_Parms,NULL);
	pFnOr_IntInt->FunctionFlags |= 0x400;
	pFnOr_IntInt->iNative = NativeIndex;
	return Or_IntInt_Parms.ReturnValue;
}

struct Core_SubtractEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::SubtractEqual_DoubleDouble(double* A,double B)
{
	static UFieldFunc* pFnSubtractEqual_DoubleDouble = NULL;
	if(!pFnSubtractEqual_DoubleDouble)
		pFnSubtractEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.SubtractEqual_DoubleDouble");

	Core_SubtractEqual_DoubleDouble_Parms SubtractEqual_DoubleDouble_Parms;
	SubtractEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnSubtractEqual_DoubleDouble->iNative;
	pFnSubtractEqual_DoubleDouble->iNative = 0;
	pFnSubtractEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_DoubleDouble,NULL,&SubtractEqual_DoubleDouble_Parms,NULL);
	pFnSubtractEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnSubtractEqual_DoubleDouble->iNative = NativeIndex;
	if(A)
		*A = SubtractEqual_DoubleDouble_Parms.A;
	return SubtractEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_QuatToRotator_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	FRotator                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FRotator UObject::QuatToRotator(struct FQuat A)
{
	static UFieldFunc* pFnQuatToRotator = NULL;
	if(!pFnQuatToRotator)
		pFnQuatToRotator = UObject::FindFunction("Function Core.Object.QuatToRotator");

	Core_QuatToRotator_Parms QuatToRotator_Parms;
	memcpy(&QuatToRotator_Parms.A,&A,0x10);
	pFnQuatToRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatToRotator,NULL,&QuatToRotator_Parms,NULL);
	pFnQuatToRotator->FunctionFlags |= 0x400;
	return QuatToRotator_Parms.ReturnValue;
}

struct Core_AddEqual_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::AddEqual_VectorVector(FVector3* A,FVector3 B)
{
	static UFieldFunc* pFnAddEqual_VectorVector = NULL;
	if(!pFnAddEqual_VectorVector)
		pFnAddEqual_VectorVector = UObject::FindFunction("Function Core.Object.AddEqual_VectorVector");

	Core_AddEqual_VectorVector_Parms AddEqual_VectorVector_Parms;
	memcpy(&AddEqual_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnAddEqual_VectorVector->iNative;
	pFnAddEqual_VectorVector->iNative = 0;
	pFnAddEqual_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddEqual_VectorVector,NULL,&AddEqual_VectorVector_Parms,NULL);
	pFnAddEqual_VectorVector->FunctionFlags |= 0x400;
	pFnAddEqual_VectorVector->iNative = NativeIndex;
	if(A)
		memcpy(A,&AddEqual_VectorVector_Parms.A,0xC);
	return AddEqual_VectorVector_Parms.ReturnValue;
}

struct Core_ParseStringIntoArray_Parms
{
	struct FString                                     BaseString;                                       		// 0x000000 (0x000C)              
	TArray<struct FString>                             Pieces;                                           		// 0x00000C (0x000C)              
	struct FString                                     delim;                                            		// 0x000018 (0x000C)              
	unsigned long                                      bCullEmpty : 1;                                   		// 0x000024 (0x0004) [0x00000001] 
};

void UObject::ParseStringIntoArray(struct FString BaseString,TArray<struct FString>* Pieces,struct FString delim,bool bCullEmpty)
{
	static UFieldFunc* pFnParseStringIntoArray = NULL;
	if(!pFnParseStringIntoArray)
		pFnParseStringIntoArray = UObject::FindFunction("Function Core.Object.ParseStringIntoArray");

	Core_ParseStringIntoArray_Parms ParseStringIntoArray_Parms;
	memcpy(&ParseStringIntoArray_Parms.BaseString,&BaseString,0xC);
	memcpy(&ParseStringIntoArray_Parms.delim,&delim,0xC);
	ParseStringIntoArray_Parms.bCullEmpty = bCullEmpty;
	pFnParseStringIntoArray->FunctionFlags |= ~0x400;
	ProcessEvent(pFnParseStringIntoArray,NULL,&ParseStringIntoArray_Parms,NULL);
	pFnParseStringIntoArray->FunctionFlags |= 0x400;
	if(Pieces)
		memcpy(Pieces,&ParseStringIntoArray_Parms.Pieces,0xC);
}

struct Core_OrthoRotation_Parms
{
	FVector3                                           X;                                                		// 0x000000 (0x000C)              
	FVector3                                           Y;                                                		// 0x00000C (0x000C)              
	FVector3                                           Z;                                                		// 0x000018 (0x000C)              
	FRotator                                           ReturnValue;                                      		// 0x000024 (0x000C)              
};

FRotator UObject::OrthoRotation(FVector3 X,FVector3 Y,FVector3 Z)
{
	static UFieldFunc* pFnOrthoRotation = NULL;
	if(!pFnOrthoRotation)
		pFnOrthoRotation = UObject::FindFunction("Function Core.Object.OrthoRotation");

	Core_OrthoRotation_Parms OrthoRotation_Parms;
	memcpy(&OrthoRotation_Parms.X,&X,0xC);
	memcpy(&OrthoRotation_Parms.Y,&Y,0xC);
	memcpy(&OrthoRotation_Parms.Z,&Z,0xC);
	pFnOrthoRotation->FunctionFlags |= ~0x400;
	ProcessEvent(pFnOrthoRotation,NULL,&OrthoRotation_Parms,NULL);
	pFnOrthoRotation->FunctionFlags |= 0x400;
	return OrthoRotation_Parms.ReturnValue;
}

struct Core_PopState_Parms
{
	unsigned long                                      bPopAll : 1;                                      		// 0x000000 (0x0004) [0x00000001] 
};

void UObject::PopState(bool bPopAll)
{
	static UFieldFunc* pFnPopState = NULL;
	if(!pFnPopState)
		pFnPopState = UObject::FindFunction("Function Core.Object.PopState");

	Core_PopState_Parms PopState_Parms;
	PopState_Parms.bPopAll = bPopAll;
	pFnPopState->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPopState,NULL,&PopState_Parms,NULL);
	pFnPopState->FunctionFlags |= 0x400;
}

struct Core_RSize_Parms
{
	FRotator                                           R;                                                		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
	//int                                                PitchNorm;                                        		// 0x000010 (0x0004)              
	//int                                                YawNorm;                                          		// 0x000014 (0x0004)              
	//int                                                RollNorm;                                         		// 0x000018 (0x0004)              
};

float UObject::RSize(FRotator R)
{
	static UFieldFunc* pFnRSize = NULL;
	if(!pFnRSize)
		pFnRSize = UObject::FindFunction("Function Core.Object.RSize");

	Core_RSize_Parms RSize_Parms;
	memcpy(&RSize_Parms.R,&R,0xC);
	ProcessEvent(pFnRSize,NULL,&RSize_Parms,NULL);
	return RSize_Parms.ReturnValue;
}

struct Core_GetAxes_Parms
{
	FRotator                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           X;                                                		// 0x00000C (0x000C)              
	FVector3                                           Y;                                                		// 0x000018 (0x000C)              
	FVector3                                           Z;                                                		// 0x000024 (0x000C)              
};

void UObject::GetAxes(FRotator A,FVector3* X,FVector3* Y,FVector3* Z)
{
	static UFieldFunc* pFnGetAxes = NULL;
	if(!pFnGetAxes)
		pFnGetAxes = UObject::FindFunction("Function Core.Object.GetAxes");

	Core_GetAxes_Parms GetAxes_Parms;
	memcpy(&GetAxes_Parms.A,&A,0xC);

	unsigned short NativeIndex = pFnGetAxes->iNative;
	pFnGetAxes->iNative = 0;
	pFnGetAxes->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetAxes,NULL,&GetAxes_Parms,NULL);
	pFnGetAxes->FunctionFlags |= 0x400;
	pFnGetAxes->iNative = NativeIndex;
	if(X)
		memcpy(X,&GetAxes_Parms.X,0xC);
	if(Y)
		memcpy(Y,&GetAxes_Parms.Y,0xC);
	if(Z)
		memcpy(Z,&GetAxes_Parms.Z,0xC);
}

struct Core_MakeLinearColor_Parms
{
	float                                              R;                                                		// 0x000000 (0x0004)              
	float                                              G;                                                		// 0x000004 (0x0004)              
	float                                              B;                                                		// 0x000008 (0x0004)              
	float                                              A;                                                		// 0x00000C (0x0004)              
	struct FLinearColor                                ReturnValue;                                      		// 0x000010 (0x0010)              
	//struct FLinearColor                                LC;                                               		// 0x000020 (0x0010)              
};

struct FLinearColor UObject::MakeLinearColor(float R,float G,float B,float A)
{
	static UFieldFunc* pFnMakeLinearColor = NULL;
	if(!pFnMakeLinearColor)
		pFnMakeLinearColor = UObject::FindFunction("Function Core.Object.MakeLinearColor");

	Core_MakeLinearColor_Parms MakeLinearColor_Parms;
	MakeLinearColor_Parms.R = R;
	MakeLinearColor_Parms.G = G;
	MakeLinearColor_Parms.B = B;
	MakeLinearColor_Parms.A = A;
	ProcessEvent(pFnMakeLinearColor,NULL,&MakeLinearColor_Parms,NULL);
	return MakeLinearColor_Parms.ReturnValue;
}

struct Core_SubtractEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x000018 (0x000C)              
};

struct FString UObject::SubtractEqual_StrStr(struct FString* A,struct FString B)
{
	static UFieldFunc* pFnSubtractEqual_StrStr = NULL;
	if(!pFnSubtractEqual_StrStr)
		pFnSubtractEqual_StrStr = UObject::FindFunction("Function Core.Object.SubtractEqual_StrStr");

	Core_SubtractEqual_StrStr_Parms SubtractEqual_StrStr_Parms;
	memcpy(&SubtractEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnSubtractEqual_StrStr->iNative;
	pFnSubtractEqual_StrStr->iNative = 0;
	pFnSubtractEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_StrStr,NULL,&SubtractEqual_StrStr_Parms,NULL);
	pFnSubtractEqual_StrStr->FunctionFlags |= 0x400;
	pFnSubtractEqual_StrStr->iNative = NativeIndex;
	if(A)
		memcpy(A,&SubtractEqual_StrStr_Parms.A,0xC);
	return SubtractEqual_StrStr_Parms.ReturnValue;
}

struct Core_Subtract_ColorColor_Parms
{
	DWORD                                              A;                                                		// 0x000000 (0x0004)              
	DWORD                                              B;                                                		// 0x000004 (0x0004)              
	DWORD                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

DWORD UObject::Subtract_ColorColor(DWORD A,DWORD B)
{
	static UFieldFunc* pFnSubtract_ColorColor = NULL;
	if(!pFnSubtract_ColorColor)
		pFnSubtract_ColorColor = UObject::FindFunction("Function Core.Object.Subtract_ColorColor");

	Core_Subtract_ColorColor_Parms Subtract_ColorColor_Parms;
	memcpy(&Subtract_ColorColor_Parms.A,&A,0x4);
	memcpy(&Subtract_ColorColor_Parms.B,&B,0x4);
	ProcessEvent(pFnSubtract_ColorColor,NULL,&Subtract_ColorColor_Parms,NULL);
	return Subtract_ColorColor_Parms.ReturnValue;
}

struct Core_LessEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::LessEqual_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnLessEqual_FloatFloat = NULL;
	if(!pFnLessEqual_FloatFloat)
		pFnLessEqual_FloatFloat = UObject::FindFunction("Function Core.Object.LessEqual_FloatFloat");

	Core_LessEqual_FloatFloat_Parms LessEqual_FloatFloat_Parms;
	LessEqual_FloatFloat_Parms.A = A;
	LessEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnLessEqual_FloatFloat->iNative;
	pFnLessEqual_FloatFloat->iNative = 0;
	pFnLessEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLessEqual_FloatFloat,NULL,&LessEqual_FloatFloat_Parms,NULL);
	pFnLessEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnLessEqual_FloatFloat->iNative = NativeIndex;
	return LessEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_IsServerBuild_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UObject::IsServerBuild()
{
	static UFieldFunc* pFnIsServerBuild = NULL;
	if(!pFnIsServerBuild)
		pFnIsServerBuild = UObject::FindFunction("Function Core.Object.IsServerBuild");

	Core_IsServerBuild_Parms IsServerBuild_Parms;
	pFnIsServerBuild->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsServerBuild,NULL,&IsServerBuild_Parms,NULL);
	pFnIsServerBuild->FunctionFlags |= 0x400;
	return IsServerBuild_Parms.ReturnValue;
}

struct Core_GreaterEqual_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::GreaterEqual_IntInt(int A,int B)
{
	static UFieldFunc* pFnGreaterEqual_IntInt = NULL;
	if(!pFnGreaterEqual_IntInt)
		pFnGreaterEqual_IntInt = UObject::FindFunction("Function Core.Object.GreaterEqual_IntInt");

	Core_GreaterEqual_IntInt_Parms GreaterEqual_IntInt_Parms;
	GreaterEqual_IntInt_Parms.A = A;
	GreaterEqual_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnGreaterEqual_IntInt->iNative;
	pFnGreaterEqual_IntInt->iNative = 0;
	pFnGreaterEqual_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterEqual_IntInt,NULL,&GreaterEqual_IntInt_Parms,NULL);
	pFnGreaterEqual_IntInt->FunctionFlags |= 0x400;
	pFnGreaterEqual_IntInt->iNative = NativeIndex;
	return GreaterEqual_IntInt_Parms.ReturnValue;
}

struct Core_AddAdd_PreInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::AddAdd_PreInt(int* A)
{
	static UFieldFunc* pFnAddAdd_PreInt = NULL;
	if(!pFnAddAdd_PreInt)
		pFnAddAdd_PreInt = UObject::FindFunction("Function Core.Object.AddAdd_PreInt");

	Core_AddAdd_PreInt_Parms AddAdd_PreInt_Parms;

	unsigned short NativeIndex = pFnAddAdd_PreInt->iNative;
	pFnAddAdd_PreInt->iNative = 0;
	pFnAddAdd_PreInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddAdd_PreInt,NULL,&AddAdd_PreInt_Parms,NULL);
	pFnAddAdd_PreInt->FunctionFlags |= 0x400;
	pFnAddAdd_PreInt->iNative = NativeIndex;
	if(A)
		*A = AddAdd_PreInt_Parms.A;
	return AddAdd_PreInt_Parms.ReturnValue;
}

struct Core_Multiply_LinearColorFloat_Parms
{
	struct FLinearColor                                LC;                                               		// 0x000000 (0x0010)              
	float                                              Mult;                                             		// 0x000010 (0x0004)              
	struct FLinearColor                                ReturnValue;                                      		// 0x000014 (0x0010)              
};

struct FLinearColor UObject::Multiply_LinearColorFloat(struct FLinearColor LC,float Mult)
{
	static UFieldFunc* pFnMultiply_LinearColorFloat = NULL;
	if(!pFnMultiply_LinearColorFloat)
		pFnMultiply_LinearColorFloat = UObject::FindFunction("Function Core.Object.Multiply_LinearColorFloat");

	Core_Multiply_LinearColorFloat_Parms Multiply_LinearColorFloat_Parms;
	memcpy(&Multiply_LinearColorFloat_Parms.LC,&LC,0x10);
	Multiply_LinearColorFloat_Parms.Mult = Mult;
	ProcessEvent(pFnMultiply_LinearColorFloat,NULL,&Multiply_LinearColorFloat_Parms,NULL);
	return Multiply_LinearColorFloat_Parms.ReturnValue;
}

struct Core_FRand_Parms
{
	float                                              ReturnValue;                                      		// 0x000000 (0x0004)              
};

float UObject::FRand()
{
	static UFieldFunc* pFnFRand = NULL;
	if(!pFnFRand)
		pFnFRand = UObject::FindFunction("Function Core.Object.FRand");

	Core_FRand_Parms FRand_Parms;

	unsigned short NativeIndex = pFnFRand->iNative;
	pFnFRand->iNative = 0;
	pFnFRand->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFRand,NULL,&FRand_Parms,NULL);
	pFnFRand->FunctionFlags |= 0x400;
	pFnFRand->iNative = NativeIndex;
	return FRand_Parms.ReturnValue;
}

struct Core_Subtract_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Subtract_IntInt(int A,int B)
{
	static UFieldFunc* pFnSubtract_IntInt = NULL;
	if(!pFnSubtract_IntInt)
		pFnSubtract_IntInt = UObject::FindFunction("Function Core.Object.Subtract_IntInt");

	Core_Subtract_IntInt_Parms Subtract_IntInt_Parms;
	Subtract_IntInt_Parms.A = A;
	Subtract_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnSubtract_IntInt->iNative;
	pFnSubtract_IntInt->iNative = 0;
	pFnSubtract_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_IntInt,NULL,&Subtract_IntInt_Parms,NULL);
	pFnSubtract_IntInt->FunctionFlags |= 0x400;
	pFnSubtract_IntInt->iNative = NativeIndex;
	return Subtract_IntInt_Parms.ReturnValue;
}

struct Core_SubtractEqual_ByteByte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      B;                                                		// 0x000001 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000002 (0x0001)              
};

unsigned char UObject::SubtractEqual_ByteByte(unsigned char* A,unsigned char B)
{
	static UFieldFunc* pFnSubtractEqual_ByteByte = NULL;
	if(!pFnSubtractEqual_ByteByte)
		pFnSubtractEqual_ByteByte = UObject::FindFunction("Function Core.Object.SubtractEqual_ByteByte");

	Core_SubtractEqual_ByteByte_Parms SubtractEqual_ByteByte_Parms;
	SubtractEqual_ByteByte_Parms.B = B;

	unsigned short NativeIndex = pFnSubtractEqual_ByteByte->iNative;
	pFnSubtractEqual_ByteByte->iNative = 0;
	pFnSubtractEqual_ByteByte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractEqual_ByteByte,NULL,&SubtractEqual_ByteByte_Parms,NULL);
	pFnSubtractEqual_ByteByte->FunctionFlags |= 0x400;
	pFnSubtractEqual_ByteByte->iNative = NativeIndex;
	if(A)
		*A = SubtractEqual_ByteByte_Parms.A;
	return SubtractEqual_ByteByte_Parms.ReturnValue;
}

struct Core_Subtract_PreVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00000C (0x000C)              
};

FVector3 UObject::Subtract_PreVector(FVector3 A)
{
	static UFieldFunc* pFnSubtract_PreVector = NULL;
	if(!pFnSubtract_PreVector)
		pFnSubtract_PreVector = UObject::FindFunction("Function Core.Object.Subtract_PreVector");

	Core_Subtract_PreVector_Parms Subtract_PreVector_Parms;
	memcpy(&Subtract_PreVector_Parms.A,&A,0xC);

	unsigned short NativeIndex = pFnSubtract_PreVector->iNative;
	pFnSubtract_PreVector->iNative = 0;
	pFnSubtract_PreVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_PreVector,NULL,&Subtract_PreVector_Parms,NULL);
	pFnSubtract_PreVector->FunctionFlags |= 0x400;
	pFnSubtract_PreVector->iNative = NativeIndex;
	return Subtract_PreVector_Parms.ReturnValue;
}

struct Core_Sqrt_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Sqrt(float A)
{
	static UFieldFunc* pFnSqrt = NULL;
	if(!pFnSqrt)
		pFnSqrt = UObject::FindFunction("Function Core.Object.Sqrt");

	Core_Sqrt_Parms Sqrt_Parms;
	Sqrt_Parms.A = A;

	unsigned short NativeIndex = pFnSqrt->iNative;
	pFnSqrt->iNative = 0;
	pFnSqrt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSqrt,NULL,&Sqrt_Parms,NULL);
	pFnSqrt->FunctionFlags |= 0x400;
	pFnSqrt->iNative = NativeIndex;
	return Sqrt_Parms.ReturnValue;
}

struct Core_DRand_Parms
{
	double                                             ReturnValue;                                      		// 0x000000 (0x0008)              
};

double UObject::DRand()
{
	static UFieldFunc* pFnDRand = NULL;
	if(!pFnDRand)
		pFnDRand = UObject::FindFunction("Function Core.Object.DRand");

	Core_DRand_Parms DRand_Parms;

	unsigned short NativeIndex = pFnDRand->iNative;
	pFnDRand->iNative = 0;
	pFnDRand->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDRand,NULL,&DRand_Parms,NULL);
	pFnDRand->FunctionFlags |= 0x400;
	pFnDRand->iNative = NativeIndex;
	return DRand_Parms.ReturnValue;
}

struct Core_DExp_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DExp(double A)
{
	static UFieldFunc* pFnDExp = NULL;
	if(!pFnDExp)
		pFnDExp = UObject::FindFunction("Function Core.Object.DExp");

	Core_DExp_Parms DExp_Parms;
	DExp_Parms.A = A;

	unsigned short NativeIndex = pFnDExp->iNative;
	pFnDExp->iNative = 0;
	pFnDExp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDExp,NULL,&DExp_Parms,NULL);
	pFnDExp->FunctionFlags |= 0x400;
	pFnDExp->iNative = NativeIndex;
	return DExp_Parms.ReturnValue;
}

struct Core_MultiplyEqual_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::MultiplyEqual_VectorVector(FVector3* A,FVector3 B)
{
	static UFieldFunc* pFnMultiplyEqual_VectorVector = NULL;
	if(!pFnMultiplyEqual_VectorVector)
		pFnMultiplyEqual_VectorVector = UObject::FindFunction("Function Core.Object.MultiplyEqual_VectorVector");

	Core_MultiplyEqual_VectorVector_Parms MultiplyEqual_VectorVector_Parms;
	memcpy(&MultiplyEqual_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnMultiplyEqual_VectorVector->iNative;
	pFnMultiplyEqual_VectorVector->iNative = 0;
	pFnMultiplyEqual_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_VectorVector,NULL,&MultiplyEqual_VectorVector_Parms,NULL);
	pFnMultiplyEqual_VectorVector->FunctionFlags |= 0x400;
	pFnMultiplyEqual_VectorVector->iNative = NativeIndex;
	if(A)
		memcpy(A,&MultiplyEqual_VectorVector_Parms.A,0xC);
	return MultiplyEqual_VectorVector_Parms.ReturnValue;
}

struct Core_MakeRotationTranslationMatrix_Parms
{
	FVector3                                           Translation;                                      		// 0x000000 (0x000C)              
	FRotator                                           Rotation;                                         		// 0x00000C (0x000C)              
	unsigned char                                      _0x000018[0x8];                                   		// 0x000018 (0x0008) MISSED OFFSET
	FMatrix                                            ReturnValue;                                      		// 0x000020 (0x0040)              
};

FMatrix UObject::MakeRotationTranslationMatrix(FVector3 Translation,FRotator Rotation)
{
	static UFieldFunc* pFnMakeRotationTranslationMatrix = NULL;
	if(!pFnMakeRotationTranslationMatrix)
		pFnMakeRotationTranslationMatrix = UObject::FindFunction("Function Core.Object.MakeRotationTranslationMatrix");

	Core_MakeRotationTranslationMatrix_Parms MakeRotationTranslationMatrix_Parms;
	memcpy(&MakeRotationTranslationMatrix_Parms.Translation,&Translation,0xC);
	memcpy(&MakeRotationTranslationMatrix_Parms.Rotation,&Rotation,0xC);
	pFnMakeRotationTranslationMatrix->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMakeRotationTranslationMatrix,NULL,&MakeRotationTranslationMatrix_Parms,NULL);
	pFnMakeRotationTranslationMatrix->FunctionFlags |= 0x400;
	return MakeRotationTranslationMatrix_Parms.ReturnValue;
}

struct Core_EqualEqual_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnEqualEqual_VectorVector = NULL;
	if(!pFnEqualEqual_VectorVector)
		pFnEqualEqual_VectorVector = UObject::FindFunction("Function Core.Object.EqualEqual_VectorVector");

	Core_EqualEqual_VectorVector_Parms EqualEqual_VectorVector_Parms;
	memcpy(&EqualEqual_VectorVector_Parms.A,&A,0xC);
	memcpy(&EqualEqual_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnEqualEqual_VectorVector->iNative;
	pFnEqualEqual_VectorVector->iNative = 0;
	pFnEqualEqual_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_VectorVector,NULL,&EqualEqual_VectorVector_Parms,NULL);
	pFnEqualEqual_VectorVector->FunctionFlags |= 0x400;
	pFnEqualEqual_VectorVector->iNative = NativeIndex;
	return EqualEqual_VectorVector_Parms.ReturnValue;
}

struct Core_Subtract_PreInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::Subtract_PreInt(int A)
{
	static UFieldFunc* pFnSubtract_PreInt = NULL;
	if(!pFnSubtract_PreInt)
		pFnSubtract_PreInt = UObject::FindFunction("Function Core.Object.Subtract_PreInt");

	Core_Subtract_PreInt_Parms Subtract_PreInt_Parms;
	Subtract_PreInt_Parms.A = A;

	unsigned short NativeIndex = pFnSubtract_PreInt->iNative;
	pFnSubtract_PreInt->iNative = 0;
	pFnSubtract_PreInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_PreInt,NULL,&Subtract_PreInt_Parms,NULL);
	pFnSubtract_PreInt->FunctionFlags |= 0x400;
	pFnSubtract_PreInt->iNative = NativeIndex;
	return Subtract_PreInt_Parms.ReturnValue;
}

struct Core_DSquare_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DSquare(double A)
{
	static UFieldFunc* pFnDSquare = NULL;
	if(!pFnDSquare)
		pFnDSquare = UObject::FindFunction("Function Core.Object.DSquare");

	Core_DSquare_Parms DSquare_Parms;
	DSquare_Parms.A = A;

	unsigned short NativeIndex = pFnDSquare->iNative;
	pFnDSquare->iNative = 0;
	pFnDSquare->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDSquare,NULL,&DSquare_Parms,NULL);
	pFnDSquare->FunctionFlags |= 0x400;
	pFnDSquare->iNative = NativeIndex;
	return DSquare_Parms.ReturnValue;
}

struct Core_ByteToFloat_Parms
{
	unsigned char                                      inputByte;                                        		// 0x000000 (0x0001)              
	unsigned long                                      bSigned : 1;                                      		// 0x000004 (0x0004) [0x00000001] 
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::ByteToFloat(unsigned char inputByte,bool bSigned)
{
	static UFieldFunc* pFnByteToFloat = NULL;
	if(!pFnByteToFloat)
		pFnByteToFloat = UObject::FindFunction("Function Core.Object.ByteToFloat");

	Core_ByteToFloat_Parms ByteToFloat_Parms;
	ByteToFloat_Parms.inputByte = inputByte;
	ByteToFloat_Parms.bSigned = bSigned;
	ProcessEvent(pFnByteToFloat,NULL,&ByteToFloat_Parms,NULL);
	return ByteToFloat_Parms.ReturnValue;
}

struct Core_IsA_Parms
{
	struct FName                                       ClassName;                                        		// 0x000000 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::IsA(struct FName ClassName)
{
	static UFieldFunc* pFnIsA = NULL;
	if(!pFnIsA)
		pFnIsA = UObject::FindFunction("Function Core.Object.IsA");

	Core_IsA_Parms IsA_Parms;
	memcpy(&IsA_Parms.ClassName,&ClassName,0x8);

	unsigned short NativeIndex = pFnIsA->iNative;
	pFnIsA->iNative = 0;
	pFnIsA->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsA,NULL,&IsA_Parms,NULL);
	pFnIsA->FunctionFlags |= 0x400;
	pFnIsA->iNative = NativeIndex;
	return IsA_Parms.ReturnValue;
}

struct Core_MatrixGetOrigin_Parms
{
	FMatrix                                            TM;                                               		// 0x000000 (0x0040)              
	FVector3                                           ReturnValue;                                      		// 0x000040 (0x000C)              
};

FVector3 UObject::MatrixGetOrigin(FMatrix TM)
{
	static UFieldFunc* pFnMatrixGetOrigin = NULL;
	if(!pFnMatrixGetOrigin)
		pFnMatrixGetOrigin = UObject::FindFunction("Function Core.Object.MatrixGetOrigin");

	Core_MatrixGetOrigin_Parms MatrixGetOrigin_Parms;
	memcpy(&MatrixGetOrigin_Parms.TM,&TM,0x40);
	pFnMatrixGetOrigin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMatrixGetOrigin,NULL,&MatrixGetOrigin_Parms,NULL);
	pFnMatrixGetOrigin->FunctionFlags |= 0x400;
	return MatrixGetOrigin_Parms.ReturnValue;
}

struct Core_DumpStateStack_Parms
{
};

void UObject::DumpStateStack()
{
	static UFieldFunc* pFnDumpStateStack = NULL;
	if(!pFnDumpStateStack)
		pFnDumpStateStack = UObject::FindFunction("Function Core.Object.DumpStateStack");

	Core_DumpStateStack_Parms DumpStateStack_Parms;
	pFnDumpStateStack->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDumpStateStack,NULL,&DumpStateStack_Parms,NULL);
	pFnDumpStateStack->FunctionFlags |= 0x400;
}

struct Core_ClassIsChildOf_Parms
{
	class UClass*                                      TestClass;                                        		// 0x000000 (0x0004)              
	class UClass*                                      ParentClass;                                      		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::ClassIsChildOf(class UClass* TestClass,class UClass* ParentClass)
{
	static UFieldFunc* pFnClassIsChildOf = NULL;
	if(!pFnClassIsChildOf)
		pFnClassIsChildOf = UObject::FindFunction("Function Core.Object.ClassIsChildOf");

	Core_ClassIsChildOf_Parms ClassIsChildOf_Parms;
	ClassIsChildOf_Parms.TestClass = TestClass;
	ClassIsChildOf_Parms.ParentClass = ParentClass;

	unsigned short NativeIndex = pFnClassIsChildOf->iNative;
	pFnClassIsChildOf->iNative = 0;
	pFnClassIsChildOf->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClassIsChildOf,NULL,&ClassIsChildOf_Parms,NULL);
	pFnClassIsChildOf->FunctionFlags |= 0x400;
	pFnClassIsChildOf->iNative = NativeIndex;
	return ClassIsChildOf_Parms.ReturnValue;
}

struct Core_Min_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Min(int A,int B)
{
	static UFieldFunc* pFnMin = NULL;
	if(!pFnMin)
		pFnMin = UObject::FindFunction("Function Core.Object.Min");

	Core_Min_Parms Min_Parms;
	Min_Parms.A = A;
	Min_Parms.B = B;

	unsigned short NativeIndex = pFnMin->iNative;
	pFnMin->iNative = 0;
	pFnMin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMin,NULL,&Min_Parms,NULL);
	pFnMin->FunctionFlags |= 0x400;
	pFnMin->iNative = NativeIndex;
	return Min_Parms.ReturnValue;
}

struct Core_Multiply_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000018 (0x000C)              
};

FVector3 UObject::Multiply_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnMultiply_VectorVector = NULL;
	if(!pFnMultiply_VectorVector)
		pFnMultiply_VectorVector = UObject::FindFunction("Function Core.Object.Multiply_VectorVector");

	Core_Multiply_VectorVector_Parms Multiply_VectorVector_Parms;
	memcpy(&Multiply_VectorVector_Parms.A,&A,0xC);
	memcpy(&Multiply_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnMultiply_VectorVector->iNative;
	pFnMultiply_VectorVector->iNative = 0;
	pFnMultiply_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_VectorVector,NULL,&Multiply_VectorVector_Parms,NULL);
	pFnMultiply_VectorVector->FunctionFlags |= 0x400;
	pFnMultiply_VectorVector->iNative = NativeIndex;
	return Multiply_VectorVector_Parms.ReturnValue;
}

struct Core_GetDotDistance_Parms
{
	FVector2                                           OutDotDist;                                       		// 0x000000 (0x0008)              
	FVector3                                           Direction;                                        		// 0x000008 (0x000C)              
	FVector3                                           AxisX;                                            		// 0x000014 (0x000C)              
	FVector3                                           AxisY;                                            		// 0x000020 (0x000C)              
	FVector3                                           AxisZ;                                            		// 0x00002C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000038 (0x0004) [0x00000001] 
};

bool UObject::GetDotDistance(FVector2* OutDotDist,FVector3 Direction,FVector3 AxisX,FVector3 AxisY,FVector3 AxisZ)
{
	static UFieldFunc* pFnGetDotDistance = NULL;
	if(!pFnGetDotDistance)
		pFnGetDotDistance = UObject::FindFunction("Function Core.Object.GetDotDistance");

	Core_GetDotDistance_Parms GetDotDistance_Parms;
	memcpy(&GetDotDistance_Parms.Direction,&Direction,0xC);
	memcpy(&GetDotDistance_Parms.AxisX,&AxisX,0xC);
	memcpy(&GetDotDistance_Parms.AxisY,&AxisY,0xC);
	memcpy(&GetDotDistance_Parms.AxisZ,&AxisZ,0xC);
	pFnGetDotDistance->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetDotDistance,NULL,&GetDotDistance_Parms,NULL);
	pFnGetDotDistance->FunctionFlags |= 0x400;
	if(OutDotDist)
		memcpy(OutDotDist,&GetDotDistance_Parms.OutDotDist,0x8);
	return GetDotDistance_Parms.ReturnValue;
}

struct Core_ComplementEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::ComplementEqual_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnComplementEqual_StrStr = NULL;
	if(!pFnComplementEqual_StrStr)
		pFnComplementEqual_StrStr = UObject::FindFunction("Function Core.Object.ComplementEqual_StrStr");

	Core_ComplementEqual_StrStr_Parms ComplementEqual_StrStr_Parms;
	memcpy(&ComplementEqual_StrStr_Parms.A,&A,0xC);
	memcpy(&ComplementEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnComplementEqual_StrStr->iNative;
	pFnComplementEqual_StrStr->iNative = 0;
	pFnComplementEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnComplementEqual_StrStr,NULL,&ComplementEqual_StrStr_Parms,NULL);
	pFnComplementEqual_StrStr->FunctionFlags |= 0x400;
	pFnComplementEqual_StrStr->iNative = NativeIndex;
	return ComplementEqual_StrStr_Parms.ReturnValue;
}

struct Core_TransformVector_Parms
{
	FMatrix                                            TM;                                               		// 0x000000 (0x0040)              
	FVector3                                           A;                                                		// 0x000040 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00004C (0x000C)              
};

FVector3 UObject::TransformVector(FMatrix TM,FVector3 A)
{
	static UFieldFunc* pFnTransformVector = NULL;
	if(!pFnTransformVector)
		pFnTransformVector = UObject::FindFunction("Function Core.Object.TransformVector");

	Core_TransformVector_Parms TransformVector_Parms;
	memcpy(&TransformVector_Parms.TM,&TM,0x40);
	memcpy(&TransformVector_Parms.A,&A,0xC);
	pFnTransformVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTransformVector,NULL,&TransformVector_Parms,NULL);
	pFnTransformVector->FunctionFlags |= 0x400;
	return TransformVector_Parms.ReturnValue;
}

struct Core_NotEqual_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnNotEqual_StrStr = NULL;
	if(!pFnNotEqual_StrStr)
		pFnNotEqual_StrStr = UObject::FindFunction("Function Core.Object.NotEqual_StrStr");

	Core_NotEqual_StrStr_Parms NotEqual_StrStr_Parms;
	memcpy(&NotEqual_StrStr_Parms.A,&A,0xC);
	memcpy(&NotEqual_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnNotEqual_StrStr->iNative;
	pFnNotEqual_StrStr->iNative = 0;
	pFnNotEqual_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_StrStr,NULL,&NotEqual_StrStr_Parms,NULL);
	pFnNotEqual_StrStr->FunctionFlags |= 0x400;
	pFnNotEqual_StrStr->iNative = NativeIndex;
	return NotEqual_StrStr_Parms.ReturnValue;
}

struct Core_FindObject_Parms
{
	struct FString                                     ObjectName;                                       		// 0x000000 (0x000C)              
	class UClass*                                      ObjectClass;                                      		// 0x00000C (0x0004)              
	class UObject*                                     ReturnValue;                                      		// 0x000010 (0x0004)              
};

class UObject* UObject::FindObject(struct FString ObjectName,class UClass* ObjectClass)
{
	static UFieldFunc* pFnFindObject = NULL;
	if(!pFnFindObject)
		pFnFindObject = UObject::FindFunction("Function Core.Object.FindObject");

	Core_FindObject_Parms FindObject_Parms;
	memcpy(&FindObject_Parms.ObjectName,&ObjectName,0xC);
	FindObject_Parms.ObjectClass = ObjectClass;
	pFnFindObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFindObject,NULL,&FindObject_Parms,NULL);
	pFnFindObject->FunctionFlags |= 0x400;
	return FindObject_Parms.ReturnValue;
}

struct Core_Repl_Parms
{
	struct FString                                     Src;                                              		// 0x000000 (0x000C)              
	struct FString                                     Match;                                            		// 0x00000C (0x000C)              
	struct FString                                     With;                                             		// 0x000018 (0x000C)              
	unsigned long                                      bCaseSensitive : 1;                               		// 0x000024 (0x0004) [0x00000001] 
	struct FString                                     ReturnValue;                                      		// 0x000028 (0x000C)              
};

struct FString UObject::Repl(struct FString Src,struct FString Match,struct FString With,bool bCaseSensitive)
{
	static UFieldFunc* pFnRepl = NULL;
	if(!pFnRepl)
		pFnRepl = UObject::FindFunction("Function Core.Object.Repl");

	Core_Repl_Parms Repl_Parms;
	memcpy(&Repl_Parms.Src,&Src,0xC);
	memcpy(&Repl_Parms.Match,&Match,0xC);
	memcpy(&Repl_Parms.With,&With,0xC);
	Repl_Parms.bCaseSensitive = bCaseSensitive;

	unsigned short NativeIndex = pFnRepl->iNative;
	pFnRepl->iNative = 0;
	pFnRepl->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRepl,NULL,&Repl_Parms,NULL);
	pFnRepl->FunctionFlags |= 0x400;
	pFnRepl->iNative = NativeIndex;
	return Repl_Parms.ReturnValue;
}

struct Core_Dot_VectorVector_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	FVector3                                           B;                                                		// 0x00000C (0x000C)              
	float                                              ReturnValue;                                      		// 0x000018 (0x0004)              
};

float UObject::Dot_VectorVector(FVector3 A,FVector3 B)
{
	static UFieldFunc* pFnDot_VectorVector = NULL;
	if(!pFnDot_VectorVector)
		pFnDot_VectorVector = UObject::FindFunction("Function Core.Object.Dot_VectorVector");

	Core_Dot_VectorVector_Parms Dot_VectorVector_Parms;
	memcpy(&Dot_VectorVector_Parms.A,&A,0xC);
	memcpy(&Dot_VectorVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnDot_VectorVector->iNative;
	pFnDot_VectorVector->iNative = 0;
	pFnDot_VectorVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDot_VectorVector,NULL,&Dot_VectorVector_Parms,NULL);
	pFnDot_VectorVector->FunctionFlags |= 0x400;
	pFnDot_VectorVector->iNative = NativeIndex;
	return Dot_VectorVector_Parms.ReturnValue;
}

struct Core_DSin_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::DSin(double A)
{
	static UFieldFunc* pFnDSin = NULL;
	if(!pFnDSin)
		pFnDSin = UObject::FindFunction("Function Core.Object.DSin");

	Core_DSin_Parms DSin_Parms;
	DSin_Parms.A = A;

	unsigned short NativeIndex = pFnDSin->iNative;
	pFnDSin->iNative = 0;
	pFnDSin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDSin,NULL,&DSin_Parms,NULL);
	pFnDSin->FunctionFlags |= 0x400;
	pFnDSin->iNative = NativeIndex;
	return DSin_Parms.ReturnValue;
}

struct Core_GreaterGreater_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::GreaterGreater_IntInt(int A,int B)
{
	static UFieldFunc* pFnGreaterGreater_IntInt = NULL;
	if(!pFnGreaterGreater_IntInt)
		pFnGreaterGreater_IntInt = UObject::FindFunction("Function Core.Object.GreaterGreater_IntInt");

	Core_GreaterGreater_IntInt_Parms GreaterGreater_IntInt_Parms;
	GreaterGreater_IntInt_Parms.A = A;
	GreaterGreater_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnGreaterGreater_IntInt->iNative;
	pFnGreaterGreater_IntInt->iNative = 0;
	pFnGreaterGreater_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreaterGreater_IntInt,NULL,&GreaterGreater_IntInt_Parms,NULL);
	pFnGreaterGreater_IntInt->FunctionFlags |= 0x400;
	pFnGreaterGreater_IntInt->iNative = NativeIndex;
	return GreaterGreater_IntInt_Parms.ReturnValue;
}

struct Core_QuatDot_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	struct FQuat                                       B;                                                		// 0x000010 (0x0010)              
	float                                              ReturnValue;                                      		// 0x000020 (0x0004)              
};

float UObject::QuatDot(struct FQuat A,struct FQuat B)
{
	static UFieldFunc* pFnQuatDot = NULL;
	if(!pFnQuatDot)
		pFnQuatDot = UObject::FindFunction("Function Core.Object.QuatDot");

	Core_QuatDot_Parms QuatDot_Parms;
	memcpy(&QuatDot_Parms.A,&A,0x10);
	memcpy(&QuatDot_Parms.B,&B,0x10);
	pFnQuatDot->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatDot,NULL,&QuatDot_Parms,NULL);
	pFnQuatDot->FunctionFlags |= 0x400;
	return QuatDot_Parms.ReturnValue;
}

struct Core_PushedState_Parms
{
};

void UObject::PushedState()
{
	static UFieldFunc* pFnPushedState = NULL;
	if(!pFnPushedState)
		pFnPushedState = UObject::FindFunction("Function Core.Object.PushedState");

	Core_PushedState_Parms PushedState_Parms;
	ProcessEvent(pFnPushedState,NULL,&PushedState_Parms,NULL);
}

struct Core_AddToRoot_Parms
{
};

void UObject::AddToRoot()
{
	static UFieldFunc* pFnAddToRoot = NULL;
	if(!pFnAddToRoot)
		pFnAddToRoot = UObject::FindFunction("Function Core.Object.AddToRoot");

	Core_AddToRoot_Parms AddToRoot_Parms;
	pFnAddToRoot->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddToRoot,NULL,&AddToRoot_Parms,NULL);
	pFnAddToRoot->FunctionFlags |= 0x400;
}

struct Core_Acos_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Acos(float A)
{
	static UFieldFunc* pFnAcos = NULL;
	if(!pFnAcos)
		pFnAcos = UObject::FindFunction("Function Core.Object.Acos");

	Core_Acos_Parms Acos_Parms;
	Acos_Parms.A = A;
	pFnAcos->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAcos,NULL,&Acos_Parms,NULL);
	pFnAcos->FunctionFlags |= 0x400;
	return Acos_Parms.ReturnValue;
}

struct Core_RandRange_Parms
{
	float                                              InMin;                                            		// 0x000000 (0x0004)              
	float                                              InMax;                                            		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::RandRange(float InMin,float InMax)
{
	static UFieldFunc* pFnRandRange = NULL;
	if(!pFnRandRange)
		pFnRandRange = UObject::FindFunction("Function Core.Object.RandRange");

	Core_RandRange_Parms RandRange_Parms;
	RandRange_Parms.InMin = InMin;
	RandRange_Parms.InMax = InMax;
	ProcessEvent(pFnRandRange,NULL,&RandRange_Parms,NULL);
	return RandRange_Parms.ReturnValue;
}

struct Core_RemoveFromRoot_Parms
{
};

void UObject::RemoveFromRoot()
{
	static UFieldFunc* pFnRemoveFromRoot = NULL;
	if(!pFnRemoveFromRoot)
		pFnRemoveFromRoot = UObject::FindFunction("Function Core.Object.RemoveFromRoot");

	Core_RemoveFromRoot_Parms RemoveFromRoot_Parms;
	pFnRemoveFromRoot->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRemoveFromRoot,NULL,&RemoveFromRoot_Parms,NULL);
	pFnRemoveFromRoot->FunctionFlags |= 0x400;
}

struct Core_Sin_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Sin(float A)
{
	static UFieldFunc* pFnSin = NULL;
	if(!pFnSin)
		pFnSin = UObject::FindFunction("Function Core.Object.Sin");

	Core_Sin_Parms Sin_Parms;
	Sin_Parms.A = A;

	unsigned short NativeIndex = pFnSin->iNative;
	pFnSin->iNative = 0;
	pFnSin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSin,NULL,&Sin_Parms,NULL);
	pFnSin->FunctionFlags |= 0x400;
	pFnSin->iNative = NativeIndex;
	return Sin_Parms.ReturnValue;
}

struct Core_Multiply_FloatVector_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	FVector3                                           B;                                                		// 0x000004 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x000010 (0x000C)              
};

FVector3 UObject::Multiply_FloatVector(float A,FVector3 B)
{
	static UFieldFunc* pFnMultiply_FloatVector = NULL;
	if(!pFnMultiply_FloatVector)
		pFnMultiply_FloatVector = UObject::FindFunction("Function Core.Object.Multiply_FloatVector");

	Core_Multiply_FloatVector_Parms Multiply_FloatVector_Parms;
	Multiply_FloatVector_Parms.A = A;
	memcpy(&Multiply_FloatVector_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnMultiply_FloatVector->iNative;
	pFnMultiply_FloatVector->iNative = 0;
	pFnMultiply_FloatVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_FloatVector,NULL,&Multiply_FloatVector_Parms,NULL);
	pFnMultiply_FloatVector->FunctionFlags |= 0x400;
	pFnMultiply_FloatVector->iNative = NativeIndex;
	return Multiply_FloatVector_Parms.ReturnValue;
}

struct Core_Subtract_QuatQuat_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	struct FQuat                                       B;                                                		// 0x000010 (0x0010)              
	struct FQuat                                       ReturnValue;                                      		// 0x000020 (0x0010)              
};

struct FQuat UObject::Subtract_QuatQuat(struct FQuat A,struct FQuat B)
{
	static UFieldFunc* pFnSubtract_QuatQuat = NULL;
	if(!pFnSubtract_QuatQuat)
		pFnSubtract_QuatQuat = UObject::FindFunction("Function Core.Object.Subtract_QuatQuat");

	Core_Subtract_QuatQuat_Parms Subtract_QuatQuat_Parms;
	memcpy(&Subtract_QuatQuat_Parms.A,&A,0x10);
	memcpy(&Subtract_QuatQuat_Parms.B,&B,0x10);

	unsigned short NativeIndex = pFnSubtract_QuatQuat->iNative;
	pFnSubtract_QuatQuat->iNative = 0;
	pFnSubtract_QuatQuat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_QuatQuat,NULL,&Subtract_QuatQuat_Parms,NULL);
	pFnSubtract_QuatQuat->FunctionFlags |= 0x400;
	pFnSubtract_QuatQuat->iNative = NativeIndex;
	return Subtract_QuatQuat_Parms.ReturnValue;
}

struct Core_Divide_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000008 (0x0004)              
};

int UObject::Divide_IntInt(int A,int B)
{
	static UFieldFunc* pFnDivide_IntInt = NULL;
	if(!pFnDivide_IntInt)
		pFnDivide_IntInt = UObject::FindFunction("Function Core.Object.Divide_IntInt");

	Core_Divide_IntInt_Parms Divide_IntInt_Parms;
	Divide_IntInt_Parms.A = A;
	Divide_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnDivide_IntInt->iNative;
	pFnDivide_IntInt->iNative = 0;
	pFnDivide_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivide_IntInt,NULL,&Divide_IntInt_Parms,NULL);
	pFnDivide_IntInt->FunctionFlags |= 0x400;
	pFnDivide_IntInt->iNative = NativeIndex;
	return Divide_IntInt_Parms.ReturnValue;
}

struct Core_SClampRotAxis_Parms
{
	float                                              DeltaTime;                                        		// 0x000000 (0x0004)              
	int                                                ViewAxis;                                         		// 0x000004 (0x0004)              
	int                                                out_DeltaViewAxis;                                		// 0x000008 (0x0004)              
	int                                                MaxLimit;                                         		// 0x00000C (0x0004)              
	int                                                MinLimit;                                         		// 0x000010 (0x0004)              
	float                                              InterpolationSpeed;                               		// 0x000014 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
	//unsigned long                                      bClamped : 1;                                     		// 0x00001C (0x0004) [0x00000001] 
};

bool UObject::SClampRotAxis(float DeltaTime,int ViewAxis,int* out_DeltaViewAxis,int MaxLimit,int MinLimit,float InterpolationSpeed)
{
	static UFieldFunc* pFnSClampRotAxis = NULL;
	if(!pFnSClampRotAxis)
		pFnSClampRotAxis = UObject::FindFunction("Function Core.Object.SClampRotAxis");

	Core_SClampRotAxis_Parms SClampRotAxis_Parms;
	SClampRotAxis_Parms.DeltaTime = DeltaTime;
	SClampRotAxis_Parms.ViewAxis = ViewAxis;
	SClampRotAxis_Parms.MaxLimit = MaxLimit;
	SClampRotAxis_Parms.MinLimit = MinLimit;
	SClampRotAxis_Parms.InterpolationSpeed = InterpolationSpeed;
	ProcessEvent(pFnSClampRotAxis,NULL,&SClampRotAxis_Parms,NULL);
	if(out_DeltaViewAxis)
		*out_DeltaViewAxis = SClampRotAxis_Parms.out_DeltaViewAxis;
	return SClampRotAxis_Parms.ReturnValue;
}

struct Core_ColorToLinearColor_Parms
{
	DWORD                                              OldColor;                                         		// 0x000000 (0x0004)              
	struct FLinearColor                                ReturnValue;                                      		// 0x000004 (0x0010)              
};

struct FLinearColor UObject::ColorToLinearColor(DWORD OldColor)
{
	static UFieldFunc* pFnColorToLinearColor = NULL;
	if(!pFnColorToLinearColor)
		pFnColorToLinearColor = UObject::FindFunction("Function Core.Object.ColorToLinearColor");

	Core_ColorToLinearColor_Parms ColorToLinearColor_Parms;
	memcpy(&ColorToLinearColor_Parms.OldColor,&OldColor,0x4);
	ProcessEvent(pFnColorToLinearColor,NULL,&ColorToLinearColor_Parms,NULL);
	return ColorToLinearColor_Parms.ReturnValue;
}

struct Core_Caps_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UObject::Caps(struct FString S)
{
	static UFieldFunc* pFnCaps = NULL;
	if(!pFnCaps)
		pFnCaps = UObject::FindFunction("Function Core.Object.Caps");

	Core_Caps_Parms Caps_Parms;
	memcpy(&Caps_Parms.S,&S,0xC);

	unsigned short NativeIndex = pFnCaps->iNative;
	pFnCaps->iNative = 0;
	pFnCaps->FunctionFlags |= ~0x400;
	ProcessEvent(pFnCaps,NULL,&Caps_Parms,NULL);
	pFnCaps->FunctionFlags |= 0x400;
	pFnCaps->iNative = NativeIndex;
	return Caps_Parms.ReturnValue;
}

struct Core_UnwindHeading_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::UnwindHeading(float A)
{
	static UFieldFunc* pFnUnwindHeading = NULL;
	if(!pFnUnwindHeading)
		pFnUnwindHeading = UObject::FindFunction("Function Core.Object.UnwindHeading");

	Core_UnwindHeading_Parms UnwindHeading_Parms;
	UnwindHeading_Parms.A = A;
	ProcessEvent(pFnUnwindHeading,NULL,&UnwindHeading_Parms,NULL);
	return UnwindHeading_Parms.ReturnValue;
}

struct Core_FClamp_Parms
{
	float                                              V;                                                		// 0x000000 (0x0004)              
	float                                              A;                                                		// 0x000004 (0x0004)              
	float                                              B;                                                		// 0x000008 (0x0004)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::FClamp(float V,float A,float B)
{
	static UFieldFunc* pFnFClamp = NULL;
	if(!pFnFClamp)
		pFnFClamp = UObject::FindFunction("Function Core.Object.FClamp");

	Core_FClamp_Parms FClamp_Parms;
	FClamp_Parms.V = V;
	FClamp_Parms.A = A;
	FClamp_Parms.B = B;

	unsigned short NativeIndex = pFnFClamp->iNative;
	pFnFClamp->iNative = 0;
	pFnFClamp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnFClamp,NULL,&FClamp_Parms,NULL);
	pFnFClamp->FunctionFlags |= 0x400;
	pFnFClamp->iNative = NativeIndex;
	return FClamp_Parms.ReturnValue;
}

struct Core_Percent_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::Percent_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnPercent_DoubleDouble = NULL;
	if(!pFnPercent_DoubleDouble)
		pFnPercent_DoubleDouble = UObject::FindFunction("Function Core.Object.Percent_DoubleDouble");

	Core_Percent_DoubleDouble_Parms Percent_DoubleDouble_Parms;
	Percent_DoubleDouble_Parms.A = A;
	Percent_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnPercent_DoubleDouble->iNative;
	pFnPercent_DoubleDouble->iNative = 0;
	pFnPercent_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnPercent_DoubleDouble,NULL,&Percent_DoubleDouble_Parms,NULL);
	pFnPercent_DoubleDouble->FunctionFlags |= 0x400;
	pFnPercent_DoubleDouble->iNative = NativeIndex;
	return Percent_DoubleDouble_Parms.ReturnValue;
}

struct Core_TransformNormal_Parms
{
	FMatrix                                            TM;                                               		// 0x000000 (0x0040)              
	FVector3                                           A;                                                		// 0x000040 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00004C (0x000C)              
};

FVector3 UObject::TransformNormal(FMatrix TM,FVector3 A)
{
	static UFieldFunc* pFnTransformNormal = NULL;
	if(!pFnTransformNormal)
		pFnTransformNormal = UObject::FindFunction("Function Core.Object.TransformNormal");

	Core_TransformNormal_Parms TransformNormal_Parms;
	memcpy(&TransformNormal_Parms.TM,&TM,0x40);
	memcpy(&TransformNormal_Parms.A,&A,0xC);
	pFnTransformNormal->FunctionFlags |= ~0x400;
	ProcessEvent(pFnTransformNormal,NULL,&TransformNormal_Parms,NULL);
	pFnTransformNormal->FunctionFlags |= 0x400;
	return TransformNormal_Parms.ReturnValue;
}

struct Core_EqualEqual_IntInt_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_IntInt(int A,int B)
{
	static UFieldFunc* pFnEqualEqual_IntInt = NULL;
	if(!pFnEqualEqual_IntInt)
		pFnEqualEqual_IntInt = UObject::FindFunction("Function Core.Object.EqualEqual_IntInt");

	Core_EqualEqual_IntInt_Parms EqualEqual_IntInt_Parms;
	EqualEqual_IntInt_Parms.A = A;
	EqualEqual_IntInt_Parms.B = B;

	unsigned short NativeIndex = pFnEqualEqual_IntInt->iNative;
	pFnEqualEqual_IntInt->iNative = 0;
	pFnEqualEqual_IntInt->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_IntInt,NULL,&EqualEqual_IntInt_Parms,NULL);
	pFnEqualEqual_IntInt->FunctionFlags |= 0x400;
	pFnEqualEqual_IntInt->iNative = NativeIndex;
	return EqualEqual_IntInt_Parms.ReturnValue;
}

struct Core_ComplementEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::ComplementEqual_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnComplementEqual_DoubleDouble = NULL;
	if(!pFnComplementEqual_DoubleDouble)
		pFnComplementEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.ComplementEqual_DoubleDouble");

	Core_ComplementEqual_DoubleDouble_Parms ComplementEqual_DoubleDouble_Parms;
	ComplementEqual_DoubleDouble_Parms.A = A;
	ComplementEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnComplementEqual_DoubleDouble->iNative;
	pFnComplementEqual_DoubleDouble->iNative = 0;
	pFnComplementEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnComplementEqual_DoubleDouble,NULL,&ComplementEqual_DoubleDouble_Parms,NULL);
	pFnComplementEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnComplementEqual_DoubleDouble->iNative = NativeIndex;
	return ComplementEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_SetGameEpoch_Parms
{
	unsigned char                                      eNewEpoch;                                        		// 0x000000 (0x0001)              
};

void UObject::SetGameEpoch(unsigned char eNewEpoch)
{
	static UFieldFunc* pFnSetGameEpoch = NULL;
	if(!pFnSetGameEpoch)
		pFnSetGameEpoch = UObject::FindFunction("Function Core.Object.SetGameEpoch");

	Core_SetGameEpoch_Parms SetGameEpoch_Parms;
	SetGameEpoch_Parms.eNewEpoch = eNewEpoch;
	pFnSetGameEpoch->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSetGameEpoch,NULL,&SetGameEpoch_Parms,NULL);
	pFnSetGameEpoch->FunctionFlags |= 0x400;
}

struct Core_NormalizeRotAxis_Parms
{
	int                                                Angle;                                            		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::NormalizeRotAxis(int Angle)
{
	static UFieldFunc* pFnNormalizeRotAxis = NULL;
	if(!pFnNormalizeRotAxis)
		pFnNormalizeRotAxis = UObject::FindFunction("Function Core.Object.NormalizeRotAxis");

	Core_NormalizeRotAxis_Parms NormalizeRotAxis_Parms;
	NormalizeRotAxis_Parms.Angle = Angle;
	pFnNormalizeRotAxis->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNormalizeRotAxis,NULL,&NormalizeRotAxis_Parms,NULL);
	pFnNormalizeRotAxis->FunctionFlags |= 0x400;
	return NormalizeRotAxis_Parms.ReturnValue;
}

struct Core_Rand_Parms
{
	int                                                Max;                                              		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::Rand(int Max)
{
	static UFieldFunc* pFnRand = NULL;
	if(!pFnRand)
		pFnRand = UObject::FindFunction("Function Core.Object.Rand");

	Core_Rand_Parms Rand_Parms;
	Rand_Parms.Max = Max;

	unsigned short NativeIndex = pFnRand->iNative;
	pFnRand->iNative = 0;
	pFnRand->FunctionFlags |= ~0x400;
	ProcessEvent(pFnRand,NULL,&Rand_Parms,NULL);
	pFnRand->FunctionFlags |= 0x400;
	pFnRand->iNative = NativeIndex;
	return Rand_Parms.ReturnValue;
}

struct Core_NotEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnNotEqual_DoubleDouble = NULL;
	if(!pFnNotEqual_DoubleDouble)
		pFnNotEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.NotEqual_DoubleDouble");

	Core_NotEqual_DoubleDouble_Parms NotEqual_DoubleDouble_Parms;
	NotEqual_DoubleDouble_Parms.A = A;
	NotEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnNotEqual_DoubleDouble->iNative;
	pFnNotEqual_DoubleDouble->iNative = 0;
	pFnNotEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_DoubleDouble,NULL,&NotEqual_DoubleDouble_Parms,NULL);
	pFnNotEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnNotEqual_DoubleDouble->iNative = NativeIndex;
	return NotEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_XorXor_BoolBool_Parms
{
	unsigned long                                      A : 1;                                            		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::XorXor_BoolBool(bool A,bool B)
{
	static UFieldFunc* pFnXorXor_BoolBool = NULL;
	if(!pFnXorXor_BoolBool)
		pFnXorXor_BoolBool = UObject::FindFunction("Function Core.Object.XorXor_BoolBool");

	Core_XorXor_BoolBool_Parms XorXor_BoolBool_Parms;
	XorXor_BoolBool_Parms.A = A;
	XorXor_BoolBool_Parms.B = B;

	unsigned short NativeIndex = pFnXorXor_BoolBool->iNative;
	pFnXorXor_BoolBool->iNative = 0;
	pFnXorXor_BoolBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnXorXor_BoolBool,NULL,&XorXor_BoolBool_Parms,NULL);
	pFnXorXor_BoolBool->FunctionFlags |= 0x400;
	pFnXorXor_BoolBool->iNative = NativeIndex;
	return XorXor_BoolBool_Parms.ReturnValue;
}

struct Core_ContinuedState_Parms
{
};

void UObject::ContinuedState()
{
	static UFieldFunc* pFnContinuedState = NULL;
	if(!pFnContinuedState)
		pFnContinuedState = UObject::FindFunction("Function Core.Object.ContinuedState");

	Core_ContinuedState_Parms ContinuedState_Parms;
	ProcessEvent(pFnContinuedState,NULL,&ContinuedState_Parms,NULL);
}

struct Core_MatrixGetRotator_Parms
{
	FMatrix                                            TM;                                               		// 0x000000 (0x0040)              
	FRotator                                           ReturnValue;                                      		// 0x000040 (0x000C)              
};

FRotator UObject::MatrixGetRotator(FMatrix TM)
{
	static UFieldFunc* pFnMatrixGetRotator = NULL;
	if(!pFnMatrixGetRotator)
		pFnMatrixGetRotator = UObject::FindFunction("Function Core.Object.MatrixGetRotator");

	Core_MatrixGetRotator_Parms MatrixGetRotator_Parms;
	memcpy(&MatrixGetRotator_Parms.TM,&TM,0x40);
	pFnMatrixGetRotator->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMatrixGetRotator,NULL,&MatrixGetRotator_Parms,NULL);
	pFnMatrixGetRotator->FunctionFlags |= 0x400;
	return MatrixGetRotator_Parms.ReturnValue;
}

struct Core_Locs_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
};

struct FString UObject::Locs(struct FString S)
{
	static UFieldFunc* pFnLocs = NULL;
	if(!pFnLocs)
		pFnLocs = UObject::FindFunction("Function Core.Object.Locs");

	Core_Locs_Parms Locs_Parms;
	memcpy(&Locs_Parms.S,&S,0xC);

	unsigned short NativeIndex = pFnLocs->iNative;
	pFnLocs->iNative = 0;
	pFnLocs->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLocs,NULL,&Locs_Parms,NULL);
	pFnLocs->FunctionFlags |= 0x400;
	pFnLocs->iNative = NativeIndex;
	return Locs_Parms.ReturnValue;
}

struct Core_Add_QuatQuat_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	struct FQuat                                       B;                                                		// 0x000010 (0x0010)              
	struct FQuat                                       ReturnValue;                                      		// 0x000020 (0x0010)              
};

struct FQuat UObject::Add_QuatQuat(struct FQuat A,struct FQuat B)
{
	static UFieldFunc* pFnAdd_QuatQuat = NULL;
	if(!pFnAdd_QuatQuat)
		pFnAdd_QuatQuat = UObject::FindFunction("Function Core.Object.Add_QuatQuat");

	Core_Add_QuatQuat_Parms Add_QuatQuat_Parms;
	memcpy(&Add_QuatQuat_Parms.A,&A,0x10);
	memcpy(&Add_QuatQuat_Parms.B,&B,0x10);

	unsigned short NativeIndex = pFnAdd_QuatQuat->iNative;
	pFnAdd_QuatQuat->iNative = 0;
	pFnAdd_QuatQuat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdd_QuatQuat,NULL,&Add_QuatQuat_Parms,NULL);
	pFnAdd_QuatQuat->FunctionFlags |= 0x400;
	pFnAdd_QuatQuat->iNative = NativeIndex;
	return Add_QuatQuat_Parms.ReturnValue;
}

struct Core_DynamicLoadObject_Parms
{
	struct FString                                     ObjectName;                                       		// 0x000000 (0x000C)              
	class UClass*                                      ObjectClass;                                      		// 0x00000C (0x0004)              
	unsigned long                                      MayFail : 1;                                      		// 0x000010 (0x0004) [0x00000001] 
	class UObject*                                     ReturnValue;                                      		// 0x000014 (0x0004)              
};

class UObject* UObject::DynamicLoadObject(struct FString ObjectName,class UClass* ObjectClass,bool MayFail)
{
	static UFieldFunc* pFnDynamicLoadObject = NULL;
	if(!pFnDynamicLoadObject)
		pFnDynamicLoadObject = UObject::FindFunction("Function Core.Object.DynamicLoadObject");

	Core_DynamicLoadObject_Parms DynamicLoadObject_Parms;
	memcpy(&DynamicLoadObject_Parms.ObjectName,&ObjectName,0xC);
	DynamicLoadObject_Parms.ObjectClass = ObjectClass;
	DynamicLoadObject_Parms.MayFail = MayFail;
	pFnDynamicLoadObject->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDynamicLoadObject,NULL,&DynamicLoadObject_Parms,NULL);
	pFnDynamicLoadObject->FunctionFlags |= 0x400;
	return DynamicLoadObject_Parms.ReturnValue;
}

struct Core_PoppedState_Parms
{
};

void UObject::PoppedState()
{
	static UFieldFunc* pFnPoppedState = NULL;
	if(!pFnPoppedState)
		pFnPoppedState = UObject::FindFunction("Function Core.Object.PoppedState");

	Core_PoppedState_Parms PoppedState_Parms;
	ProcessEvent(pFnPoppedState,NULL,&PoppedState_Parms,NULL);
}

struct Core_Split_Parms
{
	struct FString                                     Text;                                             		// 0x000000 (0x000C)              
	struct FString                                     SplitStr;                                         		// 0x00000C (0x000C)              
	unsigned long                                      bOmitSplitStr : 1;                                		// 0x000018 (0x0004) [0x00000001] 
	struct FString                                     ReturnValue;                                      		// 0x00001C (0x000C)              
	//int                                                pos;                                              		// 0x000028 (0x0004)              
};

struct FString UObject::Split(struct FString Text,struct FString SplitStr,bool bOmitSplitStr)
{
	static UFieldFunc* pFnSplit = NULL;
	if(!pFnSplit)
		pFnSplit = UObject::FindFunction("Function Core.Object.Split");

	Core_Split_Parms Split_Parms;
	memcpy(&Split_Parms.Text,&Text,0xC);
	memcpy(&Split_Parms.SplitStr,&SplitStr,0xC);
	Split_Parms.bOmitSplitStr = bOmitSplitStr;
	ProcessEvent(pFnSplit,NULL,&Split_Parms,NULL);
	return Split_Parms.ReturnValue;
}

struct Core_EqualEqual_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnEqualEqual_FloatFloat = NULL;
	if(!pFnEqualEqual_FloatFloat)
		pFnEqualEqual_FloatFloat = UObject::FindFunction("Function Core.Object.EqualEqual_FloatFloat");

	Core_EqualEqual_FloatFloat_Parms EqualEqual_FloatFloat_Parms;
	EqualEqual_FloatFloat_Parms.A = A;
	EqualEqual_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnEqualEqual_FloatFloat->iNative;
	pFnEqualEqual_FloatFloat->iNative = 0;
	pFnEqualEqual_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_FloatFloat,NULL,&EqualEqual_FloatFloat_Parms,NULL);
	pFnEqualEqual_FloatFloat->FunctionFlags |= 0x400;
	pFnEqualEqual_FloatFloat->iNative = NativeIndex;
	return EqualEqual_FloatFloat_Parms.ReturnValue;
}

struct Core_Add_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::Add_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnAdd_FloatFloat = NULL;
	if(!pFnAdd_FloatFloat)
		pFnAdd_FloatFloat = UObject::FindFunction("Function Core.Object.Add_FloatFloat");

	Core_Add_FloatFloat_Parms Add_FloatFloat_Parms;
	Add_FloatFloat_Parms.A = A;
	Add_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnAdd_FloatFloat->iNative;
	pFnAdd_FloatFloat->iNative = 0;
	pFnAdd_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdd_FloatFloat,NULL,&Add_FloatFloat_Parms,NULL);
	pFnAdd_FloatFloat->FunctionFlags |= 0x400;
	pFnAdd_FloatFloat->iNative = NativeIndex;
	return Add_FloatFloat_Parms.ReturnValue;
}

struct Core_MultiplyEqual_ByteByte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      B;                                                		// 0x000001 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000002 (0x0001)              
};

unsigned char UObject::MultiplyEqual_ByteByte(unsigned char* A,unsigned char B)
{
	static UFieldFunc* pFnMultiplyEqual_ByteByte = NULL;
	if(!pFnMultiplyEqual_ByteByte)
		pFnMultiplyEqual_ByteByte = UObject::FindFunction("Function Core.Object.MultiplyEqual_ByteByte");

	Core_MultiplyEqual_ByteByte_Parms MultiplyEqual_ByteByte_Parms;
	MultiplyEqual_ByteByte_Parms.B = B;

	unsigned short NativeIndex = pFnMultiplyEqual_ByteByte->iNative;
	pFnMultiplyEqual_ByteByte->iNative = 0;
	pFnMultiplyEqual_ByteByte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiplyEqual_ByteByte,NULL,&MultiplyEqual_ByteByte_Parms,NULL);
	pFnMultiplyEqual_ByteByte->FunctionFlags |= 0x400;
	pFnMultiplyEqual_ByteByte->iNative = NativeIndex;
	if(A)
		*A = MultiplyEqual_ByteByte_Parms.A;
	return MultiplyEqual_ByteByte_Parms.ReturnValue;
}

struct Core_JoinArray_Parms
{
	TArray<struct FString>                             StringArray;                                      		// 0x000000 (0x000C)              
	struct FString                                     out_Result;                                       		// 0x00000C (0x000C)              
	struct FString                                     delim;                                            		// 0x000018 (0x000C)              
	unsigned long                                      bIgnoreBlanks : 1;                                		// 0x000024 (0x0004) [0x00000001] 
	//int                                                I;                                                		// 0x000028 (0x0004)              
};

void UObject::JoinArray(TArray<struct FString> StringArray,struct FString* out_Result,struct FString delim,bool bIgnoreBlanks)
{
	static UFieldFunc* pFnJoinArray = NULL;
	if(!pFnJoinArray)
		pFnJoinArray = UObject::FindFunction("Function Core.Object.JoinArray");

	Core_JoinArray_Parms JoinArray_Parms;
	memcpy(&JoinArray_Parms.StringArray,&StringArray,0xC);
	memcpy(&JoinArray_Parms.delim,&delim,0xC);
	JoinArray_Parms.bIgnoreBlanks = bIgnoreBlanks;
	ProcessEvent(pFnJoinArray,NULL,&JoinArray_Parms,NULL);
	if(out_Result)
		memcpy(out_Result,&JoinArray_Parms.out_Result,0xC);
}

struct Core_Subtract_PreDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000008 (0x0008)              
};

double UObject::Subtract_PreDouble(double A)
{
	static UFieldFunc* pFnSubtract_PreDouble = NULL;
	if(!pFnSubtract_PreDouble)
		pFnSubtract_PreDouble = UObject::FindFunction("Function Core.Object.Subtract_PreDouble");

	Core_Subtract_PreDouble_Parms Subtract_PreDouble_Parms;
	Subtract_PreDouble_Parms.A = A;

	unsigned short NativeIndex = pFnSubtract_PreDouble->iNative;
	pFnSubtract_PreDouble->iNative = 0;
	pFnSubtract_PreDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtract_PreDouble,NULL,&Subtract_PreDouble_Parms,NULL);
	pFnSubtract_PreDouble->FunctionFlags |= 0x400;
	pFnSubtract_PreDouble->iNative = NativeIndex;
	return Subtract_PreDouble_Parms.ReturnValue;
}

struct Core_EqualEqual_BoolBool_Parms
{
	unsigned long                                      A : 1;                                            		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::EqualEqual_BoolBool(bool A,bool B)
{
	static UFieldFunc* pFnEqualEqual_BoolBool = NULL;
	if(!pFnEqualEqual_BoolBool)
		pFnEqualEqual_BoolBool = UObject::FindFunction("Function Core.Object.EqualEqual_BoolBool");

	Core_EqualEqual_BoolBool_Parms EqualEqual_BoolBool_Parms;
	EqualEqual_BoolBool_Parms.A = A;
	EqualEqual_BoolBool_Parms.B = B;

	unsigned short NativeIndex = pFnEqualEqual_BoolBool->iNative;
	pFnEqualEqual_BoolBool->iNative = 0;
	pFnEqualEqual_BoolBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnEqualEqual_BoolBool,NULL,&EqualEqual_BoolBool_Parms,NULL);
	pFnEqualEqual_BoolBool->FunctionFlags |= 0x400;
	pFnEqualEqual_BoolBool->iNative = NativeIndex;
	return EqualEqual_BoolBool_Parms.ReturnValue;
}

struct Core_IsZero_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x00000C (0x0004) [0x00000001] 
};

bool UObject::IsZero(FVector3 A)
{
	static UFieldFunc* pFnIsZero = NULL;
	if(!pFnIsZero)
		pFnIsZero = UObject::FindFunction("Function Core.Object.IsZero");

	Core_IsZero_Parms IsZero_Parms;
	memcpy(&IsZero_Parms.A,&A,0xC);

	unsigned short NativeIndex = pFnIsZero->iNative;
	pFnIsZero->iNative = 0;
	pFnIsZero->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsZero,NULL,&IsZero_Parms,NULL);
	pFnIsZero->FunctionFlags |= 0x400;
	pFnIsZero->iNative = NativeIndex;
	return IsZero_Parms.ReturnValue;
}

struct Core_AddEqual_ByteByte_Parms
{
	unsigned char                                      A;                                                		// 0x000000 (0x0001)              
	unsigned char                                      B;                                                		// 0x000001 (0x0001)              
	unsigned char                                      ReturnValue;                                      		// 0x000002 (0x0001)              
};

unsigned char UObject::AddEqual_ByteByte(unsigned char* A,unsigned char B)
{
	static UFieldFunc* pFnAddEqual_ByteByte = NULL;
	if(!pFnAddEqual_ByteByte)
		pFnAddEqual_ByteByte = UObject::FindFunction("Function Core.Object.AddEqual_ByteByte");

	Core_AddEqual_ByteByte_Parms AddEqual_ByteByte_Parms;
	AddEqual_ByteByte_Parms.B = B;

	unsigned short NativeIndex = pFnAddEqual_ByteByte->iNative;
	pFnAddEqual_ByteByte->iNative = 0;
	pFnAddEqual_ByteByte->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAddEqual_ByteByte,NULL,&AddEqual_ByteByte_Parms,NULL);
	pFnAddEqual_ByteByte->FunctionFlags |= 0x400;
	pFnAddEqual_ByteByte->iNative = NativeIndex;
	if(A)
		*A = AddEqual_ByteByte_Parms.A;
	return AddEqual_ByteByte_Parms.ReturnValue;
}

struct Core_Multiply_MatrixMatrix_Parms
{
	FMatrix                                            A;                                                		// 0x000000 (0x0040)              
	FMatrix                                            B;                                                		// 0x000040 (0x0040)              
	FMatrix                                            ReturnValue;                                      		// 0x000080 (0x0040)              
};

FMatrix UObject::Multiply_MatrixMatrix(FMatrix A,FMatrix B)
{
	static UFieldFunc* pFnMultiply_MatrixMatrix = NULL;
	if(!pFnMultiply_MatrixMatrix)
		pFnMultiply_MatrixMatrix = UObject::FindFunction("Function Core.Object.Multiply_MatrixMatrix");

	Core_Multiply_MatrixMatrix_Parms Multiply_MatrixMatrix_Parms;
	memcpy(&Multiply_MatrixMatrix_Parms.A,&A,0x40);
	memcpy(&Multiply_MatrixMatrix_Parms.B,&B,0x40);
	pFnMultiply_MatrixMatrix->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMultiply_MatrixMatrix,NULL,&Multiply_MatrixMatrix_Parms,NULL);
	pFnMultiply_MatrixMatrix->FunctionFlags |= 0x400;
	return Multiply_MatrixMatrix_Parms.ReturnValue;
}

struct Core_Greater_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::Greater_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnGreater_StrStr = NULL;
	if(!pFnGreater_StrStr)
		pFnGreater_StrStr = UObject::FindFunction("Function Core.Object.Greater_StrStr");

	Core_Greater_StrStr_Parms Greater_StrStr_Parms;
	memcpy(&Greater_StrStr_Parms.A,&A,0xC);
	memcpy(&Greater_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnGreater_StrStr->iNative;
	pFnGreater_StrStr->iNative = 0;
	pFnGreater_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGreater_StrStr,NULL,&Greater_StrStr_Parms,NULL);
	pFnGreater_StrStr->FunctionFlags |= 0x400;
	pFnGreater_StrStr->iNative = NativeIndex;
	return Greater_StrStr_Parms.ReturnValue;
}

struct Core_OrOr_BoolBool_Parms
{
	unsigned long                                      A : 1;                                            		// 0x000000 (0x0004) [0x00000001] 
	unsigned long                                      B : 1;                                            		// 0x000004 (0x0004) [0x00000001] 
	unsigned long                                      ReturnValue : 1;                                  		// 0x000008 (0x0004) [0x00000001] 
};

bool UObject::OrOr_BoolBool(bool A,bool B)
{
	static UFieldFunc* pFnOrOr_BoolBool = NULL;
	if(!pFnOrOr_BoolBool)
		pFnOrOr_BoolBool = UObject::FindFunction("Function Core.Object.OrOr_BoolBool");

	Core_OrOr_BoolBool_Parms OrOr_BoolBool_Parms;
	OrOr_BoolBool_Parms.A = A;
	OrOr_BoolBool_Parms.B = B;

	unsigned short NativeIndex = pFnOrOr_BoolBool->iNative;
	pFnOrOr_BoolBool->iNative = 0;
	pFnOrOr_BoolBool->FunctionFlags |= ~0x400;
	ProcessEvent(pFnOrOr_BoolBool,NULL,&OrOr_BoolBool_Parms,NULL);
	pFnOrOr_BoolBool->FunctionFlags |= 0x400;
	pFnOrOr_BoolBool->iNative = NativeIndex;
	return OrOr_BoolBool_Parms.ReturnValue;
}

struct Core_VSize2D_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::VSize2D(FVector3 A)
{
	static UFieldFunc* pFnVSize2D = NULL;
	if(!pFnVSize2D)
		pFnVSize2D = UObject::FindFunction("Function Core.Object.VSize2D");

	Core_VSize2D_Parms VSize2D_Parms;
	memcpy(&VSize2D_Parms.A,&A,0xC);
	pFnVSize2D->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVSize2D,NULL,&VSize2D_Parms,NULL);
	pFnVSize2D->FunctionFlags |= 0x400;
	return VSize2D_Parms.ReturnValue;
}

struct Core_GetRangePctByValue_Parms
{
	FVector2                                           Range;                                            		// 0x000000 (0x0008)              
	float                                              Value;                                            		// 0x000008 (0x0004)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::GetRangePctByValue(FVector2 Range,float Value)
{
	static UFieldFunc* pFnGetRangePctByValue = NULL;
	if(!pFnGetRangePctByValue)
		pFnGetRangePctByValue = UObject::FindFunction("Function Core.Object.GetRangePctByValue");

	Core_GetRangePctByValue_Parms GetRangePctByValue_Parms;
	memcpy(&GetRangePctByValue_Parms.Range,&Range,0x8);
	GetRangePctByValue_Parms.Value = Value;
	ProcessEvent(pFnGetRangePctByValue,NULL,&GetRangePctByValue_Parms,NULL);
	return GetRangePctByValue_Parms.ReturnValue;
}

struct Core_DMin_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::DMin(double A,double B)
{
	static UFieldFunc* pFnDMin = NULL;
	if(!pFnDMin)
		pFnDMin = UObject::FindFunction("Function Core.Object.DMin");

	Core_DMin_Parms DMin_Parms;
	DMin_Parms.A = A;
	DMin_Parms.B = B;

	unsigned short NativeIndex = pFnDMin->iNative;
	pFnDMin->iNative = 0;
	pFnDMin->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDMin,NULL,&DMin_Parms,NULL);
	pFnDMin->FunctionFlags |= 0x400;
	pFnDMin->iNative = NativeIndex;
	return DMin_Parms.ReturnValue;
}

struct Core_LessEqual_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::LessEqual_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnLessEqual_DoubleDouble = NULL;
	if(!pFnLessEqual_DoubleDouble)
		pFnLessEqual_DoubleDouble = UObject::FindFunction("Function Core.Object.LessEqual_DoubleDouble");

	Core_LessEqual_DoubleDouble_Parms LessEqual_DoubleDouble_Parms;
	LessEqual_DoubleDouble_Parms.A = A;
	LessEqual_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnLessEqual_DoubleDouble->iNative;
	pFnLessEqual_DoubleDouble->iNative = 0;
	pFnLessEqual_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLessEqual_DoubleDouble,NULL,&LessEqual_DoubleDouble_Parms,NULL);
	pFnLessEqual_DoubleDouble->FunctionFlags |= 0x400;
	pFnLessEqual_DoubleDouble->iNative = NativeIndex;
	return LessEqual_DoubleDouble_Parms.ReturnValue;
}

struct Core_QuatRotateVector_Parms
{
	struct FQuat                                       A;                                                		// 0x000000 (0x0010)              
	FVector3                                           B;                                                		// 0x000010 (0x000C)              
	FVector3                                           ReturnValue;                                      		// 0x00001C (0x000C)              
};

FVector3 UObject::QuatRotateVector(struct FQuat A,FVector3 B)
{
	static UFieldFunc* pFnQuatRotateVector = NULL;
	if(!pFnQuatRotateVector)
		pFnQuatRotateVector = UObject::FindFunction("Function Core.Object.QuatRotateVector");

	Core_QuatRotateVector_Parms QuatRotateVector_Parms;
	memcpy(&QuatRotateVector_Parms.A,&A,0x10);
	memcpy(&QuatRotateVector_Parms.B,&B,0xC);
	pFnQuatRotateVector->FunctionFlags |= ~0x400;
	ProcessEvent(pFnQuatRotateVector,NULL,&QuatRotateVector_Parms,NULL);
	pFnQuatRotateVector->FunctionFlags |= 0x400;
	return QuatRotateVector_Parms.ReturnValue;
}

struct Core_Add_DoubleDouble_Parms
{
	double                                             A;                                                		// 0x000000 (0x0008)              
	double                                             B;                                                		// 0x000008 (0x0008)              
	double                                             ReturnValue;                                      		// 0x000010 (0x0008)              
};

double UObject::Add_DoubleDouble(double A,double B)
{
	static UFieldFunc* pFnAdd_DoubleDouble = NULL;
	if(!pFnAdd_DoubleDouble)
		pFnAdd_DoubleDouble = UObject::FindFunction("Function Core.Object.Add_DoubleDouble");

	Core_Add_DoubleDouble_Parms Add_DoubleDouble_Parms;
	Add_DoubleDouble_Parms.A = A;
	Add_DoubleDouble_Parms.B = B;

	unsigned short NativeIndex = pFnAdd_DoubleDouble->iNative;
	pFnAdd_DoubleDouble->iNative = 0;
	pFnAdd_DoubleDouble->FunctionFlags |= ~0x400;
	ProcessEvent(pFnAdd_DoubleDouble,NULL,&Add_DoubleDouble_Parms,NULL);
	pFnAdd_DoubleDouble->FunctionFlags |= 0x400;
	pFnAdd_DoubleDouble->iNative = NativeIndex;
	return Add_DoubleDouble_Parms.ReturnValue;
}

struct Core_InStr_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	struct FString                                     T;                                                		// 0x00000C (0x000C)              
	unsigned long                                      bSearchFromRight : 1;                             		// 0x000018 (0x0004) [0x00000001] 
	unsigned long                                      bIgnoreCase : 1;                                  		// 0x00001C (0x0004) [0x00000001] 
	int                                                StartPos;                                         		// 0x000020 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000024 (0x0004)              
};

int UObject::InStr(struct FString S,struct FString T,bool bSearchFromRight,bool bIgnoreCase,int StartPos)
{
	static UFieldFunc* pFnInStr = NULL;
	if(!pFnInStr)
		pFnInStr = UObject::FindFunction("Function Core.Object.InStr");

	Core_InStr_Parms InStr_Parms;
	memcpy(&InStr_Parms.S,&S,0xC);
	memcpy(&InStr_Parms.T,&T,0xC);
	InStr_Parms.bSearchFromRight = bSearchFromRight;
	InStr_Parms.bIgnoreCase = bIgnoreCase;
	InStr_Parms.StartPos = StartPos;

	unsigned short NativeIndex = pFnInStr->iNative;
	pFnInStr->iNative = 0;
	pFnInStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnInStr,NULL,&InStr_Parms,NULL);
	pFnInStr->FunctionFlags |= 0x400;
	pFnInStr->iNative = NativeIndex;
	return InStr_Parms.ReturnValue;
}

struct Core_SubtractSubtract_Int_Parms
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                ReturnValue;                                      		// 0x000004 (0x0004)              
};

int UObject::SubtractSubtract_Int(int* A)
{
	static UFieldFunc* pFnSubtractSubtract_Int = NULL;
	if(!pFnSubtractSubtract_Int)
		pFnSubtractSubtract_Int = UObject::FindFunction("Function Core.Object.SubtractSubtract_Int");

	Core_SubtractSubtract_Int_Parms SubtractSubtract_Int_Parms;

	unsigned short NativeIndex = pFnSubtractSubtract_Int->iNative;
	pFnSubtractSubtract_Int->iNative = 0;
	pFnSubtractSubtract_Int->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSubtractSubtract_Int,NULL,&SubtractSubtract_Int_Parms,NULL);
	pFnSubtractSubtract_Int->FunctionFlags |= 0x400;
	pFnSubtractSubtract_Int->iNative = NativeIndex;
	if(A)
		*A = SubtractSubtract_Int_Parms.A;
	return SubtractSubtract_Int_Parms.ReturnValue;
}

struct Core_Square_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000004 (0x0004)              
};

float UObject::Square(float A)
{
	static UFieldFunc* pFnSquare = NULL;
	if(!pFnSquare)
		pFnSquare = UObject::FindFunction("Function Core.Object.Square");

	Core_Square_Parms Square_Parms;
	Square_Parms.A = A;

	unsigned short NativeIndex = pFnSquare->iNative;
	pFnSquare->iNative = 0;
	pFnSquare->FunctionFlags |= ~0x400;
	ProcessEvent(pFnSquare,NULL,&Square_Parms,NULL);
	pFnSquare->FunctionFlags |= 0x400;
	pFnSquare->iNative = NativeIndex;
	return Square_Parms.ReturnValue;
}

struct Core_Less_StrStr_Parms
{
	struct FString                                     A;                                                		// 0x000000 (0x000C)              
	struct FString                                     B;                                                		// 0x00000C (0x000C)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000018 (0x0004) [0x00000001] 
};

bool UObject::Less_StrStr(struct FString A,struct FString B)
{
	static UFieldFunc* pFnLess_StrStr = NULL;
	if(!pFnLess_StrStr)
		pFnLess_StrStr = UObject::FindFunction("Function Core.Object.Less_StrStr");

	Core_Less_StrStr_Parms Less_StrStr_Parms;
	memcpy(&Less_StrStr_Parms.A,&A,0xC);
	memcpy(&Less_StrStr_Parms.B,&B,0xC);

	unsigned short NativeIndex = pFnLess_StrStr->iNative;
	pFnLess_StrStr->iNative = 0;
	pFnLess_StrStr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLess_StrStr,NULL,&Less_StrStr_Parms,NULL);
	pFnLess_StrStr->FunctionFlags |= 0x400;
	pFnLess_StrStr->iNative = NativeIndex;
	return Less_StrStr_Parms.ReturnValue;
}

struct Core_VSizeSq2D_Parms
{
	FVector3                                           A;                                                		// 0x000000 (0x000C)              
	float                                              ReturnValue;                                      		// 0x00000C (0x0004)              
};

float UObject::VSizeSq2D(FVector3 A)
{
	static UFieldFunc* pFnVSizeSq2D = NULL;
	if(!pFnVSizeSq2D)
		pFnVSizeSq2D = UObject::FindFunction("Function Core.Object.VSizeSq2D");

	Core_VSizeSq2D_Parms VSizeSq2D_Parms;
	memcpy(&VSizeSq2D_Parms.A,&A,0xC);
	pFnVSizeSq2D->FunctionFlags |= ~0x400;
	ProcessEvent(pFnVSizeSq2D,NULL,&VSizeSq2D_Parms,NULL);
	pFnVSizeSq2D->FunctionFlags |= 0x400;
	return VSizeSq2D_Parms.ReturnValue;
}

struct Core_Chr_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000004 (0x000C)              
};

struct FString UObject::Chr(int I)
{
	static UFieldFunc* pFnChr = NULL;
	if(!pFnChr)
		pFnChr = UObject::FindFunction("Function Core.Object.Chr");

	Core_Chr_Parms Chr_Parms;
	Chr_Parms.I = I;

	unsigned short NativeIndex = pFnChr->iNative;
	pFnChr->iNative = 0;
	pFnChr->FunctionFlags |= ~0x400;
	ProcessEvent(pFnChr,NULL,&Chr_Parms,NULL);
	pFnChr->FunctionFlags |= 0x400;
	pFnChr->iNative = NativeIndex;
	return Chr_Parms.ReturnValue;
}

struct Core_Clamp_Parms
{
	int                                                V;                                                		// 0x000000 (0x0004)              
	int                                                A;                                                		// 0x000004 (0x0004)              
	int                                                B;                                                		// 0x000008 (0x0004)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UObject::Clamp(int V,int A,int B)
{
	static UFieldFunc* pFnClamp = NULL;
	if(!pFnClamp)
		pFnClamp = UObject::FindFunction("Function Core.Object.Clamp");

	Core_Clamp_Parms Clamp_Parms;
	Clamp_Parms.V = V;
	Clamp_Parms.A = A;
	Clamp_Parms.B = B;

	unsigned short NativeIndex = pFnClamp->iNative;
	pFnClamp->iNative = 0;
	pFnClamp->FunctionFlags |= ~0x400;
	ProcessEvent(pFnClamp,NULL,&Clamp_Parms,NULL);
	pFnClamp->FunctionFlags |= 0x400;
	pFnClamp->iNative = NativeIndex;
	return Clamp_Parms.ReturnValue;
}

struct Core_ScriptTrace_Parms
{
};

void UObject::ScriptTrace()
{
	static UFieldFunc* pFnScriptTrace = NULL;
	if(!pFnScriptTrace)
		pFnScriptTrace = UObject::FindFunction("Function Core.Object.ScriptTrace");

	Core_ScriptTrace_Parms ScriptTrace_Parms;
	pFnScriptTrace->FunctionFlags |= ~0x400;
	ProcessEvent(pFnScriptTrace,NULL,&ScriptTrace_Parms,NULL);
	pFnScriptTrace->FunctionFlags |= 0x400;
}

struct Core_GetRightMost_Parms
{
	struct FString                                     Text;                                             		// 0x000000 (0x000C)              
	struct FString                                     ReturnValue;                                      		// 0x00000C (0x000C)              
	//int                                                Idx;                                              		// 0x000018 (0x0004)              
};

struct FString UObject::GetRightMost(struct FString Text)
{
	static UFieldFunc* pFnGetRightMost = NULL;
	if(!pFnGetRightMost)
		pFnGetRightMost = UObject::FindFunction("Function Core.Object.GetRightMost");

	Core_GetRightMost_Parms GetRightMost_Parms;
	memcpy(&GetRightMost_Parms.Text,&Text,0xC);
	ProcessEvent(pFnGetRightMost,NULL,&GetRightMost_Parms,NULL);
	return GetRightMost_Parms.ReturnValue;
}

struct Core_Divide_FloatFloat_Parms
{
	float                                              A;                                                		// 0x000000 (0x0004)              
	float                                              B;                                                		// 0x000004 (0x0004)              
	float                                              ReturnValue;                                      		// 0x000008 (0x0004)              
};

float UObject::Divide_FloatFloat(float A,float B)
{
	static UFieldFunc* pFnDivide_FloatFloat = NULL;
	if(!pFnDivide_FloatFloat)
		pFnDivide_FloatFloat = UObject::FindFunction("Function Core.Object.Divide_FloatFloat");

	Core_Divide_FloatFloat_Parms Divide_FloatFloat_Parms;
	Divide_FloatFloat_Parms.A = A;
	Divide_FloatFloat_Parms.B = B;

	unsigned short NativeIndex = pFnDivide_FloatFloat->iNative;
	pFnDivide_FloatFloat->iNative = 0;
	pFnDivide_FloatFloat->FunctionFlags |= ~0x400;
	ProcessEvent(pFnDivide_FloatFloat,NULL,&Divide_FloatFloat_Parms,NULL);
	pFnDivide_FloatFloat->FunctionFlags |= 0x400;
	pFnDivide_FloatFloat->iNative = NativeIndex;
	return Divide_FloatFloat_Parms.ReturnValue;
}

struct Core_NotEqual_NameName_Parms
{
	struct FName                                       A;                                                		// 0x000000 (0x0008)              
	struct FName                                       B;                                                		// 0x000008 (0x0008)              
	unsigned long                                      ReturnValue : 1;                                  		// 0x000010 (0x0004) [0x00000001] 
};

bool UObject::NotEqual_NameName(struct FName A,struct FName B)
{
	static UFieldFunc* pFnNotEqual_NameName = NULL;
	if(!pFnNotEqual_NameName)
		pFnNotEqual_NameName = UObject::FindFunction("Function Core.Object.NotEqual_NameName");

	Core_NotEqual_NameName_Parms NotEqual_NameName_Parms;
	memcpy(&NotEqual_NameName_Parms.A,&A,0x8);
	memcpy(&NotEqual_NameName_Parms.B,&B,0x8);

	unsigned short NativeIndex = pFnNotEqual_NameName->iNative;
	pFnNotEqual_NameName->iNative = 0;
	pFnNotEqual_NameName->FunctionFlags |= ~0x400;
	ProcessEvent(pFnNotEqual_NameName,NULL,&NotEqual_NameName_Parms,NULL);
	pFnNotEqual_NameName->FunctionFlags |= 0x400;
	pFnNotEqual_NameName->iNative = NativeIndex;
	return NotEqual_NameName_Parms.ReturnValue;
}

struct Core_Left_Parms
{
	struct FString                                     S;                                                		// 0x000000 (0x000C)              
	int                                                I;                                                		// 0x00000C (0x0004)              
	struct FString                                     ReturnValue;                                      		// 0x000010 (0x000C)              
};

struct FString UObject::Left(struct FString S,int I)
{
	static UFieldFunc* pFnLeft = NULL;
	if(!pFnLeft)
		pFnLeft = UObject::FindFunction("Function Core.Object.Left");

	Core_Left_Parms Left_Parms;
	memcpy(&Left_Parms.S,&S,0xC);
	Left_Parms.I = I;

	unsigned short NativeIndex = pFnLeft->iNative;
	pFnLeft->iNative = 0;
	pFnLeft->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLeft,NULL,&Left_Parms,NULL);
	pFnLeft->FunctionFlags |= 0x400;
	pFnLeft->iNative = NativeIndex;
	return Left_Parms.ReturnValue;
}

struct Core_GetGameEpoch_Parms
{
	unsigned char                                      ReturnValue;                                      		// 0x000000 (0x0001)              
};

unsigned char UObject::GetGameEpoch()
{
	static UFieldFunc* pFnGetGameEpoch = NULL;
	if(!pFnGetGameEpoch)
		pFnGetGameEpoch = UObject::FindFunction("Function Core.Object.GetGameEpoch");

	Core_GetGameEpoch_Parms GetGameEpoch_Parms;
	pFnGetGameEpoch->FunctionFlags |= ~0x400;
	ProcessEvent(pFnGetGameEpoch,NULL,&GetGameEpoch_Parms,NULL);
	pFnGetGameEpoch->FunctionFlags |= 0x400;
	return GetGameEpoch_Parms.ReturnValue;
}

struct Core_IsSafeBuild_Parms
{
	unsigned long                                      ReturnValue : 1;                                  		// 0x000000 (0x0004) [0x00000001] 
};

bool UObject::IsSafeBuild()
{
	static UFieldFunc* pFnIsSafeBuild = NULL;
	if(!pFnIsSafeBuild)
		pFnIsSafeBuild = UObject::FindFunction("Function Core.Object.IsSafeBuild");

	Core_IsSafeBuild_Parms IsSafeBuild_Parms;
	pFnIsSafeBuild->FunctionFlags |= ~0x400;
	ProcessEvent(pFnIsSafeBuild,NULL,&IsSafeBuild_Parms,NULL);
	pFnIsSafeBuild->FunctionFlags |= 0x400;
	return IsSafeBuild_Parms.ReturnValue;
}

struct Core_LogCurrentRecords_Parms
{
};

void UcStatWatchManager::LogCurrentRecords()
{
	static UFieldFunc* pFnLogCurrentRecords = NULL;
	if(!pFnLogCurrentRecords)
		pFnLogCurrentRecords = UObject::FindFunction("Function Core.cStatWatchManager.LogCurrentRecords");

	Core_LogCurrentRecords_Parms LogCurrentRecords_Parms;
	pFnLogCurrentRecords->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLogCurrentRecords,NULL,&LogCurrentRecords_Parms,NULL);
	pFnLogCurrentRecords->FunctionFlags |= 0x400;
}

struct Core_LogRecord_Parms
{
	struct FSpikeRecord                                theRecord;                                        		// 0x000000 (0x0014)              
};

void UcStatWatchManager::LogRecord(struct FSpikeRecord theRecord)
{
	static UFieldFunc* pFnLogRecord = NULL;
	if(!pFnLogRecord)
		pFnLogRecord = UObject::FindFunction("Function Core.cStatWatchManager.LogRecord");

	Core_LogRecord_Parms LogRecord_Parms;
	memcpy(&LogRecord_Parms.theRecord,&theRecord,0x14);
	pFnLogRecord->FunctionFlags |= ~0x400;
	ProcessEvent(pFnLogRecord,NULL,&LogRecord_Parms,NULL);
	pFnLogRecord->FunctionFlags |= 0x400;
}

struct Core_CastCustomisationMode_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastCustomisationMode(int I)
{
	static UFieldFunc* pFnCastCustomisationMode = NULL;
	if(!pFnCastCustomisationMode)
		pFnCastCustomisationMode = UObject::FindFunction("Function Core.cAPBCoreSDD.CastCustomisationMode");

	Core_CastCustomisationMode_Parms CastCustomisationMode_Parms;
	CastCustomisationMode_Parms.I = I;
	ProcessEvent(pFnCastCustomisationMode,NULL,&CastCustomisationMode_Parms,NULL);
	return CastCustomisationMode_Parms.ReturnValue;
}

struct Core_CastDistrictType_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastDistrictType(int I)
{
	static UFieldFunc* pFnCastDistrictType = NULL;
	if(!pFnCastDistrictType)
		pFnCastDistrictType = UObject::FindFunction("Function Core.cAPBCoreSDD.CastDistrictType");

	Core_CastDistrictType_Parms CastDistrictType_Parms;
	CastDistrictType_Parms.I = I;
	ProcessEvent(pFnCastDistrictType,NULL,&CastDistrictType_Parms,NULL);
	return CastDistrictType_Parms.ReturnValue;
}

struct Core_CastHostingConfigFile_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastHostingConfigFile(int I)
{
	static UFieldFunc* pFnCastHostingConfigFile = NULL;
	if(!pFnCastHostingConfigFile)
		pFnCastHostingConfigFile = UObject::FindFunction("Function Core.cAPBCoreSDD.CastHostingConfigFile");

	Core_CastHostingConfigFile_Parms CastHostingConfigFile_Parms;
	CastHostingConfigFile_Parms.I = I;
	ProcessEvent(pFnCastHostingConfigFile,NULL,&CastHostingConfigFile_Parms,NULL);
	return CastHostingConfigFile_Parms.ReturnValue;
}

struct Core_CastHostingConfigFileType_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastHostingConfigFileType(int I)
{
	static UFieldFunc* pFnCastHostingConfigFileType = NULL;
	if(!pFnCastHostingConfigFileType)
		pFnCastHostingConfigFileType = UObject::FindFunction("Function Core.cAPBCoreSDD.CastHostingConfigFileType");

	Core_CastHostingConfigFileType_Parms CastHostingConfigFileType_Parms;
	CastHostingConfigFileType_Parms.I = I;
	ProcessEvent(pFnCastHostingConfigFileType,NULL,&CastHostingConfigFileType_Parms,NULL);
	return CastHostingConfigFileType_Parms.ReturnValue;
}

struct Core_CastDesignerConstant2_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastDesignerConstant2(int I)
{
	static UFieldFunc* pFnCastDesignerConstant2 = NULL;
	if(!pFnCastDesignerConstant2)
		pFnCastDesignerConstant2 = UObject::FindFunction("Function Core.cAPBCoreSDD.CastDesignerConstant2");

	Core_CastDesignerConstant2_Parms CastDesignerConstant2_Parms;
	CastDesignerConstant2_Parms.I = I;
	ProcessEvent(pFnCastDesignerConstant2,NULL,&CastDesignerConstant2_Parms,NULL);
	return CastDesignerConstant2_Parms.ReturnValue;
}

struct Core_CastGender_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastGender(int I)
{
	static UFieldFunc* pFnCastGender = NULL;
	if(!pFnCastGender)
		pFnCastGender = UObject::FindFunction("Function Core.cAPBCoreSDD.CastGender");

	Core_CastGender_Parms CastGender_Parms;
	CastGender_Parms.I = I;
	ProcessEvent(pFnCastGender,NULL,&CastGender_Parms,NULL);
	return CastGender_Parms.ReturnValue;
}

struct Core_CastDesignerConstant_Parms
{
	int                                                I;                                                		// 0x000000 (0x0004)              
	unsigned char                                      ReturnValue;                                      		// 0x000004 (0x0001)              
};

unsigned char UcAPBCoreSDD::CastDesignerConstant(int I)
{
	static UFieldFunc* pFnCastDesignerConstant = NULL;
	if(!pFnCastDesignerConstant)
		pFnCastDesignerConstant = UObject::FindFunction("Function Core.cAPBCoreSDD.CastDesignerConstant");

	Core_CastDesignerConstant_Parms CastDesignerConstant_Parms;
	CastDesignerConstant_Parms.I = I;
	ProcessEvent(pFnCastDesignerConstant,NULL,&CastDesignerConstant_Parms,NULL);
	return CastDesignerConstant_Parms.ReturnValue;
}

struct Core_Main_Parms
{
	struct FString                                     Params;                                           		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UCommandlet::Main(struct FString Params)
{
	static UFieldFunc* pFnMain = NULL;
	if(!pFnMain)
		pFnMain = UObject::FindFunction("Function Core.Commandlet.Main");

	Core_Main_Parms Main_Parms;
	memcpy(&Main_Parms.Params,&Params,0xC);
	pFnMain->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMain,NULL,&Main_Parms,NULL);
	pFnMain->FunctionFlags |= 0x400;
	return Main_Parms.ReturnValue;
}

struct Core_Main_Parms
{
	struct FString                                     Params;                                           		// 0x000000 (0x000C)              
	int                                                ReturnValue;                                      		// 0x00000C (0x0004)              
};

int UHelpCommandlet::Main(struct FString Params)
{
	static UFieldFunc* pFnMain = NULL;
	if(!pFnMain)
		pFnMain = UObject::FindFunction("Function Core.HelpCommandlet.Main");

	Core_Main_Parms Main_Parms;
	memcpy(&Main_Parms.Params,&Params,0xC);
	pFnMain->FunctionFlags |= ~0x400;
	ProcessEvent(pFnMain,NULL,&Main_Parms,NULL);
	pFnMain->FunctionFlags |= 0x400;
	return Main_Parms.ReturnValue;
}
