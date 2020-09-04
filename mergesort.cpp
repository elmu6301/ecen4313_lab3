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
#include "mergesort.hpp"


/*

*/
void merge(vector <int> &array, vector <int> &lArray, vector <int> &rArray){
    array.clear(); 
    int lSize = lArray.size(); 
    int rSize = rArray.size(); 
    // int size = lSize + rSize; 

    int left = 0;  //index of left array
    int right = 0; //index of right array

    while(left < lSize && right < rSize){
        if(lArray[left] < rArray[right]){
            array.push_back(lArray[left]); 
            //array[index] = lArray[left]; 
            left++; 
        }else{
            array.push_back(rArray[right]);
            // printf("array[%d] = rArray[%d] = %d\n", index, right, rArray[right]); 
            right++; 
       }
 
    }
    //Copy remaing elements from the left array
    while(left < lSize){
        array.push_back(lArray[left]); 
        left++; 
    }

    //Copy remaing elements from the right array
    while(right < rSize){
        array.push_back(rArray[right]);
        right++; 
    }

}



void mergeSort(vector <int> &array){
    int size = array.size(); 
    if(size == 1){
        return; 
    }
    int lSize = size/2; 
    int rSize = size-lSize; 
    

    vector <int> lArray; 
    vector <int> rArray; 

    int index = 0; 
    
    //Create left array
    for(int i = 0; i < lSize; i++){
        lArray.push_back(array[index]);  
        index++; 
        
    }
   
    //Create right array
    for(int i = 0; i < rSize; i++){
        rArray.push_back(array[index]);   
        index++; 
    }
    
    mergeSort(lArray); 
    mergeSort(rArray); 
    merge(array, lArray, rArray); 


}