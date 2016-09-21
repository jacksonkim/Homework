/* CIST2373 - 20411 - Kimberly Jackson - SID: 0332
 * Week 1, Hardware Store MDI GUI - 8/19/13
 * 
 * Description: Create an MDI GUI that tracks the inventory of a hardware store.
 * Inventory information will be held in an external direct-access binary file.
 * The name of the file is hardware.dat
 * 
 * Not gonna lie, I had to use the Bank sample and repurpose it because we only
 * got to like Chapter 18 in the book for Java 2. Which is the one on Recursion.
 * And we didn't even use that in the final.
 * 
 */
package hardwarestore;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;

public class HardwareStore extends ExitableJFrame
{
    private RandomAccessToolFile file;
    private JMenuItem newItem, updateItem, deleteItem, listItem, exitItem;
    private NewDialogue newDialog;
    private UpdateDialogue updateDialog;
    private DeleteDialogue deleteDialog;
    private ToolList toolList;
    private JDesktopPane desktop;
    
    public HardwareStore()
    {
        super("HardwareStore");

	try
        {
            File f = new File("hardware.dat");

            // check if data file exists - if it does not create it and initialize the records
            if (!f.exists())
            {
                file = new RandomAccessToolFile( );  // open new file
                file.initializeRecords( );              // initialize records
            }
            else
            {
                file = new RandomAccessToolFile( );  // open existing file
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
        updateDialog = new UpdateDialogue(file);
        newDialog = new NewDialogue(file);
        deleteDialog = new DeleteDialogue(file);
        toolList = new ToolList(file);

        // add the dialogs to the desktop
        desktop.add(newDialog);
        desktop.add(updateDialog);
        desktop.add(deleteDialog);
        desktop.add(toolList);



        // add menu items to the menu and setup the ActionListener to launch the appropriate dialog
        newItem = new JMenuItem("New Tool");
        newItem.addActionListener( new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    newDialog.setVisible(true);
                }
            } );

        updateItem = new JMenuItem("Update Tool");
        updateItem.addActionListener( new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    updateDialog.setVisible(true);
                }
            } );

        deleteItem = new JMenuItem("Delete Tool");
        deleteItem.addActionListener( new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    deleteDialog.setVisible(true);
                }
            } );

        listItem = new JMenuItem("Show Tools");
        listItem.addActionListener( new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    toolList.setVisible(true);
                    toolList.display();
                }
            } );

        exitItem = new JMenuItem("Exit");
        exitItem.addActionListener( new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    dispose();
                }
            } );

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
        new HardwareStore();
    }
}
