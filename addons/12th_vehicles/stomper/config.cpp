/*
  ==============================================================================
  config.cpp

  This file declares new vehicle classes for the 12th MEU mod. It uses macros
  from "config_macros.hpp" to handle file paths (QP) and to provide default
  inventory definitions (STDINV, MEDINV).

  Key Points:
    - CfgPatches: Tells Arma which units/classes are included and what version.
    - CfgVehicles: Lists the actual vehicle classes, referencing base Arma classes.
    - #pragma hemtt suppress pw3_padded_arg config:
        Suppresses a known HEMTT warning about parameter padding in config files.
  ==============================================================================
*/
#pragma hemtt suppress pw3_padded_arg config
// Includes macros used throughout (for paths, default inventory, etc.).
#include "..\config_macros.hpp"
#include "spawn_info.hpp"


class CfgPatches {
  class twelfth_vehicles_stomper {
    units[] = {
      "twelfth_stomper",
      "twelfth_stomper_rcws"
        /*
          These two define the classnames for the vehicles you want to add.
          If you add new vehicles, place them in this array so Arma recognizes them
          as part of the mod. 
        */
    };
    weapons[] = {};
    requiredVersion=0.1;
  };
};

class CfgVehicles {

  /*
    We need to forward-declare the base classes that we inherit from.
    B_UGV_01_F and B_UGV_01_rcws_F are vanilla Arma 3 classes for the Stomper UGV.
  */
  class B_UGV_01_F;
  class B_UGV_01_rcws_F;

  // ---------------------------------------------------------------------------
  //  [12th] Stomper UGV (unarmed variant)
  // ---------------------------------------------------------------------------
  /*
    Uncomment to use this vehicle in-game.
    Inherits from B_UGV_01_F (the unarmed stomper).
  */
  
  class twelfth_stomper: B_UGV_01_F {
    scope = 2;               // Visible/available in the editor
    scopeCurator = 2;        // Visible to Zeus
    displayName = "[12th] Stomper UGV"; 
    author = "Waylen";

    // Factions & Categories let you place the vehicle in the editor under your unit’s tabs
    faction = "twelfth_MEU";            
    editorCategory = "twelfth_MEU";     
    editorSubcategory = "twelfth_MEU_Drones";  
    crew = "B_UAV_AI";  // The default AI driver
    typicalCargo[] = {""};
    

    // Hidden selections allow retexturing. Here we define three camo selections:
    hiddenSelections[] = {"Camo1", "Camo2", "Camo3"};
    hiddenSelectionsTextures[] = {
      QP(stomper\default\ext_co.paa),   // Exterior
      QP(stomper\default\int_co.paa),   // Interior
      QP(stomper\default\turret_co.paa) // Turret
    };

    // textureSources define alternate texture sets for the vehicle
    class textureSources {
      class default {
        displayName = "Default";
        author = "Waylen";
        textures[] = {
          QP(stomper\default\ext_co.paa),
          QP(stomper\default\int_co.paa),
          QP(stomper\default\turret_co.paa)
			};
		};
      class twelfth_stomper_tex_vivi {
        displayName = "Vi-Vi";
        author = "Rex";
        textures[] = {
          QP(stomper\default\ViVi\ext_co.paa),
          QP(stomper\default\int_co.paa),
          QP(stomper\default\turret_co.paa)
			};
		};
	};

    STOMPER_SP_INFO(0,Empty)
    WPNSINV

    maximumLoad = 2500;
  };
  

  // ---------------------------------------------------------------------------
  //  [12th] Stomper RCWS UGV (armed variant)
  // ---------------------------------------------------------------------------
  /*
    Similarly, for the armed stomper version with an RCWS (remote-controlled weapon station).
  */
  
  class twelfth_stomper_rcws: B_UGV_01_rcws_F {
    scope = 2;
    scopeCurator = 2;
    displayName = "[12th] Stomper RCWS";
    author = "Waylen";

    // Adjust these to place it properly in your mod’s faction listing
    vehicleClass = "OPTRE_UNSC_Vehicle_class";
    faction = "twelfth_MEU";
    editorCategory = "twelfth_MEU";
    editorSubcategory = "twelfth_MEU_Drones";
    crew = "B_UAV_AI";
    typicalCargo[] = {""};

    // Example macro usage: STOMPER_SP_INFO(1,RCWS)
    // STOMPER_SP_INFO(1,RCWS)

    hiddenSelections[] = {"Camo1", "Camo2", "Camo3"};
    hiddenSelectionsTextures[] = {
      QP(stomper\default\ext_co.paa),
      QP(stomper\default\int_co.paa),
      QP(stomper\default\turret_co.paa)
    };

    class textureSources {
      class default {
        displayName = "Default";
        author = "Waylen";
        textures[] = {
          QP(stomper\default\ext_co.paa),
          QP(stomper\default\int_co.paa),
          QP(stomper\default\turret_co.paa)
        };
	  };
      class twelfth_stomper_tex_vivi {
        displayName = "Vi-Vi";
        author = "Rex";
        textures[] = {
          QP(stomper\default\ViVi\ext_co.paa),
          QP(stomper\default\int_co.paa),
          QP(stomper\default\turret_co.paa)
        };
      };
    };

    STOMPER_SP_INFO(0,RCWS)
    WPNSINV

    maximumLoad = 2500;
  };
  

};
