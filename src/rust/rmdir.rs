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
    if fs::metadata(path).unwrap().is_file() {
        println!("rmdir: failed to remove '{}': Not a directory", path);
        return;
    }
    match fs::remove_dir(path) {
        Result::Ok(_) => (),
        Result::Err(_error) => println!("rmdir: failed to remove '{}': No such directory", path)
    }
}