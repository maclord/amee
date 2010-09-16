#!/bin/sh

usage()
{
cat << EOF
usage: $0 /path/to/OpenWRT/directory

This script helps setting QMAKE variables to use an OpenWRT toolchain.
It can be used this way :
	$ eval \`$0 /path/to/OpenWRT/directory\`

EOF
}

export_variable()
{
NAME=$1
VALUE=$2
#echo "$NAME=$VALUE"
VARS="$VARS $NAME=\"$VALUE\""
}

if [ $# -ne 1 ]
then
  usage
else

OPENWRT_PATH=$1
export_variable QMAKE_CXX $OPENWRT_PATH/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/bin/arm-openwrt-linux-g++
export_variable QMAKE_CC $OPENWRT_PATH/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/bin/arm-openwrt-linux-gcc
export_variable QMAKE_LINK $OPENWRT_PATH/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/bin/arm-openwrt-linux-gcc
export_variable QMAKESPEC $OPENWRT_PATH/staging_dir/target-arm_v4t_uClibc-0.9.30.1_eabi/usr/share/mkspecs/linux-openwrt-g++
export_variable QMAKE_CXXFLAGS "-O2 -pipe -march=armv4t -mtune=arm920t -funit-at-a-time -fhonour-copts -msoft-float -Wall"
export_variable QMAKE_CFLAGS "-O2 -pipe -march=armv4t -mtune=arm920t -funit-at-a-time -fhonour-copts -msoft-float -Wall -Wno-pointer-sign"
#export_variable QMAKE_DEFINES "-DQT_NO_DEBUG -DQT_DBUS_LIB -DQT_CORE_LIBaaaaaaaa"
#export_variable QMAKE_HOST.arch gnah

echo $VARS
fi
