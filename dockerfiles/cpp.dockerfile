# Light builtins's dockerfile
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0

FROM gcc:12.2.0

COPY . /usr/src/light_builtins

WORKDIR /usr/src/light_builtins

RUN make init compile_cpp

RUN mv bin/* /bin

CMD ["bash"]