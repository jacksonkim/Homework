package ParkingGarage;
/* CIST 2731 - Kimberly Jackson - CRN: 20790 - SID: 0332
 * 
 * Week 2, Program 2, Parking Attendant application
 * 
 * Description: A parking garage charges a $2.00 minimum fee to park for 
 *  up to three hours. The garage charges an additional $0.50 per hour 
 *  for each hour or part thereof in excess of three hours. The maximum charge 
 *  for any given 24-hour period is $10.00. Assume that no car parks for 
 *  longer than 24 hours at a time. Write a Java console application that 
 *  calculates and displays the parking charges for each customer. Input 
 *  should be the time parked in hours and fractions (not hours and minutes). 
 *  The program should display the charge for the current customer and should 
 *  calculate and display the running total of the receipts after each input. 
 *  The program should use the method calculateCharges to determine the charge 
 *  for each customer. Sentinel values are to be used to end loops.
 *
 */

import java.util.Scanner;

public class ParkingAttendant
{
   public static void main(String[] args)
   {
        Scanner input = new Scanner(System.in);
        
        float total = 0;
        float parkedTime;
        
        //casual greeting
        System.out.println("Sorry to see you leave. This parking attendant"
                + " will help you in paying for your stay.");
        System.out.println("Otherwise you'll have to stay here forever.");
        System.out.println("Ha. Just kidding...");
        System.out.println("------------------------"
                + "-------------------------------");
        System.out.println("OR AM I?");


        System.out.println();
        System.out.println("Please input the amount of time "
                + "you have been parked by using decimals or whole numbers.");
        System.out.println("You may enter -1 to complete your transaction.");
        System.out.println("Your input should look something like this: "
                + "1.5 or 3.2 - This means no minutes, basically.");
        System.out.print("Your time, please: ");
        parkedTime = input.nextFloat();

        while(parkedTime != -1)
        {
            float customerTotal = calculateCharges(parkedTime);
            total += customerTotal;

            //display customer output
            System.out.printf("The current rate for parking %.2f "
                    + "hours is %.2f \n", parkedTime, customerTotal);

            //display total receipts
            System.out.printf("Add this to your running total and your"
                    + " current daily total is %.2f \n", total);

            //prompt user for time parked
            System.out.println();
            System.out.println("And here we are again.");
            System.out.println("Please input the amount of time "
                    + "you have been parked by using decimals or whole numbers.");
            System.out.println("You may enter -1 to complete your transaction.");
            System.out.println("Your input should look something like this: 1.5 or 3.2");
            System.out.print("Your time, please: ");
            parkedTime = input.nextFloat();
        } //end sentinel controlled loop
        
   }

   //this function accepts one float, the value of parkedTime and uses it
   //to calculate the charge
   public static float calculateCharges(float parka)
   {
        float amountDue = 0.0f,
                partialhours,
                solidhours;

        if(parka > 0)
        {
            if (parka <=3)
            {
                amountDue = 2.00f;
            }
            else if (parka > 3)
            {
                if (parka < 24)
                {
                    //add 2$ for first 3 hours
                    amountDue = 2.00f;

                    //take away those 3 hours since the customer was 
                    //already charged 2$ for them
                    parka = parka - 3;

                    partialhours = parka % 1; //to hold the partials
                    //so that this calculation can be done
                    solidhours = parka - partialhours; 
                    

                    //add .50 cent for each whole hour that's left
                    amountDue = amountDue + (solidhours * .5f);

                    
                    if(partialhours > 0)
                    {
                        //add additional .50 cent if any partial hours are left
                        amountDue = amountDue + .5f;
                    }//end if partialhours > 0

                    //check to see the current value of amountDue is not over 10$
                    if(amountDue > 10.00f)
                    {
                        //reset the charge
                        amountDue = 10.00f;
                    }//end if due >10  
                    
                } //end if parka > 24
                
            }//end if parka <=3 or >3
            
        }//end the if parka > 0

        return amountDue;
   } //end calculateCharges
}