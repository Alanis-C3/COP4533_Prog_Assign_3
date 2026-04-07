# Contributors
Alanis Castillo 18144408 

Graciela Strand 80178234


# Compile-Build-Run Instructions
cd path\to\project

mkdir build

cd build

cmake ..

cmake --build .

.\main.exe


# Assumptions
* Data stored in a 2D array, where the first row and first column is all 0s
* Values span from 1-10
* String lengths for A and B equivalent, both >25 and <100
* The same subset of the alphabet is used for both string A and B

# **Written Component**
## **Question 1: Empirical Comparison**  
Use at least 10 nontrivial input files (i.e., contain strings of length at least 25). Graph the runtime of the 10 files.

![runtime](https://github.com/user-attachments/assets/0f19c152-236b-4330-a9d1-03b018f8433e)


## **Question 2: Recurrence Equation**  
Give a recurrence that is the basis of a dynamic programming algorithm to compute the HVLCS of strings A and B. You must provide the appropriate base cases, and explain why your recurrence is correct.

OPT(i, j) = {
  * 0, if i=0 or j = 0
  * max( A[i] + OPT(i-1, j-1), OPT(i, j-1), OPT(i-1, j) ), if A[i] == B[j]
  * max( OPT(i, j-1), OPT(i-1, j) ), otherwise
}

In this recurrence equation, we start with the base case, where i = 0 or j = 0. This establishes the row and column of zeros boardering the table, also haulting the recursion.
Next, we have a case where there's a match (value of A at i equals the value of B at j). The algorithm branches, deciding if choosing this value and proceding would be best, or decrementing either pointer would be best.
Finally, if the values don't match at the two indicies, the algorithm choses between the two branching paths (decrementing i or decrementing j).

## **Question 3: Prove OPTFF is Optimal**  
Give pseudocode of an algorithm to compute the length of the HVLCS of given strings A and B. What is the runtime of your algorithm?

* Input K, X1 v 1 …… xk vk, A (a1, a2 … aI) B (b1, b2, … bJ)
* Create 2D array M 
* For i = 0 to I
  * M[i , 0] = 0
* For j = 0 to J
  * M[0, j] = 0
* For i = 1 to I
  * For j= 1 to J
    * If A[i] = B[j] // case 1
      * M[i,j] = max(v(A[i]) + M[i-1,j-1], M[i, j-1], M[i-1, j])
    * Else //case 2 and 3
      * M[i,j] = max( M[i, j-1], M[i-1, j])
* Return M[I,J]

The runtime of the algorithm is O(I J) because the for next for loops result in I * J runtime and they both iterate though the respective value.
