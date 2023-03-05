// Light builtins's
// cp - copy files and directories
// A lightweight repository of useful C++/C shell commands
// GitHub: https://www.github.com/awesomelewis2007/light_builtins
// License: GNU General Public License v3.0

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

int main (int argc, char *argv[]) {
    std::string path = argc > 1 ? argv[1] : ".";
    std::string path2 = argc > 2 ? argv[2] : ".";
    std::filesystem::copy(path, path2);
    return 0;
}