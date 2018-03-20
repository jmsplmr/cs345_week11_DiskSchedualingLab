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

#define FORWARD true;
#define REVERSE false;

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
      requests.erase (std::remove (requests.begin (), requests.end (), requests.front()), requests.end ());

      auto it = requests.begin ();
      auto rit= requests.rbegin ();
      while (!requests.empty ())
      {
         if (it == requests.end () || rit == requests.rend ())
         {
            it = requests.begin ();
            rit = requests.rbegin ();
            direction = !direction;
         }

         if (direction) 
         {
            if (currentLocation > *it) 
            {
               ++it;
               continue;
            }
            currentLocation = *it;
            record ();
            it = requests.erase (std::remove (requests.begin (), requests.end (), *it), requests.end ());
         }
         else 
         {
            if (currentLocation < *rit)
            {
               ++rit;
               continue;
            }
            currentLocation = *rit;
            record ();
            std::advance (rit, 1);
            requests.erase( std::next(rit).base() );
         }
      }
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> requests;
   int start, numRequests;
   bool direction;
};
