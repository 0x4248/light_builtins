/* Light builtins's (Rust version)
 * mv - move (rename) files
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
    let new_path;
    /* Get the command line arguments */
    if args.len() == 1 {
        /* Check if a file path was provided */
        println!("mv: missing file operand");
        return;
    } else if args.len() == 2 {
        /* Check if a new file path was provided */
        println!("mv: missing destination file operand after '{}'", args[1]);
        return;
    } else {
        /* Get the file path from the command line arguments */
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
