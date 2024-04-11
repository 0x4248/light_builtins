/* Light builtins's
 * rmdir - remove empty directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
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
    /* Check if the user has provided any arguments */
    if (argc == 1) {
        /* Print the usage information */
        std::cout << "Usage: rmdir [-r] [path]" << std::endl;
        return 0;
    }
    /* Check if the user has provided the -r flag to remove directories
     * recursively */
    if (argc > 1 && std::string(argv[1]) == "-r") {
        /* Get the path to the directory to remove */
        std::filesystem::path path = argc > 2 ? argv[2] : ".";
        /* Remove the directory and its contents recursively */
        std::filesystem::remove_all(path);
        return 0;
    }
    /* Get the path to the directory to remove */
    std::filesystem::path path = argc > 1 ? argv[1] : ".";
    /* Check if the directory is empty */
    if (std::filesystem::is_empty(path)) {
        /* Remove the directory */
        std::filesystem::remove(path);
    } else {
        /**
         * If the directory is not empty, then we can not remove it.
         * We will print an error message using cerr and return 1.
         */
        std::cerr << "Directory is not empty" << std::endl;
        return 1;
    }
    return 0;
}