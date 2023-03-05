// Light builtins's
// cat - concatenate files and print on the standard output
// A lightweight repository of useful C++/C shell commands
// GitHub: https://www.github.com/awesomelewis2007/light_builtins
// License: GNU General Public License v3.0

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::string path = argc > 1 ? argv[1] : ".";
    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }
    return 0;
}
