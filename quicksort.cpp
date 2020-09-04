/*
ECEN 4313: Concurrent Programming
Author: Elena Murray
Date: 8/30/2020
Lab 0: 
    
*/

//Library includes
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std; 

//Developer includes
#include "quicksort.hpp"

void quickPrint(){
    cout<<"Inside quicksort.cpp"<<endl; 
}

/*
    Partitions an array into a part less than a pivot (ending index)
    and another larger than the pivot. 
*/
int partition(vector <int> &array, int sIndex, int eIndex){
    //Select the last element to be the pivot
    int pivot = array[eIndex]; 
    //Create indecies to for partitioning
    int i = sIndex - 1; 
    int temp; 
    //loop through the array and partition it 
    for(int j = sIndex; j < eIndex; j++){
        if(array[j] < pivot){
            
            i++; 
            //swap the elements at i & j
            swap(array[i],array[j]); 
        }
    }

    //swap the pivot to the i + 1 spot
    swap(array[i+1], array[eIndex]); 
    return i+1; 
}


/*
    Recursive quick sort algorithm implementation. 
*/
void quickSortR(vector <int> &array, int sIndex, int eIndex){
    //check to make sure we are in bounds
    if(sIndex < eIndex){
        //Partition the array and get the partition index
        int pIndex = partition(array, sIndex, eIndex); 
        //Quick sort the partion before the partition index 
        quickSortR(array,sIndex, pIndex - 1); 
        //Quick sort the partition after the partition index
        quickSortR(array, pIndex + 1 , eIndex);
    }
}

/*
    Applies the quick sort algorithm to sort a given array
*/
void quickSort(vector <int> &array ){
    quickSortR(array, 0, array.size()-1); 
}