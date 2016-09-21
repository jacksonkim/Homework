package hardwarestore;

/*
	Bank application
	NewDialogue class
	used to implement creating a new toolID record
*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;


class NewDialogue extends JInternalFrame implements ActionListener
{
   private RandomAccessToolFile file;
   private ToolDisplay toolDisplay;

   public NewDialogue( RandomAccessToolFile newFile )
   {
      super( "New Tool Record" );

	  // setup a reference to the random access data file for this class
	  // so we can save the record to the data file
      file = newFile;

      toolDisplay = new ToolDisplay("Save");

      toolDisplay.saveButton.addActionListener( this );
      toolDisplay.cancelButton.addActionListener( this );
      Container container = getContentPane();
      container.add(toolDisplay);

      pack();
      setVisible( false );
   }


   public void setVisible(boolean aFlag) // override setVisible to set focus when made visible
   {
       super.setVisible(aFlag);
       if (aFlag)
       {
            toolDisplay.setAllEditable();
            toolDisplay.toolIDField.requestFocus();
       }
   }

   // process events
   public void actionPerformed( ActionEvent event )
   {
      // save button
      if ( event.getSource() == toolDisplay.saveButton )
      {

         int recordNumber = toolDisplay.getToolID();

         // check if record number is within range
         if ( recordNumber < 1 || recordNumber > RandomAccessToolFile.MAX_RECORDS )
         {
            JOptionPane.showMessageDialog( this, String.format("Invalid toolID number\nMust be 1 - %d",RandomAccessToolFile.MAX_RECORDS),
               "Tool Error", JOptionPane.ERROR_MESSAGE );
            toolDisplay.clear();
            return;
         }

         ToolRecord data = new ToolRecord();
         // set file-pointer to appropriate location
         try
         {
             data = file.readRecord( toolDisplay.getToolRecord().getToolID() );
         }

         catch ( IOException ioException )
         {
            JOptionPane.showMessageDialog( this,
               "Error while reading from file",
               "Read Error", JOptionPane.ERROR_MESSAGE );
         }

         // record number already exists
         if ( data.getToolID() != 0 )
         {
            JOptionPane.showMessageDialog( this,
               "Tool ID number already exists",
               "Duplicate tool number", JOptionPane.ERROR_MESSAGE );
            toolDisplay.clear();
            return;
         }

         // set values of new record and write to file
         try
         {
             file.writeRecord( toolDisplay.getToolRecord());
         }

         catch ( IOException ioException )
         {
            JOptionPane.showMessageDialog( this,
               "Error while writing to file",
               "Write Error", JOptionPane.ERROR_MESSAGE );
            return;
         }

         setVisible( false );
         toolDisplay.clear();
      }

      // cancel button
      else if ( event.getSource() == toolDisplay.cancelButton )
      {
         setVisible( false );
         toolDisplay.clear();
      }

   }  // end method actionPerformed


}  // end class NewDialogue
