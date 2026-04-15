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

// stands for 'extended path', used to denote background image
// paths for extended arsenal icon backgrounds
#define XTP(SFX) Q(\x\12thMEU\addons\12th_armor\xtd_icons\##SFX.paa)

//Common texture paths
#define HELM_DEC_PATH "tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\White\vest_M43_DecalSheet_CA.paa"

// Main vest
#define VEST_PATH_01(CAMO)\
  QP(data\vests\##CAMO\vest_01_co.paa) 

// armored thighs, shins (used in _2, _3, _2_1, _2_2, etc.)
#define VEST_PATH_02(CAMO)\
  QP(data\vests\##CAMO\vest_02_co.paa) 

// collars and some straps, idk
#define VEST_PATH_03(CAMO)\
  QP(data\vests\##CAMO\vest_03_co.paa)  

// shoulder armore for sec, grungir S and L
#define VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE)\
  QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_##FULLTYPE##_co.paa)

#define MODEL_PATH_01(ARMOR,arg1) \
  Q(\TCP\Characters\BLUFOR\UNSC\Army\Vests\##ARMOR##\##ARMOR##_##arg1##.p3d)

/*
#define GUNGNIR_PATH(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa) 

#define VEST_PATH_02(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa)

#define BASESEC_PATH(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa)
*/

// Standard vest attributes
#define VEST_MASS 80      // The vest’s "mass" for ACE/Arma calculations
#define VEST_MAXLOAD 200  // The vest’s carrying capacity (in “inventory units”)

// Macro for the hitpoint data applied to vests
#define VEST_HITPOINT_INFO \
  class HitpointsProtectionInfo { \
    class Neck { \
      hitpointName="HitNeck"; \
      armor=20; \
      passThrough=0.30000001; \
    }; \
    class Arms { \
      hitpointName="HitArms"; \
      armor=10; \
      passThrough=0.60000002; \
    }; \
    class Chest { \
      hitpointName="HitChest"; \
      armor=20; \
      passThrough=0.30000001; \
    }; \
    class Diaphragm { \
      hitpointName="HitDiaphragm"; \
      armor=20; \
      passThrough=0.30000001; \
    }; \
    class Abdomen { \
      hitpointName="HitAbdomen"; \
      armor=20; \
      passThrough=0.30000001; \
    }; \
    class Body { \
      hitpointName="HitBody"; \
      passThrough=0.30000001; \
      armor=20; \
    }; \
    class Legs { \
      hitpointName="HitLegs"; \
      armor=10; \
      passThrough=0.60000002; \
    }; \
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

  // adds class references that are used in our 12th vest reimplementations
  #define GENERATE_VEST_REFERENCE_INSTANCE(ARMOUR) \
  class TCP_V_M43A_##ARMOUR##_Base;

  /* generate all vest references */
  #define GENERATE_VEST_REFERENCES \
	GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_1_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_1_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_2_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_2_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_3) \
  GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_3_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(BaseSec_3_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_1_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_1_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_2_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_2_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_3) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_3_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirS_3_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_1_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_1_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_2_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_2_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_3) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_3_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(GungnirL_3_2) \
	GENERATE_VEST_REFERENCE_INSTANCE(Light) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_1_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_1_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_2_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_2_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_3) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_3_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Light_3_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_1_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_1_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_2_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_2_2) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_3) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_3_1) \
  GENERATE_VEST_REFERENCE_INSTANCE(Pads_3_2) 


  /* Generic functions used to generate our 12th vest classes */

  // 1 camo variant, uses only vest_01_co.paa
  // belt off, leg armor off, shoulder armor off
  #define CLASS_VEST_GENERIC_OOO(VARIANT,SCOPEVAL,CAMO,ARMOR,FULLTYPE,PLATOON,ROLE,DISPLAYNAME,arg1) \
  class twelfth_##ARMOR##_##arg1##_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO) \
        }; \
      }; \
    };

// 2 camo version, uses vest_01_co.paa and vest_03_co.paa
// belt on, leg armor off, shoulder armor off
#define CLASS_VEST_GENERIC_BOO(VARIANT,SCOPEVAL,CAMO,ARMOR,FULLTYPE,PLATOON,ROLE,DISPLAYNAME,arg1) \
  class twelfth_##ARMOR##_##arg1##_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","collararmored","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","collararmored","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_1_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","collararmored"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","collararmored"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_2_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; 

    // 2 camo version, uses vest_01_co.paa and vest_03_co.paa
// belt on, leg armor on, shoulder armor off
#define CLASS_VEST_GENERIC_BLO(VARIANT,SCOPEVAL,CAMO,ARMOR,FULLTYPE,PLATOON,ROLE,DISPLAYNAME,arg1) \
  class twelfth_##ARMOR##_##arg1##_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_02(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_02(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_1_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_02(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_02(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_2_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_02(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_02(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; 

  // 3 camo variant, uses vest_01_co.paa, vest_02_co.paa and vest_03_co.paa
  // belt on, leg armor off, shoulder armor on
  #define CLASS_VEST_GENERIC_BOS(VARIANT,SCOPEVAL,CAMO,ARMOR,FULLTYPE,PLATOON,ROLE,DISPLAYNAME,arg1) \
  class twelfth_##ARMOR##_##arg1##_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_1_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","collararmored"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_2_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; 

  // 3 camo variant, uses vest_01_co.paa, dedicated paa for the shoulder and vest_03_co.paa
  // belt on, leg armor on, shoulder armor on
  #define CLASS_VEST_GENERIC_BLS(VARIANT,SCOPEVAL,CAMO,ARMOR,FULLTYPE,PLATOON,ROLE,DISPLAYNAME,arg1) \
  class twelfth_##ARMOR##_##arg1##_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","camo3","collararmored","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
        VEST_PATH_02(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","camo3","collararmored","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
          VEST_PATH_02(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_1_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","camo3","collararmored"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
        VEST_PATH_02(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","camo3","collararmored"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
          VEST_PATH_02(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; \
    class twelfth_##ARMOR##_##arg1##_2_##CAMO##_##PLATOON##_##ROLE##: TCP_##VARIANT##_##ARMOR##_##arg1##_Base \
    { \
      scope = #SCOPEVAL; \
      scopeArsenal = #SCOPEVAL; \
      author = "Sammy"; \
      displayName = DISPLAYNAME; \
      ACE_GForceCoef = 0.4; \
      model = MODEL_PATH_01(ARMOR,arg1); \
      hiddenSelections[] = {"decals","camo","camo1","camo2","camo3","collarflak"}; \
      hiddenSelectionsTextures[] = \
      { \
        HELM_DEC_PATH, \
        VEST_PATH_01(CAMO), \
        VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
        VEST_PATH_02(CAMO), \
        VEST_PATH_03(CAMO) \
      }; \
      class ItemInfo: VestItem \
      { \
        mass = 80; \
        containerClass="twelfth_vest_supply"; \
        setMaxLoad=200; \
        VEST_HITPOINT_INFO \
        uniformModel = MODEL_PATH_01(ARMOR,arg1); \
        hiddenSelections[] = {"decals","camo","camo1","camo2","camo3","collarflak"}; \
        hiddenSelectionsTextures[] = \
        { \
          HELM_DEC_PATH, \
          VEST_PATH_01(CAMO), \
          VEST_PATH_SHOULDER_01(CAMO,PLATOON,ROLE,FULLTYPE), \
          VEST_PATH_02(CAMO), \
          VEST_PATH_03(CAMO) \
        }; \
      }; \
    }; 

  /* Generate all vest classes. Ordering is CAMO > VEST > TYPE > ELEMENT > ROLE */
  #define GENERATE_VEST_CLASSES(CAMO) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,na,na,"[12th][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,na,na,"[12th][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,na,na,"[12th][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,na,na,"[12th][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,na,med,"[12th][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,na,med,"[12th][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,na,med,"[12th][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,na,med,"[12th][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,1pl,na,"[12th][1PL][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,1pl,na,"[12th][1PL][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,1pl,na,"[12th][1PL][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,1pl,na,"[12th][1PL][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,1pl,med,"[12th][1PL][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,1pl,med,"[12th][1PL][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,1pl,med,"[12th][1PL][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,1pl,med,"[12th][1PL][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,2pl,na,"[12th][2PL][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,2pl,na,"[12th][2PL][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,2pl,na,"[12th][2PL][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,2pl,na,"[12th][2PL][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,2pl,med,"[12th][2PL][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,2pl,med,"[12th][2PL][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,2pl,med,"[12th][2PL][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,2pl,med,"[12th][2PL][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,hq,na,"[12th][HQ][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,hq,na,"[12th][HQ][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,hq,na,"[12th][HQ][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,hq,na,"[12th][HQ][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,hq,med,"[12th][HQ][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,hq,med,"[12th][HQ][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,hq,med,"[12th][HQ][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,hq,med,"[12th][HQ][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,lpl,na,"[12th][LOGI][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,lpl,na,"[12th][LOGI][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,lpl,na,"[12th][LOGI][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,lpl,na,"[12th][LOGI][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_OOO(V,2,CAMO,M43A,Light,lpl,med,"[12th][LOGI][Inf] Light Armor",Light) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Light,lpl,med,"[12th][LOGI][Inf] Light Armor",Light_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,lpl,med,"[12th][LOGI][Inf] Light Armor",Light_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Light,lpl,med,"[12th][LOGI][Inf] Light Armor",Light_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,1pl,na,"[12th][1PL][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,1pl,na,"[12th][1PL][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,1pl,na,"[12th][1PL][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,1pl,med,"[12th][1PL][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,1pl,med,"[12th][1PL][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,1pl,med,"[12th][1PL][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,2pl,na,"[12th][2PL][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,2pl,na,"[12th][2PL][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,2pl,na,"[12th][2PL][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,2pl,med,"[12th][2PL][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,2pl,med,"[12th][2PL][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,2pl,med,"[12th][2PL][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,hq,na,"[12th][HQ][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,hq,na,"[12th][HQ][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,hq,na,"[12th][HQ][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,hq,med,"[12th][HQ][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,hq,med,"[12th][HQ][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,hq,med,"[12th][HQ][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,lpl,na,"[12th][LOGI][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,lpl,na,"[12th][LOGI][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,lpl,na,"[12th][LOGI][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOO(V,2,CAMO,M43A,Pads,lpl,med,"[12th][LOGI][Inf] Pads Armor",Pads_1) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,lpl,med,"[12th][LOGI][Inf] Pads Armor",Pads_2) \
  CLASS_VEST_GENERIC_BLO(V,2,CAMO,M43A,Pads,lpl,med,"[12th][LOGI][Inf] Pads Armor",Pads_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,1pl,na,"[12th][1PL][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,1pl,na,"[12th][1PL][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,1pl,na,"[12th][1PL][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,1pl,med,"[12th][1PL][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,1pl,med,"[12th][1PL][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,1pl,med,"[12th][1PL][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,2pl,na,"[12th][2PL][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,2pl,na,"[12th][2PL][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,2pl,na,"[12th][2PL][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,2pl,med,"[12th][2PL][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,2pl,med,"[12th][2PL][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,2pl,med,"[12th][2PL][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,hq,na,"[12th][HQ][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,hq,na,"[12th][HQ][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,hq,na,"[12th][HQ][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,hq,med,"[12th][HQ][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,hq,med,"[12th][HQ][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,hq,med,"[12th][HQ][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,lpl,na,"[12th][LOGI][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,lpl,na,"[12th][LOGI][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,lpl,na,"[12th][LOGI][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,BaseSecurity,lpl,med,"[12th][LOGI][Inf] Base Security Armor",BaseSec_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,lpl,med,"[12th][LOGI][Inf] Base Security Armor",BaseSec_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,BaseSecurity,lpl,med,"[12th][LOGI][Inf] Base Security Armor",BaseSec_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,1pl,na,"[12th][1PL][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,na,"[12th][1PL][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,na,"[12th][1PL][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,1pl,med,"[12th][1PL][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,med,"[12th][1PL][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,med,"[12th][1PL][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,2pl,na,"[12th][2PL][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,na,"[12th][2PL][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,na,"[12th][2PL][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,2pl,med,"[12th][2PL][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,med,"[12th][2PL][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,med,"[12th][2PL][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,hq,na,"[12th][HQ][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,na,"[12th][HQ][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,na,"[12th][HQ][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,hq,med,"[12th][HQ][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,med,"[12th][HQ][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,med,"[12th][HQ][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,lpl,na,"[12th][LOGI][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,na,"[12th][LOGI][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,na,"[12th][LOGI][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,lpl,med,"[12th][LOGI][Inf] Gungnir Armor",GungnirS_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,med,"[12th][LOGI][Inf] Gungnir Armor",GungnirS_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,med,"[12th][LOGI][Inf] Gungnir Armor",GungnirS_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,1pl,med,"[12th][1PL][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,med,"[12th][1PL][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,1pl,med,"[12th][1PL][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,2pl,med,"[12th][2PL][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,med,"[12th][2PL][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,2pl,med,"[12th][2PL][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,hq,na,"[12th][HQ][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,na,"[12th][HQ][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,na,"[12th][HQ][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,hq,med,"[12th][HQ][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,med,"[12th][HQ][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,hq,med,"[12th][HQ][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor",GungnirL_3) \
  CLASS_VEST_GENERIC_BOS(V,2,CAMO,M43A,Gungnir,lpl,med,"[12th][LOGI][Inf] Gungnir Large Armor",GungnirL_1) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,med,"[12th][LOGI][Inf] Gungnir Large Armor",GungnirL_2) \
  CLASS_VEST_GENERIC_BLS(V,2,CAMO,M43A,Gungnir,lpl,med,"[12th][LOGI][Inf] Gungnir Large Armor",GungnirL_3)


  // VEST XTD Gear Info functions

  // belt always on generic
  #define CLASS_VEST_XTDGI_02(CAMO,PLATOON,ROLE,TYPE,SHOULDERS,LEGS) \
  class twelfth_M43A_##TYPE##_##CAMO##_##PLATOON##_##ROLE## { \
    model="twelfth_base_vests"; \
    camo=#CAMO; \
    collar="none"; \
    shoulders=#SHOULDERS; \
    belt="belt"; \
    legs=#LEGS; \
    element=#PLATOON; \
    role=#ROLE; \
  }; \
  class twelfth_M43A_##TYPE##_1_##CAMO##_##PLATOON##_##ROLE## { \
    model="twelfth_base_vests"; \
    camo=#CAMO; \
    collar="flak"; \
    shoulders=#SHOULDERS; \
    belt="belt"; \
    legs=#LEGS; \
    element=#PLATOON; \
    role=#ROLE; \
  }; \
  class twelfth_M43A_##TYPE##_2_##CAMO##_##PLATOON##_##ROLE## { \
    model="twelfth_base_vests"; \
    camo=#CAMO; \
    collar="armored"; \
    shoulders=#SHOULDERS; \
    belt="belt"; \
    legs=#LEGS; \
    element=#PLATOON; \
    role=#ROLE; \
  };
  
  // belt off generic, used only in TCP_V_M43A_Light_Base
  #define CLASS_VEST_XTDGI_01(CAMO,PLATOON,ROLE,TYPE) \
  class twelfth_M43A_##TYPE##_##CAMO##_##PLATOON##_##ROLE## { \
    model="twelfth_base_vests"; \
    camo=#CAMO; \
    collar="none"; \
    shoulders="Light"; \
    belt="none"; \
    legs="none"; \
    element=#PLATOON; \
    role=#ROLE; \
  }; \

  // Generate all XTD Gear Info classes
  #define GENERATE_VEST_XTDGI(CAMO) \
  CLASS_VEST_XTDGI_01(CAMO,na,na,Light) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,na,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,na,med,Light) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,na,med,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,1pl,na,Light) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,na,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,1pl,med,Light) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,1pl,med,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,2pl,na,Light) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,na,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,2pl,med,Light) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,2pl,med,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,hq,na,Light) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,na,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,hq,med,Light) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,hq,med,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,lpl,na,Light) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,na,GungnirL_3,GungnirL,full) \
  CLASS_VEST_XTDGI_01(CAMO,lpl,med,Light) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,Light_1,Light,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,Light_2,Light,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,Light_3,Light,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,Pads_1,Pads,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,Pads_2,Pads,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,Pads_3,Pads,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,BaseSec_1,BaseSec,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,BaseSec_2,BaseSec,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,BaseSec_3,BaseSec,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,GungnirS_1,GungnirS,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,GungnirS_2,GungnirS,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,GungnirS_3,GungnirS,full) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,GungnirL_1,GungnirL,none) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,GungnirL_2,GungnirL,thigh) \
  CLASS_VEST_XTDGI_02(CAMO,lpl,med,GungnirL_3,GungnirL,full)