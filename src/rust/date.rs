/* Light builtins's (Rust version)
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
*/

use std::time::{SystemTime, UNIX_EPOCH};

fn main() {
    /* Get the current date and time */
    let now = SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_secs();
    let date = chrono::Utc.timestamp(now as i64, 0).format("%a %b %d %H:%M:%S %Z %Y").to_string();
    /* Print the date and time */
    println!("{}", date);
}