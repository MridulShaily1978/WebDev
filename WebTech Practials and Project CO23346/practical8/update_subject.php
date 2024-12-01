<?php
require_once('db_connection.php');

// Values to update
$id = 1;  // ID of the subject you want to update
$new_menu_name = "Updated About Us"; 
$new_position = 2; 
$new_visible = 0; 

// SQL Query to update the subject
$query = "UPDATE subjects 
          SET menu_name = '$new_menu_name', position = $new_position, visible = $new_visible 
          WHERE id = $id";

$result = mysqli_query($connection, $query);

if ($result) {
    echo "Record updated successfully!";
} else {
    echo "Error: " . mysqli_error($connection);
}

// Close the connection
mysqli_close($connection);
?>
