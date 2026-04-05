/*
  ==============================================================================
  config_macros.hpp

  This file contains:
    - Basic macros for backpack capacity (BP_MAXLOAD) and mass (BP_MASS).
    - Path macros (BP_TEXPATH, P, QP).
    - Display name macros (BP_DISP_*).
    - The main macros to generate backpack classes (BACKPACK_ALLTYPES, etc.).
    - XtdGear integration macros (ALL_GI, BACKPACK_GI).

  By using these macros, you can quickly add a new camouflage type by 
  just calling BACKPACK_ALLTYPES(<newCamo>, <DisplayName>) in config.cpp. 
  This drastically reduces repetitive code.
  ==============================================================================
*/

// Set the backpack capacity and weight
#define BP_MAXLOAD 425
#define BP_MASS 60

// Simple path building macros
#define P(PATH) \x\12thMEU\addons\12th_backpacks\##PATH
#define QP(PATH) #P(PATH)
#define QOUTE(s) #s
// For extended gear images referencing "xtd_icons\<SFX>.paa"
#define XTP(SFX) QP(xtd_icons\##SFX.paa)

// Macro for texture paths: e.g., \x\12thMEU\addons\12th_backpacks\backpack\<CAMOTYPE>\<FILE>.paa
#define BP_TEXPATH(CAMOTYPE,FILE) \x\12thMEU\addons\12th_backpacks\backpack\##CAMOTYPE\##FILE

// Macros for display names
#define BP_DISP(DISPLAY_TYPE) [12th][DISPLAY_TYPE] Backpack
#define BP_DISP_RTO(DISPLAY_TYPE) [12th][DISPLAY_TYPE][RTO] Backpack
#define BP_DISP_LIGHT(DISPLAY_TYPE) [12th][DISPLAY_TYPE][Light] Backpack
#define BP_DISP_HEAVY(DISPLAY_TYPE) [12th][DISPLAY_TYPE][Heavy] Backpack
#define BP_DISP_MEDIC(DISPLAY_TYPE) [12th][DISPLAY_TYPE][Medic] Backpack

// -----------------------------------------------------------------------------
//  XtdGear Macros
// -----------------------------------------------------------------------------
#define BACKPACK_GI(CAMOTYPE,TYPE) \
class twelfth_backpack_##TYPE##_##CAMOTYPE {  \
  model = "twelfth_backpacks";  \
  camo = #CAMOTYPE; \
  type = #TYPE; \
};  \

// Creates references for each of the 5 types under a given camo
#define ALL_GI(CAMO) \
BACKPACK_GI(CAMO,light) \
BACKPACK_GI(CAMO,na)      \
BACKPACK_GI(CAMO,heavy) \
BACKPACK_GI(CAMO,medic) \
BACKPACK_GI(CAMO,rto) \


// -----------------------------------------------------------------------------
//  Creation of actual backpack classes
// -----------------------------------------------------------------------------
/*
  BACKPACK_ALLTYPES(CAMOTYPE, DISPLAY_TYPE)
  Creates 5 classes:
    1) twelfth_backpack_na_<CAMOTYPE>     -> [12th][DISPLAY_TYPE] Backpack
       ("NO" extra pouches)

    2) twelfth_backpack_light_<CAMOTYPE>  -> [12th][DISPLAY_TYPE][Light] Backpack
       ("NO" pouches, "NO" roll)

    3) twelfth_backpack_heavy_<CAMOTYPE>  -> [12th][DISPLAY_TYPE][Heavy] Backpack
       (pouches + roll)

    4) twelfth_backpack_rto_<CAMOTYPE>    -> [12th][DISPLAY_TYPE][RTO] Backpack
       (radio attached)

    5) twelfth_backpack_medic_<CAMOTYPE>  -> [12th][DISPLAY_TYPE][Medic] Backpack
       (uses medic_ca.paa for the texture)

  Each backpack inherits from twelfth_backpack_base and sets hiddenSelectionsTextures
  accordingly to show/hide certain pouches or rolls.
*/
#define BACKPACK_ALLTYPES(CAMOTYPE, DISPLAY_TYPE)                          \
class twelfth_backpack_na_##CAMOTYPE : twelfth_backpack_base {                \
  scope=2;                                                                 \
  scopeArsenal=2;                                                          \
  displayName=#BP_DISP(DISPLAY_TYPE);                                      \
  hiddenSelectionsTextures[]={                                             \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    "",                                                                    \
    ""                                                                     \
  };                                                                       \
};                                                                         \
class twelfth_backpack_light_##CAMOTYPE : twelfth_backpack_base {          \
  scope=2;                                                                 \
  scopeArsenal=2;                                                          \
  displayName=#BP_DISP_LIGHT(DISPLAY_TYPE);                                \
  hiddenSelectionsTextures[]={                                             \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    "",                                                                    \
    "",                                                                    \
    ""                                                                     \
  };                                                                       \
};                                                                         \
class twelfth_backpack_heavy_##CAMOTYPE : twelfth_backpack_base {          \
  scope=2;                                                                 \
  scopeArsenal=2;                                                          \
  displayName=#BP_DISP_HEAVY(DISPLAY_TYPE);                                \
  hiddenSelectionsTextures[]={                                             \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    ""                                                                     \
  };                                                                       \
};                                                                         \
class twelfth_backpack_rto_##CAMOTYPE : twelfth_backpack_base {            \
  scope=2;                                                                 \
  scopeArsenal=2;                                                          \
  displayName=#BP_DISP_RTO(DISPLAY_TYPE);                                  \
  hiddenSelectionsTextures[]={                                             \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa),                                     \
    #BP_TEXPATH(CAMOTYPE,main_ca.paa)                                      \
  };                                                                       \
};                                                                         \
class twelfth_backpack_medic_##CAMOTYPE : twelfth_backpack_base {          \
  scope=2;                                                                 \
  scopeArsenal=2;                                                          \
  displayName=#BP_DISP_MEDIC(DISPLAY_TYPE);                                \
  hiddenSelectionsTextures[]={                                             \
    #BP_TEXPATH(CAMOTYPE,medic_ca.paa),                                    \
    #BP_TEXPATH(CAMOTYPE,medic_ca.paa),                                    \
    #BP_TEXPATH(CAMOTYPE,medic_ca.paa),                                    \
    ""                                                                     \
  };                                                                       \
};                                                                         \



/*

Pouch definitons

*/
#define TCP_CLASS_DEF_NORM(ROLE,NUMBER)\
class TCP_B_##ROLE##_##NUMBER##_Brown;\
class TCP_B_##ROLE##_##NUMBER##_Brown_M43A;\
class TCP_B_##ROLE##_##NUMBER##_Brown_M43A1;\
class Twelfth_##ROLE##_##NUMBER##_Brown : TCP_B_##ROLE##_##NUMBER##_Brown{\
    scopeArsenal=2;\
    scope=2;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_Brown_M43A : TCP_B_##ROLE##_##NUMBER##_Brown_M43A{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_Brown_M43A1 : TCP_B_##ROLE##_##NUMBER##_Brown_M43A1{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_Brown); \
		};\
};\

#define TCP_CLASS_DEF_NORM_PACK(ROLE,NUMBER,PACK)\
class TCP_B_##ROLE##_##NUMBER##_##PACK##_Brown;\
class TCP_B_##ROLE##_##NUMBER##_##PACK##_Brown_M43A;\
class TCP_B_##ROLE##_##NUMBER##_##PACK##_Brown_M43A1;\
class Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown : TCP_B_##ROLE##_##NUMBER##_##PACK##_Brown{\
    scopeArsenal=2;\
    scope=2;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown_M43A : TCP_B_##ROLE##_##NUMBER##_##PACK##_Brown_M43A{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown_M43A1 : TCP_B_##ROLE##_##NUMBER##_##PACK##_Brown_M43A1{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown); \
		};\
};

#define TCP_CLASS_DEF_NORM_BACKPACK(ROLE,NUMBER,BACKPACKTYPE)\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown_M43A;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown_M43A1;\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown{\
    scopeArsenal=2;\
    scope=2;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown_M43A : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown_M43A{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown_M43A1 : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown_M43A1{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown); \
		};\
};



#define TCP_CLASS_DEF_NORM_BACKPACK_ADDON(ROLE,NUMBER,BACKPACKTYPE,ADDON)\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown_M43A;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown_M43A1;\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown{\
    scopeArsenal=2;\
    scope=2;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown_M43A : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown_M43A{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown_M43A1 : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown_M43A1{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown); \
		};\
};



#define TCP_CLASS_DEF_NORM_BACKPACK_PACK(ROLE,NUMBER,BACKPACKTYPE,PACK)\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown_M43A;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown_M43A1;\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown{\
    scopeArsenal=2;\
    scope=2;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown_M43A : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown_M43A{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown_M43A1 : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown_M43A1{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown); \
		};\
};

#define TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(ROLE,NUMBER,BACKPACKTYPE,PACK,ADDON)\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown_M43A;\
class TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown_M43A1;\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown : TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown{\
    scopeArsenal=2;\
    scope=2;\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown_M43A :TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown_M43A{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown); \
		};\
};\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown_M43A1 :TCP_B_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown_M43A1{\
    scopeArsenal=1;\
    scope=1;\
    author="Sammy";\
    maximumLoad = BP_MAXLOAD;\
    mass = BP_MASS;\
    ace_arsenal_uniqueBase = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown); \
    class TCP_equipmentTypes: TCP_equipmentTypes \
		{ \
			baseEquipment = QOUTE(Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown); \
		};\
};



#define TCP_CLASS_DEF \
TCP_CLASS_DEF_NORM(Ammo_Bearer,1)\
TCP_CLASS_DEF_NORM(Assaulter,1)\
TCP_CLASS_DEF_NORM(Assaulter,2)\
TCP_CLASS_DEF_NORM(Autorifleman,1)\
TCP_CLASS_DEF_NORM(Autorifleman,2)\
TCP_CLASS_DEF_NORM(Breacher,1)\
TCP_CLASS_DEF_NORM(Engineer,1)\
TCP_CLASS_DEF_NORM(Grenadier,1)\
TCP_CLASS_DEF_NORM(Grenadier,2)\
TCP_CLASS_DEF_NORM(Marksman,1)\
TCP_CLASS_DEF_NORM(Marksman,2)\
TCP_CLASS_DEF_NORM(Marksman,3)\
TCP_CLASS_DEF_NORM(Medic,1)\
TCP_CLASS_DEF_NORM(Medic,2)\
TCP_CLASS_DEF_NORM(NCO,1)\
TCP_CLASS_DEF_NORM(NCO,2)\
TCP_CLASS_DEF_NORM(NCO,3)\
TCP_CLASS_DEF_NORM(Rifleman,1)\
TCP_CLASS_DEF_NORM(Rifleman,2)\
TCP_CLASS_DEF_NORM(Rifleman,3)\
TCP_CLASS_DEF_NORM(Rifleman,4)\
TCP_CLASS_DEF_NORM(Rifleman,5)\
TCP_CLASS_DEF_NORM(Rifleman,6)\
TCP_CLASS_DEF_NORM(Rifleman,7)\
TCP_CLASS_DEF_NORM(RTO,1)\
TCP_CLASS_DEF_NORM(Sapper,1)\
TCP_CLASS_DEF_NORM(Sniper,1)\
TCP_CLASS_DEF_NORM(Sniper,2)\
TCP_CLASS_DEF_NORM_PACK(Ammo_Bearer,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Assaulter,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Assaulter,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Autorifleman,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Autorifleman,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Breacher,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Engineer,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Grenadier,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Grenadier,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Marksman,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Marksman,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Marksman,3,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Medic,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Medic,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(NCO,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(NCO,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(NCO,3,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,3,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,4,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,5,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,6,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,7,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(RTO,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Sapper,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Sniper,1,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Sniper,2,M2_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Ammo_Bearer,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Assaulter,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Assaulter,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Autorifleman,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Autorifleman,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Breacher,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Engineer,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Grenadier,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Grenadier,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Marksman,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Marksman,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Marksman,3,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Medic,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Medic,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(NCO,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(NCO,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(NCO,3,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,3,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,4,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,5,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,6,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Rifleman,7,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(RTO,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Sapper,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Sniper,1,M35_Buttpack)\
TCP_CLASS_DEF_NORM_PACK(Sniper,2,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK(Ammo_Bearer,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Assaulter,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Assaulter,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Autorifleman,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Autorifleman,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Breacher,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Engineer,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Grenadier,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Grenadier,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,3,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Medic,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Medic,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,3,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,3,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,4,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,5,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,6,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,7,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(RTO,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Sapper,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Sniper,1,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Sniper,2,ANPRC171)\
TCP_CLASS_DEF_NORM_BACKPACK(Ammo_Bearer,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Assaulter,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Assaulter,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Autorifleman,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Autorifleman,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Breacher,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Engineer,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Grenadier,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Grenadier,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,3,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Medic,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Medic,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,3,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,3,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,4,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,5,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,6,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,7,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(RTO,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Sapper,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Sniper,1,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK(Sniper,2,M43_Medium_Rucksack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,ANPRC171,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,ANPRC171,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,ANPRC171,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,ANPRC171,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,ANPRC171,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Field)



/*
TCP_CLASS_DEF_NORM_BACKPACK(Ammo_Bearer,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Assaulter,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Assaulter,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Autorifleman,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Autorifleman,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Breacher,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Engineer,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Grenadier,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Grenadier,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Marksman,3,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Medic,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Medic,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(NCO,3,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,3,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,4,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,5,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,6,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Rifleman,7,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(RTO,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Sapper,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Sniper,1,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK(Sniper,2,EM39_MLBE_Hardcase)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,Roll)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,M2_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,M35_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Ammo_Bearer,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Assaulter,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Autorifleman,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Breacher,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Engineer,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Grenadier,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Marksman,3,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Medic,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(NCO,3,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,3,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,4,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,5,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,6,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Rifleman,7,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(RTO,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sapper,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,1,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON(Sniper,2,EM39_MLBE_Hardcase,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,Roll,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
TCP_CLASS_DEF_NORM_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
*/

/*

Pouch Extended Arsenal

*/
#define POUCH_DEF_GI(ROLE,NUMBER)\
class Twelfth_##ROLE##_##NUMBER##_Brown {  \
  model = "twelfth_Pouches";  \
  role = #ROLE; \
  variant = #NUMBER; \
  backpack = "NO";\
  pack = "NO";\
  addon = "NO";\
};


#define POUCH_DEF_GI_PACK(ROLE,NUMBER,PACK)\
class Twelfth_##ROLE##_##NUMBER##_##PACK##_Brown {  \
  model = "twelfth_Pouches";  \
  role = #ROLE; \
  variant = #NUMBER; \
  backpack = "NO";\
  pack = #PACK;\
  addon = "NO";\
};

#define POUCH_DEF_GI_BACKPACK(ROLE,NUMBER,BACKPACKTYPE)\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_Brown {  \
  model = "twelfth_Pouches";  \
  role = #ROLE; \
  variant = #NUMBER; \
  backpack = #BACKPACKTYPE;\
  pack = "NO";\
  addon = "NO";\
};

#define POUCH_DEF_GI_BACKPACK_ADDON(ROLE,NUMBER,BACKPACKTYPE,ADDON)\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_Brown {  \
  model = "twelfth_Pouches";  \
  role = #ROLE; \
  variant = #NUMBER; \
  backpack = #BACKPACKTYPE;\
  pack = "NO";\
  addon = #ADDON;\
};

#define POUCH_DEF_GI_BACKPACK_PACK(ROLE,NUMBER,BACKPACKTYPE,PACK)\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##PACK##_Brown {  \
  model = "twelfth_Pouches";  \
  role = #ROLE; \
  variant = #NUMBER; \
  backpack = #BACKPACKTYPE;\
  pack = #PACK;\
  addon = "NO";\
};

#define POUCH_DEF_GI_BACKPACK_ADDON_PACK(ROLE,NUMBER,BACKPACKTYPE,PACK,ADDON)\
class Twelfth_##ROLE##_##NUMBER##_##BACKPACKTYPE##_##ADDON##_##PACK##_Brown {  \
  model = "twelfth_Pouches";  \
  role = #ROLE; \
  variant = #NUMBER; \
  backpack = #BACKPACKTYPE;\
  pack = #PACK;\
  addon = #ADDON;\
};

/*
POUCH_DEF_GI_BACKPACK(Ammo_Bearer,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Assaulter,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Assaulter,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Autorifleman,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Autorifleman,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Breacher,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Engineer,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Grenadier,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Grenadier,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Marksman,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Marksman,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Marksman,3,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Medic,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Medic,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(NCO,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(NCO,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(NCO,3,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,3,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,4,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,5,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,6,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Rifleman,7,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(RTO,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Sapper,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Sniper,1,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK(Sniper,2,EM39_MLBE_Hardcase)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,EM39_MLBE_Hardcase,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,EM39_MLBE_Hardcase,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,EM39_MLBE_Hardcase,EM39_Buttpack,Patrol)\
*/



#define POUCH_GI\
POUCH_DEF_GI(Ammo_Bearer,1)\
POUCH_DEF_GI(Assaulter,1)\
POUCH_DEF_GI(Assaulter,2)\
POUCH_DEF_GI(Autorifleman,1)\
POUCH_DEF_GI(Autorifleman,2)\
POUCH_DEF_GI(Breacher,1)\
POUCH_DEF_GI(Engineer,1)\
POUCH_DEF_GI(Grenadier,1)\
POUCH_DEF_GI(Grenadier,2)\
POUCH_DEF_GI(Marksman,1)\
POUCH_DEF_GI(Marksman,2)\
POUCH_DEF_GI(Marksman,3)\
POUCH_DEF_GI(Medic,1)\
POUCH_DEF_GI(Medic,2)\
POUCH_DEF_GI(NCO,1)\
POUCH_DEF_GI(NCO,2)\
POUCH_DEF_GI(NCO,3)\
POUCH_DEF_GI(Rifleman,1)\
POUCH_DEF_GI(Rifleman,2)\
POUCH_DEF_GI(Rifleman,3)\
POUCH_DEF_GI(Rifleman,4)\
POUCH_DEF_GI(Rifleman,5)\
POUCH_DEF_GI(Rifleman,6)\
POUCH_DEF_GI(Rifleman,7)\
POUCH_DEF_GI(RTO,1)\
POUCH_DEF_GI(Sapper,1)\
POUCH_DEF_GI(Sniper,1)\
POUCH_DEF_GI(Sniper,2)\
POUCH_DEF_GI_PACK(Ammo_Bearer,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Assaulter,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Assaulter,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(Autorifleman,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Autorifleman,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(Breacher,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Engineer,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Grenadier,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Grenadier,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,3,M2_Buttpack)\
POUCH_DEF_GI_PACK(Medic,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Medic,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(NCO,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(NCO,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(NCO,3,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,3,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,4,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,5,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,6,M2_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,7,M2_Buttpack)\
POUCH_DEF_GI_PACK(RTO,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Sapper,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Sniper,1,M2_Buttpack)\
POUCH_DEF_GI_PACK(Sniper,2,M2_Buttpack)\
POUCH_DEF_GI_PACK(Ammo_Bearer,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Assaulter,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Assaulter,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(Autorifleman,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Autorifleman,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(Breacher,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Engineer,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Grenadier,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Grenadier,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,3,M35_Buttpack)\
POUCH_DEF_GI_PACK(Medic,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Medic,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(NCO,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(NCO,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(NCO,3,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,3,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,4,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,5,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,6,M35_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,7,M35_Buttpack)\
POUCH_DEF_GI_PACK(RTO,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Sapper,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Sniper,1,M35_Buttpack)\
POUCH_DEF_GI_PACK(Sniper,2,M35_Buttpack)\
POUCH_DEF_GI_PACK(Ammo_Bearer,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Assaulter,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Assaulter,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Autorifleman,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Autorifleman,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Breacher,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Engineer,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Grenadier,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Grenadier,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Marksman,3,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Medic,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Medic,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(NCO,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(NCO,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(NCO,3,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,2,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,3,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,4,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,5,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,6,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Rifleman,7,EM39_Buttpack)\
POUCH_DEF_GI_PACK(RTO,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Sapper,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Sniper,1,EM39_Buttpack)\
POUCH_DEF_GI_PACK(Sniper,2,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK(Ammo_Bearer,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Assaulter,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Assaulter,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Autorifleman,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Autorifleman,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Breacher,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Engineer,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Grenadier,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Grenadier,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Marksman,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Marksman,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Marksman,3,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Medic,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Medic,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(NCO,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(NCO,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(NCO,3,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,3,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,4,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,5,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,6,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Rifleman,7,ANPRC171)\
POUCH_DEF_GI_BACKPACK(RTO,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Sapper,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Sniper,1,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Sniper,2,ANPRC171)\
POUCH_DEF_GI_BACKPACK(Ammo_Bearer,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Assaulter,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Assaulter,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Autorifleman,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Autorifleman,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Breacher,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Engineer,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Grenadier,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Grenadier,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Marksman,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Marksman,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Marksman,3,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Medic,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Medic,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(NCO,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(NCO,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(NCO,3,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,3,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,4,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,5,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,6,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Rifleman,7,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(RTO,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Sapper,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Sniper,1,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK(Sniper,2,M43_Medium_Rucksack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,ANPRC171,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,Roll)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,ANPRC171,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,ANPRC171,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,ANPRC171,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,ANPRC171,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON(Ammo_Bearer,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Assaulter,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Autorifleman,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Breacher,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Engineer,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Grenadier,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Marksman,3,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Medic,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(NCO,3,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,3,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,4,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,5,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,6,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Rifleman,7,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(RTO,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Sapper,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,1,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON(Sniper,2,M43_Medium_Rucksack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,ANPRC171,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Patrol)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Assault)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Engineer)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Medical)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,Roll,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M2_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,M35_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Ammo_Bearer,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Assaulter,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Autorifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Breacher,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Engineer,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Grenadier,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Marksman,3,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Medic,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(NCO,3,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,2,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,3,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,4,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,5,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,6,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Rifleman,7,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(RTO,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sapper,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,1,M43_Medium_Rucksack,EM39_Buttpack,Field)\
POUCH_DEF_GI_BACKPACK_ADDON_PACK(Sniper,2,M43_Medium_Rucksack,EM39_Buttpack,Field)




