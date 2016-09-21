/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tempconversion;

import javax.ejb.Remote;

@Remote
public interface TemperatureEJB 
{
    public double convertFahrenheitToCelsius(double f);
}
