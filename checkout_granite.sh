#!/bin/bash

# Only checks out what is necessary to build standalone.
#
GRANITE_COMMIT=e96891e77d89f11dc4aa3f1789af08e1192544ad

if [ -d Granite ]; then
	cd Granite
	git fetch origin
	git checkout $GRANITE_COMMIT
else
	git clone https://github.com/evadne/Granite
	cd Granite
	git checkout $GRANITE_COMMIT
fi

cd ..

update() {
	git submodule sync $1
	git submodule update --init $1
}

cd Granite
update third_party/volk
update third_party/khronos/vulkan-headers
