/* Light builtins's (Rust version)
 * rmdir - remove empty directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;
use std::fs;

fn main() {
    /* Get the command line arguments */
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        /* Check if a file path was provided */
        println!("rmdir: missing operand");
        return;
    } else {
        path = &args[1];
    }
    /* Remove the directory */
    if fs::metadata(path).unwrap().is_file() {
        println!("rmdir: failed to remove '{}': Not a directory", path);
        return;
    }
    /* Check if the directory is empty */
    if fs::read_dir(path).unwrap().count() != 0 {
        println!("rmdir: failed to remove '{}': Directory not empty", path);
        return;
    }
    /* Remove the directory */
    match fs::remove_dir(path) {
        Result::Ok(_) => (),
        Result::Err(_error) => println!("rmdir: failed to remove '{}': No such directory", path),
    }
}
