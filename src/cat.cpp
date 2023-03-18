/* Light builtins's
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: cat [FILE] [OPTION]" << std::endl;
        std::cout << "    -ln: Print line numbers" << std::endl;
        return 1;
    }
    std::string path = argc > 1 ? argv[1] : ".";
    bool print_ln = false;
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-ln") {
            print_ln = true;
        }
    }
    std::ifstream file(path);
    if (file.is_open()) {
        /* We need to check if the file is open before reading it*/
        std::string line;
        int ln = 1;
        while (std::getline(file, line)) {
            if (print_ln) {
                std::cout << ln << " ";
                ln++;
            }
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        /**
         * If the file is not open, then we assume 
         * that we can not read from it.
        */
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }
    return 0;
}
