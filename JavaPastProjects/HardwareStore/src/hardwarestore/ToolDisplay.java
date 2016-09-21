package hardwarestore;

/*
	HardwareStore application
	ToolDisplay class
	Sets up the GUI layout for display and editing
*/

import java.awt.*;
import javax.swing.*;


public class ToolDisplay extends JPanel
{
   private JLabel toolIDLabel, toolNameLabel, quantityLabel, unitCostLabel;
   private JTextField toolNameField, quantityField, unitCostField;
   protected JTextField toolIDField;
   protected JButton saveButton, cancelButton;
   private int recordNumber;

    public ToolDisplay()
    {
        this("Save");
    }

    public ToolDisplay(String saveButtonTitle)
    {
        // set up GUI
        toolIDLabel = new JLabel( "Tool ID Number" );
        toolIDField= new JTextField( 10 );
        toolNameLabel = new JLabel( "Tool Name" );
        toolNameField = new JTextField( 10 );
        quantityLabel = new JLabel( "Quantity" );
        quantityField = new JTextField( 10 );
        unitCostLabel = new JLabel( "Unit Cost" );
        unitCostField = new JTextField( 10 );
        unitCostField.setEditable( false );

        saveButton = new JButton( saveButtonTitle );
        cancelButton = new JButton( "Cancel" );

        setLayout( new GridLayout( 5, 2 ) );
        add( setupCell( toolIDLabel ) );
        add( setupCell( toolIDField ) );
        add( setupCell( toolNameLabel ) );
        add( setupCell( toolNameField ) );
        add( setupCell( quantityLabel ) );
        add( setupCell( quantityField ) );
        add( setupCell( unitCostLabel ) );
        add( setupCell( unitCostField ) );
        add( setupCell( saveButton ) );
        add( setupCell( cancelButton ) );

        clear();

    }

    public void setAllEditable()
    {
        toolIDField.setEditable( true );
        toolNameField.setEditable( true );
        quantityField.setEditable( true );
        unitCostField.setEditable( true );
    }

    // display set so only tool number can be entered
    public void setToolIDNumberOnlyEditable()
    {
        toolIDField.setEditable( true );
        toolNameField.setEditable( false );
        quantityField.setEditable( false );
        unitCostField.setEditable( false );
    }

    // all components are set in JPanels, right alignment, for each cell
    public JPanel setupCell(JComponent component)
    {
       JPanel container = new JPanel();
       container.setLayout( new FlowLayout() );
       ( (FlowLayout) container.getLayout() ).setAlignment(FlowLayout.RIGHT);
       container.add( component );
       return container;
    }

    // clear all text areas
    public void clear()
    {
        toolIDField.setText( "" );
        toolNameField.setText( "" );
        quantityField.setText( "" );
        unitCostField.setText( "" );
    }

    // return the ToolRecord contained in the display
    public ToolRecord getToolRecord()
    {
        ToolRecord tr;
        int quantity = getToolQuantity();
        double unitCost;

        int toolID = getToolID();

        if (toolID > 0)
        {
            try
            {
                unitCost = new Double( unitCostField.getText() );
            }
            catch(NumberFormatException e)
            {
                unitCost = 0.0;
            }
            tr = new ToolRecord(toolID, toolNameField.getText(), 
                    quantity, unitCost );
        }
        else
        {
            tr = new ToolRecord();
        }
        return tr;
    }

    // return the tool number contained in the toolIDField
    public int getToolID()
    {
        int toolID;

        try
        {
            toolID = Integer.parseInt( toolIDField.getText() );
            if (toolID < 0) 
                toolID = 0;
        }
        catch(NumberFormatException e)
        {
            toolID = 0;
        }
        return toolID;
    }
    
    public int getToolQuantity()
    {
        int quantity;

        try
        {
            quantity = Integer.parseInt( quantityField.getText() );
            if (quantity < 0) 
                quantity = 0;
        }
        catch(NumberFormatException e)
        {
            quantity = 0;
        }
        return quantity;
    }

    // load display with existing ToolRecord
    public void setToolRecord(ToolRecord data)
    {
        // put ToolRecord data in all display fields
        toolIDField.setText( new Integer(data.getToolID()).toString() );
        toolNameField.setText( data.getToolName().trim() );
        quantityField.setText( new Integer(data.getToolQuantity()).toString() );
        unitCostField.setText( new Double(data.getToolUnitCost()).toString() );

        // set appropriate fields to editable
        // do I want to be able to "clone" an tool?
        // if not I should not allow editing of toolIDField
        toolIDField.setEditable( false );
        toolNameField.requestFocus();
        toolNameField.setEditable( true );
        quantityField.setEditable( true );
        unitCostField.setEditable( true );
    }
}