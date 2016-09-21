/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package bmicalculator;

/**
 *
 * @author Kim
 */
public class Calculate 
{
    public double weight, height, bmi;
    
    public void setWeight(double w)
    {
        weight = w;
    }
    
    public void setHeight(double h)
    {
        height = h;
    }
    
    public double CalculateBMI(double w, double h)
    {
       bmi = (w * 703)/h;
       return bmi;
    }
    
    
}
