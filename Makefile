all: main

main: src/main.cpp
	g++ -Werror -Wall -o bin/main src/main.cpp -O0 -g
