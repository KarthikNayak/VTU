#!/bin/bash
x=`cat out.tr|grep "^d"|wc -l`
echo -en "\nNumber of packets dropped : $x \n "
