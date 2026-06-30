class CfgAmmo
{
	class Sh_125mm_HE;
	class M_Titan_AT;
	class Sh_75mm_Railgun_APFSDS;
	class SMT_200mm_HE_Slow: Sh_125mm_HE //Indirect fire HE
	{
		hit = 660;indirectHit = 160;indirectHitRange = 10; 
		typicalSpeed = 420;
		caliber = 16; /// caliber 1 equals 6.5mm round

		dangerRadiusBulletClose 		= -1;	/// defines how far the AI gets alerted by the projectile's impact or explosion. Default value -1 makes this distance be automatically derived from the hit and indirectHit properties.
		dangerRadiusHit 				= 200;	/// defines how far the AI gets alerted by the bullet's pass. Default value -1 disables the detection. (works only for bullets, no other projectiles)
		suppressionRadiusBulletClose 	= -1;	/// defines the max. distance at which the AI becomes suppressed by the projectile's impact or explosion. Default value -1 disables the suppressive effect
		suppressionRadiusHit 			= 46;	/// defines the max. distance at which the AI becomes suppressed by the bullet's pass. Default value -1 disables the suppressive effect (works only for bullets, no other projectiles)
		shootDistraction 				= -1;	/// -1 by default to be computed from visibleFire and audibleFire, describes how much does the shoot distract the shooter
		
		/////////////////////ACE STUFF//////////////////////////////
		ace_frag_charge = 4000;
		ace_rearm_caliber = 200;
		/////////////////////ACE STUFF//////////////////////////////

	};
    class SMT_200mm_HE_fast: SMT_200mm_HE_slow //Fast High explosive
	{
		typicalSpeed = 1400;
		
		/////////////////////ACE STUFF//////////////////////////////
		/////////////////////ACE STUFF//////////////////////////////
	};
    class SMT_200mm_SALH: M_Titan_AT //Laser guided Missile
	{
        airLock = 0;
		autoSeekTarget = 1;
		cmImmunity = 1;
		flightProfiles[] = {"LOALDistance"};
		irLock = 0;
		laserLock=1;
		lockSeekRadius = 3000;
		lockType = 0;
		manualControl = 0;
		maxControlRange = 10000;
		missileKeepLockedCone = 360;
		missileLockCone = 300;
		nvlock = 0;
		trackLead = 0.5;
		trackOversteer = 1;
		weaponLockSystem = "4 + 16";

        
		hit = 300;indirectHit = 50;indirectHitRange = 6; 
		typicalSpeed = 200;
		maxSpeed = 190;
		caliber = 1.5; /// caliber 1 equals 6.5mm round

		dangerRadiusBulletClose 		= -1;	/// defines how far the AI gets alerted by the projectile's impact or explosion. Default value -1 makes this distance be automatically derived from the hit and indirectHit properties.
		dangerRadiusHit 				= -1;	/// defines how far the AI gets alerted by the bullet's pass. Default value -1 disables the detection. (works only for bullets, no other projectiles)
		suppressionRadiusBulletClose 	= -1;	/// defines the max. distance at which the AI becomes suppressed by the projectile's impact or explosion. Default value -1 disables the suppressive effect
		suppressionRadiusHit 			= 40;	/// defines the max. distance at which the AI becomes suppressed by the bullet's pass. Default value -1 disables the suppressive effect (works only for bullets, no other projectiles)
		shootDistraction 				= -1;	/// -1 by default to be computed from visibleFire and audibleFire, describes how much does the shoot distract the shooter
		
		/////////////////////ACE STUFF//////////////////////////////
		ace_rearm_caliber = 200;
		/////////////////////ACE STUFF//////////////////////////////

	};
    class SMT_200mm_APFSDS: Sh_75mm_Railgun_APFSDS //Armour piercing
	{
		hit = 1200;indirectHit = 0;indirectHitRange = 0; 
		typicalSpeed = 3500;
		caliber = 35; /// caliber 1 equals 6.5mm round

		dangerRadiusBulletClose 		= 20;	/// defines how far the AI gets alerted by the projectile's impact or explosion. Default value -1 makes this distance be automatically derived from the hit and indirectHit properties.
		dangerRadiusHit 				= 60;	/// defines how far the AI gets alerted by the bullet's pass. Default value -1 disables the detection. (works only for bullets, no other projectiles)
		suppressionRadiusBulletClose 	= 12;	/// defines the max. distance at which the AI becomes suppressed by the projectile's impact or explosion. Default value -1 disables the suppressive effect
		suppressionRadiusHit 			= 16;	/// defines the max. distance at which the AI becomes suppressed by the bullet's pass. Default value -1 disables the suppressive effect (works only for bullets, no other projectiles)
		shootDistraction 				= -1;	/// -1 by default to be computed from visibleFire and audibleFire, describes how much does the shoot distract the shooter
		
		/////////////////////ACE STUFF//////////////////////////////
		ace_rearm_caliber = 200;
		/////////////////////ACE STUFF//////////////////////////////
	};
};
