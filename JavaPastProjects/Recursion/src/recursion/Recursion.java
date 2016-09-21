/* CIST 2371 - 20790 - Kimberly Jackson - SID 0332
 * Week 13?, Recursion App - 12/6/12
 * 
 * Description: Create a recursive method - recursiveLinearSearch
 * to perform a linear search of an array. The method should receive
 * the search key and the starting index as arguments. If the 
 * search key is found, return the index in the array. If the key is
 * NOT found, return -1. Each call should only check one index in the array.
 *(Side note, this sounds like it would be dumb in practice? At first glance.)
 * 
 */
package recursion;

import java.util.Scanner;

public class Recursion 
{

    
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int searchInt;
        //why is this outside of the loop
        
        LinearArray searchArray = new LinearArray(10);
        System.out.println(searchArray+"\n");
        
        System.out.print("Please enter an integer value (-1 to quit): ");
        searchInt = input.nextInt();
        
        while (searchInt != -1)
        {
            int position=0; //if you ran this program multiple times, this position
            //would be set to 11 if the variable remained outside of the loop.
            //keeping it in the loop means it gets reset to 0 at the end of the loop
            position = searchArray.recursiveLinearSearch(searchInt, position);
            
            if (position == -1)
                System.out.println("The integer "+searchInt+" was not found.\n");
            else
                System.out.println("The integer "+searchInt+" was "
                        + "found in position "+position+".\n");
            
            System.out.print("Please enter an integer value (-1 to quit): ");
            searchInt = input.nextInt();
        }
    }
}
