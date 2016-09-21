import java.util.*;
import java.io.*;
import java.text.*;
import java.sql.*;

public class CustomerDatabase
{
	public static void main(String[] args)
	{
		String again = "y",
			fname = "",
			lname = "",
			emailaddress = "";
		
		Scanner input = new Scanner(System.in);
		
		do
		{

			System.out.print("Please enter in employee's FIRST name: ");
			try
			{
				fname = input.next();
				
				if(fname.matches("^[-+]?\\d+(\\.\\d+)?$") == true)
				{
					throw new MyNumberException();
				}
			}
			catch(MyNumberException mime)
			{
				System.out.println(mime.getMessage());
			}
			
			System.out.print("\nPlease enter in employee's LAST name: ");
			try
			{
				lname = input.next();
				
				if(lname.matches("^[-+]?\\d+(\\.\\d+)?$") == true)
				{
					throw new MyNumberException();
				}
			}
			catch(MyNumberException mime)
			{
				System.out.println(mime.getMessage());
			}
						
			System.out.print("\nPlease enter in employee's EMAIL ADDRESS: ");
			try
			{
				emailaddress = input.next();
				
				if(emailaddress.matches("^[-+]?\\d+(\\.\\d+)?$") == true)
				{
					throw new MyNumberException();
				}
			}
			catch(MyNumberException mime)
			{
				System.out.println(mime.getMessage());
			}
						
			System.out.println("\nFirst name: " + fname + "\tLast name: " + lname);
			System.out.println("Email Address: " + emailaddress);
			System.out.println("will be posted in the Employee database.");
			
			System.out.print("\nWould you like to enter in more employee information?");
			System.out.print("\nPlease type in y to continue, n to quit: ");
			again = input.next();
			
			Customer cust = new Customer(fname, lname, emailaddress);
			addCustomer(cust);
			
		} while(again == "y");
		
		ArrayList<Customer> customs = new ArrayList<Customer>();
		
		customs = retrieveCustomers();
		
		Customer[] customers = customs.toArray(new Customer[0]);
		
		for(int count = 0; count <= (customers.length-1); count++)
		{
			System.out.println("\nFirst name: " + customers[count].getFirstName() + "\tLast name: " + customers[count].getLastName());
			System.out.println("Email Address: " + customers[count].getEmailAddress());
		}
		
		System.out.println("\nThanks for coming!");
	}
	
	public static void addCustomer(Customer c)
	{
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		String fname, lname, emaddress;
	
		String fn1 = "f_name", fn2 = "l_name", fn3 = "e_address";
		
		fname = c.getFirstName();
		lname = c.getLastName();
		emaddress = c.getEmailAddress();
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/CustomerData");
			sta = con.createStatement();
			int res1 = sta.executeUpdate("insert into Customer values('" + fname + "', '" + lname + "', '" + emaddress + "')");			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
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
	
	public static ArrayList<Customer> retrieveCustomers()
	{
		Connection con = null;
		Statement sta = null;
		ResultSet res = null;
		
		String fname, lname, emaddress;
	
		String fn1 = "f_name", fn2 = "l_name", fn3 = "e_address";
		
		ArrayList<Customer> customers = new ArrayList<Customer>();
		
		try
		{
			Class.forName("org.apache.derby.jdbc.ClientDriver").newInstance();
			con = DriverManager.getConnection("jdbc:derby://localhost:1527/CustomerData");
			sta = con.createStatement();
			res = sta.executeQuery("select * from Customer");
			
			while(res.next())
			{
				fname = res.getString(fn1);
				lname = res.getString(fn2);
				emaddress = res.getString(fn3);
				
				Customer cust = new Customer(fname, lname, emaddress);
				customers.add(cust);
			}
			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
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
		
		return customers;
	}
}