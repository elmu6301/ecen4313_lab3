/*
ECEN 4313: Concurrent Programming
Author: Elena Murray
Date: 8/30/2020
Lab 0: 

*/

//Library includes
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <vector>
#include <string>
#include <exception>

using namespace std; 

//Developer includes
#include "mergesort.hpp"
#include "quicksort.hpp"

//Global Variables
string my_name = "Elena Murray"; //full name 
string name_opt = "--name"; 
string out_opt = "-o"; 
string merge_opt = "merge"; 
string quick_opt = "quick"; 

//print function
void printArray(int array[], int size){
    //cout<<"Inside print array"<<endl; 
    for(int i = 0; i < size; i++){
        printf("\t%d\n", array[i]); 
    }
}

void printVector(vector <int> array){
    //cout<<"Inside print array"<<endl; 
    for(int i = 0; i < array.size(); i++){
        printf("\t%d\n", array[i]); 
    }
}


void testQuickSort(){
    vector <int> array{10, 80, 30, 90, 40, 50, 70}; 
    quickSort(array); 
    cout <<"Array after sorting:"<<endl ; 
    printVector(array); 

}

void printUsage(){
    printf("mysort [--name] [sourcefile.txt] [-o outfile.txt] [--alg=<merge,quick>]\n");
}


//main function
int main(int argc, char* argv[]){ 
    //variable for parsing the command line
    string srcFile; //stores the name of the file to read from 
    string outFile; //stores the name of the file to output the data
    string alg; //stores the algorithm to be used either q (quicksort) or m (mergesort) 
    char opt; //stores the option value
    
    static struct option longopt[] = {
        {"name", no_argument, NULL, 'n'},// --name
        {"o", required_argument, NULL, 'o'}, // output file
        {"alg", required_argument, NULL, 'a'} // algorithm

    }; 
    char * optstr = "no:a:"; 
    //Get the source file
    if(argc > 1){
        srcFile = argv[1];  
    }
    //Parse the rest of the command line
    while((opt = getopt_long(argc, argv, optstr, longopt, NULL))!=-1){
        // cout<<opt<<endl; 
        switch(opt){
            case 'n': 
                cout<<my_name<<endl; 
                return 1; 
                break; 
            case 'o':
                outFile = optarg; 
                break; 
            case 'a':
                alg = optarg; 
                break; 
        }
    }
    //Check options to make sure that they are valid
    if(srcFile.rfind(".txt")==string::npos){
        cout<<"The source file: "<<srcFile<<" is not a .txt file."<<endl; 
        printUsage(); 
        return -1;
    }

    if(outFile.rfind(".txt")==string::npos){
        cout<<"The output file: "<<outFile<<" is not a .txt file."<<endl; 
        printUsage(); 
        return -2;
    }   

    if(alg.compare("merge")!= 0 && alg.compare("quick")!=0 ){
        cout<<"An invalid algorithm was entered."<<endl; 
        printUsage();
        return -3; 
    }
    
    
    //Open sourcefile
    ifstream fileIn;  
    fileIn.open(srcFile); 
    if(!fileIn){
        cout<<"Unable to open the file: "<<srcFile<<endl; 
        return -4; 
    }

    //Read in the input
    vector <int> data; 
    string line; 
    int el; 
    while(getline(fileIn, line)){
        try{
            el = stoi(line); 
            data.push_back(el); 
        }catch(exception & e){
            cout<<"Error: invalid data detected."<<endl; 
            fileIn.close(); 
            return -4; 
        }
    }
    fileIn.close(); 
   

     //TODO Run sorting algorithm HERE
       cout<<"Running the "<<alg<<"Sort algorithm with input file: "
        <<srcFile<<" and outputting to: "<<outFile<<endl; 
    if(alg.compare("quick")==0){
        quickSort(data); 
    }else{
        mergeSort(data);  
    }
    //Output sorted data to output file
    ofstream fileOut; 
    fileOut.open(outFile); 
     if(!fileOut){
        cout<<"Unable to open the file: "<<outFile<<endl; 
        return -4; 
    }

    for(int i = 0; i < data.size(); i++){
        fileOut<<data[i]<<endl; 
    }

    fileOut.close(); 
   
}


