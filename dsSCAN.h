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
   DiskSchedulingSCAN (const ScheduleProblem & problem)
      : DiskSchedulingAlgorithm(problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
      requests = std::vector<int> {
         std::begin(problem.requests),
         std::end(problem.requests)
      };
      std::sort(requests.begin(), requests.end());
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
      int count = 0;
      int begin = 0;
      
      for (int i = 0; i < numRequests; ++i)
      {
         if (requests.at(i) > start)
         {
            begin = i;
            break;
         }
      }

      while (count <= requests.size()) {
         if (!direction)
         {
            int i = begin - 1;
            while (i >= 0)
            {
               currentLocation = requests[i];
               record ();
               ++count;
               --i;
            }
            currentLocation = 0;
            record ();
            ++count;
            direction = !direction;

         }
         else
         {
            int i = begin;
            while (i < requests.size())
            {
               currentLocation = requests[i];
               record ();
               ++count;
               ++i;
            }
            direction = !direction;
         }
      }
   }

   private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> requests;
   int start, numRequests;
   bool direction;
};
