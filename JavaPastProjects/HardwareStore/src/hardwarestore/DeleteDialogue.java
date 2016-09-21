package hardwarestore;

/*
	Bank Application
	DeleteDialogue class
	Used to implement the ToolRecord delete feature

*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;


class DeleteDialogue extends JInternalFrame implements ActionListener
{
   private RandomAccessToolFile file;
   private ToolDisplay toolDisplay;

   public DeleteDialogue( RandomAccessToolFile updateFile )
   {
       super( "Delete Tool" );

       file = updateFile;

       // setup GUI
       toolDisplay = new ToolDisplay("Delete");
       toolDisplay.setToolIDNumberOnlyEditable();

       toolDisplay.toolIDField.addActionListener( this );
       toolDisplay.saveButton.addActionListener( this );
       toolDisplay.cancelButton.addActionListener( this );
       Container container = getContentPane();
       container.add(toolDisplay);

       pack();
       setVisible( false );
    }

   public void setVisible(boolean aFlag) // to set focus when made visible
   {
       super.setVisible(aFlag);
       if (aFlag)
       {
            toolDisplay.setToolIDNumberOnlyEditable();
            toolDisplay.toolIDField.requestFocus();
       }
   }

   // process events
   public void actionPerformed( ActionEvent event )
   {
      // text field
        if ( event.getSource() == toolDisplay.toolIDField )
        {
            int recordNumber = toolDisplay.getToolID();

            // check if record number is within range
             if (!isToolIDNumberValid(recordNumber)) 
             {
                 return;
             }
             
             ToolRecord data = new ToolRecord();
             
                // set file-pointer to appropriate location
             try
             {
                 data = file.readRecord( recordNumber );
             }
             catch ( IOException ioException )
             {
                JOptionPane.showMessageDialog( this, "Error while reading from file",
                    "Read Error", JOptionPane.ERROR_MESSAGE );
             }

             // retrieve current record information
             if ( data.getToolID() != 0 )
             {
                toolDisplay.setToolRecord(data);
                toolDisplay.setToolIDNumberOnlyEditable();
                toolDisplay.toolIDField.requestFocus();
             }
             else
             {
                JOptionPane.showMessageDialog( this, "Tool ID number does not exist.",
                         "Update Tool Error", JOptionPane.ERROR_MESSAGE );
                toolDisplay.clear();
                toolDisplay.toolIDField.setText( recordNumber + " does not exist" );
             }
      }
      else if ( event.getSource() == toolDisplay.saveButton )
      { // save button
          int recordNumber = toolDisplay.getToolID();
          // update record information
          try
          {
             ToolRecord data = new ToolRecord();
             data = file.readRecord( ( recordNumber - 1 ) * RandomAccessToolRecord.SIZE );
             if (!isToolIDNumberValid(data.getToolID())) return;
             file.deleteRecord( recordNumber );
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
      else if ( event.getSource() == toolDisplay.cancelButton )
      {
         setVisible( false );
         toolDisplay.clear();
      }

   }  // end method actionPerformed

   private boolean isToolIDNumberValid(int toolIDNumber)
   {
        if ( toolIDNumber < 1 || toolIDNumber > RandomAccessToolFile.MAX_RECORDS )
        {
            JOptionPane.showMessageDialog( this, "Invalid tool ID number",
                     "Tool Error", JOptionPane.ERROR_MESSAGE );
            toolDisplay.clear();
            return false;
        }
        return true;
    }

}
