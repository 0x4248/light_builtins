/* Light builtins's (Rust version)
 * echo - display a line of text
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

use std::env;

fn main() {
    /* Get the command line arguments */
    let args: Vec<String> = env::args().collect();
    let mut output = String::new();
    
    for i in 1..args.len() {
        output.push_str(&args[i]);
        output.push(' ');
    }
    println!("{}", output);
}
