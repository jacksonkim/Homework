/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package inheritance;

/**
 *
 * @author Kim
 */
public class Child extends Jackson
{
    private String fname;
    
    Child(String fn)
    {
        fname = fn;
    }
    
    /**
     *
     */
    @Override
    public void Registered()
    {
        System.out.println("I have gotten registered.");
    }
}
