/*
  ==============================================================================
  config_macros.hpp

  This file contains macros used to simplify the creation of new helmets,
  including:
    - Texture path macros (HELMTEXPATH, HELMVISORPATH, CH_PILOT_TEX).
    - The big helmet macros (CUSTOM_HELM_S_AV, CH_HELM_S_GI).
    - The pilot helmet macro (CUSTOM_PILOT_HELM).

  The macros expand into full class definitions referencing your custom textures,
  specifying item info, armor, hearing protection, etc.
  ==============================================================================
*/
#define HELMTEXPATH(SUFFIX) \x\12thMEU\addons\12th_custom_helms\data\helms\Helm_co_##SUFFIX.paa
  // Resolves to: "\x\12thMEU\addons\12th_custom_helms\data\helms\Helm_co_<SUFFIX>.paa"

#define HELMVISORPATH(VISOR) \x\12thMEU\addons\12th_custom_helms\data\visors\##VISOR.paa
  // For potential custom visor textures

#define P(PATH) \x\12thMEU\addons\12th_custom_helms\##PATH
  // Standard path concatenation for the twelfth_custom_helms addon

#define CH_PILOT_TEX(CAMOTYPE,FILENAME) P(data\pilots\##CAMOTYPE\##FILENAME)
  // Points to the pilot texture location, e.g.:
  // "\x\12thMEU\addons\12th_custom_helms\data\pilots\<CAMOTYPE>\FILENAME"

#define GLUE(A,B) A##B
#define GLUE3(A,B,C) A##B##C

// Prefix macros for naming clarity
#define S_PREFIX [12th][Inf][S][Cstm]
#define W_PREFIX [12th][Inf][W][Cstm]


//Macro for the TCP decals
#define HELM_DEC_PATH tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\White\vest_M43_DecalSheet_CA.paa

/*
  ==============================================================================
  CUSTOM_HELM_S_AV(SUFFIX)
  ==============================================================================
  Defines two classes:
    1) twelfth_helmCH43A_std_##SUFFIX##     (Standard)
    2) twelfth_helmCH43A_std_##SUFFIX##_clsd  (closed variant)
  Each inherits from `twelfth_helmCH43A_base`.
  The macro references HELMTEXPATH(SUFFIX) for the base color/texture,
  and sets hiddenSelections. The difference in `_nv` variant is that it has
  an additional selection for "camo2" that is set to empty ( "" ).
*/
#define CUSTOM_HELM_S_AV(SUFFIX)                       \
class twelfth_helmCH43A_std_##SUFFIX##: twelfth_helmCH43A_base {  \
    scope=2;                                           \
    author="Sammy";                                     \
    picture="\x\12thMEU\addons\12th_ui\data\logo.paa";                                        \
    scopeArsenal=2;                                    \
    displayName=#GLUE3(S_PREFIX,[SV] ,SUFFIX);         \
  hiddenSelections[] = { "camo","decals" };              \
  hiddenSelectionsTextures[] = {                \
    #HELMTEXPATH(SUFFIX),				\
	  #HELM_DEC_PATH								\
  }; 											\
	class TCP_uniformDecals: TCP_uniformDecals		\
	{												\
		decalColor = "white";						\
	};  											\
  class ItemInfo: HeadgearItem {                \
    uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";   \
    picture="\x\12thMEU\addons\12th_ui\data\logo.paa";                                 \
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
      #HELMTEXPATH(SUFFIX),				\
	    #HELM_DEC_PATH	  						\
    };                                          \
  };   \
};                                                     \
class twelfth_helmECH43A_std_##SUFFIX##_clsd: twelfth_helmECH43A_base { \
  scope=2;                                           \
  author="Sammy";                                     \
  picture="\x\12thMEU\addons\12th_ui\data\logo.paa";                                        \
  scopeArsenal=2;                                    \
  displayName=#GLUE3(S_PREFIX,[CLSD] ,SUFFIX);         \
  model = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_Black.p3d"; \
  hiddenSelections[]= {"camo","camo1","decals"};             \
  hiddenSelectionsTextures[] = {                \
    #HELMTEXPATH(SUFFIX),				\
    "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\black\helmet_ECH43A_Visor_CO.paa",\
    #HELM_DEC_PATH								\
  }; 											\
  class TCP_uniformDecals: TCP_uniformDecals		\
  {												\
    decalColor = "white";						\
  };  											\
  class ItemInfo: HeadgearItem {                \
    uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_Black.p3d";   \
    picture="\x\12thMEU\addons\12th_ui\data\logo.paa";                                 \
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
      #HELMTEXPATH(SUFFIX),				\
      "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\black\helmet_ECH43A_Visor_CO.paa",\
      #HELM_DEC_PATH	  						\
    };                                          \
  };                                            \
};

/*
  ==============================================================================
  CH_HELM_S_GI(SFX)
  ==============================================================================
  Expands to CH_HELM_AV_GI, generating references for XtdGear, marking 
  "visor = 'Yes'" for the standard helmet and "visor = 'No'" for the NV variant.
*/
#define CH_HELM_S_GI(SFX) CH_HELM_AV_GI(SFX,std)

/*
  ==============================================================================
  CH_HELM_AV_GI(SFX, CAMO)
  ==============================================================================
  Creates two gear info classes for XtdGear:
   1) twelfth_ch_<CAMO>_<SFX> 
   2) twelfth_ch_<CAMO>_<SFX>_nv
  Each references the same model ("twelfth_custom_helms"), sets 
  `visor` to "Yes" or "No", and uses `member = SFX`.
*/
#define CH_HELM_AV_GI(SFX,CAMO)       \
class twelfth_helmCH43A_##CAMO##_##SFX {     \
  model="twelfth_custom_helms";       \
  camo=#CAMO;                         \
  closed="No";                        \
  member=#SFX;                        \
};                                    \
class twelfth_helmECH43A_##CAMO##_##SFX##_clsd {\
  model="twelfth_custom_helms";       \
  camo=#CAMO;                         \
  closed="Yes";                         \
  member=#SFX;                        \
};

/*
  ==============================================================================
  CUSTOM_PILOT_HELM(SUFFIX,DISPLAY,C1,C2,C3,C4,C5)
  ==============================================================================
  For pilot helmets, we have a different model (Pilot_Helmet_01) and 
  5 possible texture layers. Each parameter (C1..C5) corresponds to a subfolder
  in data\pilots\[C1..C5]. Each subfolder's .paa name is Addons_co, EXT_co, INT_co,
  MID_co, or Visor_co, respectively.
*/
#define CUSTOM_PILOT_HELM(SUFFIX,DISPLAY,C1,C2,C3,C4,C5)                  \
class 12th_pilot_ch_##SUFFIX : H_HelmetB {                                \
  author="Waylen";                                                          \
  scope=2;                                                                \
  scopeArsenal=2;                                                         \
  picture="\x\12thMEU\addons\12th_ui\data\logo.paa";                                                             \
  ace_hearing_protection=1;                                               \
  ace_hearing_lowerVolume=0.30000001;                                     \
  optreVarietys[] = {"", "", "_broken"};                                  \
  optreHUDStyle = "ODST_1";                                               \
  displayName=DISPLAY;                                                    \
  hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4", "camo5"};     \
  model="\Foundries\DMNS_Units\Armour\Pilot_Helm_01\Pilot_Helmet_01.p3d";          \
  hiddenSelectionsTextures[]={                                            \
      #CH_PILOT_TEX(C1,Addons_co.paa),                                    \
      #CH_PILOT_TEX(C2,EXT_co.paa),                                       \
      #CH_PILOT_TEX(C3,INT_co.paa),                                       \
      #CH_PILOT_TEX(C4,MID_co.paa),                                       \
      #CH_PILOT_TEX(C5,Visor_co.paa)                                      \
  };                                                                      \
  class ItemInfo : HeadgearItem {                                         \
    mass = 25;                                                            \
    modelSides[]={6};                                                     \
    uniformModel="\Foundries\DMNS_Units\Armour\Pilot_Helm_01\Pilot_Helmet_01.p3d"; \
    hiddenSelections[]={"camo1", "camo2", "camo3", "camo4", "camo5"};     \
    hiddenSelectionsTextures[]={                                          \
      #CH_PILOT_TEX(C1,Addons_co.paa),                                    \
      #CH_PILOT_TEX(C2,EXT_co.paa),                                       \
      #CH_PILOT_TEX(C3,INT_co.paa),                                       \
      #CH_PILOT_TEX(C4,MID_co.paa),                                       \
      #CH_PILOT_TEX(C5,Visor_co.paa)                                      \
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
