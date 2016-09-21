package interface_assignment;

interface Employee
{
    String getFirstName();
    String getLastName();
    double getAnnualSalary();
    void setFirstName(String fn);
    void setLastName(String ln);
    void setAnnualSalary(double as);

    // calculate pay check amount
    double calculatePayCheck();
    
    // print employee information    and
    // check amount (of this pay period)
    void printCheck();
}