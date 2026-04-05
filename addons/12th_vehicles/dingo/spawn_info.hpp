#define DINGO_SP_INFO(PRI,TYPE) \
class VehicleSpawnerInfo {        \
  class twelfth_ground_spawner {     \
    priority=PRI;                 \
    spawner = "12th Ground";      \
    scope = 1;                    \
    vehicle = "Dingo";          \
    icon="";                      \
    type=#TYPE;                   \
    cost=0;                       \
  };                              \
};