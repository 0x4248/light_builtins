/* Light builtins's
 * pwd - print name of current/working directory
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
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
    std::string path = std::filesystem::current_path();
    path.erase(remove(path.begin(), path.end(), '"'), path.end());
    /* Print the current working directory to the console */
    std::cout << path << std::endl;
    return 0;
}