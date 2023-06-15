/* Light builtins's
 * ls - list directory contents
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "config.h"

std::string BLUE_BOLD = "\033[1;34m";
std::string RESET = "\033[0m";

int main(int argc, char *argv[]) {
    /* Check if the user has provided the -v or --version flag to show the version */
    if (argc >= 2 &&
        (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        /* Print the version information */
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    std::string path;
    /* Check if the user has provided the -l flag to show file sizes */
    if (strcmp(argv[1], "-l") == 0) {
        /* Get the path to the directory to list */
        std::string path = argc > 2 ? argv[2] : ".";
        /* Loop through each file in the directory */
        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            std::string name = entry.path().filename();
            int size;
            /* Check if the file is a directory */
            if (entry.is_directory()) {
                /* Format the directory name with color */
                name = BLUE_BOLD + name + RESET;
                size = 0;
                /* Loop through each file in the directory and get the total size */
                for (const auto &entry2 :
                     std::filesystem::directory_iterator(entry.path())) {
                    std::ifstream file(entry2.path());
                    file.seekg(0, std::ios::end);
                    size += file.tellg();
                }
            } else {
                /* Get the size of the file */
                std::ifstream file(name);
                file.seekg(0, std::ios::end);
                size = file.tellg();
            }
            /* Remove any quotes from the file name */
            name.erase(remove(name.begin(), name.end(), '"'), name.end());
            /* Print the file size and name to the console */
            if (size > 0) {
                std::cout << size << "\t" << name << std::endl;
            } else {
                std::cout << "\t" << name << std::endl;
            }
        }
        return 0;
    }
    /* Get the path to the directory to list */
    path = argc > 1 ? argv[1] : ".";
    /* Loop through each file in the directory */
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string name = entry.path().filename();
        /* Format the directory name with color if it is a directory */
        if (entry.is_directory()) {
            name = BLUE_BOLD + name + RESET;
        }
        /* Remove any quotes from the file name */
        name.erase(remove(name.begin(), name.end(), '"'), name.end());
        /* Print the file name to the console */
        std::cout << name << " ";
    }
    std::cout << std::endl;
    return 0;
}
