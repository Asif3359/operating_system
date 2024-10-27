#! /bin/bash

[ -d "$1" ] || mkdir "$1"
[ -f "$1/$2" ] || touch "$1/$2"
