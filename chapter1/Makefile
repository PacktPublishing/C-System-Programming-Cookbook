CC = g++

all: hello

hello: hello.o
	${CC} -o hello hello.o

hello.o: hello.cpp
	${CC} -c hello.cpp

clean:
	rm hello.o hello
