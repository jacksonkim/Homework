/* CIST2373 - 20411 - Kimberly Jackson - SID: 0332
 * Week 5, JDBC Console - 9/22/13
 * 
 * Description: Create a simple console app to allow a user to query
        a database, the Northwinds Database for the following information:
        Print order total (minus frieght cost)
        Print all order details
        Print names and cities of all customers in a specific state
        Print the names of all employees who have a birthday in a specific year
        (that last one is really specific...)
 */

package jdbc;

import java.util.*;
import java.sql.*;

public class main 
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
		
		String state;
			
		int year, orderID, menuOption = 0;
                
        QueryFinder qf = new QueryFinder();
        
        do
        {
            System.out.println("Welcome to the QueryFinder.");
            System.out.println("1. Order Total");
            System.out.println("2. Order Details");
            System.out.println("3. Customers by State");
            System.out.println("4. Employees Birthdays by Year");
            System.out.println("5. Exit");
            System.out.print("What would you like to do? ");
            menuOption = input.nextInt();
            
            switch (menuOption)
            {
                case 1:
                    System.out.print("Please enter in the Order ID to total: ");
                    orderID = input.nextInt();
                    System.out.println();
                    qf.viewTotal(orderID);
                    System.out.println();
                    break;
                case 2:
                    System.out.print("Please enter in the Order ID: ");
                    orderID = input.nextInt();
                    System.out.println();
                    qf.viewOrderDets(orderID);
                    System.out.println();
                    break;
                case 3:
                    System.out.print("Please enter in the two letter "
                            + "abbreviation for the state: ");
                    state = input.next();
                    System.out.println();
                    qf.viewStates(state);
                    System.out.println();
                    break;
                case 4:
                    System.out.print("Please enter in the four digit year: ");
                    year = input.nextInt();
                    System.out.println();
                    qf.viewBirthday(year);
                    System.out.println();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("That wasn't one of the options. Please try again.\n");
                    break;
            }
            
        } while (menuOption !=5);
        
        
        System.out.println("Thank you for using QueryFinder.");
        System.out.println("We hope this application was of help to you.");
        qf.closeConnection();
    }
}
