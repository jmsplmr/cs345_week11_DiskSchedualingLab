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
      int i;
      int temp;
      int numLocations = requests.size();
      int * reqs = new int [numLocations];
      int disk = start; //loc of head
      int dloc; //loc of disk in array
      for (i = 0; i < numLocations; i++)
      {
         reqs[i] = requests.at(i);
      }
      reqs[numLocations] = disk;
      numLocations = numLocations + 1;
      for (i = 0; i < numLocations; i++) // sorting disk locations
      {
         for (int j = i; j < numLocations; j++)
         {
            if (reqs[i] > reqs[j])
            {
               temp = reqs[i];
               reqs[i] = reqs[j];
               reqs[j] = temp;
            }
         }
      }
      for (i = 0; i < numLocations; i++) // to find loc of disc in array
      {
         if (disk == reqs[i])
         {
            dloc = i;
            break;
         }
      }
      for (i = dloc; i >= 0; i--)
      {
         currentLocation = reqs[i];
         record();
      }
      currentLocation = 0;
      record();
      for (i = dloc + 1; i < numLocations; i++)
      {
         currentLocation = reqs[i];
         record();
      }

      delete[] reqs;
   }

   private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> requests;
   int start, numRequests;
   bool direction;
};
