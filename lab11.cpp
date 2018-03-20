/***********************************************************************
* Program:
*    Lab 11: Disk Scheduling Lab
*    <your instructor>, CS 345
* Author:
*    <your name>
* Summary: 
*    This is the driver program to exercise the disk scheduling algorithm
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
#include "ds.h"
using namespace std;

/*****************************************************************
 * MENU
 * Present the user with a menu from which he/she will select
 * the scheduling algorithm to use
 *****************************************************************/
DiskSchedulingType menu()
{
   // present a list of options
   cout << "Please select one of the following disk scheduling algorithms:\n";
   cout << "  1. First-Come, First-Served\n";
   cout << "  2. Shortest-Seek-Time-First\n";
   cout << "  3. SCAN (elevator) algorithm\n";
   cout << "  4. Circular SCAN\n";
   cout << "  5. LOOK\n";
   cout << "  6. Circular LOOK\n";

   // prompt the user for a selection
   assert(cin.good());
   int input = 1;
   cout << "> ";
   cin  >> input;
   while (cin.fail() || input < 1 || input > NUM_TYPES)
   {
      cout << "Error, invalid input. "
           << "Please select a number between 1 and " << NUM_TYPES << ": ";
      cin  >> input;
   }

   // return the type
   DiskSchedulingType array[] =
   { // 0      1      2      3     4       5       6
      FCFS,   FCFS,  SSTF,  SCAN, C_SCAN, LOOK, C_LOOK
   };
   assert(input >= 1 && input < sizeof(array)/sizeof(array[1]));
   assert(NUM_TYPES + 1 /*for the 0 slot*/ == sizeof(array)/sizeof(array[1]));
   return array[input];
}

/*********************************************************************
 * READ QUEUE
 * Prompt the user for a filename containing the disk locations
 * The file format consists of
 *    <number of locations>
 *    <increasing/decreasing>
 *    <the location where the head starts>
 *    <request 1, request2, request3, ...>
 * Example:
 *     200
 *     increasing
 *     53
 *     98, 183, 37, 122, 14, 124, 65, 67
 * There are 200 unique locations on this hard disk.
 * The head is currently moving in the increasing direction.
 * The head starts at 53 and the queue is 98, 183, etc.
 *********************************************************************/
bool readQueue(ScheduleProblem & problem)
{
   // prompt for filename
   char fileName[256];
   cout << "What is the filename of the disk queue file? ";
   cin  >> fileName;

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file '"
           << fileName
           << "', exiting.\n";
      return false;
   }

   //
   // Read the data from the disk
   //
   
   // how many unique sectors are there in the disk?
   fin >> problem.diskSize;

   // is the head moving in the increasing direction or decreasing direction?
   string direction;
   fin >> direction;
   problem.increasing = (direction == string("increasing"));
   
   // what is the location of the head when the simulation begins?
   fin >> problem.startLocation;

   // read in all the requests one at a time
   int request;
   while (fin >> request)
      problem.requests.push_back(request);
   
   // close the file    
   fin.close();
   return true;
}

/**********************************************************************
 * MAIN
 * This is where it all begins
 ***********************************************************************/
int main()
{
   // read the process info from a file
   ScheduleProblem problem;
   if (!readQueue(problem))
      return 1;

   // select the disk scheduling algorithm
   DiskSchedulingAlgorithm * p = dsFactory(menu(), problem);

   // run the simulation
   p->run();
            
   // display the results
   cout << *p;

   // make like a tree
   delete p;   
   return 0;
}
