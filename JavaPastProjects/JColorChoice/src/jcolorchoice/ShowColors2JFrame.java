/* 
 * 
 * 
 */

package jcolorchoice;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ShowColors2JFrame extends JFrame
{
    private JButton changeColorJButton;
    private Color color = Color.LIGHT_GRAY;
    private JPanel colorJPanel;
    
    public ShowColors2JFrame()
    {
        super("Using JColorChooser");
        
        colorJPanel = new JPanel();
        colorJPanel.setBackground(color);
        
        changeColorJButton = new JButton("Change Color");
        changeColorJButton.addActionListener(
                new ActionListener()
                {
                    public void actionPerformed(ActionEvent event)
                    { //this is recursive!
                        color = JColorChooser.showDialog(
                                ShowColors2JFrame.this, "Choose a color", color);
                        
                        if (color == null)
                            color = Color.LIGHT_GRAY;
                        
                        colorJPanel.setBackground(color);
                    }
                });
        
        add(colorJPanel, BorderLayout.CENTER);
        add(changeColorJButton, BorderLayout.SOUTH);
        
        setSize(400,100);
        setVisible(true);
    }
}
