class CodeTest{
    public static void main(String[] args){
        Employee employee1 = new Employee();
        employee1.setFirstName("Tim");
        employee1.setLastName("Jones");
        employee1.setPhoneNumber("404-321-1234");
        employee1.setEmailAddress("tj@mc.com");

        Employee employee2 = new Employee();
        employee2.setFirstName("Kimberly");
        employee2.setLastName("Smith");
        employee2.setPhoneNumber("404-322-1234");
        employee2.setEmailAddress("ks@mc.com");

        Employee employee3 = new Employee();
        employee3.setFirstName("Ron");
        employee3.setLastName("Patel");
        employee3.setPhoneNumber("404-323-1234");
        employee3.setEmailAddress("tj@mc.com");

        System.out.println("Number of employee(s) created is: " + Employee.getEmployeeCount() );

        String [] employeeData = employee2.getEmployeeData();

        for(int i = 0; i < employeeData.length; i++){
            System.out.println( employeeData[i] );
        }
	}
}