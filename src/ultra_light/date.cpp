/* Light builtins's (Ultra Light)
 * date - display the current date and time
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <ctime>

int main() {
    std::time_t now = std::time(nullptr);
    char date[100];
    std::strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Z %Y", std::localtime(&now));
    std::cout << date << std::endl;
    return 0;
}
