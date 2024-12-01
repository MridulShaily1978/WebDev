<?php
  session_start();
  if (!isset($_SESSION['admin_id'])) {
      header("Location: login.php");
  }
?>
<!DOCTYPE html>
<html>
<head>
  <title>Admin Menu</title>
</head>
<body>
  <h1>Welcome, Admin</h1>
  <ul>
    <li><a href="manage_content.php">Manage Website Content</a></li>
    <li><a href="manage_admins.php">Manage Admin Users</a></li>
    <li><a href="logout.php">Logout</a></li>
  </ul> 
</body>
</html>
