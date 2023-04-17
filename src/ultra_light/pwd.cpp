/* Light builtins's (Ultra Light)
 * pwd - print name of current/working directory
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
 * By: Lewis Evans
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
    std::string path = std::filesystem::current_path();
    path.erase(remove(path.begin(), path.end(), '"'), path.end());
    std::cout << path << std::endl;
    return 0;
}