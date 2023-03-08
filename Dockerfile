FROM gcc:latest

COPY . /usr/src/light_builtins

WORKDIR /usr/src/light_builtins

RUN make

RUN rm -rf bin/c

RUN mv bin/* /bin

CMD ["bash"]