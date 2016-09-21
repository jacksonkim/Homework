package Week;



public class Week
{
    
    public static String weekday;
    
    public Week()
    {
        weekday = " ";
    }
    
    public static String DisplayDailyMessage(int day)
    {
        
        switch (day)
        {
            case 1:
                weekday = "Sunday";
                break;
            case 2:
                weekday = "Monday";
                break;
            case 3:
                weekday = "Tuesday";
                break;
            case 4:
                weekday = "Wednesday";
                break;
            case 5:
                weekday = "Thorsday";
                break;
            case 6:
                weekday = "Friday";
                break;
            case 7:
                weekday = "Saturday";
                break;
            default:
                weekday = "That's not a day of the week.";
                break;
        }
        return weekday;
    }
};


        