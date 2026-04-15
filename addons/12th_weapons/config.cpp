/*
  ==============================================================================
  config.cpp

  This file pulls together all of our weapon, ammo, magazine, and macro configs
  for the 12th MEU custom weapons. It references a series of .hpp files that
  contain definitions for CfgAmmo, CfgMagazines, CfgWeapons, and macros.

  Files included:
    - config_macros.hpp  (Shared macros for attachments, magazines, bipods, etc.)
    - config_ammo.hpp    (Ammo definitions like ballistics, underwater ammo, etc.)
    - config_magazines.hpp (Magazine definitions, capacities, weights, etc.)
    - config_weapons.hpp (Weapon definitions referencing macros, ammo, magazines.)

  Note on Required Addons:
    `requiredAddons[]` must list all addons that our mod depends on to function.
    Make sure you update these when referencing external mods (e.g., ACE, OPTRE).

  ==============================================================================
*/
#include "config_macros.hpp"
#include "config_ammo.hpp"
#include "config_magazines.hpp"
#include "config_weapons.hpp"
#include "model.cfg"
class CfgPatches
{
  class twelfth_weapons
  {
    units[] = {}; // Currently no placeable units are defined by this config.
                  // If you add a placeable object/vehicle that belongs to this mod,
                  // you should list that class name here.
    weapons[] = {
                 "twelfth_M6C", "twelfth_M7_Test", "twelfth_M7_Test_Folded", "twelfth_M90", "twelfth_MA5B",
                 "twelfth_br55", "twelfth_br55_HB",
                 "twelfth_M392", "twelfth_MA37K", "twelfth_Commando",
                 "twelfth_M73H", "twelfth_M33_t", "twelfth_M247", "twelfth_M319",
                 "twelfth_M319N", "twelfth_MA5C", "twelfth_MA5CGL", "twelfth_MA5K", 
                 "twelfth_MAAWS_base","twelfth_MAAWS_olive","twelfth_MAAWS_sand",
				 "twelfth_MA6_K","twelfth_MA6","twelfth_MA6_D","twelfth_MA6_A_BOX","twelfth_MA6_A_DRUM","twelfth_M6C2","twelfth_M6C","twelfth_M6G2","twelfth_MA6_AL"}; // Ensure any newly created weapon class is listed above.
    ammo[] = {"twelfth_20g_bb", "twelfth_95x40_UW", "twelfth_5x23mm_UW", "twelfth_40mmG_HEAT"}; // Please add your new ammo types to this list
    magazines[] = {"twelfth_20g_mag", "twelfth_95x40_100rnd", "twelfth_762x51_200rnd",
                   "twelfth_762x51_200rnd_T", "twelfth_br_36Rnd_UW", "twelfth_m7_60rnd_UW",
                   "twelfth_m7_48rnd_UW", "twelfth_40mm_heat","twelfth_100Rnd_95x40_Box_T","twelfth_56Rnd_95x40_Mag","twelfth_56Rnd_95x40_Mag_T"}; // Add new magazines here.
    requiredVersion = 0.1;
    requiredAddons[] = {"Dmns_Weapons", "OPTRE_Weapons", "Dmns_Weapons_F_MachineGuns",
                        "A3_Weapons_F", "A3_Weapons_F_Exp", "19_UNSC_Weapons", 
                        "ace_common", "a3_weapons_f_tank", "ace_reloadlaunchers",
                        }; 
        /*
        IMPORTANT: If you rely on additional external mods,
        add them here so the game loads them before ours.
      */
  };
  
  //Smoke bouncing fix, I don't know why but this needs to be here in order for the change in config_ammo.hpp line 87 to work
  class ABI_SmokeFix
	{
		units[] = {};
		weapons[] = {};
		author = "Abbi";
		requiredVersion = 0.1;
		requiredAddons[] = { "A3_Weapons_F" };
	};
};

// CBA-Disposable launchers must define two states: the 'ready' version and the 'used' version
class CBA_DisposableLaunchers {
    twelfth_m96_READY[] = {"twelfth_m96", "twelfth_m96_USED"};
};

class CfgMovesBasic {
	class default;
};
class CfgMovesMaleSdr: CfgMovesBasic {
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesMale";
	class StandBase;
	class States {
		class MA6Animation: StandBase {
			file="x\12thMEU\addons\12th_weapons\data\MA6\animations\MA6.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
		class MA6KAnimation: StandBase {
			file="x\12thMEU\addons\12th_weapons\data\MA6_K\animations\MA6_K.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
	};
};