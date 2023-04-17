/* Light builtins's
 * ls - list directory contents
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
 * By: Lewis Evans
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>

#include "config.h"

std::string BLUE_BOLD = "\033[1;34m";
std::string RESET = "\033[0m";

int main (int argc, char *argv[]) {
    if (argc >= 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "." 
                  << VERSION_MINOR << "." << VERSION_PATCH << "-" 
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    std::string path;
    if (strcmp(argv[1], "-l") == 0) {
        std::string path = argc > 2 ? argv[2] : ".";
        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            std::string name = entry.path().filename();
            int size;
            if (entry.is_directory()) {
                name = BLUE_BOLD + name + RESET;
                size = 0;
                for (const auto &entry2 : std::filesystem::directory_iterator(entry.path())) {
                    std::ifstream file(entry2.path());
                    file.seekg(0, std::ios::end);
                    size += file.tellg();
                }
            } else {
                std::ifstream file(name);
                file.seekg(0, std::ios::end);
                size = file.tellg();
            }
            name.erase(remove(name.begin(), name.end(), '"'), name.end());
            if (size > 0){
                std::cout << size << "\t" << name << std::endl;
            } else {
                std::cout << "\t"<< name << std::endl;
            }
        }
        return 0;
    }
    path = argc > 1 ? argv[1] : ".";
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string name = entry.path().filename();
        if (entry.is_directory()) {
            name = BLUE_BOLD + name + RESET;
        }
        name.erase(remove(name.begin(), name.end(), '"'), name.end());
        std::cout << name << " ";
    }
    std::cout << std::endl;
    return 0;
}
