<?php
$host = "localhost";         // Server hostname
$user = "root";              // XAMPP default MySQL user
$password = "";              // Default password is empty
$dbname = "cms";             // Your database name

// Create a connection
$connection = mysqli_connect($host, $user, $password, $dbname);

// Check connection
if (!$connection) {
    die("Database connection failed: " . mysqli_connect_error());
}
?>
