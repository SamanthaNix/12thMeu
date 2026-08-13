    maxSpeed = 145;
    slowSpeedForwardCoef = 0.3;
    normalSpeedForwardCoef = 0.85;
    brakeIdleSpeed = 0.2;
    thrustDelay = 0.55;
    accelAidForceCoef = 1.5;
    accelAidForceSpd = 5;
    accelAidForceYOffset = -0.2;
    dampersBumpCoef = 0.3;
    waterLeakiness = 10;

    enginePower = 1309;
    maxOmega = 670.206;
    minOmega = 89.012;
    idleRpm = 850;
    redRpm = 6400;
    peakTorque = 2500;
    torqueCurve[] = { { 0.0, 0.55 }, { 0.25, 0.80 }, { 0.45, 1.0 }, { 0.70, 0.92 }, { 1.0, 0.72 } };
    engineMOI = 1;
    dampingRateFullThrottle = 0.08;
    dampingRateZeroThrottleClutchEngaged = 2;
    dampingRateZeroThrottleClutchDisengaged = 0.35;

    clutchStrength = 10;
    switchTime = 0.35;
    latency = 1.2;
    changeGearType = "rpmratio";
    changeGearOmegaRatios[] = { 1, 0.16, 0.16, 0, 0.92, 0.18, 0.88, 0.42, 0.86, 0.4, 0.84, 0.38, 0.82, 0.36 };

    differentialType = "all_open";
    frontRearSplit = 0.42;
    frontBias = 1.3;
    rearBias = 1.3;
    centreBias = 1.3;
    antiRollbarForceCoef = 1.5;
    antiRollbarForceLimit = 2;
    antiRollbarSpeedMin = 10;
    antiRollbarSpeedMax = 60;
    tankTurnForce = 34100000;
    tankTurnForceAngMinSpd = 3;
    tankTurnForceAngSpd = 4;

    class complexGearbox
    {
        GearboxRatios[] = { "R1", -3.23, "N", 0, "D1", 2.46, "D2", 1.87, "D3", 1.24, "D4", 0.97, "D5", 0.71 };
        TransmissionRatios[] = { "High", 4.11 };
        gearBoxMode = "auto";
        moveOffGear = 1;
        driveString = "D";
        neutralString = "N";
        reverseString = "R";
    };

    class Wheels
    {
        class L1
        {
            boneName = "wheel_1_1_damper";
            steering = 0;
            side = "left";
            center = "wheel_1_1_axis";
            boundary = "wheel_1_1_bound";
            mass = 42;
            MOI = 10;
            dampingRate = 0.35;
            dampingRateDamaged = 1;
            dampingRateDestroyed = 1000;
            maxBrakeTorque = 10000;
            maxHandBrakeTorque = 20000;
            suspTravelDirection[] = { 0, -1, 0 };
            suspForceAppPointOffset = "wheel_1_1_axis";
            tireForceAppPointOffset = "wheel_1_1_axis";
            maxCompression = 0.1;
            maxDroop = 0.1;
            sprungMass = 1800;
            springStrength = 45000;
            springDamperRate = 9000;
            longitudinalStiffnessPerUnitGravity = 10000;
            latStiffX = 2.5;
            latStiffY = 180;
            frictionVsSlipGraph[] =
				{
					{0.0, 1.0},
					{0.075, 2.0},
					{0.75, 1.0}
				};
        };
        class R1
        {
            boneName = "wheel_2_1_damper";
            steering = 0;
            side = "right";
            center = "wheel_2_1_axis";
            boundary = "wheel_2_1_bound";
            mass = 42;
            MOI = 10;
            dampingRate = 0.35;
            dampingRateDamaged = 1;
            dampingRateDestroyed = 1000;
            maxBrakeTorque = 10000;
            maxHandBrakeTorque = 20000;
            suspTravelDirection[] = { 0, -1, 0 };
            suspForceAppPointOffset = "wheel_2_1_axis";
            tireForceAppPointOffset = "wheel_2_1_axis";
            maxCompression = 0.1;
            maxDroop = 0.1;
            sprungMass = 1800;
            springStrength = 45000;
            springDamperRate = 9000;
            longitudinalStiffnessPerUnitGravity = 10000;
            latStiffX = 2.5;
            latStiffY = 180;
            frictionVsSlipGraph[] =
				{
					{0.0, 1.0},
					{0.075, 2.0},
					{0.75, 1.0}
				};
        };
        class L2 : L1
        {
            boneName = "wheel_1_2_damper";
            center = "wheel_1_2_axis";
            boundary = "wheel_1_2_bound";
            suspForceAppPointOffset = "wheel_1_2_axis";
            tireForceAppPointOffset = "wheel_1_2_axis";
        };
        class R2 : R1
        {
            boneName = "wheel_2_2_damper";
            center = "wheel_2_2_axis";
            boundary = "wheel_2_2_bound";
            suspForceAppPointOffset = "wheel_2_2_axis";
            tireForceAppPointOffset = "wheel_2_2_axis";
        };
        class L3 : L1
        {
            boneName = "wheel_1_3_damper";
            center = "wheel_1_3_axis";
            boundary = "wheel_1_3_bound";
            suspForceAppPointOffset = "wheel_1_3_axis";
            tireForceAppPointOffset = "wheel_1_3_axis";
        };
        class R3 : R1
        {
            boneName = "wheel_2_3_damper";
            center = "wheel_2_3_axis";
            boundary = "wheel_2_3_bound";
            suspForceAppPointOffset = "wheel_2_3_axis";
            tireForceAppPointOffset = "wheel_2_3_axis";
        };
        class L4 : L1
        {
            boneName = "wheel_1_4_damper";
            center = "wheel_1_4_axis";
            boundary = "wheel_1_4_bound";
            suspForceAppPointOffset = "wheel_1_4_axis";
            tireForceAppPointOffset = "wheel_1_4_axis";
        };
        class R4 : R1
        {
            boneName = "wheel_2_4_damper";
            center = "wheel_2_4_axis";
            boundary = "wheel_2_4_bound";
            suspForceAppPointOffset = "wheel_2_4_axis";
            tireForceAppPointOffset = "wheel_2_4_axis";
        };
        class L5 : L1
        {
            boneName = "wheel_1_5_damper";
            center = "wheel_1_5_axis";
            boundary = "wheel_1_5_bound";
            suspForceAppPointOffset = "wheel_1_5_axis";
            tireForceAppPointOffset = "wheel_1_5_axis";
        };
        class R5 : R1
        {
            boneName = "wheel_2_5_damper";
            center = "wheel_2_5_axis";
            boundary = "wheel_2_5_bound";
            suspForceAppPointOffset = "wheel_2_5_axis";
            tireForceAppPointOffset = "wheel_2_5_axis";
        };
        class L6 : L1
        {
            boneName = "wheel_1_6_damper";
            center = "wheel_1_6_axis";
            boundary = "wheel_1_6_bound";
            suspForceAppPointOffset = "wheel_1_6_axis";
            tireForceAppPointOffset = "wheel_1_6_axis";
        };
        class R6 : R1
        {
            boneName = "wheel_2_6_damper";
            center = "wheel_2_6_axis";
            boundary = "wheel_2_6_bound";
            suspForceAppPointOffset = "wheel_2_6_axis";
            tireForceAppPointOffset = "wheel_2_6_axis";
        };
        class L7 : L1
        {
            boneName = "wheel_1_7_damper";
            center = "wheel_1_7_axis";
            boundary = "wheel_1_7_bound";
            suspForceAppPointOffset = "wheel_1_7_axis";
            tireForceAppPointOffset = "wheel_1_7_axis";
        };
        class R7 : R1
        {
            boneName = "wheel_2_7_damper";
            center = "wheel_2_7_axis";
            boundary = "wheel_2_7_bound";
            suspForceAppPointOffset = "wheel_2_7_axis";
            tireForceAppPointOffset = "wheel_2_7_axis";
        };
    };