/***********************************************************************
* Component:
*    Disk Scheduling
* Author:
*    Br. Helfrich
* Summary:
*    This will implement a few helper functions.
*
*    Note that you do not need to change this to any capacity
************************************************************************/

#include <iostream>   // for the insertion operator
#include <iomanip>    // for SETW
#include <cassert>    // because I am paranoid
#include "ds.h"       // for the DiskSchedulingAlgorithm class definition

/**********************************************
 * DISPLAY
 * Display the history of all the executions
 **********************************************/
std::ostream & operator << (std::ostream & out, DiskSchedulingAlgorithm & rhs)
{
   int num = rhs.history.size ();
   int totalTraversed = 0;

   std::list <int> ::const_iterator it;

   // header
   out << "Start   Finish   Distance\n";

   // display the distance traveled
   rhs.resetHeadToStart ();
   for (it = rhs.history.begin (); it != rhs.history.end (); ++it)
   {
      out << std::setw (4) << rhs.currentLocation
         << " --->"
         << std::setw (4) << *it;

      int distanceTraveled = rhs.computeDistance (*it);
      rhs.currentLocation = *it;
      totalTraversed += distanceTraveled;

      out << std::setw (9) << distanceTraveled << std::endl;
   }
   out << std::endl;

   // display the summary
   out.setf (std::ios::fixed | std::ios::showpoint);
   out.precision (1);
   out << "Average: " << ((float)totalTraversed / (float)num) << std::endl;

   return out;
}

/*****************************************************
 * Disk Scheduling FACTORY
 * Create an instance of a Disk Scheduling Algorithm that implements
 * a specific algorithm
 *****************************************************/
DiskSchedulingAlgorithm * dsFactory (DiskSchedulingType dst,
   const ScheduleProblem & problem)
{
   switch (dst)
   {
   case FCFS:
      return new DiskSchedulingFCFS (problem);
   case SSTF:
      return new DiskSchedulingSSTF (problem);
   case SCAN:
      return new DiskSchedulingSCAN (problem);
   case C_SCAN:
      return new DiskSchedulingC_SCAN (problem);
   case LOOK:
      return new DiskSchedulingLOOK (problem);
   case C_LOOK:
      return new DiskSchedulingC_LOOK (problem);
   }

   assert (false);
   return new DiskSchedulingFCFS (problem);
}