###############################################################
# Program:
#     Lab 11, Disk Scheduling Lab
#     Brother Ball, CS345
# Author:
#     James Palmer
# Summary:
#     // TODO Fill out this summary
# Time:
#     // TODO Fill out time to complete
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab11.o ds.o
	g++ -std=c++0x -o a.out lab11.o ds.o
	tar -cf lab11.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab11.o: lab11.cpp ds.h
	g++ -std=c++0x -c lab11.cpp

ds.o: ds*.h ds.cpp ds.h
	g++ -std=c++0x -c ds.cpp

clean:
	rm -f *.o
