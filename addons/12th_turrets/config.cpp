/*
  ==============================================================================
  config.cpp

  This file configures all custom turret assets for the 12th MEU mod. 
  We use a macro (DEFINE_TURRET) to reduce repetitive definitions for multiple
  turret variants (UNSC, Insurrectionist, CMA, etc.).

  Key Points:
    - CfgPatches: Identifies this addon, lists requiredAddons, and enumerates 
      the units it introduces.
    - Turret base classes: We reference OPTRE turret classes (e.g., OPTRE_Static_M41).
      Make sure your requiredAddons[] includes the mod that provides these base classes.
    - DEFINE_TURRET macro: Simplifies creation of new turret classes. It sets scope, 
      displayName, faction, etc.

  Macro usage example:
    DEFINE_TURRET(twelfth_Static_M41, 
                  OPTRE_Static_M41, 
                  "[12th] M41 LAAG Turret", 
                  "twelfth_MEU", 
                  "twelfth_MEU", 
                  "twelfth_MEU_Turrets")

  expands to:
    class twelfth_Static_M41 : OPTRE_Static_M41 {
      scope = 2;
      scopeCurator = 2;
      author = "Weber";
      displayName = "[12th] M41 LAAG Turret";
      faction = "twelfth_MEU";
      editorCategory = "twelfth_MEU";
      editorSubcategory = "twelfth_MEU_Turrets";
      armor = 200;
    };
  ==============================================================================
*/
// Suppress a known HEMTT warning about padded arguments in configs
#pragma hemtt suppress pw3_padded_arg config

class CfgPatches {
  class twelfth_Weapons_Turrets {
    /*
      units[]: This lists all classes recognized as units by the game (placeable
               in editor). If you add or remove turret classes, update them here.
    */
    units[] = {
      "twelfth_Static_M41",
      "twelfth_Static_Gauss",
      "twelfth_Static_ATGM",
      "twelfth_Static_AA",
      "twelfth_Static_M41_Ins",
      "twelfth_Static_AA_Ins",
      "twelfth_Static_ATGM_Ins",
      "twelfth_Static_Gauss_CMA",
      "twelfth_Static_M41_CMA",
      "twelfth_Static_AA_CMA",
      "twelfth_Static_ATGM_CMA"
    };
    weapons[] = {};
    ammo[] = {};
    magazines[] = {};
    requiredVersion = 0.1;
    requiredAddons[] = {
      "OPTRE_Weapons_Turrets",
      "A3_Weapons_F",
      "A3_Weapons_F_Exp"
    /*
      requiredAddons: The mod will not load unless these are present.
      - OPTRE_Weapons_Turrets: Contains the base turret classes 
        (OPTRE_Static_M41, etc.)
      - A3_Weapons_F, A3_Weapons_F_Exp: Typically needed for certain inherited
        parameters or references in Arma 3.
    */
    };
  };
};

// -----------------------------------------------------------------------------
//  Pre-declare base classes from OPTRE so we can inherit from them
// -----------------------------------------------------------------------------
class OPTRE_Static_M41;
class OPTRE_Static_Gauss;
class OPTRE_Static_ATGM;
class OPTRE_Static_AA;
class OPTRE_Static_M41_Ins;
class OPTRE_Static_AA_Ins;
class OPTRE_Static_ATGM_Ins;
class OPTRE_Static_Gauss_Ins;
class OPTRE_Static_Gauss_CMA;
class OPTRE_Static_M41_CMA;
class OPTRE_Static_AA_CMA;
class OPTRE_Static_ATGM_CMA;

// -----------------------------------------------------------------------------
//  Macro: DEFINE_TURRET
//  Creates a new turret class inheriting from a base class, with scope, display, 
//  faction, and armor set.
// -----------------------------------------------------------------------------
#define DEFINE_TURRET(CLASSNAME, BASECLASS, DISPLAY, FACTION, CATEGORY, SUBCATEGORY) \
  class CLASSNAME : BASECLASS { \
    scope = 2; \
    scopeCurator = 2; \
    author = "Weber"; \
    displayName = DISPLAY; \
    faction = FACTION; \
    editorCategory = CATEGORY; \
    editorSubcategory = SUBCATEGORY; \
    armor = 200; \
  };

// -----------------------------------------------------------------------------
//  CfgVehicles
//  Where we define actual turret classes using our macro. 
// -----------------------------------------------------------------------------
class CfgVehicles {
  // -------------------- UNSC Turrets --------------------
  DEFINE_TURRET(twelfth_Static_M41, OPTRE_Static_M41, "[12th] M41 LAAG Turret", "twelfth_MEU", "twelfth_MEU", "twelfth_MEU_Turrets")
  DEFINE_TURRET(twelfth_Static_Gauss, OPTRE_Static_Gauss, "[12th] M41 Gauss Turret", "twelfth_MEU", "twelfth_MEU", "twelfth_MEU_Turrets")
  DEFINE_TURRET(twelfth_Static_ATGM, OPTRE_Static_ATGM, "[12th] M41 ATGM Turret", "twelfth_MEU", "twelfth_MEU", "twelfth_MEU_Turrets")
  DEFINE_TURRET(twelfth_Static_AA, OPTRE_Static_AA, "[12th] M41 AA Turret", "twelfth_MEU", "twelfth_MEU", "twelfth_MEU_Turrets")

  // ----------------- Insurrectionist Turrets -----------------
  DEFINE_TURRET(twelfth_Static_M41_Ins, OPTRE_Static_M41_Ins, "[12th] M41 LAAG Turret (Insurrectionist)", "twelfth_MEU_Ins", "twelfth_MEU_Ins", "twelfth_MEU_INS_Turrets")
  DEFINE_TURRET(twelfth_Static_Gauss_Ins, OPTRE_Static_Gauss_Ins, "[12th] M41 Gauss Turret (Insurrectionist)", "twelfth_MEU_Ins", "twelfth_MEU_Ins", "twelfth_MEU_INS_Turrets")
  DEFINE_TURRET(twelfth_Static_ATGM_Ins, OPTRE_Static_ATGM_Ins, "[12th] M41 ATGM Turret (Insurrectionist)", "twelfth_MEU_Ins", "twelfth_MEU_Ins", "twelfth_MEU_INS_Turrets")
  DEFINE_TURRET(twelfth_Static_AA_Ins, OPTRE_Static_AA_Ins, "[12th] M41 AA Turret (Insurrectionist)", "twelfth_MEU_Ins", "twelfth_MEU_Ins", "twelfth_MEU_INS_Turrets")

  // -------------------- CMA Turrets --------------------
  DEFINE_TURRET(twelfth_Static_M41_CMA, OPTRE_Static_M41_CMA, "[12th] M41 LAAG Turret (CMA)", "twelfth_MEU_CMA", "twelfth_MEU_CMA", "twelfth_MEU_CMA_Turrets")
  DEFINE_TURRET(twelfth_Static_Gauss_CMA, OPTRE_Static_Gauss_CMA, "[12th] M41 Gauss Turret (CMA)", "twelfth_MEU_CMA", "twelfth_MEU_CMA", "twelfth_MEU_CMA_Turrets")
  DEFINE_TURRET(twelfth_Static_ATGM_CMA, OPTRE_Static_ATGM_CMA, "[12th] M41 ATGM Turret (CMA)", "twelfth_MEU_CMA", "twelfth_MEU_CMA", "twelfth_MEU_CMA_Turrets")
  DEFINE_TURRET(twelfth_Static_AA_CMA, OPTRE_Static_AA_CMA, "[12th] M41 AA Turret (CMA)", "twelfth_MEU_CMA", "twelfth_MEU_CMA", "twelfth_MEU_CMA_Turrets")
};
