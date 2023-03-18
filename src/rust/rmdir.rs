/* Light builtins's (Rust version)
 * rmdir - remove empty directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        println!("rmdir: missing operand");
        return;
    } else {
        path = &args[1];
    }
    match fs::remove_dir(path) {
        Result::Ok(_) => (),
        Result::Err(error) => panic!("{}", error)
    }
}