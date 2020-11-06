ECEN 4313 Concurrent Programming
LAB 3 Write Up
Elena Murray

1. Overview:
    a. Code Organization
        The code is separated into three parts: main, mergesort, and omp_mergesort. 
        I decided to have a separate OpenMP parallized mergesort becuase I wanted to keep the
        structure similar to lab 1. Maintaining a similar structure to lab 1 helped me figure out
        I wanted to parallize mergesort using OpenMP. This also allowed for easier reuse of
        my mergesort code from lab 0. 
    b. Parallelization Strategy: 
        Because OpenMP essentially uses a fork join model, I was able to not only reuse the same 
        structure, but also reuse the same approach. Like in lab 1, I assigned each thread a partion
        of the overall data and had it sort that data chunk. After the parallel section, I merged all
        the individual arrays one by one.

        The area that I struggled translating from pthreads to OpenMP was the partitioning of the
        data array, which relied on the number of threads. In previous labs the number of threads 
        used was an explicit parameter that was known before Parallelization. This was not the case
        with OpenMp. To get around this, I used a omp single block to divide the data array. I used this
        over master because of the implicit barrier which prevented other threads from working on nonexistent
        chuncks of data. Additionally, since the thread partition is known before run-time, all threads needed
        access to the data array which is why it is shared. The partitioned data (split_array) is an array of 
        vectors and each index corresponded to a thread id. Since each thread only accessed index matching their
        thread id, I could share split_array between all threads with out mutual exclusion or syncronization.

        One issue that I ran into this lab occurred when there were more threads than data elements. This case 
        conflicted with my approach of assigning every thread a chunk of data. To fix this, I limited the number 
        of threads to the number of elements using omp_set_num_threads. 
    c. Ease of Parallelization: 
        For the most part, OpenMP was a lot easier for me to parallize versus pthreads. One reason is that it handled forking
        and joining threads, implementing barriers, and protecting some variables for me. I also think that it was easier
        because I had already parallized this problem before: I was able to reuse my approach from previous labs. The 
        only issue I had was figuring out how many threads were used and paritioning the data array. With pthreads the number 
        of threads was more accessible which meant I could partition before the parallel sections. Overall, this lab took me about 
        3 - 4 hours, while labs using pthreads took a lot longer (particularly lab 1). I also found clearer documentation OpenMP. 
        Side note, IBM has a great API on OpenMp and it was especially useful for understanding run time functions. 

2. File Description
    a. main:
        Parses in the input from the command line arguments, reads in data from the input
        source, calls the openMP parallized mergsort, and outputs the sorted data
        to the provided output file. 
    b. mergesort: 
        Contains all functions that implement the merge sort algorithm. 
    c. omp_mergesort: 
        Contains the parallized version of merge sort using openMP. 
    d. Makefile: 
        The Makefile used for compiling and creating the executable.
    e. /test_files: 
        Files that contain test cases and their solutions. Used for the mysort_script.shuf
        testing. 
    f. mysort_script.sh: 
        Script used to test ./mysort against various test cases.  

3. Compliation Instruction: 
    1. Run the Makefile using: make 
        This will generate all object files and the executable. 
    2. Clean the project using: make clean

4. Execution Instruction:
    1. Print name
        ./mysort --name
    2. Run the merge sort algorithm:
        ./mysort your_input_file.txt -o your_output_file.txt

5. Known Bugs/Assumptions:
    1. All files must be text files.
    2. If there are more data elements than number of threads, the number of threads will be
       to set to the number data elements. 
    3. There must be an input and output file to run an algorithm, otherwise the program exits.

6. Testing: 
    a. Single test case:
        shuf -i1-100 -n50 > input.txt
        ./mysort input.txt -o output.txt
        sort -n input.txt > output_soln.txt
        cmp --silent output.txt output_soln.txt && echo "Same!" || echo "Different!"
    b. mysort_script.sh