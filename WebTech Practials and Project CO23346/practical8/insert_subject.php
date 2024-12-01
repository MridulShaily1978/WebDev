<?php
require_once('db_connection.php');

$menu_name = "About Us";
$position = 1;
$visible = 1;

$query = "INSERT INTO subjects (menu_name, position, visible) 
          VALUES ('$menu_name', $position, $visible)";

$result = mysqli_query($connection, $query);

if ($result) { 
    echo "Record created successfully!";
} else {
    echo "Error: " . mysqli_error($connection);
}
?>
