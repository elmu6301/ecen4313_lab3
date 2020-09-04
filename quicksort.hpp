#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
/*
ECEN 4313: Concurrent Programming
Author: Elena Murray
Date: 8/30/2020
Lab 0: 
    
*/
#include <vector>

void quickPrint(); 
int partition(vector <int> &array, int sIndex, int eIndex); 
void quickSort(vector <int> &array); 
#endif