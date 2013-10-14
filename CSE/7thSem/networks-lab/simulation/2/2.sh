#!/bin/bash
tcp=`cat 2.nam |cut -d " " -f 9|sort|grep tcp|wc|sed "s/  //g"|cut -d " " -f 1`
udp=`cat 2.nam |cut -d " " -f 9|sort|grep cbr|wc|sed "s/  //g"|cut -d " " -f 1`
echo "Number of TCP packets : $tcp"
echo "Number of UDP : $udp"
