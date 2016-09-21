package filestreams;

import java.io.*;
import java.util.*;
class FileHandling
{
	FileWriter fw = null;
	BufferedWriter bw = null;
	
	
	public FileHandling()
	{
	
	}
	
	public void addCustomers(ArrayList<Customer> al, String filePath)
	{
		//BufferedWriter br;
		try
		{		
			fw = new FileWriter(filePath);
			bw = new BufferedWriter(fw);
			
			for (int counter = 0; counter < al.size(); counter++)
			{
				Customer cust = al.get(counter);
				
				String first = cust.getFirstName(),
					last = cust.getLastName(),
					email = cust.getEmailAddress();
					//temp = " ";
				
				System.out.println("Extracted data from Customer Object.");
				
				bw.write(first);
				bw.write(" ");
				bw.write(last);
				bw.write(" ");
				bw.write(email);
				bw.write(" ");
				
				System.out.println("Wrote data to file.");
			}
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		finally
		{
			if(bw != null)
			{
				bw.close();
			}
		}
		
	}
	
	public void retrieveCustomerData(String filePath)
	{
		
	}
}