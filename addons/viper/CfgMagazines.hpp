#pragma hemtt suppress pw3_padded_arg config

class CfgMagazines { 
    class SMT_200mm_HE_Slow;
    class SMT_200mm_HE_fast;
    class SMT_200mm_SALH;
    class SMT_200mm_APFSDS;

    class SMT_200mm_HE_Slow: {
        tracersEvery = 1;
        count=8;
    };
    class SMT_200mm_HE_fast {
        tracersEvery = 1;
        count=18;
    };
    class SMT_200mm_SALH {
        tracersEvery = 1;
        count=6;
    };
    class SMT_200mm_APFSDS {
        tracersEvery = 1;
        count=18;
    };
};