#!/bin/bash
tcp=`cat 2.nam |grep "tcp"|wc -l`
udp=`cat 2.nam |grep "cbr"|wc -l`
echo -e "\nPackets Dropped for\n"
echo -e "\nTCP : $tcp\n"
echo -e "\nUDP : $udp\n"
