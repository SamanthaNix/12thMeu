/*
  ==============================================================================
  config_macros.hpp

  This file sets up shorthand macros for referencing images in your UI. 
  The macros revolve around:
    - P() and QP(): Building relative paths to your mod’s .paa or .jpg files.
    - RSC_PIC(): A single macro that defines a new RscPicture with coordinates 
      covering the entire screen (SafeZone).

  Usage:
    RSC_PIC(SomeClassName, data\filename.jpg)

  expands to:
    class SomeClassName : RscPicture {
      idc = 1;
      x = "SafeZoneX";
      y = "SafeZoneY";
      w = "SafeZoneW";
      h = "SafeZoneH";
      text = "\x\12thMEU\addons\12th_ui\data\filename.jpg";
    };
  ==============================================================================
*/
#define P(PATH) \x\12thMEU\addons\12th_ui\##PATH
  // Prepends the local path for 12th_ui files to PATH.

#define QP(PATH) #P(PATH)
  // Wraps the expanded path in quotes, e.g.:
  // QP(data\loading_bg.jpg) => "\x\12thMEU\addons\12th_ui\data\loading_bg.jpg"

#define RSC_PIC(CLASSNAME,PATH) \
class CLASSNAME : RscPicture {  \
  idc=1;                        \
  x="SafeZoneX";                \
  y="SafeZoneY";                \
  h="SafeZoneH";                \
  w="SafeZoneW";                \
  text = QP(PATH);              \
};
