# PREPARE 11 : DISK SCHEDULING LAB

_Due Tuesday night at Midnight MST_

The second prepare activity of this week will be to write a program to implement the disk scheduling algorithms discussed in the chapter. Recall that there are for parts of the submission process: Code, Post, Review, and Submit.

## 1. Write your code - Due Tuesday

The first step in the coding projects is to write the code.

### A. Start with the provided code

Most of the code for this program is provided. You are only to implement the disk scheduling algorithms, not the user interface. The code is provided in the following location:

``` sh
/home/cs345/week11/
```

Here you will find several files:

- `makefile` : compile the files and create a TAR for submission and should not need to be changed.
- `lab11.cpp` : defines `main()` and a few user interface functions and will not need to be changed.
- `lab11.out` : an executable so you can see how it should work. This is mostly provided for testing purposes.
- `ds.h` : defines the `DiskSchedulilngAlgorithm` base-class from which you will author the various derived classes. There is also the `ScheduleProblem` structure which contains all the information about the problem which was read from the file. This will not need to be changed.
- `ds.cpp` : implements the interfaces for `DiskSchedulingtAlgorithm` and will not need to be changed.
- `dsFCFS.h` : contains an implementation for the simplest disk scheduling algorithm. This code is provided. You might want to use it as a reference when implementing the rest of the other algorithms.
- `dsSSTF.h` : a stub for the SSTF algorithm you will have to write.
- `dsSCAN.h` : a stub for the SCAN algorithm you will have to write.
- `dsC_SCAN.h` : a stub for the Circular-SCAN algorithm you will have to write.
- `dsLOOK.h` : a stub for the LOOK algorithm you will have to write.
- `dsC_LOOK.h` : a stub for the Circular-LOOK algorithm you will have to write.
- `test1.txt` : one data-set used in textbook for Figure 9.4, 9.7, and 9.8.
- `test2.txt` : another data-set used in textbook for Figure 9.5 and 9.5.
- `test3.txt` : another data-set.
- `test4.txt` : a complex data-set similar to what a real algorithm would be faced with.

Make sure you update the header in the makefile so it gets submitted to the correct location. The assignment this week will be called Lab 11, Disk Scheduling Lab

### B. Write the code

Implement five of the six scheduling algorithms as mentioned in the textbook (the first has been implemented as an example). These algorithms are:

- **SSTF**: Shortest-Seek-Time-First found in section 9.4.2 SSTF Scheduling on page 448-449
- **SCAN**: The elevator algorithm found in section 8.4.3 SCAN Scheduling on page 449-450
- **C-SCAN**: Circular SCAN found in section 9.4.4 C_SCAN Scheduling on page 450
- **LOOK**: The look-ahead variant of SCAN found in 9.4.5 LOOK Scheduling on page 451
- **C-LOOK**: The circular variant of LOOK also found in 9.4.5 LOOK Scheduling on page 451

Note that all algorithms will have to implement the constructor, the run() method, and add at least one local variable. A few algorithms will need to also implement computeDistance().

### C. Verify

The testBed for this assignment is:

``` sh
testBed cs345/lab11 lab11.tar
```

Please make sure your program runs without error.

### D. Style

Your program should be well-commented and free of any style-checker errors.

### E. Submit

You will submit this assignment now. Wednesday morning, you will be able to to post your code on the discussion board for review. You will need to submit it again after you have had your code reviewed on the discussion board.

## 2. Post your code - Due Wednesday

As with previous weeks, post your code for review. A few reminders:

- The subject of the post should be your full name.
- Post by midnight MST.
- Copy-Paste your code if it is small
- include an attachment if your code is big.

Please only post the relevant code. This means only past code that you actually wrote. This should be limited to the constructor, run(), and anything else you need.

## 3. Review - Due Friday

The details of the review component of the lab are described in Week 11 : Teach One Another.

## 4. Submit - Due Saturday

The details of the submit component of the lab are described in Week 11 : Ponder & Prove.