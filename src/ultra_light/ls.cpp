/* Light builtins's (Ultra Light)
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

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++ Ultra Light) " << VERSION_MAJOR << "." 
                  << VERSION_MINOR << "." << VERSION_PATCH << "-" 
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    std::string path = argc > 1 ? argv[1] : ".";
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string name = entry.path().filename();
        if (entry.is_directory()) {
            /* Show / before the directory 
             * name to help the user know 
             * its a directory
             */
            name = "/" + name;
        }
        name.erase(remove(name.begin(), name.end(), '"'), name.end());
        std::cout << name << " ";
    }
    std::cout << std::endl;
    return 0;
}
