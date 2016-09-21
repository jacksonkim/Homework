/*operator

Pay checks are printed every 2 weeks. There
  are 52 weeks in a year. The formula to 
  calculate check is =(2*(annualSalary/52))+bonus

- Operators are eligible for an additional 5%
  bonus of their regular pay each pay period
*/

package interface_assignment;

class Operator implements Employee
{
	private double salesBonus = .05,
		annualSalary;
	private String fname,
		lname;
	
	public Operator()
	{
		fname = "";
		lname = "";
		annualSalary = 0.0;
	};
	
	public Operator(String fn, String ln, double sal)
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
	 	System.out.printf("Paycheck for Operator this week is: $%.2f\n", calculatePayCheck());
	 };
}