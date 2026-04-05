#include "..\config_macros.hpp"

#define TEMPEST_TEXPATH(BASE, PATH) \x\12thMEU\addons\12th_vehicles\tempest\##BASE\##PATH

#define TEMPEST_3(SP_PRI,SP_TYPE,CLASS,BASE_CLASS,DISPLAY,CAMO3) \
class CLASS: BASE_CLASS { \
  side=1; \
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
  TEMPEST_SP_INFO(SP_PRI,SP_TYPE) \
  hiddenSelections[]= {"camo1", "camo2", "camo3"}; \
  hiddenSelectionsTextures[]= { \
    #TEMPEST_TEXPATH(default,ext01_co.paa), \
    #TEMPEST_TEXPATH(default,ext02_co.paa), \
    #TEMPEST_TEXPATH(default,CAMO3) \
  }; \
  class textureSources { \
    class twelfth_tempest_tex_default { \
      displayName="Default"; \
      author="Weber"; \
      textures[]= { \
        #TEMPEST_TEXPATH(default,ext01_co.paa), \
        #TEMPEST_TEXPATH(default,ext02_co.paa), \
        #TEMPEST_TEXPATH(default,CAMO3) \
      }; \
    }; \
  }; \
};

#define TEMPEST_4(SP_PRI,SP_TYPE,CLASS,BASE_CLASS,DISPLAY,CAMO3,CAMO4) \
class CLASS: BASE_CLASS {                                              \
  side=1;                                                              \
  scope=2;                                                             \
  scopeCurator=2;                                                      \
  author="Waylen";                                                     \
  displayName=DISPLAY;                                                 \
  vehicleClass="OPTRE_UNSC_Vehicle_class";                             \
  faction="twelfth_MEU";                                               \
  editorCategory="twelfth_MEU";                                        \
  editorSubcategory="twelfth_MEU_Cars";                                \
  class TransportItems {};                                             \
  class TransportMagazines {};                                         \
  class TransportWeapons {};                                           \
  TEMPEST_SP_INFO(SP_PRI,SP_TYPE)                                      \
  hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4"};            \
  hiddenSelectionsTextures[]= {                                        \
    #TEMPEST_TEXPATH(default,ext01_co.paa),                            \
    #TEMPEST_TEXPATH(default,ext02_co.paa),                            \
    #TEMPEST_TEXPATH(default,CAMO3),                                   \
    #TEMPEST_TEXPATH(default,CAMO4)                                    \
  };                                                                   \
  class textureSources {                                               \
    class twelfth_tempest_tex_default {                                \
      displayName="Default";                                           \
      author="Weber";                                                  \
      textures[]= {                                                    \
        #TEMPEST_TEXPATH(default,ext01_co.paa),                         \
        #TEMPEST_TEXPATH(default,ext02_co.paa),                         \
        #TEMPEST_TEXPATH(default,CAMO3),                                \
        #TEMPEST_TEXPATH(default,CAMO4)                                 \
      };                                                                \
    };                                                                  \
  }; \
};

#define TEMPEST_5(SP_PRI,SP_TYPE,CLASS,BASE_CLASS,DISPLAY,CAMO3,CAMO4,CAMO5) \
class CLASS: BASE_CLASS {                                                     \
  side=1;                                                                     \
  scope=2;                                                                    \
  scopeCurator=2;                                                             \
  author="Waylen";                                                            \
  displayName=DISPLAY;                                                        \
  vehicleClass="OPTRE_UNSC_Vehicle_class";                                    \
  faction="twelfth_MEU";                                                      \
  editorCategory="twelfth_MEU";                                               \
  editorSubcategory="twelfth_MEU_Cars";                                       \
  class TransportItems {};                                                    \
  class TransportMagazines {};                                                \
  class TransportWeapons {};                                                  \
  TEMPEST_SP_INFO(SP_PRI,SP_TYPE)                                             \
  hiddenSelections[]= {"camo1", "camo2", "camo3", "camo4", "camo5"};          \
  hiddenSelectionsTextures[]= {                                               \
    #TEMPEST_TEXPATH(default,ext01_co.paa),                                   \
    #TEMPEST_TEXPATH(default,ext02_co.paa),                                   \
    #TEMPEST_TEXPATH(default,CAMO3),                                          \
    #TEMPEST_TEXPATH(default,CAMO4),                                          \
    #TEMPEST_TEXPATH(default,CAMO5)                                           \
  };                                                                          \
  class textureSources {                                                      \
    class twelfth_tempest_tex_default {                                       \
      displayName="Default";                                                  \
      author="Weber";                                                         \
      textures[]= {                                                           \
        #TEMPEST_TEXPATH(default,ext01_co.paa),                               \
        #TEMPEST_TEXPATH(default,ext02_co.paa),                               \
        #TEMPEST_TEXPATH(default,CAMO3),                                      \
        #TEMPEST_TEXPATH(default,CAMO4),                                      \
        #TEMPEST_TEXPATH(default,CAMO5)                                       \
      };                                                                    \
    };                                                                    \
  };                                                                    \
};
