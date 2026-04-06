#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

vector<string> generator() {
    vector<string> fileList;
    string fileName = "";
    mt19937 gen(random_device{}());

    for (int i=0; i<12; i++){ // create 12 example input files
        uniform_int_distribution stringlen(25, 100);
        int strlen = stringlen(gen);
        uniform_int_distribution alphabetlen(5, 26);
        int alphalen = alphabetlen(gen);

        // write to input the file
        fileName = "../inputs/example" + to_string(strlen) + "in.txt"; // for strlen = 62, file name is example62in.txt
        ofstream outFile(fileName);
        if (!outFile.is_open()){
            cout << "Error in creating file!" << endl;
        } else {
            fileList.push_back(fileName); // add file name to the list

            // start by writing the quantity of available letters
            outFile << to_string(alphalen) << "\n";

            // print out alphabet with random weights
            uniform_int_distribution weight(1,10);
            for (int j=0; j<alphalen; j++){
                int lweight = weight(gen);
                char letter = 'a' + j;
                outFile << letter << " " << to_string(lweight) << "\n";
            }
            // create random strings using the available letters
            uniform_int_distribution<int> letter(0, alphalen - 1);
            for (int k = 0; k < 2; k++) {      // loop through twice, once for A and once for B
                for (int c = 0; c < strlen; c++) { // loop through length (>25), picking random letter by random letter
                    char chosenletter = 'a' + letter(gen);
                    outFile << chosenletter;
                }
                outFile << "\n";
            }
        }
        outFile.close(); // close the file and start over with the next one
    }


    return fileList; // return list of files so they can be parsed in main, and processed with OPT/backtracking
}