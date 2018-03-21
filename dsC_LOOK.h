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
      requests = std::vector<int>{
         std::begin (problem.requests),
         std::end (problem.requests)
      };
      std::sort (requests.begin (), requests.end ());
      start = problem.startLocation;
      numRequests = problem.diskSize;
      direction = problem.increasing;
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
      int count = 0;
      int begin = 0;

      for (int i = 0; i < numRequests; ++i)
      {
         if (requests.at (i) > start)
         {
            begin = i;
            break;
         }
      }

      while (count <= requests.size ()) {
         if (!direction)
         {
            int i = begin - 1;
            while (i >= 0 && count <= requests.size ())
            {
               currentLocation = requests[i];
               record ();
               ++count;
               --i;
               if (i + 1 >= requests.size ())
               {
                  i = requests.size () - 1;
                  ++count;
               }
            }
         }
         else
         {
            int i = begin;
            while (i < requests.size () && count <= requests.size ())
            {
               currentLocation = requests[i];
               record ();
               ++count;
               ++i;
               if (i + 1 > requests.size ())
               {
                  i = 0;
                  ++count;
               }
            }
         }
      }
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> requests;
   int start, numRequests;
   bool direction;
};
