# Light builtins's dockerfile
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/awesomelewis2007/light_builtins
# Licence: GNU General Public License v3.0

FROM rust:1.61

COPY . /usr/src/light_builtins

WORKDIR /usr/src/light_builtins

RUN make init compile_rust

RUN mv bin/rust/* /bin

CMD ["bash"]
