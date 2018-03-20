/***********************************************************************
* Component:
*    DISK SCHEDULING C-LOOK
* Author:
*    James Palmer
* Summary: 
*    This is the DERRIVED class to implement the C-LOOK algorithm
************************************************************************/

#pragma once

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class

//using namespace std;

/****************************************************
 * C-LOOK
 * The C-LOOK disk scheduling algorithm
 ***************************************************/
class DiskSchedulingC_LOOK : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to C-LOOK
    *****************************************************/
   DiskSchedulingC_LOOK(const ScheduleProblem & problem) :
     DiskSchedulingAlgorithm(problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
   }

   /****************************************************
    * RUN
    * Implement the algorithm here. This function will only
    * be called once and will need to complete the entire
    * simulation. With file location, send the results to record().
    ***************************************************/
   void run()
   {
      /////////////// YOUR CODE HERE ////////////////////

      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
};
