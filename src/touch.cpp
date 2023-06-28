/* Light builtins's
 * touch - change the file's timestamp to the current time
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "config.h"

int main(int argc, char *argv[]) {
    /* Check if the user has provided the -v or --version flag to show the
     * version */
    if (argc >= 2 &&
        (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version")) {
        /* Print the version information */
        std::cout << "Light Builtins (C++) " << VERSION_MAJOR << "."
                  << VERSION_MINOR << "." << VERSION_PATCH << "-"
                  << EXTRA_VERSION << std::endl;
        return 0;
    }
    /* Check if the user has provided the correct number of arguments */
    if (argc != 2) {
        /* Print the usage information */
        std::cerr << "Usage: touch [Filename]" << std::endl;
        return 1;
    }

    /* Create the file with the given filename */
    std::ofstream file(argv[1]);
    /* Check if the file was created successfully */
    if (!file) {
        /* Print an error message if the file could not be created */
        std::cerr << "Touch: error creating file" << std::endl;
        return 1;
    }

    /* Get the current time */
    std::time_t now =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    /* Add a space to the file */
    file << " ";
    /* Get the fill character for the file */
    std::ofstream::traits_type::char_type c = file.fill();
    /* Move the file pointer back one character */
    file.seekp(-1, std::ios_base::cur);
    /* Replace the space with the fill character */
    file.put(c);

    /* Get the local time */
    std::tm *timeinfo = std::localtime(&now);
    /* Convert the time to a string */
    std::string time_str = std::asctime(timeinfo);
    /* Close the file */
    file.close();

    return 0;
}