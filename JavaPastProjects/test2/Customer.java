public class Customer
{
	private String firstName, lastName, emailAddress;
	
	public Customer(String fn, String ln, String email)
	{
		firstName = fn;
		lastName = ln;
		emailAddress = email;
	}
	
	public String getFirstName()
	{
		return firstName;
	}
	
	public String getLastName()
	{
		return lastName;
	}
	
	public String getEmailAddress()
	{
		return emailAddress;
	}
}