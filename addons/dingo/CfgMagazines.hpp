#pragma hemtt suppress pw3_padded_arg config

class CfgMagazines { 
    class ACE_500Rnd_20mm_shells_Comanche;

    class SMT_500Rnd_20mm_shells_Dingo: ACE_500Rnd_20mm_shells_Comanche {
        tracersEvery = 2;
    };
};