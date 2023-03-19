/* Light builtins's (Rust version)
 * ls - list directory contents
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

use std::env;
use std::fs;
use std::fs::metadata;
use std::os::unix::prelude::PermissionsExt;

pub mod colour {
    pub const RED: &str = "\x1b[31m";
    pub const GREEN: &str = "\x1b[32m";
    pub const YELLOW: &str = "\x1b[33m";
    pub const BLUE: &str = "\x1b[34m";
    pub const MAGENTA: &str = "\x1b[35m";
    pub const CYAN: &str = "\x1b[36m";
    pub const WHITE: &str = "\x1b[37m";
    pub const RESET: &str = "\x1b[0m";
}


fn main() {
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        path = ".";
    } else {
        path = &args[1];
    }
    let paths = fs::read_dir(path).unwrap();
    for path in paths {
        let path = path.unwrap().path();
        let meta = metadata(&path).unwrap();
        let file = path.to_str().unwrap();
        let file = &file.replace("./", "");
        if meta.is_dir() {
            print!("/{}{}{} ", colour::BLUE, file, colour::RESET);
        } else {
            let perms = meta.permissions();
            let mode = perms.mode();
            if mode & 0o111 != 0 {
                print!("{}{}{} ", colour::GREEN, file, colour::RESET);
            }
            else if mode & 0o444 != 0 {
                print!("{}{}{} ", colour::RED, file, colour::RESET);
            } else {
                print!("{} ", file);
            }

        }
    }
    println!("");
}