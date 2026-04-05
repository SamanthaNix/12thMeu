#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_oryx {
    units[] = {
      "twelfth_oryx"
    };
  };
};

class CfgVehicles {
  class OPTRE_M494;

  //-ORYX-------------------------------------------------------------

  class twelfth_oryx: OPTRE_M494 {
    scope=2;
    scopeCurator=2;
    author="OPTRE; Waylen";
    displayName="[12th] M494 Oryx IFV";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Armor";
    ORYX_SP_INFO(0,Base)
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_vehicles\oryx\default\armor_co.paa",
      "\x\12thMEU\addons\12th_vehicles\oryx\default\main_co.paa",
      "\OPTRE_Vehicles_Tracked\Oryx\data\texture\oryx_net_ca.paa",
      "\OPTRE_Vehicles_Tracked\Oryx\data\texture\oryx_net_ca.paa",
      "\OPTRE_Vehicles_Tracked\Oryx\data\texture\oryx_net_ca.paa",
      "\x\12thMEU\addons\12th_vehicles\oryx\default\turret_co.paa",
      "\x\12thMEU\addons\12th_vehicles\oryx\default\mg_co.paa",
      "\x\12thMEU\addons\12th_vehicles\oryx\default\decal_co.paa",
      ""
    };
    class TextureSources {
      class twelfth_oryx_tex_default {
        displayName="Default";
        author="Waylen";
        textures[]= {
          "\x\12thMEU\addons\12th_vehicles\oryx\default\armor_co.paa",
          "\x\12thMEU\addons\12th_vehicles\oryx\default\main_co.paa",
          "\OPTRE_Vehicles_Tracked\Oryx\data\texture\oryx_net_ca.paa",
          "\OPTRE_Vehicles_Tracked\Oryx\data\texture\oryx_net_ca.paa",
          "\OPTRE_Vehicles_Tracked\Oryx\data\texture\oryx_net_ca.paa",
          "\x\12thMEU\addons\12th_vehicles\oryx\default\turret_co.paa",
          "\x\12thMEU\addons\12th_vehicles\oryx\default\mg_co.paa",
          "\x\12thMEU\addons\12th_vehicles\oryx\default\decal_co.paa",
          ""
        };
      };
    };
  };
};
