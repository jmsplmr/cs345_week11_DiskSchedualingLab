/***********************************************************************
* Component:
*    DISK SCHEDULING LOOK
* Author:
*    James Palmer
* Summary:
*    This is the DERRIVED class to implement the LOOK algorithm
************************************************************************/
#pragma once

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class

// using namespace std;

/****************************************************
 * SCAN
 * The LOOK (SCAN with lookahead) disk scheduling algorithm
 ***************************************************/
class DiskSchedulingLOOK : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SCAN
    *****************************************************/
   DiskSchedulingLOOK (const ScheduleProblem & problem) :
      DiskSchedulingAlgorithm (problem)
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
   void run ()
   {
      /////////////// YOUR CODE HERE ////////////////////
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
};
