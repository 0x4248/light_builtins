/* Light builtins's (Ultra Light)
 * rmdir - remove empty directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++ Ultra Light) " << VERSION_MAJOR << "." 
                  << VERSION_MINOR << "." << VERSION_PATCH << "-" 
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    if (argc > 1 && std::string(argv[1]) == "-r") {
        std::string path = argc > 2 ? argv[2] : ".";
        std::filesystem::remove_all(path);
        return 0;
    }
    std::string path = argc > 1 ? argv[1] : ".";
    if (std::filesystem::is_empty(path)) {
        std::filesystem::remove(path);
    } else {
        /**
         * If the directory is not empty, then we can not remove it.
        */
        std::cerr << "Directory is not empty" << std::endl;
        return 1;
    }
    return 0;
}