/* Light builtins's (Rust version)
 * mv - move (rename) files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    let new_path;
    if args.len() == 1 {
        println!("mv: missing file operand");
        return;
    } else if args.len() == 2 {
        println!("mv: missing destination file operand after '{}'", args[1]);
        return;
    } else {
        path = &args[1];
        new_path = &args[2];
    }
    /* move files */
    if let Err(_err) = fs::rename(path, new_path) {
        println!(
            "mv: cannot move '{}' to '{}': No such file or directory",
            path, new_path
        );
    }
}
