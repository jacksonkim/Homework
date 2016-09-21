<!DOCTYPE html>
<html lan="en">

<head>

	<title>Letter Grades</title>
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
		global $errorCount;
		if (empty($_POST['Student']))
		{
			echo "Student Name is a required field.<br />\n";
			++$errorCount;
		}
		if (empty($_POST['NumGrade']))
		{
			echo "Numerical Grade is a required field.<br />\n";
			++$errorCount;
		}
		else if(!is_numeric($_POST['NumGrade']))
		{
			echo "Numerical Grade field requires numbers only.<br />\n";
			++$errorcount;
		}
		
		function convertToLetterGrade($GradeNum)
		{
			if($GradeNum >= 90)
				return "A";
			else if($GradeNum >= 80)
				return "B";
			else if($GradeNum >= 70)
				return "C";
			else if($GradeNum >= 60)
				return "D";
			else if($GradeNum < 60)
				return "F";
		}
		
		function recordData($Name, $Grade)
		{
			$GradeFile = fopen("grades.txt", "ab");
			if (is_writeable("grades.txt")) 
			{
				if (fwrite($GradeFile, $Name.", ".$Grade."\n"))
					echo "<p>Grade has been recorded</p>\n";
				else
					echo "<p>Cannot record this student's grade.</p>\n";
			}
			else
					echo "<p>Cannot write to the file.</p>\n";
					
			fclose($GradeFile);
		}
		
		$Student = $_POST['Student'];
		$NumGrade = $_POST['NumGrade'];
		
		if($errorCount > 0)
		{
			echo "<p>Click your browser's Back button to return to 
				  the Grade Converter form and fix the errors.</p>\n";
		}
		else
		{			
			$LetterGrade = convertToLetterGrade($NumGrade);
			echo "<p>".$Student." has recieved a letter grade of ".$LetterGrade." for their score of ".$NumGrade."</p>\n";
			recordData($Student, $NumGrade);
		}
	?>

</body>

</html>