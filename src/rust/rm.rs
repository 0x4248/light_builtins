/* Light builtins's (Rust version)
 * rm - remove files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        println!("rm: missing operand");
        return;
    } else {
        path = &args[1];
    }
    if std::fs::metadata(path).unwrap().is_dir() {
        println!("rm: cannot remove '{}': Is a directory", path);
        return;
    }
    match std::fs::remove_file(path) {
        Result::Ok(_) => (),
        Result::Err(_error) => println!("rm: cannot remove '{}'", path),
    }
}
