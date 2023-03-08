# Light builtins's dockerfile
# A lightweight repository of useful C++/C shell commands
# GitHub: https://www.github.com/awesomelewis2007/light_builtins
# License: GNU General Public License v3.0

FROM gcc:latest

COPY . /usr/src/light_builtins

WORKDIR /usr/src/light_builtins

RUN make

RUN rm -rf bin/c

RUN mv bin/* /bin

CMD ["bash"]