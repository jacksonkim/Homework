
package calculator;

/**
 *
 * @author Kim
 */
public class Calculator implements ISum, IAverage
{
   @Override
   public int Sum(int num1, int num2)
   {
       return num1+num2;
   }
   
   @Override
   public String Sum(String str1, String str2)
   {
       return str1+" "+str2;
   }
   
   @Override
   public int Average(int num1, int num2)
   {
       return (num1+num2)/2;
   }
}
