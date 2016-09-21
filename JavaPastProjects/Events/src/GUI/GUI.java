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

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GUI extends JFrame
{
    JLabel label1 = new JLabel("Enter the current temperature to convert: ");
    JLabel label2;
    JTextField temperature = new JTextField(10);
    
    JButton convert = new JButton("Convert");
    
    JRadioButton farentocel;
    JRadioButton celtokelvin;
    ButtonGroup radiogroup;
    
    private double input;
    private double output;
    
    public GUI()
    {
        super("Temperature Conversion App");
        setLayout(new FlowLayout());
        
        add(label1);
        //textfield
        add(temperature);
        
        HandleInput inhandler = new HandleInput();
        
        //radio buttons
        farentocel = new JRadioButton("Farenheit to Celsius", true);
        celtokelvin = new JRadioButton("Celsius to Kelvin", false);
        add(farentocel);
        add(celtokelvin);
        
        radiogroup = new ButtonGroup();
        radiogroup.add(farentocel);
        radiogroup.add(celtokelvin);
        
        //farentocel.addItemListener(new RadioButtonHandler());
        
        add(convert);
        
        ButtonHandler bhandler = new ButtonHandler();
        
        convert.addActionListener(bhandler);
    }
    
    private class HandleInput implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            String data = event.getActionCommand();
            
            if (!ValidDouble(data))
            {
                JOptionPane.showMessageDialog(null, "Please enter valid integers",
                                              "Input Error!", JOptionPane.ERROR_MESSAGE);
                temperature.setText(null);
            }
            
            if (event.getSource() == temperature)
            {
                data = event.getActionCommand();
                input = Double.parseDouble(data);
            }
        }
    }
    
    private boolean ValidDouble(String num)
    {
        try
        {
            Double.parseDouble(num);
        }
        catch(NumberFormatException e)
        {
            return false;
        }
        
        return true;
    }
    
    private class ButtonHandler implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            //HOW DO?
        }
    }
    
    private class RadioButtonHandler implements ItemListener
    {
        private int temperate;
        private String out;
        
        public RadioButtonHandler()
        {
            if (farentocel.isSelected())
            {
                //temperate = (5/9)(input-32);
                out = Double.toString(temperate);
            }
            else if (celtokelvin.isSelected())
            {
                //temperate = input + 273.15;
                out = Double.toString(temperate);
            }
        }
        
        @Override
        public void itemStateChanged(ItemEvent event)
        {
            label2.setText(out);
        }
    }
}
