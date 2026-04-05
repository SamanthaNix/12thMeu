#define _ARMA_
#include "basicDefines_A3.hpp"


class CfgPatches
{
	class PrototypeLaser_F
	{
		units[] = {};
		weapons[] = {"PrototypeLaser_01_F","PrototypeOptics"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F"};
		magazines[] = {"3Rnd_test_mag"};
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
		mass=90;
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
	};
};
