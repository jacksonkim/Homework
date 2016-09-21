/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;

/**
 *
 * @author burley
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Events extends JFrame
{
    //controls for window
    JLabel lbl1 = new JLabel("Enter first value");
    JLabel lbl2 = new JLabel("Enter second value");
    JLabel lbl3 = new JLabel("Sum");

    JTextField num1 = new JTextField(10);
    JTextField num2 = new JTextField(10);
    JTextField sum =  new JTextField(10);
    
    //misc variables
    private int val1 = 0;
    private int val2 = 0;
    
    public Events()
    {
        super("Adder");
        setLayout(new FlowLayout());
        setVisible(true);
        
        //add controls to window
        add(lbl1);
        add(num1);

        add(lbl2);
        add(num2);

        add(lbl3);
        add(sum);
        
        //create an event handler
        HandleInput handler = new HandleInput();
        
        //register handler
        num1.addActionListener(handler);
        num2.addActionListener(handler);
        sum.addActionListener(handler);
    }

    //embedded class to handle events
    private class HandleInput implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            String data = event.getActionCommand();
            
            if(!ValidInteger(data))
            {
                JOptionPane.showMessageDialog(null, "Please enter valid integers",
                                              "Input Error!", JOptionPane.ERROR_MESSAGE);
                Reset();
            }
                
            if(event.getSource() == num1)
            {
                data = event.getActionCommand();
                val1 = Integer.parseInt(data);
                ShowSum();
            }
            else if(event.getSource() == num2)
            {
                data = event.getActionCommand();
                val2 = Integer.parseInt(data);
                ShowSum();
            }
            else if(event.getSource() == sum)
            {
                Reset();
            }
        }
    }
    
    private void ShowSum()
    {
        sum.setText(Integer.toString(val1 + val2));
    }
    
    private boolean ValidInteger(String num)
    {
        try
        {
            Integer.parseInt(num);
        }
        catch(NumberFormatException e)
        {
            return false;
        }
        
        return true;
    }
    
    private void Reset()
    {
        num1.setText(null);
        num2.setText(null);
        sum.setText(null);
    }
}