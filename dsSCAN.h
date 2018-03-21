/***********************************************************************
* Component:
*    DISK SCHEDULING SCAN
* Author:
*    James Palmer
* Summary:
*    This is the DERRIVED class to implement the SCAN algorithm
************************************************************************/
#pragma once

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class

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
   DiskSchedulingSCAN (const ScheduleProblem & problem) :
      DiskSchedulingAlgorithm (problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
      requests = std::vector<int>{ std::begin (problem.requests), std::end (problem.requests) };
      std::sort (requests.begin (), requests.end ());
      start = problem.startLocation;
      numRequests = problem.diskSize;
      direction = problem.increasing;
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
      int spot = 0;
//      while(!requests.empty())
//      {
//         
//      }

   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> requests;
   int start, numRequests;
   bool direction;
};
