#!/bin/sh

/etc/init.d/dbus start
eval `dbus-launch --auto-syntax`
/root/amee
