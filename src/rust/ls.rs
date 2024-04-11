/* Light builtins's (Rust version)
 * ls - list directory contents
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

use std::env;
use std::fs;
use std::fs::metadata;
use std::os::unix::prelude::PermissionsExt;

pub mod colour {
    pub const RED: &str = "\x1b[31m";
    pub const GREEN: &str = "\x1b[32m";
    pub const BLUE: &str = "\x1b[34m";
    pub const RESET: &str = "\x1b[0m";
}

fn main() {
    /* Get the command line arguments */
    let args: Vec<String> = env::args().collect();
    let path;
    if args.len() == 1 {
        path = ".";
    } else {
        path = &args[1];
    }
    /* List the directory contents */
    let paths = fs::read_dir(path).unwrap();
    for path in paths {
        /* Get the file path */
        let path = path.unwrap().path();
        let meta = metadata(&path).unwrap();
        let file = path.to_str().unwrap();
        let file = &file.replace("./", "");
        if meta.is_dir() {
            /* Print the directory name in blue */
            print!("/{}{}{} ", colour::BLUE, file, colour::RESET);
        } else {
            /* Print the file name in green if it is executable, otherwise print it in red if it is read-only */
            let perms = meta.permissions();
            let mode = perms.mode();
            if mode & 0o111 != 0 {
                /* The file is executable */
                print!("{}{}{} ", colour::GREEN, file, colour::RESET);
            } else if mode & 0o444 != 0 {
                /* The file is read-only */
                print!("{}{}{} ", colour::RED, file, colour::RESET);
            } else {
                /* The file is not executable or read-only */
                print!("{} ", file);
            }
        }
    }
    println!("");
}
