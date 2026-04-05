#define ORYX_SP_INFO(PRI,TYPE) \
class VehicleSpawnerInfo {     \
  class twelfth_ground_spawner {  \
    priority=PRI;              \
    spawner = "12th Ground";   \
    scope = 1;                 \
    vehicle = "Oryx";          \
    icon="";                   \
    type=#TYPE;                \
    cost=0;                    \
  };                           \
};
