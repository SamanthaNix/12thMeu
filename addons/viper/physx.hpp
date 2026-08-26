    simulation = "tankX";
    maxSpeed = 145;
    enginePower = 1309;
    maxOmega = __EVAL((6400 * 2 * PI) / 60);
	minOmega = __EVAL((850 * 2 * PI) / 60);
    idleRpm = 850;
    redRpm = 6400;
    peakTorque = 2500;
    torqueCurve[] = {
			{0.347826,0.735294},
			{0.434783,0.911765},
			{0.521739,1},
			{0.608696,1},
			{0.695652,0.985294},
			{0.782609,0.926471},
			{0.869565,0.823529},
			{1,0.676471}
		};

    thrustDelay			= 0.1;    	/// how much time does it take to get the full thrust (default 1), used to reduce initial wheel slipping
    clutchStrength 		= 180.0;
    fuelCapacity		= 1885;
    brakeIdleSpeed		= 1.78; 	/// speed in m/s below which braking is applied
    latency 			= 0.1;
    changeGearOmegaRatios[] = { 1, 0.16, 0.16, 0, 0.92, 0.18, 0.88, 0.42, 0.86, 0.4, 0.84, 0.38, 0.82, 0.36 };

    tankTurnForce = 2800000;

    class complexGearbox
    {
        GearboxRatios[] = {"R1",-6,"N",0,"D1",8.1,"D2",3.51,"D3",1.90,"D4",1.44,"D5",1.00,"D6",0.74,"D7",0.64};
        TransmissionRatios[] = {"High",4.111}; // Optional: defines transmission ratios (for example, High and Low range as commonly found in offroad vehicles)
        gearBoxMode        = "auto"; //gearbox can be of type: full-auto (only requires 'W' or 'S'), auto (requires shift between drive and reverse), semi-auto, manual
        moveOffGear        = 1; // defines what gear an automatic or semi-automatic gearbox will move off from stationary in. 1 by default.
        driveString        = "D"; // string to display in the HUD for forward gears.
        neutralString      = "N"; // string to display in the HUD for neutral gear.
        reverseString      = "R"; // string to display in the HUD for reverse gears.
    };

    class Wheels
    {
        class L1
        {
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// General parameters
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// <Description>: Name of the bone, used for wheel and suspension animations.
				// <Type>: string
				// <Default>: ""
				boneName = "wheel_1_1_damper";

				// <Description>: If true, wheel is steerable, false - wheel is fixed.
				// <Type>: bool
				// <Default>: (required)
				steering = 0;

				// <Description>: Defines if wheel is on the right or left side of the vehicle
				// <Type>: string
				// <Default>: "right"
				side = "left";

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// Wheel PX parameters
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// <Description>: Center of the wheel (axis)
				// <Type>: memory point
				// <Default>: (required)
				center   = "wheel_1_1_axis";

				// <Description>: Point on the outside rim of the tire, used to calculate radius of the wheel (distance between center and boundary).
				// <Type>: memory point
				// <Default>: (required)
				boundary = "wheel_1_1_bound";

				// <Description>: This is the weight in kg of wheel including both rim and tyre.
				// <Type>: float
				// <Default>: 10.0
				mass = 150;

				// <Description>: This is the wheel's moment of inertia about the rolling axis. Smaller values result in more slips in aggresive driving
				// while larger hamper the gain of speed. Good base to start with is this formula:
				// MOI = 0.5 * Mass * Radius * Radius
				// Some tweaking is needed after the computation, but it is still better than nothing.
				// <Type>: float
				// <Default>: 0.5 * WheelMass * WheelRadius * WheelRadius
				MOI = 25;

				// <Description>:The damping rate describes the rate at which a freely spinning wheel loses rotational speed.
				// Values in range (0.25, 2) seem like sensible values. Experimentation is always a good idea, even outside this range.
				// <Type>: float
				// <Default>: 0.1
				dampingRate = 0.25;
				dampingRateDamaged = 1.0;
				dampingRateDestroyed = 1000.0;
				// <Description>: This is the value of the torque applied to the wheel when the brakes are maximally applied. Higher torques will lock the wheel
				// quicker when braking, while lower torques will take longer to lock the wheel.
				// A value of around 1500 is a good starting point for a vanilla wheel but a google search will reveal typical braking torques. One difficulty is
				// that these are often expressed by manufacturers as braking horsepower or in "pounds inches". The values required here are in "Newton metres".
				// <Type>: float
				// <Default>: 2500
				maxBrakeTorque = 25000;

				// <Description>: This is the same as the max brake torque except for the handbrake rather than the brake. Typically, for a 4-wheeled car,
				// the handbrake is stronger than the brake and is only applied to the rear wheels. A value of 4000 for the rear wheels is a good starting point,
				// while a value of 0 is necessary for the front wheels to make sure they do not react to the handbrake.
				// <Type>: float
				// <Default>: 2*maxBrakeTorque
				maxHandBrakeTorque = 0;

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// Wheel simulation parameters
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// <Description>: This is the direction of the suspension in the downward direction in the rest configuration of the vehicle. A vector that
				// points straight downwards is a good starting point.
				// <Type>: Array[3]
				// <Default>: {0, -1, 0}
				suspTravelDirection[] = {0, -1, 0};

				// <Description>: This is the application point of the suspension force.
				// <Type>: memory point
				// <Default>: center
				suspForceAppPointOffset = "wheel_1_1_axis";

				// <Description>: This is almost the same as the suspension force app point except for the lateral and longitudinal forces that develop on the tire.
				// A good starting point is to duplicate the suspension force application point.
				// <Type>: memory point
				// <Default>: suspForceAppPointOffset
				tireForceAppPointOffset = "wheel_1_1_axis";

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// Suspension parameters
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// <Description>: These values describe the maximum compression and elongation in metres that the spring can support.
				// <Type>: float
				// <Default>: 0.15
				maxCompression = 0.1;
				maxDroop = 0.1;

				// <Description>: This is the mass in kg that is supported by the suspension spring.
				// <Type>: float
				// <Default>: vehicleMass/numberOfWheels
				sprungMass = 2300;

				// <Description>: This is the strength of the suspension spring in Newtons per metre.
				//   springStrength = naturalFrequency * naturalFrequency * sprungMass
				// <Type>: float
				// <Default>: sprungMass*5,0*5,0
				springStrength = 57200;

				// <Description>: This describes the rate at which the spring dissipates the energy stored in the spring.
				// Basic equiation for this is
				//  springDamperRate = dampingRatio * 2 * sqrt(springStrength * sprungMass)
				// where dampingRatio = 1 mean critical damping (critically damped pendulum should get back to start point in every swing)
				// <Type>: float
				// <Default>: 0,4*2*sqrt(springStrength*sprungMass)
				springDamperRate = 12000;

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// Tire parameters
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// <Description>: Increasing this value will result in the tire attempting to generate more longitudinal force when the tire is slipping.
				// Typically, increasing longitudinal stiffness will help the car accelerate and brake. The total tire force available is limited by the
				// load on the tire so be aware that increases in this value might have no effect or even come at the expense of reduced lateral force.
				// <Type>: float
				// <Default>: 10000
				longitudinalStiffnessPerUnitGravity = 10000;

				// <Description>: These values together describe the lateral stiffness per unit lateral slip (in radians) of the tire.
				// <Type>: float, float
				// <Default>: 25, 180
				latStiffX = 25;
				latStiffY = 180;

				// <Description>: These six values describe a graph of friction as a function of longitudinal slip.
				// A good starting point for this is a flat graph of friction vs slip with these values:
				// frictionVsSlipGraph[0][0]=0.0
				// frictionVsSlipGraph[0][1]=1.0
				// frictionVsSlipGraph[1][0]=0.5
				// frictionVsSlipGraph[1][1]=1.0
				// frictionVsSlipGraph[2][0]=1.0
				// frictionVsSlipGraph[2][1]=1.0
				// <Type>: Array[3][2]
				// <Default>: {{0, 1}, {0.5, 1}, {1,1}}
				frictionVsSlipGraph[] =
				{
					{0.0, 1.0},
					{0.075, 2.0},
					{0.75, 1.0}
				};
                weight = 150;
        };
        class R1:L1
        {
            boneName = "wheel_2_1_damper";
            side = "right";
            center = "wheel_2_1_axis";
            boundary = "wheel_2_1_bound";
            suspForceAppPointOffset = "wheel_2_1_axis";
            tireForceAppPointOffset = "wheel_2_1_axis";
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