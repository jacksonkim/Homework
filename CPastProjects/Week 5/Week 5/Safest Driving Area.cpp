#include <iostream>


using namespace std;

int getNumAccidents(int&, int&, int&, int&, int&);
int findLowest(int, int, int, int, int, int);

int main()
{
	//Creating the variables in the main module so they may be passed as reference to the getnum module
	//for input, then passed into the findlowest. I suppose I could make the variables in the getnum function,
	//but I decided to see if it would still work if I did it the hard way.

	int northAccidents, //To hold the value of the northern region
		southAccidents, //southern region
		eastAccidents, //eastern region
		westAccidents, //I figured you'd get it by now
		centralAccidents, //They're pretty self-explanatory
		lowest = 0; //To hold the lowest value to report which area had the lowest number of accidents

	//doofy wall of text and instructions
	cout << "Thank you for worrying about your safety and the safety" <<endl;
	cout << "of your family and friends. Although, this app does" << endl;
	cout << "require some numbers from you." << endl;
	cout << endl;
	cout << "The numbers we need are the number of automobile" << endl;
	cout << "accidents that have occurred in the last year in" << endl;
	cout << "five different geographical areas of your city." << endl;
	cout << "\n";
	cout << "These areas are categorized in the Cardinal directions and\nalso central." << endl;
	cout << "\n";
	cout << "For those unfamiliar with the term 'Cardinal Directions', it simply means\n";
	cout << "the directions on a compass. So North, South, East, and West.\n";

	//call the first function - getnumaccidents
	cout << "\n";
	cout << "Anywho, let's get start, shall we?\n";

	getNumAccidents(northAccidents, southAccidents, eastAccidents, westAccidents, centralAccidents);

	//call the second function - findlowest
	cout << "\n";
	cout << "Thank you for all that information. Time to do some calculations.\n";
	cout << "\n";

	findLowest(northAccidents, southAccidents, eastAccidents, westAccidents, centralAccidents, lowest);

	cout << "\n";
	system("pause");
	return 0;

}

int getNumAccidents(int & refnorthAccidents, int & refsouthAccidents, int & refeastAccidents, int & refwestAccidents, int & refcentralAccidents)
{
	//Prompt for each region, checking to make sure the value is not < 0
	cout << "\n";
	cout << "Please do not input a number less than zero for accidents in the last year.\n";
	cout << "If for no other reason than you can't negate an accident. I don't think...\n";

	//A Do loop will allow this question to run at least once without having to prime the value of the accidents.
	//Only YOU can prevent logic errors.
	do
	{
		cout << "\n";
		cout << "Firstly, how many accidents occurred in the Nothern region\n";
		cout << "of your city last year?\n";
		cin >> refnorthAccidents;
	} while (refnorthAccidents < 0);

	//Maintain for every question.
	do
	{
		cout << "\n";
		cout << "How about in the Southern region?\n";
		cin >> refsouthAccidents;
	} while (refsouthAccidents < 0);

	//And again with the do loop.
	do
	{
		cout << "\n";
		cout << "What about in the Eastern region?\n";
		cin >> refeastAccidents;
	} while (refeastAccidents < 0);

	//Do loop for the Western region.
	do
	{
		cout << "\n";
		cout << "Go West, young man. How is the traffic in that area?\n";
		cin >> refwestAccidents;
	} while (refwestAccidents < 0);

	//We didn't forget about the central district, did we?
	do
	{
		cout << "\n";
		cout << "And finally, tell us about the Central region's accidents.\n";
		cin >> refcentralAccidents;
	} while (refcentralAccidents < 0);

	//With that, all five regions have been collected. Time to move on to the test.
	return 0;
}

int findLowest(int north, int south, int east, int west, int central, int lowest)
{
	//In hope of preventing this from being some horrible If monster, a For loop is being used to test each region against the current value of lowest.

	int counter; //counter for the for loop

	//set the lowest to prime it for the if statement later.
	lowest = north;

	for (counter=1; counter <6; counter++)
	{
		//going to create a bunch of separate if statements to avoid skipping all the tests.
		//North first.
		if (lowest > north)
			lowest = north;

		//then soth
		if (lowest > south)
			lowest = south;

		//east
		if (lowest > east)
			lowest = east;

		//west
		if (lowest > west)
			lowest = west;

		//finally, central booking
		if (lowest > central)
			lowest = central;

		//at this point, lowest should have a new value and it will run the for loop at least 5 times to verify
		//that the lowest value is the indeed the lowest.

	}
//testing is complete

	//Time to display the information related to what the lowest number is.
	if (lowest == north)
	{
		cout << "\n";
		cout << "It appears as though the Northside has the least amount of accidents.\n";
		cout << "Only " << lowest << " in the last year alone. Congrats.\n";
	}
	else if (lowest == south)
	{
		cout << "\n";
		cout << "It appears as though the Southside has the least amount of accidents.\n";
		cout << "Only " << lowest << " in the last year alone. Congrats.\n";
	}
	else if (lowest == east)
	{
		cout << "\n";
		cout << "It appears as though the Eastside has the least amount of accidents.\n";
		cout << "Only " << lowest << " in the last year alone. Congrats.\n";
	}
	else if (lowest == west)
	{
		cout << "\n";
		cout << "It appears as though the Westside has the least amount of accidents.\n";
		cout << "Only " << lowest << " in the last year alone. Congrats.\n";
	}
	else if (lowest == central)
	{
		cout << "\n";
		cout << "It appears as though the Central region has the least amount of accidents.\n";
		cout << "Only " << lowest << " in the last year alone. Congrats.\n";
	}
	else
	{
		cout << "\n";
		cout << "Something bad happened and I don't know what.\n";
	}

	return 0;
}