#!/usr/bin/perl
use CGI;
use DBI;
$q=new CGI;
$nm=$q->param("pname");
$age=$q->param("age");
$db=DBI->connect('DBI:mysql:dbname','root','password');
$st="insert into age_info values ('$nm',$age)";
$q=$db->prepare($st);
$q->execute();
$q=$db->prepare("select * from age_info");
$q->execute();
print<<wp8;
content-type: text/html \n\n
<html>
<head><title>Database Information</title></head>
<body >
<h2>User Information</h2>
<center><table border=1 cellpadding=15>
<tr><th><h2>NAME<th><h2>AGE</tr>
wp8
while(($nm,$age)=$q->fetchrow())
{
print "<tr><td><h3>$nm<td><h3>$age</tr>";
}
$q->finish();
$db->disconnect();
print"</center></table></body></html>";

