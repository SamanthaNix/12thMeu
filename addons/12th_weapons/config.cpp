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
#include "config_ammo.hpp"
#include "config_macros.hpp"
#include "config_magazineGroups.hpp"
#include "config_weapons.hpp"
#include "model.cfg"
#include "XtdGear.hpp"
class CfgPatches
{
  class twelfth_weapons
  {
    units[] = {}; // If you add a placeable object/vehicle that belongs to this mod,
                  // you should list that class name here.
    weapons[] = {
				         "twelfth_MA6_K","twelfth_MA6","twelfth_MA6_D","twelfth_MA6_A_BOX","twelfth_MA6_A_DRUM","twelfth_MA6_AL","avm224_W_M224_mortar_proxy","NDS_W_M224_mortar","twelfth_MAAWS_base","twelfth_MAAWS_olive","twelfth_MAAWS_sand",
                 }; // Ensure any newly created weapon class is listed above.
    ammo[] = {"F_HuntIR_mortar","twelfth_W_B250","twelfth_W_B500"}; // Please add your new ammo types to this list
    magazines[] = {"twelfth_M_1Rnd_60mm_HUNTIR_csw", "twelfth_M_6Rnd_60mm_HUNTIR","twelfth_W_P_GBU_prototype_250x1","twelfth_W_P_GBU_prototype_250x2","twelfth_W_P_GBU_prototype_250x4",
                    "twelfth_W_P_GBU_prototype_500x1","twelfth_W_P_GBU_prototype_500x2",
                    "twelfth_pylonrack_aim120x1","twelfth_pylonrack_aim120x2",
                    "twelfth_pylonrack_aim132x1","twelfth_pylonrack_aim132x2",
                    "twelfth_pylonrack_AGM65Dx1","twelfth_pylonrack_AGM65Dx3",
                    "twelfth_pylonrack_AGM65Gx1","twelfth_pylonrack_AGM65Gx3",
                    "twelfth_pylonrack_AGM65Lx1","twelfth_pylonrack_AGM65Lx3",
                    "twelfth_pylonrack_AGM88Cx1",
                    "twelfth_pylonrack_AGM114Kx1","twelfth_pylonrack_AGM114Kx3","twelfth_pylonrack_AGM114Kx4",
                    "twelfth_pylonrack_AGM114Lx1","twelfth_pylonrack_AGM114Lx3","twelfth_pylonrack_AGM114Lx4",
                    "twelfth_pylonrack_AGM114Nx1","twelfth_pylonrack_AGM114Nx3","twelfth_pylonrack_AGM114Nx4",
                    "twelfth_pylonrack_AGM502x1","twelfth_pylonrack_AGM502x2","twelfth_pylonrack_AGM502x3","twelfth_pylonrack_AGM502x4",
                    "twelfth_pylonrack_AGM90Bx1","twelfth_pylonrack_AGM90Bx2","twelfth_pylonrack_AGM90Bx4","twelfth_pylonrack_AGM90Bx8","twelfth_56Rnd_95x40_Mag","twelfth_56Rnd_95x40_Mag_T"}; // Add new magazines here.
    requiredVersion = 0.1;
    requiredAddons[] = { "OPTRE_Weapons",
                        "A3_Weapons_F", "A3_Weapons_F_Exp", 
                        "ace_missileguidance","ace_common", "a3_weapons_f_tank", "ace_reloadlaunchers","NDS_M224_mortar","avm224_mortar","ace_csw","ace_apl","ace_huntir",
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

class CfgMovesBasic;
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
    class MA6_UGL_Animation: StandBase {
			file="x\12thMEU\addons\12th_weapons\data\MA6_UGL\Ma_6_UGL.rtm";
			looped=1;
			speed=1;
			mask = "bodyFullReal";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
	};
};
