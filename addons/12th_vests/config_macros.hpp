/*
  ==============================================================================
  config_macros.hpp

  This file contains all macros used in our 12th_vests config. Macros reduce
  duplication and make it easier to manage changes across multiple vests. 

  Notable macros here:
    - P() and Q() to handle path building and string quoting.
    - VEST_MASS: standard ACE mass for these vests.
    - VEST_MAXLOAD: total carrying capacity for the vest container.
    - VEST_HITPOINT_INFO: sets up armor (hit) values for various body parts.
    - UNSCF_VEST_ITEM_INFO and INVIS_VEST_ITEM_INFO: define vest parameters like
      mass, containerClass, and the hitpoint info.
    - UNSCF_VEST_ALL_VARIANTS: expands into multiple definitions for each vest
      selection set (Rifleman, Breacher, Grenadier, etc.) with each
      combination of pouches.
  ==============================================================================
*/
// Basic path macros
#define P(PATH) \x\12thMEU\addons\12th_vests\##PATH
  // P(something) => "\x\12thMEU\addons\12th_vests\something"

#define QP(PATH) #P(PATH)
#define Q(INPUT) #INPUT
  // Q(INPUT) => "INPUT"
#define GLUE(A,B) A##B
  // GLUE(A,B) => AB (concatenates tokens)


//Common texture paths
#define HELM_DEC_PATH "tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\White\vest_M43_DecalSheet_CA.paa"

#define VEST_PATH_01(CAMO)\
  QP(data\vests\##CAMO\vest_01_co.paa) 

#define VEST_PATH_02(CAMO)\
  QP(data\vests\##CAMO\vest_02_co.paa) 

#define VEST_PATH_03(CAMO)\
  QP(data\vests\##CAMO\vest_03_co.paa)  

/*
#define GUNGNIR_PATH(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa) 

#define VEST_PATH_02(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa)

#define BASESEC_PATH(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa)
*/

// Standard vest attributes
#define VEST_MASS 80      // The vest’s "mass" for ACE/Arma calculations
#define VEST_MAXLOAD 200  // The vest’s carrying capacity (in “inventory units”)

// Macro for the hitpoint data applied to vests
#define VEST_HITPOINT_INFO       \
  class HitpointsProtectionInfo {  \
    class Neck {                   \
      hitpointName="HitNeck";      \
      armor=20;                    \
      passThrough=0.30000001;      \
    };                             \
    class Arms {                   \
      hitpointName="HitArms";      \
      armor=10;                    \
      passThrough=0.60000002;      \
    };                             \
    class Chest {                  \
      hitpointName="HitChest";     \
      armor=20;                    \
      passThrough=0.30000001;      \
    };                             \
    class Diaphragm {              \
      hitpointName="HitDiaphragm"; \
      armor=20;                    \
      passThrough=0.30000001;      \
    };                             \
    class Abdomen {                \
      hitpointName="HitAbdomen";   \
      armor=20;                    \
      passThrough=0.30000001;      \
    };                             \
    class Body {                   \
      hitpointName="HitBody";      \
      passThrough=0.30000001;      \
      armor=20;                    \
    };                             \
    class Legs {                   \
      hitpointName="HitLegs";      \
      armor=10;                    \
      passThrough=0.60000002;      \
    };                             \
  };

// Macro for the invisible vest’s item info
#define INVIS_VEST_ITEM_INFO \
  class ItemInfo: VestItem { \
    vestType="Rebreather"; \
    uniformModel = "\halo_marine\null.p3d"; \
    containerClass="twelfth_vest_supply"; \
    mass=80; \
    VEST_HITPOINT_INFO \
  };



/* New vest stuff */



#define NEW_VEST_SETUP              \
	NEW_VEST(BaseSec_1)               \
  NEW_VEST(BaseSec_1_1)               \
  NEW_VEST(BaseSec_1_2)               \
	NEW_VEST(BaseSec_2)               \
  NEW_VEST(BaseSec_2_1)               \
  NEW_VEST(BaseSec_2_2)               \
	NEW_VEST(BaseSec_3)               \
  NEW_VEST(BaseSec_3_1)               \
  NEW_VEST(BaseSec_3_2)               \
	NEW_VEST(GungnirS_1)              \
  NEW_VEST(GungnirS_1_1)              \
  NEW_VEST(GungnirS_1_2)              \
	NEW_VEST(GungnirS_2)              \
  NEW_VEST(GungnirS_2_1)              \
  NEW_VEST(GungnirS_2_2)              \
	NEW_VEST(GungnirS_3)              \
  NEW_VEST(GungnirS_3_1)              \
  NEW_VEST(GungnirS_3_2)              \
	NEW_VEST(GungnirL_1)              \
  NEW_VEST(GungnirL_1_1)              \
  NEW_VEST(GungnirL_1_2)              \
	NEW_VEST(GungnirL_2)              \
  NEW_VEST(GungnirL_2_1)              \
  NEW_VEST(GungnirL_2_2)              \
	NEW_VEST(GungnirL_3)              \
  NEW_VEST(GungnirL_3_1)              \
  NEW_VEST(GungnirL_3_2)              \
	NEW_VEST(Light)

#define ALL_VESTS(CAMO)                                     \
  MEU_VEST_LIGHT(CAMO,1pl,na,"[12th][1PL][Inf] Light Armor")            \
  MEU_VEST_LIGHT(CAMO,1pl,med,"[12th][1PL][Inf][Med] Light Armor")      \
  MEU_VEST_LIGHT(CAMO,2pl,na,"[12th][2PL][Inf] Light Armor")            \
  MEU_VEST_LIGHT(CAMO,2pl,med,"[12th][2PL][Inf][Med] Light Armor")      \
  MEU_VEST_LIGHT(CAMO,hq,na,"[12th][HQ][Inf] Light Armor")              \
  MEU_VEST_LIGHT(CAMO,hq,med,"[12th][HQ][Inf][Med] Light Armor")        \
  MEU_VEST_LIGHT(CAMO,lpl,na,"[12th][LOGI][Inf] Light Armor")           \
  MEU_VEST_LIGHT(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Light Armor") \
  MEU_VEST_BS1(CAMO,1pl,na,"[12th][1PL][Inf] Base Security Armor")            \
  MEU_VEST_BS1(CAMO,1pl,med,"[12th][1PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS1(CAMO,2pl,na,"[12th][2PL][Inf] Base Security Armor")            \
  MEU_VEST_BS1(CAMO,2pl,med,"[12th][2PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS1(CAMO,hq,na,"[12th][HQ][Inf] Base Security Armor")              \
  MEU_VEST_BS1(CAMO,hq,med,"[12th][HQ][Inf][Med] Base Security Armor")        \
  MEU_VEST_BS1(CAMO,lpl,na,"[12th][LOGI][Inf] Base Security Armor")           \
  MEU_VEST_BS1(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS2(CAMO,1pl,na,"[12th][1PL][Inf] Base Security Armor")            \
  MEU_VEST_BS2(CAMO,1pl,med,"[12th][1PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS2(CAMO,2pl,na,"[12th][2PL][Inf] Base Security Armor")            \
  MEU_VEST_BS2(CAMO,2pl,med,"[12th][2PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS2(CAMO,hq,na,"[12th][HQ][Inf] Base Security Armor")              \
  MEU_VEST_BS2(CAMO,hq,med,"[12th][HQ][Inf][Med] Base Security Armor")        \
  MEU_VEST_BS2(CAMO,lpl,na,"[12th][LOGI][Inf] Base Security Armor")           \
  MEU_VEST_BS2(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Base Security Armor")     \
  MEU_VEST_BS3(CAMO,1pl,na,"[12th][1PL][Inf] Base Security Armor")            \
  MEU_VEST_BS3(CAMO,1pl,med,"[12th][1PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS3(CAMO,2pl,na,"[12th][2PL][Inf] Base Security Armor")            \
  MEU_VEST_BS3(CAMO,2pl,med,"[12th][2PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS3(CAMO,hq,na,"[12th][HQ][Inf] Base Security Armor")              \
  MEU_VEST_BS3(CAMO,hq,med,"[12th][HQ][Inf][Med] Base Security Armor")        \
  MEU_VEST_BS3(CAMO,lpl,na,"[12th][LOGI][Inf] Base Security Armor")           \
  MEU_VEST_BS3(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Base Security Armor")     \
  MEU_VEST_GUNGNIR1(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR1(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR1(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR1(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR1(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Armor")              \
  MEU_VEST_GUNGNIR1(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Armor")        \
  MEU_VEST_GUNGNIR1(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Armor")           \
  MEU_VEST_GUNGNIR1(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Armor")     \
  MEU_VEST_GUNGNIR2(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR2(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR2(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR2(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR2(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Armor")              \
  MEU_VEST_GUNGNIR2(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Armor")        \
  MEU_VEST_GUNGNIR2(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Armor")           \
  MEU_VEST_GUNGNIR2(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Armor")     \
  MEU_VEST_GUNGNIR3(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR3(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR3(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR3(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR3(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Armor")              \
  MEU_VEST_GUNGNIR3(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Armor")        \
  MEU_VEST_GUNGNIR3(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Armor")           \
  MEU_VEST_GUNGNIR3(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Armor")     \
  MEU_VEST_GUNGNIR1_L(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR1_L(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR1_L(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR1_L(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR1_L(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Large Armor")              \
  MEU_VEST_GUNGNIR1_L(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Large Armor")        \
  MEU_VEST_GUNGNIR1_L(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor")           \
  MEU_VEST_GUNGNIR1_L(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Large Armor")     \
  MEU_VEST_GUNGNIR2_L(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR2_L(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR2_L(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR2_L(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR2_L(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Large Armor")              \
  MEU_VEST_GUNGNIR2_L(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Large Armor")        \
  MEU_VEST_GUNGNIR2_L(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor")           \
  MEU_VEST_GUNGNIR2_L(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Large Armor")     \
  MEU_VEST_GUNGNIR3_L(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR3_L(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR3_L(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR3_L(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR3_L(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Large Armor")              \
  MEU_VEST_GUNGNIR3_L(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Large Armor")        \
  MEU_VEST_GUNGNIR3_L(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor")           \
  MEU_VEST_GUNGNIR3_L(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Large Armor")     \



#define NEW_VEST(ARMOUR) 						                                                  \
  class TCP_V_M43A_##ARMOUR##_Base;

#define MEU_VEST_LIGHT(CAMO,PLATOON,ROLE,DISPLAYNAME)                                       \
  class twelfth_M43A_Light_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_Light_Base      \
  {                                                                                   \
    scope = 2;                                                                        \
    scopeArsenal = 2;                                                                 \
    author = "Sammy";                                                                 \
    displayName = DISPLAYNAME;                                                        \
    ACE_GForceCoef = 0.4;                                                             \
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_Light.p3d";             \
    hiddenSelections[] = {"camo","decals"};                                           \
    hiddenSelectionsTextures[] =                                                    \
    {                                                                               \
      VEST_PATH_01(CAMO),                               \
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH                                                                 \
    };  \
    class ItemInfo: VestItem                                                          \
    {                                                                                 \
      mass = 80;                                                                      \
      containerClass="twelfth_vest_supply";                                \
      setMaxLoad=200;\
      VEST_HITPOINT_INFO                                                              \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_Light.p3d";    \
      hiddenSelections[] = {"camo","decals"};                                           \
      hiddenSelectionsTextures[] =                                                    \
      {                                                                               \
        VEST_PATH_01(CAMO),                               \
        HELM_DEC_PATH                                                                 \
      };                                                                              \
    };                                                                                \
  };


#define MEU_VEST_BS1(CAMO,PLATOON,ROLE,DISPLAYNAME)                                         \
	class twelfth_M43A_BaseSec1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_1_Base {     \
    scope = 2;                                                                              \
    scopeArsenal = 2;                                                                       \
    author = "Sammy";                                                                       \
    displayName = DISPLAYNAME;                                                              \
    ACE_GForceCoef = 0.4;                                                                   \
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";               \
		hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored","collarflak"};                                         \
    hiddenSelectionsTextures[] =                                                            \
    {                                                                                       \
      VEST_PATH_01(CAMO),                            \
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),    \
      VEST_PATH_03(CAMO),                  \
      HELM_DEC_PATH                                                                         \
    };                                                                                      \
    class ItemInfo: VestItem                                                                \
    {                                                                                       \
      mass = 80;                                                                            \
      containerClass="twelfth_vest_supply";                                \
      setMaxLoad=200;\
      VEST_HITPOINT_INFO                                                                    \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";      \
      hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored","collarflak"};                                       \
		  hiddenSelectionsTextures[] = {                                                        \
        VEST_PATH_01(CAMO),                          \
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),                    \
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH                                                                       \
      };                                                                                    \
    };                                                                                      \
  };\
  class twelfth_M43A_BaseSec1_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_1_1_Base {     \
      scope = 2;                                                                              \
      scopeArsenal = 2;                                                                       \
      author = "Sammy";                                                                       \
      displayName = DISPLAYNAME;                                                              \
      ACE_GForceCoef = 0.4;                                                                   \
      model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";               \
      hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored"};                                         \
      hiddenSelectionsTextures[] =                                                            \
      {                                                                                       \
        VEST_PATH_01(CAMO),                            \
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),    \
        VEST_PATH_03(CAMO),                  \
        HELM_DEC_PATH                                                                         \
      };                                                                                      \
      class ItemInfo: VestItem                                                                \
      {                                                                                       \
        mass = 80;                                                                            \
        containerClass="twelfth_vest_supply";                                \
        setMaxLoad=200;\
        VEST_HITPOINT_INFO                                                                    \
        uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";      \
        hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored"};                                       \
        hiddenSelectionsTextures[] = {                                                        \
          VEST_PATH_01(CAMO),                          \
          QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),                    \
          VEST_PATH_03(CAMO),\
          HELM_DEC_PATH                                                                       \
        };                                                                                    \
      };                                                                                      \
    };\
    class twelfth_M43A_BaseSec1_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_1_2_Base {     \
    scope = 2;                                                                              \
    scopeArsenal = 2;                                                                       \
    author = "Sammy";                                                                       \
    displayName = DISPLAYNAME;                                                              \
    ACE_GForceCoef = 0.4;                                                                   \
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";               \
		hiddenSelections[] = {"camo","camo1","camo2","decals","collarflak"};                                         \
    hiddenSelectionsTextures[] =                                                            \
    {                                                                                       \
      VEST_PATH_01(CAMO),                            \
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),    \
      VEST_PATH_03(CAMO),                  \
      HELM_DEC_PATH                                                                         \
    };                                                                                      \
    class ItemInfo: VestItem                                                                \
    {                                                                                       \
      mass = 80;                                                                            \
      containerClass="twelfth_vest_supply";                                \
      setMaxLoad=200;\
      VEST_HITPOINT_INFO                                                                    \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";      \
      hiddenSelections[] = {"camo","camo1","camo2","decals","collarflak"};                                       \
		  hiddenSelectionsTextures[] = {                                                        \
        VEST_PATH_01(CAMO),                          \
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),                    \
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH                                                                       \
      };                                                                                    \
    };                                                                                      \
  };

#define MEU_VEST_BS2(CAMO,PLATOON,ROLE,DISPLAYNAME)                                       \
  class twelfth_M43A_BaseSec2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH};\
      };\
  };\
  class twelfth_M43A_BaseSec2_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_2_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH};\
      };\
  };\
  class twelfth_M43A_BaseSec2_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_2_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH};\
      };\
  };


#define MEU_VEST_BS3(CAMO,PLATOON,ROLE,DISPLAYNAME)    \
  class twelfth_M43A_BaseSec3_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_3_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_BaseSec3_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_3_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_BaseSec3_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_3_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR1(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirS_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirS_1_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_1_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirS_1_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_1_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\


#define MEU_VEST_GUNGNIR2(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirS_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BGungnirS_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
		  hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirS_2_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_2_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BGungnirS_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
		  hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirS_2_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_2_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BGungnirS_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
		  hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR3(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirS_3_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_3_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = { \
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = { \
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirS_3_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_3_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
    hiddenSelectionsTextures[] = { \
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
      hiddenSelectionsTextures[] = { \
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirS_3_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_3_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
    hiddenSelectionsTextures[] = { \
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
      hiddenSelectionsTextures[] = { \
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR1_L(CAMO,PLATOON,ROLE,DISPLAYNAME) \
   class twelfth_M43A_GungnirL_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirL_1_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_1_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals","collararmored"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirL_1_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_1_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR2_L(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirL_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
   class twelfth_M43A_GungnirL_2_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_2_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
   class twelfth_M43A_GungnirL_2_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_2_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR3_L(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirL_3_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_3_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirL_3_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_3_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collararmored"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };\
  class twelfth_M43A_GungnirL_3_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_3_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      VEST_PATH_03(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass="twelfth_vest_supply";                                \
      mass = 80;\
      VEST_HITPOINT_INFO \
      setMaxLoad=200;\
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","camo3","decals","collarflak"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        VEST_PATH_03(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


