# $(envdir)/share 	- .so structures
# $(envdir)/SFML 	- SFML headers
# $(envdir)/kernel 	- kernel headers and sources
# ALSO! $(envdir) path added into ld.so.conf

logs = ./dumps/log
envdir = /usr/local/lib/asnn/

build:
	g++ -o ./debug main.cpp -L$(envdir)/share -lkermdl -lsfml-graphics -lsfml-window -lsfml-system -lpthread -I$(envdir)

run:
	./debug v 2>$(logs)
