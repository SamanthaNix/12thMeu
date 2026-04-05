#pragma hemtt suppress pw3_padded_arg config
//#include "config_macros.hpp"

// Path macros for simplified file path usage
#define P(PATH) \x\12thMEUAssets\addons\12th_tagging\##PATH
#define QP(PATH) #P(PATH)
#define Q(INPUT) #INPUT
#define GLUE(g1, g2) g1##g2

/*
  SPRAY_CLASS(CSFX):
  - Adds a basic prefix to indicate a spray class.
  - CSFX: Class suffix, used to create a unique class name for the spray item.
*/
#define SPRAY_CLASS(CSFX) twelfth_spray_##CSFX

/*
  TPATH(TYPE, FILE):
  - Stands for Tag Path. Defines the path to a texture file.
  - TYPE: Folder type (e.g., platoon, unit).
  - FILE: The specific texture file within the folder.
*/
#define TPATH(TYPE, FILE) P(data\tags\##TYPE\##FILE)

/*
  SPRAY_ITEM(CSFX, DSFX):
  - Defines a spray can item with a specific suffix and display name.
  - CSFX: Unique class suffix.
  - DSFX: Suffix added to the display name.
*/
#define SPRAY_ITEM(CSFX, DSFX)                                        \
class SPRAY_CLASS(CSFX) : ACE_SpraypaintBlack {                       \
  author = "Waylen";                                                  \
  displayName = #GLUE([12th] Spray Can, DSFX);                        \
  picture = "\z\ace\addons\tagging\UI\items\itemSpraypaintBlack.paa"; \
  hiddenSelectionsTextures[] = {                                      \
    "\z\ace\addons\tagging\data\spraycanBlack_co.paa"                 \
  };                                                                  \
  class ItemInfo: CBA_MiscItem_ItemInfo {                             \
    mass = 0;                                                         \
  };                                                                  \
};

/*
  TAG(SUFFIX, REQ_ITEM, DISPLAY, TEXPATH):
  - Defines a single tag item.
  - SUFFIX: A unique suffix appended to the class name.
  - REQ_ITEM: The required item class in quotes.
  - DISPLAY: The display name for the tag.
  - TEXPATH: Full texture path to the texture that will be painted on the surface.
*/
#define TAG(SUFFIX, REQ_ITEM, DISPLAY, TEXPATH) \
class twelfth_tag_##SUFFIX {                    \
  displayName = DISPLAY;                        \
  requiredItem = REQ_ITEM;                      \
  textures[] = { #TEXPATH };                    \
  icon = #TEXPATH;                              \
};

/*
  PLT_TAGS(CSFX, REQ_ITEM, TYPE):
  - Defines a standard set of tags for a specific platoon or HQ element.
  - CSFX: Class suffix, ensure uniqueness.
  - REQ_ITEM: The required item class in quotes.
  - TYPE: Folder name for a set of platoon-specific tags.
*/
#define PLT_TAGS(CSFX, REQ_ITEM, TYPE)                                      \
TAG(GLUE(CSFX, _bhz), REQ_ITEM, "Biohazard", TPATH(TYPE, bhz.paa))          \
TAG(GLUE(CSFX, _clr), REQ_ITEM, "Clear", TPATH(TYPE, clr.paa))              \
TAG(GLUE(CSFX, _int), REQ_ITEM, "Intel", TPATH(TYPE, int.paa))              \
TAG(GLUE(CSFX, _mines), REQ_ITEM, "Mines", TPATH(TYPE, mines.paa))          \
TAG(GLUE(CSFX, _noent), REQ_ITEM, "No Entry", TPATH(TYPE, no_ent.paa))      \

class CfgPatches {
    class twelfth_tagging {
        units[] = {};
        weapons[] = {

        };
        requiredAddons[] = {
            "ace_interaction",
            "ace_tagging"
        };
        requiredVersion = 0.1;
        version = 0.1;
    };
};

class CfgVehicles {};

// Define custom spray can items for each platoon and miscellaneous sprays
/* class CfgWeapons {
    class ACE_SpraypaintBlack; // Base class for spray can items
    class CBA_MiscItem_ItemInfo; // Base class for item information

    // Define spray cans for each platoon
//    SPRAY_ITEM(1stplt,1PLT)
//    SPRAY_ITEM(2ndplt,2PLT)
//    SPRAY_ITEM(hq,HQ)
//    SPRAY_ITEM(misc,Misc)

//         weapons patches
            "twelfth_spray_hq",
            "twelfth_spray_1stplt",
            "twelfth_spray_2ndplt",
            "twelfth_spray_misc" 
}; */

// Define the tags that can be applied using the spray cans
class ACE_Tags {
    // Define tags for HQ, 1st Platoon, and 2nd Platoon
//    PLT_TAGS(1stplt,twelfth_spray_1stplt,1stplt)

    // Define miscellaneous tags that can be used with the misc spray can
    class misc_lb {
        displayName = "12th Logo (Black)";
        texture = "path\to\misc\12thLogoBlack.paa";
        weapon = "twelfth_spray_misc";
    };

    class misc_lw {
        displayName = "12th Logo (White)";
        texture = "path\to\misc\12thLogoWhite.paa";
        weapon = "twelfth_spray_misc";
    };

    class misc_bs {
        displayName = "Blank Square";
        texture = "path\to\misc\BlankSquare.paa";
        weapon = "twelfth_spray_misc";
    };

    class misc_au {
        displayName = "Arrow Up";
        texture = "path\to\misc\ArrowUp.paa";
        weapon = "twelfth_spray_misc";
    };

    class misc_ar {
        displayName = "Arrow Right";
        texture = "path\to\misc\ArrowRight.paa";
        weapon = "twelfth_spray_misc";
    };

    class misc_ad {
        displayName = "Arrow Down";
        texture = "path\to\misc\ArrowDown.paa";
        weapon = "twelfth_spray_misc";
    };

    class misc_al {
        displayName = "Arrow Left";
        texture = "path\to\misc\ArrowLeft.paa";
        weapon = "twelfth_spray_misc";
    };
};
