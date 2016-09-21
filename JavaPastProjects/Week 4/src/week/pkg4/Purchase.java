/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package week.pkg4;

/**
 *
 * @author Kim
 */
public class Purchase {
    
    private double Milk,
            Eggs,
            Butter,
            Bread;
    
    public Purchase()
    {
        Milk = 3.99;
        Eggs = 1.09;
        Butter = .99;
        Bread = 1.50;
    }
    
    public void setMilk(double m)
    {
        Milk = m;
    }
    
    public void setEggs(double e)
    {
        Eggs = e;
    }
    
    public void setButter(double bu)
    {
        Butter = bu;
    }
    
    public void setBread(double br)
    {
        Bread = br;
    }
    
    public double getMilk()
    {
        return Milk;
    }
    
    public double getEggs()
    {
        return Eggs;
    }
    
    public double getButter()
    {
        return Butter;
    }
    
    public double getBread()
    {
        return Bread;
    }
    
    
}
