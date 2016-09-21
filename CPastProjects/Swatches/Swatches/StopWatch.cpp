/*
  The following code was inspired by http://cplus.about.com/od/howtodothingsi2/a/timing.htm
  But has been gutted to work with the standard C++ library instead of Windows libraries.
  Written By Charles R. Hardnett (c) 2011
*/

#include "StopWatch.h"
#include <ctime>			// standard high resolution timer
#include <iostream>


// constructor
CStopWatch::CStopWatch(){
	timer.start=0;
	timer.stop=0;
	timing = false;
}

// starts the stop watch
void CStopWatch::startTimer( ) {

	// only start if not currently timing
    if (!timing) {
		timer.start=clock();
	    timing = true;
	} else {
		std::cerr << "timer is already started" << std::endl;
		exit(-1);
	}
}

void CStopWatch::stopTimer( ) {

   // don't allow the timer to be stopped if not currently timing
   if (timing) {
	   timer.stop=clock();
	   timing = false;
   } else {
	   std::cerr << "timer has not been started" << std::endl;
	   exit(-1);
   }
}

// returns the last recorded time from start to stop
double CStopWatch::getElapsedTime() {

	// CLOCKS_PER_SEC is the frequency of the high res timer (set in library)
	return (double)(timer.stop - timer.start) / CLOCKS_PER_SEC * 1000;
}

