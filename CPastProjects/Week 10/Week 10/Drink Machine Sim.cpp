/* CIST 2361 - Drink Machine Simulator
Kimberly Jackson - 4/3/12 and 4/4/12

Description: Program will display a menu of sodas to drink, their price, and
	the quantity currently in the machine. A looped menu will ask the user to
	input which soda they would like to purchase and the amount of money
	they will be using to purchase their soda of choice. Numbers no larger than
	a dollar ($1.00) or less than 0 will be accepted. If a drink that has been selected
	that is sold out, a message will display. Once the user is completed, it will display
	how much money the machine has earned.

	Notes: I tried to use a string with toupper(userSoda) and it told me to piss off.
		error C2664: 'toupper' : cannot convert parameter 1 from 'std::string' to 'int'

		Attempted to make functions the same data type as the structure. Couldn't
		figure out how to make it use just the information from array[sub whatever].
		Ended up just flipping my laptop and making it global.
		Mostly it was working with sending the sodaData array and trying to send it back,
		and then arrays can't be referenced, and bleh bleh bleh.

		By 4am, I was too frustrated to care. I knew making it global would work, so
		I pulled up my lazy pants. Copy-pasta'd a lot of it and changed the verbage and
		array subs just because I could. It was easier than, say, doing the menu option-1
		or something. Although... that could've worked too, I suppose. Poo.

		I also found out that Switch structures can't use strings to test?

		I also had some math issues. I was so worried about making sure the code
		was doing what it was supposed to, I forgot how to math. It took me a while to
		go NO, THE BIGGER ONE GOES FIRST WHEN SUBTRACTING. DUH. And then
		NO, YOU HAVE TO ADD THE PRICE OF THE SODA TO THE INCOME.

		PPPPBBBBTTTTT. Bedtime.

		4/4/12 - Noticed the requirement for a quit option.  Added it in the loop and all
			3 of the cases that check user input.

*/

#include <iostream>
#include <iomanip>
#include <cctype> //to maintain the input for soda
#include <string>

using namespace std;

//structure containing the soda information: drink name, price, and quantity
struct sodaData
{
	string sodaName;
	double sodaPrice;
	int sodaQuant;
};

//time to make the array for the structure
	const int SIZE = 5;

//array - had to make this global to make the program do what i intended
	sodaData sodaMachine[SIZE] = { //preloading the array of structures
		{ "COLA", .75, 20 }, //sub 0
		{ "ROOT BEER", .75, 20 }, //sub 1
		{ "LEMON-LIME", .75, 20 }, //sub 2
		{ "GRAPE SODA",  .80, 0 }, //sub 3 - this is set to 0 for ease of testing purposes
		{ "CREAM SODA", .80, 20 }, //sub 4
		}; //end the array of structures

//prototypes to handle the sodas individually. a switch will be used
//to determin which will be used
void sodaCola(double &);
void sodaRootBeer(double &);
void sodaLemon(double &);
void sodaGrape(double &);
void sodaCream(double &);
void getSoda(int &); //this is just to get user input

int main()
{
	//variables to accept user input
	int userSoda;
	double earnedIncome = 0; //this is to hold the total earned by the machine
	char again; //to redo the whole thing
	int counter = 0; //added this here so it can be used outside of the for loop

	cout << "Welcome to the Drink Machine Simulator.\n";
	cout << "\n";
	cout << "To begin, we will accept the soda that you wish the purchase.\n";
	cout << "\n";

	do	
		{
			//call the input module, sending the user input for soda
			cout << setprecision(2) << showpoint;
			cout << setw(12) << "Drink Name" << setw(20) << "Cost in cents"
				<< setw(20) << "Number in Machine\n";
			cout << "----------------------------------------------------------\n";
			//loop to process the menu
			for (counter = 0; counter < 5; counter++)
			{
				//display all of the array contents one-by-one
				cout << counter+1 << ". " << setw(12) << sodaMachine[counter].sodaName
					<< setw(18) << sodaMachine[counter].sodaPrice << setw(18) << sodaMachine[counter].sodaQuant
					<< "\n";
			}
			//display the quit option
			cout << counter+1 << ". Quit\n";

			//proceed to accept input
			getSoda(userSoda);

			//now that the referenced variable is a number, this switch will
			//take the user to the appropriate soda function
			switch (userSoda)
			{	
				case 1:
					//it would be a good idea to test to see if there's any in the machine?
					if (sodaMachine[0].sodaQuant > 0)
						sodaCola(earnedIncome);
					else
						cout << "This beverage appears to be sold out.\n";
						break;
				case 2:
					if (sodaMachine[1].sodaQuant > 0)
						sodaCola(earnedIncome);
					else
						cout << "This beverage appears to be sold out.\n";
						break;
				case 3:
					if (sodaMachine[2].sodaQuant > 0)
						sodaLemon(earnedIncome);
					else
						cout << "This beverage appears to be sold out.\n";
						break;
				case 4:
					if (sodaMachine[3].sodaQuant > 0)
						sodaGrape(earnedIncome);
					else
						cout << "This beverage appears to be sold out.\n";
						break;
				case 5:
					if (sodaMachine[4].sodaQuant > 0)
						sodaCream(earnedIncome);
					else
						cout << "This beverage appears to be sold out.\n";
						break;
				case 6:
					break;
			};


			cout << "\nWould you like to purchase another soda?\n";
			cout << "Please enter Y to purchase another beverage.\n";
			cin >> again;
		} while (toupper(again) == 'Y');

		cout << setprecision(3) << showpoint;
		cout << "\n";
		cout << "We kept a tally of how much money the machine earned\n";
		cout << "as you ran your simulation.\n";
		cout << "The total comes out to: $" << earnedIncome << ".\n";

	//this is how i end all my programs. i love the extra line and the pause
	cout << "\n";
	system("pause");
	return 0;
}

/* function getSoda
	function will accept the int choice soda as a reference to send it back
	to drive the menu.

	*see note at beginning

*/
void getSoda(int & soda)
{
		//create variable for the switch
		bool drinkTrue;
	
			cout << "Please input the soda to be purchased.\n";
			cout << "Please use the number of the soda.\n";
			cin >> soda;
			
			//time to test for the pretest loop
			switch (soda)
			{	
				case 1:
						drinkTrue = true;
						break;
				case 2:
						drinkTrue = true;
						break;
				case 3:
						drinkTrue = true;
						break;
				case 4:
						drinkTrue = true;
						break;
				case 5:
						drinkTrue = true;
						break;
				case 6:
						drinkTrue = true;
						break;
				default:
						drinkTrue = false;
			};

			while (drinkTrue !=true)
			{
				//if any of the above were incorrect, it would go into here
				cout << "Looks like you keyed in the wrong thing. Try again.\n";
				cout << "Less fail this time, eh?\n";
				cout << "Please input the soda to be purchased.\n";
				cout << "Please use the number of the soda.\n";
				cin >> soda;

				switch (soda)
				{	
					case 1:
							drinkTrue = true;
							break;
					case 2:
							drinkTrue = true;
							break;
					case 3:
							drinkTrue = true;
							break;
					case 4:
							drinkTrue = true;
							break;
					case 5:
							drinkTrue = true;
							break;
					case 6:
							drinkTrue = true;
							break;
					default:
							drinkTrue = false;
				};

					//test the new input
					
			}
}

/* function sodaCola
accepts the sodaData structure array to do the math with and change the
quantity of drinks in the machine and the income to set the earned income.
will return the array structure at cola sub which is 0.
*/
void sodaCola(double & income)
{
	//at this point we have to declare a variable to accept the amount
	//of money being spent on the soda
	double userMoney;

	cout << "\n";
	cout << "You have selected Cola to purchase.\n";
	cout << "Please enter in the amount of money you wish to\n";
	cout << "spend on this purchse.\n";
	cout << "Amounts between 0 and $1.00 only are accepted.\n";
	cin >> userMoney;
	
	//validation for if the amount entered is negative or greater than $1.00
	while (userMoney < 0 || userMoney > 1.0)
	{
		cout << "\n";
		cout << "Looks like you didn't do what I asked.\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//not asked for, but it would be hard to sell a soda if there
	//wasn't enough money for it.
	while (userMoney < sodaMachine[0].sodaPrice)
	{
		cout << "\n";
		cout << "Not enough money\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//now that the money has been verified, time to do a math
	sodaMachine[0].sodaQuant--;
	income += sodaMachine[0].sodaPrice;

	cout << "Given that you supplied more than the cost of the drink,\n";
	cout << "$" << userMoney - sodaMachine[0].sodaPrice  << " will be returned to you.\n";

}

/* function sodaRootBeer
accepts the sodaData structure array to do the math with and change the
quantity of drinks in the machine and the income to set the earned income.
will return the array structure at root beer sub which is 1.
*/
void sodaRootBeer(double & income)
{
	//at this point we have to declare a variable to accept the amount
	//of money being spent on the soda
	double userMoney;
	
	cout << "\n";
	cout << "You have selected Root Beer to purchase.\n";
	cout << "Please enter in the amount of money you wish to\n";
	cout << "spend on this purchse.\n";
	cout << "Amounts between 0 and $1.00 only are accepted.\n";
	cin >> userMoney;
	
	//validation for if the amount entered is negative or greater than $1.00
	while (userMoney < 0 || userMoney > 1.0)
	{
		cout << "\n";
		cout << "Looks like you didn't do what I asked.\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//not asked for, but it would be hard to sell a soda if there
	//wasn't enough money for it.
	while (userMoney < sodaMachine[1].sodaPrice)
	{
		cout << "\n";
		cout << "Not enough money\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//now that the money has been verified, time to do a math
	sodaMachine[1].sodaQuant--;
	income += sodaMachine[1].sodaPrice;

	cout << "Given that you supplied more than the cost of the drink,\n";
	cout << "$" << userMoney - sodaMachine[1].sodaPrice  << " will be returned to you.\n";

}

/* function sodaLemon
accepts the sodaData structure array to do the math with and change the
quantity of drinks in the machine and the income to set the earned income.
will return the array structure at lemon-lime sub which is 2.
*/
void sodaLemon(double & income)
{
	//at this point we have to declare a variable to accept the amount
	//of money being spent on the soda
	double userMoney;

	cout << "\n";
	cout << "You have selected Lemon-Lime to purchase.\n";
	cout << "Please enter in the amount of money you wish to\n";
	cout << "spend on this purchse.\n";
	cout << "Amounts between 0 and $1.00 only are accepted.\n";
	cin >> userMoney;
	
	//validation for if the amount entered is negative or greater than $1.00
	while (userMoney < 0 || userMoney > 1.0)
	{
		cout << "\n";
		cout << "Looks like you didn't do what I asked.\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//not asked for, but it would be hard to sell a soda if there
	//wasn't enough money for it.
	while (userMoney < sodaMachine[2].sodaPrice)
	{
		cout << "\n";
		cout << "Not enough money\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//now that the money has been verified, time to do a math
	sodaMachine[2].sodaQuant--;
	income += sodaMachine[2].sodaPrice;

	cout << "Given that you supplied more than the cost of the drink,\n";
	cout << "$" << userMoney - sodaMachine[2].sodaPrice << " will be returned to you.\n";

}

/* function sodaGrape
accepts the sodaData structure array to do the math with and change the
quantity of drinks in the machine and the income to set the earned income.
will return the array structure at grape soda sub which is 3.
*/
void sodaGrape(double & income)
{
	//at this point we have to declare a variable to accept the amount
	//of money being spent on the soda
	double userMoney;

	cout << "\n";
	cout << "You have selected Grape Soda to purchase.\n";
	cout << "Please enter in the amount of money you wish to\n";
	cout << "spend on this purchse.\n";
	cout << "Amounts between 0 and $1.00 only are accepted.\n";
	cin >> userMoney;
	
	//validation for if the amount entered is negative or greater than $1.00
	while (userMoney < 0 || userMoney > 1.0)
	{
		cout << "\n";
		cout << "Looks like you didn't do what I asked.\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//not asked for, but it would be hard to sell a soda if there
	//wasn't enough money for it.
	while (userMoney < sodaMachine[3].sodaPrice)
	{
		cout << "\n";
		cout << "Not enough money\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//now that the money has been verified, time to do a math
	sodaMachine[3].sodaQuant--;
	income += sodaMachine[3].sodaPrice;

	cout << "Given that you supplied more than the cost of the drink,\n";
	cout << "$" << userMoney - sodaMachine[3].sodaPrice << " will be returned to you.\n";

}

/* function sodaCream
accepts the sodaData structure array to do the math with and change the
quantity of drinks in the machine and the income to set the earned income.
will return the array structure at cream soda sub which is 4.
*/
void sodaCream(double & income)
{
	//at this point we have to declare a variable to accept the amount
	//of money being spent on the soda
	double userMoney;

	cout << "\n";
	cout << "You have selected Cream Soda to purchase.\n";
	cout << "Please enter in the amount of money you wish to\n";
	cout << "spend on this purchse.\n";
	cout << "Amounts between 0 and $1.00 only are accepted.\n";
	cin >> userMoney;
	
	//validation for if the amount entered is negative or greater than $1.00
	while (userMoney < 0 || userMoney > 1.0)
	{
		cout << "\n";
		cout << "Looks like you didn't do what I asked.\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//not asked for, but it would be hard to sell a soda if there
	//wasn't enough money for it.
	while (userMoney < sodaMachine[4].sodaPrice)
	{
		cout << "\n";
		cout << "Not enough money\n";
		cout << "Please try again, only this time, only something between\n";
		cout << "0 and $1.00.\n";
		cin >> userMoney;
	}

	//now that the money has been verified, time to do a math
	sodaMachine[4].sodaQuant--;
	income += sodaMachine[4].sodaPrice;

	cout << "Given that you supplied more than the cost of the drink,\n";
	cout << "$" <<  userMoney - sodaMachine[4].sodaPrice << " will be returned to you.\n";

}