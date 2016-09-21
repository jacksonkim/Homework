/* CIST2373 - 20411 - Kimberly Jackson - SID:0332
    Guestbook - 10/13/13
    Description:
 */
package guestbook;

import java.io.Serializable;
import java.util.ArrayList;
import javax.enterprise.context.ApplicationScoped;
import javax.faces.bean.ManagedBean;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;

@ApplicationScoped
@WebServlet("/GuestBook")
@ManagedBean(name="guestBookBean")
public class GuestBookBean extends HttpServlet implements Serializable 
{
    
    private ArrayList<GuestBookEntry> gblist = new ArrayList();
    
    public GuestBookBean()
    {
        GuestBookEntry gbentry = new GuestBookEntry();
    }
    
    
}
