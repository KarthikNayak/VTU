#!/usr/bin/perl
use CGI;
$q = new CGI;
$cmd = $q->param("msg");
@greet=("hello","hi","good morning","have a nice day");
$index=length($cmd)%4;
print<<wp6a;
Content-type:text/html\n\n
<html>
<head><title>Welcome</title></head>
<body>
<h1><center>
$cmd , $greet[$index].
</center>
</h1></body></html>
wp6a

