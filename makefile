###############################################################
# Program:
#     Lab 11, Disk Scheduling Lab
#     <your instructor>, CS345
# Author:
#     <your name here>
# Summary:
#     <put a description here>
# Time:
#     <how long did it take to complete this program?>
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab11.o ds.o
	g++ -o a.out lab11.o ds.o
	tar -cf lab11.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab11.o: lab11.cpp ds.h
	g++ -c lab11.cpp

ds.o: ds*.h ds.cpp ds.h
	g++ -c ds.cpp

