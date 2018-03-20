/***********************************************************************
* Component:
*    DISK SCHEDULING C-SCAN
* Author:
*    <your name here>
* Summary: 
*    This is the DERRIVED class to implement the C-SCAN algorithm
************************************************************************/

#ifndef DS_C_SCAN
#define DS_C_SCAN

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class

//using namespace std;

/****************************************************
 * C-SCAN
 * The C-SCAN disk scheduling algorithm
 ***************************************************/
class DiskSchedulingC_SCAN : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to C-SCAN
    *****************************************************/
   DiskSchedulingC_SCAN(const ScheduleProblem & problem) :
     DiskSchedulingAlgorithm(problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
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
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
};

#endif // DS_C_SCAN
