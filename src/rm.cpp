/* Light builtins's
 * rm - remove files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>

#include "config.h"

int main(int argc, char *argv[]) {
    /* Check if the user has provided the -v or --version flag to show the
     * version */
    if (argc >= 2 &&
        (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        /* Print the version information */
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    std::string path = argc > 1 ? argv[1] : ".";
    /* Check if the path is a directory */
    if (std::filesystem::is_directory(path)) {
        /**
         * If the directory already exists, then we can not create it.
         * We will print an error message using cerr and return 1.
         */
        std::cerr << "rm: can not remove directory " << std::endl;
        return 1;
    }
    /* Check if the path exists */
    if (std::filesystem::exists(path)) {
        /* Remove the file */
        std::filesystem::remove(path);
    } else {
        /* Print an error message if the path does not exist */
        std::cerr << "rm: can not remove " << path
                  << " no such file or directory" << std::endl;
        return 1;
    }
    return 0;
}