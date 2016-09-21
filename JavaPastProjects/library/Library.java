import java.util.*;

public class Library
{
	public static void main(String[] args)
	{	
	
		System.out.println("Books created thus far is: " + Book.getBooks());
		
		//title, author, isbn, price
		//title, author(1-4), isbn, publisher, copyrightdate, price
		Book[] books = new Book[11];
		books[0] = new Book("What Did That Change", "Charles Xavier", "98-27946917489", 12.95);
		books[1] = new Book("Norse Politics", "Darcy Lewis", "25-837482274568", 9.95);
		books[2] = new Book("Modern Robotics", "Thomas Light", "Albert Wily", 
			"Emily Stantion", "98-12476381538", "Protomen", "April 27, 2003", 25.95);
		books[3] = new Book("Sensual Phrase 3", "Mayu Shinjo", "10-61754320987", 9.99);
		books[4] = new Book("Penny Arcade", "Tycho & Gabe", "52-40389568329", 6.95);
		books[5] = new Book("Tabletop RPGs", "Felicia Day", "X. J. Isben", "Daniel Craig", 
			"Stellan Skarsgard", "75-87320432796", "Larry Whidmore", "December 25, 1964", 59.99);
		books[6] = new Book("Zen and Cats", "Bruce Banner", "98-02847928490", 2.65);
		books[7] = new Book("Autobiography of Me: Ironman", "Tony Stark" ,"0913908174", 85.62);
		books[8] = new Book("Mischevious Life", "Loki", "11-11111111111", 10.00);
		books[9] = new Book("Knights of Illaria", "Drew Sapundjieff", "93772119848", 
			"Wizards of the Coast", "March 3, 2013", 8.95);
		books[10] = new Book(books[2]); //copied*/
		
		System.out.println("Books created thus far is: " + Book.getBooks());
		
		Scanner input = new Scanner(System.in);
		int menuOption = 1, bookNumber = 0;
		int bookCounter = 0, bookCount = 0;
		Integer bookParse = new Integer(bookCounter);
		
		System.out.println(books.length);
		do
		{
			System.out.println("\nPlease enter in a number for your choice.");
			//check in
			System.out.println("1. Check in a book");
			//check out
			System.out.println("2. Check out a book");
			//list all books
			System.out.println("3. List all books");
			//list all checked out
			System.out.println("4. List all books checked out");
			//check for copies
			System.out.println("5. Check for copies in the database");
			//total cost of all books
			System.out.println("6. Total cost of all books listed");
			//quit
			System.out.println("7. Quit");
			
			System.out.print("Please input your selection: ");
			menuOption = input.nextInt();
			
			System.out.println();
			switch(menuOption)
			{
				case 1: //check in book
				{
					bookParse = 0;
					System.out.println("Checking in a book?");
					for(bookCounter = 0; bookCounter < books.length; bookCounter++)
					{
						bookParse++;
						System.out.print("\n" + bookParse + ". ");
						books[bookCounter].displayShortInfo();
					}
					System.out.println("Please enter in the number of the book: ");
					bookNumber = input.nextInt();
					bookNumber--;
					books[bookNumber].setCheckedOut(false);
					break;
				}
				case 2: //check out book
				{
					bookParse = 0;
					System.out.println("Checking out a book?");
					for(bookCounter = 0; bookCounter < books.length; bookCounter++)
					{
						bookParse++;
						System.out.print("\n" + bookParse + ". ");
						books[bookCounter].displayShortInfo();
					}
					System.out.print("Please enter in the number of the book: ");
					bookNumber = input.nextInt();
					bookNumber--;
					if(books[bookNumber].getCheckedOut() == true)
					{
						System.out.println("Sorry, that book is already checked out.");
					}
					else
					{
						books[bookNumber].setCheckedOut(true);
						System.out.println("Book has been checked out.");
					}
					break;
				}
				case 3: //list all books
				{
					bookParse = 0;
					for(bookCounter = 0; bookCounter < books.length; bookCounter++)
					{
						bookParse++;
						System.out.print("\n" + bookParse + ". ");
						books[bookCounter].displayAllInfo();
					}
					break;
				}
				case 4: //list all checked out
				{
					bookParse = 0;
					for(bookCounter = 0; bookCounter < books.length; bookCounter++)
					{
						if(books[bookCounter].getCheckedOut() == true)
						{
							bookParse++;
							System.out.print("\n" + bookParse + ". ");
							books[bookCounter].displayShortInfo();
						}
					}
					break;
				}
				case 5: //check for copies
				{
					/*for(bookCounter = 0; bookCounter < books.length; bookCounter++)
					{
						for(bookCount = 1; bookCount < books.length; bookCount++)
						{
							System.out.println(bookCount);
							if(books[bookCounter].equals(books[bookCount]))
							{
								System.out.print("\nCopy found. Deleting...\n");
								books[bookCount].setAll();
							}
						}
						
					}*/
					break;
				}
				case 6: //total cost of all
				{
					double total = 0;
					for(bookCounter = 0; bookCounter < books.length; bookCounter++)
					{
						total = total + books[bookCounter].getPrice();
					}
					System.out.println("Total cost of every book listed is $" + total + ".");
					break;
				}
				case 7: //quit
				{
					System.out.println("Quitting...");
					break;
				}
				default:
				{
					System.out.println("That is not a valid option.");
					break;
				}
			}//end switch

		} while(menuOption != 7);
		
		System.out.println("Books created thus far is: " + Book.getBooks());
		System.out.println("Thanks for coming! Have a good day/night!");
	}
	
}