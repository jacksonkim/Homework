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

/**
 *
 * @author Kim
 */

import java.util.Scanner;

public class MFWeekday 
{
    public static void main(String[] args)
    {
        int menuOption = 0,
                day = 0;
        String event;
        Scanner input = new Scanner(System.in);
        
        Calendar week1 = new Calendar();
        
        System.out.println("Welcome to the Weekday Calendar App.");
        System.out.println("This app was designed to function for the Monday"
                + "through Friday weekday.");
        System.out.println("If you have events on the weekends, you will have"
                + "to purchase an upgrade. (Don't worry, it's cheap.)");
        
        do
        {
            System.out.println("Please choose an option below.");
            System.out.println("1. View current list of all events");
            System.out.println("2. View a single event");
            System.out.println("3. Input an event");
            System.out.println("4. Edit an event");
            System.out.println("5. Exit");
            
            System.out.print("\nPlease input a number between 1-5: ");
            menuOption = input.nextInt();
            
            switch (menuOption)
            {
                case 1:
                    week1.DisplayEvents();
                    break;
                case 2:
                    System.out.print("Please input a number between 1-5 to "
                            + "correspond with the day of the week: ");
                    day = input.nextInt();
                    week1.DisplaySingleEvent(day-1);
                    break;
                case 3:
                    System.out.print("Please input a number between 1-5 to "
                            + "correspond with the day of the week: ");
                    day = input.nextInt();
                    switch (day)
                    {
                        case 1:
                            System.out.println("This will be for Monday.");
                            System.out.print("Please input the single word event: ");
                            event = input.next();
                            week1.CreateEvent(event, day-1);
                            break;
                        case 2:
                            System.out.println("This will be for Tuesday.");
                            System.out.print("Please input the single word event: ");
                            event = input.next();
                            week1.CreateEvent(event, day-1);
                            break;
                        case 3:
                            System.out.println("This will be for Wednesday.");
                            System.out.print("Please input the single word event: ");
                            event = input.next();
                            week1.CreateEvent(event, day-1);
                            break;
                        case 4:
                            System.out.println("This will be for Thursday.");
                            System.out.print("Please input the single word event: ");
                            event = input.next();
                            week1.CreateEvent(event, day-1);
                            break;
                        case 5:
                            System.out.println("This will be for Friday.");
                            System.out.print("Please input the single word event: ");
                            event = input.next();
                            week1.CreateEvent(event, day-1);
                            break;            
                    }                   
                    break;
                case 4:
                    System.out.print("Please input a number between 1-5 to "
                            + "correspond with the day of the week: ");
                    day = input.nextInt();
                    System.out.print("Please input the single word event: ");
                    event = input.next();
                    week1.CreateEvent(event, day-1);
                    break;
                case 5:
                    System.out.println("Thank you for your patronage.");
                    break;            
            }
            
        } while (menuOption != 5);
    }
}
