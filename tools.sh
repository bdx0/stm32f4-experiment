#!/bin/bash -

[ -d tool ] || mkdir tool
pushd tool

[ "$(ls arm-compiler)" != "" ] || rm -rf arm-compiler
[ -d arm-compiler ] || (mkdir arm-compiler && wget -O- https://launchpad.net/gcc-arm-embedded/4.9/4.9-2015-q1-update/+download/gcc-arm-none-eabi-4_9-2015q1-20150306-linux.tar.bz2 | tar -xj --strip-components=1 -C arm-compiler)

if [ ! -d stlink ]; then
git clone https://github.com/texane/stlink.git
pushd stlink
./autogen.sh
./configure
make
popd
fi

popd