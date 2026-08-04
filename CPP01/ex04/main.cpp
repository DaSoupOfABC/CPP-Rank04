#include <iostream>
#include <fstream>
#include <string>

std::string replaceOccurrences(std::string content, const std::string& s1, const std::string& s2) 
{
    
	if (s1.empty()) return content;
    std::string result;
    size_t pos = 0;
    size_t found;

    // Loop through finding every match of s1
    while ((found = content.find(s1, pos)) != std::string::npos) {
        // Append everything from the last position up to the match
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos, content.length() - pos);
    
    return result;
}

int main(int argc, char** argv) 
{
    if (argc != 4) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: The string to replace (s1) cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file '" << filename << "'." << std::endl;
        return 1;
    }

    // Create output file (<filename>.replace)
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file '" << outFilename << "'." << std::endl;
        inFile.close();
        return 1;
    }

    //ead input file content line by line or all at once
    std::string line;
    while (std::getline(inFile, line)) {
        outFile << replaceOccurrences(line, s1, s2);
        if (!inFile.eof()) {
            outFile << "\n"; // Preserve newlines
        }
    }

    // Close streams
    inFile.close();
    outFile.close();

    std::cout << "Successfully generated " << outFilename << std::endl;
    return 0;
}