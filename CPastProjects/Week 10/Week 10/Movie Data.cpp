/* CIST 2361 - Movie Data
Kimberly Jackson - 4/3/12

Description: Program will display movie title, director, year it was released, and 
	running time in minutes. Data will be stored in a MovieData structure, sent 
	to a function to be displayed.

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData //structure to hold the title, director, year, and running time
{
public:
	string title,
		director; //strings to hold the movie title and director
	int year,
		runningTime; //integers to hold the year the movie was released and running time

};

//prototype for the display function. will accept the moviedata structure
void showData(MovieData);

int main()
{
	//load the moviedata variables with random movies. these are the first 2 i thought of
	MovieData movie1 = { "Trojan War", "George Huang", 1997, 84 }, //this one is on my laptop
		movie2 = { "The Machinist", "Brad Anderson", 2004, 101 }; //variables to hold the structure MovieData
		//this one i just enjoy. not sure why it popped up in my head


	//call the showdata function twice, once for each variable
	showData(movie1);
	showData(movie2);

	//outro message
	cout << "Thanks for checking!\n";
	cout << "\n";
	system("pause");
	return 0;

} //end main

//function showData
//called twice by the main function to display the information from
//the moviedata variables.
void showData(MovieData movie)
{
	cout << "Movie title: " << movie.title << "\n";
	cout << "Director: " << movie.director << "\n";
	cout << "Year movie was released: " << movie.year << "\n";
	cout << "Average running time of movie: " << movie.runningTime << " minutes.\n";
	cout << "\n";
} //end showData