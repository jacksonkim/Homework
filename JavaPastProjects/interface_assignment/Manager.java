/*manager

Pay checks are printed every 2 weeks. There
  are 52 weeks in a year. The formula to 
  calculate check is =(2*(annualSalary/52))+bonus

- Managers are eligible for an additional 15%
  bonus of their regular pay each pay period    
*/

package interface_assignment;

class Manager implements Employee
{
	private double salesBonus = .15,
		annualSalary;
	private String fname,
		lname;
	
	public Manager()
	{
		fname = "";
		lname = "";
		annualSalary = 0.0;
	};
	
	public Manager(String fn, String ln, double sal)
	{
		fname = fn;
		lname = ln;
		annualSalary = sal;
	};
	
	public double getBonus()
	{
		return salesBonus;
	};
	
	 public String getFirstName()
	 {
	 	return fname;
	 };
	 
    public String getLastName()
	 {
	 	return lname;
	 };
	 
    public double getAnnualSalary()
	 {
		return annualSalary;
	 };
	 
    public void setFirstName(String fn)
	 {
	 	fname = fn;
	 };
	 
    public void setLastName(String ln)
	 {
	 	lname = ln;
	 };
	 
    public void setAnnualSalary(double as)
	 {
	 	annualSalary = as;
	 };

    // calculate pay check amount
    public double calculatePayCheck()
	 {
	 	double payStub = (2*(annualSalary/52)),
			bonus = payStub*salesBonus,
			paycheck = payStub+bonus;
			
		return paycheck;
	 };
    
    // print employee information    and
    // check amount (of this pay period)
    public void printCheck()
	 {
	 	System.out.printf("First Name: %s\n", fname);
		System.out.printf("Last Name: %s\n", lname);
	 	System.out.printf("Paycheck for Manager this week is: $%.2f\n", calculatePayCheck());
	 };

}