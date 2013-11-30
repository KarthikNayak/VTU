# This script is created by NSG2 beta1
# <http://wushoupong.googlepages.com/nsg>

#===================================
#     Simulation parameters setup
#===================================
set val(stop)   10.0                         ;# time of simulation end

#===================================
#        Initialization        
#===================================
#Create a ns simulator
set ns [new Simulator]

#add manually
$ns color 1 "red"
$ns color 2 "blue"
#end

#Open the NS trace file
set tracefile [open 4.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open 4.nam w]
$ns namtrace-all $namfile

#===================================
#        Nodes Definition        
#===================================
#Create 6 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

#===================================
#        Links Definition        
#===================================
#Createlinks between nodes
$ns duplex-link $n0 $n2 10.0Mb 10ms DropTail
$ns queue-limit $n0 $n2 5
$ns duplex-link $n1 $n2 10.0Mb 10ms DropTail
$ns queue-limit $n1 $n2 5
$ns duplex-link $n2 $n3 .3Mb 10ms DropTail
$ns queue-limit $n2 $n3 5

#Give node position (for NAM)
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
#add manually
$ns duplex-link-op $n2 $n3 queuePos 0.5

set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTail MAC/802_3 Channel]

set loss_module [new ErrorModel]
$loss_module ranvar [new RandomVariable/Uniform]
$loss_module drop-target [new Agent/Null]
$ns lossmodel $loss_module $n2 $n3
#end

#===================================
#        Agents Definition        
#===================================
#Setup a TCP connection
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1
$ns connect $tcp0 $sink1
$tcp0 set packetSize_ 1500

#Setup a UDP connection
set udp2 [new Agent/UDP]
$ns attach-agent $n1 $udp2
set null3 [new Agent/Null]
$ns attach-agent $n5 $null3
$ns connect $udp2 $null3
$udp2 set packetSize_ 1500


#===================================
#        Applications Definition        
#===================================
#Setup a FTP Application over TCP connection
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 0.1 "$ftp0 start"
$ns at 9.8 "$ftp0 stop"

#Setup a CBR Application over UDP connection
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp2
$cbr1 set packetSize_ 1000
$cbr1 set rate_ 0.1Mb
$cbr1 set random_ null
$ns at 0.5 "$cbr1 start"
$ns at 9.9 "$cbr1 stop"

#add manually
$tcp0 set class_ 1
$udp2 set class_ 2
#end

#===================================
#        Termination        
#===================================
#Define a 'finish' procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    #add manually
    set TcpSize 1500
#[exec grep "^r" 4.tr | grep -c "tcp" ]
    set numTcp [exec grep "^r" 4.tr | grep -c "tcp"]
    set tcpTime 9.7
    set UdpSize 1000
    set numUdp [exec grep "^r" 4.tr | grep -c "cbr" ]
    set udpTime 9.4
    puts "The throughput of FTP is"
    puts "[expr ($numTcp*$TcpSize)/$tcpTime] bytes per second"
    puts "The throughput of CBR is"
    puts "[expr ($numUdp*$UdpSize)/$udpTime] bytes per second" 
    #end
    exec nam 4.nam &
    exit 0
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run

#output: To check throughput by varying the bandwidth between nodes n2 and n3
# 1st instance: $ns duplex-link $n2 $n3 0.3Mb 10ms DropTail ( at line 47)
# 2nd instance: $ns duplex-link $n2 $n3 3Kb 10ms DropTail
