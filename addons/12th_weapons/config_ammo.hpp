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
  class OPTRE_B_762x51_Ball;
  class OPTRE_M41_Rocket_HEAT_G;

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

   //Modify standard 40mm grenade ammo to remove bounce
  	class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
	};

  class twelfth_MAAWS_HEAT: R_MRAAWS_HEAT_F{
    hit = 380;
    fuseDistance = 30;
  };

  // 9.5x40mm AP
class twelfth_95x40_AP : OPTRE_B_95x40_Ball {
  caliber = 4.0;
  hit = 20;
};

  // 7.62x51mm AP
  class twelfth_762x51_AP : OPTRE_B_762x51_Ball {
    caliber = 2.1;
    hit = 18;
  };


  class Bomb_03_F;
  class twelfth_W_B250 : Bomb_03_F {
    maneuvrability = 0; // no maneuvrability so that default guidance doesnt work
    class ace_missileguidance {
      enabled = 1; // Explicit enabling of the system
      
      pitchRate = 15; // How many degrees/second the missile can pitch
      yawRate = 20; // How many degrees/second this missile can yaw
      
      canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

      // Guidance type for munitions
      defaultSeekerType = "GPS"; // Default seeker type
      seekerTypes[] = { "SALH", "GPS" };

      defaultSeekerLockMode = "LOAL"; // Default lock mode
      seekerLockModes[] = { "LOAL" };

      defaultNavigationType = "LINE";
      navigationTypes[] = { "LINE" };

      lineGainP = 50;
      lineGainD = 0;

      useModeForAttackProfile = 1;

      seekLastTargetPos = 1;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
      seekerAngle = 70;           // Angle in front of the missile which can be searched
      seekerAccuracy = 1;         // seeker accuracy multiplier

      seekerMinRange = 5;         // Minimum range from the missile which the seeker can visually search
      seekerMaxRange = 4000;      // Maximum range from the missile which the seeker can visually search

      // Attack profile type selection
      defaultAttackProfile = "JDAM";
      attackProfiles[] = {"JDAM"};
    };
    hit = 5000;
    indirectHit = 1200;
    indirectHitRange = 12;
  };

  class Bomb_04_F;
  class twelfth_W_B500 : Bomb_04_F {
    maneuvrability = 0; // no maneuvrability so that default guidance doesnt work
    class ace_missileguidance {
      enabled = 1; // Explicit enabling of the system
      
      pitchRate = 15; // How many degrees/second the missile can pitch
      yawRate = 20; // How many degrees/second this missile can yaw

      canVanillaLock = 0;          // Can this default vanilla lock? Only applicable to non-cadet mode

      // Guidance type for munitions
      defaultSeekerType = "GPS"; // Default seeker type
      seekerTypes[] = { "SALH", "GPS" };

      defaultSeekerLockMode = "LOAL"; // Default lock mode
      seekerLockModes[] = { "LOAL" };

      defaultNavigationType = "LINE";
      navigationTypes[] = { "LINE" };

      lineGainP = 50;
      lineGainD = 0;

      useModeForAttackProfile = 1;

      seekLastTargetPos = 1;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
      seekerAngle = 70;           // Angle in front of the missile which can be searched
      seekerAccuracy = 1;         // seeker accuracy multiplier

      seekerMinRange = 5;         // Minimum range from the missile which the seeker can visually search
      seekerMaxRange = 4000;      // Maximum range from the missile which the seeker can visually search

      // Attack profile type selection
      defaultAttackProfile = "JDAM";
      attackProfiles[] = {"JDAM"};
    };
    hit = 5000;
    indirectHit = 1200;
    indirectHitRange = 12;
  };

  class FlareBase;
  class F_HuntIR: FlareBase {
    class Eventhandlers;
  };
  class F_HuntIR_mortar : F_HuntIR {
    author = "Hen gizzard and Turnip wizard";
    timeToLive = 15;
    class Eventhandlers {
      fired = "[gunner (_this#0), _this#1, _this#2, _this#3, _this#4, _this#5, _this#6] call ACE_huntir_fnc_handleFired;";
    };
  };

  class twelfth_M41_IR_rocket : OPTRE_M41_Rocket_HEAT_G {
    author = "Rex";
    hit = 150;
		indirectHit = 100;
		proximityExplosionDistance = 12;
		indirectHitRange = 12;
		explosive= 0.80000001;
		irLock = 1;
		airLock = 1;
		laserLock = 0;
		nvLock = 0;
		cmImmunity = 0.8;
		simulationStep = 0.002;
		airFriction = 0.064999998;
		sideAirFriction = 0.2;
		manualControl = 0;
		maneuvrability = 15;
		missileKeepLockedCone = 75;
		missileLockCone = 15;
		missileLockMaxDistance = 5000;
		missileLockMinDistance = 50;
		missileLockMaxSpeed = 150;
		trackOversteer = 0.9;
		trackLead = 0.8;
		weaponLockSystem = "2 + 16";
		timeToLive = 30;
		initTime = 0.2;
		thrustTime = 1.5;
		thrust = 150;
		maxSpeed = 200;
  };
};
