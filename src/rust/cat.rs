/* Light builtins's (Rust version)
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    /* Get the command line arguments */
    let path;
    if args.len() == 1 {
        /* Check if a file path was provided */
        /* Print an error message and exit the program */
        println!("cat: missing file operand");
        return;
    } else {
        /* Get the file path from the command line arguments */
        path = &args[1];
    }
    /* Read the file contents */
    let content = match fs::read_to_string(path) {
        Result::Ok(value) => value,
        Result::Err(_error) => {
            println!("cat: {}: No such file or directory", path);
            return;
        }
    };

    println!("{}", content);
}
