// Light builtins's
// mv - move (rename) files
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
    if (!std::filesystem::exists(path)) {
        std::cerr << "Can not move " << path << std::endl;
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }
    if (std::filesystem::exists(path2)) {
        std::cerr << "Can not move " << path << " to " << path2 << std::endl;
        std::cerr << "File already exists" << std::endl;
        return 1;
    }
    try {
        std::filesystem::rename(path, path2);
    } catch (std::filesystem::filesystem_error &e) {
        std::cerr << "Can not move " << path << " to " << path2 << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
