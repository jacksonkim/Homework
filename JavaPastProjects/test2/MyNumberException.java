public class MyNumberException extends Exception
{
	String errormessage = "These do not take numerical data.";
	
	public String getMessage()
	{	
		return errormessage;
	}
}