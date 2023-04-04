/* Light builtins's (Ultra Light)
 * rm - remove files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

int main (int argc, char *argv[]) {
    std::string path = argc > 1 ? argv[1] : ".";
    if (std::filesystem::is_directory(path)) {
        /**
         * If the directory already exists, then we can not create it.
         * We will print an error message using cerr and return 1.
        */
        std::cerr << "rm: can not remove directory" << std::endl;
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