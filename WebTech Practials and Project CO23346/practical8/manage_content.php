<?php
  session_start();
  require_once('db_connection.php');

  if (!isset($_SESSION['admin_id'])) {
      header("Location: login.php");
  }

  $query = "SELECT * FROM subjects";
  $subjects = mysqli_query($connection, $query);
?>

<!DOCTYPE html>
<html>
<head>
  <title>Manage Content</title>
</head>
<body>
  <h1>Manage Content</h1>
  <a href="new_subject.php">+ Add a Subject</a>
  <ul>
    <?php while($subject = mysqli_fetch_assoc($subjects)) { ?>
      <li><?php echo $subject['menu_name']; ?> | <a href="edit_subject.php?id=<?php echo $subject['id']; ?>">Edit</a></li>
    <?php } ?> 
  </ul>
</body>
</html>
