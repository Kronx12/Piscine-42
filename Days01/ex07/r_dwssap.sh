#!/bin/sh
cat /etc/passwd | grep -v "#" | awk 'NR % 2 == 0' | rev | sed "s/.*:\*://" | sort -r | sed -n "7, 15 p" | sed "s/$/, /" | tr -d '\n' | sed 's/, $/./' | tr -d "\n"

