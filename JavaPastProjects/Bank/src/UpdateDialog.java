/*
	Bank Application
	UpdateDialog class
	Used to implement the AccountRecord update feature

*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;


class UpdateDialog extends JInternalFrame implements ActionListener
{
   private RandomAccessAccountFile file;
   private AccountDisplay accountDisplay;

   public UpdateDialog( RandomAccessAccountFile updateFile )
   {
       super( "Update Record" );

       file = updateFile;

       // setup GUI
       accountDisplay = new AccountDisplay("Save Updates");
       accountDisplay.setAccountNumberOnlyEditable();

       accountDisplay.accountField.addActionListener( this );
       accountDisplay.saveButton.addActionListener( this );
       accountDisplay.cancelButton.addActionListener( this );
       Container container = getContentPane();
       container.add(accountDisplay);

       pack();
       setVisible( false );
	}

   public void setVisible(boolean aFlag) // to set focus when made visible
   {
  	   super.setVisible(aFlag);
   	   if (aFlag)
   	   {
				accountDisplay.setAccountNumberOnlyEditable();
				accountDisplay.accountField.requestFocus();
			}
   }

   // process events
   public void actionPerformed( ActionEvent event )
   {
      // text field
		if ( event.getSource() == accountDisplay.accountField )
      {
        	int recordNumber = accountDisplay.getAccountNumber();

            // check if record number is within range
         if ( recordNumber < 1 || recordNumber > RandomAccessAccountFile.MAX_RECORDS )
         {
            JOptionPane.showMessageDialog( this, "Invalid account number",
                     "Account Error", JOptionPane.ERROR_MESSAGE );
            accountDisplay.clear();
            return;
         }

			AccountRecord data = new AccountRecord();
            // set file-pointer to appropriate location
         try
         {
			 data = file.readRecord( recordNumber );
         }

         catch ( IOException ioException )
         {
            JOptionPane.showMessageDialog( this,
                "Error while reading from file",
                "Read Error", JOptionPane.ERROR_MESSAGE );
         }

         // retrieve current record information
         if ( data.getAccountNumber() != 0 )
         {
				accountDisplay.setAccountRecord(data);
         }
         else
         {
            JOptionPane.showMessageDialog( this, "Account number does not exist.",
                     "Update Account Error", JOptionPane.ERROR_MESSAGE );
            accountDisplay.clear();
            accountDisplay.accountField.setText( recordNumber + " does not exist" );
         }
      }

      // save button
      else if ( event.getSource() == accountDisplay.saveButton )
      {
		 	 int recordNumber = accountDisplay.getAccountNumber();
          // update record information
          try
          {
			 file.writeRecord( accountDisplay.getAccountRecord() );
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
      else if ( event.getSource() == accountDisplay.cancelButton )
      {
         setVisible( false );
         accountDisplay.clear();
      }

   }  // end method actionPerformed

}
