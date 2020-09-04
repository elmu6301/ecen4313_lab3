ECEN 4313 Concurrent Programming
LAB 0 Write Up
Elena Murray

1. Overview:
    The code is separated into three parts: main, mergesort, and quicksort. 
    See the file description below for more details. 

2. File Description
    a. main:
        Parses in the input from the command line arguments, reads in data from the input
        source, determines which algorithm to run on the data, and outputs the sorted data
        to the provided output file. 
    b. mergesort: 
        Contains all functions that implement the merge sort algorithm. 
    c. quicksort: 
        Contains all functions that implement the quick sort algorithm. 
    d. Makefile: 
        The Makefile used for compiling and creating the executable.
    e. input.txt, output.txt, output_soln.txt: 
        Files used for testing purposes. 

3. Compliation Instruction: 
    1. Run the Makefile using: make 
        This will generate all object files and the executable. 
    2. Clean the project using: make clean

4. Execution Instruction:
    1. Print name
        ./mysort --name
    2. Run the merge sort algorithm:
        ./mysort your_input_file.txt -o your_output_file.txt --alg=merge
    3. Run the quick sort algorithm:
        ./mysort your_input_file.txt -o your_output_file.txt --alg=quick

5. Known Bugs/Assumptions:
    1. All files must be text files.
    2. Only "merge" or "quick" can be passed in for alg, otherwise the program exits.
    3. There must be an input and output file to run an algorithm, otherwise the program exits.

6. Testing: 
    a. mergeSort:
        shuf -i1-100 -n50 > input.txt
        ./mysort input.txt -o output.txt --alg=merge
        sort -n input.txt > output_soln.txt
        cmp --silent output.txt output_soln.txt && echo "Same!" || echo "Different!"
    b. quickSort: 
        shuf -i1-100 -n50 > input.txt
        ./mysort input.txt -o output.txt --alg=quick
        sort -n input.txt > output_soln.txt
        cmp --silent output.txt output_soln.txt && echo "Same!" || echo "Different!"