package interface_assignment;

import java.util.Scanner;

class Test{
    public static void main(String[] args)
	 {
        // The code below is legal since each object below 
        // is also of Employee type (by inheritance)
        Employee emp1 = new Technician();
        Employee emp2 = new Operator();
        Employee emp3 = new Manager();

        /*
            Part 2:            
            - Write code here to get data from user
              to populate the three employee objects above.
            
            - After that, print the pay checks as
              output to display all employee information
              along with the check amount for all 3 employees.
        */
		  Scanner input = new Scanner(System.in);
		  
			//technician
		  System.out.print("Please enter in the FIRST name of your Technician: ");
		  emp1.setFirstName(input.next());
		  
		  System.out.print("Please enter in the LAST name of your Technician: ");
		  emp1.setLastName(input.next());
		  
		  System.out.print("Please enter in the ANNUAL SALARY of your Technician: ");
		  emp1.setAnnualSalary(input.nextDouble());
		  
		  System.out.println();
		  
		  //operator
		  System.out.print("Please enter in the FIRST name of your Operator: ");
		  emp2.setFirstName(input.next());
		  
		  System.out.print("Please enter in the LAST name of your Operator: ");
		  emp2.setLastName(input.next());
		  
		  System.out.print("Please enter in the ANNUAL SALARY of your Operator: ");
		  emp2.setAnnualSalary(input.nextDouble());
		  
		  System.out.println();
		  
		  //manager
		  System.out.print("Please enter in the FIRST name of your Manager: ");
		  emp3.setFirstName(input.next());
		  
		  System.out.print("Please enter in the LAST name of your Manager: ");
		  emp3.setLastName(input.next());
		  
		  System.out.print("Please enter in the ANNUAL SALARY of your Manager: ");
		  emp3.setAnnualSalary(input.nextDouble());
		  
		  System.out.println();
		  System.out.println();
		  //technician
		  emp1.printCheck();
		  System.out.println();
		  //operator
		  emp2.printCheck();
		  System.out.println();
		  //manager
		  emp3.printCheck();
	}
}