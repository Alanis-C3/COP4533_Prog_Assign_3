#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "OPT.CPP"
#include "Backtracking.cpp"
#include "Generator.cpp"
using namespace std;

int main() {
    vector<string> fileList = generator();

    for (string file : fileList){

        map<char, int> alphabet;
        // alphabet char to match char of string A and B for easier comparators of same type
        int K;
        ifstream inFile(file);
        if (!inFile.is_open()){
            cout << "Error opening file" << endl;
            return -1;
        }
        string strk;

        //get K length of alphabet
        getline(inFile, strk);
        K = stoi(strk);
        string temp;
        // get key and value of alphabet
        for (int i = 0; i < K; i++) {
            getline(inFile, temp);
            istringstream iss(temp);
            string tempkey;
            string tempvalue;
            iss >> tempkey >> tempvalue;
            char key = tempkey[0];
            alphabet[key] = stoi(tempvalue);
        }

        // get string A and B
        string strA;
        string strB;
        getline(inFile, strA);
        getline(inFile, strB);
        //convert to vector
        vector<char> A(strA.begin(), strA.end());
        vector<char> B(strB.begin(), strB.end());
        // insert empty char for DP algorithm when filling table
        A.insert(A.begin(), ' ');
        B.insert(B.begin(), ' ');

        cout << "K = " << K << endl;
        for (auto it: alphabet) {
            cout << it.first << " : " << it.second << endl;
        }
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < B.size(); i++) {
            cout << B[i] << " ";
        }
        cout << endl;

        //creating 2D vector for memorization
        // 2d vector creation source : https://www.geeksforgeeks.org/cpp/2d-vector-in-cpp-with-user-defined-size/
        vector<vector<int>> M(A.size(), vector<int>(B.size(), 0));

        int results = opt(alphabet, A, B, M);
        cout << "Maximum Value = " << results << endl;

        vector<char> optSequence = backtracking(M, alphabet, A, B);
        cout << "Optimal Sequence = [";
        for (int i = 0; i<optSequence.size(); i++){
            if (i+1 == optSequence.size()){
                cout << optSequence[i] << "] \n";
            } else {
                cout << optSequence[i] << ", ";
            }
        }
        cout << "\n";
    }


    return 0;
}