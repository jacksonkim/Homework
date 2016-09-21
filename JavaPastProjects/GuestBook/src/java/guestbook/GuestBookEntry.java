/* CIST2373 - 20411 - Kimberly Jackson - SID:0332
    GuestBook - 10/13/13
    Description:
 */
package guestbook;



public class GuestBookEntry 
{
    
    private String name = "";
    private String email = "";
    private String message = "";
    
    public GuestBookEntry()
    {
        
    }
    
    public GuestBookEntry(String n, String e, String m)
    {
        name = n;
        email = e;
        message = m;
    }
    
    public String getName()
    {
        return name;
    }
    
    public String getEmail()
    {
        return email;
    }
    
    public String getMessage()
    {
        return message;
    }
    
    public void setName(String n)
    {
        name = n;
    }
    
    public void setEmail(String e)
    {
        email = e;
    }
    
    public void setMessage(String m)
    {
        message = m;
    }
}
