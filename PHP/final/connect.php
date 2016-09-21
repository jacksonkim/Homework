<?php # mysqli_connect.php

// This file contains the database access information. 
// This file also establishes a connection to MySQL, 
// selects the database, and sets the encoding.

// Set the database access information as constants:
/*
DEFINE ('DB_HOST', 'mysql28.freehostia.com');
DEFINE ('DB_PASSWORD', '023schala');
DEFINE ('DB_USER', 'kimjac1_userdb');
DEFINE ('DB_NAME', 'kimjac1_userdb');
*/
//>mysql -h 97.74.31.27 -u jhuang123db01 -p
//Enter password: Jhuang123db0! [Enter]

DEFINE ('DB_HOST', 'mysql28.freehostia.com');
DEFINE ('DB_PASSWORD', '023schala');
DEFINE ('DB_USER', 'kimjac1_userdb');
DEFINE ('DB_NAME', 'kimjac1_userdb');

// Make the connection:
$dbc = @mysqli_connect (DB_HOST, DB_USER, DB_PASSWORD, DB_NAME) OR die ('Could not connect to MySQL: ' . mysqli_connect_error() );
// Set the encoding...
mysqli_set_charset($dbc, 'utf8');