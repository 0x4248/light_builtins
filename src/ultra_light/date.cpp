/* Light builtins's (Ultra Light)
 * date - display the current date and time
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
 * By: Lewis Evans
*/

#include <iostream>
#include <ctime>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 && (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++ Ultra Light) " << VERSION_MAJOR << "." 
                  << VERSION_MINOR << "." << VERSION_PATCH << "-" 
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    std::time_t now = std::time(nullptr);
    char date[100];
    std::strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Z %Y", std::localtime(&now));
    std::cout << date << std::endl;
    return 0;
}
