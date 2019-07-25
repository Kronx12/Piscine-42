#!/bin/sh
find . -type f -name "*.sh" | sed 's#.*/##' | cut -f1 -d '.'
