#include "build.hpp"

FILE * dump;
void intrsig (int sig) {
	fclose(dump);
	exit(0);
}

int main (int argc, char * argv[]) {
	bool vis = false;
	dump = fopen("dumps/imprint", "w");
	signal(SIGINT, intrsig);

	env::init();
	if (argc > 1 && argv[1][0] == 'v') vis = true;
	std::thread listener(rebind);
	listener.detach();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == event.MouseButtonPressed)
				env::reInitLight(event.mouseButton.x, event.mouseButton.y, true);
		}

		if (vis) window.clear();
		makeEpoch(dump);
		if (vis) drawAll();
		if (vis) window.display();

		usleep(actionTimer);
	}
 
	return 0;
}
