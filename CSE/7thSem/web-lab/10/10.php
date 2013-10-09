<?php
session_start();
session_register("count");
if (!isset($_SESSION))
{
$_SESSION["count"] = 0;
echo "<p>Counter initialized</p>\n";
}
else { $_SESSION["count"]++; }
echo "<p>The counter is now <b>$_SESSION[count]</b></p><p>reload this page to increment</p>";
?>

