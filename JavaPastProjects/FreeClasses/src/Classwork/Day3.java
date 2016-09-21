/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Classwork;

/**
 *
 * @author Kim
 */
import Classwork.Math;
import java.util.Scanner;

public class Day3 
{
    
    //public static void main(String args[])
    {
        String another = "yes";
        
        Scanner input = new Scanner(System.in);
        Math avg = new Math();
        while (another=="yes")
        {
            do
            {
                System.out.print("Please enter the first number: ");
                avg.setnum1(input.nextInt());
                if (avg.getnum1()> 0)
                {
                    System.out.println("Thank you.");
                }
                else
                {
                    System.out.println("Please enter a number greater than 0.");
                }
            } while(avg.getnum1()!=0);

            do                
            {
                System.out.print("Please enter the second number: ");
                avg.setnum2(input.nextInt()); 
                if (avg.getnum2()>0)
                {
                    System.out.println("Thank you.");
                }
                else
                {
                    System.out.println("Please enter a number greater than 0.");
                }
            } while (avg.getnum2()!=0);

            while (avg.getnum1()!=0 && avg.getnum2()!=0)
            {
                System.out.print(avg.Average());
            }
            
            System.out.println();
            System.out.println("Would you like to average more number pairs?");
            System.out.println("Please enter yes to continue.");
            another=input.next();
            
        }

        
    }
    
} //end Day3 class
