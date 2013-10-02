#!/usr/bin/perl
use CGI ':standard';
use CGI::Carp qw(warningsToBrowser);
print header();
print start_html(-title=>"WebPage Counter",-bgcolor=>"White",-text=>"black");
open(FILE,'<count.txt');
$count=<FILE>;
close(FILE);
$count++;
open(FILE,'>count.txt');
print FILE "$count";
print ("This page has been viewed $count times");
close(FILE);
print end_html();

