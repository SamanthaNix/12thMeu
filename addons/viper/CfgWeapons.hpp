#pragma hemtt suppress pw3_padded_arg config


class CfgWeapons
{ 
    class cannon_railgun;

    class SMT_200mm_railgun: cannon_railgun {
        dexterity = 0.5;
        displayName = "200mm Railgun";
        magazines[] = { "SMT_200mm_HE_Slow_8rnd","SMT_200mm_HE_fast_18rnd","SMT_200mm_SALH_6rnd","SMT_200mm_APFSDS_18rnd" };
    };
};
