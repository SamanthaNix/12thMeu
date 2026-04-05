class CfgAmmo
{
	class BulletBase;
	class StandardLiquidLaserAmmo: BulletBase
	{
		hit = 300;indirectHit = 0;indirectHitRange = 0; 
		cartridge = "FxCartridge_65_caseless"; /// seems like standard 6.5mm round
		visibleFire = 5; /// how big does the shooter seem to be for AI to take notice after he shoots
		audibleFire = 8; /// how big does the shooter seem to be for AI to take notice after he shoots
		cost = 100; 
		typicalSpeed = 2000;
		caliber = 2.0; /// caliber 1 equals 6.5mm round
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red"; /// just for tracer
		tracerScale = 10; /// how big is the flying tracer
		tracerStartTime = 0.05; // seconds
		tracerEndTime = 1; // seconds
		airFriction = 0;
	    explosionEffects = "GrenadeExplosion";
		/* z:
			air friction value was set carefully to match RL ballistic table with high fidelity
			source: http://www.shootingtimes.com/wp-content/blogs.dir/11/files/6-5mm-grendel-the-round-the-military-ought-to-have/6-5mm-grendel_009.jpg
		*/
		
		dangerRadiusBulletClose 		= 8;	/// defines how far the AI gets alerted by the projectile's impact or explosion. Default value -1 makes this distance be automatically derived from the hit and indirectHit properties.
		dangerRadiusHit 				= 12;	/// defines how far the AI gets alerted by the bullet's pass. Default value -1 disables the detection. (works only for bullets, no other projectiles)
		suppressionRadiusBulletClose 	= 6;	/// defines the max. distance at which the AI becomes suppressed by the projectile's impact or explosion. Default value -1 disables the suppressive effect
		suppressionRadiusHit 			= 8;	/// defines the max. distance at which the AI becomes suppressed by the bullet's pass. Default value -1 disables the suppressive effect (works only for bullets, no other projectiles)
		shootDistraction 				= 10;	/// -1 by default to be computed from visibleFire and audibleFire, describes how much does the shoot distract the shooter
		
		/////////////////////ACE STUFF//////////////////////////////
 		ACE_caliber = 13;
		ACE_bulletLength = 70.012;
		ACE_bulletMass = 60.0176;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={1.01};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={2000};
        ACE_barrelLengths[]={736.6}; 
		ACE_damageType ="bullet";
		/////////////////////ACE STUFF//////////////////////////////
		class CamShakeFire /// doesn't cause any camera shake
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire /// doesn't cause any camera shake
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		
	};
	class CompressedLiquidLaserAmmo: BulletBase
	{
		explosive= 0.4;
		hit = 700;indirectHit = 100;indirectHitRange = 2; 
		cartridge = "FxCartridge_65_caseless"; /// seems like standard 6.5mm round
		visibleFire = 5; /// how big does the shooter seem to be for AI to take notice after he shoots
		audibleFire = 8; /// how big does the shooter seem to be for AI to take notice after he shoots
		cost = 100; 
		typicalSpeed = 3000;
		caliber = 2.0; /// caliber 1 equals 6.5mm round
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red"; /// just for tracer
		tracerScale = 10; /// how big is the flying tracer
		tracerStartTime = 0.05; // seconds
		tracerEndTime = 1; // seconds
		airFriction = 0;
	    explosionEffects = "ExplosionEffects";
		/* z:
			air friction value was set carefully to match RL ballistic table with high fidelity
			source: http://www.shootingtimes.com/wp-content/blogs.dir/11/files/6-5mm-grendel-the-round-the-military-ought-to-have/6-5mm-grendel_009.jpg
		*/
		
		dangerRadiusBulletClose 		= 8;	/// defines how far the AI gets alerted by the projectile's impact or explosion. Default value -1 makes this distance be automatically derived from the hit and indirectHit properties.
		dangerRadiusHit 				= 12;	/// defines how far the AI gets alerted by the bullet's pass. Default value -1 disables the detection. (works only for bullets, no other projectiles)
		suppressionRadiusBulletClose 	= 6;	/// defines the max. distance at which the AI becomes suppressed by the projectile's impact or explosion. Default value -1 disables the suppressive effect
		suppressionRadiusHit 			= 8;	/// defines the max. distance at which the AI becomes suppressed by the bullet's pass. Default value -1 disables the suppressive effect (works only for bullets, no other projectiles)
		shootDistraction 				= 10;	/// -1 by default to be computed from visibleFire and audibleFire, describes how much does the shoot distract the shooter
		
		/////////////////////ACE STUFF//////////////////////////////
 		ACE_caliber = 13;
		ACE_bulletLength = 70.012;
		ACE_bulletMass = 60.0176;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={1.01};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={3000};
        ACE_barrelLengths[]={736.6}; 
		ACE_damageType ="explosive";
		/////////////////////ACE STUFF//////////////////////////////
		class CamShakeFire /// doesn't cause any camera shake
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire /// doesn't cause any camera shake
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		
	};
};
