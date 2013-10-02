#!/usr/bin/perl
use CGI ':standard';
print "Refresh: 1\n";
print "Content-Type: text/html\n\n";
print start_html(-title=>"Program 8",-bgcolor=>"Black",-text=>"white");
($s,$m,$h)=localtime(time);
print br,br,"The current system time is $h:$m:$s";
print br,br,hr,"In words $h hours $m minutes $s seconds";
print end_html;

