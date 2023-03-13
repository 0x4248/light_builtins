/* Light builtins's
 * mkdir - make directories
 * A lightweight repository of useful C++/C shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>


int main (int argc, char *argv[]) {
    // Get the path to the directory to create
    std::string path = argc > 1 ? argv[1] : ".";
    if (std::filesystem::exists(path)) {
        /**
         * If the directory already exists, then we can not create it.
         * We will print an error message using cerr and return 1.
        */
        std::cerr << "Can not create directory " << path << std::endl;
        std::cerr << "Directory already exists" << std::endl;
        return 1;
    }
    // Create the directory
    std::filesystem::create_directory(path);
    return 0;
}