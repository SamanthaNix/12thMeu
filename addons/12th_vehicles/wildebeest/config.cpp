#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_wildebeest {
    units[] = {
      "twelfth_wildebeest"
    };
    requiredVersion = 0.1;
  };
};

class CfgVehicles {
  // Wildebeest
  class OPTRE_M125_APC_Base;

  // -WILDEBEEST------------------------------------------------------

  class twelfth_wildebeest: OPTRE_M125_APC_Base {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    author = "Waylen";
    displayName = "[12th] M125 Wildebeest";
    faction = "twelfth_MEU";
    editorCategory = "twelfth_MEU";
    editorSubcategory = "twelfth_MEU_Armor";

    armor = 350;
    waterSpeedFactor = 1;
    enginePower = 1000;
    engineShiftY = -0.1;
    maxFordingDepth = 0.1;
    waterResistanceCoef = 0.1;
  };
};