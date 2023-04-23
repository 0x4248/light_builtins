/* Light builtins's
 * mv - move (rename) files
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
    std::string path2 = argc > 2 ? argv[2] : ".";
    if (!std::filesystem::exists(path)) {
        /**
         * Check if path 1 exists. If it does not exist,
         * then we can not move it. We will print an error
        */
        std::cerr << "Can not move " << path << std::endl;
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }
    if (std::filesystem::exists(path2)) {
        /**
         * Check if path 2 exists. If it does exist,
         * then we can not move it. We will print an error
        */
        std::cerr << "Can not move " << path << " to " << path2 << std::endl;
        std::cerr << "File already exists" << std::endl;
        return 1;
    }
    try {
        std::filesystem::rename(path, path2);
    } catch (std::filesystem::filesystem_error &e) {
        /**
         * If there is an error moving the file, then we will print an error
        */
        std::cerr << "Can not move " << path << " to " << path2 << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
