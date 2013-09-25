#!/usr/bin/perl
print<<1;
	Content-type:text/html\n\n
	<html>
		<body>
			<table cellpadding=5 border=1>
				<tr>
					<th>ENV_VARIABLES</th>
					<th>VALUE</th>
				</tr>
1
foreach $i (sort keys %ENV)
{
	print "<tr><td>$i</td><td>$ENV{$i}</td></tr>";
}
print "</table></body></html>";

