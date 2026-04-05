#pragma hemtt suppress pw3_padded_arg config
#include "spawn_info.hpp"

class CfgPatches {
  class twelfth_vehicles_SRV {
    units[] = {
      "twelfth_SRV"
    };
    requiredVersion = 0.1;
  };
};

class CfgVehicles {
    class SRV_UKWD;
    class twelfth_SRV: SRV_UKWD {
    scope=2;
    scopeCurator=2;
    author="Sammy";
    displayName="[12th] SRV UKWD";
    vehicleClass="OPTRE_UNSC_Vehicle_class";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Cars";
    SRV_SP_INFO(10)
  };
};