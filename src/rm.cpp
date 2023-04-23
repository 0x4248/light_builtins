/* Light builtins's
 * rm - remove files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

#include "config.h"

int main (int argc, char *argv[]) {
    if (argc >= 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "." 
                  << VERSION_MINOR << "." << VERSION_PATCH << "-" 
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    std::string path = argc > 1 ? argv[1] : ".";
    if (std::filesystem::is_directory(path)) {
        /**
         * If the directory already exists, then we can not create it.
         * We will print an error message using cerr and return 1.
        */
        std::cerr << "rm: can not remove directory " << std::endl;
        return 1;
    }
    if (std::filesystem::exists(path)) {
        std::filesystem::remove(path);
    } else {
        std::cerr << "rm: can not remove " << path << " no such file or directory" << std::endl;
        return 1;
    }
    return 0;
}