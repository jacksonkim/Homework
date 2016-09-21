/* CIST 2371 - 20790 - Kimberly Jackson - SID 0332
 *  Week 8, Calculator Interface assignment - 10/17/12
 * 
 *  Description: Create interface ISum with 2 methods: one method should take
 *      two ints as arguments and return their sum; other method should take
 *      two strings as arguments and return their concatenation(this method
 *      should be an overload).
 *      Create interface IAverage with one method that takes two int arguments
 *      and returns the average.
 *      Create a class named Calculator that implements both ISum and IAverage.
 *      This class must implement exception handling.
 */

package calculator;

/**
 *
 * @author Kim
 */
public class Main extends Calculator
{
    public static void main(String[] args) 
    {
        try
        {
            Calculator calc = new Calculator();
            
            int num1=3, num2=20;
            String str1="Java", str2="maybe";           
            
            System.out.printf("The sum of the two hardcoded "
                    + "numbers is %d", calc.Sum(num1, num2));
            System.out.printf("\nThe sum of those numbers averaged"
                    + " is %d", calc.Average(num1, num2));
            System.out.printf("\nAnd I just met you, and this is crazy, \n"
                    + "but I got this language, and it's %s", calc.Sum(str1, str2));
            System.out.println();
        }
        catch (Exception e)
        {
            System.out.println("It looks like that was coded wrong.");
        }
    }
}
