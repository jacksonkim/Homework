package filestreams;

import java.io.File;
import java.util.*;
class Test
{
	public static void main(String[] args)
	{
		// Object creation:
		Customer customer1 = new Customer("John","Smith","js@js.com");
		Customer customer2 = new Customer("Elizabeth","Johnson","ej@abc.com");
		customer2.setFirstName("Beth");
		customer2.setLastName("Johnson-Lopez");
		customer2.setEmailAddress("bjl@abc.com");
		
		// Storing object(s) to file:
		FileHandling fh = new FileHandling();
		ArrayList<Customer> al = new ArrayList<Customer>();
		al.add(customer1);
		al.add(customer2);
		fh.addCustomers(al,"customer.dat");
		
		// Retrieving stored data:
		fh.retrieveCustomerData("customer.dat");
		
		int option;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter 1 to end the program: ");
		option = input.nextInt();
	}
}	