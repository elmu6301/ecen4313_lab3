# ECEN 4313: Concurrent Programming
# Author: Elena Murray
# Date: 8/30/2020
# Lab 0: 
# 	Makefile

#Executable
mysort: main.o mergesort.o  omp_mergesort.o
	g++ main.o mergesort.o omp_mergesort.o -fopenmp -o mysort

#Object Files
main.o: main.cpp
	g++ -c main.cpp
mergesort.o: mergesort.cpp mergesort.hpp
	g++ -c mergesort.cpp 
quicksort.o: quicksort.cpp quicksort.hpp
	g++ -c quicksort.cpp 
omp_mergesort.o: omp_mergesort.cpp omp_mergesort.hpp
	g++ -c omp_mergesort.cpp -fopenmp
#Clean
clean:
	rm *.o mysort