#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

const string FILENAME = "answer.h";

void codeCheck(string filename=FILENAME, int n=0) {
    // :param: n: number of line to be ignored
    const string fbdKw[] = {
            "include"
    };
    const int nFbdKw = 1;
    ifstream ifs(filename);
    if (ifs.fail()) {
        cout << "No such file: " << filename << endl;
        throw std::runtime_error("Check n first line gets Error");
    }
    string line;
    for (int i = 0; i < n; ++i) {
        getline(ifs, line);
    }

    stringstream ss;
    string word;
    while (getline(ifs, line)
            ) {
        ss = stringstream(line);
        bool cmtLine = false;
        bool cmtBlock = false;
//        bool gotoNextLine = false;

        while (ss >> word) {
            // ignore "//"
            if (word.length() >= 2 && word.substr(0, 2) == "//") {
                cmtLine = true;
            }
                // ignore "/*"
            else if (word.length() >= 2 && word.substr(0, 2) == "/*") {
                cmtBlock = true;
            }

            if (cmtLine) {
                // Go to next line
                break;
            }
            else if (cmtBlock) {
                bool findEnclosedStr = false; // check if find "*/"
                while (ss >> word) { // if this line has remaining words
                    if (word.length() >= 2 && word.substr(word.length()-2, 2) == "*/") {
                        findEnclosedStr = true;
                        break;
                    }
                }
                // read all line but does not find "*/"
                // -> find in next lines
                if (!findEnclosedStr) {
                    bool stopReadline = false;
                    while ((!stopReadline) && getline(ifs, line)) {
                        ss = stringstream(line);
                        while (ss >> word) {
                            if (word.length() >= 2 && word.substr(word.length()-2, 2) == "*/") {
                                // found enclosed string
                                stopReadline = true;
                                break;
                            }
                        }
                    }
                }
            }
            else {
                // actual checking words
                for (int i = 0; i < nFbdKw; ++i) {
                    if (word.find(fbdKw[i]) != string::npos) {
                        cout << "Violate the forbidden words: "
                             << fbdKw[i] << endl;
                        throw runtime_error("Runtime Exception.");
                    }
                }
            }
        }
    }
}