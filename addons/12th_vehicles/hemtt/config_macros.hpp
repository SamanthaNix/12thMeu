#include "..\config_macros.hpp"

#define HEMTT_TEXPATH(BASE, CAMO3) \x\12thMEU\addons\12th_vehicles\hemtt\##BASE\##CAMO3

#define HEMTT_3(SP_PRI,SP_TYPE,CLASS,BASE_CLASS,DISPLAY,CAMO3) \
class CLASS: BASE_CLASS { \
  scope=2; \
  scopeCurator=2; \
  author="Waylen"; \
  displayName=DISPLAY; \
  vehicleClass="OPTRE_UNSC_Vehicle_class"; \
  faction="twelfth_MEU"; \
  editorCategory="twelfth_MEU"; \
  editorSubcategory="twelfth_MEU_Cars"; \
  class TransportItems {}; \
  class TransportMagazines {}; \
  class TransportWeapons {}; \
  hiddenSelections[]= {"camo1", "camo2", "camo3"}; \
  HEMTT_SP_INFO(SP_PRI,SP_TYPE) \
  hiddenSelectionsTextures[]= { \
    #HEMTT_TEXPATH(default,ext_01_co.paa), \
    #HEMTT_TEXPATH(default,ext_02_co.paa), \
    #HEMTT_TEXPATH(default,CAMO3) \
  }; \
  class textureSources { \
    class twelfth_hemtt_tex_default { \
      displayName="Default"; \
      author="Weber"; \
      textures[]= { \
        #HEMTT_TEXPATH(default,ext_01_co.paa), \
        #HEMTT_TEXPATH(default,ext_02_co.paa), \
        #HEMTT_TEXPATH(default,CAMO3) \
      }; \
    }; \
  }; \
};

#define HEMTT_4(SP_PRI,SP_TYPE,CLASS,BASE_CLASS,DISPLAY,CAMO3,CAMO4)  \
class CLASS: BASE_CLASS {   \
  scope=2;  \
  scopeCurator=2;   \
  author="Waylen";  \
  displayName=DISPLAY;  \
  vehicleClass="OPTRE_UNSC_Vehicle_class";  \
  faction="twelfth_MEU";  \
  editorCategory="twelfth_MEU";   \
  editorSubcategory="twelfth_MEU_Cars";   \
  class TransportItems {};  \
  class TransportMagazines {};  \
  class TransportWeapons {};  \
  hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4"};   \
  HEMTT_SP_INFO(SP_PRI,SP_TYPE)   \
  hiddenSelectionsTextures[]= {   \
    #HEMTT_TEXPATH(default,ext_01_co.paa),  \
    #HEMTT_TEXPATH(default,ext_02_co.paa),  \
    #HEMTT_TEXPATH(default,CAMO3),  \
    #HEMTT_TEXPATH(default,CAMO4)   \
  };  \
  class textureSources {  \
    class twelfth_hemtt_tex_default {   \
      displayName="Default";  \
      author="Weber";   \
      textures[]= {   \
        #HEMTT_TEXPATH(default,ext_01_co.paa),  \
        #HEMTT_TEXPATH(default,ext_02_co.paa),  \
        #HEMTT_TEXPATH(default,CAMO3),  \
        #HEMTT_TEXPATH(default,CAMO4)   \
      };  \
    };  \
  };  \
};
