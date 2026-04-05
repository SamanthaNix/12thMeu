class CfgSoundSets
{
	class PrototypeLaser_01_Base_F_Shot_SoundSet
	{
		soundShaders[] = {"PrototypeLaser_01_Base_F_Closure_SoundShader", "PrototypeLaser_01_Base_F_closeShot_SoundShader","PrototypeLaser_01_Base_F_midShot_SoundShader","PrototypeLaser_01_Base_F_distShot_SoundShader" };
		volumeFactor = 1.6;
		sound3DProcessingType = "Emitter";
		distanceFilter = "none";
		spatial = true;
		doppler = false;
		loop = false;
	};
/* 	class PrototypeLaser_01_Base_F_Tail_SoundSet
	{
		soundShaders[] = { "PrototypeLaser_01_Base_F_tailTrees_SoundShader", "PrototypeLaser_01_Base_F_tailForest_SoundShader", "PrototypeLaser_01_Base_F_tailMeadows_SoundShader", "PrototypeLaser_01_Base_F_tailHouses_SoundShader" };
		volumeFactor = 1;
		volumeCurve = "InverseSquare2Curve";
		frequencyRandomizer = 1;
		sound3DProcessingType = "WeaponMediumShotTail3DProcessingType";
		distanceFilter = "weaponShotTailDistanceFreqAttenuationFilter";
		spatial = 1;
		doppler = 0;
		loop = 0;
		soundShadersLimit = 2;
	};*/
}; 
