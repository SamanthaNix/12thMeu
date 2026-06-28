#pragma hemtt suppress pw3_padded_arg config
#include "\x\cba\addons\main\script_macros_common.hpp"
#include "config_macros.hpp"

/*
  ==============================================================================
  Overview
  ==============================================================================
  - CfgPatches: Declares this addon (twelfth_backpacks) and the units (backpack
    classes) it provides.
  - CfgVehicles: Defines each custom backpack class. The macros in
    config_macros.hpp generate different variants (light, heavy, RTO, medic)
    for each camo type (e.g., standard, forest).
  - XtdGearModels & XtdGearInfos: Provide extended gear definitions for custom
    UI/Arsenal handling.

  Key Macros:
    - BACKPACK_ALLTYPES(CAMOTYPE, DISPLAY_TYPE) => Creates 5 classes:
         twelfth_backpack_na_<CAMOTYPE>
         twelfth_backpack_light_<CAMOTYPE>
         twelfth_backpack_heavy_<CAMOTYPE>
         twelfth_backpack_rto_<CAMOTYPE>
         twelfth_backpack_medic_<CAMOTYPE>
      Each with different texture setups for the hidden selections.

    - BP_MAXLOAD & BP_MASS => Control the backpack capacity and weight.
  ==============================================================================
*/

class CfgPatches {
  /*
    Base classes from Arma or other mods that we inherit from:
    - B_AssaultPack_Base: The vanilla Arma 3 assault pack base.
    - 19th_Bag_Base: Another modded base class for an alternative RTO backpack.
  */
  class twelfth_backpacks {
    requiredAddons[] = {
    };
    units[] = {  // List of all custom backpack units.
      "twelfth_M3_MAAWS_backpack",
      "twelfth_poncho_wet",
      "twelfth_poncho_dry",

	  // Alternative RTO backpack.
    };
    weapons[] = {};  // No weapons defined.
    requiredVersion = 0.1;  // Minimum required game version.
  };
};

class CfgVehicles {
  class B_AssaultPack_Base;  // Base class for standard backpacks.
  class M3_Backpack_Mcm_B;
  class mgsr_poncho_wet;
  class mgsr_poncho_dry;
  class TCP_equipmentTypes;
  // ---------------------------------------------------------------------------
  //  twelfth_backpack_base
  // ---------------------------------------------------------------------------
  /*
    This serves as a parent class for standard 12th MEU backpacks. 
    All other variants (standard, forest, etc.) inherit from it.
  */
  // Poncho backpack
  class twelfth_poncho_wet:mgsr_poncho_wet{
    maximumLoad = BP_MAXLOAD;
    mass = BP_MASS;
    author = "Sammy";
		scope = 2;
		displayName = "[Twelfth] Poncho (Wet)";
  };

  class twelfth_poncho_dry:mgsr_poncho_dry{
    maximumLoad = BP_MAXLOAD;
    mass = BP_MASS;
    author = "Sammy";
		scope = 2;
		displayName = "[Twelfth] Poncho (Dry)";
  };




  // ---------------------------------------------------------------------------
  //  twelfth_backpack_invis
  // ---------------------------------------------------------------------------
  /*
    An invisible backpack used for special cases (maybe for certain loadouts
    that need a backpack slot but no visible model).
  */
  class twelfth_backpack_invis : B_AssaultPack_Base {
    author = "Waylen";
    scope = 2;
    scopeArsenal = 2;
    picture = "";  // No picture defined.
    displayName = "[12th] Invisible Backpack";
    model = "x\12thMEU\addons\12th_backpacks\backpack\null.p3d";  // Invisible model.
    hiddenSelectionsTextures[] = {"", "", "", ""};  // No textures.
    maximumLoad = BP_MAXLOAD;  // Load capacity macro.
    mass = BP_MASS;  // Backpack mass macro.
    class TransportMagazines {};  // No magazines by default.
    class TransportItems {};  // No items by default.
  };

  class twelfth_M3_MAAWS_backpack: M3_Backpack_Mcm_B {
    author = "Waylen / Sammy";
    scope = 2;
    scopeArsenal = 2;
    picture = "";
    displayName = "[12th] MAAWS Backpack";
    hiddenSelections [] = 
      {
        "Container",
        "Shoulder_straps",
        "Lid_back",
        "Lid_front"
      };
    hiddenSelectionsTextures [] = 
      {
        QP(backpack\maaws\container_co.paa),
        QP(backpack\maaws\straps_co.paa),
        QP(backpack\maaws\lid_back_co.paa),
        QP(backpack\maaws\lid_front_co.paa)
      };
  
      maximumLoad = BP_MAXLOAD;  // Load capacity macro.
      mass = BP_MASS;  // Backpack mass macro.
    };



  //Pouches

  TCP_CLASS_DEF
};

// -----------------------------------------------------------------------------
//  XtdGear Integration
// -----------------------------------------------------------------------------
/*
  The "XtdGearModels" and "XtdGearInfos" classes let you define custom UI 
  or arsenal categories for these backpacks if you have an extended gear mod 
  supporting them (like XtdGear).
*/
class XtdGearModels {
  class CfgVehicles{
    /*
      The ALL_GI(CAMO) macro calls BACKPACK_GI(CAMO, TYPE) for each type
      (light, na, heavy, medic, rto). This means the extended gear system
      sees each variant (e.g., twelfth_backpack_light_standard) with 
      model="twelfth_backpacks", camo="standard", type="light", etc.
    */
    class twelfth_backpacks {
      label = "12th Backpacks";
      options[] = {"camo", "type"};
      class camo {
        alwaysSelectable = 1;
        label = "Camoflauge";
        values[] = {"standard", "forest", "desert"};
        class forest {label = "Standard"; image = XTP(forest);};
        class standard {label = "MARPAT"; image = XTP(std);};
		    class desert {label = "Desert"; image = XTP(desert);};
      };
      class type {
        alwaysSelectable = 1;
        label = "Variant";
        values [] = {"na", "light", "heavy", "medic", "rto"};
        class na {label = "N/A";};
        class light {label = "Light";};
        class heavy {label = "Heavy";};
        class medic {label = "Corpsman";};
        class rto {label = "RTO";};
      };
    };

    class twelfth_Pouches {
      label = "12th Pouches";
      options[] = {"role", "variant","backpack","pack","addon"};
      class role {
        alwaysSelectable = 1;
        label = "Role";
        values[] = {"Ammo_Bearer","Autorifleman", "Assaulter", "Breacher","Engineer","Grenadier","Marksman","Medic","NCO","Rifleman","RTO","Sapper","Sniper"};
        class Ammo_Bearer {label = "Ammo Bearer";};
        class Assaulter {label = "Assaulter";};
        class Autorifleman {label = "Autorifleman";};
		    class Breacher {label = "Breacher";};
        class Engineer{label = "Engineer";};
        class Grenadier{label = "Grenadier";};
        class Marksman{label = "Marksman";};
        class Medic{label = "Medic";};
        class NCO{label = "NCO";};
        class Rifleman{label = "Rifleman";};
        class RTO{label = "RTO";};
        class Sapper{label = "Sapper";};
        class Sniper{label = "Sniper";};
      };
      class Variant {
        alwaysSelectable = 1;
        label = "Variant";
        values [] = {"1", "2", "3", "4", "5","6","7"};
        class 1 {label = "1";};
        class 2 {label = "2";};
        class 3 {label = "3";};
        class 4 {label = "4";};
        class 5 {label = "5";};
        class 6 {label = "6";};
        class 7 {label = "7";};
      };
      class backpack {
        alwaysSelectable = 1;
        label = "Backpack Type";
        values [] = {"NO", "ANPRC171", "EM39_MLBE_Hardcase", "M43_Medium_Rucksack"};
        class NO {label = "None";};
        class ANPRC171 {label = "ANPRC171";};
        class EM39_MLBE_Hardcase {label = "EM39";};
        class M43_Medium_Rucksack {label = "M43";};
      };
      class Pack {
        alwaysSelectable = 1;
        label = "Pack Type";
        values [] = {"NO", "EM39_Buttpack", "M2_Buttpack", "M35_Buttpack","Roll"};
        class NO {label = "None";};
        class EM39_Buttpack {label = "EM39 Pack";};
        class M2_Buttpack {label = "M2 Pack";};
        class M35_Buttpack {label = "M35 Pack";};
        class Roll {label = "Roll";};
      };
      class Addon {
        alwaysSelectable = 1;
        label = "Addons";
        values [] = {"NO", "Assault", "Engineer", "Field","Medical","Patrol"};
        class NO {label = "None";};
        class Assault {label = "Assault";};
        class Engineer {label = "Engineer";};
        class Field {label = "Field";};
        class Medical {label = "Medical";};
        class Patrol {label = "Patrol";};
      };
    };
  };
};

class XtdGearInfos {
  class CfgVehicles {
    ALL_GI(standard)
    ALL_GI(forest)
	  ALL_GI(desert)
    POUCH_GI
  };
};