#!/bin/bash
x=`cat 1.nam |cut -d " " -f 1|sort|grep d|wc|sed 's/  //g'|cut -d " " -f 1`
echo "No. of Packets dropped: $x"

