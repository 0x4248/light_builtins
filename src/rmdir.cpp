// Light builtins's
// rmdir - remove empty directories
// A lightweight repository of useful C++/C shell commands
// GitHub: https://www.github.com/awesomelewis2007/light_builtins
// License: GNU General Public License v3.0

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

int main (int argc, char *argv[]) {
    std::string path = argc > 1 ? argv[1] : ".";
    if (std::filesystem::is_empty(path)) {
        std::filesystem::remove(path);
    } else {
        std::cerr << "Directory is not empty" << std::endl;
        return 1;
    }
    return 0;
}