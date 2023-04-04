/* Light builtins's (Ultra Light)
 * echo - display a line of text
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::string str = argc > 1 ? argv[1] : "";
    std::cout << str << std::endl;
    return 0;
}