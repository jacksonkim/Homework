/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Ecomm;

/**
 *
 * @author Kim
 */
import java.util.Scanner;

public class Ecomm
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
      int menuOption;
      
      Scanner input = new Scanner(System.in);
      
      Inventory inv = new Inventory();
      
      inv.ListAvailableProducts();
      System.out.print("Please choose an item: ");
      menuOption = input.nextInt();
        
    }
}
