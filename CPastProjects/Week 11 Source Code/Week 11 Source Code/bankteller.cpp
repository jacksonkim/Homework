// bank teller simulation routine
//
// Described in Chapter 10 of
// Data Structures in C++ using the STL
// Published by Addison-Wesley, 1997
// Written by Tim Budd, budd@cs.orst.edu
// Oregon State University
//
// modified by Charles R. Hardnett, 2011

#include <list>
#include <vector>
#include <stack>
#include <string>
#include <queue> 
#include <iostream>
#include <ctime>
#include <iomanip>


using namespace std;


class Customer; // forward declaration


// function protoypes
ostream& operator<<(ostream&, Customer&);


//
// class Customer
// a single customer waiting in the bank teller line
class Customer
{
public:
	// constructors
	Customer (int at) {
		arrivalTime	= at;
		processTime = 2 + (rand() % 6);
	} 		

	Customer () : arrivalTime(0), processTime(0) { }
	
	// operations
	bool done () { 
		return --processTime == 0; 
	} 
	int arrival () { return arrivalTime; }
	
	int remain() { return processTime; }
	
	// order by arrival time 
	bool operator<(const Customer & c) 
		{ return arrivalTime < c.arrivalTime; }

	// no two customers are alike
	bool operator==(const Customer & c) { return false; }
	
	// friend ops
	friend ostream& operator<<(ostream&, Customer&);
	
protected:
	unsigned int arrivalTime; 
	unsigned int processTime;
};


//
// class Teller
// a teller servicing customers in a bank teller line
class Teller
{
public:
	
	
	Teller() {  // creating a new teller
		free = true;
	}
	
	bool isFree() // see if teller is free to work 
	{
		if (free) 
			return true; 
		

		if (customer.done()) {
			free = true;
			cout << "\t--Customer Leaves " << customer << endl;
		}
			
		
		return free;
	}
	
	void addCustomer(Customer & c) // start servicing customer
	{
		customer = c;

		free = false;
	}
	
protected:
	bool free;
	Customer customer;
};



int main() {
	int numberOfTellers = 6;
	int numberOfMinutes = 180;
	double totalWait = 0;
	int numberOfCustomers = 0;
	
	srand(time(NULL));
	
	vector<Teller> teller(numberOfTellers); 
	queue<Customer, list<Customer> > line;
	
	// maintain simulation time
	for (int time = 0; time < numberOfMinutes; time++) { 
		cout << "Time " << time << ":" << endl;
		
		// a new customer may arrive 10% of the time each minute
		if ((rand() % 10) < 9)	{ 
			Customer newCustomer(time); 
			line.push(newCustomer);
			cout << "\t++Customer Arrives " << newCustomer << endl;
		}	
		
		// check the status of each teller. If one is available and
		// someone is waiting then they should be helped.
		for (int i = 0; i < numberOfTellers; i++)
		{
			if (teller[i].isFree() & ! line.empty())
			{ 
				Customer frontCustomer = line.front();
				numberOfCustomers++;
				totalWait += (time - frontCustomer.arrival()); 
				
				cout << "\t**Customer serviced " << frontCustomer;
				cout << "by teller #" << i+1 << endl;
				
				teller[i].addCustomer(frontCustomer); 
				line.pop();					
			} 
		}
	}
	
	// output stats related to average waiting time
	cout << fixed << setprecision(2);
	cout << "\n\n";
	cout <<	"average wait: " << (totalWait / numberOfCustomers) << " minutes." << endl;
	
	cout << "\n";
	system("pause");
	return 0;
}



ostream& operator<<(ostream& os, Customer& c) {
	os << "{ a= " << c.arrival() << ", tr= " << c.remain() << "} ";		
	return os;
}

