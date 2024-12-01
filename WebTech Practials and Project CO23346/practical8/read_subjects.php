<?php
require_once('db_connection.php');

// SQL Query to fetch all subjects
$query = "SELECT * FROM subjects";
$result = mysqli_query($connection, $query);

// Check if query was successful
if ($result) {
    echo "<h1>Subjects List:</h1>";
    
    // Loop through the results and display each record
    while ($subject = mysqli_fetch_assoc($result)) {
        echo "ID: " . $subject['id'] . "<br>";
        echo "Menu Name: " . $subject['menu_name'] . "<br>";
        echo "Position: " . $subject['position'] . "<br>";
        echo "Visible: " . ($subject['visible'] ? "Yes" : "No") . "<br><br>";
    }

    // Free result set
    mysqli_free_result($result);
} else {
    echo "Error: " . mysqli_error($connection);
}

// Close the connection
mysqli_close($connection);
?>
