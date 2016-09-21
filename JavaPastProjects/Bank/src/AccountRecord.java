/*
	Bank application
	AccountRecord class
	implements a bank account record
*/



import java.io.Serializable;

public class AccountRecord implements Serializable
{
	// bank account data
   private int account;
   private String firstName;
   private String lastName;
   private double balance;

   // no-argument constructor calls other constructor with default values
   public AccountRecord()
   {
      this( 0, "", "", 0.0 );
   }

   // initialize a record
   public AccountRecord( int acct, String first, String last, double bal )
   {
      setAccountNumber( acct );
      setFirstName( first );
      setLastName( last );
      setBalance( bal );
   }

   // set account number
   public void setAccountNumber( int acct )
   {
      if (acct >= 0) account = acct;
   }

   // get account number
   public int getAccountNumber()
   {
      return account;
   }

   // set first name
   public void setFirstName( String first )
   {
      firstName = first;
   }

   // get first name
   public String getFirstName()
   {
      return firstName;
   }

   // set last name
   public void setLastName( String last )
   {
      lastName = last;
   }

   // get last name
   public String getLastName()
   {
      return lastName;
   }

	// deposit money in account
	public boolean deposit( double d )
	{
		boolean success = true;

		if (d >= 0.0)
		{
			balance += d;
			success = true;
		}
		else
		{
			success = false;
		}
		return success;
	}

	// withdraw money from account
	public boolean withdraw( double w )
	{
		boolean success = true;

		if (balance - w >= 0.0)
		{
			balance -= w;
			success = true;
		}
		else
		{
			success = false;
		}
		return success;
	}

   // set balance  -
   // should not be used except by constructor to set initial balance for new account
   protected void setBalance( double bal )
   {
      if (bal >= 0.0) balance = bal;
   }

   // get balance
   public double getBalance()
   {
      return balance;
   }

   public String toString()
   {
		return String.format("Account: %d %s %s $%.2f", getAccountNumber(), getFirstName(), getLastName(), getBalance());
   }

} // end class AccountRecord

