#include <iostream>
#include <fstream>
#include "my_string.hpp"
#include "my_vector.hpp"

int main() {
    // Read input file
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Store words in a dynamic array
    my_vector::my_vector<my_string::string> words;

    my_string::string line;
    while (my_string::getline(inputFile, line, '\n')) {
        size_t start = 0;
        size_t end = line.find(' ');
        while (end != my_string::string::npos) {
            words.push_back(line.substr(start, end - start));
            start = end + 1;
            end = line.find(' ', start);
        }
        words.push_back(line.substr(start));
    }

    // Sort words alphabetically
    std::sort(words.begin(), words.end());

    // Write sorted words to the output file
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    for (const auto& word : words) {
        outputFile << word.c_str() << ' ';
    }

    return 0;
}
