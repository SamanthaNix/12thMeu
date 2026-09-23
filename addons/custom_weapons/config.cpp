#define _ARMA_
#include "basicDefines_A3.hpp"


class CfgPatches
{
	class SMT_Custom_Weapons
	{
		units[] = {};
		weapons[] = {"SMT_PrototypeLaser_01_F","SMT_PrototypeOptics","SMT_G82","SMT_G82_sight","SMT_srifle_XR704","SMT_XR704_Scope","SMT_XR_Holo","SMT_SMG_XR121"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F"};
		magazines[] = {"3Rnd_test_mag","SMT_G82_35Rnd_Mag", "SMT_G82_35Rnd_Mag_T","408CT_6Rnd_Mag_T","408CT_6Rnd_Mag","SMT_65x55_60rnd_Mag","SMT_65x55_60rnd_T_Mag","SMT_65x55_90rnd_Mag","SMT_65x55_90rnd_T_Mag"};
		ammo[] = {"StandardLiquidLaserAmmo","CompressedLiquidLaserAmmo","B_65x55_green","B_408_CheyTac"};
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
			"SMT_LLRLaserMag",
			"SMT_CompressedLaserMag"
		};
	};
	class G82mag {
		SMT_Magazines[] =
		{
			"SMT_G82_35Rnd_Mag", "SMT_G82_35Rnd_Mag_T"
		};
	};
	class XR704mag{
		SMT_Magazines[]=
		{
			"SMT_408CT_6Rnd_Mag_T","SMT_408CT_6Rnd_Mag"
		};
	};
	class XR121_mag{
		SMT_Magazines[]=
		{
			"SMT_65x55_60rnd_Mag","SMT_65x55_60rnd_T_Mag","SMT_65x55_90rnd_Mag","SMT_65x55_90rnd_T_Mag"
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


	class SMT_PrototypeLaser_01_F: PrototypeLaser_01_Base_F
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

//////////////////G82////////////////////
	class SMT_G82: OPTRE_Commando {
		model="x\12thMEU\addons\custom_weapons\G82\G82.p3d";
		author = "Rex";
		scope = 2;
		scopeArsenal = 2;
		displayName = "G82";
		baseWeapon = "SMT_G82";
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
            compatibleitems[] = {"SMT_G82_sight"};
          };
		}; 
		class LinkedItems {
			class LinkedItemsCows {
				item = "SMT_G82_sight";
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
/////////////////////XR-704/////////////////////
	class LRR_base_F;
	class SMT_srifle_XR704 : LRR_base_F{
		model="x\12thMEU\addons\custom_weapons\XR-704\XR_704.p3d";
		author = "Sammy";
		scope = 2;
		scopeArsenal = 2;
		mass=250;
		/////////////////////ACE STUFF//////////////////////////////
		ace_overheating_barrelMass = 5;
		ACE_barrelLength = 800;
		ACE_barrelTwist = 330.2;
        ACE_twistDirection = 1;
		/////////////////////ACE STUFF//////////////////////////////
		displayName = "XR-704";
		baseWeapon = "SMT_srifle_XR704";
		canShootInWater = 1;
		magazineWell[] = { "XR704mag" };
		magazines[] = {"SMT_408CT_6Rnd_Mag", "SMT_408CT_6Rnd_Mag_T"};
		muzzles[] = {"this"};
		picture="\x\12thMEU\addons\custom_weapons\XR-704\data\preview.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\12thMEU\addons\custom_weapons\XR-704\data\XR-704.rtm"};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class CowsSlot : CowsSlot
          	{
            compatibleitems[] += {"SMT_XR704_Scope"};
          	};
			class UnderBarrelSlot: UnderBarrelSlot 
			{
				compatibleItems[] = {"bipod_03_F_blk","bipod_02_F_blk","bipod_01_F_blk","bipod_02_F_hex","bipod_01_F_mtp","bipod_03_F_oil","bipod_01_F_snd","bipod_02_F_tan"};
			};
			class PointerSlot : PointerSlot 
			{
				compatibleItems[] = {};
			};
		}; 
		class LinkedItems {
			class LinkedItemsCows {
				item = "SMT_XR704_Scope";
				slot = "CowsSlot";
			};
		};
	};
/////////////////////XR-121/////////////////////
	class fullauto_medium;
	class FullAuto;
	class arifle_MX_F;
	class SMT_SMG_XR121 : arifle_MX_F{
		model="x\12thMEU\addons\custom_weapons\XR-121\XR_121.p3d";
		author = "Sammy";
		scope = 2;
		scopeArsenal = 2;
		displayName = "XR-121";
		baseWeapon = "smg_XR121";
		canShootInWater = 1;
		muzzles[] = {"this"};
		picture="\x\12thMEU\addons\custom_weapons\XR-121\data\preview.paa";
		mass=180;
		//Ace stuff
		ace_overheating_barrelMass = 2;
		ACE_barrelLength = 440;
		ACE_barrelTwist = 220;
        ACE_twistDirection = 1;
		ace_overheating_closedBolt=0;

		//Magazine
		magazines[] = {"SMT_65x55_60rnd_T_Mag"};
		magazineWell[] = { "XR121_mag" };

		//Flashlight
		class FlashLight
        {
            ambient[] = {0.9,0.81,0.7};
            color[] = {180,160,130};
            coneFadeCoef = 8;
            dayLight = 0;
            direction = "flash";
            flareMaxDistance = 100;
            flareSize = 1.4;
            innerAngle = 5;
            intensity = 100;
            outerAngle = 100;
            position = "flash dir";
            scale[] = {1,1,1};
            size = 1;
            useFlare = 1;
            volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";

            class Attenuation
            {
                constant = 0.5;
                hardLimitEnd = 40;
                hardLimitStart = 32;
                linear = 0.1;
                quadratic = 0.2;
                start = 0;
            };
        };


		handAnim[] = {"OFP2_ManSkeleton","\x\12thMEU\addons\custom_weapons\XR-121\data\XR-121.rtm"};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			class CowsSlot : CowsSlot
          	{
            compatibleitems[] += {"SMT_XR_Holo","optic_arco_ak_blk_f", "optic_dms", "optic_aco_grn", "optic_aco", "optic_arco_blk_f", "optic_holosight_blk_f", "optic_mrco", "optic_khs_blk", "optic_hamr", "optic_sos", "optic_nightstalker", "optic_erco_blk_f", "optic_yorris", "optic_aco_smg", "optic_aco_grn_smg", "optic_holosight_smg_blk_f", "optic_mrd_black", "ace_optic_arco_2d", "ace_optic_arco_pip", "ace_optic_lrps_pip", "ace_optic_sos_2d", "ace_optic_sos_pip", "ace_optic_mrco_2d", "ace_optic_hamr_2d", "ace_optic_hamr_pip", "OPTRE_M7_Sight", "OPTRE_M12_Optic", "OPTRE_M12_Optic_Red", "OPTRE_M12_Optic_Green", "Optre_Recon_Sight", "Optre_Recon_Sight_Red", "Optre_Recon_Sight_Green", "Optre_Recon_Sight_Desert", "Optre_Recon_Sight_UNSC", "Optre_Recon_Sight_Snow", "OPTRE_BR45_Scope", "OPTRE_BR55HB_Scope", "OPTRE_BR55HB_Scope_Grey", "OPTRE_BMR_Scope", "OPTRE_M392_Scope", "OPTRE_M393_Scope", "OPTRE_M393_ACOG", "OPTRE_M393_EOTECH", "OPTRE_SRM_Sight", "OPTRE_MA5_BUIS","TCP_optic_M11VERO_Blue","TCP_optic_M11VERO","TCP_optic_M27RCO","TCP_optic_M43RCO","TCP_optic_M27RCO_CRS","TCP_optic_M27RCO_CRS_CUP","TCP_optic_M27RCO_CUP","TCP_optic_M5BSLSV_Blue","TCP_optic_M5BSLSV","TCP_optic_M81ERO_Blue","TCP_optic_M81ERO","TCP_optic_M43RCO_CRS","TCP_optic_M43RCO_CRS_CUP","TCP_optic_M43RCO_CUP","twelfth_m43rco","twelfth_m43rco_crs","twelfth_m43rco_crs_cup","twelfth_m43rco_cup"};
          	};
			class UnderBarrelSlot: UnderBarrelSlot 
			{
				compatibleItems[] = {""};
			};
			class PointerSlot : PointerSlot 
			{
				compatibleItems[] = {"TCP_acc_flashlight_M6G","TCP_acc_pointer_lam_M6G","TCP_acc_pointer_lam_M6C2"	,"OPTRE_BMR_Vis_Red_Laser", "ACE_acc_pointer_red", "ACE_acc_pointer_green", "ACE_acc_pointer_green_IR", "acc_pointer_IR", "OPTRE_M12_Laser","OPTRE_M12_Flashlight","OPTRE_M12_Vis_Red_Laser","ACE_SPIR","ACE_SPIR_Medium","ACE_SPIR_Narrow","ACE_SPIR_LR","ACE_SPIR_LR_Medium","ACE_SPIR_LR_Narrow","acc_flashlight","acc_flashlightMax","ACE_DBAL_A3_Green","ACE_DBAL_A3_Green_II","ACE_DBAL_A3_Green_IP","ACE_DBAL_A3_GreenLR","ACE_DBAL_A3_Green_LR","ACE_DBAL_A3_Green_LR_II","ACE_DBAL_A3_Green_LR_IP","ACE_DBAL_A3_Green_LR_VP","ACE_DBAL_A3_Green_VP","ACE_DBAL_A3_Red","ACE_DBAL_A3_Red_II","ACE_DBAL_A3_Red_IP","ACE_DBAL_A3_RedLR","ACE_DBAL_A3_Red_LR","ACE_DBAL_A3_Red_LR_II","ACE_DBAL_A3_Red_LR_IP","ACE_DBAL_A3_Red_LR_VP","ACE_DBAL_A3_Red_VP"};
			};
		};
		modes[] = {"Single","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2","ACE_Burst_far","FullestAuto","FullestAuto_Close_Optics"};
		class FullAuto:FullAuto{
			showtoplayer=1;
			reloadTime = 0.08;
		};
		class fullauto_medium:fullauto_medium{
			reloadTime = 0.08;
		};
		class FullestAuto:FullAuto{
			showtoplayer=1;
			reloadTime = 0.04;
			textureType = "fastAuto";
		};
		class FullestAuto_Close_Optics:fullauto_medium{
			reloadTime = 0.04;
		};
	};


	/// include accessory from separate file to not clutter this one
	#include "accessory.hpp"
};
class CfgMovesBasic {
	class Default;
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
		class XR121GunHoldAnim: StandBase {
			file="\x\12thMEU\addons\custom_weapons\XR-121\data\XR-121.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
	};
};

/* class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
			class ACE_Equipment {
				class greenOptic {
					displayName = "Change optic colour to Green";
					exceptions[] = {};
					statement = "_this setObjectTexture ["Optics", #(rgb,1,1,3)color(0,1,0,1)];";
				};
				class RedOptic {
					displayName = "Change optic colour to Red";
					exceptions[] = {};
					statement = "_this setObjectTexture ["Optics", #(rgb,1,1,1)color(1,0,0,1)];";
				};
			};
		};
    };
}; */