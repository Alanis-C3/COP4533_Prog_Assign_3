#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#pragma once
using namespace std;


int opt(map<char, int> alphabet, vector<char> A, vector<char> B, vector<vector<int>>& M, vector<pair<int, float>>& runtimes) {
    auto start = chrono::high_resolution_clock::now();
    //base cases of filling first row and col with 0
    for (int i = 0; i < A.size(); i++) {
        M[i][0] = 0;
    }
    for (int j = 0; j < B.size(); j++) {
        M[0][j] = 0;
    }

    // opt for loop
    for (int i = 1; i < A.size(); i++) {
        for (int j = 1; j < B.size(); j++) {
            if (A[i] == B[j]) {
                M[i][j] = max({ (alphabet[A[i]] + M[i - 1][j - 1]),
                    M[i - 1][j],
                    M[i][j-1]});
            }
            else {
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
            }
        }
    }

    // print M for testing
//    int maxVal = 0;
//    for (const auto& row : M)
//        for (int v : row)
//            if (v > maxVal) maxVal = v;
//
//    int width = static_cast<int>(std::to_string(maxVal).size()) + 2;
//
//    for (const auto& row : M) {
//        for (int v : row) {
//            std::cout << std::setw(width) << v;
//        }
//        std::cout << '\n';
//    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    float elasped = duration.count();
    int size = A.size() * B.size();
    runtimes.push_back(make_pair(size, elasped));
    return M[A.size()-1][B.size()-1];
}
