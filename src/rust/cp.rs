/* Light builtins's (Rust version)
 * cp - copy files and directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

use std::env;
use std::fs;


fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    let new_path;
    if args.len() == 1 {
        println!("cp: missing file operand");
        return;
    } else if args.len() == 2 {
        println!("cp: missing destination file operand after '{}'", args[1]);
        return;
    } else {
        path = &args[1];
        new_path = &args[2];
    }
    if let Err(_err) = fs::copy(path, new_path) {
        println!("cp: cannot copy '{}' to '{}': No such file or directory", path, new_path);
    }
}