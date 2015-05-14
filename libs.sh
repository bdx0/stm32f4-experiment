#!/bin/bash -

[ -d lib ] || mkdir lib
pushd lib

if [ ! -d stm32_discovery_arm_gcc ]; then
git clone https://github.com/rowol/stm32_discovery_arm_gcc
fi
pushd stm32_discovery_arm_gcc/blinky
make
make burn
popd

popd