/*
  ==============================================================================
  config.cpp

  This file configures our custom vests, referencing macros and selection sets
  defined in "config_macros.hpp" and "unscf_vest_sel.hpp". It includes:
    - CfgPatches (describing what's included in this addon).
    - CfgVehicles (to define supply containers or special vest containers).
    - CfgWeapons (to define the vests themselves).

  Notable Macros:
    - VEST_MAXLOAD: sets the maximum carrying capacity for the containerClass.
    - UNSCF_VEST_ALL_VARIANTS(): expands into multiple vest classes for each
      camo variant (e.g., standard or winter).
  ==============================================================================
*/

// This directive suppresses specific Hemtt warnings related to padded arguments in the configuration file.
#pragma hemtt suppress pw3_padded_arg config

// Includes the macros used below (e.g., VEST_MAXLOAD, etc.)
#include "config_macros.hpp"


// -----------------------------------------------------------------------------
//  CfgPatches
// -----------------------------------------------------------------------------
class CfgPatches {
  class twelfth_vests {
    units[]= {}; // We’re not defining placeable units in this PBO.
    weapons[]= { 
      "twelfth_invis_vest"
        /*
          If you create more vests that are stand-alone (not just variants),
          add them here so the engine recognizes them as part of this mod.
        */
    };
    requiredAddons[] = {"TCP_Characters"};
    requiredVersion=0.1;
  };
};

// -----------------------------------------------------------------------------
//  CfgVehicles
// -----------------------------------------------------------------------------
class CfgVehicles {
  /*
    We'll create a supply container class that references a macro
    for max load. This containerClass is used by the vests to determine
    how much gear can be carried.
  */
  class ContainerSupply; // Pre-declaration: inherits from a base ArmA class.
  class twelfth_vest_supply : ContainerSupply {
    maximumLoad=200;
    /*
      The VEST_MAXLOAD macro is defined in config_macros.hpp. 
      This sets how many "units" of gear can fit inside the vest container.
    */
  };
};

// -----------------------------------------------------------------------------
//  CfgWeapons (Primary location for vest definitions)
// -----------------------------------------------------------------------------
class CfgWeapons
{
  class ItemCore;
  class VestItem;
  class OPTRE_UNSC_M52A_Armor2_MAR;
  class mgsr_poncho_wet_vest;
  class mgsr_poncho_dry_vest;
  class TCP_V_M43D_ODST_4_Black;

  // Ponchos

  class twelft_poncho_dry_vest: mgsr_poncho_dry_vest{
    author = "Sammy";
		scope = 2;
    model="\mgsr_poncho\mgsr_poncho.p3d";
		displayName = "[12th] Poncho (Dry)";
		class ItemInfo: VestItem
		{
      uniformModel = "\mgsr_poncho\mgsr_poncho.p3d";
      containerClass="twelfth_vest_supply";
      mass = 80;
       class HitpointsProtectionInfo {
        class Neck {
          hitpointName="HitNeck";
          armor=20; 
          passThrough=0.30000001;
        };
        class Arms {
          hitpointName="HitArms";
          armor=10; 
          passThrough=0.60000002;
        };
        class Chest {
          hitpointName="HitChest";
          armor=20; 
          passThrough=0.30000001;
        };
        class Diaphragm {        
          hitpointName="HitDiaphragm";
          armor=20; 
          passThrough=0.30000001;
        };
        class Abdomen {
          hitpointName="HitAbdomen";
          armor=20; 
          passThrough=0.30000001;
        };
        class Body {
          hitpointName="HitBody";
          passThrough=0.30000001;
          armor=20; 
        };
        class Legs {
          hitpointName="HitLegs";
          armor=10;
          passThrough=0.60000002;
        };
      }; 
      setMaxLoad=200;
      hiddenSelections[] = {"camo"};
			hiddenSelectionsTextures[] = {"\mgsr_poncho\data\mgsr_poncho.paa"};
			hiddenSelectionsMaterials[] = {"\mgsr_poncho\data\mgsr_poncho_dry.rvmat"};
		};
  };
  
  class twelft_poncho_wet_vest: mgsr_poncho_wet_vest{
    author = "Sammy";
		scope = 2;
		displayName = "[12th] Poncho (Wet)";
    model="\mgsr_poncho\mgsr_poncho.p3d";
		class ItemInfo: VestItem
		{
      uniformModel = "\mgsr_poncho\mgsr_poncho.p3d";
      containerClass="twelfth_vest_supply";
      mass = 80;
       class HitpointsProtectionInfo {
        class Neck {
          hitpointName="HitNeck";
          armor=20; 
          passThrough=0.30000001;
        };
        class Arms {
          hitpointName="HitArms";
          armor=10; 
          passThrough=0.60000002;
        };
        class Chest {
          hitpointName="HitChest";
          armor=20; 
          passThrough=0.30000001;
        };
        class Diaphragm {        
          hitpointName="HitDiaphragm";
          armor=20; 
          passThrough=0.30000001;
        };
        class Abdomen {
          hitpointName="HitAbdomen";
          armor=20; 
          passThrough=0.30000001;
        };
        class Body {
          hitpointName="HitBody";
          passThrough=0.30000001;
          armor=20; 
        };
        class Legs {
          hitpointName="HitLegs";
          armor=10;
          passThrough=0.60000002;
        };
      }; 
      setMaxLoad=200;
      hiddenSelections[] = {"camo"};
			hiddenSelectionsTextures[] = {"\mgsr_poncho\data\mgsr_poncho.paa"};
			hiddenSelectionsMaterials[] = {"\mgsr_poncho\data\mgsr_poncho.rvmat"};
		};
  };

  // ODST
  class twelft_odst_vest : TCP_V_M43D_ODST_4_Black {
    scope = 2;
    scopeArsenal = 2;
    author = "Rex";
    displayName = "[12] ODST";
    ACE_GForceCoef = 0.4;
    model = "\TCP\Characters\BLUFOR\UNSC\Marines\Vests\M43D\M43D_ODST_4.p3d";
    class ItemInfo: VestItem
    {
      containerClass="twelfth_vest_supply";                                
      mass = 80;
      uniformModel = "\TCP\Characters\BLUFOR\UNSC\Marines\Vests\M43D\M43D_ODST_4.p3d";
      VEST_HITPOINT_INFO 
      setMaxLoad=200;
      hiddenSelectionsTextures[] = {"\TCP\characters\BLUFOR\UNSC\Army\Vests\M43A\data\camo\Black\vest_M43A_01_CO.paa","\TCP\Characters\BLUFOR\UNSC\Marines\Vests\M43D\data\camo\Black\vest_Shoulders_ODST_CO.paa",
      "\TCP\Characters\BLUFOR\UNSC\Marines\Vests\M43D\data\camo\Black\vest_M43D_ODST_CO.paa","\TCP\characters\BLUFOR\UNSC\Army\Vests\M43A\data\camo\Black\vest_M43A_02_CO.paa",
      "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\white\vest_M43_DecalSheet_CA.paa"};
    };
  };


  // ---------------------------------------------------------------------------
  //  Invisible Vest
  // ---------------------------------------------------------------------------
  class twelfth_invis_vest: OPTRE_UNSC_M52A_Armor2_MAR {
    author="Weber"; 
    scope=2;  // Visible in-game.
    scopeArsenal=2;  // Available in the Arsenal.
    displayName = "[12th] Invisible Vest";
    model="x\12thMEU\addons\12th_backpacks\backpack\null.p3d";
      /*
        This is a blank model referencing an invisible or “null” vest geometry.
      */
    picture="";
    hiddenSelectionsTextures[] = {""};
      /*
        Usually, you’d set an empty texture. If you have an actual blank texture,
        you could define it here. Otherwise, leaving it blank is enough.
      */
    // Use our macro to define vest characteristics (mass, container size, etc.)
    INVIS_VEST_ITEM_INFO
  };

  
  

  // Base uniform item for new-gen armor
  //-New Armour-----------------------------------------------------
  GENERATE_VEST_REFERENCES
  GENERATE_VEST_CLASSES(std)

    // Army
  class twelft_army_vest : TCP_V_M43A_GungnirL_3_Base{
    scope = 2;
    scopeArsenal = 2;
    author = "Rex";
    displayName = "[12th] Army";
    ACE_GForceCoef = 0.4;
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};
    hiddenSelectionsTextures[] = {
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Vest_01_CO",
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Gungnir_CO.paa",
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Vest_02_CO",
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Vest_03_co",
        "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"
    };
    class ItemInfo : VestItem {
      containerClass="twelfth_vest_supply";                                
      mass = 80;
      uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";
      VEST_HITPOINT_INFO 
      setMaxLoad=200;
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};
      hiddenSelectionsTextures[] = {
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Vest_01_CO",
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Gungnir_CO.paa",
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Vest_02_CO",
        "\x\12thMeu\addons\12th_vests\data\Army\camo\Vest_03_co",
        "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"
      };
    };
  };
};

class XtdGearModels {
  class CfgWeapons {
    class twelfth_base_vests {
      label="12th Infantry Vests";
      options[] = {"camo","element","role","belt","shoulders","collar","legs"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"forest", "std", "forest90", "urban", "drk", "desert"};
        class forest {label="Standard";};
        class std {label="MARPAT";};
        class forest90 {label="Forest90";};
        class urban {label="Urban";}; //maybe winter?? will need to look into new armor pieces
        class drk {label="VBSS";};
        class desert {label="Desert";};
      };
      class collar {
        alwaysSelectable = 1;
        label="Collar Armour";
        values[]={"none", "flak", "armored"};
        class none {label="None";};
        class flak {label="Flak";};
        class armored {label="Armoured";};
      };
      class shoulders {
        alwaysSelectable = 1;
        label="Shoulder Armour";
        values[]={"Light","Pads","BaseSec","GungnirS","GungnirL"};
        class Light  {label="None";};
        class Pads  {label="Pads";};
        class BaseSec {label="Security";};
        class GungnirS {label="Gungnir(S)";};
        class GungnirL {label="Gungnir(L)";};
      };
      class belt {
        alwaysSelectable = 1;
        label="Belt";
        values[]={"none", "belt"};
        class none {label="None";};
        class belt {label="Belt";};
      };
      class legs {
        alwaysSelectable = 1;
        label="Leg Armour";
        values[]={"none", "thigh", "full"};
        class none {label="None";};
        class thigh {label="Thigh";};
        class full {label="Full";};
      };
      class element {
        alwaysSelectable = 1;
        label="Element";
        values[]={"na","hq","1pl","2pl","lpl"};
        class na  {label="None";};
        class hq  {label="HQ";  image=XTP(athena);};
        class 1pl {label="1PLT"; image=XTP(1pl);};
        class 2pl {label="2PLT";   image=XTP(2pl);};
        class lpl {label="LOGI";   image=XTP(chaos);};
      };
      class role {
        alwaysSelectable = 1;
        label="MOS";
        values[]={"na","med"};
        class na  {label="None";};
        class med {label="Corpsman"; image=XTP(med);};
      };
    };
  };
};

class XtdGearInfos {
  class CfgWeapons {
    // VEST GI
    GENERATE_VEST_XTDGI(std)
  };
};
