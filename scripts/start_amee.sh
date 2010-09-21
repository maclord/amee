#!/bin/sh

AMEE_BIN=./amee

if [ $(whoami) == "root" ]
then
	echo "Started as root user"
	if [ -e /var/run/dbus.pid ]
	then
		echo "D-Bus is running"
	else
		echo "D-Bus is not running, let's start it"
		/etc/init.d/dbus start
	fi
fi

if [ -z "${DBUS_SESSION_BUS_ADDRESS}" ]
then
	echo "No D-Bus session found, let's start it"
	eval `dbus-launch --auto-syntax`
fi

if [ -z "${DBUS_SESSION_BUS_ADDRESS}" ]
then
	echo "D-Bus session still not found :("
	exit 1
else
	echo "D-Bus session found : ${DBUS_SESSION_BUS_ADDRESS}"
fi

echo "Starting AMEE for real..."
clear
eval $AMEE_BIN
