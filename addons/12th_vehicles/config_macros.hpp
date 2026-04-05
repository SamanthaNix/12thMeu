/*
  ==============================================================================
  config_macros.hpp

  This file contains macros that handle:
    1. File path building: P() and QP().
    2. Default inventories: STDINV and MEDINV (for medical vehicles).
    3. Any custom macros for vehicle definitions, textures, or properties.

  Notably, `STOMPER_SP_INFO(...)` is alluded to in config.cpp but not defined here;
  you'd add it if you want to apply special side/faction/spawn properties consistently.
  ==============================================================================
*/
#define P(PATH) \x\12thMEU\addons\12th_vehicles\##PATH
    // Concatenates the internal path for your 12th_vehicles addon, e.g.:
    // P(mySubfolder\something.paa) => \x\12thMEU\addons\12th_vehicles\mySubfolder\something.paa
#define QP(PATH) #P(PATH)
    // Wraps the path in quotes to produce a string.

// -----------------------------------------------------------------------------
//  Macro: STDINV
//  This macro sets a “Standard” default inventory for a vehicle’s cargo.
//  Typically includes common magazines, grenades, and some medical items.
// -----------------------------------------------------------------------------
#define STDINV   \
class TransportMagazines {      \
    class _xx_OPTRE_32Rnd_762x51_Mag_Tracer { magazine = "OPTRE_32Rnd_762x51_Mag_Tracer"; count = 10; };    \
    class _xx_OPTRE_36Rnd_95x40_Mag_Tracer { magazine = "OPTRE_36Rnd_95x40_Mag_Tracer"; count = 6; };   \
};  \
class TransportWeapons {    \
    class _xx_twelfth_m96 { weapon = "twelfth_m96"; count = 1; };   \
};  \
class TransportItems{   \
    class _xx_ACE_IR_Strobe_Item { name = "ACE_IR_Strobe_Item"; count = 2; };   \
    class _xx_OPTRE_M9_Frag { name = "OPTRE_M9_Frag"; count = 4; }; \
    class _xx_OPTRE_M2_Smoke { name = "OPTRE_M2_Smoke"; count = 4; };   \
    class _xx_OPTRE_M2_Smoke_Blue { name = "OPTRE_M2_Smoke_Blue"; count = 1; }; \
    class _xx_ACE_M84 { name = "ACE_M84"; count = 4; }; \
    class _xx_kat_IFAK { name = "kat_IFAK"; count = 2; };   \
    class _xx_ACE_plasmaIV_500 { name = "ACE_plasmaIV_500"; count = 2; };   \
    class _xx_ACE_CableTie { name = "ACE_CableTie"; count = 10; };  \
    class _xx_ACE_WaterBottle { name = "ACE_WaterBottle"; count = 2; }; \
};  

// -----------------------------------------------------------------------------
//  Macro: MEDINV
//  This macro sets a “Medical” oriented default inventory for a vehicle’s cargo.
//  Typically used by dedicated medical vehicles or logistic vehicles that
//  specialize in treatment items.
// -----------------------------------------------------------------------------
#define MEDINV   \
class TransportMagazines {      \
    class _xx_OPTRE_32Rnd_762x51_Mag_Tracer { magazine = "OPTRE_32Rnd_762x51_Mag_Tracer"; count = 4; };    \
    class _xx_OPTRE_36Rnd_95x40_Mag_Tracer { magazine = "OPTRE_36Rnd_95x40_Mag_Tracer"; count = 4; };   \
};  \
class TransportItems{   \
    class _xx_kat_IV_16 { name = "kat_IV_16"; count = 10; };        \
    class _xx_kat_AFAK { name = "kat_AFAK"; count = 4; };       \
    class _xx_kat_MFAK { name = "kat_MFAK"; count = 2; };       \
    class _xx_ACE_tourniquet { name = "ACE_tourniquet"; count = 8; };       \
    class _xx_kat_bloodIV_O_N_500 { name = "kat_bloodIV_O_N_500"; count = 10; };        \
    class _xx_ACE_splint { name = "ACE_splint"; count = 8; };       \
    class _xx_ACE_morphine { name = "ACE_morphine"; count = 10; };      \
    class _xx_ACE_adenosine { name = "ACE_adenosine"; count = 10; };        \
    class _xx_ACE_epinephrine { name = "ACE_epinephrine"; count = 10; };        \
    class _xx_ACE_salineIV { name = "ACE_salineIV"; count = 5; };       \
    class _xx_ACE_suture { name = "ACE_suture"; count = 40; };      \
};  \

// -----------------------------------------------------------------------------
//  Macro: WPNSINV
//  This macro sets a Weapons Team oriented default inventory for a vehicle’s cargo.
// -----------------------------------------------------------------------------

#define WPNSINV                                                                                                               \
class TransportMagazines {                                                                                                    \
    class _xx_OPTRE_400Rnd_762x51_M118_M247A1_BOX { magazine = "OPTRE_400Rnd_762x51_M118_M247A1_BOX"; count = 10; };                          \
    class _xx_avm224_M_6Rnd_60mm_HE_0_csw { magazine = "avm224_M_6Rnd_60mm_HE_0_csw"; count = 5; };                           \
    class _xx_avm224_M_6Rnd_60mm_HE_csw { magazine = "avm224_M_6Rnd_60mm_HE_csw"; count = 20; };                              \
    class _xx_OPTRE_M41_Twin_HEAT_G_AA { magazine = "OPTRE_M41_Twin_HEAT_G_AA"; count = 4; };                           \
    class _xx_OPTRE_M41_Twin_HEAT_G { magazine = "OPTRE_M41_Twin_HEAT_G"; count = 4; };                                       \
    class _xx_OPTRE_M41_Twin_HE { magazine = "OPTRE_M41_Twin_HE"; count = 2; };   \
};                                                                                                                            \
class TransportItems{                                                                                                         \
    class _xx_ACE_SpareBarrel { name = "ACE_SpareBarrel"; count = 3; };                                                       \
    class _xx_ACE_WaterBottle { name = "ACE_WaterBottle"; count = 10; };                                                      \
    class _xx_optic_DMS { name = "optic_DMS"; count = 1; };                                                                   \
};                                                                                                                            \
class TransportWeapons {                                                                                                      \
    class _xx_twelfth_M247A1 { weapon = "twelfth_M247A1"; count = 1; };                                                           \
    class _xx_12th_MG_Tripod_Carry { weapon = "12th_MG_Tripod_Carry"; count = 1; };                                           \
    class _xx_avm224_W_M224_mortar_carry { weapon = "avm224_W_M224_mortar_carry"; count = 1; };                               \
    class _xx_OPTRE_M41_SSR { weapon = "OPTRE_M41_SSR"; count = 1; };                                                         \
};
