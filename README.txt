ECEN 4313 Concurrent Programming
LAB 0 Write Up
Elena Murray

1. Overview
2. File Description
3. Compliation Instruction
4. Execution Instruction
5. Known Bugs

6. Testing 
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