<!DOCTYPE html>
<!-- HTML5 style -->

<html lan="en">
<head>

	<title>Login Page</title>
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


	<?php # login.php

	// main()
	if (isset($_POST['submit'])) 
	{
		$errors = array(); // Initialize an error array.
	   
	   validate($_POST['username'], $_POST['password']);
		
	   if (empty($errors)) 
	   {
		  // Check the login:
		  list ($authenticated, $data) = authenticate($_POST['username'], $_POST['password']);
	   
	   if ($authenticated) 
	   { // OK!
			 // Set the cookies:
			 setcookie ('username', $data['username']);
			 setcookie ('firstname', $data['firstname']);
			 setcookie ('password', $data['password']);
			 // Redirect:
			 header("Location: main.php");  //re-direct to a different page!!
		  } 
		  else 
		  { // Unsuccessful!
		  //!!! $errors will be displayed at due time, below the form (see main form below !!!
		  }
	   }
	} // End of the main Submit conditional.
	
	function validate($username, $password) 
	{
	   global $errors;
	   
		// Validate the username:
		if (empty($username)) 
			$errors[] = 'You forgot to enter your user id.';	// Validate the password:
		if (empty($password)) 
			$errors[] = 'You forgot to enter your password.';
	}

	function authenticate($username, $password) 
	{
		global $errors;
		$check = false;
		$row = array();
	   
		require ('connect.php'); // Connect to the db.

		$uid = mysqli_real_escape_string($dbc, trim($username));
		$passwd = mysqli_real_escape_string($dbc, trim($password));
		// Retrieve the username and first_name for that username/password combination:
		$q = "SELECT username, firstname, password FROM usertb WHERE username='$uid' AND password='$passwd'";		
		$r = @mysqli_query ($dbc, $q); // Run the query.
		// Check the result:
		if (mysqli_num_rows($r) == 1) 
		{
			// Fetch the record:
			$row = mysqli_fetch_array ($r, MYSQLI_ASSOC);
		  $check = true;
		} 
		else 
		{ // Not a match!
			$errors[] = 'The username and password entered do not match those on file.';
			$check = false;
		}
		mysqli_close($dbc); // Close the database connection.
	   return array($check, $row);
	} // End of authenticate() function.

	?>

	<h1>Login</h1>
	<form action="login.php" method="post">
		<p>Username: <input type="text" name="username" size="16" maxlength="20" value="<?php if (isset($_POST['username'])) echo $_POST['username']; ?>"  /> </p>
		<p>First Name(only): <input type="text" name="firstname" size="16" maxlength="20" value="<?php if (isset($_POST['firstname'])) echo $_POST['firstname']; ?>"  /></p>
		<p>Password: <input type="password" name="password" size="16" maxlength="6" value="<?php if (isset($_POST['password'])) echo $_POST['password']; ?>"  /></p>
		<p><input type="submit" name="submit" value="Login" /></p>
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