<!DOCTYPE html>
<!-- HTML5 style -->

<html lan="en">
<head>
	<title>Rebel List</title>
	<meta charset="utf-8" />
	
	<style>
		body {background-color: #512882;
			font-family: Century Gothic, Segoe UI, sans-serif;
			font-size: 11pt;
			color: #FFFFFF;}
		h1 {text-align:center;}
		div {text-align:center;}
		a:link { color:#CC99CC;}
		a:hover {color:#CC99CC; background-color:#ffffff;}
		a:visited {color:#FFFFFF;}
		img { margin-left: auto; margin-right: auto; }
	</style>
</head>

<body>


	<?php # view_users.php 
	// This script retrieves all the records from the users table.

	$page_title = 'List Others';
	//include ('includes/header.html');

	// Page header:
	echo '<h1>List Rebels</h1>';

	require ('connect.php'); // Connect to the db.
			
	// Make the query:
	$q = "SELECT username, firstname, password FROM usertb ORDER BY firstname ASC";		
	$r = @mysqli_query ($dbc, $q); // Run the query.
	print_r($r);
	// Count the number of returned rows:
	$num = mysqli_num_rows($r);

	if ($num > 0) { // If it ran OK, display the records.

		// Print how many users there are:
		echo "<p>There are currently $num registered rebels in the fight.</p>\n";

		// Table header.
		echo 
		'<table align="center" cellspacing="3" cellpadding="3" width="75%"> '.
		'<tr><td align="left"><b>Username</b></td> '.
		'<td align="left"><b>First Name</b></td> '.
		'<td align="left"><b>Password</b></td> '.
		'</td></tr>';
		
		// Fetch and print all the records:
		while ($row = mysqli_fetch_array($r, MYSQLI_ASSOC)) 
		{
			echo 
			'<tr><td align="left">' . $row['username'] . '</td>'."\n".
			'<td align="left">' . $row['firstname'] . '</td>'."\n".
			'<td align="left">' . $row['password'] . '</td></tr>'."\n";
		}
		echo '</table>'; // Close the table.
		
		mysqli_free_result ($r); // Free up the resources.	

	} 
	else 
	{ // If no records were returned.

		echo '<p class="error">There are currently no registered fighters. Wily would be pleased.</p>';

	}

	if (isset($_POST['register']))
	{
		
		validate_register($_POST['username'], $_POST['firstname'], $_POST['password']);
		
	}
	
	function validate_register($username, $firstname, $password) 
	{
	   global $errors;
	   
		// Validate the username:
		if (empty($username)) 
			$errors[] = 'You forgot to enter your user id.';
		if (empty($firstname)) 
			$errors[] = 'You forgot to enter your first name.';
		if (empty($password)) // Validate the password:
			$errors[] = 'You forgot to enter your password.';
		
		$row = array();
		
		require ('connect.php'); // Connect to the db.

		$uid = mysqli_real_escape_string($dbc, trim($username));
		$fn = mysqli_real_escape_string($dbc, trim($firstname));
		$passwd = mysqli_real_escape_string($dbc, trim($password));
		// Retrieve the username and first_name for that username/password combination:
		$q = "SELECT username, firstname, password FROM usertb WHERE username='$uid' AND password='$passwd'";		
		$r = @mysqli_query ($dbc, $q); // Run the query.
		// Check the result:
		if (mysqli_num_rows($r) == 1) 
		{
			// Fetch the record:
			$row = mysqli_fetch_array ($r, MYSQLI_ASSOC);
			echo "That person is already registered.";
		} 
		else 
		{ // Not a match!
			echo 'Welcome to the fight!';
			
			$q2 = "INSERT INTO usertb (username, firstname, password) VALUES ('$uid', '$fn', '$passwd')";		
			$r2 = @mysqli_query ($dbc, $q2);
		}
		mysqli_close($dbc); // Close the database connection.		
	}
	
	mysqli_close($dbc); // Close the database connection.
	?>

	<h1>Register a Rebel</h1>
	<form action="main.php" method="post">
		<p>Username: <input type="text" name="username" size="16" maxlength="20" value="<?php if (isset($_POST['username'])) echo $_POST['username']; ?>"  /> </p>
		<p>First Name(only): <input type="text" name="firstname" size="16" maxlength="20" value="<?php if (isset($_POST['firstname'])) echo $_POST['firstname']; ?>"  /></p>
		<p>Password: <input type="password" name="password" size="16" maxlength="6" value="<?php if (isset($_POST['password'])) echo $_POST['password']; ?>"  /></p>
		<p><input type="submit" name="register" value="Register"></p>
	</form>
	
	<?php 
	if (!empty($errors)) 
	{
			echo '<h1>Error!</h1>
			<p class="error">The following error(s) occurred:<br />';
			foreach ($errors as $msg) 
			{ // Print each error.
				echo " - $msg<br />\n";
			}
			echo '</p><p>Please try again.</p><p><br /></p>';
	}
	//include ('includes/footer.html'); 
	?>

</body>
</html>