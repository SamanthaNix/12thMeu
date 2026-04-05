/*
  ==============================================================================
  config.cpp

  This file establishes the 12th MEU factions, editor categories, and subcategories
  for use in the Eden Editor. It defines three factions: 12th MEU (BLUFOR),
  Insurrection (OPFOR), and CMA (INDEPENDENT), each with its own sets of subcategories
  (cars, turrets, supplies, etc.).

  Key Points:
    - CfgPatches: Basic mod info (units, weapons, requiredAddons).
    - CfgFactionClasses: Creates the 12th MEU factions. You can add a faction icon
      later for each, if desired.
    - CfgEditorCategories: Top-level categories used in Eden (like "12th Marine
      Expeditionary Unit").
    - CfgEditorSubcategories: More specific groupings for vehicles, turrets, supplies,
      etc., under the top-level category.

  NOTE: For these factions/categories to appear in Eden, ensure you reference them
  in your vehicles or units (e.g., `faction = "twelfth_MEU"; editorCategory = "twelfth_MEU";`).
  ==============================================================================
*/

// Basic mod info and dependencies
class CfgPatches {
  class twelfth_faction_data {
    units[] = {};  // No units defined yet.
    weapons[] = {};  // No weapons defined yet.
    requiredVersion = 0.1;  // Minimum required game version.
    requiredAddons[] = {"A3_Characters_F_BLUFOR"};  // Dependencies.
  };
};

/*
  ==============================================================================
  CfgFactionClasses
  ==============================================================================
  Creates the actual factions: 12th MEU, 12th Insurrection, 12th CMA. 
  - displayName: How it shows up in lists.
  - icon: Path to a faction icon (paa or png). Example: "x\12thMEU\path\icon.paa".
  - side: 1 = BLUFOR, 2 = OPFOR, 3 = Independent, 4 = Civilian.

  priority: The engine uses this to decide sort order. Higher = displayed first.
*/
class CfgFactionClasses {
  class twelfth_MEU {
    displayName = "12th Marine Expeditionary Unit";
    icon="";  // TODO: Add faction icon.
    author="Weber";
    priority=99;  // High priority to ensure it appears at the top of the list.
    side=1;  // Blufor (friendly) side.
  };
  class twelfth_MEU_Ins {
    displayName="12th Insurrection Assets";
    icon="";  // TODO: Add faction icon.
    author="Weber";
    priority=99;
    side=2;  // Opfor (enemy) side.
  };
  class twelfth_MEU_CMA {
    displayName="12th CMA Assets";
    icon="";  // TODO: Add faction icon.
    author="Weber";
    priority=99;
    side=3;  // Independent side.
  };
};

/*
  ==============================================================================
  CfgEditorCategories
  ==============================================================================
  These are the "top-level" folders in the Eden Editor for objects belonging
  to our 12th MEU faction. For instance, "twelfth_MEU" will appear as a main
  category with subcategories (like "twelfth_MEU_Cars").
*/
class CfgEditorCategories {
  class twelfth_MEU {
    displayName="12th Marine Expeditionary Unit";
    priority=99;  // High priority for easy access.
    side=1;  // Blufor (friendly) side.
  };
  class twelfth_MEU_Ins {
    displayName="12th Insurrection Assets";
    priority=99;
    side=2;  // Opfor (enemy) side.
  };
  class twelfth_MEU_CMA {
    displayName="12th CMA Assets";
    priority=99;
    side=3;  // Independent side.
  };
};

/*
  ==============================================================================
  CfgEditorSubcategories
  ==============================================================================
  Subcategories under each main category. For example, "twelfth_MEU_Cars" can
  appear under "twelfth_MEU" if a vehicle is declared with 
    faction = "twelfth_MEU";
    editorCategory = "twelfth_MEU";
    editorSubcategory = "twelfth_MEU_Cars";
*/
class CfgEditorSubcategories {
  // 12th MEU Marine Assets
  class twelfth_MEU_Rotary {
    displayName="Rotary Aircraft";  // Rotary-wing aircraft (helicopters).
  };
  class twelfth_MEU_Cars {
    displayName="Cars";  // Ground vehicles (cars, trucks).
  };
  class twelfth_MEU_Armor {
    displayName="Armor";  // Armored vehicles (tanks, APCs).
  };
  class twelfth_MEU_Drones {
    displayName="Drones";  // Unmanned aerial vehicles (UAVs).
  };
  class twelfth_MEU_Supplies {
    displayName="Supplies";  // Supply and logistics assets.
  };
  class twelfth_MEU_FixedWing {
    displayName="Fixed Wing Aircraft";  // Fixed-wing aircraft (jets, planes).
  };
  class twelfth_MEU_Turrets {
    displayName="Turrets";  // Static defensive turrets.
  };

  // 12th Insurrection Assets
  class twelfth_MEU_INS_Turrets {
    displayName="Turrets";  // Static defensive turrets.
  };

  // 12th CMA Assets
  class twelfth_MEU_CMA_Turrets {
    displayName="Turrets";  // Static defensive turrets.
  };
};
