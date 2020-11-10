# $(resources)			- local .so structures
# $(resources)/SFML 	- SFML headers
# $(resources)/kernel 	- kernel headers

logs = ./dumps/log
resources = /home/ireoi/.lib
reorganize = ./test

all: build run

build:
	g++ -o ./debug main.cpp -L$(resources) -lkermdl -lsfml-graphics -lsfml-window -lsfml-system -lpthread -I$(resources)/asnn

run:
	$(reorganize) | ./debug v 2>$(logs)
