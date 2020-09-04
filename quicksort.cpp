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



int partition(vector <int> &array, int sIndex, int eIndex){
    //Select the last element to be the pivot
    int pivot = array[eIndex]; 
    // printf("\n  pivot = %d\n", pivot); 
    //Create indecies to for partitioning
    int i = sIndex - 1; 
    int temp; 
    //loop through the array and partition it 
    for(int j = sIndex; j < eIndex; j++){
        if(array[j] < pivot){
            
            i++; 
            // printf("swaping %d and %d when i = %d and j = %d\n", array[i], array[j], i , j); 
            //swap the elements at i & j
            swap(array[i],array[j]); 
        }
    }

    //swap the pivot to the i + 1 spot
    swap(array[i+1], array[eIndex]); 
    return i+1; 
}

void quickSortR(vector <int> &array, int sIndex, int eIndex){
    //check to make sure we are in bounds
    if(sIndex < eIndex){
        //Partition the array and get the partition index
        int pIndex = partition(array, sIndex, eIndex); 
        //Quick sort the partion before the partition index 
        // cout<<"sIndex = "<<sIndex<<" eIndex = "<<eIndex<<": ";  
        // for(int i = sIndex; i < eIndex; i++){
        //     printf("%d ",array[i]); 
        // }
        // cout<<endl; 
        quickSortR(array,sIndex, pIndex - 1); 
        //Quick sort the partition after the partition index
        quickSortR(array, pIndex + 1 , eIndex);
    }
}

void quickSort(vector <int> &array ){
    quickSortR(array, 0, array.size()-1); 
}