/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Day1;

/**
 *
 * @author Kim
 */
import java.util.Scanner;
public class Day1 
{
    int classVar=4;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
         /*System.out.println("\nHello world.");
        System.out.println("Oh wow there sure are a lot of you.");
        System.out.println("No, no, one at a time please.");
        */
        
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num1 = input.nextInt();
        
        System.out.print("Enter another number: ");
        int num2 = input.nextInt();
    
        int sum=Add();
        System.out.printf("\n%s%d\n", "The average of the prior two numbers is ", 
                average(num1, num2));
       
    }
    
    public static int Add()
    {
        int x=2;
        int y=3;
        int z=(x+y+52)/3; //originally classVar
        System.out.println(z);
        return z;       
    }
    
    public static int average(int numa1, int numa2)
    {
        
        int average=(numa1+numa2)/2;
        
        return average;
    }
}
