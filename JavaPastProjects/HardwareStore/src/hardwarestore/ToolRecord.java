package hardwarestore;

/* CIST2373 - 20411 - Kimberly Jackson - SID: 0332
 * Week 1, Hardware Store MDI GUI - 8/19/13
 * 
 * Description: Create an MDI GUI that tracks the inventory of a hardware store.
 * Inventory information will be held in an external direct-access binary file.
 * The name of the file is hardware.dat
 * 
 * The Tool class is to hold the following information:
 * 
 *      Tool ID - int
 *      Tool Name - char array
 *      Quantity of Tool - int
 *      Unit Cost of Tool - double
 */

import java.io.Serializable;

public class ToolRecord 
{
    //tool record data
    private int toolID;
    private String toolName;
    private int quantity;
    private double unitCost;
    
    //no argument constructor with initial values
    public ToolRecord()
    {
        this(0, "", 0, 0.0);
    };
    
    //initialize a record
    public ToolRecord(int tid, String tn, int q, double uc)
    {
        setToolID(tid);
        setToolName(tn);
        setToolQuantity(q);
        setToolUnitCost(uc);
    };
    
    public void setToolID(int tid)
    {
        if (tid >= 0 )
        {
            toolID = tid;
        };
    };
    
    public void setToolName(String tn)
    {
        toolName = tn;
    };
    
    public void setToolQuantity(int q)
    {
        quantity = q;
    };
    
    public void setToolUnitCost(double uc)
    {
        unitCost = uc;
    };
    
    public int getToolID()
    {
        return toolID;
    };
    
    public String getToolName()
    {
        return toolName;
    };
    
    public int getToolQuantity()
    {
        return quantity;
    };
    
    public double getToolUnitCost()
    {
        return unitCost;
    };
    
    public String toString()
   {
	return String.format("Tool: %d %s %s $%.2f", getToolID(), getToolName(), 
                getToolQuantity(), getToolUnitCost());
   }
}
