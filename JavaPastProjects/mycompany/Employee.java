/* CIST 2372 - 40790 - Kimberly Jackson - SID:0332
	Week 3, Employee Object - 2/1/2013
	
	Description: Object Employee should hold 4 variables of information
		about employees and return information as needed.

*/

class Employee
{
	public String fname,
		lname,
		phone,
		email;
	public static int numOfEmployees = 0;
		
	public Employee()
	{
		fname = "";
		lname = "";
		phone = "";
		email = "";
		numOfEmployees++;
	}
		
	public void setFirstName(String first)
	{
		fname = first;
	}
	
	public void setLastName(String last)
	{
		lname = last;
	}
	
	public void setPhoneNumber(String pNumber)
	{
		phone = pNumber;
	}
	
	public void setEmailAddress(String electro)
	{
		email = electro;
	}
	
	public static int getEmployeeCount()
	{
		return numOfEmployees;
	}
	
	public String[] getEmployeeData()
	{
		String[] employeeinfo = new String[4];
		employeeinfo[0] = fname;
		employeeinfo[1] = lname;
		employeeinfo[2] = phone;
		employeeinfo[3] = email;
		return employeeinfo;
	}
}