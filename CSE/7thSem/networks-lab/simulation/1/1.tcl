#New Sim obj
set ns [new Simulator]
#Set color class
$ns color 1 "RED"
$ns color 2 "Blue"

#Open NAM file 
set nf [open 1.nam w]
$ns namtrace-all $nf

#Def Finish proc
proc finish {} {
	global ns nf
	$ns flush-trace
	#Execute nam file
	exec nam 1.nam &
	exec bash 1.sh &
	#Close nam file
	close $nf
	exit 0
}


#Create 3 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

#Assign labels
$n0 label "SRC0"
$n1 label "SRC1"
$n2 label "Dest"
#Create links
$ns duplex-link $n0 $n2 100Kb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail

#Set queue size
$ns set queue-limit $n0 $n2 10

#postion the nodes
$ns duplex-link-op $n0 $n2 orient right
$ns duplex-link-op $n1 $n2 orient right-down

#Set UDP0 connection
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0


#Set CBR0 over UDP0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0
$cbr0 set packet_size_ 500

#Set UDP1 connection
set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1

#Set CBR1 over UDP1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$cbr1 set packet_size_ 500

set null [new Agent/Null]
$ns  attach-agent $n2 $null
$ns connect $udp0 $null
$ns connect $udp1 $null

#Set color for flows
$udp0 set class_ 1
$udp1 set class_ 2


#Schedule events 
$ns at 0.1 "$cbr0 start"
$ns at 0.2 "$cbr1 start"
$ns at 5.0 "$cbr1 stop"
$ns at 5.5 "$cbr0 stop"

#call finish
$ns at 5.6 "finish"

$ns run 
