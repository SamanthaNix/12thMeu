#define _ARMA_
#include "basicDefines_A3.hpp"


class CfgPatches
{
	class SMT_Custom_Weapons
	{
		units[] = {};
		weapons[] = {"PrototypeLaser_01_F","PrototypeOptics","twelfth_G82","twelfth_G82_sight","srifle_XR704","XR704_Scope"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F"};
		magazines[] = {"3Rnd_test_mag","twelfth_G82_35Rnd_Mag", "twelfth_G82_35Rnd_Mag_T","408CT_6Rnd_Mag_T","408CT_6Rnd_Mag"};
		ammo[] = {"StandardLiquidLaserAmmo"};
	};
};


class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class BaseSoundModeType;

#include "cfgRecoils.hpp" /// specific recoil patterns for this rifle
#include "cfgMagazines.hpp" /// specific magazines for this rifle
#include "cfgAmmo.hpp" /// specific ammo for this rifle
#include "cfgSoundShaders.hpp" // SoundShaders
#include "cfgSoundSets.hpp" // SoundSets
#include "model.cfg"


class CfgMagazineWells
{
	class LiquidMag
	{
		SMT_Magazines[] =
		{
			"LLRLaserMag",
			"CompressedLaserMag"
		};
	};
	class G82mag {
		SMT_Magazines[] =
		{
			"twelfth_G82_35Rnd_Mag", "twelfth_G82_35Rnd_Mag_T"
		};
	};
	class XR704mag{
		SMT_Magazines[]=
		{
			"408CT_6Rnd_Mag_T","408CT_6Rnd_Mag"
		};
	};
};

class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class PrototypeLaser_01_Base_F: Rifle_Base_F
	{
		editorCategory ="12th_Assets";
		handAnim[] = {"OFP2_ManSkeleton","\x\12thMEU\addons\custom_weapons\data\animations\llr.rtm"};
		mass=180;
		/////////////////////ACE STUFF//////////////////////////////
		ace_overheating_barrelMass = 20;
		ACE_barrelLength = 800;
		ACE_barrelTwist = 229;
        ACE_twistDirection = 1;
		/////////////////////ACE STUFF//////////////////////////////
		magazines[] = {"3Rnd_test_mag"};
		magazineWell[] = { "LiquidMag" };
		reloadAction = "GestureReloadMX";
		magazineReloadSwitchPhase = 0.4;
		discreteDistanceInitIndex = 0;
		picture="\x\12thMEU\addons\Custom_Weapons\data\PrototypeLaserPreview.paa";
		maxRecoilSway = 0.0025;
		swayDecaySpeed = 5;
		inertia = 0.8;
		initSpeed = -1;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName = "Nabojnicestart";
				directionName = "Nabojniceend";
				effectName = "CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot{};
			class CowsSlot: CowsSlot
			{
				displayName = "$STR_A3_CowsSlot0";
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[] = {"PrototypeOptics","PrototypeOpticsV2"};
				iconPosition[] = {0.5,0.35};
				iconScale = 0.2;
			};
			class PointerSlot : PointerSlot 
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot: UnderBarrelSlot 
			{
				compatibleItems[] = {};
			};
			
		};
		caseless[] = {"",1,1,1};
		soundBullet[] = {"caseless",1};
		selectionFireAnim = "muzzleFlash";
		modes[] = {"Single", "single_medium_optics1", "single_far_optics2"};
			class Single: Mode_SemiAuto /// Pew
			{
				
				sounds[] = {"StandardSound","SilencedSound"};
				class BaseSoundModType {};
				class StandardSound : BaseSoundModType
				{
					// array of sounds (SoundSet names) to be played at the game event (shot)
					// number of SoundSets in array is not limited
					// consider that several ms lag could appear between each SoundSet is played
					// closure (bolt action) sound definition should be part of SoundSet
					soundSetShot[] =
					{
						"PrototypeLaser_01_Base_F_Shot_SoundSet"
					};
				};
				class SilencedSound : BaseSoundModType
				{
					// array of sounds (SoundSet names) to be played at the game event (shot)
					// number of SoundSets in array is not limited
					// consider that several ms lag could appear between each SoundSet is played
					// closure (bolt action) sound definition should be part of SoundSet
					soundSetShot[] =
					{
						"PrototypeLaser_01_Base_F_Shot_SoundSet"
					};
				};
				showtoplayer=1;
				reloadTime = 5; /// timebetween bullets
				dispersion = 0.00001; /// accuracy


				recoil = "recoil_single_Test_rifle_01"; /// defined in cfgRecoils
				recoilProne = "recoil_single_prone_Test_rifle_01"; /// defined in cfgRecoils

				minRange = 2; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
				midRange = 200; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
				maxRange = 1000; maxRangeProbab = 0.3; 	/// probability of the weapon, does some calculation and compares it with calculated probability of other weapons
			};

    //////////////////////////////////////////////////// OPTICS //////////////////////////////////////////////////

		class single_medium_optics1: Single /// Pew for AI with collimator sights
			{
				requiredOpticType = 0;
				showToPlayer = 0;

				minRange = 2; minRangeProbab = 0.2;
				midRange = 450; midRangeProbab = 0.7;
				maxRange = 600; maxRangeProbab = 0.2;

				aiRateOfFire = 20;
				aiRateOfFireDistance = 600;
			};

		class single_far_optics2: single_medium_optics1	/// Pew for AI with better sights
		{
			requiredOpticType = 1;
			showToPlayer = 0;

			minRange = 100; minRangeProbab = 0.1;
			midRange = 700; midRangeProbab = 0.6;
			maxRange = 1000; maxRangeProbab = 0.05;

			aiRateOfFire = 20;
			aiRateOfFireDistance = 700;
		};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};


	class PrototypeLaser_01_F: PrototypeLaser_01_Base_F
	{
		scope = 2;
		displayName = "[12th] Prototype LLR";
		descriptionShort = "A high powered, slow firerate weapon meant for cracking medium targets.";
		model = "\x\12thMEU\addons\Custom_Weapons\data\PrototypeLaser.p3d";
		UiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
		weaponInfoType = "RscWeaponZeroing";
		muzzles[] = {"this"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
		};
	};


	class OPTRE_Commando;
	class WeaponSlotsInfo;
	class UGL_F;
	class twelfth_G82: OPTRE_Commando {
		model="x\12thMEU\addons\custom_weapons\G82\G82.p3d";
		author = "Rex";
		scope = 2;
		scopeArsenal = 2;
		displayName = "[12th] G82";
		baseWeapon = "twelfth_G82";
		canShootInWater = 1;
		magazineWell[] = { "G82mag" };
		magazines[] = {"G82_35Rnd_Mag", "G82_35Rnd_Mag_T"};
		ace_overheating_barrelMass = 5;
		muzzles[] = {"this", "Test_GL_F"};
		picture="\x\12thMEU\addons\custom_weapons\G82\data\g82_preview.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\12thMEU\addons\custom_weapons\G82\data\G82.rtm"};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class CowsSlot : CowsSlot
          {
            compatibleitems[] = {"twelfth_G82_sight"};
          };
		}; 
		class LinkedItems {
			class LinkedItemsCows {
				item = "twelfth_G82_sight";
				slot = "CowsSlot";
			};
		};

		class Test_GL_F: UGL_F /// Some grenade launcher to have some more fun
		{
			displayName = "G82 Grenade Launcher";
			descriptionShort = "G82-GL";
			useModelOptics = false;
			useExternalOptic = false; /// Doesn't use optics from the attachment, has it's own
			magazines[] = {"1Rnd_HE_Grenade_shell"};
			cameraDir = "OP_look";
			discreteDistance[] = {100, 200, 300, 400};
			discreteDistanceCameraPoint[] = {"OP_eye", "OP_eye2", "OP_eye3", "OP_eye4"}; /// the angle of gun changes with zeroing
			discreteDistanceInitIndex = 1; /// 200 is the default zero
		};
	}; 



	
	class LRR_base_F;
	class srifle_XR704 : LRR_base_F{
		model="x\12thMEU\addons\custom_weapons\XR-704\XR_704.p3d";
		author = "Sammy";
		scope = 2;
		scopeArsenal = 2;
		mass=250;
		/////////////////////ACE STUFF//////////////////////////////
		ace_overheating_barrelMass = 5;
		ACE_barrelLength = 800;
		ACE_barrelTwist = 229;
        ACE_twistDirection = 1;
		/////////////////////ACE STUFF//////////////////////////////
		displayName = "XR-704";
		baseWeapon = "srifle_XR704";
		canShootInWater = 1;
		magazineWell[] = { "XR704mag" };
		magazines[] = {"408CT_6Rnd_Mag", "408CT_6Rnd_Mag_T"};
		muzzles[] = {"this"};
		picture="\x\12thMEU\addons\custom_weapons\XR-704\data\preview.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\12thMEU\addons\custom_weapons\XR-704\data\XR-704.rtm"};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class CowsSlot : CowsSlot
          	{
            compatibleitems[] += {"XR704_Scope"};
          	};
			class UnderBarrelSlot: UnderBarrelSlot 
			{
				compatibleItems[] = {"bipod_03_F_blk","bipod_02_F_blk","bipod_01_F_blk","bipod_02_F_hex","bipod_01_F_mtp","bipod_03_F_oil","bipod_01_F_snd","bipod_02_F_tan"};
			};
		}; 
		class LinkedItems {
			class LinkedItemsCows {
				item = "XR704_Scope";
				slot = "CowsSlot";
			};
		};
	};




	/// include accessory from separate file to not clutter this one
	#include "accessory.hpp"
};
class CfgMovesBasic {
	class default;
};
class CfgMovesMaleSdr: CfgMovesBasic {
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesMale";
	class StandBase;
	class States {
		class LLRGunHoldAnim: StandBase {
			file="\x\12thMEU\addons\custom_weapons\data\animations\llr.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
		class G82GunHoldAnim: StandBase {
			file="\x\12thMEU\addons\custom_weapons\G82\data\G82.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
		class XR704GunHoldAnim: StandBase {
			file="\x\12thMEU\addons\custom_weapons\XR-704\data\XR-704.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
	};
};

