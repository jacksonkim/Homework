/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package jcolorchoice;

import javax.swing.JFrame;

/**
 *
 * @author Kim
 */

public class JColorChoice 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
//        ShowColors2JFrame app = new ShowColors2JFrame();
//        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        if("XYZ".compareTo("abc") > 0)
        { System.out.println("XYZ if greater than abc.");}
        else
        { System.out.println("abc is greater than XYZ");
        
        String s = new String("hello world");
        if (s == "Hello World".toLowerCase())
            System.out.println("True");
        else
            System.out.println("False");
        }
    }
}
