/* CIST 2371 - 20790 - Kimberly Jackson - SID: 0332
 *  Week 7, BMI Calculator - 10/6/2012
 * 
 *  Description: Inheritance exercise. Create a class Calculate
 *      that is the parents to a class BMI that have the same
 *      method CalculateBMI. Except in the BMI class, adjust the
 *      BMI based on gender and age.
 */
package bmicalculator;

/**
 *
 * @author Kim
 */

import java.util.Scanner;
        
public class BMICalculator 
{    
    
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        BMI calculate = new BMI();
        
        String gender;
        int age, again;
        double weight, height;
        
        do
        {
            System.out.println("Is it really time to check your BMI?");
            System.out.println("According to Penn & Teller, BMI is... false.");
            System.out.println("Anywho, not important. What is important is your stats.");
            System.out.print("Let's start with gender. Male or Female: ");
            gender = input.next();        
            calculate.setGender(gender);

            System.out.print("Next, what is your current age: ");
            age = input.nextInt();
            calculate.setAge(age);

            System.out.print("Your current height in inches: ");
            height = input.nextDouble();
            calculate.setHeight(height);

            System.out.print("And finally, the hard part - your current weight in pounds: ");
            weight = input.nextDouble();
            calculate.setWeight(weight);

            System.out.printf("With all those numbers, it looks like your current BMI is %.1f.", calculate.CalculateBMI(weight, height));

            System.out.println("\nWould you like to calculate another BMI?");
            System.out.print("Please enter in -1 to quit: ");
            again = input.nextInt();
        
        } while (again != -1);
        
                
    }
}
