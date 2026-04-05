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
