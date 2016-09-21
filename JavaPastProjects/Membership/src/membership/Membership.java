/* CIST 2371 - 20790 - Kimberly Jackson - SID: 0332
 * Week 12, Membership Programming - 12/6/12
 * 
 * Description:
 */
package membership;

import java.io.FileNotFoundException;
import java.io.IOException;


public class Membership 
{

    
    public static void main(String[] args) throws FileNotFoundException, IOException, Exception 
    {
        Tester whatsit = new Tester();
        
        
        //whatsit.CreateAdministratorUser();
        
        User[] members = whatsit.GetAllUsers();
    }
}
