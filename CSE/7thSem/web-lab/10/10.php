<?php
session_start();
// store session data
if(!isset($_SESSION))
$_SESSION['views']=1;
else
$_SESSION['views']++;

?>

<html>
<body>

<?php
//retrieve session data
echo "Pageviews=". $_SESSION['views'];
?>

</body>
</html>
