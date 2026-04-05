/*
  ==============================================================================
  config_macros.hpp

  This file provides:
    - Path macros for referencing custom textures in 12th_aircraft.
    - `AIR_SP_INFO` for your custom vehicle spawn script integration.
    - Large macros (PELICAN_TEXTURESETS, FALCON_TEXTURESETS, etc.) 
      that define hiddenSelections[] + hiddenSelectionsTextures[] + 
      class textureSources. This simplifies the config for each vehicle.

  ==============================================================================
*/
#define P(PATH) \x\12thMEU\addons\12th_aircraft\##PATH
#define QP(PATH) #P(PATH)

// AIR_SP_INFO macro:
//  - Creates a "VehicleSpawnerInfo" class with sub-class twelfth_air_spawner. 
//  - Config values like priority, spawner name, type, and cost.
#define AIR_SP_INFO(VEH,PRI,TYPE) \
class VehicleSpawnerInfo {        \
  class twelfth_air_spawner {        \
    priority=PRI;                 \
    spawner = "12th Aircraft";    \
    scope = 1;                    \
    vehicle = #VEH;               \
    icon="";                      \
    type=#TYPE;                   \
    cost=0;                       \
  };                              \
};

// Macro: PELICAN_TEXTURESETS
//  - Sets hiddenSelections, hiddenSelectionsTextures, plus a textureSources class
//    to define multiple paint schemes (default, urban, ONI, etc.).
#define PELICAN_TEXTURESETS                       \
hiddenSelections[] = {                            \
  "camo1",                                        \
  "camo2",                                        \
  "camo3",                                        \
  "troop_bay",                                    \
  "doors",                                        \
  "hall_and_cockpit"                              \
};                                                \
hiddenSelectionsTextures[] = {                    \
  QP(pelican\default\body_co.paa),                \
  QP(pelican\default\wings_and_gear_co.paa),      \
  QP(pelican\default\weaponry_co.paa),            \
  QP(pelican\default\troop_bay_co.paa),           \
  QP(pelican\default\doors_co.paa),               \
  QP(pelican\default\hall_and_cockpit_co.paa)     \
};                                                \
class textureSources {                            \
  class twelfth_d77tc_tex_default {                  \
    displayName = "Default";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\default\body_co.paa),            \
      QP(pelican\default\wings_and_gear_co.paa),  \
      QP(pelican\default\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_urban {                  \
    displayName = "Urban";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\urban\body_co.paa),            \
      QP(pelican\urban\wings_and_gear_co.paa),  \
      QP(pelican\urban\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_splinter {                  \
    displayName = "Splinter Jungle";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\jsplinter\body_co.paa),            \
      QP(pelican\jsplinter\wings_and_gear_co.paa),  \
      QP(pelican\jsplinter\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_asg {                  \
    displayName = "Air Superiority Grey";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\asg\body_co.paa),            \
      QP(pelican\asg\wings_and_gear_co.paa),  \
      QP(pelican\asg\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_woodland {                  \
    displayName = "Woodland";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\woodland\body_co.paa),            \
      QP(pelican\woodland\wings_and_gear_co.paa),  \
      QP(pelican\woodland\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_oni {                  \
    displayName = "ONI";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\oni\body_co.paa),            \
      QP(pelican\oni\wings_and_gear_co.paa),  \
      QP(pelican\oni\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_police {                  \
    displayName = "Police";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\police\body_co.paa),            \
      QP(pelican\police\wings_and_gear_co.paa),  \
      QP(pelican\police\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_jotun {                  \
    displayName = "Jotun";                      \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\jotun\body_co.paa),            \
      QP(pelican\jotun\wings_and_gear_co.paa),  \
      QP(pelican\jotun\weaponry_co.paa),        \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
  class twelfth_d77tc_tex_winter {                   \
    displayName = "Winter";                       \
    author = "Weber";                            \
    textures[] = {                                \
      QP(pelican\winter\body_co.paa),             \
      QP(pelican\winter\wings_and_gear_co.paa),   \
      QP(pelican\winter\weaponry_co.paa),         \
      QP(pelican\default\troop_bay_co.paa),       \
      QP(pelican\default\doors_co.paa),           \
      QP(pelican\default\hall_and_cockpit_co.paa) \
    };                                            \
    factions[] = {"twelfth_MEU"};                    \
  };                                              \
};

//--------------------------------------------------------------------
// Falcon
//--------------------------------------------------------------------
#define FALCON_TEXTURESETS                   \
hiddenSelections[] = {"camo1", "camo2", "camo3", "camoGlass", "camoGlassPilot", "camoDecal"}; \
hiddenSelectionsTextures[] = {               \
    QP(falcon\default\main_co.paa),          \
    QP(falcon\default\attachments_co.paa),   \
    QP(falcon\default\interior_co.paa),      \
    "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa", \
		"\optre_vehicles_air\falcon\data\falcon_glass_ca.paa", \
		QP(falcon\default\empty.paa)      \
};                                           \
class textureSources {                       \
  class twelfth_falcon_tex_default {         \
    displayName = "Default";                 \
    author = "Waylen";                        \
    textures[] = {                           \
      QP(falcon\default\main_co.paa),        \
      QP(falcon\default\attachments_co.paa), \
      QP(falcon\default\interior_co.paa),\
      "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa", \
			"\optre_vehicles_air\falcon\data\falcon_glass_ca.paa", \
			QP(falcon\default\empty.paa) \
      };                                       \
    };                                         \
    class twelfth_falcon_tex_asg {         \
    displayName = "Air Superiority Grey";                 \
    author = "Wolfe";                        \
    textures[] = {                           \
      QP(falcon\asg\main_co.paa),        \
      QP(falcon\asg\attachments_co.paa), \
      QP(falcon\asg\interior_co.paa),\
      "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa", \
			"\optre_vehicles_air\falcon\data\falcon_glass_ca.paa", \
			QP(falcon\asg\empty.paa) \
      };                                       \
    };                                         \
  };                                          
//--------------------------------------------------------------------
// Sparrowhawk
//--------------------------------------------------------------------
#define SPARROWHAWK_TEXTURESETS \
hiddenSelectionsTextures[]= { \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_01_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_02_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_03_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_04_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_05_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\autocannon_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\feed_autocannon_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\decal_01_co.paa", \
  "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\decal_01_co.paa" \
}; \
class textureSources { \
  class twelfth_sph_tex_default { \
     displayName="Default"; \
     author="Weber"; \
     textures[] = { \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_01_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_02_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_03_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_04_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_05_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\autocannon_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\feed_autocannon_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\decal_01_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\decal_01_co.paa" \
     }; \
     factions[] = {"twelfth_MEU"}; \
  }; \
  class twelfth_sph_tex_asg { \
     displayName="Air Superiority Grey"; \
     author="Weber"; \
     textures[] = { \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\asg\body_01_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\asg\body_02_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\asg\body_03_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\asg\body_04_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\body_05_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\asg\autocannon_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\asg\feed_autocannon_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\decal_01_co.paa", \
       "\x\12thMEU\addons\12th_aircraft\sparrowhawk\default\decal_01_co.paa" \
     }; \
     factions[] = {"twelfth_MEU"}; \
  }; \
}; \
textureList[] = { \
  "twelfth_sph_tex_default", 1, \
  "twelfth_sph_tex_asg", 1 \
};
//--------------------------------------------------------------------
// Blackfish
//--------------------------------------------------------------------
#define BLACKFISH_TEXTURESETS \
hiddenSelections[]={"Camo_1", "Camo_2", "Camo_3", "Camo_4", "Camo_5"}; \
hiddenSelectionsTextures[]={ \
  QP(blackfish\default\ext01_co.paa), \
  QP(blackfish\default\ext02_co.paa), \
  QP(blackfish\default\ext03_co.paa), \
  QP(blackfish\default\ext04_co.paa), \
  QP(blackfish\default\signs_ca.paa) \
}; \
class textureSources { \
  class twelfth_blackfish_tex_default { \
    displayName="Default"; \
    author="Wolfe"; \
    textures[]= { \
      QP(blackfish\default\ext01_co.paa), \
      QP(blackfish\default\ext02_co.paa), \
      QP(blackfish\default\ext03_co.paa), \
      QP(blackfish\default\ext04_co.paa), \
      QP(blackfish\default\signs_ca.paa) \
    }; \
  }; \
  class twelfth_blackfish_tex_asg { \
    displayName="Air Superiority Grey"; \
    author="Wolfe"; \
    textures[]= { \
      QP(blackfish\asg\ext01_co.paa), \
      QP(blackfish\asg\ext02_co.paa), \
      QP(blackfish\asg\ext03_co.paa), \
      QP(blackfish\asg\ext04_co.paa), \
      QP(blackfish\default\signs_ca.paa) \
    }; \
  }; \
};
