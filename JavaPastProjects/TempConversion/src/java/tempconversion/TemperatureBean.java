/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tempconversion;

import java.io.Serializable;
import javax.faces.bean.ManagedBean;

@ManagedBean( name="temperatureBean" )
public class TemperatureBean implements Serializable
{
    private double fahrenheit;
    private double celsius;

    // return the double fahrenheit
    public double getFahrenheit()
    {
      return fahrenheit;
    } // end method getFahrenheit

    // set the double fahrenheit
    public void setFahrenheit( double f )
    {
      this.fahrenheit = f;
    } // end method setFahrenheit
    
    //return the double celsius
    public double getCelsius()
    {
      return celsius;
    } // end method getCelsius

    // set the double celsius
    public void setCelsius( double c )
    {
      this.celsius = convertFahrenheitToCelsius();
    } // end method setCelsius
    
    public String getResult()
    {                
      if ( fahrenheit != 0 ) //&& celsius != 0
         return "<p style=\"background-color:#512882;width:200px;" +
            "padding:5px;color: #FFFFFF;\">Fahrenheit: " + getFahrenheit() +
                 "<br/>Celsius: " + getCelsius() + "</p>";
      else
         return ""; // request has not yet been made
    } // end method getResult
    
    public double convertFahrenheitToCelsius()
    {
        double cel = 5/9*(fahrenheit-32);
       return cel;        
    }
}