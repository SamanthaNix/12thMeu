#pragma hemtt suppress pw3_padded_arg config
#include "config_macros.hpp"

/*
  ==============================================================================
  Documentation / Workflow
  ==============================================================================
  1) **Texture Import**  
     - Convert your helmet texture(s) to .paa.  
     - Name them using this pattern: `twelfth_ch_[CAMO]_[NAME].paa`, for example
       "twelfth_ch_std_Bert.paa" (if no explicit camo is used, omit that part).

  2) **Add a New Helmet**  
     - In the `CfgPatches` -> `weapons[]` array below, add both:
       `twelfth_ch_[CAMO]_[NAME]`
       and
       `twelfth_ch_[CAMO]_[NAME]_nv`
       (the NV variant).
     - Under `CfgWeapons`, call the relevant macro:
       `CUSTOM_HELM_S_AV(NAME)`, which auto-generates two classes:
         - `twelfth_ch_std_[NAME]`
         - `twelfth_ch_std_[NAME]_nv`.
     - Add the new helmet name to `XtdGearModels->CfgWeapons->twelfth_custom_helms->member[]`.
     - Use the macro `CH_HELM_S_GI(NAME)` in `XtdGearInfos->CfgWeapons` block.

  3) **Pilot Helmets**  
     - If you’re adding a custom pilot helmet, use `CUSTOM_PILOT_HELM(...)`.
     - Then also add the resulting class name to `CfgPatches` weapons[] array.

  4) **Alphabetical Order**  
     - Insert new entries in alphabetical order to keep the file tidy.

  ==============================================================================
*/

class CfgPatches {
  class twelfth_custom_helms {
    units[] = {};
    weapons[] = {
      "twelfth_helmCH43A_std_Bateman",
      "twelfth_helmCH43A_std_Bert",
      "twelfth_helmCH43A_std_Bob",
      "twelfth_helmCH43A_std_Bobby",
      "twelfth_helmCH43A_std_Coady",
      "twelfth_helmCH43A_std_Don",
      "twelfth_helmCH43A_std_Dixie",
      "twelfth_helmCH43A_std_Duckworth",
      "twelfth_helmCH43A_std_Felix",
      "twelfth_helmCH43A_std_Geoff",
      "twelfth_helmCH43A_std_Germain",
      "twelfth_helmCH43A_std_Hathaway",
      "twelfth_helmCH43A_std_Jekyll",
      "twelfth_helmCH43A_std_Kiens",
      "twelfth_helmCH43A_std_LeDoux",
      "twelfth_helmCH43A_std_Mcintyre",
      "twelfth_helmCH43A_std_Mercer",
      "twelfth_helmCH43A_std_Moss",
      "twelfth_helmCH43A_std_Perry",
      "twelfth_helmCH43A_std_Quinn",
      "twelfth_helmCH43A_std_Rex",
      "twelfth_helmCH43A_std_Sand",
      "twelfth_helmCH43A_std_Sammy",
      "twelfth_helmCH43A_std_Schultz",
      "twelfth_helmCH43A_std_Shepard",
      "twelfth_helmCH43A_std_Simmons",
      "twelfth_helmCH43A_std_Smitty",
      "twelfth_helmCH43A_std_Stacker",
      "twelfth_helmCH43A_std_Styx",
      "twelfth_helmCH43A_std_Origami",
      "twelfth_helmCH43A_std_Sullivan",
      "twelfth_helmCH43A_std_Luke",
      "twelfth_helmCH43A_std_Taji",
      "twelfth_helmCH43A_std_Thomas",
      "twelfth_helmCH43A_std_Wilson",
      
      "twelfth_helmECH43A_std_Bateman_clsd",
      "twelfth_helmECH43A_std_Bert_clsd",
      "twelfth_helmECH43A_std_Bob_clsd",
      "twelfth_helmECH43A_std_Bobby_clsd",
      "twelfth_helmECH43A_std_Coady_clsd",
      "twelfth_helmECH43A_std_Don_clsd",
      "twelfth_helmECH43A_std_Dixie_clsd",
      "twelfth_helmECH43A_std_Duckworth_clsd",
      "twelfth_helmECH43A_std_Felix_clsd",
      "twelfth_helmECH43A_std_Geoff_clsd",
      "twelfth_helmECH43A_std_Germain_clsd",
      "twelfth_helmECH43A_std_Hathaway_clsd",
      "twelfth_helmECH43A_std_Jekyll_clsd",
      "twelfth_helmECH43A_std_Kiens_clsd",
      "twelfth_helmECH43A_std_LeDoux_clsd",
      "twelfth_helmECH43A_std_Mcintyre_clsd",
      "twelfth_helmECH43A_std_Mercer_clsd",
      "twelfth_helmECH43A_std_Moss_clsd",
      "twelfth_helmECH43A_std_Perry_clsd",
      "twelfth_helmECH43A_std_Quinn_clsd",
      "twelfth_helmECH43A_std_Rex_clsd",
      "twelfth_helmECH43A_std_Sammy_clsd",
      "twelfth_helmECH43A_std_Schultz_clsd",
      "twelfth_helmECH43A_std_Shepard_clsd",
      "twelfth_helmECH43A_std_Simmons_clsd",
      "twelfth_helmECH43A_std_Smitty_clsd",
      "twelfth_helmECH43A_std_Stacker_clsd",
      "twelfth_helmECH43A_std_Styx_clsd",
      "twelfth_helmECH43A_std_Origami_clsd",
      "twelfth_helmECH43A_std_Sullivan_clsd",
      "twelfth_helmECH43A_std_Luke_clsd",
      "twelfth_helmECH43A_std_Taji_clsd",
      "twelfth_helmECH43A_std_Thomas_clsd",
      "twelfth_helmECH43A_std_Wilson_clsd",
      "12th_pilot_ch_penquite",
      "12th_pilot_ch_Moss",
      "12th_pilot_ch_tomb",
    };
    requiredAddons[]= {
      "A3_Armor_F_Beta",
      "A3_Soft_F",
      "OPTRE_Vehicles_M494"
    };
  };
};

class CfgWeapons {
  /*
    Base classes & references:
    - H_HelmetB: Standard ArmA 3 base helmet
    - HeadgearItem: For item-specific config (weight, armor, etc.)
  */
  class H_HelmetB;
  class ItemInfo;
  class HeadgearItem;
  class twelfth_helmCH43A_base;
  class twelfth_helmECH43A_base;
  class TCP_uniformDecals;
  // ---------------------------------------------------------------------------
  //  Base Class for 12th Custom Helmets
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  //  Macros: CUSTOM_HELM_S_AV(NAME)
  // ---------------------------------------------------------------------------
  /*
    Creates two classes:
      1) twelfth_ch_std_[NAME]    : Standard
      2) twelfth_ch_std_[NAME]_nv : NV variant (capable of some "visor" or 2nd selection)
    
    Each inherits from `twelfth_custom_helm_base`, sets textures, etc.
    If you want to hide or comment out certain members, do so below in the macro calls.
  */

  // -- Standard Helmets --
  CUSTOM_HELM_S_AV(Bateman)
  CUSTOM_HELM_S_AV(Bert)
  CUSTOM_HELM_S_AV(Bob)
  CUSTOM_HELM_S_AV(Bobby)
  CUSTOM_HELM_S_AV(Coady)
  CUSTOM_HELM_S_AV(Clarke)
  CUSTOM_HELM_S_AV(Don)
  CUSTOM_HELM_S_AV(Dixie)
  CUSTOM_HELM_S_AV(Duckworth)
  CUSTOM_HELM_S_AV(Felix)
  CUSTOM_HELM_S_AV(Geoff)
  CUSTOM_HELM_S_AV(Germain)
  CUSTOM_HELM_S_AV(Hathaway)
  CUSTOM_HELM_S_AV(Jekyll)
  CUSTOM_HELM_S_AV(Kiens)
  CUSTOM_HELM_S_AV(LeDoux)
  CUSTOM_HELM_S_AV(Mcintyre)
  CUSTOM_HELM_S_AV(Mercer)
  CUSTOM_HELM_S_AV(Moss)
  CUSTOM_HELM_S_AV(Perry)
  CUSTOM_HELM_S_AV(Quinn)
  CUSTOM_HELM_S_AV(Rex)
  CUSTOM_HELM_S_AV(Sand)
  CUSTOM_HELM_S_AV(Sammy)
  CUSTOM_HELM_S_AV(Schultz)
  CUSTOM_HELM_S_AV(Shepard)
  CUSTOM_HELM_S_AV(Simmons)
  CUSTOM_HELM_S_AV(Smitty)
  CUSTOM_HELM_S_AV(Stacker)
  CUSTOM_HELM_S_AV(Styx)
  CUSTOM_HELM_S_AV(Origami)
  CUSTOM_HELM_S_AV(Quiggle)
  CUSTOM_HELM_S_AV(Sullivan)
  CUSTOM_HELM_S_AV(Luke)
  CUSTOM_HELM_S_AV(Taji)
  CUSTOM_HELM_S_AV(Thomas)
  CUSTOM_HELM_S_AV(Wilson)


  // -- Pilot Helmets --
  /*
    Macro usage:
    CUSTOM_PILOT_HELM(
      SUFFIX, 
      DISPLAY, 
      C1, C2, C3, C4, C5
    );
    Each bracket represents a separate texture path inside data\pilots\.

    Example:
    If you pass (penquite,"[12th][Pilot][Customs] Penquite", default, penquite, default, default, default)
    The 5 textures it looks for:
      \...\pilots\default\Addons_co.paa
      \...\pilots\penquite\EXT_co.paa
      \...\pilots\default\INT_co.paa
      \...\pilots\default\MID_co.paa
      \...\pilots\default\Visor_co.paa
  */

  CUSTOM_PILOT_HELM(penquite, "[12th][Pilot][Customs] Penquite",default,penquite,default,default,default)
  CUSTOM_PILOT_HELM(Moss, "[12th][Pilot][Customs] Moss",moss,moss,default,default,default)
  CUSTOM_PILOT_HELM(tomb, "[12th][Pilot][Customs] Tomb",tomb,tomb,default,default,default)

};

// -----------------------------------------------------------------------------
//  Extended Arsenal Integration
// -----------------------------------------------------------------------------
/*
  1) XtdGearModels: The top-level definitions for different helmet configs.
  2) XtdGearInfos:  Concrete expansions mapping each helmet name to its model, 
                    camo variant, and visor state (Yes or No).
*/
class XtdGearModels {
  class CfgWeapons {
    class twelfth_custom_helms {
      label="12th Custom Infantry Helmets";
      options[]= {"closed","camo","member"};
      class camo {
        alwaysSelectable=1;
        label="Camouflage";
        values[]={"std"};
        class std {label="Standard";};
      };
      class closed {
        alwaysSelectable=1;
        label="Closed";
        values[]={"Yes", "No"};
      };
      class member {
        alwaysSelectable=1;
        label="Member";
        values[]={
          "Abrams",
          "Aurora",
          "Bateman",
          "Bert",
          "Bob",
          "Bobby",
          "Bretek",
          "Broad",
          "Bunge",
          "Burns",
          "Coady",
          "Clarke",
          "Deluge",
          "Dennis",
          "Dixie",
          "Dom",
          "Don",
          "Dras",
          "Duckworth",
          "Felix",
          "Gallegos",
          "Galvin",
          "Geoff",
          "Germain",
          "Hathaway",
          "Jekyll",
          "Kiens",
          "LeDoux",
          "Link",
          "Luerssen",
          "Luke",
          "Mackle",
          "McMillian",
          "Mcintyre",
          "Mercer",
          "Moss",
          "Nightingale",
          "Oliver",
          "Origami",
          "Perry",
          "Quinn",
          "Quiggle",
          "Quebec",
          "Quinn",
          "Rex",
          "Sand",
          "Sammy",
          "Sand",
          "Schultz",
          "Shepard",
          "Simmons",
          "Spector",
          "Smitty",
          "Stacker",
          "Styx",
          "Sullivan",
          "Taji",
          "Thomson",
          "Thomas",
          "Vickers",
          "Whirley",
          "Wilson",
          "Wolffe",
          "Wulf"
        };
      };
    };
  };
};

class XtdGearInfos {
  /*
      The macro CH_HELM_S_GI(SFX) => expands to references for both standard
      (visor = "Yes") and NV (visor = "No") for each name in "member".
    */
  class CfgWeapons {
    CH_HELM_S_GI(Abrams)
    CH_HELM_S_GI(Aurora)
    CH_HELM_S_GI(Bateman)
    CH_HELM_S_GI(Bert)
    CH_HELM_S_GI(Bob)
    CH_HELM_S_GI(Bobby)
    CH_HELM_S_GI(Bretek)
    CH_HELM_S_GI(Broad)
    CH_HELM_S_GI(Burns)
    CH_HELM_S_GI(Bunge)
    CH_HELM_S_GI(Coady)
    CH_HELM_S_GI(Clarke)
    CH_HELM_S_GI(Dennis)
    CH_HELM_S_GI(Deluge)
    CH_HELM_S_GI(Dom)
    CH_HELM_S_GI(Don)
    CH_HELM_S_GI(Dras)
    CH_HELM_S_GI(Duckworth)
    CH_HELM_S_GI(Dixie)
    CH_HELM_S_GI(Felix)
    CH_HELM_S_GI(Gallegos)
    CH_HELM_S_GI(Galvin)
    CH_HELM_S_GI(Geoff)
    CH_HELM_S_GI(Germain)
    CH_HELM_S_GI(Hathaway)
    CH_HELM_S_GI(Jekyll)
    CH_HELM_S_GI(Kiens)
    CH_HELM_S_GI(LeDoux)
    CH_HELM_S_GI(Link)
    CH_HELM_S_GI(Luerssen)
    CH_HELM_S_GI(Luke)
    CH_HELM_S_GI(Nightingale)
    CH_HELM_S_GI(Mackle)
    CH_HELM_S_GI(Mercer)
    CH_HELM_S_GI(Moss)
    CH_HELM_S_GI(Mcintyre)
    CH_HELM_S_GI(McMillian)
    CH_HELM_S_GI(Oliver)
  	CH_HELM_S_GI(Origami)
    CH_HELM_S_GI(Perry)
    CH_HELM_S_GI(Quebec)
	  CH_HELM_S_GI(Quinn)
    CH_HELM_S_GI(Quiggle)
  	CH_HELM_S_GI(Rex)
    CH_HELM_S_GI(Schultz)
    CH_HELM_S_GI(Sand)
    CH_HELM_S_GI(Sammy)
	  CH_HELM_S_GI(Shepard) 
    CH_HELM_S_GI(Simmons)
    CH_HELM_S_GI(Sullivan)
    CH_HELM_S_GI(Spector)
    CH_HELM_S_GI(Smitty)
    CH_HELM_S_GI(Stacker)
    CH_HELM_S_GI(Styx)
    CH_HELM_S_GI(Taji)
    CH_HELM_S_GI(Thomson)
    CH_HELM_S_GI(Thomas)
    CH_HELM_S_GI(Vickers)
    CH_HELM_S_GI(Wilson)
    CH_HELM_S_GI(Wolffe)
    CH_HELM_S_GI(Whirley)
    CH_HELM_S_GI(Wulf)
  };
};
