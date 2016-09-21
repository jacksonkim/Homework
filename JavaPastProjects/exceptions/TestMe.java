import java.util.*;
import java.text.*;
import java.io.*;

public class TestMe
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String myString = "",
		errorlog;
		
		Date date = new Date();
		SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy h:mm:ss a");
		String formattedDate = sdf.format(date);
		
		System.out.print("Please enter an integer(whole number): ");
		
		try
		{
			myString = input.next();
			
			System.out.println("\nYou have entered: " + myString);
			if(myString.matches("^[-+]?\\d+(\\.\\d+)?$"))
			{
				throw new MyNumberException(false);
			}
			else
			{
				throw new MyNumberException(true);
			}
		}
		catch(MyNumberException men)
		{
			System.out.println("\n" + men.getMessage());
			try
			{
				FileWriter fw = new FileWriter("errorlog.txt", true);
				errorlog = "\n" + formattedDate + " MyNumberException";
				fw.write(errorlog);
				fw.close();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
		catch(InputMismatchException mime)
		{
			System.out.println("You did not enter an integer.");
			try
			{
				FileWriter fw = new FileWriter("errorlog.txt", true);
				errorlog = "\n" + formattedDate + " InputMismatchException";
				fw.write(errorlog);
				fw.close();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
			
		}
		
		
		System.out.print("Please enter some letters or words: ");
		try
		{
			myString = input.next();
			System.out.println("\nYou have entered: " + myString);
			if(myString.matches("^[-+]?\\d+(\\.\\d+)?$"))
			{
				throw new MyNumberException(false);
			}
			else
			{
				throw new MyNumberException(true);
			}

		}
		catch(MyNumberException men)
		{
			System.out.println("\n" + men.getMessage());
			try
			{
				FileWriter fw = new FileWriter("errorlog.txt", true);
				errorlog = "\n" + formattedDate + " MyNumberException";
				fw.write(errorlog);
				fw.close();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
		catch(InputMismatchException mime)
		{
			System.out.println("You did not enter an integer.");
			try
			{
				FileWriter fw = new FileWriter("errorlog.txt", true);
				errorlog = "\n" + formattedDate + " InputMismatchException";
				fw.write(errorlog);
				fw.close();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}	
		}
		

	}
}