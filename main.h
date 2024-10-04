#ifndef MAIN_H
#define MAIN_H

#include <string>

std::string readFile(const std::string& filePath);
bool isValidFileName(const std::string& content);
bool isValidPath(const std::string& path);
std::string convertSymbols(const std::string& content);
void processFile(const std::string& inputFilePath, const std::string& outputFilePath);

#endif //MAIN_H