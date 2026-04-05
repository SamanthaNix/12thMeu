/*
  ==============================================================================
  config_ammo.hpp

  This file defines custom ammo classes. Each class inherits from an ArmA 3 base
  or a modded base (e.g., OPTRE_...).

  Key points:
    - `hit`, `indirectHit`, and `indirectHitRange` define damage values.
    - `caliber` influences how armor is penetrated.
    - `airFriction` affects ballistic drop (negative friction slows the projectile).
    - `typicalSpeed` is muzzle velocity in m/s.
    - `timeToLive` for underwater ammo restricts how far it can travel underwater.

  NOTE: The "base class" references indicate from which class we are inheriting
        default properties. Make sure the base class is loaded by `requiredAddons[]`.
  ==============================================================================
*/
class CfgAmmo
{
   /*
    Pre-declarations for classes we plan to extend (i.e., "inheriting from").
    This ensures the compiler knows these classes exist before we reference them.
  */
  class BulletBase;            // Base class for all bullet-type ammunition. However, this is only used for BB ammo right now
  class OPTRE_B_95x40_Ball;    // Base class for 9.5x40mm Ball ammo
  class OPTRE_B_5x23_Caseless; // Base class for 5x23mm Caseless ammo
  class M319_HEAT;             // Base class for 40mm HEAT grenades
  class R_PG32V_F;
  class SmokeShell;
  class R_MRAAWS_HEAT_F;

  // Training (non-lethal) bullet
  class twelfth_20g_bb : BulletBase
  {
    model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
    cartridge = "";
    hit = 0; // Non-lethal training rounds. I will probably change this later so it bruises
    indirectHit = 0;
    indirectHitRange = 0;
    cost = 100;
    typicalSpeed = 380; // Speed in meters per second
    airFriction = -0.0016;
    caliber = 1.2;
    deflecting = -1;
    airLock = 1;
    tracerScale = 0.75;
    tracerBeginTime = 0.01;
    tracerEndTime = 20;
    nvgOnly = 0;
    audibleFire = 30;
    aiAmmoUsageFlags = 64;
    dangerRadiusBulletClose = 4;
    dangerRadiusHit = 8;
    suppressionRadiusBulletClose = 2;
    suppressionRadiusHit = 4; // Who says you can't suppress someone with BB's?
  };

  // 9.5x40mm Underwater
  class twelfth_95x40_UW : OPTRE_B_95x40_Ball
  {
    typicalSpeed = 700; // Increased muzzle velocity
    waterFriction = -0.00096; // Allows the bullet to travel underwater
    timeToLive = 0.12; // Lifetime in seconds, limiting underwater range
    effectFly = "AmmoUnderwater";
  };
  // 5x23mm Underwater
  class twelfth_5x23mm_UW : OPTRE_B_5x23_Caseless
  {
    typicalSpeed = 700;
    waterFriction = -0.00096;
    timeToLive = 0.12;
    effectFly = "AmmoUnderwater";
  };

  // Custom 40mm High-Explosive Anti-Tank
  class twelfth_40mmG_HEAT : M319_HEAT
  {
    ace_frag_metal = 2000; // Number of fragments
    indirectHitRange = 0.1; // Very small radial damage
    hit = 470; // Direct hit damage
  };
  // Custom rocket for M96 LAW
  class twelfth_m96_rocket_heat: R_PG32V_F {
    hit = 300; // Adjust for desired armor penetration; depends on your game balance.
    thrust=250;
    thrustTime = 1.00000;
  };
   //Modify standard 40mm grenade ammo to remove bounce
  	class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};

  class twelfth_MAAWS_HEAT: R_MRAAWS_HEAT_F{
    hit = 380;
    fuseDistance = 30;
  };


};