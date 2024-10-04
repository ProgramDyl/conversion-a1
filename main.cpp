#include <iostream>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <regex>
#include "main.h"
#include "testing.h"


using namespace std;

// Validate file name + path
bool isValidFileName(const string &fileName) {
    //
    //Windows file name restrictions REGEX
    // Source: https://kb.unca.edu/kb/file-name-best-practices#:~:text=Windows%20can%20handle%20file%20names,things%20known%20as%20system%20variables.
    //
    const regex pattern(R"(^[^<>:"/\\|?*\x00-\x1F]+$)");
    return regex_match(fileName, pattern) && fileName.length() <= 259;
}

bool isValidPath(const string &path) {
    return (path.find('\\') != std::string::npos);
}

// Convert < and > symbols
void convertSymbols(ifstream &fin, ofstream &fout) {
    try {
        string line;
        while (getline(fin, line)) {
            if (!fout.is_open()) throw "Failed to open output file.";
            line = regex_replace(line, regex("<"), "&lt");
            line = regex_replace(line, regex(">"), "&gt");
            fout << line << endl;
        }
    } catch (const char *e) {
        cerr << "Error: " << e << endl;

        fin.fail();
        fout.fail();
        return;
    }
}

// Function:
void processFile(const string &inputFilePath, const string &outputFilePath) {

    // User-entered filepath
//   ifstream fin(inputFilePath);
//   ofstream fout(outputFilePath);

    // Hard-coded filepath
    ifstream fin(R"(C:\Users\dylan\NSCC\Semester 3\5-C++\assignments\conversion-a1\testing.cpp)");
    ofstream fout(R"(C:\Users\dylan\NSCC\Semester 3\5-C++\assignments\conversion-a1\output.html)");

    // Checks if files are not open, runs an error
    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Failed to open file(s)." << endl;
        return;
    }

    // Line 1 of output file -- opening pre tag
    fout << "<PRE>" << endl;
    try {
        convertSymbols(fin, fout);
        fin.close();
    // Last line of output file -- closing pre tag
        fout << "</PRE>" << endl;
        // Clear buffer to ensure data is written to disk
        // CITATION:
        fout.flush();
        fout.close();
    } catch (const exception &e) {
        // Catch processing errors
        cerr << "Error: " << e.what() << endl;

        // set input/output files to failed state
        fin.fail();
        fout.fail();
    }
} // end function

int main() {

    string inputFilePath, outputFilePath;

    // Get input file path
    cout << "Enter path of C++ source file (.cpp): ";
    cin >> inputFilePath;
    // Validate input file path
    while (!isValidFileName(inputFilePath)) {
        cout << "Invalid file path or name.\n Please enter a valid path: ";
        cin >> inputFilePath;
    }

    // Get output filepath
    cout << "Enter path for output HTML file (.html): ";
    cin >> outputFilePath;
    // Validate output file Path
    while (!isValidFileName(outputFilePath)) {
        cout << "Invalid file name. Please enter a valid file name: ";
        cin >> outputFilePath;
    }

    try {
        processFile(inputFilePath, outputFilePath);
    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }
    return 0;

}//end main


