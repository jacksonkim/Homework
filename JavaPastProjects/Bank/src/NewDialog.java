/*
	Bank application
	NewDialog class
	used to implement creating a new account record
*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;


class NewDialog extends JInternalFrame implements ActionListener
{
   private RandomAccessAccountFile file;
   private AccountDisplay accountDisplay;

   public NewDialog( RandomAccessAccountFile newFile )
   {
      super( "New Record" );

	  // setup a reference to the random access data file for this class
	  // so we can save the record to the data file
      file = newFile;

      accountDisplay = new AccountDisplay("Save");

      accountDisplay.saveButton.addActionListener( this );
      accountDisplay.cancelButton.addActionListener( this );
      Container container = getContentPane();
      container.add(accountDisplay);

      pack();
      setVisible( false );
   }


   public void setVisible(boolean aFlag) // override setVisible to set focus when made visible
   {
	   super.setVisible(aFlag);
	   if (aFlag)
	   {
			accountDisplay.setAllEditable();
			accountDisplay.accountField.requestFocus();
		}
   }

   // process events
   public void actionPerformed( ActionEvent event )
   {
      // save button
      if ( event.getSource() == accountDisplay.saveButton )
      {

         int recordNumber = accountDisplay.getAccountNumber();

         // check if record number is within range
         if ( recordNumber < 1 || recordNumber > RandomAccessAccountFile.MAX_RECORDS )
         {
            JOptionPane.showMessageDialog( this, String.format("Invalid account number\nMust be 1 - %d",RandomAccessAccountFile.MAX_RECORDS),
               "Account Error", JOptionPane.ERROR_MESSAGE );
            accountDisplay.clear();
            return;
         }

         AccountRecord data = new AccountRecord();
         // set file-pointer to appropriate location
         try
         {
			 data = file.readRecord( accountDisplay.getAccountRecord().getAccountNumber() );
         }

         catch ( IOException ioException )
         {
            JOptionPane.showMessageDialog( this,
               "Error while reading from file",
               "Read Error", JOptionPane.ERROR_MESSAGE );
         }

         // record number already exists
         if ( data.getAccountNumber() != 0 )
         {
            JOptionPane.showMessageDialog( this,
               "Account number already exists",
               "Duplicate record number", JOptionPane.ERROR_MESSAGE );
            accountDisplay.clear();
            return;
         }

         // set values of new record and write to file
         try
         {
			 file.writeRecord( accountDisplay.getAccountRecord());
         }

         catch ( IOException ioException )
         {
            JOptionPane.showMessageDialog( this,
               "Error while writing to file",
               "Write Error", JOptionPane.ERROR_MESSAGE );
            return;
         }

         setVisible( false );
         accountDisplay.clear();
      }

      // cancel button
      else if ( event.getSource() == accountDisplay.cancelButton )
      {
         setVisible( false );
         accountDisplay.clear();
      }

   }  // end method actionPerformed


}  // end class NewDialog
