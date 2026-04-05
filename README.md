# 12th Marine Expeditionary Unit Assets

## About

This is a mod that contains any and all relevant assets that are actively
used by the 12th Marine division in their ArmA 3 campaigns.

Originally found here: https://github.com/nojusr/12thMD_Assets
## Contents

The `./addons/` folder contains all of the folders that are to be used in
the building process. Think of each folder within `/addons` as an unpacked
PBO file.

* `12th_vests` contains any and all customized vests.
* `12th_backpacks` contains any and all customized backpacks.
* `12th_custom_helms` contains all individually customized helmets
* `12th_armor` contains any and all customized uniforms, non-custom helmets included.
* `12th_tagging` contains a set of spray cans with 12th-specific tags programmed in.
* `12th_weapons` contains any and all customzied weapons.
* `12th_aircraft` contains any and all customized aircraft.
* `12th_vehicles` contains any and all customized ground vehicles.
* `12th_supply_pods` contains all of our supply pod re-textures and custom configurations.
* `12th_music` contains all of the custom music that is in-use.
* `12th_misc` contains all other relevant assets (if needed)
* `12th_ui` contains a set of loading screens and splash screens. Made to be a separate PBO specifically to allow people to use our other PBO's without seeing the 12th's stuff splattered all over it.

The `./pbo_include` folder contains all of our 3rd party PBOS that are to be
included into the mod. Currently the PBOs included are listed in this link: https://pastebin.com/RPFdREG3

## Building/Testing

### Windows
To build a development version, run the `build.ps1` script. You can do this
by right-clicking the file and clicking on `Run With Powershell` button.

This script will produce a folder, labled `.hemttout/build`. You can load this
folder as a mod directly into ArmA3. Use this for testing purposes.

To build a release version, run the `release.ps1` script.
This will produce a zip file in `./releases` and a folder in `.hemttout/release`.

### Linux
Ensure that HEMTT is installed on your system.

Development version:
```
$ ./build.sh
```

Release version:
```
$ ./release.sh
```
These will produce mod folders in the same location as on Windows.
