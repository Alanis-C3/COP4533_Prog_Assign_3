#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<char> backtracking(vector<vector<int>>& M, map<char, int> alphabet, vector<char> A, vector<char> B) {
    vector<char> optSequence; // store opt sequence to return

    // begin at bottom right corner of the M chart and traverse back to the start
    int i = A.size()-1;
    int j = B.size()-1;

    while (i>0 && j>0){

        if (A[i] == B[j] && M[i][j] == alphabet[A[i]] + M[i-1][j-1]){
            // found (i,j) where values are equivalent and the value was previous selected
            // add letter to the opt sequence **NOTE: creates inverse order
            optSequence.push_back(A[i]);

            // move pointers diagonally
            i=i-1;
            j=j-1;

        } else if (M[i-1][j] >= M[i][j-1]){
            // retracing this statement M[i][j] = max(M[i-1][j], M[i][j-1]) to determine direction of backtracking
            // **NOTE: if they are equal, we will choose the i path for simplicity
            i=i-1;

        } else {
            // M[i-1][j] < M[i][j-1] go towards j
            j=j-1;

        }
    }
    // reverse the sequence, since we did pushbacks in O(1) rather than inserts in O(n)
    reverse(optSequence.begin(), optSequence.end());

    // create an output file
    string fileName = "../outputs/example" + to_string(A.size()) + "out.txt";
    ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        cout << "Error in creating file!" << endl;
    }
    else {
        for (int k = 0; k<optSequence.size(); k++){
            outFile << optSequence[k] << " ";
        }
        outFile.close();
    }

    return optSequence;

}