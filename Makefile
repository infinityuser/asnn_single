kernel = ../kernel/kermdl.o
log = dumps/log
prog = ./debug

build:
	g++ -o $(prog) main.cpp $(kernel) -lpthread -lsfml-graphics -lsfml-window -lsfml-system

run:
	$(prog) v 2>$(log)
