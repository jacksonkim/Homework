
package membership;

import java.io.Serializable;    //allow class to be serialzied
import java.io.*;

public class User implements Serializable 
{
    private String firstName;
    private String lastName;
    private String emailAddress;
    private transient String password;
    
   // private
    
    //default contruction
    public User()
    {
        //initialize class variables
        firstName = "";
        lastName = "";
        emailAddress = "";
        password = "";
    }
    
    //construction
    public User(String fname, String lname, String email, String pw)
    {
        //initialize class variables
        firstName = fname;
        lastName = lname;
        emailAddress = email;
        password = pw;
    }
    
    //accessor methods
    public String getFirstName(){return firstName;}     
    public String getLastName(){return lastName;}     
    public String getEmailAddress(){return emailAddress;}  
    public String getPassword(){return password;}     
    
    public void setFirstName(String name){firstName = name;}
    public void setLastName(String name){lastName = name;}
    public void setEmailAddress(String email){emailAddress = email;}
    public void setPassword(String pw){password = pw;}
    
    //public 
}