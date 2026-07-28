#pragma hemtt suppress pw3_padded_arg config


class CfgWeapons
{ 
    class cannonCore;
    class gatling_20mm;
    class StandardSound;
    class M134_minigun;
    class ACE_gatling_20mm_Comanche: gatling_20mm {
        class manual;
        class close;
        class short;
        class medium;
        class far;
    };
    class SMT_20mm_ac: ACE_gatling_20mm_Comanche {
        dexterity = 0.5;
        inertia = 0.7;
        class manual: manual {
            reloadTime = 0.3369; // because we can the memes
            showToPlayer = 1;
            SOUND_20MM_CLASS
        };
        class burst: manual {
            burst = 4;
            showToPlayer = 1;
            reloadTime = 0.2;
            textureType = "burst";
            SOUND_20MM_CLASS
        };
        class close: close {
            reloadTime = 0.3369; 
            SOUND_20MM_CLASS
        };
        class short: short {
            reloadTime = 0.3369;
            SOUND_20MM_CLASS
        };
        class medium: medium {
            reloadTime = 0.3369;
            SOUND_20MM_CLASS
        };
        class far: far {
            reloadTime = 0.3369;
            SOUND_20MM_CLASS
        };
        modes[] += {"burst"};
        magazines[] = { "SMT_500Rnd_20mm_shells_Dingo" };
    };

    class SMT_minigun_762mm:M134_minigun {
    magazines[] = { "SMT_2000Rnd_762_shells_Dingo" };
    };
};
