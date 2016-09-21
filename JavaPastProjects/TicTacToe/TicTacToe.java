
public class TicTacToe
{
	public char board[][] = new char[3][3];
	
	TicTacToe()
	{
		int count = 0;
		board[count][count] = '-';
		board[count][count+1] = '-';
		board[count][count+2] = '-';
		
		board[count+1][count] = '-';
		board[count+1][count+1] = '-';
		board[count+1][count+2] = '-';
		
		board[count+2][count] = '-';
		board[count+2][count+1] = '-';
		board[count+2][count+2] = '-';
	}
	
	void displayUpdate()
	{
		System.out.print("|  " + board[0][0] + "  |");
		System.out.print("|  " + board[1][0] + "  |");
		System.out.print("|  " + board[2][0] + "  |\n");
		
		System.out.print("|  " + board[0][1] + "  |");
		System.out.print("|  " + board[1][1] + "  |");
		System.out.print("|  " + board[2][1] + "  |\n");
		
		System.out.print("|  " + board[0][2] + "  |");
		System.out.print("|  " + board[1][2] + "  |");
		System.out.print("|  " + board[2][2] + "  |\n");
	}
	 
	boolean insertNextMove(char c, int row, int column)
	{		
		boolean good = false;
		if(c == 'x' || c == 'o')
		{
			if(row-1 < 3 && row-1 > -1)
			{
				if(column-1 < 3 && column-1 > -1)
				{
					if(board[column-1][row-1] == '-')
					{
						board[column-1][row-1] = c;
						good = true;

					}//end checking for content and placement									
				}//end verifying column
			}//end verifying row
		}//end verifying char
		
		return good;
	}
	
	boolean gameOver()
	{
		boolean good = false;
		int count = 0;
		
		if (board[count][count] == 'x')
		{
			if(board[count][count+1] == 'x')
			{
				if(board[count][count+2] == 'x')
				{
					good = true;
				}//first row x
			}//second row spot x
			else if(board[count+1][count] == 'x')
			{
				if(board[count+2][count] == 'x')
				{
					good = true;
				}//first column x
			}//second column spot x
			else if(board[count+1][count+1] == 'x')
			{
				if(board[count+2][count+2] == 'x')
				{
					good = true;
				}//diagonal x
			}//center board x
		}//end first row/col x
		else if(board[count+1][count] == 'x')
		{
			if(board[count+1][count+1] == 'x')
			{
				if(board[count+1][count+2] == 'x')
				{
					good = true;
				}//second row x
			}//second row spot x
		}//end second row if
		else if(board[count+2][count] == 'x')
		{
			if(board[count+2][count+1] == 'x')
			{
				if(board[count+2][count+2] == 'x')
				{
					good = true;
				}//third row x
			}//third row spot x
			else if(board[count+1][count+1] == 'x')
			{
				if(board[count][count+2] == 'x')
				{
					good = true;
				}//end diagonal x
			}//end center x
		}//end diagonal x if
		else if(board[count+1][count] == 'x')
		{
			if(board[count+1][count+1] == 'x')
			{
				if(board[count+1][count+2] == 'x')
				{
					good = true;
				}//end second col x
			}//end second col spot x
		}//end second col x
		else if(board[count+2][count] == 'x')
		{
			if(board[count+2][count+1] == 'x')
			{
				if(board[count+2][count+2] == 'x')
				{
					good = true;
				}//third col x
			}//third col spot x
		}//end third col x
		
		
		

		if (board[count][count] == 'o')
		{
			if(board[count][count+1] == 'o')
			{
				if(board[count][count+2] == 'o')
				{
					good = true;
				}//first row o
			}//second row spot o
			else if(board[count+1][count] == 'o')
			{
				if(board[count+2][count] == 'o')
				{
					good = true;
				}//first column o
			}//second column spot o
			else if(board[count+1][count+1] == 'o')
			{
				if(board[count+2][count+2] == 'o')
				{
					good = true;
				}//diagonal o
			}//center board o
		}//end first row/col o
		else if(board[count+1][count] == 'o')
		{
			if(board[count+1][count+1] == 'o')
			{
				if(board[count+1][count+2] == 'o')
				{
					good = true;
				}//second row o
			}//second row spot o
		}//end second row if
		else if(board[count+2][count] == 'o')
		{
			if(board[count+2][count+1] == 'o')
			{
				if(board[count+2][count+2] == 'o')
				{
					good = true;
				}//third row o
			}//third row spot o
			else if(board[count+1][count+1] == 'o')
			{
				if(board[count][count+2] == 'o')
				{
					good = true;
				}//end diagonal o
			}//end center o
		}//end diagonal o if
		else if(board[count+1][count] == 'o')
		{
			if(board[count+1][count+1] == 'o')
			{
				if(board[count+1][count+2] == 'o')
				{
					good = true;
				}//end second col o
			}//end second col spot o
		}//end second col o
		else if(board[count+2][count] == 'o')
		{
			if(board[count+2][count+1] == 'o')
			{
				if(board[count+2][count+2] == 'o')
				{
					good = true;
				}//third col o
			}//third col spot o
		}//end third col o
		
		if (board[count][count] != '-')
		{
			if (board[count][count+1] != '-')
			{
				if (board[count][count+2] != '-')
				{
					if (board[count+1][count] != '-')
					{
						if (board[count+1][count+1] != '-')
						{
							if (board[count+1][count+2] != '-')
							{
								if (board[count+2][count] != '-')
								{
									if (board[count+2][count+1] != '-')
									{
										if (board[count+2][count+2] != '-')
										{
											good = true;
										}//end checking every square 3,3
									}//3,2
								}//3,1
							}//2,3
						}//2,2
					}//2,1
				}//1,3
			}//1,2
		}//1,1
		
		return good;
	}
}