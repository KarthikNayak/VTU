set ns [new Simulator]
set f [open out.tr w]
set nf [open out.nam w]

$ns trace-all $f
$ns namtrace-all $nf

proc finish {} {
	global ns f nf
	$ns flush-trace
	close $f
	close $nf
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$n0 label "ping0"
$n1 label "ping1"
$n2 label "R1"
$n3 label "R2"
$n4 label "ping4"
$n5 label "ping5"

$ns color 1 red
$ns color 2 blue
$ns color 3 green
$ns color 4 orange

$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.4Mb 30ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail
$ns duplex-link $n3 $n5 1Mb 10ms DropTail

set ping0 [new Agent/Ping]
$ns attach-agent $n0 $ping0

set ping1 [new Agent/Ping]
$ns attach-agent $n1 $ping1

set ping4 [new Agent/Ping]
$ns attach-agent $n4 $ping4

set ping5 [new Agent/Ping]
$ns attach-agent $n5 $ping5

$ns connect $ping0 $ping4
$ns connect $ping1 $ping5

proc sendPingPacket {} {
	global ns ping0 ping1
	set intervalTime 0.001
	set now [$ns now]
	$ns at [expr $now + $intervalTime] "$ping0 send"
	$ns at [expr $now + $intervalTime] "$ping1 send"
	$ns at [expr $now + $intervalTime] "sendPingPacket"
}

Agent/Ping instproc recv {from rtt} {
	global seq
	$self instvar node_
	puts "The node [$node_ id] received an ACK from the node $from with RTT $rtt ms"
}

$ping0 set class_ 1
$ping1 set class_ 2
$ping4 set class_ 4
$ping5 set class_ 5

$ns at 0.01 "sendPingPacket"
$ns at 10.0 "finish"
$ns run 
