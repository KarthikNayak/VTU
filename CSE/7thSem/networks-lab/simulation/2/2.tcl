set ns [new Simulator]

#NAM file
set nf [open 2.nam w]
$ns namtrace-all $nf

#create the nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Define color classes
$ns color 1 "red"
$ns color 2 "blue"

#Apply labels
$n0 label "src 1"
$n1 label "src 2"
$n2 label "Intermediate"
$n3 label "dest"

#Create links
$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 10Mb 10ms DropTail
$ns duplex-link $n2 $n3 10Mb 1ms DropTail

#Attach UDP agents
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

#RUN FTP over $tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

#Create a TCP destination i.e sink
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink

#Create UDP 
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

#Run CBR over udp
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp

#create udp destination i.e null
set null [new Agent/Null]
$ns attach-agent $n3 $null

#Assign colors to flows
$tcp0 set class_ 1
$udp set class_ 2

#Assign some properties
$ftp0 set packetSize_ 90
$ftp0 set interval_ 0.01

$cbr set packetSize_ 93
$cbr set interval _ 0.1

#connect 
$ns connect $tcp0 $sink
$ns connect $udp $null

#define finish proc
proc finish {} {
	global ns nf
	$ns flush-trace
	exec nam 2.nam &
	close $nf
	exit 0
}

#Assign timing to events
$ns at 0.1 "$cbr start"
$ns at 0.5 "$ftp0 start"
$ns at 10.5 "finish"

#Start the simulation
$ns run
