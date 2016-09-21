package filestreams;

class Customer
{
	private String lastName, firstName, emailAddress;
	
	public Customer()
	{
		lastName = "Doe";
		firstName = "John";
		emailAddress = "jdoe@gmail.com";
	}
	
	public Customer(String lname, String fname, String email)
	{
		lastName = lname;
		firstName = fname;
		emailAddress = email;
	}
	
	public void setLastName(String lname)
	{
		lastName = lname;
	}
	
	public void setFirstName(String fname)
	{
		firstName = fname;
	}
	
	public void setEmailAddress(String email)
	{
		emailAddress = email;
	}
	
	public String getLastName()
	{
		return lastName;
	}
	
	public String getFirstName()
	{
		return firstName;
	}
	
	public String getEmailAddress()
	{
		return emailAddress;
	}
	
}