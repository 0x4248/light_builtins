/* Light builtins's (Rust version)
 * touch - change file timestamps
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

use std::env;
use std::fs;
use std::fs::File;
use std::io::prelude::*;

fn main() {
    /* Get the command line arguments */
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        /* Check if a file path was provided */
        println!("touch: missing operand");
        return;
    } else {
        path = &args[1];
    }
    /* Create the file */
    match File::create(path) {
        Result::Ok(_) => (),
        Result::Err(_error) => println!("touch: cannot create file '{}': File exists", path),
    }
}