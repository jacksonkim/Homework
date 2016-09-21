<!DOCTYPE html>
<html lan="en">

<head>

	<title>Grade Converter</title>
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

	<?php	
		function displayForm($Student, $NumGrade) 
		{
	?>
		<h2 style="text-align:center">Grade Converter</h2>
		<p>This form is here to help you convert your numerical grade to a letter grade.</p>
		<form action="PageTwo.php" method="post">
			<p>Student's Name: <input type="text" name="Student" value="<?php 
				 echo $Student; ?>" /></p>
			<p>Numerical Grade: <input type="text" name="NumGrade" value="<?php echo 
				 $NumGrade; ?>" /></p>
			<p><input type="reset" value="Clear Form" />
				&nbsp; &nbsp;
				<input type="submit" name="Submit" value="Send Form" /></p>
		</form>
	<?php
		}
		
		displayForm($Student, $NumGrade);
	?>

</body>

</html>