/* Light builtins's (Rust version)
 * echo - display a line of text
 * A lightweight repository of useful C++/C shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut output = String::new();
    for i in 1..args.len() {
        output.push_str(&args[i]);
        output.push(' ');
    }
    println!("{}", output);
}