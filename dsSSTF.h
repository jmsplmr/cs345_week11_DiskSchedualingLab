/***********************************************************************
* Component:
*    DISK SCHEDULING SSTF
* Author:
*    James Palmer
* Summary:
*    This is the DERRIVED class to implement the SSTF algorithm
************************************************************************/

#pragma once

#include <algorithm>
#include <list>
#include <iterator>
#include <iostream>

// vec is assumed to be sorted
inline int closest (const std::vector<int> vec, const int value)
{
   const auto closestVal = std::lower_bound (vec.begin (), vec.end (), value);

   if (closestVal == vec.end ())
   {
      if (vec.empty ()) return -1;
      return *vec.rbegin ();
   }
   return *closestVal;
}

inline void removeRequest (std::vector<int> & vec, const int request)
{
   vec.erase (std::remove (vec.begin (), vec.end (), request), vec.end ());
}

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
   DiskSchedulingSSTF (const ScheduleProblem & problem) :
      DiskSchedulingAlgorithm (problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
      requests = std::vector<int>{ std::begin (problem.requests), std::end (problem.requests) };
      std::sort (requests.begin (), requests.end ());
      start = problem.startLocation;
      numRequests = problem.diskSize;
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
      std::vector<int> orderedRequests;

      orderedRequests.push_back (start);
      removeRequest (requests, start);

      for (int i = 0; i < numRequests; ++i )
      {
         int closestRequest = closest (requests, orderedRequests[i]);
         if (closestRequest == -1) break;
         orderedRequests.push_back (closestRequest);
         removeRequest (requests, closestRequest);
         currentLocation = orderedRequests[i + 1];
         record ();
      }
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> requests;
   int start, numRequests;
};
