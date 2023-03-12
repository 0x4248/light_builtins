// Light builtins's
// mkdir - make directories
// A lightweight repository of useful C++/C shell commands
// GitHub: https://www.github.com/awesomelewis2007/light_builtins
// License: GNU General Public License v3.0

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

int main (int argc, char *argv[]) {
    std::string path = argc > 1 ? argv[1] : ".";
    if (std::filesystem::exists(path)) {
        std::cerr << "Can not create directory " << path << std::endl;
        std::cerr << "Directory already exists" << std::endl;
        return 1;
    }
    std::filesystem::create_directory(path);
    return 0;
}