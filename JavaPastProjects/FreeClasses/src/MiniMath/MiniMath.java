package MiniMath;

/* CIST 2731 - 20790 - Kimberly Jackson - SID: 0332
 * 
 * Week 3, Assignment, MiniMath class
 * 
 * Description: Create a public class called MiniMath. The class should contain 
 * four overloaded methods called Add. A single method must be defined for each
 * of the following:

* integer - ints. what more can i say
* float - return to 1 decimal place
* double - return to 2 decimal places
* String - add a space between the strings before returning the result

* Each method must be static, should take 2 arguments, and the return type 
* must be the same as the argument type
    
    * public static int Add(int value1, int value2)

* Create a driver program that calls each method in your MiniMath class and 
* prints the result.  Input can be determined at the time of development and 
* need not be retrieved from the user
* 
*/

public class MiniMath {
    
    public static int Add(int in1, int in2)
    {
        return in1+in2;
    }
    
    public static float Add(float inf1, float inf2)
    {
        float total = inf1+inf2;
               
        return total;
    }
    
    public static double Add(double indub1, double indub2)
    {
        double total = indub1+indub2;
        
        return total;
    }
    
    public static String Add(String inst1, String inst2)
    {
        
        return inst1+" "+inst2;
    }
    
}
