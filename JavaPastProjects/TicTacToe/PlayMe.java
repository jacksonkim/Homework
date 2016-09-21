import java.util.*;

class PlayMe
{
	public static void main(String[] args)
	{
		TicTacToe game1 = new TicTacToe();
		
		System.out.println("\nPlease use only lowercase x and o to play this game." + 
			"\nAnd of course only the numbers 1-3 for the columns and rows.\nGood luck!\n");
		
				
		Scanner input = new Scanner(System.in);
		
		char letterbox;
		String next;
		int col, row;
		
		while (!game1.gameOver())
		{
		
			game1.displayUpdate();

			System.out.print("\nPlease enter in the LETTER that you would like to play: ");
			next = input.next();
			
			next = next.toLowerCase();
			letterbox = next.charAt(0);
			
			System.out.print("\nPlease enter in the COLUMN to place your piece: ");
			col = input.nextInt();
			
			System.out.print("\nPlease enter in the ROW to place your piece: ");
			row = input.nextInt();
			
			System.out.println("\nCool, let's try to put that in.\n\n");
			
			if(game1.insertNextMove(letterbox, row, col) == true)
			{
				System.out.println("Oh, good move!\n");
			}
			else
			{
				System.out.println("Sorry, try that again. It looks like something went wrong.");
				System.out.println("It'ss... NO GOOOOOD.\n");
			}			

		}//end while
		
		System.out.println("Looks like the game is over.");
	}

}
