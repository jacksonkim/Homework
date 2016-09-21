/*
	Bank.java
	Simulate a bank
	Builds and manipulates random access accounts file
*/

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;

public class Bank extends ExitableJFrame
{
	private RandomAccessAccountFile file;
	private JMenuItem newItem, updateItem, deleteItem, listItem, exitItem;
	private NewDialog newDialog;
	private UpdateDialog updateDialog;
	private DeleteDialog deleteDialog;
	private AccountList accountList;
	private JDesktopPane desktop;

	public Bank()  // constructor sets up the main window, main menu and dialogs
	{
            super("Bank");

            try
            {
                    File f = new File("Accounts.dat");

                    // check if data file exists - if it does not create it and initialize the records
                    if (!f.exists())
                    {
                            file = new RandomAccessAccountFile( );  // open new file
                            file.initializeRecords( );              // initialize records

                    }
                    else
                    {
                            file = new RandomAccessAccountFile( );  // open existing file
                    }
            }
            catch( IOException ioException )
            {
                    System.err.println( ioException.toString() );
                    // if we could not open or create the data file bail out - can't do anything without the file
                    System.exit(1);
            }

            // create a menu bar for the main JFrame and set it in the frame
            JMenuBar menuBar = new JMenuBar();
            setJMenuBar(menuBar);

            // create a File menu and add it to the menuBar
            JMenu fileMenu = new JMenu("File");
            menuBar.add(fileMenu);

            // setup the main JFrame content pane with a desktop to display the JInternalFrame dialogs
            Container container = getContentPane();
            desktop = new JDesktopPane();
            container.add(desktop);

            // create dialogs for the various program functions
            updateDialog = new UpdateDialog(file);
            newDialog = new NewDialog(file);
            deleteDialog = new DeleteDialog(file);
            accountList = new AccountList(file);

            // add the dialogs to the desktop
            desktop.add(newDialog);
            desktop.add(updateDialog);
            desktop.add(deleteDialog);
            desktop.add(accountList);



            // add menu items to the menu and setup the ActionListener to launch the appropriate dialog
            newItem = new JMenuItem("New Record");
            newItem.addActionListener(
                    new ActionListener()
                    {
                            public void actionPerformed( ActionEvent event )
                            {
                                    newDialog.setVisible(true);
                            }
                    }
            );

            updateItem = new JMenuItem("Update Record");
            updateItem.addActionListener(
                    new ActionListener()
                    {
                            public void actionPerformed( ActionEvent event )
                            {
                                    updateDialog.setVisible(true);
                            }
                    }
            );

            deleteItem = new JMenuItem("Delete Record");
            deleteItem.addActionListener(
                    new ActionListener()
                    {
                            public void actionPerformed( ActionEvent event )
                            {
                                    deleteDialog.setVisible(true);
                            }
                    }
            );

            listItem = new JMenuItem("Show Accounts");
            listItem.addActionListener(
                    new ActionListener()
                    {
                            public void actionPerformed( ActionEvent event )
                            {
                                    accountList.setVisible(true);
                                    accountList.display();

                            }
                    }
            );

            exitItem = new JMenuItem("Exit");
            exitItem.addActionListener(
                    new ActionListener()
                    {
                            public void actionPerformed( ActionEvent event )
                            {
                                    dispose();
                            }
                    }
            );



            fileMenu.add(newItem);
            fileMenu.add(updateItem);
            fileMenu.add(deleteItem);
            fileMenu.add(listItem);
            fileMenu.add(exitItem);


            setSize( 470, 330 );
            setVisible(true);
	}


	public static void main(String[] args)
	{
		new Bank();
	}
}
