/***********************************************************************
* Component:
*    Disk Scheduling
* Author:
*    Br. Helfrich
* Summary: 
*    This is the base-class that enables various
*    disk scheduling algorithms
************************************************************************/

#ifndef DS_H
#define DS_H

#include <iostream>   // for the insertion operator
#include <cassert>    // because I am paranoid
#include <queue>      // the queue of disk requests
#include <list>       // for a history of all the track requests

enum DiskSchedulingType { FCFS,  SSTF,  SCAN, C_SCAN, LOOK, C_LOOK };
#define NUM_TYPES 6

/*******************************************************
 * SCHEDULE PROBLEM
 * All the data to represent one disk scheduling problem
 ******************************************************/
struct ScheduleProblem
{
   int             diskSize;         // how many locations in this problem
   int             startLocation;    // the start location
   bool            increasing;       // is the head moving up?
   std::list <int> requests;         // the collection of requests
};

/*****************************************************
 * DISK SCHEDULING ALGORITHM
 * The base-class for all the disk scheduling algorithms
 ****************************************************/
class DiskSchedulingAlgorithm
{
 public:
   //
   // The following three methods may need to be modified in the derrived class
   //
   
   // only constructor: one parameter for the details of the problem
   DiskSchedulingAlgorithm(const ScheduleProblem & problem) :
      headStarts(problem.startLocation),
      currentLocation(problem.startLocation),
      diskSize(problem.diskSize) {}

   // run the simulation. This needs to be implemented
   virtual void run() = 0;

   //  find the distance between points
   virtual int computeDistance(int pt)
   {
      return (pt > currentLocation) ?
         (pt - currentLocation) : (currentLocation - pt);
   }

   //
   // The next three methods are not to be changed
   //
   
   // display the status of the simulation
   friend std::ostream & operator <<
      (std::ostream & out, DiskSchedulingAlgorithm & rhs);

   // find the disk size
   int getDiskSize() const { return diskSize; }

   void resetHeadToStart() { currentLocation = headStarts; }
   
protected:
   // before calling record(), make sure to update currentLocation
   int currentLocation;         // the current location of the head

   // call this method every time currentLocation is updated
   void record()
   {
      history.push_back(currentLocation);
   }
 
private:
   std::list <int> history;  // the history of all track locations
   int headStarts;           // the place where the head starts
   int diskSize;             // number of locations on the disk
};

#include "dsFCFS.h"
#include "dsSSTF.h"
#include "dsSCAN.h"
#include "dsC_SCAN.h"
#include "dsLOOK.h"
#include "dsC_LOOK.h"


DiskSchedulingAlgorithm * dsFactory(DiskSchedulingType dst,
                                    const ScheduleProblem & problem);

#endif // DS_H
