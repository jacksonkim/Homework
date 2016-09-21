/*
 * 
 * 
 */
package Classwork;

/**
 *
 * @author Kim
 */
public class Math {
    
    private int num1, num2;
    
    public void setnum1(int n1)
    {
        num1=n1;
    }
    
    public void setnum2(int n2)
    {
        num2=n2;
    }
    
    public int getnum1()
    {
        return num1;
    }
    
    public int getnum2()
    {
        return num2;
    }
    
    public int Average()
    {
        return (num1+num2)/2;
    }
    
}
