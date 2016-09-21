/*
	Bank application
	AccountList class
	implements listing all accounts feature

*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;



class AccountList extends JInternalFrame
{
	private RandomAccessAccountFile file;
	private JButton closeButton;
	private JPanel buttonContainer;
	private JScrollingTextArea scroller;

	public AccountList(RandomAccessAccountFile listFile)
	{
		super("Accounts");

		file = listFile;

		buttonContainer = new JPanel();
		closeButton = new JButton("Close");
		buttonContainer.add(closeButton);

		scroller = new JScrollingTextArea(100,100);
		scroller.setEditable(false);

		closeButton.addActionListener(
			new ActionListener()
			{
				public void actionPerformed( ActionEvent event )
				{
					setVisible( false );
				}
			}
		);

		Container container = getContentPane();
		container.setLayout( new BorderLayout() );
		container.add(scroller,BorderLayout.CENTER);
		container.add(buttonContainer,BorderLayout.SOUTH);

		setSize( 375,275 );
		setVisible(false);
	}

	public void display()
	{
		AccountRecord data = new AccountRecord();
		int i;
		scroller.setText("Account #\tFirst Name\tLast Name\tBalance\n");

		try
		{
			for (i = 1; i <= RandomAccessAccountFile.MAX_RECORDS; i++)
			{
				data = file.readRecord( i );
				if (data.getAccountNumber() > 0)
				{
					scroller.append( data.getAccountNumber() + "\t" +
						data.getFirstName() + "\t" + data.getLastName() + "\t" +
						data.getBalance() + "\n" );
				}
			}
		}
		catch ( IOException e)
		{
			JOptionPane.showMessageDialog(this,
				"Error during read from file ","Read Error",
				JOptionPane.ERROR_MESSAGE);
		}
	}

}
