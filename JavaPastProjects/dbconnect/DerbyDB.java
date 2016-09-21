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

import java.sql.*;

public class DerbyDB
{
	private Connection con = null;
	private Statement sta = null;
	private ResultSet res = null;
		
	public DerbyDB()
	{
		
	}
	
	public void viewData(String serverName, String dbName, String tableName, String fn1, String fn2,
		String fn3, String fn4, String fn5)
	{
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://" + serverName + "/" + dbName);
			sta = con.createStatement();
			res = sta.executeQuery("select * from " + tableName);
			
			while(res.next())
			{ 
				System.out.println(fn1 + ": " + res.getInt(fn1) + "\t" + fn2 + ": " + 
					res.getString(fn2) + ": " + fn3 + ": " + res.getString(fn3));
				System.out.println(fn4 + ": " + res.getInt(fn4) + "\t" + fn5 + ": " + 
					res.getInt(fn5));
				System.out.println();
			};
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			closeConnection();
		}

	}
	
	public void addData(String serverName, String dbName, String tableName,
		int id, String fname, String lname, String pnum, int age)
	{
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://" + serverName + "/" + dbName);
			sta = con.createStatement();
			int res = sta.executeUpdate("insert into " + tableName + 
				" values(" + id + ", '" + fname + "', '" + lname + "', '" + pnum + "', " + age + ")");			
			
			System.out.println("Added information to database.");
			System.out.println();
			closeConnection();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			closeConnection();
		}
		
	}
	
	public void closeConnection()
	{
		try
		{
			if(res != null)
			{
				res.close();
			}
			if(sta != null)
			{
				sta.close();
			}
			if(con != null)
			{
				con.close();
			}

		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}