/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package bmicalculator;

/**
 *
 * @author Kim
 */
public class BMI extends Calculate
{
    private String gender;
    private int age;
    
    public void setGender(String g)
    {
        gender = g;
    }
    
    public void setAge(int a)
    {
        age = a;
    }
    
    /**
     *
     * @param w
     * @param h
     * @return
     */
    @Override
    public double CalculateBMI(double w, double h)
    {
        bmi = super.CalculateBMI(w, h);
        switch (gender.toLowerCase()) {
            case "male":
                if (age <= 35)
                {
                    bmi = (.02*bmi);
                }
                else
                {
                    bmi = (.05*bmi);
                }
                break;
            case "female":
                if (age <= 35)
                {
                    bmi = (.015*bmi);
                }
                else
                {
                    bmi = (.035*bmi);
                }
                break;
        }
        return bmi;
    }
}
