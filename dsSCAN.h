/***********************************************************************
* Component:
*    DISK SCHEDULING SCAN
* Author:
*    <your name here>
* Summary: 
*    This is the DERRIVED class to implement the SCAN algorithm
************************************************************************/

#ifndef DS_SCAN
#define DS_SCAN

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class

// using namespace std;

/****************************************************
 * SCAN
 * The SCAN (aka Elevator) disk scheduling algorithm
 ***************************************************/
class DiskSchedulingSCAN : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SCAN
    *****************************************************/
   DiskSchedulingSCAN(const ScheduleProblem & problem) :
             DiskSchedulingAlgorithm(problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
   }

   /****************************************************
    * RUN
    * Implement the algorithm here. This function will only
    * be called once and will need to complete the entire
    * simulation.
    *
    * Each time a disk request is made by setting currentLocation,
    * call record() to save that.
    ***************************************************/         
   void run()
   {
      /////////////// YOUR CODE HERE ////////////////////
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
};

#endif // DS_SCAN
