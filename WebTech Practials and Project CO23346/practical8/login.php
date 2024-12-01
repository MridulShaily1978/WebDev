<?php
  session_start();
  require_once('db_connection.php');

  if (isset($_POST['submit'])) {
      $username = $_POST['username'];
      $password = $_POST['password'];

      $query = "SELECT * FROM admins WHERE username = '{$username}' LIMIT 1";
      $result = mysqli_query($connection, $query);

      if ($admin = mysqli_fetch_assoc($result)) {
          if (password_verify($password, $admin['hashed_password'])) {
              $_SESSION['admin_id'] = $admin['id'];
              header("Location: admin.php");
          } else {
              $message = "Invalid credentials.";
          }
      } else {
          $message = "Invalid credentials.";
      }
  } 
?>
<!DOCTYPE html>
<html>
<head>
  <title>Login</title>
</head>
<body>
  <form action="login.php" method="post">
    <p>Username: <input type="text" name="username"></p>
    <p>Password: <input type="password" name="password"></p>
    <input type="submit" name="submit" value="Login">
  </form>
</body>
</html>
