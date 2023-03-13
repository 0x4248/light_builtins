/* Light builtins's
 * pwd - print name of current/working directory
 * A lightweight repository of useful C++/C shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/
#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

int main (int argc, char *argv[]) {
    std::string path = std::filesystem::current_path();
    path.erase(remove(path.begin(), path.end(), '"'), path.end());
    std::cout << path << std::endl;
    return 0;
}