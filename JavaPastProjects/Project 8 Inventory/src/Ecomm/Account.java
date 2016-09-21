package EComm;

public class Account 
{

	// Declare final class variables
	public final static int cartArrayElements = 100;
	
	// Declare instance variables
	private String name = "";
	private int age = 0;
	private boolean employed = false;
	private boolean full_time = false;
	private String address = "";
	private double limit = 0.0;
	private double total_price = 0.0;
	private int lastIndex = -1;
	
	// Declare instance cart array
	private int cart[] = new int[cartArrayElements];
	
	// Constructor - default
	public Account()
	{
		
	}
	
	// Constructor - String Name Load
	public Account(String accountName)
	{
		
		setName(accountName);
		
	}
	
	public void setName(String accountName)
	{
		name = accountName;
	}
	
	public String getName()
	{
		return name;
	}

	public void setAge(int buyerAge)
	{
		age = buyerAge;
	}
	
	public int getAge()
	{
		return age;
	}

	public void setEmployed(boolean buyerEmployed)
	{
		employed = buyerEmployed;
	}
	
	public boolean getEmployed()
	{
		return employed;
	}

	public void setFull_time(boolean buyerFull_time)
	{
		full_time = buyerFull_time;
	}
	
	public boolean getFull_time()
	{
		return full_time;
	}

	public void setAddress(String buyerAddress)
	{
		address = buyerAddress;
	}
	
	public String getAddress()
	{
		return address;
	}

	public void setLimit(double buyerLimit)
	{
		limit = buyerLimit;
	}
	
	public double getLimit()
	{
		return limit;
	}

	public void setCart(int arrayIndex, int cartValue)
	{
		cart[arrayIndex] = cartValue;
	}
	
	public int getCart(int arrayIndex)
	{
		return cart[arrayIndex];
	}

	// Determine Credit Method
	public double applyForCredit(String accountName, int accountAge, 
			boolean accountEmployed, boolean accountFull_time)
	{

		setName(accountName);
		setAge(accountAge);
		setEmployed(accountEmployed);
		setFull_time(accountFull_time);
		
		return determineCreditLimit();
		
	}
	
	// Determine Credit Method
	private double determineCreditLimit()
	{
		
		if (age >= 18) // Buyer must be 18 to get credit
		{
		
			if (employed & full_time)
			{
				
				setLimit(1000.00);
				return getLimit();
				
			}
			
			if (employed)
			{
				
				setLimit(500.00);
				return getLimit();
				
			}
				
			setLimit(250.00);
			return getLimit();
			
		}
	
		return 0.00;
		
	}
	

	public void AddToCart(int choice)
    {
        switch(choice)
        {
            case 1:if (limit >=total_price)
            {
                total_price +=199.99;
                setCart(++lastIndex, choice);
            }
            else
                System.out.print("You have reached your credit limit");
            case 2:if (limit >=total_price)
            {
            	total_price +=800.00;
                setCart(++lastIndex, choice);
            }
            else
                System.out.print("You have reached your credit limit");
            case 3:if (limit >=total_price)
            {
                total_price +=400.00;
                setCart(++lastIndex, choice);
            }
            else
                System.out.print("You have reached your credit limit");
            case 4:if (limit >= total_price)
            {
                total_price +=350.00;
                setCart(++lastIndex, choice);
            }
            else
                         System.out.print("You have reached your credit limit");
            case 5:if (limit >=total_price)
            {
            	total_price +=24.00;
            	setCart(++lastIndex, choice);
            }
                else
                         System.out.print("You have reached your credit limit");
        }
        
            
    }

	
}
