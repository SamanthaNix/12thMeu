/*
  ==============================================================================
  config_macros.hpp

  This file contains a comprehensive set of macros for creating uniforms, helmets,
  caps, boonie hats, etc. It leverages hiddenSelectionsTextures to define how 
  multiple camos and roles (e.g., medic, PL, etc.) are generated en masse.

  Key Macros:
    - ALL_UNI_VEH / ALL_UNI_WEP / ALL_UNI_GI to produce all platoon+role combos.
    - ALL_HELM / ALL_HELM_GI to produce multiple variations of a single helmet 
      in standard or NV variants.
    - BOONIE_WEP / PATROLCAP_WEP for boonie/patrol caps.
    - PILOT_HELM for custom pilot helmet references.

  Remember to look at the expansions near the bottom of config.cpp for usage:
    ALL_UNI_WEP(std), ALL_UNI_WEP(forest), etc.
  ==============================================================================
*/
#define P(PATH) \x\12thMEU\addons\12th_armor\##PATH
#define QP(PATH) #P(PATH)
#define GLUE(A,B) A##B
#define QOUTE(s) #s
#define PILOT_H_TEX(CAMOTYPE,FILENAME) P(helmets\pilot\##CAMOTYPE\##FILENAME)
#define nill 
#define EMPTY()  

#define UNIFORM_WEP_CLASSNAME(CAMO,PLATOON,ROLE) twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_veh
#define HELM_DEC_PATH tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\White\vest_M43_DecalSheet_CA.paa
#define UNIFORM_OLD_VEH_TEXPATH(SUFFIX) P(uniforms\armor_old\Uniform_co_##SUFFIX.paa)
#define UNIFORM_OLD_WEP_CLASSPATH(SUFFIX) twelfth_uni_##SUFFIX##_veh

#define TWELFTH_WEP_NORMAL(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_##CAMO##
#define TWELFTH_VEH_NORMAL(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_##CAMO##
//Bloused
#define TWELFTH_WEP_BLOUSED(CAMO,SHIRT,SLEEVE)  twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO##
#define TWELFTH_VEH_BLOUSED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO##
//Gloves
#define TWELFTH_WEP_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO##
#define TWELFTH_VEH_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO##
//Bloused_Gloves
#define TWELFTH_WEP_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO##
#define TWELFTH_VEH_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO##
//Unzipped
#define TWELFTH_WEP_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO##
#define TWELFTH_VEH_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO##
//Bloused_Unzipped
#define TWELFTH_WEP_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO##
#define TWELFTH_VEH_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO##
//Gloves_Unzipped
#define TWELFTH_WEP_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO##
#define TWELFTH_VEH_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO##
//GLOVES_BLOUSED_UNZIPPED
#define TWELFTH_WEP_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO##
#define TWELFTH_VEH_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO##

#define TWELFTH_REF_GENERIC_3(VARIANT,CAMO,arg1,arg2) twelfth_##VARIANT##_##arg1##_##arg2##_##CAMO##
#define TWELFTH_REF_GENERIC_4(VARIANT,CAMO,arg1,arg2,arg3) twelfth_##VARIANT##_##arg1##_##arg2##_##arg3##_##CAMO##
#define TWELFTH_REF_GENERIC_5(VARIANT,CAMO,arg1,arg2,arg3,arg4) twelfth_##VARIANT##_##arg1##_##arg2##_##arg3##_##arg4##_##CAMO##
#define TWELFTH_REF_GENERIC_6(VARIANT,CAMO,arg1,arg2,arg3,arg4,arg5) twelfth_##VARIANT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##CAMO##
#define TWELFTH_REF_GENERIC_7(VARIANT,CAMO,arg1,arg2,arg3,arg4,arg5,arg6) twelfth_##VARIANT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##arg6##_##CAMO

//                   ,~.
//                ,-'__ `-,
//               {,-'  `. }              ,')
//              ,( a )   `-.__         ,',')~,
//             <=.) (         `-.__,==' ' ' '}             
//               (   )                      /             
//                `-'\   ,                  )             
//                    |  \        `~.      /          
//   .                \   `._        \    /      
//       0 o           \     `._____,'   /             
//    O   .             `-.            ,'                
//      o                  `-.      ,-'               
//                            `~~~~'                
//  a hen offers you          //_||
//  some beans for the     __//--'/`          
//  journey ahead        ,--'/`  '
//                          '
//  they are not of the highest quality, 
//  but you are a dauntless, errant knight


#define HELM_TEX_PATH(SUFFIX) P(helmets\infantry\Helm_co_##SUFFIX.paa)
#define HELM_TEX_PATH_CH43A(SUFFIX) P(helmets\infantry\CH43A\Helm_co_##SUFFIX.paa)
#define CAP_TEX_PATH(SUFFIX) P(helmets\cap_b\cap_co_##SUFFIX.paa)

#define INF_UNI_DISP(CAMO,PLATOON,ROLE) [12th][INF][CAMO][PLATOON][ROLE] Armor

// stands for 'extended path', used to denote background image
// paths for extended arsenal icon backgrounds
#define XTP(SFX) QP(xtd_icons\##SFX.paa)

/* Stands for uniform gear info. */                                                                     

#define TSHIRT_NORMAL_GI(CAMO,TUCK) \
  class twelfth_U_B_TShirt_##TUCK##_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="no"; \
    tuck=#TUCK; \
    blouse="noblouse"; \
    kneepad="nokneepads"; \
  };\
  class twelfth_U_B_TShirt_##TUCK##_Kneepads_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="no"; \
    tuck=#TUCK; \
    blouse="noblouse"; \
    kneepad="kneepads"; \
  };

#define TSHIRT_BLOUSED_GI(CAMO,TUCK) \
  class twelfth_U_B_TShirt_##TUCK##_Bloused_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="no"; \
    tuck=#TUCK; \
    blouse="blouse"; \
    kneepad="nokneepads"; \
  };     \
  class twelfth_U_B_TShirt_##TUCK##_Bloused_Kneepads_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="no"; \
    tuck=#TUCK; \
    blouse="blouse"; \
    kneepad="kneepads"; \
  };                    

#define TSHIRT_GLOVES_GI(CAMO,TUCK) \
  class twelfth_U_B_TShirt_##TUCK##_Gloves_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="yes"; \
    tuck=#TUCK; \
    blouse="noblouse"; \
    kneepad="nokneepads"; \
  };     \
  class twelfth_U_B_TShirt_##TUCK##_Gloves_Kneepads_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="yes"; \
    tuck=#TUCK; \
    blouse="noblouse"; \
    kneepad="kneepads"; \
  };                                  

#define TSHIRT_BLOUSED_GLOVES_GI(CAMO,TUCK) \
  class twelfth_U_B_TShirt_##TUCK##_Gloves_Bloused_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="yes"; \
    tuck=#TUCK; \
    blouse="blouse"; \
    kneepad="nokneepads"; \
  };     \
  class twelfth_U_B_TShirt_##TUCK##_Gloves_Bloused_Kneepads_##CAMO## { \
    model="twelfth_tshirt"; \
    camo=#CAMO; \
    glove="yes"; \
    tuck=#TUCK; \
    blouse="blouse"; \
    kneepad="kneepads"; \
  };

//TCP CLASS DEFINITONS WEP
#define TCP_WEP_CLASS_GENERIC_2(arg1,arg2) \
  class TCP_U_B_CBUU_##arg1##_##arg2##_Base;

#define TCP_WEP_CLASS_GENERIC_3(arg1,arg2,arg3) \
  class TCP_U_B_CBUU_##arg1##_##arg2##_##arg3##_Base;

#define TCP_WEP_CLASS_GENERIC_4(arg1,arg2,arg3,arg4) \
  class TCP_U_B_CBUU_##arg1##_##arg2##_##arg3##_##arg4##_Base;

#define TCP_WEP_CLASS_GENERIC_5(arg1,arg2,arg3,arg4,arg5) \
  class TCP_U_B_CBUU_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_Base;

#define TCP_WEP_CLASS_GENERIC_6(arg1,arg2,arg3,arg4,arg5,arg6) \
  class TCP_U_B_CBUU_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##arg6##_Base;

//TCP CLASS DEFINITONS VEH
#define TCP_VEH_CLASS_GENERIC_2(arg1,arg2) \
  class TCP_B_CBUU_##arg1##_##arg2##_Base;

#define TCP_VEH_CLASS_GENERIC_3(arg1,arg2,arg3) \
  class TCP_B_CBUU_##arg1##_##arg2##_##arg3##_Base;

#define TCP_VEH_CLASS_GENERIC_4(arg1,arg2,arg3,arg4) \
  class TCP_B_CBUU_##arg1##_##arg2##_##arg3##_##arg4##_Base;

#define TCP_VEH_CLASS_GENERIC_5(arg1,arg2,arg3,arg4,arg5) \
  class TCP_B_CBUU_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_Base;

  #define TCP_VEH_CLASS_GENERIC_6(arg1,arg2,arg3,arg4,arg5,arg6) \
  class TCP_B_CBUU_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##arg6##_Base;

// Generic functions for handling VEH and WEP classes
// They differ by two digits at the end
// first is the amount of arguments (yes, it changed, i didnt update. Get mad, call the police)
// second is the variant, for 3, 2 and 1, defines how many hiddenSelectionTextures are used inside
// order of args: gloves, bloused, zip, kneepad
  #define CLASS_GENERIC_3_2(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_3(VARIANT2,CAMO,SHIRT,arg1));\
  };
  
  #define CLASS_GENERIC_3_1(VARIANT,VARIANT2,SCOPEVAL,CAMO,SHIRT,arg1) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_Base {\
      scope=#SCOPEVAL;\
      displayName="[12th] Uniform";\
      ACE_GForceCoef=0.4;\
      class TCP_equipmentTypes: TCP_equipmentTypes {\
        baseEquipment = QOUTE(twelfth_##VARIANT##_##SHIRT##_##arg1##_##CAMO##); \
      }; \
      class ItemInfo : ItemInfo {\
        uniformClass = QOUTE(TWELFTH_REF_GENERIC_3(VARIANT2,CAMO,SHIRT,arg1));\
        containerClass="Supply100"; \
        mass=1;\
        uniformType = "Neopren";\
        allowedSlots[]={"701","801","901"};\
        armor=20;\
      };\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
      };\
  };

  #define CLASS_GENERIC_4_3(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_4(VARIANT2,CAMO,SHIRT,arg1,arg2));\
  };

  #define CLASS_GENERIC_4_2(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_4(VARIANT2, CAMO,SHIRT,arg1,arg2));\
  };

  #define CLASS_GENERIC_4_1(VARIANT,VARIANT2,SCOPEVAL,CAMO,SHIRT,arg1,arg2) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_Base {\
      scope=#SCOPEVAL;\
      displayName="[12th] Uniform";\
      ACE_GForceCoef=0.4;\
      class TCP_equipmentTypes: TCP_equipmentTypes {\
        baseEquipment = QOUTE(twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##CAMO##); \
      }; \
      class ItemInfo : ItemInfo {\
        uniformClass = QOUTE(TWELFTH_REF_GENERIC_4(VARIANT2,CAMO,SHIRT,arg1,arg2));\
        containerClass="Supply100"; \
        mass=1;\
        uniformType = "Neopren";\
        allowedSlots[]={"701","801","901"};\
        armor=20;\
      };\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
      };\
  };

  #define CLASS_GENERIC_5_3(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2,arg3) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_5(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3));\
  };

  #define CLASS_GENERIC_5_2(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2,arg3) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_5(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3));\
  };

  #define CLASS_GENERIC_5_1(VARIANT,VARIANT2,SCOPEVAL,CAMO,SHIRT,arg1,arg2,arg3) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_Base {\
      scope=#SCOPEVAL;\
      displayName="[12th] Uniform";\
      ACE_GForceCoef=0.4;\
      class TCP_equipmentTypes: TCP_equipmentTypes {\
        baseEquipment = QOUTE(twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##CAMO##); \
      }; \
      class ItemInfo : ItemInfo {\
        uniformClass = QOUTE(TWELFTH_REF_GENERIC_5(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3));\
        containerClass="Supply100"; \
        mass=1;\
        uniformType = "Neopren";\
        allowedSlots[]={"701","801","901"};\
        armor=20;\
      };\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
      };\
  };

  #define CLASS_GENERIC_6_3(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2,arg3,arg4) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_6(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3,arg4));\
  };

  #define CLASS_GENERIC_6_2(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2,arg3,arg4) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_6(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3,arg4));\
  };

  #define CLASS_GENERIC_6_1(VARIANT,VARIANT2,SCOPEVAL,CAMO,SHIRT,arg1,arg2,arg3,arg4) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_Base {\
      scope=#SCOPEVAL;\
      displayName="[12th] Uniform";\
      ACE_GForceCoef=0.4;\
      class TCP_equipmentTypes: TCP_equipmentTypes {\
        baseEquipment = QOUTE(twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##CAMO##); \
      }; \
      class ItemInfo : ItemInfo {\
        uniformClass = QOUTE(TWELFTH_REF_GENERIC_6(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3,arg4));\
        containerClass="Supply100"; \
        mass=1;\
        uniformType = "Neopren";\
        allowedSlots[]={"701","801","901"};\
        armor=20;\
      };\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
      };\
  };

  #define CLASS_GENERIC_7_3(VARIANT,VARIANT2,SCOPEVAL,CAMO,SUBCAMO,SHIRT,arg1,arg2,arg3,arg4,arg5) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_Base {\
      author="Sammy";\
      scope=#SCOPEVAL;\
      scopeArsenal=#SCOPEVAL;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##SUBCAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_REF_GENERIC_7(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3,arg4,arg5));\
  };
  #define CLASS_GENERIC_7_1(VARIANT,VARIANT2,SCOPEVAL,CAMO,SHIRT,arg1,arg2,arg3,arg4,arg5) \
  class twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##CAMO## : TCP_##VARIANT##_CBUU_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_Base {\
      scope=#SCOPEVAL;\
      displayName="[12th] Uniform";\
      ACE_GForceCoef=0.4;\
      class TCP_equipmentTypes: TCP_equipmentTypes {\
        baseEquipment = QOUTE(twelfth_##VARIANT##_##SHIRT##_##arg1##_##arg2##_##arg3##_##arg4##_##arg5##_##CAMO##); \
      }; \
      class ItemInfo : ItemInfo {\
        uniformClass = QOUTE(TWELFTH_REF_GENERIC_7(VARIANT2,CAMO,SHIRT,arg1,arg2,arg3,arg4,arg5));\
        containerClass="Supply100"; \
        mass=1;\
        uniformType = "Neopren";\
        allowedSlots[]={"701","801","901"};\
        armor=20;\
      };\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
      };\
  };


/* New uniform gear info */
#define NORMAL(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_##CAMO## { \
    model="twelfth_new_uniforms"; \
    camo=#CAMO; \
    sleeve=#SLEEVE; \
    glove="no"; \
    shirt=#SHIRT; \
    blouse="noblouse"; \
    zip="zipped"; \
    kneepad="nokneepads"; \
  };\
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Kneepads_##CAMO## { \
    model="twelfth_new_uniforms"; \
    camo=#CAMO; \
    sleeve=#SLEEVE; \
    glove="no"; \
    shirt=#SHIRT; \
    blouse="noblouse"; \
    zip="zipped"; \
    kneepad="kneepads"; \
  };

#define BLOUSED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="zipped"; \
    kneepad="nokneepads"; \
  };     \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="zipped"; \
    kneepad="kneepads"; \
  };                    

#define GLOVES(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="zipped";                                         \
    kneepad="nokneepads"; \
  };                                 \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="zipped";                                         \
    kneepad="kneepads"; \
  };                                 

#define BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="zipped";                                         \
    kneepad="nokneepads"; \
  };      \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="zipped";                                         \
    kneepad="kneepads"; \
  };             

#define UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="unzipped";                                         \
    kneepad="nokneepads"; \
  };           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Unzipped_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="unzipped";                                         \
    kneepad="kneepads"; \
  };                          

#define BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="unzipped";                                         \
    kneepad="nokneepads"; \
  };      \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="unzipped";                                         \
    kneepad="kneepads"; \
  };                         

#define GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="unzipped";                                         \
    kneepad="nokneepads"; \
  };    \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="unzipped";                                         \
    kneepad="kneepads"; \
  }; 
                             


#define GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                                              \
    sleeve=#SLEEVE;                                         \
    glove="yes";                                             \
    shirt=#SHIRT;                                            \
    blouse="blouse";                                        \
    zip="unzipped";                                         \
    kneepad="nokneepads"; \
  };\
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_Kneepads_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                                              \
    sleeve=#SLEEVE;                                         \
    glove="yes";                                             \
    shirt=#SHIRT;                                            \
    blouse="blouse";                                        \
    zip="unzipped";                                         \
    kneepad="kneepads"; \
  };        



// LATER ME NOTE
// REWRITE THIS TO PULL ARMOR TEXTURES FROM ONE FOLDER PER TYPE OF ARMOR (EX STD VS DRK)
// SINCE ARMOR NOW MATCHES PLT COLORS ANYWAYS, NO NEED FOR DIFFERENTIATION BETWEEN ARM/LEGS/CHEST

#define TSHIRT_UNIFORM_VEH(CAMO,PLATOON,ROLE,ARM,DISPLAYNAME)                          \
  class twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_veh: twelfth_uni_ng_base_veh{   \
    author="Waylen";                                                              \
    picture="";                                                                   \
    scope=1;                                                                      \
    scopeArsenal=2;                                                               \
    displayName=DISPLAYNAME;                                                      \
    hiddenSelectionsTextures[] =                                                  \
    {                                                                             \
      QP(uniforms\armor\bases\##CAMO\##PLATOON##_chest_co.paa),                   \
      QP(uniforms\armor\arms\##ARM\##PLATOON##_##ROLE##_arms_co.paa),             \
      QP(uniforms\armor\bases\##CAMO\##PLATOON##_legs_co.paa),                    \
      QP(uniforms\armor\bases\##CAMO\bdu_co.paa),                                 \
      QP(uniforms\armor\bases\##CAMO\misc_co.paa)                                 \
    };                                                                            \
  };             


/* 12th Uniform class definition */



#define UNIFORM_WEP(CAMO,PLATOON,ROLE,DISPLAYNAME)                                \
  class twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_wep : twelfth_uni_ng_base_wep { \
    author="Waylen";                                                              \
    picture="";                                                                   \
    scope=1;                                                                      \
    scopeArsenal=2;                                                               \
    displayName=DISPLAYNAME;                                                      \
    ACE_GForceCoef=0.4;                                                           \
    class ItemInfo: UniformItem {                                                 \
      uniformModel="-";                                                           \
      uniformType="Neopren";                                                      \
      uniformClass = #UNIFORM_WEP_CLASSNAME(CAMO,PLATOON,ROLE);                   \
      containerClass="Supply100";                                                 \
      mass=1;                                                                     \
      allowedSlots[]={"701","801","901"};                                         \
      armor=20;                                                                   \
    };                                                                            \
  };                                                                              

//New Uniform class definitions
//cfgVehicle
#define TCP_VEH_CLASS_DEF \
  TCP_VEH_CLASS_GENERIC_2(TShirt,Untucked) \
  TCP_VEH_CLASS_GENERIC_3(TShirt,Untucked,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TShirt,Untucked,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(TShirt,Untucked,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TShirt,Untucked,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(TShirt,Untucked,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TShirt,Untucked,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(TShirt,Untucked,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(TShirt,Tucked) \
  TCP_VEH_CLASS_GENERIC_3(TShirt,Tucked,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TShirt,Tucked,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(TShirt,Tucked,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TShirt,Tucked,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(TShirt,Tucked,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TShirt,Tucked,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(TShirt,Tucked,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(FieldTop,Full) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,Full,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,Full,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,Full,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,Full,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,Full,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,Full,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,Full,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,Full,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,Full,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,Full,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,Full,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,Full,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,Full,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,Full,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(FieldTop,Full,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(FieldTop,HalfRoll) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,HalfRoll,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,HalfRoll,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,HalfRoll,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,HalfRoll,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,HalfRoll,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,HalfRoll,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,HalfRoll,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,HalfRoll,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,HalfRoll,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,HalfRoll,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,HalfRoll,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,HalfRoll,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,HalfRoll,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,HalfRoll,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(FieldTop,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(FieldTop,QuarterRoll) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,QuarterRoll,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,QuarterRoll,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,QuarterRoll,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,QuarterRoll,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,QuarterRoll,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,QuarterRoll,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,QuarterRoll,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,QuarterRoll,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,QuarterRoll,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,QuarterRoll,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,QuarterRoll,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,QuarterRoll,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,QuarterRoll,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,QuarterRoll,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(FieldTop,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(FieldTop,SlimSleeve) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,SlimSleeve,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,SlimSleeve,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,SlimSleeve,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,SlimSleeve,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,SlimSleeve,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,SlimSleeve,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,SlimSleeve,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(FieldTop,SlimSleeve,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,SlimSleeve,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,SlimSleeve,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,SlimSleeve,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(FieldTop,SlimSleeve,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,SlimSleeve,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(FieldTop,SlimSleeve,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(FieldTop,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(TacShirt,Full) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,Full,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,Full,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,Full,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,Full,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,Full,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,Full,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,Full,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,Full,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,Full,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,Full,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,Full,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,Full,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,Full,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,Full,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(TacShirt,Full,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(TacShirt,HalfRoll) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,HalfRoll,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,HalfRoll,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,HalfRoll,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,HalfRoll,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,HalfRoll,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,HalfRoll,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,HalfRoll,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,HalfRoll,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,HalfRoll,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,HalfRoll,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,HalfRoll,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,HalfRoll,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,HalfRoll,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,HalfRoll,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(TacShirt,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(TacShirt,QuarterRoll) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,QuarterRoll,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,QuarterRoll,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,QuarterRoll,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,QuarterRoll,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,QuarterRoll,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,QuarterRoll,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,QuarterRoll,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,QuarterRoll,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,QuarterRoll,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,QuarterRoll,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,QuarterRoll,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,QuarterRoll,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,QuarterRoll,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,QuarterRoll,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(TacShirt,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_2(TacShirt,SlimSleeve) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,SlimSleeve,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,SlimSleeve,Unzipped) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,SlimSleeve,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,SlimSleeve,Bloused) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,SlimSleeve,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,SlimSleeve,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,SlimSleeve,Bloused,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_3(TacShirt,SlimSleeve,Gloves) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,SlimSleeve,Gloves,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,SlimSleeve,Gloves,Unzipped) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,SlimSleeve,Gloves,Unzipped,Kneepads) \
  TCP_VEH_CLASS_GENERIC_4(TacShirt,SlimSleeve,Gloves,Bloused) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,SlimSleeve,Gloves,Bloused,Kneepads) \
  TCP_VEH_CLASS_GENERIC_5(TacShirt,SlimSleeve,Gloves,Bloused,Unzipped) \
  TCP_VEH_CLASS_GENERIC_6(TacShirt,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \

//cfgWeapon
#define TCP_WEP_CLASS_DEF \
  TCP_WEP_CLASS_GENERIC_2(TShirt,Untucked) \
  TCP_WEP_CLASS_GENERIC_3(TShirt,Untucked,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TShirt,Untucked,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(TShirt,Untucked,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TShirt,Untucked,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(TShirt,Untucked,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TShirt,Untucked,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(TShirt,Untucked,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(TShirt,Tucked) \
  TCP_WEP_CLASS_GENERIC_3(TShirt,Tucked,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TShirt,Tucked,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(TShirt,Tucked,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TShirt,Tucked,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(TShirt,Tucked,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TShirt,Tucked,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(TShirt,Tucked,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(FieldTop,Full) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,Full,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,Full,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,Full,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,Full,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,Full,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,Full,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,Full,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,Full,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,Full,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,Full,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,Full,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,Full,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,Full,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,Full,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(FieldTop,Full,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(FieldTop,HalfRoll) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,HalfRoll,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,HalfRoll,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,HalfRoll,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,HalfRoll,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,HalfRoll,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,HalfRoll,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,HalfRoll,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,HalfRoll,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,HalfRoll,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,HalfRoll,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,HalfRoll,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,HalfRoll,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,HalfRoll,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,HalfRoll,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(FieldTop,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(FieldTop,QuarterRoll) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,QuarterRoll,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,QuarterRoll,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,QuarterRoll,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,QuarterRoll,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,QuarterRoll,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,QuarterRoll,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,QuarterRoll,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,QuarterRoll,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,QuarterRoll,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,QuarterRoll,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,QuarterRoll,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,QuarterRoll,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,QuarterRoll,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,QuarterRoll,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(FieldTop,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(FieldTop,SlimSleeve) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,SlimSleeve,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,SlimSleeve,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,SlimSleeve,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,SlimSleeve,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,SlimSleeve,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,SlimSleeve,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,SlimSleeve,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(FieldTop,SlimSleeve,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,SlimSleeve,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,SlimSleeve,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,SlimSleeve,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(FieldTop,SlimSleeve,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,SlimSleeve,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(FieldTop,SlimSleeve,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(FieldTop,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(TacShirt,Full) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,Full,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,Full,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,Full,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,Full,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,Full,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,Full,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,Full,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,Full,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,Full,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,Full,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,Full,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,Full,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,Full,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,Full,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(TacShirt,Full,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(TacShirt,HalfRoll) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,HalfRoll,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,HalfRoll,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,HalfRoll,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,HalfRoll,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,HalfRoll,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,HalfRoll,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,HalfRoll,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,HalfRoll,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,HalfRoll,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,HalfRoll,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,HalfRoll,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,HalfRoll,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,HalfRoll,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,HalfRoll,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(TacShirt,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(TacShirt,QuarterRoll) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,QuarterRoll,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,QuarterRoll,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,QuarterRoll,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,QuarterRoll,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,QuarterRoll,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,QuarterRoll,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,QuarterRoll,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,QuarterRoll,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,QuarterRoll,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,QuarterRoll,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,QuarterRoll,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,QuarterRoll,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,QuarterRoll,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,QuarterRoll,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(TacShirt,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_2(TacShirt,SlimSleeve) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,SlimSleeve,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,SlimSleeve,Unzipped) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,SlimSleeve,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,SlimSleeve,Bloused) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,SlimSleeve,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,SlimSleeve,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,SlimSleeve,Bloused,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_3(TacShirt,SlimSleeve,Gloves) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,SlimSleeve,Gloves,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,SlimSleeve,Gloves,Unzipped) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,SlimSleeve,Gloves,Unzipped,Kneepads) \
  TCP_WEP_CLASS_GENERIC_4(TacShirt,SlimSleeve,Gloves,Bloused) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,SlimSleeve,Gloves,Bloused,Kneepads) \
  TCP_WEP_CLASS_GENERIC_5(TacShirt,SlimSleeve,Gloves,Bloused,Unzipped) \
  TCP_WEP_CLASS_GENERIC_6(TacShirt,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \


// New uniform class setup
#define VEH_UNI_CLASS(CAMO) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,TShirt,Untucked) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TShirt,Untucked,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,TShirt,Tucked) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TShirt,Tucked,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,FieldTop,Full) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Unzipped,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,FieldTop,Full,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,FieldTop,Full,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,FieldTop,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,FieldTop,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,FieldTop,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,TacShirt,Full) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,Full,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,Full,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,Full,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,Full,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,Full,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,TacShirt,Full,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,TacShirt,Full,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,TacShirt,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,TacShirt,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Unzipped) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Bloused,Kneepads) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Bloused,Unzipped) \
  CLASS_GENERIC_6_2(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Unzipped) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_3(B,U_B,1,CAMO,CAMO,TacShirt,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \

// Tshirt cfgVehicles class setup
#define VEH_UNI_TSHIRT_CLASS(CAMO) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,std,TShirt,Untucked) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,std,TShirt,Untucked,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,std,TShirt,Untucked,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,std,TShirt,Untucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,std,TShirt,Untucked,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,std,TShirt,Untucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,std,TShirt,Untucked,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,std,TShirt,Untucked,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_3_2(B,U_B,1,CAMO,std,TShirt,Tucked) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,std,TShirt,Tucked,Kneepads) \
  CLASS_GENERIC_4_2(B,U_B,1,CAMO,std,TShirt,Tucked,Bloused) \
  CLASS_GENERIC_5_2(B,U_B,1,CAMO,std,TShirt,Tucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_3(B,U_B,1,CAMO,std,TShirt,Tucked,Gloves) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,std,TShirt,Tucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_3(B,U_B,1,CAMO,std,TShirt,Tucked,Gloves,Bloused) \
  CLASS_GENERIC_6_3(B,U_B,1,CAMO,std,TShirt,Tucked,Gloves,Bloused,Kneepads) \

//cfgWeapon
// Expect only CLASS_GENERIC_..._1 here, since we need only 1 hiddenSelectionTexture for cfgWeapons
#define WEP_UNI_CLASS(CAMO) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TShirt,Untucked) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Untucked,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Untucked,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Untucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TShirt,Tucked) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Tucked,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Tucked,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Tucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,FieldTop,Full) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,Full,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,Full,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,Full,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,Full,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,Full,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,Full,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,Full,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,Full,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,FieldTop,Full,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,FieldTop,HalfRoll) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,FieldTop,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,FieldTop,QuarterRoll) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,FieldTop,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,FieldTop,SlimSleeve) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,FieldTop,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TacShirt,Full) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,Full,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,Full,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,Full,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,Full,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,Full,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,Full,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,Full,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,Full,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,TacShirt,Full,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TacShirt,HalfRoll) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,TacShirt,HalfRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TacShirt,QuarterRoll) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,TacShirt,QuarterRoll,Gloves,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TacShirt,SlimSleeve) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Unzipped) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Bloused,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Bloused,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Bloused,Unzipped,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Unzipped) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Unzipped,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Bloused,Unzipped) \
  CLASS_GENERIC_7_1(U_B,B,2,CAMO,TacShirt,SlimSleeve,Gloves,Bloused,Unzipped,Kneepads) \

// Tshirt cfgWeapons class setup
#define WEP_UNI_TSHIRT_CLASS(CAMO) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TShirt,Untucked) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Untucked,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Untucked,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Untucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TShirt,Untucked,Gloves,Bloused,Kneepads) \
  CLASS_GENERIC_3_1(U_B,B,2,CAMO,TShirt,Tucked) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Tucked,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Tucked,Bloused) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Tucked,Bloused,Kneepads) \
  CLASS_GENERIC_4_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves,Kneepads) \
  CLASS_GENERIC_5_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves,Bloused) \
  CLASS_GENERIC_6_1(U_B,B,2,CAMO,TShirt,Tucked,Gloves,Bloused,Kneepads) \


#define NEW_UNIFROM_GI(CAMO)                        \
  NORMAL(CAMO,TShirt,Tucked)                       \
  NORMAL(CAMO,TShirt,Untucked)                       \
  NORMAL(CAMO,FieldTop,Full)                       \
  NORMAL(CAMO,FieldTop,HalfRoll)                       \
  NORMAL(CAMO,FieldTop,QuarterRoll)                       \
  NORMAL(CAMO,FieldTop,SlimSleeve)                       \
  NORMAL(CAMO,TacShirt,Full)                       \
  NORMAL(CAMO,TacShirt,HalfRoll)                       \
  NORMAL(CAMO,TacShirt,QuarterRoll)                       \
  NORMAL(CAMO,TacShirt,SlimSleeve)                       \
  BLOUSED(CAMO,TShirt,Tucked)                       \
  BLOUSED(CAMO,TShirt,Untucked)                       \
  BLOUSED(CAMO,FieldTop,Full)                       \
  BLOUSED(CAMO,FieldTop,HalfRoll)                       \
  BLOUSED(CAMO,FieldTop,QuarterRoll)                       \
  BLOUSED(CAMO,FieldTop,SlimSleeve)                       \
  BLOUSED(CAMO,TacShirt,Full)                       \
  BLOUSED(CAMO,TacShirt,HalfRoll)                       \
  BLOUSED(CAMO,TacShirt,QuarterRoll)                       \
  BLOUSED(CAMO,TacShirt,SlimSleeve)                       \
  GLOVES(CAMO,TShirt,Tucked)                       \
  GLOVES(CAMO,TShirt,Untucked)                       \
  GLOVES(CAMO,FieldTop,Full)                       \
  GLOVES(CAMO,FieldTop,HalfRoll)                       \
  GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  GLOVES(CAMO,TacShirt,Full)                       \
  GLOVES(CAMO,TacShirt,HalfRoll)                       \
  GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  BLOUSED_GLOVES(CAMO,TShirt,Tucked)                       \
  BLOUSED_GLOVES(CAMO,TShirt,Untucked)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,Full)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,HalfRoll)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,Full)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,HalfRoll)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  UNZIPPED(CAMO,FieldTop,Full)                       \
  UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  UNZIPPED(CAMO,FieldTop,SlimSleeve)                       \
  UNZIPPED(CAMO,TacShirt,Full)                       \
  UNZIPPED(CAMO,TacShirt,HalfRoll)                       \
  UNZIPPED(CAMO,TacShirt,QuarterRoll)                       \
  UNZIPPED(CAMO,TacShirt,SlimSleeve)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,Full)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,Full)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)                       \
  GLOVES_UNZIPPED(CAMO,FieldTop,Full)                                       \
  GLOVES_UNZIPPED(CAMO,FieldTop,HalfRoll)                                   \
  GLOVES_UNZIPPED(CAMO,FieldTop,QuarterRoll)                                \
  GLOVES_UNZIPPED(CAMO,FieldTop,SlimSleeve)                                 \
  GLOVES_UNZIPPED(CAMO,TacShirt,Full)                                       \
  GLOVES_UNZIPPED(CAMO,TacShirt,HalfRoll)                                   \
  GLOVES_UNZIPPED(CAMO,TacShirt,QuarterRoll)                                \
  GLOVES_UNZIPPED(CAMO,TacShirt,SlimSleeve)                                 \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,Full)                               \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)                           \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)                        \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)                         \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,Full)                               \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)                           \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)                        \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)                         \

//This is where the TCP helmets are made
#define HELM_CH43A(SUFFIX,DISPLAY)                 \
  class twelfth_helmCH43A_##SUFFIX##: twelfth_helmCH43A_base {    \
  scope=2;                                      \
  author="Sammy";                                \
  picture="";                                   \
  scopeArsenal=2;                               \
  displayName=DISPLAY;                          \
  hiddenSelections[] = { "camo","decals" };              \
  hiddenSelectionsTextures[] = {                \
    #HELM_TEX_PATH_CH43A(SUFFIX),				\
	  #HELM_DEC_PATH								\
  }; 											\
	class TCP_uniformDecals: TCP_uniformDecals		\
	{												\
		decalColor = "white";						\
	};  											\
  class ItemInfo: HeadgearItem {                \
    uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";   \
    picture="";                                 \
    mass=40;                                    \
    modelSides[]={6};                           \
    passThrough=0.1;                            \
    class HitpointsProtectionInfo {             \
      class Head {                              \
        hitpointName="HitHead";                 \
        armor=20;                               \
        passThrough=0.1;                        \
      };                                        \
    };                                          \
    hiddenSelections[]= {"camo","decals"};      \
    hiddenSelectionsTextures[]= {               \
      #HELM_TEX_PATH_CH43A(SUFFIX),				\
	    #HELM_DEC_PATH	  						\
    };                                          \
  };                                            \
};   
//Closed version
#define HELM_ECH43A(SUFFIX,DISPLAY)                 \
  class twelfth_helmECH43A_##SUFFIX##: twelfth_helmECH43A_base {    \
  scope=2;                                      \
  author="Sammy";                                \
  picture="";                                   \
  scopeArsenal=2;                               \
  displayName=DISPLAY;                          \
  model = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_Black.p3d"; \
  hiddenSelections[]= {"camo","camo1","decals"};             \
  hiddenSelectionsTextures[] = {                \
    #HELM_TEX_PATH_CH43A(SUFFIX),				\
    "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\black\helmet_ECH43A_Visor_CO.paa",\
	  #HELM_DEC_PATH								\
  }; 											\
	class TCP_uniformDecals: TCP_uniformDecals		\
	{												\
		decalColor = "white";						\
	};  											\
  class ItemInfo: HeadgearItem {                \
    uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_Black.p3d";   \
    picture="";                                 \
    mass=40;                                    \
    modelSides[]={6};                           \
    passThrough=0.1;                            \
    class HitpointsProtectionInfo {             \
      class Head {                              \
        hitpointName="HitHead";                 \
        armor=20;                               \
        passThrough=0.1;                        \
      };                                        \
    };                                          \
    hiddenSelections[]= {"camo","camo1","decals"};      \
    hiddenSelectionsTextures[]= {               \
      #HELM_TEX_PATH_CH43A(SUFFIX),				\
      "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\default\helmet_ECH43A_Visor_CO.paa",\
	    #HELM_DEC_PATH	  						\
    };                                          \
  };                                            \
};  


// this is shoved into here so that it need not be repeated 20x for different variants

#define ALL_HELM(CAMO)                                                  \
  HELM_CH43A(##CAMO##,         "[12th][Inf] Helmet")                       \
  HELM_CH43A(##CAMO##_1pl,     "[12th][Inf][1Plt] Helmet")                 \
  HELM_CH43A(##CAMO##_1pl_ftl, "[12th][Inf][1Plt] Helmet (FTL)")           \
  HELM_CH43A(##CAMO##_1pl_sl,  "[12th][Inf][1Plt] Helmet (SL)")            \
  HELM_CH43A(##CAMO##_1pl_psg, "[12th][Inf][1Plt] Helmet (PSG)")           \
  HELM_CH43A(##CAMO##_1pl_pl,  "[12th][Inf][1Plt] Helmet (PL)")            \
  HELM_CH43A(##CAMO##_1pl_med, "[12th][Inf][1Plt] Helmet (Corpsman)")      \
  HELM_CH43A(##CAMO##_2pl,     "[12th][Inf][2Plt] Helmet")                 \
  HELM_CH43A(##CAMO##_2pl_ftl, "[12th][Inf][2Plt] Helmet (FTL)")           \
  HELM_CH43A(##CAMO##_2pl_sl,  "[12th][Inf][2Plt] Helmet (SL)")            \
  HELM_CH43A(##CAMO##_2pl_psg, "[12th][Inf][2Plt] Helmet (PSG)")           \
  HELM_CH43A(##CAMO##_2pl_pl,  "[12th][Inf][2Plt] Helmet (PL)")            \
  HELM_CH43A(##CAMO##_2pl_med, "[12th][Inf][2Plt] Helmet (Corpsman)")      \
  HELM_CH43A(##CAMO##_hq,      "[12th][Inf][HQ] Helmet")                   \
  HELM_CH43A(##CAMO##_hq_ftl,  "[12th][Inf][HQ] Helmet (FTL)")             \
  HELM_CH43A(##CAMO##_hq_sl,   "[12th][Inf][HQ] Helmet (SL)")              \
  HELM_CH43A(##CAMO##_hq_psg,  "[12th][Inf][HQ] Helmet (PSG)")             \
  HELM_CH43A(##CAMO##_hq_pl,   "[12th][Inf][HQ] Helmet (PL)")              \
  HELM_CH43A(##CAMO##_hq_med,  "[12th][Inf][HQ] Helmet (Corpsman)")        \
  HELM_CH43A(##CAMO##_lpl,     "[12th][Inf][Logi] Helmet")                 \
  HELM_CH43A(##CAMO##_lpl_ftl, "[12th][Inf][Logi] Helmet (FTL)")           \
  HELM_CH43A(##CAMO##_lpl_sl,  "[12th][Inf][Logi] Helmet (SL)")            \
  HELM_CH43A(##CAMO##_lpl_psg, "[12th][Inf][Logi] Helmet (PSG)")           \
  HELM_CH43A(##CAMO##_lpl_pl,  "[12th][Inf][Logi] Helmet (PL)")            \
  HELM_CH43A(##CAMO##_lpl_med, "[12th][Inf][Logi] Helmet (Corpsman)")      \
  HELM_ECH43A(##CAMO##,         "[12th][Clsd] Helmet")                       \
  HELM_ECH43A(##CAMO##_1pl,     "[12th][Clsd][1Plt] Helmet")                 \
  HELM_ECH43A(##CAMO##_1pl_ftl, "[12th][Clsd][1Plt] Helmet (FTL)")           \
  HELM_ECH43A(##CAMO##_1pl_sl,  "[12th][Clsd][1Plt] Helmet (SL)")            \
  HELM_ECH43A(##CAMO##_1pl_psg, "[12th][Clsd][1Plt] Helmet (PSG)")           \
  HELM_ECH43A(##CAMO##_1pl_pl,  "[12th][Clsd][1Plt] Helmet (PL)")            \
  HELM_ECH43A(##CAMO##_1pl_med, "[12th][Clsd][1Plt] Helmet (Corpsman)")      \
  HELM_ECH43A(##CAMO##_2pl,     "[12th][Clsd][2Plt] Helmet")                 \
  HELM_ECH43A(##CAMO##_2pl_ftl, "[12th][Clsd][2Plt] Helmet (FTL)")           \
  HELM_ECH43A(##CAMO##_2pl_sl,  "[12th][Clsd][2Plt] Helmet (SL)")            \
  HELM_ECH43A(##CAMO##_2pl_psg, "[12th][Clsd][2Plt] Helmet (PSG)")           \
  HELM_ECH43A(##CAMO##_2pl_pl,  "[12th][Clsd][2Plt] Helmet (PL)")            \
  HELM_ECH43A(##CAMO##_2pl_med, "[12th][Clsd][2Plt] Helmet (Corpsman)")      \
  HELM_ECH43A(##CAMO##_hq,      "[12th][Clsd][HQ] Helmet")                   \
  HELM_ECH43A(##CAMO##_hq_ftl,  "[12th][Clsd][HQ] Helmet (FTL)")             \
  HELM_ECH43A(##CAMO##_hq_sl,   "[12th][Clsd][HQ] Helmet (SL)")              \
  HELM_ECH43A(##CAMO##_hq_psg,  "[12th][Clsd][HQ] Helmet (PSG)")             \
  HELM_ECH43A(##CAMO##_hq_pl,   "[12th][Clsd][HQ] Helmet (PL)")              \
  HELM_ECH43A(##CAMO##_hq_med,  "[12th][Clsd][HQ] Helmet (Corpsman)")        \
  HELM_ECH43A(##CAMO##_lpl,     "[12th][Clsd][Logi] Helmet")                 \
  HELM_ECH43A(##CAMO##_lpl_ftl, "[12th][Clsd][Logi] Helmet (FTL)")           \
  HELM_ECH43A(##CAMO##_lpl_sl,  "[12th][Clsd][Logi] Helmet (SL)")            \
  HELM_ECH43A(##CAMO##_lpl_psg, "[12th][Clsd][Logi] Helmet (PSG)")           \
  HELM_ECH43A(##CAMO##_lpl_pl,  "[12th][Clsd][Logi] Helmet (PL)")            \
  HELM_ECH43A(##CAMO##_lpl_med, "[12th][Clsd][Logi] Helmet (Corpsman)")      \




/* Stands for helm, gear info. */

#define HELM_CH43A_GI(CSFX,CAMO,EL,ROLE,CLOSED)  \
class twelfth_helmCH43A_##CSFX## {              \
  model="twelfth_base_ch43a";            \
  camo=#CAMO;                       	  \
  element=#EL;                     		   \
  role=#ROLE;                      		   \
  closed=#CLOSED;\
};
#define HELM_ECH43A_GI(CSFX,CAMO,EL,ROLE,CLOSED)  \
class twelfth_helmECH43A_##CSFX## {              \
  model="twelfth_base_ch43a";            \
  camo=#CAMO;                       	  \
  element=#EL;                     		   \
  role=#ROLE;                      		   \
  closed=#CLOSED;\
};


#define CH43A_HELM_GI(CAMO)       \
	HELM_CH43A_GI(##CAMO##,##CAMO##,na,na,no)       \
  HELM_CH43A_GI(##CAMO##_med,##CAMO##,na,med,no)        \
  HELM_CH43A_GI(##CAMO##_1pl,##CAMO##,1pl,na,no)        \
  HELM_CH43A_GI(##CAMO##_1pl_ftl,##CAMO##,1pl,ftl,no)       \
  HELM_CH43A_GI(##CAMO##_1pl_sl,##CAMO##,1pl,sl,no)       \
  HELM_CH43A_GI(##CAMO##_1pl_psg,##CAMO##,1pl,psg,no)       \
  HELM_CH43A_GI(##CAMO##_1pl_pl,##CAMO##,1pl,pl,no)       \
  HELM_CH43A_GI(##CAMO##_1pl_med,##CAMO##,1pl,med,no)       \
  HELM_CH43A_GI(##CAMO##_2pl,##CAMO##,2pl,na,no)        \
  HELM_CH43A_GI(##CAMO##_2pl_ftl,##CAMO##,2pl,ftl,no)       \
  HELM_CH43A_GI(##CAMO##_2pl_sl,##CAMO##,2pl,sl,no)       \
  HELM_CH43A_GI(##CAMO##_2pl_psg,##CAMO##,2pl,psg,no)       \
  HELM_CH43A_GI(##CAMO##_2pl_pl,##CAMO##,2pl,pl,no)       \
  HELM_CH43A_GI(##CAMO##_2pl_med,##CAMO##,2pl,med,no)       \
  HELM_CH43A_GI(##CAMO##_hq,##CAMO##,hq,na,no)        \
  HELM_CH43A_GI(##CAMO##_hq_ftl,##CAMO##,hq,ftl,no)       \
  HELM_CH43A_GI(##CAMO##_hq_sl,##CAMO##,hq,sl,no)       \
  HELM_CH43A_GI(##CAMO##_hq_psg,##CAMO##,hq,psg,no)       \
  HELM_CH43A_GI(##CAMO##_hq_pl,##CAMO##,hq,pl,no)       \
  HELM_CH43A_GI(##CAMO##_hq_med,##CAMO##,hq,med,no)       \
  HELM_CH43A_GI(##CAMO##_lpl,##CAMO##,lpl,na,no)        \
  HELM_CH43A_GI(##CAMO##_lpl_ftl,##CAMO##,lpl,ftl,no)       \
  HELM_CH43A_GI(##CAMO##_lpl_sl,##CAMO##,lpl,sl,no)       \
  HELM_CH43A_GI(##CAMO##_lpl_psg,##CAMO##,lpl,psg,no)       \
  HELM_CH43A_GI(##CAMO##_lpl_pl,##CAMO##,lpl,pl,no)       \
  HELM_CH43A_GI(##CAMO##_lpl_med,##CAMO##,lpl,med,no)       \
	HELM_ECH43A_GI(##CAMO##,##CAMO##,na,na,yes)       \
  HELM_ECH43A_GI(##CAMO##_med,##CAMO##,na,med,yes)        \
  HELM_ECH43A_GI(##CAMO##_1pl,##CAMO##,1pl,na,yes)        \
  HELM_ECH43A_GI(##CAMO##_1pl_ftl,##CAMO##,1pl,ftl,yes)       \
  HELM_ECH43A_GI(##CAMO##_1pl_sl,##CAMO##,1pl,sl,yes)       \
  HELM_ECH43A_GI(##CAMO##_1pl_psg,##CAMO##,1pl,psg,yes)       \
  HELM_ECH43A_GI(##CAMO##_1pl_pl,##CAMO##,1pl,pl,yes)       \
  HELM_ECH43A_GI(##CAMO##_1pl_med,##CAMO##,1pl,med,yes)       \
  HELM_ECH43A_GI(##CAMO##_2pl,##CAMO##,2pl,na,yes)        \
  HELM_ECH43A_GI(##CAMO##_2pl_ftl,##CAMO##,2pl,ftl,yes)       \
  HELM_ECH43A_GI(##CAMO##_2pl_sl,##CAMO##,2pl,sl,yes)       \
  HELM_ECH43A_GI(##CAMO##_2pl_psg,##CAMO##,2pl,psg,yes)       \
  HELM_ECH43A_GI(##CAMO##_2pl_pl,##CAMO##,2pl,pl,yes)       \
  HELM_ECH43A_GI(##CAMO##_2pl_med,##CAMO##,2pl,med,yes)       \
  HELM_ECH43A_GI(##CAMO##_hq,##CAMO##,hq,na,yes)        \
  HELM_ECH43A_GI(##CAMO##_hq_ftl,##CAMO##,hq,ftl,yes)       \
  HELM_ECH43A_GI(##CAMO##_hq_sl,##CAMO##,hq,sl,yes)       \
  HELM_ECH43A_GI(##CAMO##_hq_psg,##CAMO##,hq,psg,yes)       \
  HELM_ECH43A_GI(##CAMO##_hq_pl,##CAMO##,hq,pl,yes)       \
  HELM_ECH43A_GI(##CAMO##_hq_med,##CAMO##,hq,med,yes)       \
  HELM_ECH43A_GI(##CAMO##_lpl,##CAMO##,lpl,na,yes)        \
  HELM_ECH43A_GI(##CAMO##_lpl_ftl,##CAMO##,lpl,ftl,yes)       \
  HELM_ECH43A_GI(##CAMO##_lpl_sl,##CAMO##,lpl,sl,yes)       \
  HELM_ECH43A_GI(##CAMO##_lpl_psg,##CAMO##,lpl,psg,yes)       \
  HELM_ECH43A_GI(##CAMO##_lpl_pl,##CAMO##,lpl,pl,yes)       \
  HELM_ECH43A_GI(##CAMO##_lpl_med,##CAMO##,lpl,med,yes)       \
	

#define CAP_B(SUFFIX,DISPLAY)                         \
class twelfth_cap_##SUFFIX: H_Cap_oli {               \
  picture="";                                         \
  scope=2;                                            \
  scopeArsenal=2;                                     \
  displayname=DISPLAY;                                \
  hiddenselectionstextures[]={#CAP_TEX_PATH(SUFFIX)}; \
};

/*
For those of you peeking around, sorry, couldn't
have made this macro work cleanly without carrying
a local copy of the base textures from UNSCF around here.
*/

/*
  A Macro for the IAHDS Pilot helmet.
  Input:
  * SUFFIX - A class name suffix, to avoid clashing.
  * DISPLAY - What gets displayed in the Arsenal, format "like this".
  * C1 through 5 - Arguments that define from which folder a specific
                   hidden selection is going to be pulling from.
*/
#define PILOT_HELM(SUFFIX,DISPLAY,C1,C2,C3,C4,C5)                         \
  class twelfth_pilot_h_##SUFFIX : H_HelmetB {                                 \
  author="Weber";                                                          \
  scope=2;                                                                \
  scopeArsenal=2;                                                         \
  picture="";                                                             \
  ace_hearing_protection=1;                                               \
  ace_hearing_lowerVolume=0.30000001;                                     \
  optreVarietys[] = {"", "", "_broken"};                                  \
  optreHUDStyle = "ODST_1";                                               \
  displayName=DISPLAY;                                                    \
  hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4", "camo5"};     \
  model="Foundries\DMNS_Units\Armour\Pilot_Helm_01\Pilot_Helmet_01.p3d";          \
  hiddenSelectionsTextures[]={                                            \
      #PILOT_H_TEX(C1,Addons_co.paa),                                     \
      #PILOT_H_TEX(C2,EXT_co.paa),                                        \
      #PILOT_H_TEX(C3,INT_co.paa),                                        \
      #PILOT_H_TEX(C4,MID_co.paa),                                        \
      #PILOT_H_TEX(C5,Visor_co.paa)                                       \
  };                                                                      \
  class ItemInfo : HeadgearItem {                                         \
    mass = 25;                                                            \
    modelSides[]={6};                                                     \
    uniformModel="Foundries\DMNS_Units\Armour\Pilot_Helm_01\Pilot_Helmet_01.p3d"; \
    hiddenSelections[]={"camo1", "camo2", "camo3", "camo4", "camo5"};     \
    hiddenSelectionsTextures[]={                                          \
      #PILOT_H_TEX(C1,Addons_co.paa),                                     \
      #PILOT_H_TEX(C2,EXT_co.paa),                                        \
      #PILOT_H_TEX(C3,INT_co.paa),                                        \
      #PILOT_H_TEX(C4,MID_co.paa),                                        \
      #PILOT_H_TEX(C5,Visor_co.paa)                                       \
    };                                                                    \
    class HitpointsProtectionInfo {                                       \
      class Head {                                                        \
        hitpointName = "HitHead";                                         \
        armor = 20;                                                       \
        passThrough = 0.2;                                                \
      };                                                                  \
      class Face {                                                        \
        hitpointName = "HitFace";                                         \
        armor = 8;                                                        \
        passThrough = 0.3;                                                \
      };                                                                  \
      class Neck {                                                        \
        hitpointName = "HitNeck";                                         \
        armor = 15;                                                       \
        passThrough = 0.1;                                                \
      };                                                                  \
    };                                                                    \
  };                                                                      \
};

// New Boonie
#define FOLD_BOONIE_GI(CAMO, FOLD)\
  class twelfth_boonieHat_##FOLD##_##CAMO {\
    model = "twelfth_boonies";\
    camo = #CAMO;\
    fold = #FOLD;\
  };\
                                                      
#define NAFOLD_BOONIE_GI(CAMO)\
  class twelfth_boonieHat_##CAMO {\
    model = "twelfth_boonies";\
    camo = #CAMO;\
    fold = "na";\
  };\

  #define BOONIE_GI(CAMO)\
  NAFOLD_BOONIE_GI(CAMO)\
  FOLD_BOONIE_GI(CAMO,Folded)\
  FOLD_BOONIE_GI(CAMO,Folded_Left)\
  FOLD_BOONIE_GI(CAMO,Folded_Right)\

#define BOONIE_CAMO(CAMO)\
  class twelfth_boonieHat_##CAMO##: TCP_H_boonieHat_Base {  \
    author="Rex"; \
     scope=2;\
    scopeArsenal=2;                              \
    picture="";                                       \
    displayName="[12th][Caps] Boonie";            \
    hiddenSelections[] = { "camo"};    \
    hiddenSelectionsTextures[] = {                    \
      QP(helmets\boonie_hat\##CAMO\boonie_co.paa)       \
    };                                                \
    class ItemInfo: ItemInfo {                        \
      hiddenSelections[] = { "camo"};  \
      hiddenSelectionsTextures[] = {                  \
        QP(helmets\boonie_hat\##CAMO\boonie_co.paa)     \
      };                                              \
    };                                                \
  };                                                  \

#define BOONIE_FOLD(CAMO, FOLD)\
  class twelfth_boonieHat_##FOLD##_##CAMO##: TCP_H_boonieHat_##FOLD##_Base {  \
    author="Rex"; \
     scope=2;\
    scopeArsenal=2;                              \
    picture="";                                       \
    displayName="[12th][Caps] Boonie";            \
    hiddenSelections[] = { "camo"};    \
    hiddenSelectionsTextures[] = {                    \
      QP(helmets\boonie_hat\##CAMO\boonie_co.paa)       \
    };                                                \
    class ItemInfo: ItemInfo {                        \
      hiddenSelections[] = { "camo"};  \
      hiddenSelectionsTextures[] = {                  \
        QP(helmets\boonie_hat\##CAMO\boonie_co.paa)     \
      };                                              \
    };                                                \
  };                                    

#define BOONIE(CAMO)\
BOONIE_CAMO(CAMO)\
BOONIE_FOLD(CAMO,Folded)\
BOONIE_FOLD(CAMO,Folded_Left)\
BOONIE_FOLD(CAMO,Folded_Right)\

#define PATROLCAP_WEP(CAMO) \
  class twelfth_patrol_cap_##CAMO##: TCP_H_PatrolCap_Base {  \
    author="Rex"; \
     scope=2;\
    scopeArsenal=2;                              \
    picture="";                                       \
    displayName="[12th][Caps] Patrol Cap";            \
    hiddenSelections[] = { "camo"};    \
    hiddenSelectionsTextures[] = {                    \
      QP(helmets\patrol_caps\##CAMO\cap_co.paa)       \
    };                                                \
    class ItemInfo: ItemInfo {                        \
      hiddenSelections[] = { "camo"};  \
      hiddenSelectionsTextures[] = {                  \
        QP(helmets\patrol_caps\##CAMO\cap_co.paa)     \
      };                                              \
    };                                                \
  };                                                  \
  
#define PATROLCAP_GI(CAMO) \
  class twelfth_patrol_cap_##CAMO { \
    model = "twelfth_patrolcap"; \
    camo = #CAMO; \
  }; \

  #define UTILITYCOVER_WEP(CAMO) \
  class twelfth_util_cap_##CAMO##: TCP_H_UtilityCover_Base {  \
    author="Rex"; \
     scope=2;\
    scopeArsenal=2;                              \
    picture="";                                       \
    displayName="[12th][Caps] Utility Cover";            \
    hiddenSelections[] = { "camo"};    \
    hiddenSelectionsTextures[] = {                    \
      QP(helmets\utility_cover\##CAMO\util_cap_co.paa)       \
    };                                                \
    class ItemInfo: ItemInfo {                        \
      hiddenSelections[] = { "camo"};  \
      hiddenSelectionsTextures[] = {                  \
        QP(helmets\utility_cover\##CAMO\util_cap_co.paa)     \
      };                                              \
    };                                                \
  };                                                  \
  
#define UTILITYCOVER_GI(CAMO) \
  class twelfth_util_cap_##CAMO { \
    model = "twelfth_utilcap"; \
    camo = #CAMO; \
  }; \

  
