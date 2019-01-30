all: compile main

compile:
	clang++ -std=c++11 main.cpp -c -pthread
main:
	clang++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -pthread
clean:
	rm sfml-app
	rm main.o

