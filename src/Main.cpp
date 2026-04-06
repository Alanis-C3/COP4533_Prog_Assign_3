#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {

    map<char, int> alphabet;
    // alphabet char to match char of string A and B for easier comparators of same type
    int K;
    ifstream inFile("../inputs/example1.txt");
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


    return 0;
}