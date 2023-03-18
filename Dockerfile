# Light builtins's dockerfile
# A lightweight repository of useful C++/C shell commands
# GitHub: https://www.github.com/awesomelewis2007/light_builtins
# License: GNU General Public License v3.0

FROM gcc:12.2.0

COPY . /usr/src/light_builtins

WORKDIR /usr/src/light_builtins

RUN mkdir bin

RUN make compile_cpp

RUN mv bin/* /bin

CMD ["bash"]