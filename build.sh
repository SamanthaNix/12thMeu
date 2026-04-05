#/usr/bin/env bash

# this is a linux-only build script that auto-includes everything 
# within pbo_include because HEMTT cannot read directories...
# Execute from the root of this project.

hemtt build --no-bin -t 24
cp ./pbo_include/* ./.hemttout/build/addons/

count=$(ls ./pbo_include | wc -l)
echo "Copied $count external PBO files into build output"
