
#define SOUND_20MM_CLASS \
    soundClosure[] = {"sound",1}; \
    soundContinuous = 0; \
    soundEnd[] = {"sound",1}; \
    soundLoop[] = {}; \
    sounds[] = {"StandardSound"}; \
    class StandardSound { \
        begin1[] = {"A3\Sounds_F\arsenal\weapons_vehicles\cannon_30mm\autocannon_30mm_01",1.99526,1,1500}; \
        begin2[] = {"A3\Sounds_F\arsenal\weapons_vehicles\cannon_30mm\autocannon_30mm_02",1.99526,1,1500}; \
        begin3[] = {"A3\Sounds_F\arsenal\weapons_vehicles\cannon_30mm\autocannon_30mm_03",1.99526,1,1500}; \
        soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34}; \
        soundsetshot[] = {"Autocannon30mmTurret_Shot_SoundSet","Autocannon30mmBody_tail_SoundSet"}; \
    }; \
    