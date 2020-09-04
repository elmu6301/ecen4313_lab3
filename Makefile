# ECEN 4313: Concurrent Programming
# Author: Elena Murray
# Date: 8/30/2020
# Lab 0: 
# 	Makefile

#Executable
mysort: main.o mergesort.o quicksort.o
	g++ main.o mergesort.o quicksort.o -o mysort

#Object Files
main.o: main.cpp
	g++ -c main.cpp
mergesort.o: mergesort.cpp mergesort.hpp
	g++ -c mergesort.cpp 
quicksort.o: quicksort.cpp quicksort.hpp
	g++ -c quicksort.cpp 

#Clean
clean:
	rm *.o mysort