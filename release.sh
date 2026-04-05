#!/usr/bin/env bash

# this is a linux-only release script that auto-includes everything 
# within pbo_include because HEMTT cannot read directories...
# Execute from the root of this project.

hemtt release --no-bin
cp ./pbo_include/* ./.hemttout/release/addons/

count=$(ls ./pbo_include | wc -l)
echo "Copied $count external PBO files into release output"
