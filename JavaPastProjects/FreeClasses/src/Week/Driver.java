package Week;

import Week.Week;
import java.util.Scanner;

public class Driver
{
    public static void main(String args[])
    {
        int day;
        Scanner input = new Scanner(System.in);
        do
        {
           System.out.println("This application will convert the numerical value");
        System.out.println("of the day of the week into an actual day");
        System.out.println();
        System.out.print("Please enter the number of the day of the week: ");
        day = input.nextInt();
        
        while (day > 7 | day < 1)
        {
            System.out.println();
            System.out.println("The only valid numbers are 1 through 7.");
            System.out.print("Please enter the number of the day of the week: ");
            day = input.nextInt();
        }
        
        Week dailies = new Week();
        System.out.println();
        System.out.print("The day of the week appears to be ");
        System.out.print(Week.DisplayDailyMessage(day));
        System.out.println(".");
        
        System.out.println();
        System.out.println("To exit this application, enter in -1.");
        System.out.print("Please enter the number of the day of the week: ");
        day = input.nextInt();
        }while (day != -1);
        
    }
}