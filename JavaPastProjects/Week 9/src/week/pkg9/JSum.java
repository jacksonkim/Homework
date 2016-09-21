/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package week.pkg9;

/**
 *
 * @author Kim
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JSum extends JFrame
{
    private JTextField input1 = new JTextField(10);
    private JLabel labeli1 = new JLabel("Adding ");
    private JTextField input2 = new JTextField(10);
    private JLabel labeli2 = new JLabel(" + ");
    private JTextField output = new JTextField(15);
    private JLabel labelo3 = new JLabel(" = ");
    
    public JSum()
    {
        super("Add things together Woo");
        setLayout(new FlowLayout());
        setvisible(true);        
               
        add(labeli1);
        add(input1);
        add(labeli2);
        add(input2);
        add(labelo3);
        add(output);
        
        HandleInput handler = new HandleInput();
        
        input1.addActionListener(handler);
        input2.addActionListener(handler);
        output.addActionListener(handler);
        
    }
    public class HandleInput implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            if (event.getSource() == input1)
            {
                
            };
        }
        
    }
}
