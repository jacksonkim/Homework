/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package week.pkg4;

/**
 *
 * @author Kim
 */
import java.util.Scanner;
        
public class Week4 {

    /**
     * @param args the command line arguments
     */
    //public static void main(String[] args)
    {
        int menuOption,
                numItems;
        double total = 0;
        Scanner input = new Scanner(System.in);
        
        Purchase items = new Purchase();
        
        do
        {
            System.out.println("Thank you for shopping with us! %n"
                + "What would you like to buy today?");
            System.out.printf("1. Milk - %.2f", items.getMilk());
            System.out.println();
            System.out.printf("2. Eggs - %.2f", items.getEggs());
            System.out.println();
            System.out.printf("3. Butter - %.2f", items.getButter());
            System.out.println();
            System.out.printf("4. Bread - %.2f", items.getBread());
            System.out.println();
            System.out.print("Please enter the number of the "
                    + "item or -1 to exit: ");
            menuOption = input.nextInt();
            if (menuOption == -1)
                break;
            
            System.out.println();
            System.out.print("How many would you like to purchase? ");
            numItems = input.nextInt();
            
            total = calculateTotal(total, menuOption, numItems, items);
            
            System.out.printf("Your current total is: %.2f", total);
            System.out.println();
        } while (menuOption != -1);
        
        System.out.println("Please don't forget to drop by again!");
        System.out.println("Thank you for coming.");
    }
    
    public static double calculateTotal(double total, int menu, int num, Purchase items)
    {
        switch (menu)
        {
            case 1:
                total += (num * items.getMilk());
                break;
            case 2:
                total += (num * items.getEggs());
                break;
            case 3:
                total += (num * items.getButter());
                break;
            case 4:
                total += (num * items.getBread());
                break;
            default:
                System.out.println("That doesn't seem right.");
                break;
        }
        return total;
    }
}
