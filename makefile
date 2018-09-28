all: compile main

compile:
	clang++ -std=c++11 main.cpp -c 
main:
	clang++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm main.o
	rm sfml-app
