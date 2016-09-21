/*
	Bank application
	AccountDisplay class
	Sets up the GUI layout for display and editing
*/

import java.awt.*;
import javax.swing.*;


public class AccountDisplay extends JPanel
{
   private JLabel accountLabel, firstNameLabel, lastNameLabel, balanceLabel;
   private JTextField firstNameField, lastNameField, balanceField;
   protected JTextField accountField;
   protected JButton saveButton, cancelButton;
   private int recordNumber;

	public AccountDisplay()
	{
		this("Save");
	}

	public AccountDisplay(String saveButtonTitle)
	{
       // set up GUI
       accountLabel = new JLabel( "Account Number" );
       accountField= new JTextField( 10 );
       firstNameLabel = new JLabel( "First Name" );
       firstNameField = new JTextField( 10 );
       lastNameLabel = new JLabel( "Last Name" );
       lastNameField = new JTextField( 10 );
       balanceLabel = new JLabel( "Balance" );
       balanceField = new JTextField( 10 );
       balanceField.setEditable( false );

       saveButton = new JButton( saveButtonTitle );
       cancelButton = new JButton( "Cancel" );

       setLayout( new GridLayout( 5, 2 ) );
       add( setupCell( accountLabel ) );
       add( setupCell( accountField ) );
       add( setupCell( firstNameLabel ) );
       add( setupCell( firstNameField ) );
       add( setupCell( lastNameLabel ) );
       add( setupCell( lastNameField ) );
       add( setupCell( balanceLabel ) );
       add( setupCell( balanceField ) );
       add( setupCell( saveButton ) );
       add( setupCell( cancelButton ) );

       clear();

	}

	public void setAllEditable()
	{
       accountField.setEditable( true );
       firstNameField.setEditable( true );
       lastNameField.setEditable( true );
       balanceField.setEditable( true );
	}

	// display set so only account number can be entered
	public void setAccountNumberOnlyEditable()
	{
       accountField.setEditable( true );
       firstNameField.setEditable( false );
       lastNameField.setEditable( false );
       balanceField.setEditable( false );
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
        accountField.setText( "" );
        firstNameField.setText( "" );
        lastNameField.setText( "" );
        balanceField.setText( "" );
	}

	// return the AccountRecord contained in the display
	public AccountRecord getAccountRecord()
	{
		AccountRecord ar;
		Double balance;

		int accountNumber = getAccountNumber();

		if (accountNumber > 0)
		{
			try
			{
				balance = new Double( balanceField.getText() );
			}
			catch(NumberFormatException e)
			{
				balance = 0.0;
			}
			ar = new AccountRecord(accountNumber,
						firstNameField.getText(),
						lastNameField.getText(),
						balance );
		}
		else
		{
			ar = new AccountRecord();
		}
		return ar;
	}

	// return the account number contained in the accountField
	public int getAccountNumber()
	{
		int accountNumber;

		try
		{
			accountNumber = Integer.parseInt( accountField.getText() );
			if (accountNumber < 0) accountNumber = 0;
		}
		catch(NumberFormatException e)
		{
			accountNumber = 0;
		}
		return accountNumber;
	}

	// load display with existing AccountRecord
	public void setAccountRecord(AccountRecord data)
	{
		// put AccountRecord data in all display fields
		accountField.setText( new Integer(data.getAccountNumber()).toString() );
      firstNameField.setText( data.getFirstName().trim() );
      lastNameField.setText( data.getLastName().trim() );
      balanceField.setText( new Double( data.getBalance() ).toString() );

		// set appropriate fields to editable
		// do I want to be able to "clone" an account?
		// if not I should not allow editing of accountField
      accountField.setEditable( false );
		firstNameField.requestFocus();
      firstNameField.setEditable( true );
      lastNameField.setEditable( true );
      balanceField.setEditable( true );
	}
}