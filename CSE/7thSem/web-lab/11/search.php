<html>
<head>
	<title>Search</title>
</head>
<body>
	<center><h1>Search results for "<? echo $_REQUEST["name"];?>"</h1></center>
	<table border="1" align="center">
		<tr>
			<th>Name</th>
			<th>Address Line 1</th>
			<th>Address LIne 2</th>
			<th>Email ID</th>
		</tr>
		<?php
			$name=$_REQUEST["name"];
			$con = mysql_connect("localhost","root","pass") or die('Could not connect: ' . mysql_error());
			mysql_select_db("test",$con);

			$result=mysql_query("select * from student where name like '%".$name."%'");
			while($row = mysql_fetch_array($result))
			{
				echo "<tr>";
				echo "<td>".$row['name']."</td>";
				echo "<td>".$row['addr1']."</td>";
				echo "<td>".$row['addr2']."</td>";
				echo "<td>".$row['email']."</td>";
				echo "</tr>";
			}
			mysql_close($con);
		?>
	</table>
</body>
</html>
