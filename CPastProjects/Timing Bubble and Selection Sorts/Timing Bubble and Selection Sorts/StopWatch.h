/*
  The following code was inspired by http://cplus.about.com/od/howtodothingsi2/a/timing.htm
  But has been gutted to work with the standard C++ library instead of Windows libraries.
   Written By Charles R. Hardnett (c) 2011
*/

#ifndef StopWatch
#define StopWatch

#include <ctime>


// holds the start and stop time for the timer
typedef struct {
    clock_t start; 
    clock_t stop;
} stopWatch;


class CStopWatch
{
private:
	stopWatch timer;    // start and stop time for the stop watch
	bool timing;		// determines if timing is in progress
public:
	CStopWatch(void);				// initializes the timer
	void startTimer(void);			// starts the timer
	void stopTimer(void);			// stops the timer
	double getElapsedTime(void);	// gets the time last recorded
};

#endif StopWatch