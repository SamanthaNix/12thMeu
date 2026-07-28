#pragma hemtt suppress pw3_padded_arg config

class CfgMagazines { 
    class 1000Rnd_20mm_shells;
    class 5000Rnd_762x51_Yellow_Belt;
    class SMT_500Rnd_20mm_shells_Dingo: 1000Rnd_20mm_shells {
        tracersEvery = 2;
        count=500;
    };
    class SMT_2000Rnd_762_shells_Dingo: 5000Rnd_762x51_Yellow_Belt {
        tracersEvery = 1;
        count=2000;
    };
};
