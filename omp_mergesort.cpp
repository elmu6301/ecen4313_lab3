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
#include <omp.h>

using namespace std; 

//Developer includes
#include "omp_mergesort.hpp"
#include "mergesort.hpp"


/*
	Splits a vector array into num_parts. 
*/
std::vector<std::vector<int>> split_vector_array(std::vector<int>array,int num_parts){ 
	
	//Create and allocate a vector of vectors
	std::vector<std::vector<int>> arrays; 
	arrays.resize(num_parts); 

	//Calculate the best size for each sub array
	float f_size = array.size()/(float)num_parts; 
	int size = array.size()/num_parts; 
	if(f_size - size >= 0.5 && (size+1)*(num_parts-1) < array.size()){//round up
		size++; 
	}
	//Split array into n-1 size chuncks
	int index = 0; 
	int array_index; 
	//Add size elements into the array for each array_index
	for(array_index = 0; array_index < num_parts-1; array_index++){
		//Generate endpoints
		auto start = std::next(array.begin(), array_index * size); 
		auto end = std::next(array.begin(), array_index*size + size); 
		//Allocate mem
		arrays[array_index].resize(size); 
		//Copy		
		std::copy(start, end, arrays[array_index].begin()); 

	}
	//Add the last array
	std::vector<int>::iterator start = std::next(array.begin(), array_index * size); 
	 
	std::vector<int>::iterator array_end = array.end(); 
	int rem = array.size() - array_index * size;
	arrays[array_index].resize(rem); 
	//Copy
	std::copy(start, array_end, arrays[array_index].begin()); 
	arrays[array_index].resize(rem); 
	return arrays; 
}

/*
    Runs a parallized mergesort on data using OpenMP where each thread gets a subarray 
	of data. Uses the default number of threads available unless that excedes the number 
	of elements in data. In that case the number of threads becomes the umber of elements in data
*/
void omp_mergesort(vector <int> &data){
    std::vector<std::vector<int>> split_arrays; 
    int nthreads = omp_get_max_threads(); //omp_get_thread_limit(); 
    
    //Place a limit on threads if there are more threads than pieces of data
    if(nthreads > data.size()){
        omp_set_num_threads(data.size());   
    }

    #pragma omp parallel default(none) shared(split_arrays, data, nthreads)
    {
        int tid = omp_get_thread_num(); 
        // printf("\nThread[%d] reporting for duty.", tid); 
        
        //One thread splits the array
        #pragma omp single
        {
            nthreads = omp_get_num_threads(); 
            // printf("\nThread[%d] splitting data into %d parts", tid, nthreads); 
            split_arrays = split_vector_array(data, nthreads); 
        }

        //run mergesort on chuck assigned by tid
        mergeSort(split_arrays[tid]); 

    }

    //Merge arrays
    std::vector<int> array; //stores the final array
	std::vector<int> left_array = split_arrays[0];  
    if(nthreads > 1){
        for(int i = 1; i < nthreads; i++){
            merge(array, left_array, split_arrays[i]);
			left_array = array; 
			array = {};  
		}
        
    }
    data = left_array; 

}
