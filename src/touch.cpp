/* Light builtins's
 * touch - change the file's timestamp to the current time
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/


#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: touch [Filename]" << std::endl;
        return 1;
    }
    
    std::ofstream file(argv[1]);
    if (!file) {
        std::cerr << "Touch: error creating file" << std::endl;
        return 1;
    }
    
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    file << " ";
    std::ofstream::traits_type::char_type c = file.fill();
    file.seekp(-1, std::ios_base::cur);
    file.put(c);

    std::tm* timeinfo = std::localtime(&now);
    std::string time_str = std::asctime(timeinfo);
    file.close();

    return 0;
}
