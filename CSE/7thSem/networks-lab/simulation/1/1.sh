#!/bin/bash
x=`cat 1.nam |cut -d " " -f 1|sort|grep d|wc -l`
echo -ne "\nNo. of Packets dropped: $x\n"

