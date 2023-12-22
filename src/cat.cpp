/* Light builtins's
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#include <fstream>
#include <iostream>
#include <string>

#include "config.h"

int main(int argc, char *argv[]) {
    bool show_line_numbers = false;
    bool show_ends = false;
    int file_offset = 1;
    /* Check if the user has provided the -n flag to show line numbers */
    if (argc >= 2 && std::string(argv[1]) == "-n") {
        show_line_numbers = true;
        file_offset = 2;
    }
    /* Check if the user has provided the -e flag to show line endings */
    if (argc >= 2 && std::string(argv[1]) == "-e") {
        show_ends = true;
        file_offset = 2;
    }
    /* Check if the user has provided the -v or --version flag to show the
     * version */
    if (argc >= 2 &&
        (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    /* Check if the user has provided the correct number of arguments */
    if (argc < file_offset + 1) {
        std::cerr << "Usage: " << argv[0] << " [-nev] [file ...]\n";
        std::cerr << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 1;
    }

    int line_number = 1;
    /* Loop through each file provided by the user */
    for (int i = file_offset; i < argc; ++i) {
        std::ifstream file(argv[i]);
        /* Check if the file exists */
        if (!file.good()) {
            std::cerr << "File not found: " << argv[i] << "\n";
            return 1;
        }
        /* Check if the file can be opened */
        else if (!file.is_open()) {
            std::cerr << "Failed to open file: " << argv[i] << "\n";
            return 1;
        }

        std::string line;
        /* Read each line of the file and print it to the console */
        while (std::getline(file, line)) {
            if (show_line_numbers) {
                std::cout << CYAN << line_number << RESET << "\t" << line
                          << "\n";
            } else if (show_ends) {
                std::cout << line << "$"
                          << "\n";
            } else {
                std::cout << line << "\n";
            }

            line_number++;
        }
        file.close();
    }

    return 0;
}