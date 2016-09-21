/* CIST 2371 - 20790 - Kimberly Jackson - SID: 0332
 * Week 9, Temperature Conversion GUI - 10/25/2012
 *  
 *  Description: Create a temperature conversaion application using GUI
 *      components. JTextField to enter temperature and display the converted
 *      temp in a JLabel. It should allow the user to convert between any two
 *      scales.
 *      
 *      Celsius = (5/9)(farenheit-32)
 *      Kelvin = Celsius + 273.15
 * 
 *      (I assume then, that the user is working with Farenheit.)
 */
package GUI;

/**
 *
 * @author Kim
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Converter 
{
    public static void main(String[] args)
    {
        GUI converter = new GUI();
        converter.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        converter.setSize(500, 120);
        converter.setVisible(true);
    }
}
