/* Light builtins's (Rust version)
 * pwd - print name of current/working directory
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

use std::env;

fn main() {
    /* Get the current working directory */
    let cwd = env::current_dir().unwrap();
    let cwd = cwd.to_str().unwrap();
    /* Print the current working directory */
    println!("{}", cwd);
}
