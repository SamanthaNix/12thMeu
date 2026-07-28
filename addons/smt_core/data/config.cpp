class CfgPatches {
  class SMT_core {
    units[] = {};
    weapons[] = {};
    ammo[] = {};
    magazines[] = {};
    requiredVersion = 0.1;    // Minimum required version of the game
    requiredAddons[] = {};
  };
};

class CfgFactionClasses {
  class SMT_Faction {
    displayName = "Sanguine Materials Technologies";
    icon="\x\12thMEU\addons\SMT_core\Data\logo.paa";  // TODO: Add faction icon.
    priority=98;  // High priority to ensure it appears at the top of the list.
    side=1;  // Blufor (friendly) side.
  };
};

class CfgEditorCategories {
  class ED_SMT_Faction {
    displayName="Sanguine Materials Technologies";
    priority=98;  // High priority for easy access.
    side=1;  // Blufor (friendly) side.
  };
};
