package hardwarestore;

/*
	Hardware Store Application
	UpdateDialogue class
	Used to implement the ToolRecord update feature

*/
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.event.*;


class UpdateDialogue extends JInternalFrame implements ActionListener
{
   private RandomAccessToolFile file;
   private ToolDisplay toolDisplay;

   public UpdateDialogue( RandomAccessToolFile updateFile )
   {
       super( "Update Record" );

       file = updateFile;

       // setup GUI
       toolDisplay = new ToolDisplay("Save Updates");
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
            if ( recordNumber < 1 || recordNumber > RandomAccessToolFile.MAX_RECORDS )
            {
                JOptionPane.showMessageDialog( this, "Invalid tool ID number",
                         "Tool Error", JOptionPane.ERROR_MESSAGE );
                toolDisplay.clear();
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
            JOptionPane.showMessageDialog( this,
                "Error while reading from file" + ioException,
                "Read Error", JOptionPane.ERROR_MESSAGE );
         }

         // retrieve current record information
         if ( data.getToolID() != 0 )
         {
            toolDisplay.setToolRecord(data);
         }
         else
         {
            JOptionPane.showMessageDialog( this, "Tool ID number does not exist.",
                     "Update Tool Error", JOptionPane.ERROR_MESSAGE );
            toolDisplay.clear();
            toolDisplay.toolIDField.setText( recordNumber + " does not exist" );
         }
      } // save button
      else if ( event.getSource() == toolDisplay.saveButton )
      {
          int recordNumber = toolDisplay.getToolID();
          // update record information
          try
          {
             file.writeRecord( toolDisplay.getToolRecord() );
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

}
