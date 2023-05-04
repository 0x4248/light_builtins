/* Light builtins's (Rust version)
 * pwd - print name of current/working directory
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;

fn main() {
    let cwd = env::current_dir().unwrap();
    let cwd = cwd.to_str().unwrap();
    println!("{}", cwd);
}
