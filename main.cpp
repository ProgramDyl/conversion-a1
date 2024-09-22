#include <iostream>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <regex>


// TODO: - research criteria for valid Windows filename (running on mac is requirement)



// Validate file name + path
bool isValidFileName(const std::string& fileName) {
    //
    //Windows file name restrictions REGEX
    // Source: https://kb.unca.edu/kb/file-name-best-practices#:~:text=Windows%20can%20handle%20file%20names,things%20known%20as%20system%20variables.
    //
    const std::regex pattern(R"(^[^<>:"/\\|?*\x00-\x1F]+$)");
    return std::regex_match(fileName, pattern) && fileName.length() <= 259;
}

bool isValidPath(const std::string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

// Convert < and > symbols
std::string convertSymbols(const std::string& line) {
    std::string convertedLine;
    for (char c : line) {
        if (c == '<') {
            convertedLine += "lt;";
        } else if (c == '>') {
            convertedLine += "&gt;";
        } else {
            convertedLine += c;
        }
    }
    return convertedLine;
}

int main() {

    std::string inputFilePath, outputFilePath;

    //TODO:
    // Get input file path
    //      Enter path of C++ source file (.cpp)
    // Validate input file path
    // Get output filepath
    // Validate output
    // Open input and output files
    // Read input file, write to output file with conversions
    //TODO: figure out <pre> tags and how to write them to file




}//end main


