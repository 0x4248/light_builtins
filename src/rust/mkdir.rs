/* Light builtins's (Rust version)
 * mkdir - make directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    /* Get the command line arguments */
    if args.len() == 1 {
        println!("mkdir: missing operand");
        return;
    } else {
        path = &args[1];
    }
    /* Create the directory */
    match fs::create_dir(path) {
        Result::Ok(_) => (),
        Result::Err(_error) => println!("mkdir: cannot create directory '{}': File exists", path),
    }
}
