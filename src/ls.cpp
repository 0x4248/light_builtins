/* Light builtins's
 * ls - list directory contents
 * A lightweight repository of useful C++/C shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

std::string BLUE_BOLD = "\033[1;34m";
std::string RESET = "\033[0m";

int main (int argc, char *argv[]) {
    std::string path = argc > 1 ? argv[1] : ".";
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string name = entry.path().filename();
        if (entry.is_directory()) {
            /* Show / before the directory 
             * name to help the user know 
             * its a directory
             */
            name = BLUE_BOLD + name + RESET;
        }
        name.erase(remove(name.begin(), name.end(), '"'), name.end());
        std::cout << name << " ";
    }
    std::cout << std::endl;
    return 0;
}
