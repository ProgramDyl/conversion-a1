#include <iostream>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <regex>
#include <stdexcept> // For library exceptions
#include "main.h"
#include "testing.h"

using namespace std;

// Custom exception class for demonstration purposes
class CustomException : public std::exception {
public:
    CustomException(const char* message) : msg_(message) {}

    const char* what() const throw() override { return msg_;}

private:
    const char* msg_;
};

// Struct for programmer-created exception
struct ExampleException {
    string message;
    ExampleException(const string& msg) : message(msg) {}
};

// Validate file name + path (Windows file name restrictions)
bool isValidFileName(const string &fileName) {
    const regex pattern(R"(^[^<>:"/\\|?*\x00-\x1F]+$)");
    return regex_match(fileName, pattern) && fileName.length() <= 259;
}

// Convert < and > symbols to HTML entities
void convertSymbols(ifstream &fin, ofstream &fout) {
    try {
//        cout << "convertSymbols function called" << endl; // Debug print
        string line;
        while (getline(fin, line)) {
            if (!fout.is_open()) throw CustomException("Failed to open output file.");
//            cout << "Processing line: " << line << endl; // Debug print
            line = regex_replace(line, regex("<"), "<");
            line = regex_replace(line, regex(">"), ">");
            fout << line << endl;
//            cout << "Written line to output file: " << line << endl; // Debug print
        }
    } catch (const CustomException& e) {
        cerr << "Custom Error: " << e.what() << endl;
        fin.fail();
        fout.fail();
        return;
    } catch (const ExampleException& e) {
        cerr << "Programmer Error: " << e.message << endl;
        fin.fail();
        fout.fail();
        return;
    } catch (const exception& e) {
        cerr << "Standard Error: " << e.what() << endl;
        fin.fail();
        fout.fail();
        return;
    }
}

// Close input and output files
void closeAllFiles(ifstream &fin, ofstream &fout) {
    if (fin.is_open()){
        fin.close();
    }
    if (fout.is_open()) {
        fout.close(); // Corrected this line
    }
}

// Process the input file and write to the output file
void processFile(const string &inputFilePath, const string &outputFilePath) {

    //User submitted values!
//    ifstream fin(inputFilePath);
//    ofstream fout(outputFilePath);

    // Hardcoded values (absolute path)
    ifstream fin(R"(C:\Users\dylan\NSCC\Semester 3\5-C++\assignments\conversion-a1\testing.cpp)");
    ofstream fout(R"(C:\Users\dylan\NSCC\Semester 3\5-C++\assignments\conversion-a1\output.html)");

    // Check if files are open, otherwise print error
    if (!fin.is_open()) {
        cerr << "Failed to open input file: " << inputFilePath << endl;
        return;
    }
    if (!fout.is_open()) {
        cerr << "Failed to open output file: " << outputFilePath << endl;
        return;
    }

    // Write opening <PRE> tag to output file
    fout << "<PRE>" << endl;
    try {
        cout << "Reading from input file: " << inputFilePath << endl;
        string line;
        while (getline(fin, line)) {
//            cout << "Read line: " << line << endl; // Debug print
        }
        fin.clear(); // Clear EOF flag
        fin.seekg(0); // Rewind to the beginning of the file
        convertSymbols(fin, fout);
        fin.close();
        fout << "</PRE>" << endl;
        fout.flush();
        closeAllFiles(fin, fout);
    } catch (const CustomException &e) {
        cerr << "Error: " << e.what() << endl;
        fin.fail();
        fout.fail();
    } catch (const ExampleException &e) {
        cerr << "Programmer Error: " << e.message << endl;
        fin.fail();
        fout.fail();
    } catch (const exception &e) {
        cerr << "Standard Error: " << e.what() << endl;
        fin.fail();
        fout.fail();
    }
}

int main() {
    try {
        string inputFilePath, outputFilePath;

        // Get input file path from user
        cout << "Enter path of C++ source file (.cpp): ";
        cin >> inputFilePath;
        // Debug print to verify input file path
//        cout << "Input file path: " << inputFilePath << endl;

        // Validate input file path
        while (!isValidFileName(inputFilePath)) {
            cout << "Invalid file path or name.\n Please enter a valid path: ";
            cin >> inputFilePath;
        }

        // Get output file path from user
        cout << "Enter path for output HTML file (.html): ";
        cin >> outputFilePath;
        // Debug print to verify output file path
//        cout << "Output file path: " << outputFilePath << endl;

        // Validate output file path
        while (!isValidFileName(outputFilePath)) {
            cout << "Invalid file name. Please enter a valid file name: ";
            cin >> outputFilePath;
        }

        // Process the input file and generate the output file
//        cout << "Calling processFile function" << endl; // Debug print
        processFile(inputFilePath, outputFilePath);
//        cout << "Finished processing file" << endl; // Debug print
        cout << "Test successful! Output written to file! " << std::endl;
        return 0;

    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }
}
