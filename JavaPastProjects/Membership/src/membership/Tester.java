/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package membership;

import java.io.*;
import java.util.*;

public class Tester 
{
    /*
     * This method creates an administrator user that is written to the users.ser file.
     */
    public boolean CreateAdministratorUser() throws FileNotFoundException, IOException, Exception
    {
        boolean success = false;
        
        try
        {
            //object for writing data to file
            ObjectOutputStream output;

            //make sure file exists
            File file = new File("users.ser");

            //if file not found in current directory, throw error stating so
            if(file.exists())
            {
                //open file
                output = new ObjectOutputStream(new FileOutputStream(file));
                
                if(output != null)
                {
                    //create a record
                    User admin = new User();
                    admin.setFirstName("administrator");
                    admin.setLastName("administrator");
                    admin.setEmailAddress("instructor@gtc.com");

                    //write record to file
                    output.writeObject(admin);

                    //close file
                    output.close();
                    output = null;
                    
                    //no errors
                    success = true;
                }                
            }
            else
            {
                throw new FileNotFoundException();
            }
        }
        catch(FileNotFoundException fileNotFoundException)
        {
            //create exception message
        }
        catch(IOException ioException)
        {
            //create exception message
        }
        catch(Exception e)
        {
            //create exception message
        }
        finally
        {
            
        }
        
        return success;
    }
    
    /*
     * The method returns an array of User objects that are stored in the users.ser file
     */
    public User[] GetAllUsers()throws FileNotFoundException, IOException, Exception
    {
        int numUsers = 1;
        User[] users = null;
        
        try
        {
            //used for reading from the file
            ObjectInputStream input;
            
            //make sure file exists
            File file = new File("users.ser");

            //if file not found in current directory, throw error stating so
            if(file.exists())
            {
                input = new ObjectInputStream(new FileInputStream(file));
                
                //loop until all records have been read
                try
                {
                    while(true)
                    {
                        User user = (User)input.readObject();

                        //resize our array to hold additional user
                        users = new User[numUsers];
                        users[numUsers - 1] = user;

                        //increment the number of users
                        numUsers++;
                    }
                }
                catch(EOFException eof)
                {
                    //end of file reached.
                    //ignore this exception
                }
            }
            else
            {
                throw new FileNotFoundException();
            }
        }
        catch(FileNotFoundException fileNotFoundException)
        {
            //handle exception
        }
        catch(IOException ioException)
        {
            //handle exception
        }
        catch(Exception e)
        {
            //handle exception
        }
        finally
        {
            
        }
        
        return users;
    }
    
    
    public void CreateItems()
    {
        try
        {
            Formatter output = new Formatter("c:\\temp\\items.ser");
            
            output.format("%s,%.2f\r\n", "iPad", 399.99);
            output.format("%s,%.2f\r\n", "Ticle Me Elmo", 35.99);
            output.format("%s,%.2f\r\n", "XBox 360", 275.00);
            output.format("%s,%.2f\r\n", "Kindle Fire", 199.99);
            output.format("%s,%.2f\r\n", "50\" Sony Plasma", 1299.99);
            
            output.close();
        }
        catch(Exception e)
        {
        }
    }
}

