/* CIST2373 - 20411 - Kimberly Jackson - SID:0332
    Web Components Validation - 10/6/13
    Description: Edit the Web Components project to validate
    like the Validation project.
 */

package webcomponents;

import java.io.Serializable;
import javax.faces.bean.ManagedBean;

@ManagedBean( name="webComponentsBean" )
public class WebComponentsBean implements Serializable
{
    private String firstName;
    private String lastName;
    private String email;
    private String phone;
    private String book;
    private String operatingSystem;

    // return the name String
    public String getFirstName()
    {
      return firstName;
    } // end method getName

    // set the name String
    public void setFirstName( String fname )
    {
      this.firstName = fname;
    } // end method setName
    
    public String getLastName()
    {
      return lastName;
    } // end method getName

    // set the name String
    public void setLastName( String lname )
    {
      this.lastName = lname;
    } // end method setName

    // return the email String
    public String getEmail()
    {
      return email;
    } // end method getEmail

    // set the email String
    public void setEmail( String email )
    {
      this.email = email;
    } // end method setEmail

    // return the phone String
    public String getPhone()
    {
      return phone;
    } // end method getPhone

    // set the phone String
    public void setPhone( String phone )
    {
      this.phone = phone;
    } // end method setPhone

    // returns result for rendering on the client
    
    public String getBook()
    {
      return book;
    } // end method getBook

    // set the email String
    public void setBook( String book )
    {
      this.book = book;
    } // end method setBook
    
    public String getOperatingSystem()
    {
      return operatingSystem;
    } // end method getBook

    // set the email String
    public void setOperatingSystem( String operatingSystem )
    {
      this.operatingSystem = operatingSystem;
    } // end method setBook
    
    public String getResult()
    {
      if ( firstName != null && email != null && phone != null )
         return "<p style=\"background-color:#512882;width:200px;" +
            "padding:5px;color: #FFFFFF;\">Name: " + getFirstName() + 
                 " " + getLastName() + "<br/>E-Mail: " +
            getEmail() + "<br/>Phone: " + getPhone() +
                 "<br/>Book: " + getBook() + 
                 "<br/>Operating System: " + getOperatingSystem() + "</p>";
      else
         return ""; // request has not yet been made
    } // end method getResult
}
