#include <iostream>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <regex>
#include <testing.h>

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
    struct stat buffer{};
    return (stat(path.c_str(), &buffer) == 0);
}

// Convert < and > symbols
std::string convertSymbols(const std::string& line) {
    std::string convertedLine;
    for (char c : line) {
        if (c == '<') {
            //&lt is the symbol!
            convertedLine += "&lt;";
        } else if (c == '>') {
            //&gt is the symbol after conversion
            convertedLine += "&gt;";
        } else {
            convertedLine += c;
        }
    }
    return convertedLine;
}

void processFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    //use IS_OPEN to check file
    if (!inputFile.is_open()) {
        //use runtime error
        throw std::runtime_error("Error opening input file!");
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Error opening output file!");
    }

    // Write <PRE> tags to the output file

    outputFile << "<PRE>" << std::endl;

    // Read input file, write to output file with conversions
    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << convertSymbols(line) << std::endl;
    }

    // Write </PRE> tag to output file
    outputFile << "</PRE>" <<std::endl;

    // and finally... close the file
    inputFile.close();
    outputFile.close();
}

int main() {

    std::string inputFilePath, outputFilePath;

    // Get input file path
    std::cout << "Enter path of C++ source file (.cpp): ";
    std::cin >> inputFilePath;

    // Validate input file path
    while (!isValidPath(inputFilePath) || !isValidFileName(inputFilePath)) {
        std::cout << "Invalid file path or name.\n Please enter a valid path: ";
        std::cin >> inputFilePath;
    }

    // Get output filepath
    std::cout << "Enter path for output HTML file (.html): ";
    std::cin >> outputFilePath;
    // Validate output file Path
    while (!isValidFileName(outputFilePath)) {
        std::cout << "Invalid file name. Please enter a valid file name: ";
        std::cin >> outputFilePath;
    }

    try {
        processFile(inputFilePath, outputFilePath);
        std::cout << "File conversion complete! Check the output HTML file." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;


    //
    // EXCEPTION examples
    //
    // open file
        // write file
    // you want to open file BEFORE write file. So put a check before you write to the file

    //TIPS from instructor
    //1. build a series of things that are testable and actually work
    //2. Try to think ahead as to what would be a good prototype?
    //3.

}//end main


