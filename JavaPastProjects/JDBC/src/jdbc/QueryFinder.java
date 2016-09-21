/* CIST2373 - 20411 - Kimberly Jackson - SID: 0332
 * Week 5, JDBC Console - 9/22/13
 * 
 * Description: Create a simple console app to allow a user to query
        a database, the Northwinds Database for the following information:
        Print order total (minus frieght cost)
        Print all order details
        Print names and cities of all customers in a specific state
        Print the names of all employees who have a birthday in a specific year
        (that last one is really specific...)
 */

package jdbc;

import java.util.*;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class QueryFinder 
{
    
    private Connection con = null;
    private Statement sta = null;
    private ResultSet res = null;
    
    public QueryFinder()
    {
        try 
        {
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            con = DriverManager.getConnection("jdbc:odbc:DRIVER={Microsoft "
                    + "Access Driver (*.mdb)};dbq=C:\\data\\Northwind.mdb;"
                    + "UID=Admin;PWD=;");
        } 
        catch (Exception ex) 
        {
            ex.printStackTrace();
        }
    }
    
    public void viewTotal(int orderNum)
    {
        try
        {
            sta = con.createStatement();
            res = sta.executeQuery("select discount from [order details]"
                    + " where orderid=" + orderNum);
            if (res.next())
            {
                if(res.getFloat("discount") == 0.0)
                {
                    res = sta.executeQuery("select sum(unitprice*quantity) as "
                        + "ordertotal from [order details] where orderID=" 
                        + orderNum);
                }
                else
                {
                    res = sta.executeQuery("select sum((unitprice*discount)quantity) as "
                        + "ordertotal from [order details] where orderID=" 
                        + orderNum);
                }
                
            }           
            
            while (res.next())
            {
                
                System.out.println("Order Total: $" + res.getFloat("ordertotal"));
                /*System.out.print("\nPrice: $" + res.getFloat("unitprice") 
                        + "\tQuantity: " + res.getInt("quantity") + 
                        "\tDiscount: " + res.getInt("discount") + "%\n");*/
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    
    public void viewOrderDets(int orderNum)
    {
        try
        {
            //order date, freight charge, and all products and their quantity, 
            //unit price, and discount for the order.
            sta = con.createStatement();
            res = sta.executeQuery("select [orders].orderdate, "
                    + "[orders].freight, [orders].orderid, "
                    + "[order details].productid, [order details].quantity, "
                    + "[order details].unitprice, [order details].discount"
                    + " from [order details], [orders] "
                    + "where [orders].orderID=[order details].orderid "
                    + "and [orders].orderid=" + orderNum + " and "
                    + "[order details].orderid=" + orderNum);
            
            if (res.next())
            {
                System.out.print("Order Number: " + res.getInt("orderid") + 
                        "\tOrder Date: " + res.getDate("orderdate") + 
                        "\tFreight: " + res.getFloat("freight"));
                System.out.print("\nPrice: $" + res.getFloat("unitprice") 
                        + "\tQuantity: " + res.getInt("quantity") + 
                        "\tDiscount: " + res.getInt("discount") + "%");
            }
            
            while (res.next())
            {                
                System.out.print("\nPrice: $" + res.getFloat("unitprice") 
                        + "\tQuantity: " + res.getInt("quantity") + 
                        "\tDiscount: " + res.getInt("discount") + "%");                
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        
    }
    
    public void viewStates(String state)
    {
        try
        {
            sta = con.createStatement();
            res = sta.executeQuery("select * from Customers "
                    + "where region=" + state + " order by region");
            
            System.out.println("Name\t\tCity");
            System.out.println("----------------------------------");
            
            while (res.next())
            {
                System.out.println(res.getString("contactname") + "\t\t" + 
                        res.getString("city"));
            }
            
            
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        
    }
    
    public void viewBirthday(int year)
    {
        try
        {
            sta = con.createStatement();
            res = sta.executeQuery("select * from employees where "
                    + "DatePart(\"yyyy\", BirthDate)=" + year);
            //+ " order by lastname"
            
            System.out.println("Last Name\t\tFirst Name\t\tBirthday");
            System.out.println("---------------------------------------------");
            
            while (res.next())
            {
                System.out.print(res.getString("lastname") + "\t\t" + 
                        res.getString("firstname") + "\t\t " + 
                        res.getString("birthdate") + "\t\t" + 
                        res.getDate("birthdate") + "\n");
                
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

    }
    
    public void closeConnection()
    {
        try
        {
            if(res != null)
            {
                res.close();
            }
            if(sta != null)
            {
                sta.close();
            }
            if(con != null)
            {
                con.close();
            }
        }
        catch (Exception e)
	{
            e.printStackTrace();
	}
    }
}
