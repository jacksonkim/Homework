/* CIST 2372 - 40790 - Kimberly Jackson - SID: 0332

	Week 6, Program DBConnect - 3/4/2013
	
	Description: Create a program that asks a user for
		employee information until the user enters 'no'
		to stop the program.
		Each round of input should be stored in a database
		and added to the table in the database with an ID number
		that increments for every employee added(use Java logic).
		Check each input to ensure that each employee's name is
		not duplicated.
		
		When the program ends, all employee records should be
		retrieved and displayed.
		
		DB structure:
			DB Name: EmployeeDB
			Table Name: Employee
			Table fields: ID_Number int, firstName varchar(20),
				lastName varchar(20), phoneNumber varchar(10), age int

*/

import java.util.*;

public class DBConnect
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		String again = "y",
			fname,
			lname,
			pnum;
			
		int age,
			id = 0;
		
		DerbyDB employees = new DerbyDB();
		
		do
		{
			System.out.print("Please enter in employee's FIRST name: ");
			fname = input.next();
			
			System.out.print("\nPlease enter in employee's LAST name: ");
			lname = input.next();
			
			System.out.print("\nPlease enter in employee's PHONE NUMBER: ");
			pnum = input.next();
			
			System.out.print("\nPlease enter in employee's AGE: ");
			age = input.nextInt();
			
			System.out.println("\nFirst name: " + fname + "\tLast name: " + lname);
			System.out.println("Phone number: " + pnum + "\tAge: " + age);
			System.out.println("will be posted in the Employee database.");
			
			System.out.print("\nWould you like to enter in more employee information?");
			System.out.print("\nPlease type in y to continue, n to quit: ");
			again = input.next();
			
			id += 1;
			employees.addData("localhost:1527", "EmployeeDB", "Employee", id, fname, lname, pnum, age);
			
		} while(again == "y");
		
		employees.viewData("localhost:1527", "EmployeeDB", "Employee", "ID_Number", 
			"firstName", "lastName", "phoneNumber", "age");
			
	}
}