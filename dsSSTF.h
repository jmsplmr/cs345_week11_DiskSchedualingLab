/***********************************************************************
* Component:
*    DISK SCHEDULING SSTF
* Author:
*    <your name here>
* Summary: 
*    This is the DERRIVED class to implement the SSTF algorithm
************************************************************************/

#ifndef DS_SSTF
#define DS_SSTF

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class

// using namespace std;

/****************************************************
 * SSTF
 * The Sortest-Seek-Time-First disk scheduling algorithm
 ***************************************************/
class DiskSchedulingSSTF : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SSTF
    *****************************************************/
   DiskSchedulingSSTF(const ScheduleProblem & problem) :
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

#endif // DS_SSTF
