/* Light builtins's
 * echo - display a line of text
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#include <iostream>
#include <string>

#include "config.h"

int main(int argc, char *argv[]) {
    /* Check if the user has provided the -v or --version flag to show the
     * version */
    if (argc >= 2 &&
        (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    /* Print the arguments */
    std::string str = argc > 1 ? argv[1] : "";
    std::cout << str << std::endl;
    return 0;
}