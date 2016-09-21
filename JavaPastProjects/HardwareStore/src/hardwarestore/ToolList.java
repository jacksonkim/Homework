package hardwarestore;

/*
	Bank application
	ToolList class
	implements listing all toolIDs feature

*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;



class ToolList extends JInternalFrame
{
	private RandomAccessToolFile file;
	private JButton closeButton;
	private JPanel buttonContainer;
	private JScrollingTextArea scroller;

	public ToolList(RandomAccessToolFile listFile)
	{
            super("Tools");

            file = listFile;

            buttonContainer = new JPanel();
            closeButton = new JButton("Close");
            buttonContainer.add(closeButton);

            scroller = new JScrollingTextArea(100,100);
            scroller.setEditable(false);

            closeButton.addActionListener( new ActionListener()
                {
                    public void actionPerformed( ActionEvent event )
                    {
                        setVisible( false );
                    }
                });

            Container container = getContentPane();
            container.setLayout( new BorderLayout() );
            container.add(scroller,BorderLayout.CENTER);
            container.add(buttonContainer,BorderLayout.SOUTH);

            setSize( 375,275 );
            setVisible(false);
	}

	public void display()
	{
            ToolRecord data = new ToolRecord();
            int i;
            scroller.setText("Tool ID #\tTool Name\t  Quantity\tUnit Cost\n");

            try
            {
                for (i = 1; i <= RandomAccessToolFile.MAX_RECORDS; i++)
                {
                    data = file.readRecord( i );
                    if (data.getToolID() > 0)
                    {
                        scroller.append( data.getToolID() + "\t" +
                        data.getToolName() + "\t" + data.getToolQuantity() + "\t" +
                        data.getToolUnitCost() + "\n" );
                    }
                }
            }
            catch (IOException e)
            {
                JOptionPane.showMessageDialog(this, "Error during read from file\n" + e,"Read Error",
                JOptionPane.ERROR_MESSAGE);
            }
	}

}
