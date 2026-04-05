#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_lynx {
    units[] = {
      "twelfth_lynx"
    };
    requiredVersion = 0.1;
  };
};

class CfgVehicles {
  // Lynx
  class I_LT_01_cannon_F;

    // LYNX ------------------------------------------------------------
  class twelfth_lynx: I_LT_01_cannon_F {
    side=1;
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Lynx";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Armor";
    class TransportItems {};
    class TransportMagazines {};
    class TransportWeapons {};
    LYNX_SP_INFO(0,Base)
    hiddenSelections[]={"Camo1", "Camo2"};
    hiddenSelectionsTextures[] = {
      QP(lynx\default\main_co.paa),
      QP(lynx\default\cannon_co.paa)
    };
    class textureSources {
      class default {
        displayName="Default";
        author="Wolfe";
        textures[] = {
          QP(lynx\default\main_co.paa),
          QP(lynx\default\cannon_co.paa)
        };
      };
    };
  };
  
};
