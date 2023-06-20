#!/bin/bash
wget -P /tmp 'https://github.com/Arnthorny/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libspoof.so'
export LD_PRELOAD=/tmp/libspoof.so
