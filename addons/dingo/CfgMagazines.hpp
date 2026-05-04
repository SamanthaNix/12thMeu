#pragma hemtt suppress pw3_padded_arg config

class CfgMagazines { 
    class 1000Rnd_20mm_shells;

    class SMT_500Rnd_20mm_shells_Dingo: 1000Rnd_20mm_shells {
        tracersEvery = 2;
        count=500;
    };
};