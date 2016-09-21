public class MyNumberException extends Exception
{	
	public String errorMessage = "Error dwells here.";
	
	public MyNumberException(boolean matches)
	{	
		if(matches == false)
		{
			errorMessage = "You did not enter a string.";
		}
		else
		{
			errorMessage = "You did not enter an integer.";
		}
		
	}
	
	public String getMessage()
	{
		return errorMessage;
	}
	
}