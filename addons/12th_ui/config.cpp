/*
  ==============================================================================
  config.cpp

  This file configures custom UI elements for the 12th MEU mod. It replaces or
  modifies main menu elements, including background images, logos, and loading
  screens.

  Key Points:
    - CfgPatches: Identifies this addon and its dependencies.
    - RscTitles: Defines custom screen overlays (SplashNoise, BrokenHUD).
    - RscDisplayMain (and other RscDisplay classes): Overwrites or deletes
      default BIS spotlight items and logos, and injects custom images.
    - Macros from config_macros.hpp (like RSC_PIC) simplify background
      definition.
  ==============================================================================
*/
#include "config_macros.hpp"

class CfgPatches {
  class 12th_ui {
    units[]= {};
    // No actual "units" to place in the editor—this is purely a UI mod.
    weapons[]= {};
    requiredVersion=0.1;
    requiredAddons[] = {
      "cba_main",
      "ace_main",
      "19th_Fleet_Armor"
      /*
          Ensure you list all mods which your UI might rely on. If the UI
          references textures or classes from “19th_Fleet_Armor,” it needs to
          load after that mod is present.
      */
    };
  };
};

/*
  Pre-declare classes that we are going to inherit from or override. 
  They come from Arma’s UI configs.
*/
class RscPicture{}; //part of the background
class RscStandardDisplay{};
class RscActiveText{};
class RscActivePicture: RscActiveText{};
class RscText{}; 

class RscDisplayMPPlayers;

/*
  ==============================================================================
  RscTitles
  ==============================================================================
  RscTitles is where you define custom “titles” or overlays that can appear
  in-game or on top of the UI.
*/
class RscTitles {
  class SplashNoise {
    // This is a subclass that references RscPicture for background display
    class BackgroundNoise: RscPicture { text=""; };
    // Typically, you'd define an image path or leave it blank as a placeholder.
  };
  /*
    BrokenHUD might be a leftover or custom overlay that you can turn on
    for a “damaged” or “broken” effect on the screen. The high duration
    effectively makes it persist forever until manually removed.
  */
  class BrokenHUD: SplashNoise {
    duration=100000000;
    class BackgroundNoise: RscPicture { text=""; };
  };
};

/*
  ==============================================================================
  RscDisplayMain
  ==============================================================================
  The main menu display is replaced here. This is how you remove BIS spotlights
  and logos, and insert your own logo or background.
*/
class RscDisplayMain: RscStandardDisplay {
  class Controls {
    // The default spotlight buttons are removed
    delete Spotlight1;
    delete Spotlight2;
    delete Spotlight3;
    delete BackgroundSpotlightRight;
    delete BackgroundSpotlightLeft;
    delete BackgroundSpotlight;

    /*
      12thLogo: 
      We insert a new RscPicture on the main menu screen at a specific position 
      near the top center. This references a custom PNG or PAA file in 
      \x\12thMEU\addons\12th_ui\data\12th_a3_logo.paa.
    */
    class 12thLogo: RscPicture {
      idc=-1;
      text="\x\12thMEU\addons\12th_ui\data\12th_a3_logo.paa";
      x = "0.46375 * safezoneW + safezoneX";
      y = "0.01 * safezoneH + safezoneY";
      w = "0.07 * safezoneW";
      h = "0.07 * safezoneH";
    };

    // Remove the default logo
    class Logo: RscPicture {
      idc=-1;
      text="";
      // Setting text empty effectively hides it
    };
  };
  enableDisplay=0;
  // Remove the default "Spotlight" item if it still exists
  delete Spotlight;
  // Redefining these classes to ensure they exist or to override them
  class RscActiveText;
  class RscActivePicture: RscActiveText {
    style=48;
    color[]= {1, 1, 1, 0.500000};
    colorActive[]= {1, 1, 1, 1};
  };
  /*
    The background we define for the main menu. RSC_PIC is a macro from
    config_macros.hpp, which sets the image to data\main_menu_bg.jpg.
  */
  class ControlsBackground {
    RSC_PIC(LoadingPic,data\main_menu_bg.jpg)
      /*
        The macro expands into:
          class LoadingPic: RscPicture {
            idc=1;
            x="SafeZoneX";
            y="SafeZoneY";
            h="SafeZoneH";
            w="SafeZoneW";
            text = "\x\12thMEU\addons\12th_ui\data\main_menu_bg.jpg";
          };
      */
  };
};

/*
  ==============================================================================
  RscDisplayLoading
  ==============================================================================
  This is the loading screen you see when a mission is loading.
  We define "Variants" with class LoadingOne, and insert our custom background.
*/
class RscDisplayLoading {
  class Variants {
    class LoadingOne {
      idd = 250;
      class Controls {
        RSC_PIC(LoadingPic,data\loading_bg.jpg)
      };
    };
  };
};

/*
  ==============================================================================
  RscDisplayLoadMission
  ==============================================================================
  Another standard Arma display for mission loading. We apply the same background
  technique using RSC_PIC macro.
*/
class RscDisplayLoadMission : RscStandardDisplay {
  class ControlsBackground {
    RSC_PIC(LoadingPic,data\loading_bg.jpg)
  };
};

/*
  ==============================================================================
  RscDisplayStart
  ==============================================================================
  This might be the initial mission briefing screen or a transitional screen.
  Using the same macro to place a background image.
*/
class RscDisplayStart: RscStandardDisplay {
  class Controls {
    RSC_PIC(LoadingPic,data\loading_bg.jpg)
  };
};

/*
  ==============================================================================
  RscDisplayClientWait
  ==============================================================================
  For multiplayer, when waiting on clients to join or load, we often see
  RscDisplayMPPlayers. We can override it here to include our custom background.
*/
class RscDisplayClientWait : RscDisplayMPPlayers {
  RSC_PIC(LoadingPic,data\loading_bg.jpg)
};

/*
  ==============================================================================
  RscDisplayClient
  ==============================================================================
  Another display or screen that extends RscStandardDisplay. 
  We apply the same background with RSC_PIC macro in ControlsBackground.
*/
class RscDisplayClient : RscStandardDisplay {
  class ControlsBackground {
    RSC_PIC(LoadingPic,data\loading_bg.jpg)
  };
};
