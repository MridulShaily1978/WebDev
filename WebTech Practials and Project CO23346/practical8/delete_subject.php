<?php
require_once('db_connection.php');

// ID of the subject to delete
$id = 1;  // Change this to the ID of the record you want to delete

// SQL Query to delete the subject
$query = "DELETE FROM subjects WHERE id = $id";

$result = mysqli_query($connection, $query);

if ($result) {
    echo "Record deleted successfully!";
} else {
    echo "Error: " . mysqli_error($connection);
}

// Close the connection
mysqli_close($connection);
?>
