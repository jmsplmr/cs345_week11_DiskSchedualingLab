/***********************************************************************
* Component:
*    DISK SCHEDULING FCFS
* Author:
*    James Palmer
* Summary:
*    This is the DERRIVED class to implement the FCFS algorithm
************************************************************************/

#pragma once

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class
#include <list>   // for LIST, the member variable

/****************************************************
 * FCFS
 * The first-come, first-setve disk scheduling algorithm
 ***************************************************/
class DiskSchedulingFCFS : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to FCFS
    *****************************************************/
   DiskSchedulingFCFS (const ScheduleProblem & problem) :
      DiskSchedulingAlgorithm (problem)
   {
      /////////////// YOUR CODE HERE ////////////////////

      // make a copy of the list of disk requests which will be
      // consumed as the simulation runs
      requests = problem.requests;
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

      // loop through all the requests and move to that location
      std::list <int> ::iterator it;
      for (it = requests.begin (); it != requests.end (); ++it)
      {
         currentLocation = *it;
         record ();
      }

      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::list <int> requests;      // a copy of the list of disk requests
};
