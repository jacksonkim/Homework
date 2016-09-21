/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package MiniMath;

/**
 *
 * @author Kim
 */
import java.util.Scanner;

public class TestMath 
{
    
    //public static void main(String args[])
    {
        int num1, num2;
        float numf1, numf2;
        double numd1, numd2;
        String numstr1, numstr2;
        
        Scanner input = new Scanner(System.in);
        
        System.out.println("This is a test.");
        System.out.println();
        System.out.print("Please enter integer 1: ");
        num1 = input.nextInt();
        System.out.print("Please enter integer 2: ");
        num2 = input.nextInt();
        System.out.printf("The sum of those two is %d", 
                MiniMath.Add(num1, num2));
        System.out.println();
        System.out.println();
        System.out.print("Please enter float 1: ");
        numf1 = input.nextFloat();
        System.out.print("Please enter float 2: ");
        numf2 = input.nextFloat();
        System.out.printf("The sum of those two is %.1f", 
                MiniMath.Add(numf1, numf2));
        System.out.println();
        System.out.println();
        System.out.print("Please enter double 1: ");
        numd1 = input.nextDouble();
        System.out.print("Please enter double 2: ");
        numd2 = input.nextDouble();
        System.out.printf("The sum of those two is %.2f", 
                MiniMath.Add(numd1, numd2));
        System.out.println();
        System.out.println();
        System.out.print("Please enter String 1: ");
        numstr1 = input.next();
        System.out.print("Please enter float 2: ");
        numstr2 = input.next();
        System.out.printf("The sum of those two is %s", 
                MiniMath.Add(numstr1, numstr2));
        System.out.println();
        System.out.println();
        System.out.println("Thank you.");
    }
    
}
