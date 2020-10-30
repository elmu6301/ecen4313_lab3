#!/bin/bash

#Test against 
while getopts a: flag
do 
    case "${flag}" in
        a) alg=${OPTARG};;  
    esac
done

#Files
test_out="test_files/output.txt"

test_res=('SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS' 'SUCCESS')
test_case=1
n=16
i=0
while [ $i -lt $n ]
do
        
    echo "Test Case ${test_case}-> -t ${threads}"
    test_in="test_files/test_case$test_case.txt"; 
    test_sol="test_files/test_soln$test_case.txt"; 
    

    rm ${test_out}

    ./mysort ${test_in} -o ${test_out}
    
    cmp ${test_out} ${test_sol} && test_res[$i]="SUCCESS" || test_res[$i]="FAILED"
    
    test_case=$((test_case + 1))
    i=$((i + 1))
    echo 
done




echo "Results:"
i=0
while [ $i -lt $n ]
do
    p=$((i + 1))
    echo "TEST[$p]--> ${test_res[$i]}"
    i=$((i + 1))
done