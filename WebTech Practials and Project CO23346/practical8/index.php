<?php
  // Connect to database
  require_once('db_connection.php');

  // Fetch subjects and pages
  $query = "SELECT * FROM subjects WHERE visible = 1";
  $subjects_set = mysqli_query($connection, $query);
?>
 
<!DOCTYPE html> 
<html>
<head>
  <title>Widget Corp</title>
</head>
<body>
  <div id="header">
    <h1>Widget Corp</h1>
  </div>
  <div id="navigation">
    <ul>
      <?php while($subject = mysqli_fetch_assoc($subjects_set)) { ?>
        <li>
          <a href="index.php?subject=<?php echo urlencode($subject['id']); ?>">
            <?php echo $subject['menu_name']; ?>
          </a>
        </li>
      <?php } ?>
    </ul>
  </div>
  <div id="page-content">
    <p>Welcome to Widget Corp.</p>
  </div>
</body>
</html>
