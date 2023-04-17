/* Light builtins's (Ultra Light)
 * cp - copy files and directories
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
    std::string path2 = argc > 2 ? argv[2] : ".";
    try{
        /* Try to copy the file or directory*/
        std::filesystem::copy(path, path2);
    } catch(std::filesystem::filesystem_error &e){
        /**
         * If the directory already exists, then we can not create it.
         * or there is an error copying the file.
        */
        std::cerr << "Can not copy " << path << " to " << path2 << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}