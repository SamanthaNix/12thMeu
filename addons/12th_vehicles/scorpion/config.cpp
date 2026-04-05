#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_scorpion {
    units[] = {
      "twelfth_scorpion"
    };
  };
};

class CfgVehicles {
  // scorpion base classes
  class DMNS_M808B_F;

  //-SCORPIONS--------------------------------------------------------
  class twelfth_scorpion: DMNS_M808B_F {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] M808B Scorpion MBT";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Armor";
    hiddenSelections[]= {
      "camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6",
			"camo7",
			"camo8",
			"clan",
			"clan_text",
			"insignia"
    };
    SCORPION_TEXTURESET
    SCORPION_SP_INFO(0,Base)
  };

};
