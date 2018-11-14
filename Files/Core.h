
/*
-----------------------------------------------------------------
 - UConst
-----------------------------------------------------------------
*/
#define CONST_MaxInt                                             0x7fffffff
#define CONST_Pi                                                 3.1415926535897932
#define CONST_RadToDeg                                           57.295779513082321600
#define CONST_DegToRad                                           0.017453292519943296
#define CONST_UnrRotToRad                                        0.00009587379924285
#define CONST_RadToUnrRot                                        10430.3783504704527
#define CONST_INDEX_NONE                                         -1

/*
-----------------------------------------------------------------
 - UEnum
-----------------------------------------------------------------
*/
enum EAxis
{
	AXIS_NONE = 0,
	AXIS_X = 1,
	AXIS_Y = 2,
	AXIS_BLANK = 3,
	AXIS_Z = 4,
	AXIS_MAX = 5,
};
enum EInputEvent
{
	IE_Pressed = 0,
	IE_Released = 1,
	IE_Repeat = 2,
	IE_DoubleClick = 3,
	IE_Axis = 4,
	IE_MAX = 5,
};
enum EInterpCurveMode
{
	CIM_Linear = 0,
	CIM_CurveAuto = 1,
	CIM_Constant = 2,
	CIM_CurveUser = 3,
	CIM_CurveBreak = 4,
	CIM_MAX = 5,
};
enum EInterpMethodType
{
	IMT_UseFixedTangentEval = 0,
	IMT_UseBrokenTangentEval = 1,
	IMT_MAX = 2,
};
enum ECollisionCategory
{
	COL_None = 0,
	COL_AutoAssign = 1,
	COL_StaticEnvironment = 2,
	COL_InvisibleBlockCharacter = 3,
	COL_InvisibleBlockAllVehicle = 4,
	COL_InvisibleBlockCharacterVehicleAndDynamicEnviro = 5,
	COL_KinematicEnvironment = 6,
	COL_PseudoKinematicEnvironment = 7,
	COL_DynamicEnvironment = 8,
	COL_AbstractItem = 9,
	COL_CosmeticKinematic = 10,
	COL_CosmeticDynamic = 11,
	COL_PlayerCharacter = 12,
	COL_PlayerVehicle = 13,
	COL_DynamicSensor = 14,
	COL_InvisibleBlockCharacterVehicleAndDynamicEnviroSensor = 15,
	COL_Wheel = 16,
	COL_Temp_KinematicLCVehicle = 17,
	COL_Temp_PseudoKinematicLCVehicle = 18,
	COL_Temp_DynamicLCVehicle = 19,
	COL_LCPedestrian = 20,
	COL_PlayerCharacterPvPLocked = 21,
	COL_Deployable = 22,
	COL_MAX = 23,
};
enum EGameEpoch
{
	GAMEEPOCH_InitialLoad = 0,
	GAMEEPOCH_PermanentSet = 1,
	GAMEEPOCH_StaticMapSet = 2,
	GAMEEPOCH_CleanupStaticMapSet = 3,
	GAMEEPOCH_DynamicSet = 4,
	GAMEEPOCH_DynamicSet_Streaming = 5,
	GAMEEPOCH_MAX = 6,
};
enum ETickingGroup
{
	TG_PreAsyncWork = 0,
	TG_DuringAsyncWork = 1,
	TG_PostAsyncWork = 2,
	TG_PostUpdateWork = 3,
	TG_MAX = 4,
};
enum EAutomatedRunResult
{
	ARR_Unknown = 0,
	ARR_OOM = 1,
	ARR_Passed = 2,
	ARR_MAX = 3,
};
enum EDebugBreakType
{
	DEBUGGER_NativeOnly = 0,
	DEBUGGER_ScriptOnly = 1,
	DEBUGGER_Both = 2,
	DEBUGGER_MAX = 3,
};
enum etCustomisationMode
{
	kCCContext_All = 0,
	kCCContext_Creation = 1,
	kCCContext_SocialDistrict = 2,
	kCCContext_MAX = 3,
};
enum etDesignerConstant
{
	DesignerConstant_AccelerationRate = 0,
	DesignerConstant_ActivityMessage_WinStreak_Threshold = 1,
	DesignerConstant_AirControl = 2,
	DesignerConstant_AllowGiftingUnlocks = 3,
	DesignerConstant_AmmoStoredBoxesWarningLevel = 4,
	DesignerConstant_ArrestStreakArrests = 5,
	DesignerConstant_AutoReadyTimer = 6,
	DesignerConstant_BailOutSpeed = 7,
	DesignerConstant_BountyHuntDeclineTimer = 8,
	DesignerConstant_BountyHuntSuppressNotoriety = 9,
	DesignerConstant_BountyHuntSuppressTimer = 10,
	DesignerConstant_BountyHuntSuppressTimerUnopposed = 11,
	DesignerConstant_CSAHintIconDefaultMaxDistance = 12,
	DesignerConstant_CanAbandonOpposed = 13,
	DesignerConstant_CanAbandonUnopposed = 14,
	DesignerConstant_CarSurfingMinSpeed = 15,
	DesignerConstant_CashGift = 16,
	DesignerConstant_ChatAFKCooldownTime = 17,
	DesignerConstant_ChatAutomaticAFKIdleTime = 18,
	DesignerConstant_ContactHailTimerReset = 19,
	DesignerConstant_ContactInnerProximityRadius = 20,
	DesignerConstant_ContactOuterProximityRadius = 21,
	DesignerConstant_CrouchStaminaRechargeScalar = 22,
	DesignerConstant_DelayBetweenBackupCalls = 23,
	DesignerConstant_DisplayGammaMax = 24,
	DesignerConstant_DisplayGammaMin = 25,
	DesignerConstant_EscortDefaultVIPLives = 26,
	DesignerConstant_FallingDamageMultiplier = 27,
	DesignerConstant_FallingDamageSpeedThreshold = 28,
	DesignerConstant_FallingDamageStaminaMultiplier = 29,
	DesignerConstant_FallingWindedSpeedThreshold = 30,
	DesignerConstant_FeeToRefurbishCustom = 31,
	DesignerConstant_FeeToRefurbishPreset = 32,
	DesignerConstant_FemaleCharacterHeightMax = 33,
	DesignerConstant_FemaleCharacterHeightMin = 34,
	DesignerConstant_FieldSupplierRadiusPlayer = 35,
	DesignerConstant_FieldSupplierRadiusStatic = 36,
	DesignerConstant_FieldSupplierRadiusVehicle = 37,
	DesignerConstant_FlailingSpeed = 38,
	DesignerConstant_GM_MaxPlayerRunSpeed = 39,
	DesignerConstant_GM_MinPlayerRunSpeed = 40,
	DesignerConstant_GM_TeleportGMToPlayerDistance = 41,
	DesignerConstant_GM_TeleportPlayerToGMDistance = 42,
	DesignerConstant_GameControlTimeBeforeAutoReadyTimer = 43,
	DesignerConstant_GlobalUsableCooldownTimer = 44,
	DesignerConstant_GrenadeSpeedThreshold = 45,
	DesignerConstant_GroupMaxMembers = 46,
	DesignerConstant_ItemSellbackAPBCash = 47,
	DesignerConstant_ItemUnlockReplenishmentDayOffset = 48,
	DesignerConstant_ItemUnlockReplenishmentHourOffset = 49,
	DesignerConstant_ItemUnlockReplenishmentTime = 50,
	DesignerConstant_JumpStaminaDrain = 51,
	DesignerConstant_JumpZ = 52,
	DesignerConstant_KillFromBehindTolerance = 53,
	DesignerConstant_KillStreakKills = 54,
	DesignerConstant_LeanLeftCrouchingAimOffset = 55,
	DesignerConstant_LeanLeftStandingAimOffset = 56,
	DesignerConstant_LeanRightCrouchingAimOffset = 57,
	DesignerConstant_LeanRightStandingAimOffset = 58,
	DesignerConstant_LoadingScreenHintChangeFrequency = 59,
	DesignerConstant_LobbyMaxAllowedCharacters = 60,
	DesignerConstant_MaleCharacterHeightMax = 61,
	DesignerConstant_MaleCharacterHeightMin = 62,
	DesignerConstant_MarksmanshipMouseSensitivityMax = 63,
	DesignerConstant_MarksmanshipMouseSensitivityMin = 64,
	DesignerConstant_MatchmakingGlobalOwningSideBias = 65,
	DesignerConstant_MatchmakingMetaGroupAttempt = 66,
	DesignerConstant_MatchmakingMetaGroupBias = 67,
	DesignerConstant_MatchmakingMetaGroupPenalty = 68,
	DesignerConstant_MatchmakingMinimumMemberThreat = 69,
	DesignerConstant_MatchmakingOvermatchedRatio = 70,
	DesignerConstant_MatchmakingPrevSideAttempt = 71,
	DesignerConstant_MatchmakingPrevSidePenalty = 72,
	DesignerConstant_MatchmakingSameFactionAttempt = 73,
	DesignerConstant_MatchmakingSameFactionPenalty = 74,
	DesignerConstant_MatchmakingSecondsPerAttempt = 75,
	DesignerConstant_MatchmakingSideConstant = 76,
	DesignerConstant_MatchmakingSideSizeDifferencePenalty = 77,
	DesignerConstant_MatchmakingSideSizeMultiplier = 78,
	DesignerConstant_MatchmakingThresholdMax = 79,
	DesignerConstant_MatchmakingThresholdMaxAttempts = 80,
	DesignerConstant_MatchmakingThresholdMin = 81,
	DesignerConstant_MaxFallSpeedScaleToDamage = 82,
	DesignerConstant_MaxJumpZ = 83,
	DesignerConstant_MaxMissionDeclines = 84,
	DesignerConstant_MaxedContactMissionWeight = 85,
	DesignerConstant_MetagroupingInterval = 86,
	DesignerConstant_MinCSACacheTime = 87,
	DesignerConstant_MinThreatToOwnSoloMission = 88,
	DesignerConstant_MissionDeclinePeriod = 89,
	DesignerConstant_MissionDeclineTimerMax = 90,
	DesignerConstant_MissionDefaultObjectiveTimeLimit = 91,
	DesignerConstant_MissionDefaultTakeoutCount = 92,
	DesignerConstant_MissionEscapeGracePeriod = 93,
	DesignerConstant_MissionFeedback_Enabled = 94,
	DesignerConstant_MissionFeedback_NumberOfMissionsBetweenFeedback = 95,
	DesignerConstant_MissionFeedback_TimeOutSec = 96,
	DesignerConstant_MissionFirstTargetMaxRadius = 97,
	DesignerConstant_MissionMinTakeoutsClearOnStartMultiplier = 98,
	DesignerConstant_MissionMinTakeoutsVIPMultiplier = 99,
	DesignerConstant_MissionObstructedVehicleSpawnerDelay = 100,
	DesignerConstant_MissionPauseTimeMax = 101,
	DesignerConstant_MissionPauseTimeMin = 102,
	DesignerConstant_MissionPostCompletionDelay = 103,
	DesignerConstant_MissionScoreBalanceMultiplier = 104,
	DesignerConstant_MissionScoreDisplayResultsTime = 105,
	DesignerConstant_MissionTargetDamagedHUDMarkerBlinkDuration = 106,
	DesignerConstant_MissionTaskPropRespawnTime = 107,
	DesignerConstant_MissionTaskVehicleDeathDuration = 108,
	DesignerConstant_MissionVehicleSpawnFailTime = 109,
	DesignerConstant_MissionWinStreakCount = 110,
	DesignerConstant_MissionWrongMethodDamageScaler = 111,
	DesignerConstant_MissionWrongMethodMaxDamage = 112,
	DesignerConstant_ModifierSuperMagClipSizeForScaler = 113,
	DesignerConstant_ModifierSuperMagMinClipSize = 114,
	DesignerConstant_MouseSensitivityMax = 115,
	DesignerConstant_MouseSensitivityMin = 116,
	DesignerConstant_NPCHealth = 117,
	DesignerConstant_NPCHealthRechargeDelay = 118,
	DesignerConstant_NPCHealthRechargeDuration = 119,
	DesignerConstant_NPCViewingConeHorizontalAngle = 120,
	DesignerConstant_NPCViewingConeVerticalAngle = 121,
	DesignerConstant_NotReadyNagTimer_Initial = 122,
	DesignerConstant_NotReadyNagTimer_Repeat = 123,
	DesignerConstant_OvermatchedCallForBackupDialogueTimeout = 124,
	DesignerConstant_PawnSmallTaskItemSpawnRadiusAuto = 125,
	DesignerConstant_PawnSmallTaskItemSpawnRadiusManual = 126,
	DesignerConstant_PedestrianPanicMaxDuration = 127,
	DesignerConstant_PedestrianPanicMinDuration = 128,
	DesignerConstant_PedestrianTaskItemSpawnRadius = 129,
	DesignerConstant_PlayerHealth = 130,
	DesignerConstant_PlayerHealthRegenerationDelay = 131,
	DesignerConstant_PlayerHealthRegenerationDuration = 132,
	DesignerConstant_PlayerMarksmanshipSpeed = 133,
	DesignerConstant_PlayerMaxStepHeight = 134,
	DesignerConstant_PlayerRunSpeed = 135,
	DesignerConstant_PlayerSprintSpeed = 136,
	DesignerConstant_PlayerStamina = 137,
	DesignerConstant_PlayerStaminaRegenerationDelay = 138,
	DesignerConstant_PlayerStaminaRegenerationDuration = 139,
	DesignerConstant_PlayerVehicleDamageHigh = 140,
	DesignerConstant_PlayerVehicleDamageSmall = 141,
	DesignerConstant_PlayerVehicleSpawnDialogueTimeout = 142,
	DesignerConstant_PlayerVehicleSpawnMinInterval = 143,
	DesignerConstant_PlayerWalkSpeed = 144,
	DesignerConstant_PlayerWalkSpeedCrouched = 145,
	DesignerConstant_PropMissionBlockedDamageInterval = 146,
	DesignerConstant_PropMissionBlockedDamagePercentage = 147,
	DesignerConstant_RBCollisionThreshold1 = 148,
	DesignerConstant_RBCollisionThreshold2 = 149,
	DesignerConstant_RagdollImpulseScale = 150,
	DesignerConstant_RagdollImpulseScale_NPC = 151,
	DesignerConstant_RagdollSpeedThreshold = 152,
	DesignerConstant_RatingModifier = 153,
	DesignerConstant_RoleUpdateInterval = 154,
	DesignerConstant_SprintStaminaDrain = 155,
	DesignerConstant_SprintTolerance = 156,
	DesignerConstant_StaminaBuffer = 157,
	DesignerConstant_StrafeFiringTime = 158,
	DesignerConstant_StrafeReloadingTime = 159,
	DesignerConstant_TakeoutStreakTakeouts = 160,
	DesignerConstant_TargetInVehicleDriverOffsetHorizontal = 161,
	DesignerConstant_TargetInVehicleDriverOffsetVertical = 162,
	DesignerConstant_TargetingAimLockBorder = 163,
	DesignerConstant_TargetingHUDLockBorder = 164,
	DesignerConstant_TargetingLeanOffset = 165,
	DesignerConstant_TaskItemDropDistance = 166,
	DesignerConstant_TaskTargetPVPLockPendingDuration = 167,
	DesignerConstant_TaskTargetReallocationDelay = 168,
	DesignerConstant_TaskTargetReallocationMaxDistance = 169,
	DesignerConstant_TaskTargetReallocationMinDistance = 170,
	DesignerConstant_Task_Time_RunningOutOfTime = 171,
	DesignerConstant_VCPRaycastClampSpeed = 172,
	DesignerConstant_VIPVehicleTorqueReductionFactor = 173,
	DesignerConstant_VehicleAbandonmentTime = 174,
	DesignerConstant_VehicleAlarmCollisionTrigger = 175,
	DesignerConstant_VehicleAlarmOffTime = 176,
	DesignerConstant_VehicleAlarmOnTime = 177,
	DesignerConstant_VehicleAlarmTimeOut = 178,
	DesignerConstant_VehicleArsonDamageThreshold = 179,
	DesignerConstant_VehicleCriticalMaxDuration = 180,
	DesignerConstant_VehicleCriticalMinDuration = 181,
	DesignerConstant_VehicleDeliveryCleanupDuration = 182,
	DesignerConstant_VehicleDirtApplicationSpeed = 183,
	DesignerConstant_VehicleDirtApplicationTime = 184,
	DesignerConstant_VehicleDirtCleanSpeed = 185,
	DesignerConstant_VehicleDirtCleanSpeedActive = 186,
	DesignerConstant_VehicleDustApplicationTime = 187,
	DesignerConstant_VehicleEnterDistantTooGreat = 188,
	DesignerConstant_VehicleEnterNoMovementTimeOut = 189,
	DesignerConstant_VehicleEnterSpeedHoldOnToDoor = 190,
	DesignerConstant_VehicleEnterTimeout = 191,
	DesignerConstant_VehicleHitDeathSpeed = 192,
	DesignerConstant_VehicleHitNudgeAmount = 193,
	DesignerConstant_VehicleLastDamageValidTime = 194,
	DesignerConstant_VehicleMissionRecycleTime = 195,
	DesignerConstant_VehicleNeutralDamageTime = 196,
	DesignerConstant_VehiclePropCSAObstructionCleanupTime = 197,
	DesignerConstant_VehiclePropCSAObstructionDistance = 198,
	DesignerConstant_VehicleRepairDamageTimeout = 199,
	DesignerConstant_VehicleSpawnFreeBaySearchRadius = 200,
	DesignerConstant_VehicleTransientRecycleTime = 201,
	DesignerConstant_VehicleUseDoorAllowableZDiff = 202,
	DesignerConstant_VehicleUseDoorPitchAngle = 203,
	DesignerConstant_VehicleUseDoorRayCastDepth = 204,
	DesignerConstant_VehicleUseDoorRollAngle = 205,
	DesignerConstant_VehicleUseTeleportDownDistance = 206,
	DesignerConstant_VehicleUseTeleportUpDistance = 207,
	DesignerConstant_VehicleUseVAPLeanLerpOffset = 208,
	DesignerConstant_WeaponAccuracyModifierGlobal = 209,
	DesignerConstant_WeaponBenchmarkTargetRadius = 210,
	DesignerConstant_WeaponDropAddedDirectionalVelocity = 211,
	DesignerConstant_WeaponDropAddedUpVelocity = 212,
	DesignerConstant_WeaponDropDistance = 213,
	DesignerConstant_WeaponPickupMaxPickupCount = 214,
	DesignerConstant_WeaponPickupTime = 215,
	DesignerConstant_WeaponPickupTime_Empty = 216,
	DesignerConstant_WeaponRangeHysteresis = 217,
	DesignerConstant_WeaponReticulePickLength = 218,
	DesignerConstant_WindedTime = 219,
	DesignerConstant_MAX = 220,
};
enum etDesignerConstant2
{
	DesignerConstant2_AllowedDistrictThreatDifferenceDown = 0,
	DesignerConstant2_AllowedDistrictThreatDifferenceUp = 1,
	DesignerConstant2_AlwaysWitnessableCashAmount = 2,
	DesignerConstant2_AuctionCreateMinRating = 3,
	DesignerConstant2_AutoKick_SuicidesLimit = 4,
	DesignerConstant2_AutoKick_SuicidesPeriod = 5,
	DesignerConstant2_AutoKick_TeamKillsLimit = 6,
	DesignerConstant2_AutoKick_TeamKillsPeriod = 7,
	DesignerConstant2_AutoResupplyCheckTime = 8,
	DesignerConstant2_CeremonyMessagesDelayAfterDistrictMapClosed = 9,
	DesignerConstant2_ChallengeCycledMissionEnd = 10,
	DesignerConstant2_ChatAutomaticSpawnExcludedIdleTime = 11,
	DesignerConstant2_ChatFloodIgnoreNumMessages = 12,
	DesignerConstant2_ChatFloodIgnoreTimeSeconds = 13,
	DesignerConstant2_ChatFloodKickNumMessages = 14,
	DesignerConstant2_ChatFloodKickTimeSeconds = 15,
	DesignerConstant2_ChatFloodSilenceTimeSeconds = 16,
	DesignerConstant2_DailyActivitiesMaxmimum = 17,
	DesignerConstant2_DistanceDrivenBeforeGameplayEvent = 18,
	DesignerConstant2_EnvironmentDamageMultiplier = 19,
	DesignerConstant2_ExplosionDamageMultiplier = 20,
	DesignerConstant2_EyeBoneMaxRotation = 21,
	DesignerConstant2_EyelashesTickTime = 22,
	DesignerConstant2_FriendlyExplosiveDamageMultiplier = 23,
	DesignerConstant2_FriendlyWeaponDamageMultiplier = 24,
	DesignerConstant2_GroupWaypointSpamAmount = 25,
	DesignerConstant2_GroupWaypointSpamTime = 26,
	DesignerConstant2_ItemSellbackRewardTokens = 27,
	DesignerConstant2_MarksmanshipFOVMultipler = 28,
	DesignerConstant2_MinimumWitnessingCashAmount = 29,
	DesignerConstant2_MissionAFKTimer = 30,
	DesignerConstant2_MissionRewardLoseMultiplier = 31,
	DesignerConstant2_MissionRewardMaxPerformanceBonus = 32,
	DesignerConstant2_MissionRewardMaxPerformancePremiumBonus = 33,
	DesignerConstant2_MissionRewardScoreCashMultiplier = 34,
	DesignerConstant2_MissionRewardScoreCashPremiumMultiplier = 35,
	DesignerConstant2_MissionRewardScoreStandingMultiplier = 36,
	DesignerConstant2_MissionRewardUnopposedMultiplier = 37,
	DesignerConstant2_MobileRadarTowerTickTime = 38,
	DesignerConstant2_MufflerCoastingTime = 39,
	DesignerConstant2_ObjectiveHoldTickTime = 40,
	DesignerConstant2_ObjectiveProximityDistance = 41,
	DesignerConstant2_ObjectiveProximityTickTime = 42,
	DesignerConstant2_PlayerVisibilityLOSLostDelay = 43,
	DesignerConstant2_PlayerVisibilityMinDistance = 44,
	DesignerConstant2_PointOfInterestTickTime = 45,
	DesignerConstant2_PremiumPopupMissionInterval = 46,
	DesignerConstant2_ProvingGrounds_MissionActivity_SkipCooldownTimer = 47,
	DesignerConstant2_RelevanceDistance = 48,
	DesignerConstant2_RemoteDetonationMaximumTime = 49,
	DesignerConstant2_ScoreAssistDamageMultiplier = 50,
	DesignerConstant2_ScoreAssistMaximum = 51,
	DesignerConstant2_ScoreEventsforParticipation = 52,
	DesignerConstant2_ScoreMinimumForParticipation = 53,
	DesignerConstant2_ScoreObjectiveHoldPointsMultiplier = 54,
	DesignerConstant2_SelfExplosiveDamageMultiplier = 55,
	DesignerConstant2_SelfWeaponDamageMultiplier = 56,
	DesignerConstant2_SilenceTimeDefault = 57,
	DesignerConstant2_SilenceTimeMax = 58,
	DesignerConstant2_SilenceTimeMin = 59,
	DesignerConstant2_SlowCharacterListTime = 60,
	DesignerConstant2_SpotOnDetonateDistance = 61,
	DesignerConstant2_SpotOnDetonateDuration = 62,
	DesignerConstant2_SpotterDuration = 63,
	DesignerConstant2_SurfingMultiplier = 64,
	DesignerConstant2_TaskItemBounceHeight = 65,
	DesignerConstant2_TaskItemCollisionDamageMultiplier = 66,
	DesignerConstant2_TaskItemDestroyedDamageStateLifeSpan = 67,
	DesignerConstant2_TaskItemMinimumCollisionDamage = 68,
	DesignerConstant2_TeamKickCooldownTime = 69,
	DesignerConstant2_TeamLeadershipReqCooldown = 70,
	DesignerConstant2_TeamLeadershipReqQuestionTimeOut = 71,
	DesignerConstant2_TeamLeadershipReqReferendumTimeOut = 72,
	DesignerConstant2_TutorialCompleteXObjectives = 73,
	DesignerConstant2_TutorialCookTime = 74,
	DesignerConstant2_TutorialMedalsWon = 75,
	DesignerConstant2_TutorialMissionScore = 76,
	DesignerConstant2_UIInactivityFadeAlpha = 77,
	DesignerConstant2_UIInactivityFadeInDuration = 78,
	DesignerConstant2_UIInactivityFadeOutDuration = 79,
	DesignerConstant2_UnsafeHeightTimerDuration = 80,
	DesignerConstant2_VehicleCollisionDamageMultiplier = 81,
	DesignerConstant2_VehicleDamageThresholdMultiplier = 82,
	DesignerConstant2_VehicleWeaponDamageMultiplier = 83,
	DesignerConstant2_WeaponAccuracyModifierMMMaximum = 84,
	DesignerConstant2_WeaponAccuracyModifierMMMinimum = 85,
	DesignerConstant2_WeaponAccuracyModifierMaximum = 86,
	DesignerConstant2_WeaponAccuracyModifierMinimum = 87,
	DesignerConstant2_WeaponAccuracyRadiusScaleRaycast = 88,
	DesignerConstant2_WeaponPickupResupplyFailedTimer = 89,
	DesignerConstant2_WeaponPingInterval = 90,
	DesignerConstant2_WeaponRetryFireTime = 91,
	DesignerConstant2_MAX = 92,
};
enum etDistrictType
{
	DistrictType_Action = 0,
	DistrictType_SocialEnforcer = 1,
	DistrictType_SocialCriminal = 2,
	DistrictType_SocialMixedFaction = 3,
	DistrictType_MAX = 4,
};
enum etGender
{
	kGENDER_None = 0,
	kGENDER_Male = 1,
	kGENDER_Female = 2,
	kGENDER_Both = 3,
	kGENDER_MAX = 4,
};
enum etHostingConfigFile
{
	HostingConfigFile_Account = 0,
	HostingConfigFile_TutorialSettings = 1,
	HostingConfigFile_Account3 = 2,
	HostingConfigFile_Account4 = 3,
	HostingConfigFile_Account5 = 4,
	HostingConfigFile_AccountTutorialSettings = 5,
	HostingConfigFile_AccountPersistentUI = 6,
	HostingConfigFile_InputBindings = 7,
	HostingConfigFile_UserOptions = 8,
	HostingConfigFile_AccountPersistent5 = 9,
	HostingConfigFile_Character1 = 10,
	HostingConfigFile_Character2 = 11,
	HostingConfigFile_CharacterMisc = 12,
	HostingConfigFile_Character4 = 13,
	HostingConfigFile_Character5 = 14,
	HostingConfigFile_CharacterPersistent1 = 15,
	HostingConfigFile_CharacterPersistent2 = 16,
	HostingConfigFile_CharacterPersistent3 = 17,
	HostingConfigFile_CharacterPersistent4 = 18,
	HostingConfigFile_CharacterPersistent5 = 19,
	HostingConfigFile_MAX = 20,
};
enum etHostingConfigFileType
{
	kHostingConfigFileType_Account = 0,
	kHostingConfigFileType_Character = 1,
	kHostingConfigFileType_MAX = 2,
};
enum EDistributionVectorLockFlags
{
	EDVLF_None = 0,
	EDVLF_XY = 1,
	EDVLF_XZ = 2,
	EDVLF_YZ = 3,
	EDVLF_XYZ = 4,
	EDVLF_MAX = 5,
};
enum EDistributionVectorMirrorFlags
{
	EDVMF_Same = 0,
	EDVMF_Different = 1,
	EDVMF_Mirror = 2,
	EDVMF_MAX = 3,
};
enum ESpikeDetectionMethod
{
	SD_FromLast = 0,
	SD_FromMean = 1,
	SD_StandardDeviation = 2,
	SD_MAX = 3,
};

/*
-----------------------------------------------------------------
 - Structs
-----------------------------------------------------------------
*/
//0x000004
//Pointer[0x17C652E0]
struct FPointer
{
	int                                                Dummy;                                            		// 0x000000 (0x0004)              
};
//0x000004
//dword[0x17C65278]
struct Fdword
{
	int                                                Dummy;                                            		// 0x000000 (0x0004)              
};
//0x000008
//QWord[0x17C65210]
struct FQWord
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
};
//0x000004
//uint[0x17C650D8]
struct Fuint
{
	int                                                A;                                                		// 0x000000 (0x0004)              
};
//0x000004
//ThreadSafeCounter[0x17C65070]
struct FThreadSafeCounter
{
	int                                                Value;                                            		// 0x000000 (0x0004)              
};
//0x00001C
//BitArray_Mirror[0x17C65008]
struct FBitArray_Mirror
{
	DWORD                                              IndirectData;                                     		// 0x000000 (0x0004)              
	int                                                InlineData[0x4];                                  		// 0x000004 (0x0010)              
	int                                                NumBits;                                          		// 0x000014 (0x0004)              
	int                                                MaxBits;                                          		// 0x000018 (0x0004)              
};
//0x000030
//SparseArray_Mirror[0x17C64FA0]
struct FSparseArray_Mirror
{
	TArray<int>                                        Elements;                                         		// 0x000000 (0x000C)              
	struct FBitArray_Mirror                            AllocationFlags;                                  		// 0x00000C (0x001C)              
	int                                                FirstFreeIndex;                                   		// 0x000028 (0x0004)              
	int                                                NumFreeIndices;                                   		// 0x00002C (0x0004)              
};
//0x00003C
//Set_Mirror[0x17C64F38]
struct FSet_Mirror
{
	struct FSparseArray_Mirror                         Elements;                                         		// 0x000000 (0x0030)              
	int                                                InlineHash;                                       		// 0x000030 (0x0004)              
	DWORD                                              Hash;                                             		// 0x000034 (0x0004)              
	int                                                HashSize;                                         		// 0x000038 (0x0004)              
};
//0x00003C
//Map_Mirror[0x17C64ED0]
struct FMap_Mirror
{
	struct FSet_Mirror                                 Pairs;                                            		// 0x000000 (0x003C)              
};
//0x00003C
//MultiMap_Mirror[0x17C64E68]
struct FMultiMap_Mirror
{
	struct FSet_Mirror                                 Pairs;                                            		// 0x000000 (0x003C)              
};
//0x00000C (0x000048 - 0x00003C)
//LookupMap_Mirror[0x17C64E00]
struct FLookupMap_Mirror : FMultiMap_Mirror
{
	TArray<int>                                        UniqueElements;                                   		// 0x00003C (0x000C)              
};
//0x000034
//UntypedBulkData_Mirror[0x17C64D98]
struct FUntypedBulkData_Mirror
{
	DWORD                                              VfTable;                                          		// 0x000000 (0x0004)              
	int                                                BulkDataFlags;                                    		// 0x000004 (0x0004)              
	int                                                ElementCount;                                     		// 0x000008 (0x0004)              
	int                                                BulkDataOffsetInFile;                             		// 0x00000C (0x0004)              
	int                                                BulkDataSizeOnDisk;                               		// 0x000010 (0x0004)              
	int                                                SavedBulkDataFlags;                               		// 0x000014 (0x0004)              
	int                                                SavedElementCount;                                		// 0x000018 (0x0004)              
	int                                                SavedBulkDataOffsetInFile;                        		// 0x00001C (0x0004)              
	int                                                SavedBulkDataSizeOnDisk;                          		// 0x000020 (0x0004)              
	DWORD                                              BulkData;                                         		// 0x000024 (0x0004)              
	int                                                LockStatus;                                       		// 0x000028 (0x0004)              
	DWORD                                              AttachedAr;                                       		// 0x00002C (0x0004)              
	DWORD                                              LockOwner;                                        		// 0x000030 (0x0004)              
};
//0x000004 (0x000038 - 0x000034)
//TextureMipBulkData_Mirror[0x17C64D30]
struct FTextureMipBulkData_Mirror : FUntypedBulkData_Mirror
{
	int                                                bShouldFreeOnEmtpy;                               		// 0x000034 (0x0004)              
};
//0x000004
//RenderCommandFence_Mirror[0x17C64CC8]
struct FRenderCommandFence_Mirror
{
	int                                                NumPendingFences;                                 		// 0x000000 (0x0004)              
};
//0x00000C
//IndirectArray_Mirror[0x17C64C60]
struct FIndirectArray_Mirror
{
	DWORD                                              Data;                                             		// 0x000000 (0x0004)              
	int                                                ArrayNum;                                         		// 0x000004 (0x0004)              
	int                                                ArrayMax;                                         		// 0x000008 (0x0004)              
};
//0x00000C
//Array_Mirror[0x17C64BF8]
struct FArray_Mirror
{
	DWORD                                              Data;                                             		// 0x000000 (0x0004)              
	int                                                ArrayNum;                                         		// 0x000004 (0x0004)              
	int                                                ArrayMax;                                         		// 0x000008 (0x0004)              
};
//0x000010
//InlinePointerArray_Mirror[0x17C64B90]
struct FInlinePointerArray_Mirror
{
	DWORD                                              InlineData;                                       		// 0x000000 (0x0004)              
	struct FArray_Mirror                               SecondaryData;                                    		// 0x000004 (0x000C)              
};
//0x000010
//Guid[0x17C64B28]
struct FGuid
{
	int                                                A;                                                		// 0x000000 (0x0004)              
	int                                                B;                                                		// 0x000004 (0x0004)              
	int                                                C;                                                		// 0x000008 (0x0004)              
	int                                                D;                                                		// 0x00000C (0x0004)              
};
//0x00000C
//Vector[0x17C64AC0]
struct FVector
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
	float                                              Z;                                                		// 0x000008 (0x0004)              
};
//0x000010
//Vector4[0x17C64A58]
struct FVector4
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
	float                                              Z;                                                		// 0x000008 (0x0004)              
	float                                              W;                                                		// 0x00000C (0x0004)              
};
//0x000008
//Vector2D[0x17C649F0]
struct FVector2D
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
};
//0x000018
//TwoVectors[0x17C64988]
struct FTwoVectors
{
	FVector3                                           v1;                                               		// 0x000000 (0x000C)              
	FVector3                                           v2;                                               		// 0x00000C (0x000C)              
};
//0x000004 (0x000010 - 0x00000C)
//Plane[0x17C64920]
struct FPlane : FVector
{
	float                                              W;                                                		// 0x00000C (0x0004)              
};
//0x00000C
//Rotator[0x17C648B8]
struct FRotator
{
	int                                                Pitch;                                            		// 0x000000 (0x0004)              
	int                                                Yaw;                                              		// 0x000004 (0x0004)              
	int                                                Roll;                                             		// 0x000008 (0x0004)              
};
//0x000010
//Quat[0x17C64850]
struct FQuat
{
	float                                              X;                                                		// 0x000000 (0x0004)              
	float                                              Y;                                                		// 0x000004 (0x0004)              
	float                                              Z;                                                		// 0x000008 (0x0004)              
	float                                              W;                                                		// 0x00000C (0x0004)              
};
//0x000004
//PackedNormal[0x17C647E8]
struct FPackedNormal
{
	unsigned char                                      X;                                                		// 0x000000 (0x0001)              PROPERTY: 
	unsigned char                                      Y;                                                		// 0x000001 (0x0001)              PROPERTY: 
	unsigned char                                      Z;                                                		// 0x000002 (0x0001)              PROPERTY: 
	unsigned char                                      W;                                                		// 0x000003 (0x0001)              PROPERTY: 
};
//0x000008
//IntPoint[0x17C64780]
struct FIntPoint
{
	int                                                X;                                                		// 0x000000 (0x0004)              
	int                                                Y;                                                		// 0x000004 (0x0004)              
};
//0x000030
//SHVector[0x17C64718]
struct FSHVector
{
	float                                              V[0x9];                                           		// 0x000000 (0x0024)              
	float                                              Padding[0x3];                                     		// 0x000024 (0x000C)              
};
//0x000090
//SHVectorRGB[0x17C646B0]
struct FSHVectorRGB
{
	struct FSHVector                                   R;                                                		// 0x000000 (0x0030)              
	struct FSHVector                                   G;                                                		// 0x000030 (0x0030)              
	struct FSHVector                                   B;                                                		// 0x000060 (0x0030)              
};
//0x00001C
//TPOV[0x17C64648]
struct FTPOV
{
	FVector3                                           Location;                                         		// 0x000000 (0x000C)              
	FRotator                                           Rotation;                                         		// 0x00000C (0x000C)              
	float                                              FOV;                                              		// 0x000018 (0x0004)              
};
//0x000004
//Color[0x17C645E0]
struct FColor
{
	unsigned char                                      B;                                                		// 0x000000 (0x0001)              PROPERTY: 
	unsigned char                                      G;                                                		// 0x000001 (0x0001)              PROPERTY: 
	unsigned char                                      R;                                                		// 0x000002 (0x0001)              PROPERTY: 
	unsigned char                                      A;                                                		// 0x000003 (0x0001)              PROPERTY: 
};
//0x000010
//LinearColor[0x17C64578]
struct FLinearColor
{
	float                                              R;                                                		// 0x000000 (0x0004)              
	float                                              G;                                                		// 0x000004 (0x0004)              
	float                                              B;                                                		// 0x000008 (0x0004)              
	float                                              A;                                                		// 0x00000C (0x0004)              
};
//0x000019
//Box[0x17C64510]
struct FBox
{
	FVector3                                           Min;                                              		// 0x000000 (0x000C)              
	FVector3                                           Max;                                              		// 0x00000C (0x000C)              
	unsigned char                                      IsValid;                                          		// 0x000018 (0x0001)              PROPERTY: 
};
//0x00001C
//BoxSphereBounds[0x17C644A8]
struct FBoxSphereBounds
{
	FVector3                                           Origin;                                           		// 0x000000 (0x000C)              
	FVector3                                           BoxExtent;                                        		// 0x00000C (0x000C)              
	float                                              SphereRadius;                                     		// 0x000018 (0x0004)              
};
//0x000040
//Matrix[0x17C64440]
struct FMatrix
{
	struct FPlane                                      XPlane;                                           		// 0x000000 (0x0010)              
	struct FPlane                                      YPlane;                                           		// 0x000010 (0x0010)              
	struct FPlane                                      ZPlane;                                           		// 0x000020 (0x0010)              
	struct FPlane                                      WPlane;                                           		// 0x000030 (0x0010)              
};
//0x000008
//Cylinder[0x17C643D8]
struct FCylinder
{
	float                                              Radius;                                           		// 0x000000 (0x0004)              
	float                                              Height;                                           		// 0x000004 (0x0004)              
};
//0x000011
//InterpCurvePointFloat[0x17C64370]
struct FInterpCurvePointFloat
{
	float                                              InVal;                                            		// 0x000000 (0x0004)              
	float                                              OutVal;                                           		// 0x000004 (0x0004)              
	float                                              ArriveTangent;                                    		// 0x000008 (0x0004)              
	float                                              LeaveTangent;                                     		// 0x00000C (0x0004)              
	unsigned char                                      InterpMode;                                       		// 0x000010 (0x0001)              PROPERTY: EInterpCurveMode
};
//0x00000D
//InterpCurveFloat[0x17C64308]
struct FInterpCurveFloat
{
	TArray<struct FInterpCurvePointFloat>              Points;                                           		// 0x000000 (0x000C)              
	unsigned char                                      InterpMethod;                                     		// 0x00000C (0x0001)              PROPERTY: EInterpMethodType
};
//0x00001D
//InterpCurvePointVector2D[0x17C642A0]
struct FInterpCurvePointVector2D
{
	float                                              InVal;                                            		// 0x000000 (0x0004)              
	FVector2                                           OutVal;                                           		// 0x000004 (0x0008)              
	FVector2                                           ArriveTangent;                                    		// 0x00000C (0x0008)              
	FVector2                                           LeaveTangent;                                     		// 0x000014 (0x0008)              
	unsigned char                                      InterpMode;                                       		// 0x00001C (0x0001)              PROPERTY: EInterpCurveMode
};
//0x00000D
//InterpCurveVector2D[0x17C64238]
struct FInterpCurveVector2D
{
	TArray<struct FInterpCurvePointVector2D>           Points;                                           		// 0x000000 (0x000C)              
	unsigned char                                      InterpMethod;                                     		// 0x00000C (0x0001)              PROPERTY: EInterpMethodType
};
//0x000029
//InterpCurvePointVector[0x17C641D0]
struct FInterpCurvePointVector
{
	float                                              InVal;                                            		// 0x000000 (0x0004)              
	FVector3                                           OutVal;                                           		// 0x000004 (0x000C)              
	FVector3                                           ArriveTangent;                                    		// 0x000010 (0x000C)              
	FVector3                                           LeaveTangent;                                     		// 0x00001C (0x000C)              
	unsigned char                                      InterpMode;                                       		// 0x000028 (0x0001)              PROPERTY: EInterpCurveMode
};
//0x00000D
//InterpCurveVector[0x17C64168]
struct FInterpCurveVector
{
	TArray<struct FInterpCurvePointVector>             Points;                                           		// 0x000000 (0x000C)              
	unsigned char                                      InterpMethod;                                     		// 0x00000C (0x0001)              PROPERTY: EInterpMethodType
};
//0x00004D
//InterpCurvePointTwoVectors[0x17C64100]
struct FInterpCurvePointTwoVectors
{
	float                                              InVal;                                            		// 0x000000 (0x0004)              
	struct FTwoVectors                                 OutVal;                                           		// 0x000004 (0x0018)              
	struct FTwoVectors                                 ArriveTangent;                                    		// 0x00001C (0x0018)              
	struct FTwoVectors                                 LeaveTangent;                                     		// 0x000034 (0x0018)              
	unsigned char                                      InterpMode;                                       		// 0x00004C (0x0001)              PROPERTY: EInterpCurveMode
};
//0x00000D
//InterpCurveTwoVectors[0x17C64098]
struct FInterpCurveTwoVectors
{
	TArray<struct FInterpCurvePointTwoVectors>         Points;                                           		// 0x000000 (0x000C)              
	unsigned char                                      InterpMethod;                                     		// 0x00000C (0x0001)              PROPERTY: EInterpMethodType
};
//0x000041
//InterpCurvePointQuat[0x17C64030]
struct FInterpCurvePointQuat
{
	float                                              InVal;                                            		// 0x000000 (0x0004)              
	unsigned char                                      _0x000004[0xC];                                   		// 0x000004 (0x000C) MISSED OFFSET
	struct FQuat                                       OutVal;                                           		// 0x000010 (0x0010)              
	struct FQuat                                       ArriveTangent;                                    		// 0x000020 (0x0010)              
	struct FQuat                                       LeaveTangent;                                     		// 0x000030 (0x0010)              
	unsigned char                                      InterpMode;                                       		// 0x000040 (0x0001)              PROPERTY: EInterpCurveMode
};
//0x00000D
//InterpCurveQuat[0x17C63FC8]
struct FInterpCurveQuat
{
	TArray<struct FInterpCurvePointQuat>               Points;                                           		// 0x000000 (0x000C)              
	unsigned char                                      InterpMethod;                                     		// 0x00000C (0x0001)              PROPERTY: EInterpMethodType
};
//0x000018
//RawDistribution[0x17C63F60]
struct FRawDistribution
{
	unsigned char                                      Type;                                             		// 0x000000 (0x0001)              PROPERTY: 
	unsigned char                                      Op;                                               		// 0x000001 (0x0001)              PROPERTY: 
	unsigned char                                      LookupTableNumElements;                           		// 0x000002 (0x0001)              PROPERTY: 
	unsigned char                                      LookupTableChunkSize;                             		// 0x000003 (0x0001)              PROPERTY: 
	TArray<float>                                      LookupTable;                                      		// 0x000004 (0x000C)              
	float                                              LookupTableTimeScale;                             		// 0x000010 (0x0004)              
	float                                              LookupTableStartTime;                             		// 0x000014 (0x0004)              
};
//0x000004
//RenderCommandFence[0x17C63EF8]
struct FRenderCommandFence
{
	int                                                NumPendingFences;                                 		// 0x000000 (0x0004)              
};
//0x000030
//BoneAtom[0x17C63E90]
struct FBoneAtom
{
	struct FQuat                                       Rotation;                                         		// 0x000000 (0x0010)              
	FVector3                                           Translation;                                      		// 0x000010 (0x000C)              
	unsigned long                                      bPropagateScaling : 1;                            		// 0x00001C (0x0004) [0x00000001] 
	FVector3                                           Scale;                                            		// 0x000020 (0x000C)              
	unsigned long                                      bScale : 1;                                       		// 0x00002C (0x0004) [0x00000001] 
};
//0x000010
//EnumeratedName[0x17C63E28]
struct FEnumeratedName
{
	struct FName                                       MetaType;                                         		// 0x000000 (0x0008)              
	struct FName                                       Value;                                            		// 0x000008 (0x0008)              
};
//0x000011
//sAPBCollision[0x17C63DC0]
struct FsAPBCollision
{
	int                                                bits0;                                            		// 0x000000 (0x0004)              
	int                                                bits1;                                            		// 0x000004 (0x0004)              
	int                                                bits2;                                            		// 0x000008 (0x0004)              
	int                                                bits3;                                            		// 0x00000C (0x0004)              
	unsigned char                                      category;                                         		// 0x000010 (0x0001)              PROPERTY: ECollisionCategory
};
//0x000014
//StReplicatedArray[0x17C63D58]
struct FStReplicatedArray
{
	int                                                nVersion;                                         		// 0x000000 (0x0004)              
	class UClass*                                      ElementsClass;                                    		// 0x000004 (0x0004)              
	TArray<class UObject*>                             aElements;                                        		// 0x000008 (0x000C)              
};
//0x000002
//Float16[0x17C63CF0]
struct FFloat16
{
	unsigned char                                      encoding[0x2];                                    		// 0x000000 (0x0002)              PROPERTY: 
};
//0x000008
//Vector2DHalf[0x17C63C88]
struct FVector2DHalf
{
	struct FFloat16                                    X;                                                		// 0x000000 (0x0004)              
	struct FFloat16                                    Y;                                                		// 0x000004 (0x0004)              
};
//0x000004
//DesignerConstant[0x17C63C20]
struct FDesignerConstant
{
	float                                              m_fValue;                                         		// 0x000000 (0x0004)              
};
//0x000011
//DesignerConstant2[0x17C63BB8]
struct FDesignerConstant2
{
	struct FString                                     m_sComment;                                       		// 0x000000 (0x000C)              
	float                                              m_fValue;                                         		// 0x00000C (0x0004)              
	unsigned char                                      m_eDesignerConstant2;                             		// 0x000010 (0x0001)              PROPERTY: etDesignerConstant2
};
//0x000010
//tOutOfLineBulkData[0x17C63B50]
struct FtOutOfLineBulkData
{
	int                                                nFileOffset;                                      		// 0x000000 (0x0004)              
	DWORD                                              pBulkData;                                        		// 0x000004 (0x0004)              
	class UObject*                                     pObject;                                          		// 0x000008 (0x0004)              
	int                                                nIndex;                                           		// 0x00000C (0x0004)              
};
//0x000004 (0x00001C - 0x000018)
//RawDistributionFloat[0x17C63AE8]
struct FRawDistributionFloat : FRawDistribution
{
	class UDistributionFloat*                          Distribution;                                     		// 0x000018 (0x0004)              
};
//0x000004 (0x00001C - 0x000018)
//RawDistributionVector[0x17C63A80]
struct FRawDistributionVector : FRawDistribution
{
	class UDistributionVector*                         Distribution;                                     		// 0x000018 (0x0004)              
};
//0x000030
//SpikeWatch[0x17C63A18]
struct FSpikeWatch
{
	struct Fdword                                      nIgnoreFlags;                                     		// 0x000000 (0x0004)              
	float                                              fDetectionLimit;                                  		// 0x000004 (0x0004)              
	float                                              fDetectionLimitPercent;                           		// 0x000008 (0x0004)              
	unsigned char                                      eDetectionMethod;                                 		// 0x00000C (0x0001)              PROPERTY: ESpikeDetectionMethod
	unsigned char                                      _0x00000D[0x3];                                   		// 0x00000D (0x0003) MISSED OFFSET
	TArray<float>                                      fStatHistoryBuffer;                               		// 0x000010 (0x000C)              
	int                                                nHeadOfHistoryBuffer;                             		// 0x00001C (0x0004)              
	unsigned long                                      bIsHistoryBufferInit : 1;                         		// 0x000020 (0x0004) [0x00000001] 
	int                                                nNumFramesSpiked;                                 		// 0x000024 (0x0004)              
	float                                              fHistoryBufferMean;                               		// 0x000028 (0x0004)              
	float                                              fHistoryBufferStdDev;                             		// 0x00002C (0x0004)              
};
//0x000014
//SpikeRecord[0x17C639B0]
struct FSpikeRecord
{
	struct Fdword                                      nStatID;                                          		// 0x000000 (0x0004)              
	int                                                nConsecutiveFrames;                               		// 0x000004 (0x0004)              
	struct Fdword                                      nEventFlags;                                      		// 0x000008 (0x0004)              
	float                                              fTriggerValue;                                    		// 0x00000C (0x0004)              
	float                                              fBaseValue;                                       		// 0x000010 (0x0004)              
};

/*
-----------------------------------------------------------------
 - Classes
-----------------------------------------------------------------
*/
//0x000040
//Object[0x026BFCF0]
class UObject
{
public:
	DWORD                                              VfTableObject;                                    		// 0x000000 (0x0004)              
	DWORD                                              HashNext;                                         		// 0x000004 (0x0004)              
	struct FQWord                                      ObjectFlags;                                      		// 0x000008 (0x0008)              
	class UObject*                                     Linker;                                           		// 0x000010 (0x0004)              
	int                                                NetIndex;                                         		// 0x000014 (0x0004)              
	int                                                nDynRefsIndex;                                    		// 0x000018 (0x0004)              
	class UClass*                                      Class;                                            		// 0x00001C (0x0004)              
	struct FName                                       Name;                                             		// 0x000020 (0x0008)              
	class UObject*                                     ObjectArchetype;                                  		// 0x000028 (0x0004)              
	DWORD                                              StateFrame;                                       		// 0x00002C (0x0004)              
	int                                                ObjectInternalInteger;                            		// 0x000030 (0x0004)              
	DWORD                                              LinkerIndex;                                      		// 0x000034 (0x0004)              
	class UObject*                                     Outer;                                            		// 0x000038 (0x0004)              
	DWORD                                              HashOuterNext;                                    		// 0x00003C (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Object");
		return pClassPointer;
	};

public:
	FVector3 VInterpTo(FVector3 Current,FVector3 Target,float DeltaTime,float InterpSpeed);//Core.Object.VInterpTo
	struct FQuat QuatSlerp(struct FQuat A,struct FQuat B,float Alpha,bool bShortestPath);//Core.Object.QuatSlerp
	FVector3 Divide_VectorFloat(FVector3 A,float B);//Core.Object.Divide_VectorFloat
	int LessLess_IntInt(int A,int B);//Core.Object.LessLess_IntInt
	FRotator MultiplyEqual_RotatorFloat(FRotator* A,float B);//Core.Object.MultiplyEqual_RotatorFloat
	float FInterpEaseIn(float A,float B,float Alpha,float Exp);//Core.Object.FInterpEaseIn
	void PushState(struct FName NewState,struct FName NewLabel);//Core.Object.PushState
	double Divide_DoubleDouble(double A,double B);//Core.Object.Divide_DoubleDouble
	FVector3 InverseTransformVector(FMatrix TM,FVector3 A);//Core.Object.InverseTransformVector
	double DSqrt(double A);//Core.Object.DSqrt
	void WarnInternal(struct FString S);//Core.Object.WarnInternal
	double DCos(double A);//Core.Object.DCos
	FVector3 MirrorVectorByNormal(FVector3 InVect,FVector3 InNormal);//Core.Object.MirrorVectorByNormal
	float GetHeadingAngle(FVector3 Dir);//Core.Object.GetHeadingAngle
	struct FQuat QuatInvert(struct FQuat A);//Core.Object.QuatInvert
	float MultiplyEqual_FloatFloat(float* A,float B);//Core.Object.MultiplyEqual_FloatFloat
	struct FString Concat_StrStr(struct FString A,struct FString B);//Core.Object.Concat_StrStr
	struct FString PathName(class UObject* CheckObject);//Core.Object.PathName
	struct FString Right(struct FString S,int I);//Core.Object.Right
	void GetAngularFromDotDist(FVector2* OutAngDist,FVector2 DotDist);//Core.Object.GetAngularFromDotDist
	void SaveConfig();//Core.Object.SaveConfig
	int MultiplyEqual_IntFloat(int* A,float B);//Core.Object.MultiplyEqual_IntFloat
	float FMin(float A,float B);//Core.Object.FMin
	double DAbs(double A);//Core.Object.DAbs
	double DTan(double A);//Core.Object.DTan
	void SetUTracing(bool bShouldUTrace);//Core.Object.SetUTracing
	double DAsin(double A);//Core.Object.DAsin
	bool EqualEqual_DoubleDouble(double A,double B);//Core.Object.EqualEqual_DoubleDouble
	float GetRangeValueByPct(FVector2 Range,float Pct);//Core.Object.GetRangeValueByPct
	bool LessEqual_IntInt(int A,int B);//Core.Object.LessEqual_IntInt
	double DMax(double A,double B);//Core.Object.DMax
	int And_IntInt(int A,int B);//Core.Object.And_IntInt
	bool Less_DoubleDouble(double A,double B);//Core.Object.Less_DoubleDouble
	FVector3 VLerp(FVector3 A,FVector3 B,float Alpha);//Core.Object.VLerp
	float FCubicInterp(float P0,float T0,float P1,float T1,float A);//Core.Object.FCubicInterp
	unsigned char AddAdd_PreByte(unsigned char* A);//Core.Object.AddAdd_PreByte
	float PointDistToLine(FVector3 Point,FVector3 Line,FVector3 Origin,FVector3* OutClosestPoint);//Core.Object.PointDistToLine
	struct FString ConcatEqual_StrStr(struct FString* A,struct FString B);//Core.Object.ConcatEqual_StrStr
	bool ClockwiseFrom_IntInt(int A,int B);//Core.Object.ClockwiseFrom_IntInt
	bool EqualEqual_InterfaceInterface(class UInterface* A,class UInterface* B);//Core.Object.EqualEqual_InterfaceInterface
	struct FQuat QuatFindBetween(FVector3 A,FVector3 B);//Core.Object.QuatFindBetween
	FRotator RLerp(FRotator A,FRotator B,float Alpha,bool bShortestPath);//Core.Object.RLerp
	FRotator AddEqual_RotatorRotator(FRotator* A,FRotator B);//Core.Object.AddEqual_RotatorRotator
	float FMax(float A,float B);//Core.Object.FMax
	bool LessEqual_StrStr(struct FString A,struct FString B);//Core.Object.LessEqual_StrStr
	DWORD MakeColor(unsigned char R,unsigned char G,unsigned char B,unsigned char A);//Core.Object.MakeColor
	struct FString Localize(struct FString SectionName,struct FString KeyName,struct FString PackageName);//Core.Object.Localize
	float DivideEqual_FloatFloat(float* A,float B);//Core.Object.DivideEqual_FloatFloat
	bool Not_PreBool(bool A);//Core.Object.Not_PreBool
	FVector3 InverseTransformNormal(FMatrix TM,FVector3 A);//Core.Object.InverseTransformNormal
	bool IsUTracing();//Core.Object.IsUTracing
	bool ComplementEqual_FloatFloat(float A,float B);//Core.Object.ComplementEqual_FloatFloat
	float Tan(float A);//Core.Object.Tan
	FVector3 LessLess_VectorRotator(FVector3 A,FRotator B);//Core.Object.LessLess_VectorRotator
	int Max(int A,int B);//Core.Object.Max
	FVector3 Add_VectorVector(FVector3 A,FVector3 B);//Core.Object.Add_VectorVector
	bool EqualEqual_FieldField(class UField* A,class UField* B);//Core.Object.EqualEqual_FieldField
	float Lerp(float A,float B,float Alpha);//Core.Object.Lerp
	FVector3 MultiplyEqual_VectorFloat(FVector3* A,float B);//Core.Object.MultiplyEqual_VectorFloat
	int SubtractSubtract_PreInt(int* A);//Core.Object.SubtractSubtract_PreInt
	bool Greater_FloatFloat(float A,float B);//Core.Object.Greater_FloatFloat
	int Xor_IntInt(int A,int B);//Core.Object.Xor_IntInt
	FRotator Normalize(FRotator Rot);//Core.Object.Normalize
	FVector3 Subtract_VectorVector(FVector3 A,FVector3 B);//Core.Object.Subtract_VectorVector
	unsigned char DivideEqual_ByteByte(unsigned char* A,unsigned char B);//Core.Object.DivideEqual_ByteByte
	bool GetPerObjectConfigSections(class UClass* SearchClass,TArray<struct FString>* out_SectionNames,class UObject* ObjectOuter,int MaxResults);//Core.Object.GetPerObjectConfigSections
	bool NotEqual_BoolBool(bool A,bool B);//Core.Object.NotEqual_BoolBool
	bool IsPendingKill();//Core.Object.IsPendingKill
	void BeginState(struct FName PreviousStateName);//Core.Object.BeginState
	FRotator Divide_RotatorFloat(FRotator A,float B);//Core.Object.Divide_RotatorFloat
	bool IsInState(struct FName TestState,bool bTestStateStack);//Core.Object.IsInState
	struct FName GetStateName();//Core.Object.GetStateName
	FVector3 SubtractEqual_VectorVector(FVector3* A,FVector3 B);//Core.Object.SubtractEqual_VectorVector
	bool EqualEqual_RotatorRotator(FRotator A,FRotator B);//Core.Object.EqualEqual_RotatorRotator
	void StaticSaveConfig();//Core.Object.StaticSaveConfig
	struct FString Mid(struct FString S,int I,int J);//Core.Object.Mid
	int Add_IntInt(int A,int B);//Core.Object.Add_IntInt
	FVector2 vect2d(float InX,float InY);//Core.Object.vect2d
	float Exp(float A);//Core.Object.Exp
	int DivideEqual_IntFloat(int* A,float B);//Core.Object.DivideEqual_IntFloat
	int Asc(struct FString S);//Core.Object.Asc
	bool NotEqual_FieldField(class UField* A,class UField* B);//Core.Object.NotEqual_FieldField
	bool GetAngularDistance(FVector2* OutAngularDist,FVector3 Direction,FVector3 AxisX,FVector3 AxisY,FVector3 AxisZ);//Core.Object.GetAngularDistance
	bool AndAnd_BoolBool(bool A,bool B);//Core.Object.AndAnd_BoolBool
	int DFloor(double A);//Core.Object.DFloor
	FVector3 VRand();//Core.Object.VRand
	FVector3 DivideEqual_VectorFloat(FVector3* A,float B);//Core.Object.DivideEqual_VectorFloat
	int AddEqual_IntInt(int* A,int B);//Core.Object.AddEqual_IntInt
	void PausedState();//Core.Object.PausedState
	float Abs(float A);//Core.Object.Abs
	void Enable(struct FName ProbeFunc);//Core.Object.Enable
	float Multiply_FloatFloat(float A,float B);//Core.Object.Multiply_FloatFloat
	double MultiplyEqual_DoubleDouble(double* A,double B);//Core.Object.MultiplyEqual_DoubleDouble
	FRotator RotRand(bool bRoll);//Core.Object.RotRand
	float VSizeSq(FVector3 A);//Core.Object.VSizeSq
	bool LogReturnFalse(struct FString logString);//Core.Object.LogReturnFalse
	unsigned char SubtractSubtract_Byte(unsigned char* A);//Core.Object.SubtractSubtract_Byte
	FVector3 Normal(FVector3 A);//Core.Object.Normal
	double DLerp(double A,double B,double Alpha);//Core.Object.DLerp
	void Disable(struct FName ProbeFunc);//Core.Object.Disable
	FVector3 Cross_VectorVector(FVector3 A,FVector3 B);//Core.Object.Cross_VectorVector
	FVector3 ClampLength(FVector3 V,float MaxLength);//Core.Object.ClampLength
	int Round(float A);//Core.Object.Round
	bool IsUserBuild();//Core.Object.IsUserBuild
	struct FQuat QuatFromAxisAndAngle(FVector3 Axis,float Angle);//Core.Object.QuatFromAxisAndAngle
	float PointDistToPlane(FVector3 Point,FRotator Orientation,FVector3 Origin,FVector3* out_ClosestPoint);//Core.Object.PointDistToPlane
	FRotator Add_RotatorRotator(FRotator A,FRotator B);//Core.Object.Add_RotatorRotator
	unsigned char FloatToByte(float inputFloat,bool bSigned);//Core.Object.FloatToByte
	bool GreaterEqual_FloatFloat(float A,float B);//Core.Object.GreaterEqual_FloatFloat
	FVector3 GreaterGreater_VectorRotator(FVector3 A,FRotator B);//Core.Object.GreaterGreater_VectorRotator
	float RDiff(FRotator A,FRotator B);//Core.Object.RDiff
	struct FLinearColor Subtract_LinearColorLinearColor(struct FLinearColor A,struct FLinearColor B);//Core.Object.Subtract_LinearColorLinearColor
	bool NotEqual_VectorVector(FVector3 A,FVector3 B);//Core.Object.NotEqual_VectorVector
	int Multiply_IntInt(int A,int B);//Core.Object.Multiply_IntInt
	FRotator SubtractEqual_RotatorRotator(FRotator* A,FRotator B);//Core.Object.SubtractEqual_RotatorRotator
	float FindDeltaAngle(float A1,float A2);//Core.Object.FindDeltaAngle
	float SubtractEqual_FloatFloat(float* A,float B);//Core.Object.SubtractEqual_FloatFloat
	float Cos(float A);//Core.Object.Cos
	FRotator Multiply_RotatorFloat(FRotator A,float B);//Core.Object.Multiply_RotatorFloat
	double DAcos(double A);//Core.Object.DAcos
	int SubtractEqual_IntInt(int* A,int B);//Core.Object.SubtractEqual_IntInt
	float Subtract_FloatFloat(float A,float B);//Core.Object.Subtract_FloatFloat
	DWORD Multiply_ColorFloat(DWORD A,float B);//Core.Object.Multiply_ColorFloat
	bool IsChildState(struct FName TestState,struct FName TestParentState);//Core.Object.IsChildState
	double DAtan(double A,double B);//Core.Object.DAtan
	int AddAdd_Int(int* A);//Core.Object.AddAdd_Int
	unsigned char AddAdd_Byte(unsigned char* A);//Core.Object.AddAdd_Byte
	float FInterpTo(float Current,float Target,float DeltaTime,float InterpSpeed);//Core.Object.FInterpTo
	bool NotEqual_InterfaceInterface(class UInterface* A,class UInterface* B);//Core.Object.NotEqual_InterfaceInterface
	DWORD Multiply_FloatColor(float A,DWORD B);//Core.Object.Multiply_FloatColor
	float MultiplyMultiply_FloatFloat(float Base,float Exp);//Core.Object.MultiplyMultiply_FloatFloat
	float FInterpEaseOut(float A,float B,float Alpha,float Exp);//Core.Object.FInterpEaseOut
	float FInterpEaseInOut(float A,float B,float Alpha,float Exp);//Core.Object.FInterpEaseInOut
	FVector3 Multiply_VectorFloat(FVector3 A,float B);//Core.Object.Multiply_VectorFloat
	float VSize(FVector3 A);//Core.Object.VSize
	float Loge(float A);//Core.Object.Loge
	FRotator Subtract_RotatorRotator(FRotator A,FRotator B);//Core.Object.Subtract_RotatorRotator
	float FPctByRange(float Value,float InMin,float InMax);//Core.Object.FPctByRange
	float AddEqual_FloatFloat(float* A,float B);//Core.Object.AddEqual_FloatFloat
	void EndState(struct FName NextStateName);//Core.Object.EndState
	double Multiply_DoubleDouble(double A,double B);//Core.Object.Multiply_DoubleDouble
	struct FName GetPackageName();//Core.Object.GetPackageName
	bool PointInBox(FVector3 Point,FVector3 Location,FVector3 Extent);//Core.Object.PointInBox
	bool Less_FloatFloat(float A,float B);//Core.Object.Less_FloatFloat
	double Subtract_DoubleDouble(double A,double B);//Core.Object.Subtract_DoubleDouble
	unsigned char MultiplyEqual_ByteFloat(unsigned char* A,float B);//Core.Object.MultiplyEqual_ByteFloat
	bool Less_IntInt(int A,int B);//Core.Object.Less_IntInt
	struct FString ToHex(int A);//Core.Object.ToHex
	FVector3 TransformVectorByRotation(FRotator SourceRotation,FVector3 SourceVector,bool bInverse);//Core.Object.TransformVectorByRotation
	float Atan(float A,float B);//Core.Object.Atan
	bool Greater_IntInt(int A,int B);//Core.Object.Greater_IntInt
	unsigned char SubtractSubtract_PreByte(unsigned char* A);//Core.Object.SubtractSubtract_PreByte
	double DivideEqual_DoubleDouble(double* A,double B);//Core.Object.DivideEqual_DoubleDouble
	struct FString At_StrStr(struct FString A,struct FString B);//Core.Object.At_StrStr
	void LogInternal(struct FString S,struct FName Tag);//Core.Object.LogInternal
	double AddEqual_DoubleDouble(double* A,double B);//Core.Object.AddEqual_DoubleDouble
	int Complement_PreInt(int A);//Core.Object.Complement_PreInt
	bool EqualEqual_NameName(struct FName A,struct FName B);//Core.Object.EqualEqual_NameName
	FRotator Multiply_FloatRotator(float A,FRotator B);//Core.Object.Multiply_FloatRotator
	double DLoge(double A);//Core.Object.DLoge
	int GreaterGreaterGreater_IntInt(int A,int B);//Core.Object.GreaterGreaterGreater_IntInt
	int DRound(double A);//Core.Object.DRound
	struct FQuat QuatProduct(struct FQuat A,struct FQuat B);//Core.Object.QuatProduct
	void ClampRotAxis(int ViewAxis,int* out_DeltaViewAxis,int MaxLimit,int MinLimit);//Core.Object.ClampRotAxis
	void GetUnAxes(FRotator A,FVector3* X,FVector3* Y,FVector3* Z);//Core.Object.GetUnAxes
	bool NotEqual_FloatFloat(float A,float B);//Core.Object.NotEqual_FloatFloat
	DWORD Add_ColorColor(DWORD A,DWORD B);//Core.Object.Add_ColorColor
	bool GreaterEqual_DoubleDouble(double A,double B);//Core.Object.GreaterEqual_DoubleDouble
	double DClamp(double V,double A,double B);//Core.Object.DClamp
	void NotifyReferenceToObject(class UObject* RefObject);//Core.Object.NotifyReferenceToObject
	bool EqualEqual_StrStr(struct FString A,struct FString B);//Core.Object.EqualEqual_StrStr
	void GotoState(struct FName NewState,struct FName Label,bool bForceEvents,bool bKeepStack);//Core.Object.GotoState
	double MultiplyMultiply_DoubleDouble(double Base,double Exp);//Core.Object.MultiplyMultiply_DoubleDouble
	struct FName GetEnum(class UField* E,int I);//Core.Object.GetEnum
	FRotator DivideEqual_RotatorFloat(FRotator* A,float B);//Core.Object.DivideEqual_RotatorFloat
	bool NotEqual_RotatorRotator(FRotator A,FRotator B);//Core.Object.NotEqual_RotatorRotator
	FVector3 ProjectOnTo(FVector3 X,FVector3 Y);//Core.Object.ProjectOnTo
	bool Greater_DoubleDouble(double A,double B);//Core.Object.Greater_DoubleDouble
	int FFloor(float A);//Core.Object.FFloor
	FRotator RInterpTo(FRotator Current,FRotator Target,float DeltaTime,float InterpSpeed);//Core.Object.RInterpTo
	int Len(struct FString S);//Core.Object.Len
	bool NotEqual_ObjectObject(class UObject* A,class UObject* B);//Core.Object.NotEqual_ObjectObject
	struct FName GetFuncName();//Core.Object.GetFuncName
	struct FString AtEqual_StrStr(struct FString* A,struct FString B);//Core.Object.AtEqual_StrStr
	void GetAngularDegreesFromRadians(FVector2* OutFOV);//Core.Object.GetAngularDegreesFromRadians
	float Percent_FloatFloat(float A,float B);//Core.Object.Percent_FloatFloat
	bool NotEqual_IntInt(int A,int B);//Core.Object.NotEqual_IntInt
	struct FQuat QuatFromRotator(FRotator A);//Core.Object.QuatFromRotator
	int ClampRotAxisFromRange(int Current,int Min,int Max);//Core.Object.ClampRotAxisFromRange
	float Subtract_PreFloat(float A);//Core.Object.Subtract_PreFloat
	bool GreaterEqual_StrStr(struct FString A,struct FString B);//Core.Object.GreaterEqual_StrStr
	float Asin(float A);//Core.Object.Asin
	bool EqualEqual_ObjectObject(class UObject* A,class UObject* B);//Core.Object.EqualEqual_ObjectObject
	int ClampRotAxisFromBase(int Current,int Center,int MaxDelta);//Core.Object.ClampRotAxisFromBase
	int Or_IntInt(int A,int B);//Core.Object.Or_IntInt
	double SubtractEqual_DoubleDouble(double* A,double B);//Core.Object.SubtractEqual_DoubleDouble
	FRotator QuatToRotator(struct FQuat A);//Core.Object.QuatToRotator
	FVector3 AddEqual_VectorVector(FVector3* A,FVector3 B);//Core.Object.AddEqual_VectorVector
	void ParseStringIntoArray(struct FString BaseString,TArray<struct FString>* Pieces,struct FString delim,bool bCullEmpty);//Core.Object.ParseStringIntoArray
	FRotator OrthoRotation(FVector3 X,FVector3 Y,FVector3 Z);//Core.Object.OrthoRotation
	void PopState(bool bPopAll);//Core.Object.PopState
	float RSize(FRotator R);//Core.Object.RSize
	void GetAxes(FRotator A,FVector3* X,FVector3* Y,FVector3* Z);//Core.Object.GetAxes
	struct FLinearColor MakeLinearColor(float R,float G,float B,float A);//Core.Object.MakeLinearColor
	struct FString SubtractEqual_StrStr(struct FString* A,struct FString B);//Core.Object.SubtractEqual_StrStr
	DWORD Subtract_ColorColor(DWORD A,DWORD B);//Core.Object.Subtract_ColorColor
	bool LessEqual_FloatFloat(float A,float B);//Core.Object.LessEqual_FloatFloat
	bool IsServerBuild();//Core.Object.IsServerBuild
	bool GreaterEqual_IntInt(int A,int B);//Core.Object.GreaterEqual_IntInt
	int AddAdd_PreInt(int* A);//Core.Object.AddAdd_PreInt
	struct FLinearColor Multiply_LinearColorFloat(struct FLinearColor LC,float Mult);//Core.Object.Multiply_LinearColorFloat
	float FRand();//Core.Object.FRand
	int Subtract_IntInt(int A,int B);//Core.Object.Subtract_IntInt
	unsigned char SubtractEqual_ByteByte(unsigned char* A,unsigned char B);//Core.Object.SubtractEqual_ByteByte
	FVector3 Subtract_PreVector(FVector3 A);//Core.Object.Subtract_PreVector
	float Sqrt(float A);//Core.Object.Sqrt
	double DRand();//Core.Object.DRand
	double DExp(double A);//Core.Object.DExp
	FVector3 MultiplyEqual_VectorVector(FVector3* A,FVector3 B);//Core.Object.MultiplyEqual_VectorVector
	FMatrix MakeRotationTranslationMatrix(FVector3 Translation,FRotator Rotation);//Core.Object.MakeRotationTranslationMatrix
	bool EqualEqual_VectorVector(FVector3 A,FVector3 B);//Core.Object.EqualEqual_VectorVector
	int Subtract_PreInt(int A);//Core.Object.Subtract_PreInt
	double DSquare(double A);//Core.Object.DSquare
	float ByteToFloat(unsigned char inputByte,bool bSigned);//Core.Object.ByteToFloat
	bool IsA(struct FName ClassName);//Core.Object.IsA
	FVector3 MatrixGetOrigin(FMatrix TM);//Core.Object.MatrixGetOrigin
	void DumpStateStack();//Core.Object.DumpStateStack
	bool ClassIsChildOf(class UClass* TestClass,class UClass* ParentClass);//Core.Object.ClassIsChildOf
	int Min(int A,int B);//Core.Object.Min
	FVector3 Multiply_VectorVector(FVector3 A,FVector3 B);//Core.Object.Multiply_VectorVector
	bool GetDotDistance(FVector2* OutDotDist,FVector3 Direction,FVector3 AxisX,FVector3 AxisY,FVector3 AxisZ);//Core.Object.GetDotDistance
	bool ComplementEqual_StrStr(struct FString A,struct FString B);//Core.Object.ComplementEqual_StrStr
	FVector3 TransformVector(FMatrix TM,FVector3 A);//Core.Object.TransformVector
	bool NotEqual_StrStr(struct FString A,struct FString B);//Core.Object.NotEqual_StrStr
	class UObject* FindObject(struct FString ObjectName,class UClass* ObjectClass);//Core.Object.FindObject
	struct FString Repl(struct FString Src,struct FString Match,struct FString With,bool bCaseSensitive);//Core.Object.Repl
	float Dot_VectorVector(FVector3 A,FVector3 B);//Core.Object.Dot_VectorVector
	double DSin(double A);//Core.Object.DSin
	int GreaterGreater_IntInt(int A,int B);//Core.Object.GreaterGreater_IntInt
	float QuatDot(struct FQuat A,struct FQuat B);//Core.Object.QuatDot
	void PushedState();//Core.Object.PushedState
	void AddToRoot();//Core.Object.AddToRoot
	float Acos(float A);//Core.Object.Acos
	float RandRange(float InMin,float InMax);//Core.Object.RandRange
	void RemoveFromRoot();//Core.Object.RemoveFromRoot
	float Sin(float A);//Core.Object.Sin
	FVector3 Multiply_FloatVector(float A,FVector3 B);//Core.Object.Multiply_FloatVector
	struct FQuat Subtract_QuatQuat(struct FQuat A,struct FQuat B);//Core.Object.Subtract_QuatQuat
	int Divide_IntInt(int A,int B);//Core.Object.Divide_IntInt
	bool SClampRotAxis(float DeltaTime,int ViewAxis,int* out_DeltaViewAxis,int MaxLimit,int MinLimit,float InterpolationSpeed);//Core.Object.SClampRotAxis
	struct FLinearColor ColorToLinearColor(DWORD OldColor);//Core.Object.ColorToLinearColor
	struct FString Caps(struct FString S);//Core.Object.Caps
	float UnwindHeading(float A);//Core.Object.UnwindHeading
	float FClamp(float V,float A,float B);//Core.Object.FClamp
	double Percent_DoubleDouble(double A,double B);//Core.Object.Percent_DoubleDouble
	FVector3 TransformNormal(FMatrix TM,FVector3 A);//Core.Object.TransformNormal
	bool EqualEqual_IntInt(int A,int B);//Core.Object.EqualEqual_IntInt
	bool ComplementEqual_DoubleDouble(double A,double B);//Core.Object.ComplementEqual_DoubleDouble
	void SetGameEpoch(unsigned char eNewEpoch);//Core.Object.SetGameEpoch
	int NormalizeRotAxis(int Angle);//Core.Object.NormalizeRotAxis
	int Rand(int Max);//Core.Object.Rand
	bool NotEqual_DoubleDouble(double A,double B);//Core.Object.NotEqual_DoubleDouble
	bool XorXor_BoolBool(bool A,bool B);//Core.Object.XorXor_BoolBool
	void ContinuedState();//Core.Object.ContinuedState
	FRotator MatrixGetRotator(FMatrix TM);//Core.Object.MatrixGetRotator
	struct FString Locs(struct FString S);//Core.Object.Locs
	struct FQuat Add_QuatQuat(struct FQuat A,struct FQuat B);//Core.Object.Add_QuatQuat
	class UObject* DynamicLoadObject(struct FString ObjectName,class UClass* ObjectClass,bool MayFail);//Core.Object.DynamicLoadObject
	void PoppedState();//Core.Object.PoppedState
	struct FString Split(struct FString Text,struct FString SplitStr,bool bOmitSplitStr);//Core.Object.Split
	bool EqualEqual_FloatFloat(float A,float B);//Core.Object.EqualEqual_FloatFloat
	float Add_FloatFloat(float A,float B);//Core.Object.Add_FloatFloat
	unsigned char MultiplyEqual_ByteByte(unsigned char* A,unsigned char B);//Core.Object.MultiplyEqual_ByteByte
	void JoinArray(TArray<struct FString> StringArray,struct FString* out_Result,struct FString delim,bool bIgnoreBlanks);//Core.Object.JoinArray
	double Subtract_PreDouble(double A);//Core.Object.Subtract_PreDouble
	bool EqualEqual_BoolBool(bool A,bool B);//Core.Object.EqualEqual_BoolBool
	bool IsZero(FVector3 A);//Core.Object.IsZero
	unsigned char AddEqual_ByteByte(unsigned char* A,unsigned char B);//Core.Object.AddEqual_ByteByte
	FMatrix Multiply_MatrixMatrix(FMatrix A,FMatrix B);//Core.Object.Multiply_MatrixMatrix
	bool Greater_StrStr(struct FString A,struct FString B);//Core.Object.Greater_StrStr
	bool OrOr_BoolBool(bool A,bool B);//Core.Object.OrOr_BoolBool
	float VSize2D(FVector3 A);//Core.Object.VSize2D
	float GetRangePctByValue(FVector2 Range,float Value);//Core.Object.GetRangePctByValue
	double DMin(double A,double B);//Core.Object.DMin
	bool LessEqual_DoubleDouble(double A,double B);//Core.Object.LessEqual_DoubleDouble
	FVector3 QuatRotateVector(struct FQuat A,FVector3 B);//Core.Object.QuatRotateVector
	double Add_DoubleDouble(double A,double B);//Core.Object.Add_DoubleDouble
	int InStr(struct FString S,struct FString T,bool bSearchFromRight,bool bIgnoreCase,int StartPos);//Core.Object.InStr
	int SubtractSubtract_Int(int* A);//Core.Object.SubtractSubtract_Int
	float Square(float A);//Core.Object.Square
	bool Less_StrStr(struct FString A,struct FString B);//Core.Object.Less_StrStr
	float VSizeSq2D(FVector3 A);//Core.Object.VSizeSq2D
	struct FString Chr(int I);//Core.Object.Chr
	int Clamp(int V,int A,int B);//Core.Object.Clamp
	void ScriptTrace();//Core.Object.ScriptTrace
	struct FString GetRightMost(struct FString Text);//Core.Object.GetRightMost
	float Divide_FloatFloat(float A,float B);//Core.Object.Divide_FloatFloat
	bool NotEqual_NameName(struct FName A,struct FName B);//Core.Object.NotEqual_NameName
	struct FString Left(struct FString S,int I);//Core.Object.Left
	unsigned char GetGameEpoch();//Core.Object.GetGameEpoch
	bool IsSafeBuild();//Core.Object.IsSafeBuild
};
UClass* UObject::pClassPointer = NULL;

//0x000018 (0x000058 - 0x000040)
//cBulkDataCollection[0x026BCD70]
class UcBulkDataCollection : public UObject
{
public:
	TArray<struct FtOutOfLineBulkData>                 OutOfLineBulkData;                                		// 0x000040 (0x000C)              
	TArray<int>                                        ChunkSizes;                                       		// 0x00004C (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.cBulkDataCollection");
		return pClassPointer;
	};
};
UClass* UcBulkDataCollection::pClassPointer = NULL;

//0x00005C (0x00009C - 0x000040)
//cStatWatchManager[0x026BCEA0]
class UcStatWatchManager : public UObject
{
public:
	unsigned long                                      m_bLogSpikesWithMinutedSummary : 1;               		// 0x000040 (0x0004) [0x00000001] 
	unsigned long                                      m_bSuppressSummaryStats : 1;                      		// 0x000040 (0x0004) [0x00000002] 
	struct Fdword                                      m_nFlagsRaisedThisFrame;                          		// 0x000044 (0x0004)              
	struct FMap_Mirror                                 m_WatchMap;                                       		// 0x000048 (0x003C)              
	TArray<struct FSpikeRecord>                        m_Records;                                        		// 0x000084 (0x000C)              
	TArray<struct FSpikeRecord>                        m_ThisFrameRecords;                               		// 0x000090 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.cStatWatchManager");
		return pClassPointer;
	};

public:
	void LogCurrentRecords();//Core.cStatWatchManager.LogCurrentRecords
	void LogRecord(struct FSpikeRecord theRecord);//Core.cStatWatchManager.LogRecord
};
UClass* UcStatWatchManager::pClassPointer = NULL;

//0x000000 (0x000040 - 0x000040)
//cAPBCoreSDDStructs[0x026BCFD0]
class UcAPBCoreSDDStructs : public UObject
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.cAPBCoreSDDStructs");
		return pClassPointer;
	};
};
UClass* UcAPBCoreSDDStructs::pClassPointer = NULL;

//0x000000 (0x000040 - 0x000040)
//cAPBCoreSDD[0x026BD100]
class UcAPBCoreSDD : public UObject
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.cAPBCoreSDD");
		return pClassPointer;
	};

public:
	unsigned char CastCustomisationMode(int I);//Core.cAPBCoreSDD.CastCustomisationMode
	unsigned char CastDistrictType(int I);//Core.cAPBCoreSDD.CastDistrictType
	unsigned char CastHostingConfigFile(int I);//Core.cAPBCoreSDD.CastHostingConfigFile
	unsigned char CastHostingConfigFileType(int I);//Core.cAPBCoreSDD.CastHostingConfigFileType
	unsigned char CastDesignerConstant2(int I);//Core.cAPBCoreSDD.CastDesignerConstant2
	unsigned char CastGender(int I);//Core.cAPBCoreSDD.CastGender
	unsigned char CastDesignerConstant(int I);//Core.cAPBCoreSDD.CastDesignerConstant
};
UClass* UcAPBCoreSDD::pClassPointer = NULL;

//0x000004 (0x000044 - 0x000040)
//Subsystem[0x026BD490]
class USubsystem : public UObject
{
public:
	DWORD                                              VfTable_FExec;                                    		// 0x000040 (0x0004)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Subsystem");
		return pClassPointer;
	};
};
UClass* USubsystem::pClassPointer = NULL;

//0x000000 (0x000040 - 0x000040)
//Interface[0x026BDE10]
class UInterface : public UObject
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Interface");
		return pClassPointer;
	};
};
UClass* UInterface::pClassPointer = NULL;

//0x000034 (0x000074 - 0x000040)
//Factory[0x026BE1A0]
class UFactory : public UObject
{
public:
	class UClass*                                      SupportedClass;                                   		// 0x000040 (0x0004)              
	class UClass*                                      ContextClass;                                     		// 0x000044 (0x0004)              
	struct FString                                     Description;                                      		// 0x000048 (0x000C)              
	TArray<struct FString>                             Formats;                                          		// 0x000054 (0x000C)              
	unsigned long                                      bCreateNew : 1;                                   		// 0x000060 (0x0004) [0x00000001] 
	unsigned long                                      bEditAfterNew : 1;                                		// 0x000060 (0x0004) [0x00000002] 
	unsigned long                                      bEditorImport : 1;                                		// 0x000060 (0x0004) [0x00000004] 
	unsigned long                                      bText : 1;                                        		// 0x000060 (0x0004) [0x00000008] 
	int                                                AutoPriority;                                     		// 0x000064 (0x0004)              
	TArray<struct FString>                             ValidGameNames;                                   		// 0x000068 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Factory");
		return pClassPointer;
	};
};
UClass* UFactory::pClassPointer = NULL;

//0x00000C (0x00004C - 0x000040)
//Component[0x026BF830]
class UComponent : public UObject
{
public:
	class UClass*                                      TemplateOwnerClass;                               		// 0x000040 (0x0004)              
	struct FName                                       TemplateName;                                     		// 0x000044 (0x0008)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Component");
		return pClassPointer;
	};
};
UClass* UComponent::pClassPointer = NULL;

//0x000008 (0x000054 - 0x00004C)
//DistributionVector[0x026BE8C0]
class UDistributionVector : public UComponent
{
public:
	DWORD                                              VfTable_FCurveEdInterface;                        		// 0x00004C (0x0004)              
	unsigned long                                      bCanBeBaked : 1;                                  		// 0x000050 (0x0004) [0x00000001] 
	unsigned long                                      bIsDirty : 1;                                     		// 0x000050 (0x0004) [0x00000002] 

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.DistributionVector");
		return pClassPointer;
	};
};
UClass* UDistributionVector::pClassPointer = NULL;

//0x000008 (0x000054 - 0x00004C)
//DistributionFloat[0x026BE9F0]
class UDistributionFloat : public UComponent
{
public:
	DWORD                                              VfTable_FCurveEdInterface;                        		// 0x00004C (0x0004)              
	unsigned long                                      bCanBeBaked : 1;                                  		// 0x000050 (0x0004) [0x00000001] 
	unsigned long                                      bIsDirty : 1;                                     		// 0x000050 (0x0004) [0x00000002] 

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.DistributionFloat");
		return pClassPointer;
	};
};
UClass* UDistributionFloat::pClassPointer = NULL;

//0x000040 (0x000080 - 0x000040)
//Commandlet[0x026BE530]
class UCommandlet : public UObject
{
public:
	struct FString                                     HelpDescription;                                  		// 0x000040 (0x000C)              
	struct FString                                     HelpUsage;                                        		// 0x00004C (0x000C)              
	struct FString                                     HelpWebLink;                                      		// 0x000058 (0x000C)              
	TArray<struct FString>                             HelpParamNames;                                   		// 0x000064 (0x000C)              
	TArray<struct FString>                             HelpParamDescriptions;                            		// 0x000070 (0x000C)              
	unsigned long                                      IsServer : 1;                                     		// 0x00007C (0x0004) [0x00000001] 
	unsigned long                                      IsClient : 1;                                     		// 0x00007C (0x0004) [0x00000002] 
	unsigned long                                      IsEditor : 1;                                     		// 0x00007C (0x0004) [0x00000004] 
	unsigned long                                      LogToConsole : 1;                                 		// 0x00007C (0x0004) [0x00000008] 
	unsigned long                                      ShowErrorCount : 1;                               		// 0x00007C (0x0004) [0x00000010] 

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Commandlet");
		return pClassPointer;
	};

public:
	int Main(struct FString Params);//Core.Commandlet.Main
};
UClass* UCommandlet::pClassPointer = NULL;

//0x000000 (0x000080 - 0x000080)
//HelpCommandlet[0x026BE790]
class UHelpCommandlet : public UCommandlet
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.HelpCommandlet");
		return pClassPointer;
	};

public:
	int Main(struct FString Params);//Core.HelpCommandlet.Main
};
UClass* UHelpCommandlet::pClassPointer = NULL;

//0x000024 (0x000064 - 0x000040)
//TextBuffer[0x026BD230]
class UTextBuffer : public UObject
{
public:
	unsigned char                                      _0x000040[0x24];                                  		// 0x000040 (0x0024) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.TextBuffer");
		return pClassPointer;
	};
};
UClass* UTextBuffer::pClassPointer = NULL;

//0x0000F8 (0x00013C - 0x000044)
//System[0x026BD360]
class USystem : public USubsystem
{
public:
	int                                                StaleCacheDays;                                   		// 0x000044 (0x0004)              
	int                                                MaxStaleCacheSize;                                		// 0x000048 (0x0004)              
	int                                                MaxOverallCacheSize;                              		// 0x00004C (0x0004)              
	int                                                PackageSizeSoftLimit;                             		// 0x000050 (0x0004)              
	float                                              AsyncIOBandwidthLimit;                            		// 0x000054 (0x0004)              
	struct FString                                     SavePath;                                         		// 0x000058 (0x000C)              
	struct FString                                     CachePath;                                        		// 0x000064 (0x000C)              
	struct FString                                     CacheExt;                                         		// 0x000070 (0x000C)              
	struct FString                                     ScreenShotPath;                                   		// 0x00007C (0x000C)              
	TArray<struct FString>                             Paths;                                            		// 0x000088 (0x000C)              
	TArray<struct FString>                             SeekFreePCPaths;                                  		// 0x000094 (0x000C)              
	TArray<struct FString>                             StrippedDataPaths;                                		// 0x0000A0 (0x000C)              
	TArray<struct FString>                             ScriptPaths;                                      		// 0x0000AC (0x000C)              
	TArray<struct FString>                             FRScriptPaths;                                    		// 0x0000B8 (0x000C)              
	TArray<struct FString>                             UBScriptPaths;                                    		// 0x0000C4 (0x000C)              
	TArray<struct FString>                             UBUScriptPaths;                                   		// 0x0000D0 (0x000C)              
	TArray<struct FString>                             SBScriptPaths;                                    		// 0x0000DC (0x000C)              
	TArray<struct FString>                             SBUScriptPaths;                                   		// 0x0000E8 (0x000C)              
	TArray<struct FString>                             CutdownPaths;                                     		// 0x0000F4 (0x000C)              
	TArray<struct FName>                               Suppress;                                         		// 0x000100 (0x000C)              
	TArray<struct FString>                             Extensions;                                       		// 0x00010C (0x000C)              
	TArray<struct FString>                             SeekFreePCExtensions;                             		// 0x000118 (0x000C)              
	TArray<struct FString>                             LocalizationPaths;                                		// 0x000124 (0x000C)              
	struct FString                                     TextureFileCacheExtension;                        		// 0x000130 (0x000C)              

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.System");
		return pClassPointer;
	};
};
UClass* USystem::pClassPointer = NULL;

//0x000084 (0x0000C4 - 0x000040)
//PackageMap[0x026BD5C0]
class UPackageMap : public UObject
{
public:
	unsigned char                                      _0x000040[0x84];                                  		// 0x000040 (0x0084) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.PackageMap");
		return pClassPointer;
	};
};
UClass* UPackageMap::pClassPointer = NULL;

//0x00000C (0x00004C - 0x000040)
//ObjectSerializer[0x026BD6F0]
class UObjectSerializer : public UObject
{
public:
	unsigned char                                      _0x000040[0xC];                                   		// 0x000040 (0x000C) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.ObjectSerializer");
		return pClassPointer;
	};
};
UClass* UObjectSerializer::pClassPointer = NULL;

//0x000004 (0x000044 - 0x000040)
//ObjectRedirector[0x026BD820]
class UObjectRedirector : public UObject
{
public:
	unsigned char                                      _0x000040[0x4];                                   		// 0x000040 (0x0004) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.ObjectRedirector");
		return pClassPointer;
	};
};
UClass* UObjectRedirector::pClassPointer = NULL;

//0x000078 (0x0000B8 - 0x000040)
//MetaData[0x026BD950]
class UMetaData : public UObject
{
public:
	unsigned char                                      _0x000040[0x78];                                  		// 0x000040 (0x0078) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.MetaData");
		return pClassPointer;
	};
};
UClass* UMetaData::pClassPointer = NULL;

//0x0001D8 (0x000218 - 0x000040)
//Linker[0x026BDCE0]
class ULinker : public UObject
{
public:
	unsigned char                                      _0x000040[0x1D8];                                 		// 0x000040 (0x01D8) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Linker");
		return pClassPointer;
	};
};
UClass* ULinker::pClassPointer = NULL;

//0x0000B8 (0x0002D0 - 0x000218)
//LinkerSave[0x026BDA80]
class ULinkerSave : public ULinker
{
public:
	unsigned char                                      _0x000218[0xB8];                                  		// 0x000218 (0x00B8) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.LinkerSave");
		return pClassPointer;
	};
};
UClass* ULinkerSave::pClassPointer = NULL;

//0x00047C (0x000694 - 0x000218)
//LinkerLoad[0x026BDBB0]
class ULinkerLoad : public ULinker
{
public:
	unsigned char                                      _0x000218[0x47C];                                 		// 0x000218 (0x047C) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.LinkerLoad");
		return pClassPointer;
	};
};
UClass* ULinkerLoad::pClassPointer = NULL;

//0x0000C4 (0x000104 - 0x000040)
//FieldCollection[0x026BDF40]
class UFieldCollection : public UObject
{
public:
	unsigned char                                      _0x000040[0xC4];                                  		// 0x000040 (0x00C4) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.FieldCollection");
		return pClassPointer;
	};
};
UClass* UFieldCollection::pClassPointer = NULL;

//0x000000 (0x000074 - 0x000074)
//TextBufferFactory[0x026BE070]
class UTextBufferFactory : public UFactory
{
public:

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.TextBufferFactory");
		return pClassPointer;
	};
};
UClass* UTextBufferFactory::pClassPointer = NULL;

//0x000028 (0x000068 - 0x000040)
//Exporter[0x026BE2D0]
class UExporter : public UObject
{
public:
	unsigned char                                      _0x000040[0x4];                                   		// 0x000040 (0x0004) MISSED OFFSET
	TArray<struct FString>                             FormatExtension;                                  		// 0x000044 (0x000C)              
	TArray<struct FString>                             FormatDescription;                                		// 0x000050 (0x000C)              
	unsigned char                                      _0x00005C[0xC];                                   		// 0x00005C (0x000C) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Exporter");
		return pClassPointer;
	};
};
UClass* UExporter::pClassPointer = NULL;

//0x0000C0 (0x000100 - 0x000040)
//Package[0x026BFA90]
class UPackage : public UObject
{
public:
	unsigned char                                      _0x000040[0xC0];                                  		// 0x000040 (0x00C0) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Package");
		return pClassPointer;
	};
};
UClass* UPackage::pClassPointer = NULL;

//0x000078 (0x0000B8 - 0x000040)
//Class[0x026BFBC0]
class UClass : public UObject
{
public:
	unsigned char                                      _0x000040[0x78];                                  		// 0x000040 (0x0078) MISSED OFFSET

private:
	static UClass* pClassPointer;

public:
	static UClass* StaticClass()
	{
		if (!pClassPointer)
			pClassPointer = UObject::FindClass("Class Core.Class");
		return pClassPointer;
	};
};
UClass* UClass::pClassPointer = NULL;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif