#include "config_macros.hpp"
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_tempests {
    units[] = {
      "twelfth_tempest_transport",
      "twelfth_tempest_transport_covered",
      "twelfth_tempest_repair",
      "twelfth_tempest_ammo",
      "twelfth_tempest_fuel",
      "twelfth_tempest_medical"
    };
  };
};

class CfgVehicles {
  // TEMPEST ---------------------------------------------------------
  class O_Truck_03_transport_F;
  class O_Truck_03_covered_F;
  class O_Truck_03_repair_F;
  class O_Truck_03_ammo_F;
  class O_Truck_03_fuel_F;
  class O_Truck_03_medical_F;

  TEMPEST_3(1,Transport,twelfth_tempest_transport,O_Truck_03_transport_F,"[12th] Tempest Transport",cargo_co.paa)
  TEMPEST_4(2,Covered,twelfth_tempest_transport_covered,O_Truck_03_covered_F,"[12th] Tempest Covered",cargo_co.paa,cover_co.paa)
  TEMPEST_3(3,Repair,twelfth_tempest_repair,O_Truck_03_repair_F,"[12th] Tempest Repair",ammo_co.paa)
  TEMPEST_4(4,Ammo,twelfth_tempest_ammo,O_Truck_03_ammo_F,"[12th] Tempest Ammo",cargo_co.paa,ammo_co.paa)
  TEMPEST_3(5,Fuel,twelfth_tempest_fuel,O_Truck_03_fuel_F,"[12th] Tempest Fuel",fuel_co.paa)
  TEMPEST_4(6,Medical,twelfth_tempest_medical,O_Truck_03_medical_F,"[12th] Tempest Medical",cargo_co.paa,cover_co.paa)
  //TEMPEST_5(7,Device,twelfth_tempest_device,O_Truck_03_device_F,"[12th] Tempest Device",cargo_co.paa,cover_co.paa,device03_co.paa)

};
