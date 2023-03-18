/* Light builtins's (Rust version)
 * ls - list directory contents
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

use std::env;
use std::fs;
use std::fs::metadata;

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
            print!("/{} ", file);
        } else {
            print!("{} ", file);
        }
    }
    println!("");
}