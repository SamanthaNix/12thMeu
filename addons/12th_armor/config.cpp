// This directive suppresses specific Hemtt warnings related to padded arguments in the configuration file.
#pragma hemtt suppress pw3_padded_arg config


#include "config_macros.hpp"

/*
  ==============================================================================
  config.cpp

  This file defines:
    - The 12th MEU custom uniforms (both vehicle display classes and weapon/uniform classes).
    - The 12th MEU custom helmets (standard, NV variants, pilot helmets, etc.).
    - CfgPatches: Lists every uniform & helmet class for Arma’s engine.
    - CfgVehicles: Configures the actual wearable units for uniforms (the “vehicle” class).
    - CfgWeapons: Configures the “inventory” items for these uniforms & helmets.
    - XtdGearModels & XtdGearInfos for extended arsenal integration.

  Key Points:
    - The macros in `config_macros.hpp` generate a large number of uniform & helmet 
      variants: standard, forest, dark (drk), urban, plus roles like medic, HQ, 1PL, 
      2PL, etc.
    - Some items are commented out pending final textures or usage decisions.

  ==============================================================================
*/

class CfgPatches {
  class twelfth_armor {
    /*
      units[]: All the placeable "vehicle" classes for uniforms in the editor 
               or gear lists.  
      weapons[]: The “weapon” (i.e., uniform item) classes.  
    */
    units[]= {
      "twelfth_odst_uniform_veh",

    };
    weapons[]= {
      "twelfth_odst_uniform_wep",
      "twelfth_uni_ng_base_wep",
      "twelfth_aa_helm",
    };
    requiredAddons[]= {
      "A3_Armor_F_Beta",
      "A3_Soft_F",
      "OPTRE_UNSC_Units",
      "DMNS_Units",
      "cba_main",
      "ace_main",
      "TCP_characters"
    };
  };
};

// -----------------------------------------------------------------------------
//  CfgVehicles
// -----------------------------------------------------------------------------
class CfgVehicles {
// Base classes from Arma or third-party mods
  class B_Soldier_base_F;
  class B_CTRG_Soldier_2_F;
  class OPTRE_UNSC_Army_Soldier_WDL;
  class OPTRE_UNSC_Army_Soldier_R_WDL;
  class OPTRE_UNSC_Army_Soldier_S_WDL;
  class OPTRE_UNSC_Army_Soldier_DressGray;
  class OPTRE_UNSC_CH252A_Helmet_Base;
  class OPTRE_UNSC_CH252A_Helmet_dp;
 
  class 19th_ODST;
  //TCP UNIFORM vehicle definitions
  
  // ---------------------------------------------------------------------------
  //  twelfth_uni_ng_base_veh
  // ---------------------------------------------------------------------------
  /*
    A base class for your new-gen (ng) armor sets (chest, arms, legs, etc.).
    Other macros or classes inherit from this to create specific camos/roles.
  */
/*
---------------------------New uniform setup---------------------------
---------------This is where you put new uniform textures macro-------------
-----------------------------------------------------------------------
*/
  TCP_VEH_CLASS_DEF
  VEH_UNI_CLASS(std)
  VEH_UNI_CLASS(winter)
  VEH_UNI_CLASS(opfor)
  VEH_UNI_CLASS(desert)
  VEH_UNI_TSHIRT_CLASS(instructor)
  VEH_UNI_TSHIRT_CLASS(aic)
  VEH_UNI_TSHIRT_CLASS(unscmc)

  // ---------------------------------------------------------------------------
  //  twelfth_odst_uniform_veh
  // ---------------------------------------------------------------------------
  /*
    A special ODST uniform referencing a 19th ODST base. If you only need 
    one ODST variant, there’s no macro overhead. If you plan many variants, 
    you might consider macros.
  */
  class twelfth_odst_uniform_veh: 19th_ODST {
    scope=1;
    scopeArsenal=0;
    author="Waylen";
    model="Foundries\ODST\ODST_Uniform_F.p3d";
    hiddenSelections[]={"camo1", "camo2"};
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\odst\odst_top.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\odst\odst_pants.paa"
    };
  };
  

};

// -----------------------------------------------------------------------------
//  CfgWeapons
// -----------------------------------------------------------------------------
class CfgWeapons {
  class TCP_equipmentTypes;
  class H_Cap_oli;
  class UniformItem;
  class ItemInfo;
  class Uniform_Base;
  class H_HelmetB;
  class HeadgearItem;
  class OPTRE_UNSC_Army_Uniform_WDL;
  class OPTRE_UNSC_Army_Uniform_R_WDL;
  class OPTRE_UNSC_Army_Uniform_S_WDL;
  class OPTRE_UNSC_Dress_Uniform_gray;
  class U_B_CombatUniform_mcam_tshirt;
  class TCP_H_UtilityCover_Base;
  class TCP_H_Helmet_CH43A_Base;
  class TCP_V_M43A_BaseSec_1_Base;
  class OPTRE_UNSC_CH252A_Helmet_Base;
  class OPTRE_UNSC_CH252A_Helmet_dp;  // Base uniform item for new-gen armor
  class TCP_H_Helmet_ECH43A_Base;
  class TCP_H_boonieHat_Base;
  class TCP_H_boonieHat_Folded_Base;
  class TCP_H_boonieHat_Folded_Left_Base;
  class TCP_H_boonieHat_Folded_Right_Base;
  class TCP_H_PatrolCap_Base;
  class twelfth_uni_ng_base_wep: Uniform_Base {
    author="Waylen";
    scope=0;
    scopeArsenal=0;
    displayName="[12th] Armor Base Weapon (DON'T USE)";
    model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
    ACE_GForceCoef=0.4;
    class ItemInfo: UniformItem {
      uniformModel="-";
      uniformClass="twelfth_uni_ng_base_veh";
      containerClass="Supply100";
      mass=1;
      uniformType = "Neopren";
      allowedSlots[]={"701","801","901"};
      armor=20;
    };
  };

  //TCP UNIFORM Weapon definitions
  TCP_WEP_CLASS_DEF
  WEP_UNI_CLASS(std)
  WEP_UNI_CLASS(winter)
  WEP_UNI_CLASS(desert)
  WEP_UNI_CLASS(opfor)
  WEP_UNI_TSHIRT_CLASS(instructor)
  WEP_UNI_TSHIRT_CLASS(aic)
  WEP_UNI_TSHIRT_CLASS(unscmc)
  BOONIE(std)
  BOONIE(desert)
  BOONIE(snow)
  BOONIE(opfor)

  // Example ODST uniform item referencing twelfth_odst_uniform_veh
  class twelfth_odst_uniform_wep: Uniform_Base {
    scope=2;
    scopeArsenal=2;
    author="Waylen";
    model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
    displayName="[12th][ODST] Armor";
    ACE_GForceCoef = 0.4;
    class ItemInfo: UniformItem {
      uniformModel="-";
      uniformClass="twelfth_odst_uniform_veh";
      containerClass="Supply100";
      mass=1;
      uniformType = "Neopren";
      allowedSlots[]={"701","801","901"};
      armor=20;
    };
  };
  // Army Aviator helmet example: CH252AA
  class twelfth_aa_helm: OPTRE_UNSC_CH252A_Helmet_Base {
    scope=2;
    scopeArsenal=2;
    author="Waylen & A2S";
    picture="";
    displayName="[12th][CH252AA] Helmet";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
    model="\OPTRE_UNSC_Units\Army\aa_helmet.p3d";
    optreHUDStyle = "ODST_1";
    class ItemInfo: HeadgearItem{
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      uniformModel="\OPTRE_UNSC_Units\Army\aa_helmet.p3d";
      hiddenSelections[]={ "camo" };
      hiddenSelectionsTextures[]={
        "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
      };
      class HitpointsProtectionInfo{
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
    hiddenSelections[]={ "camo" };
    hiddenSelectionsTextures[]={
      "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
    };
  };

  // Depolarized variant of the AA helmet
  class twelfth_aa_helm_dp: OPTRE_UNSC_CH252A_Helmet_dp {
    scope=2;
    scopeArsenal=0;
    author="Waylen & A2S";
    picture="";
    displayName="[12th][CH252AA] Helmet DP";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0.30000001;
         model="\OPTRE_UNSC_Units\Army\aa_helmet_dp.p3d";
    optreHUDStyle = "ODST_1";
    class ItemInfo: HeadgearItem{
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      uniformModel="\OPTRE_UNSC_Units\Army\aa_helmet_dp.p3d";
      hiddenSelections[]={ "camo" };
      hiddenSelectionsTextures[]={
        "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
      };
      class HitpointsProtectionInfo{
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
    hiddenSelections[]={ "camo" };
    hiddenSelectionsTextures[]={
      "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
    };
  };




  PATROLCAP_WEP(std)
  PATROLCAP_WEP(desert)
  PATROLCAP_WEP(snow)
  PATROLCAP_WEP(opfor)

  UTILITYCOVER_WEP(std)
  UTILITYCOVER_WEP(desert)
  UTILITYCOVER_WEP(snow)
  UTILITYCOVER_WEP(opfor)
  //-HELMETS----------------------------------------------------------

  /*class twelfth_odst_helm: H_HelmetB {
    scope=2;
    scopeArsenal=2;
    author="Waylen";
    displayName="[12th][ODST] Helmet";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0.30000001;
    model="Foundries\ODST\ODST_helm_F.p3d";
    hiddenSelections[]= { "camo" };
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\helmets\odst\odst_helm.paa"
    };
    class ItemInfo: HeadgearItem {
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
      uniformModel="Foundries\ODST\ODST_helm_F.p3d";
      hiddenSelections[]={"camo"};
      hiddenSelectionsTextures[]= {
        "\x\12thMEU\addons\12th_armor\helmets\odst\odst_helm.paa"
      };
    };
  };*/

  // Helmet_CH43A
  class twelfth_helmCH43A_base: TCP_H_Helmet_CH43A_Base {
    scope=0;
    author="Sammy";
    scopeArsenal=0;
    picture="x\12thMEU\addons\12th_ui\data\logo.paa";
    displayName="[12th] Helmet Base (DON'T USE)";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
    class TCP_uniformDecals
    {
      selectionName = "nameCH43A";
    };
	  model = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";
    class ItemInfo: HeadgearItem {
	  uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
  };

  class twelfth_helmECH43A_base: TCP_H_Helmet_ECH43A_Base {
    scope=0;
    author="Sammy";
    scopeArsenal=0;
    displayName="[12th] Helmet Closed Base (DON'T USE)";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
    picture="\x\12thMEU\addons\12th_ui\data\logo.paa";
    class TCP_uniformDecals
    {
      selectionName = "nameCH43A";
    };
	  model = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_DP.p3d";
    class ItemInfo: HeadgearItem {
	  uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_DP.p3d";
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
  };
  class twelfth_pilot_helm_base: H_HelmetB {
    scope=0;
    author="Waylen";
    scopeArsenal=0;
    displayName="[12th] Pilot Helmet Base (DON'T USE)";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
    model="A3\Characters_F\Common\headgear_helmet_heli.p3d";
    picture="\x\12thMEU\addons\12th_ui\data\logo.paa";
    class ItemInfo: HeadgearItem {
      uniformModel="A3\Characters_F\Common\headgear_helmet_heli";
      mass=30;
      modelSides[]={3,1};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
  };

  // ODST
   class twelfth_odst_helmet: TCP_H_Helmet_CH43A_Base {
    scope=2;
    author="Rex";
    scopeArsenal=2;
    displayName="[12th] ODST";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
	  model = "\TCP\Characters\BLUFOR\UNSC\Marines\Headgear\helmet_ECH55D\h_helmet_ECH55D_Blue.p3d";
    class ItemInfo: HeadgearItem {
	  uniformModel = "\TCP\Characters\BLUFOR\UNSC\Marines\Headgear\helmet_ECH55D\h_helmet_ECH55D_Blue.p3d";
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
  };

  // Army
  class twelfth_army_helmet: TCP_H_Helmet_CH43A_Base {
    scope=2;
    author="Rex";
    scopeArsenal=2;
    picture="x\12thMEU\addons\12th_ui\data\logo.paa";
    displayName="[12th] Army";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
    hiddenSelections[] = { "camo","decals" };              
    hiddenSelectionsTextures[] = {                
      "\x\12thMeu\addons\12th_armor\helmets\army\Helm_CO.paa",               
      "tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\Black\vest_M43_DecalSheet_CA.paa"									
    };
    class TCP_uniformDecals
    {
      selectionName = "black";
    };
	  model = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";
    class ItemInfo: HeadgearItem {
	  uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
      hiddenSelections[] = { "camo","decals" };              
      hiddenSelectionsTextures[] = { 
        "\x\12thMeu\addons\12th_armor\helmets\army\Helm_CO.paa",               
        "tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\Black\vest_M43_DecalSheet_CA.paa"					
      };
    };
  };
  

  //-MACRO CALLS------------------------------------------------------

  /*CAP_B(twelfth_logo,    "[12th][Caps] Cap (12th Logo)")
  CAP_B(news,         "[12th][Caps] Cap (News)")
  CAP_B(news_2,       "[12th][Caps] Cap (News 2)")
  CAP_B(pale_horse,   "[12th][Caps] Cap (Pale Horse)")
  CAP_B(pale_horse_2, "[12th][Caps] Cap (Pale Horse 2)")*/

  //-UNIFORM-WEPS-----------------------------------------------------

  //-HELMETS----------------------------------------------------------
  ALL_HELM(std)

  // Pilot Helmets
  PILOT_HELM(default, "[12th][Pilot] Helmet",default,default,default,default,default)
};

// -----------------------------------------------------------------------------
//  XtdGearModels & XtdGearInfos
// -----------------------------------------------------------------------------
/*
  These define extended gear categories for UI or ACE arsenal expansions.
  - e.g. "twelfth_base_helms" with options "visor","camo","element","role".
*/
class XtdGearModels {
  class CfgWeapons {
    // Helmets
    class twelfth_patrolcap {
      label = "12th Patrol Caps";
      options[] = {"camo"};
      class camo {
        alwaysSelectable = 1;
        label = "Camoflauge";
        values[] = {"std", "desert", "snow", "opfor"};
        class std {label = "Forest";};
        class desert {label = "Desert";};
        class snow {label = "Winter";};
        class opfor {label = "OPFOR";};
      };
    };

    class twelfth_utilcap {
      label = "12th Utility Cover";
      options[] = {"camo"};
      class camo {
        alwaysSelectable = 1;
        label = "Camoflauge";
        values[] = {"std", "desert", "snow", "opfor"};
        class std {label="Forest";};
        class desert {label="Desert";};
        class snow {label="Winter";};
        class opfor {label="OPFOR";};
      };
    };

    class twelfth_base_ch43a {
      label="12th Infantry Helmets";
      options[] = {"camo","closed","element","role"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"std"};
        class std {label="Standard";};
      };
      class closed {
        alwaysSelectable = 1;
        label="Face";
        values[]={"yes","no"};
        class no  {label="Open";};
        class yes  {label="Closed";};
      };
      class element {
        alwaysSelectable = 1;
        label="Element";
        values[]={"na","hq","1pl","2pl","lpl"};
        class na  {label="None";};
        class hq  {label="HQ";  image=XTP(athena);};
        class 1pl {label="1PLT";image=XTP(1pl);};
        class 2pl {label="2PLT";image=XTP(2pl);};
        class lpl {label="LOGI";image=XTP(chaos);};
      };
      class role {
        alwaysSelectable = 1;
        label="MOS";
        values[]={"na","med","ftl","sl","pl","psg"};
        class na  {label="None";     /* image=XTP(role); */};
        class pl  {label="PLT LDR";  /* image=XTP(role_pl); */};
        class psg {label="PLT SGT";  /* image=XTP(role_psg); */};
        class ftl {label="FTL";      /* image=XTP(role_ftl); */};
        class sl  {label="SQD LDR";  /* image=XTP(role_sl); */};
        class med {label="Corpsman"; image=XTP(med);};
      };
    };

    class twelfth_base_helms {
      label="12th Infantry Helmets";
      options[] = {"visor","camo","element","role"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"std"};
        class std {label="Standard";};
      };
      class element {
        alwaysSelectable = 1;
        label="Element";
        values[]={"na","hq","1pl","2pl","lpl"};
        class na  {label="None";};
        class hq  {label="HQ";  image=XTP(athena);};
        class 1pl {label="1PLT";image=XTP(1pl);};
        class 2pl {label="2PLT";image=XTP(2pl);};
        class lpl {label="LOGI";image=XTP(chaos);};
      };
      class role {
        alwaysSelectable = 1;
        label="MOS";
        values[]={"na","med","ftl","sl","pl","psg"};
        class na  {label="None";     /* image=XTP(role); */};
        class pl  {label="PLT LDR";  /* image=XTP(role_pl); */};
        class psg {label="PLT SGT";  /* image=XTP(role_psg); */};
        class ftl {label="FTL";      /* image=XTP(role_ftl); */};
        class sl  {label="SQD LDR";  /* image=XTP(role_sl); */};
        class med {label="Corpsman"; image=XTP(med);};
      };
      class visor {
        alwaysSelectable = 1;
        label="Visor";
        values[]={"Yes", "No"};
      };
    };

    // Uniforms
    class twelfth_new_uniforms {
      label="12th New Infantry Uniforms";
      options[] = {"camo", "sleeve","glove","shirt","blouse","zip","kneepad"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"std","winter","opfor","desert"};
        class std {label="Standard";     image=XTP(forest);};
        class winter {label="Winter"; /* image=XTP(winter); */};
        class desert {label="Desert"; image=XTP(desert);};
        class opfor {label="OPFOR";};
      };
      class sleeve {
        alwaysSelectable = 1;
        label="Sleeve Type";
        values[]={"Tucked","Full","QuarterRoll","HalfRoll","SlimSleeve","Untucked"};
        class Tucked  {label="Tucked";};
        class Full  {label="Full";};
        class QuarterRoll {label="Quarter Roll";};
        class HalfRoll {label="Half Roll";};
        class SlimSleeve {label="Slim Sleeve";};
        class Untucked  {label="Untucked";};
      };
      class glove {
        alwaysSelectable = 1;
        label="Gloves";
        values[]={"yes","no"};
        class yes  {label="With Gloves";};
        class no {label="No Gloves";};
      };
      class shirt {
        alwaysSelectable = 1;
        label="Shirt Type";
        values[]={"TShirt","TacShirt","FieldTop"};
        class TShirt  {label="T-shirt";};
        class TacShirt {label="Tac-Shirt";};
        class FieldTop {label="Field Top";};
      };
      class blouse {
        alwaysSelectable=1;
        label="Blouse Type";
        values[]={"blouse","noblouse"};
        class blouse {label="Blouse";};
        class noblouse {label="No Blouse";};
      };
      class zip {
        alwaysSelectable=1;
        label="Zipper Type";
        values[]={"zipped","unzipped"};
        class zipped {label="Zipped Up";};
        class unzipped {label="Unzipped";};
      };
      class kneepad {
        alwaysSelectable=1;
        label="Kneepad Type";
        values[]={"nokneepads","kneepads"};
        class nokneepads {label="No kneepads";};
        class kneepads {label="Kneepads";};
      };
    };
    

    class twelfth_tshirt {
      label="12th TShirts";
      options[] = {"camo","tuck","glove","kneepad","blouse"};
      class camo {
        alwaysSelectable = 1;
        label="Print";
        values[]={"instructor", "aic", "unscmc"};
        class instructor {label="Instructor";}; 
        class aic {label="AiC";};
        class unscmc {label="UNSCMC";};
      };
      class tuck {
        alwaysSelectable = 1;
        label="Tucking";
        values[]={"tucked", "untucked"};
        class Tucked {label="Tucked";};
        class Untucked {label="Untucked";};
      };
      class glove {
        alwaysSelectable = 1;
        label="Gloves";
        values[]={"yes","no"};
        class yes  {label="With Gloves";};
        class no {label="No Gloves";};
      };
      class kneepad {
        alwaysSelectable=1;
        label="Kneepad Type";
        values[]={"nokneepads","kneepads"};
        class nokneepads {label="No kneepads";};
        class kneepads {label="Kneepads";};
      };
      class blouse {
        alwaysSelectable=1;
        label="Blouse Type";
        values[]={"blouse","noblouse"};
        class blouse {label="Blouse";};
        class noblouse {label="No blouse";};
      };
    };

    class twelfth_boonies {
      label="12th Boonies";
      options[] = {"camo", "fold"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"std", "desert", "snow", "opfor"};
        class std {label="Forest";}; 
        class desert {label="Desert";};
        class snow {label="Winter";};
        class opfor {label="OPFOR";};
      };
      class fold {
        alwaysSelectable = 1;
        values[]={"na", "Folded_Left", "Folded_Right", "Folded"};
        class na {label="No fold";};
        class Folded_Left {label="Left";};
        class Folded_Right {label="Right";};
        class Folded {label="Both";};
      };
    };
  };
};

class XtdGearInfos {
  class CfgWeapons {
    // THIS IS WHERE EXTENDED ARSENAL PULLS INFO FOR THE SELECTIONS FROM
    //-------------------------------------- Uniforms
    
    
    // Boonies

    BOONIE_GI(std)
    BOONIE_GI(desert)
    BOONIE_GI(snow)
    BOONIE_GI(opfor)
    

    // Patrol caps

    PATROLCAP_GI(std)
    PATROLCAP_GI(desert)
    PATROLCAP_GI(snow)
    PATROLCAP_GI(opfor)
    
    //-------------------------------------- Helmets 

	  CH43A_HELM_GI(std)


    //-------------------------------------- New uniforms
    NEW_UNIFROM_GI(std)
    NEW_UNIFROM_GI(winter)
    NEW_UNIFROM_GI(desert)
    NEW_UNIFROM_GI(opfor)
    // Utility cover

    UTILITYCOVER_GI(std)
    UTILITYCOVER_GI(desert)
    UTILITYCOVER_GI(snow)
    UTILITYCOVER_GI(opfor)

    //-------------------------------------- instructor
    //INSTRUCTOR_UNIFROM_GI
    TSHIRT_NORMAL_GI(instructor,Tucked)
    TSHIRT_NORMAL_GI(instructor,Untucked)
    TSHIRT_GLOVES_GI(instructor,Tucked)
    TSHIRT_GLOVES_GI(instructor,Untucked)
    TSHIRT_BLOUSED_GI(instructor,Tucked)
    TSHIRT_BLOUSED_GI(instructor,Untucked)
    TSHIRT_BLOUSED_GLOVES_GI(instructor,Tucked)
    TSHIRT_BLOUSED_GLOVES_GI(instructor,Untucked)
    TSHIRT_NORMAL_GI(aic,Tucked)
    TSHIRT_NORMAL_GI(aic,Untucked)
    TSHIRT_GLOVES_GI(aic,Tucked)
    TSHIRT_GLOVES_GI(aic,Untucked)
    TSHIRT_BLOUSED_GI(aic,Tucked)
    TSHIRT_BLOUSED_GI(aic,Untucked)
    TSHIRT_BLOUSED_GLOVES_GI(aic,Tucked)
    TSHIRT_BLOUSED_GLOVES_GI(aic,Untucked)
    TSHIRT_NORMAL_GI(unscmc,Tucked)
    TSHIRT_NORMAL_GI(unscmc,Untucked)
    TSHIRT_GLOVES_GI(unscmc,Tucked)
    TSHIRT_GLOVES_GI(unscmc,Untucked)
    TSHIRT_BLOUSED_GI(unscmc,Tucked)
    TSHIRT_BLOUSED_GI(unscmc,Untucked)
    TSHIRT_BLOUSED_GLOVES_GI(unscmc,Tucked)
    TSHIRT_BLOUSED_GLOVES_GI(unscmc,Untucked)
  };
};