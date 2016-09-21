package calculatemileage;

/**
 * @(#)CalculateMileage.java
 *
 *
 * @author
 * @version 1.00 2012/6/13
 * 
 * @Author Kimberly Jackson
 * @version 1.2 8/30/2012
 * I wasn't sure if we were supposed to program this ourselves or wait until
 * next class. So I have taken the solution provided and edited it to improve
 * and generally differentiate. Mostly user prompts and the like. I've done
 * these MPG programs in C++ and 1305.
 */

import java.util.Scanner;

public class CalculateMileage
{
    public static void main(String[] args)
    {
        //just a simple greeting
        System.out.println("Thank you for starting up the Miles per Gallon");
        System.out.println("calculator. This app is designed to accept a");
        System.out.println("positive whole number for both gallons and miles");
        System.out.println("to achieve your miles per gallon.");
        System.out.println("This application will accept only whole numbers for");
        System.out.println("either gallons purchased or miles.");
        System.out.println("If at any time you would like to exit the program,");
        System.out.println("input -1 into the number of gallons you purchased.");
        System.out.println("This is the signal for the program to end.");
        System.out.println();

        //instantiate a scanner object to read input
        Scanner input = new Scanner(System.in);

        //declare variables to hold user input
        int gallons;
        int miles;
        int totalGallons = 0;
        int totalMiles = 0;

        //get user input
        System.out.println("Time for you to tell me how many gallons of gas you have purchased.");
        System.out.println("Whole numbers please. Remember, -1 to exit.");
        gallons = input.nextInt();

        while(gallons != -1)
        {

            //get gallons used from user
            totalGallons += gallons;

            //get miles driven from user
            System.out.println("Now that we have your gallons, please enter in");
            System.out.println("the number of miles you drove on those gallons of gas.");
            System.out.println("Again, whole numbers please.");
            miles = input.nextInt();
            totalMiles += miles;

            System.out.println("Thank you. Your average miles per gallon will be calculated.");
            //calculate miles per gallon
            float mpg = calculateMileage(gallons, miles);

            //calculate cumulative miles per gallon
            float cumulativeMpg = calculateMileage(totalGallons, totalMiles);

            System.out.println();
            System.out.printf("You have achieved around %.3f miles per gallon! By driving %d miles"
                    + "on %d gallons of gas.", mpg, miles, gallons);

            System.out.println();
            System.out.printf("For all of the MPGs you've been calculating, "
                    + "your overall MPG is %.3f. \n", cumulativeMpg);
            System.out.println();

            //get user input
            System.out.println("Let's check another tank!");
            System.out.println("Time for you to tell me how many gallons of gas you have purchased.");
            System.out.println("Whole numbers please. Remember, -1 to exit.");
            gallons = input.nextInt();
        }

        System.out.println("Thank you for your time. Don't forget to drop by again for more calculations.");
    }

    // This method calculates the miles per gallon.  It takes number of gallons used
    // and number of miles driven as input.  It returns a floating point number
    // that represents the miles driven divided by the gallons used.
    public static float calculateMileage(int gallonsa, int milesa)
    {
        //value to be returned
        float mpg;

        mpg = milesa / gallonsa;

        return mpg;
    }

}