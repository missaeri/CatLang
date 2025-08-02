#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "parser.hpp"

bool hasMeowExtension(const std::string& filename) {
    return filename.size() > 5 && filename.substr(filename.size() - 5) == ".meow";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: catlang [-t|--time] <file.meow>\n";
        return 1;
    }

    bool showTime = false;
    std::string filename;

    if ((std::string(argv[1]) == "-t" || std::string(argv[1]) == "--time") && argc >= 3) {
        showTime = true;
        filename = argv[2];
    } else {
        filename = argv[1];
    }

    if (!hasMeowExtension(filename)) {
        std::cerr << "Error: Only .meow files are allowed!\n";
        return 2;
    }

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file: " << filename << '\n';
        return 3;
    }

    auto start = std::chrono::steady_clock::now();

    std::string line;
    while (std::getline(file, line)) {
        parseLine(line); 
    }

    auto end = std::chrono::steady_clock::now();

    if (showTime) {
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "~CatLang - " << ms << "ms to execute file \"" << filename << "\"\n";
    }

    return 0;
}