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
set tracefile [open 5.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open 5.nam w]
$ns namtrace-all $namfile

#add manually
set wf0 [open WinFile0 w]
set wf1 [open WinFile1 w]

proc PlotWindow {tcpSource file} {
global ns
set time 0.1
set now [$ns now]
set cwnd [$tcpSource set cwnd_]
puts $file "$now $cwnd"
$ns at [expr $now+$time] "PlotWindow $tcpSource $file"
}
#end

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
$ns duplex-link $n0 $n2 2.0Mb 10ms DropTail
$ns queue-limit $n0 $n2 5
$ns duplex-link $n1 $n2 2.0Mb 10ms DropTail
$ns queue-limit $n1 $n2 5
$ns duplex-link $n2 $n3 0.3Mb 10ms DropTail
$ns queue-limit $n2 $n3 3

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
set sink2 [new Agent/TCPSink]
$ns attach-agent $n4 $sink2
$ns connect $tcp0 $sink2
$tcp0 set packetSize_ 1500

#Setup a TCP connection
set tcp1 [new Agent/TCP]
$ns attach-agent $n1 $tcp1
set sink3 [new Agent/TCPSink]
$ns attach-agent $n5 $sink3
$ns connect $tcp1 $sink3
$tcp1 set packetSize_ 1500


#===================================
#        Applications Definition        
#===================================
#Setup a FTP Application over TCP connection
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 0.1 "$ftp0 start"
$ns at 9.8 "$ftp0 stop"

#Setup a FTP Application over TCP connection
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ns at 0.2 "$ftp1 start"
$ns at 9.9 "$ftp1 stop"


#add manually
$ns at 0.1 "PlotWindow $tcp0 $wf0"
$ns at 0.5 "PlotWindow $tcp1 $wf1"

$tcp0 set class_ 1
$tcp1 set class_ 2
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
    exec nam 5.nam &
    exec xgraph WinFile0 WinFile1 &
    exit 0
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run

#output: Explain the graph
