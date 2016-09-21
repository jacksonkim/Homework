/* CIST 2371 - 20790 - Kimberly Jackson - SID: 0332
 *  Week 5 Assignment, Calender App - 9/29/2012
 * 
 *  Description: Make a Calendar app that allows a user to enter in
 *      an event for the M-F days of the week. A string array of 5 elements
 *       - not hardcoded at 5 - and the user should be allowed to use an
 *      integer to set the day and a single word for the event. The entry
 *      in the array should be formatted as "Monday Appointment: PTA".
 */
package calendar;

public class Calendar 
{
    private final int NUM_DAYS = 5;
    private String[] events = new String[NUM_DAYS];
    
    Calendar()
    {
         for (int count = 0; count < NUM_DAYS; count++)
        {
            events[count] = "-No Event Planned-";
        }
    }
    
    /*
     * method: CreateEvent
     *      accepts: String argument - single word to set the event, appended
     *                      to include the event day based on in argument
     *              int argument - integer-1 to set the element in array to
     *                  String argument
     */
    void CreateEvent(String e, int d)
    {
        switch (d)
        {
            case 0:
                events[d] = "Monday Appointment: " + e;
                break;
            case 1:
                events[d] = "Tuesday Appointment: " + e;
                break;
            case 2:
                events[d] = "Wednesday Appointment: " + e;
                break;
            case 3:
                events[d] = "Thursday Appointment: " + e;
                break;
            case 4:
                events[d] = "Friday Appointment: " + e;
                break;            
        }
    }
    
    void DisplayEvents()
    {
        System.out.printf("   %s%10s\n", "Weekday", "Event");
        
        for (int count = 0; count < NUM_DAYS; count++)
        {
            System.out.print(count+1);
            System.out.printf(". %s\n", events[count]);
        }
    }
    
    void DisplaySingleEvent(int d)
    {
        switch (d)
        {
            case 0:
                System.out.print(d+1);
                System.out.printf(". %s\n", events[d]);
                break;
            case 1:
                System.out.print(d+1);
                System.out.printf(". %s\n", events[d]);
                break;
            case 2:
                System.out.print(d+1);
                System.out.printf(". %s\n", events[d]);
                break;
            case 3:
                System.out.print(d+1);
                System.out.printf(". %s\n", events[d]);
                break;
            case 4:
                System.out.print(d+1);
                System.out.printf(". %s\n", events[d]);
                break;            
        }
    }
}
