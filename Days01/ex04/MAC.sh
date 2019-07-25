#!/bin/sh
ifconfig -a link | grep ether | cut -f2 -d " "
