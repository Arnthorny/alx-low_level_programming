#!/bin/bash
wget -b -q -w 98 'https://github.com/Arnthorny/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libspoof.so'
export LD_PRELOAD=./libspoof.so
