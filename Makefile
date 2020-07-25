kernel = ../kernel/kermdl.o

build: main.cpp $(kernel)
	g++ -o ./debug main.cpp $(kernel) -lpthread -lsfml-graphics -lsfml-window -lsfml-system -llapack -lblas -O2

kernel:
	g++ -c ../kernel/src/build.cpp -lblas -llapack -O3
	mv ./build.o ../kernel/kermdl.o 

run:
	./debug &>dumps/dumpone; less dumps/dumpone; "" > dump/dumpone

runv:
	./debug v &>dumps/dumpone; less dumps/dumpone; "" > dump/dumpone

runc:
	./debug v 
