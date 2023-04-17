/* Light builtins's (Rust version)
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        println!("cat: missing file operand");
        return;
    } else {
        path = &args[1];
    }
    let content = match fs::read_to_string(path) {
        Result::Ok(value) => value,
        Result::Err(_error) => {
            println!("cat: {}: No such file or directory", path);
            return;
        }
    };
  
    println!("{}", content)
}