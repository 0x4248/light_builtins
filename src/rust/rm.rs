/* Light builtins's (Rust version)
 * rm - remove files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

use std::env;

fn main() {
    /* Get the command line arguments */
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        /* Check if a file path was provided */
        println!("rm: missing operand");
        return;
    } else {
        path = &args[1];
    }
    /* Remove the file */
    if std::fs::metadata(path).unwrap().is_dir() {
        println!("rm: cannot remove '{}': Is a directory", path);
        return;
    }
    /* Remove the file */
    match std::fs::remove_file(path) {
        Result::Ok(_) => (),
        Result::Err(_error) => println!("rm: cannot remove '{}'", path),
    }
}
