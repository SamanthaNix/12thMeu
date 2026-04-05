#pragma hemtt suppress pw3_padded_arg config
#include "spawn_info.hpp"
#include "config_macros.hpp"


class CfgPatches {
  class twelfth_vehicles_hemtt {
    units[] = {
      "twelfth_hemtt",
      "twelfth_hemtt_transport",
      "twelfth_hemtt_container",
      "twelfth_hemtt_repair",
      "twelfth_hemtt_ammo",
      "twelfth_hemtt_fuel",
      "twelfth_hemtt_medical",
      "twelfth_hemtt_covered",
      "twelfth_hemtt_flatbed",
    };
    weapons[] = {};
    requiredVersion=0.1;
  };
};

class CfgVehicles {

  // hemtt base classes
  class B_Truck_01_mover_F;
  class B_Truck_01_transport_F;
  class B_Truck_01_box_F;
  class B_Truck_01_Repair_F;
  class B_Truck_01_ammo_F;
  class B_Truck_01_fuel_F;
  class B_Truck_01_medical_F;
  class B_Truck_01_covered_F;
  class B_Truck_01_flatbed_F;

  //-HEMTT------------------------------------------------------------

  HEMTT_3(1,Base,twelfth_hemtt, B_Truck_01_mover_F,"[12th] HEMTT",mprimer_co.paa)
  HEMTT_3(2,Transport,twelfth_hemtt_transport,B_Truck_01_transport_F,"[12th] HEMTT Transport",cargo_co.paa)
  HEMTT_4(3,Container,twelfth_hemtt_container,B_Truck_01_box_F,"[12th] HEMTT Container",ammo_co.paa,containers_set_co.paa)
  HEMTT_4(4,Repair,twelfth_hemtt_repair,B_Truck_01_Repair_F,"[12th] HEMTT Repair",ammo_co.paa,containers_set_co.paa)
  HEMTT_3(5,Ammo,twelfth_hemtt_ammo,B_Truck_01_ammo_F,"[12th] HEMTT Ammo",ammo_co.paa)
  HEMTT_3(6,Fuel,twelfth_hemtt_fuel,B_Truck_01_fuel_F,"[12th] HEMTT Fuel",fuel_co.paa)
  HEMTT_4(7,Medical,twelfth_hemtt_medical,B_Truck_01_medical_F,"[12th] HEMTT Medical",cargo_co.paa,cover_co.paa)
  HEMTT_4(8,Covered,twelfth_hemtt_covered,B_Truck_01_covered_F,"[12th] HEMTT Covered",cargo_co.paa,cover_co.paa)
  HEMTT_4(9,Flatbed,twelfth_hemtt_flatbed,B_Truck_01_flatbed_F,"[12th] HEMTT Flatbed",ammo_co.paa,cargo_co.paa)

};
