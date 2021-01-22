namespace env {
	// structures ----------------
	struct unit {
		int x, y, state;
		kernel::model soul;
	};

	// environment data -----------
	const int sizeX = 40, 
	sizeY = 40,
	step = 12,
	zoom = 10;

	// network template -----------
	const auto lays = {
		$(24, {1}), // input layer
		$(24, {2}), // output layer
		$(50, {3}), // hidden layers
		$(24, {5}), // output layer
		$(50, {6}), // hidden layers
		$(24, {}), // out 
	};

	const double defav = 0.1,
	reser = 0.23,
	neumax = 1,
	impulse = 1000;
	const std::string name = "unit";

	// environment meta data ------ 
	unsigned int epoch = 0;
	unsigned int variety = 0,
	vartop = 100;
	double coun = 0;

	// unit data ------------------
	unit charac;
	double lightning;
	bool smap[sizeY][sizeX];
	int dpos[8] = {0, 1, 2, 3, 4, 5, 6, 7};

	// unit methods ---------------
	void init (void) {
		charac.soul = kernel::model(lays, defav, reser, neumax, impulse, name);
	}

	void reInitLight (int x, int y, bool newc) {
		if (newc) {
			x /= step; 
			y /= step; 
		}
		
		if (smap[y][x])
			smap[y][x] = false;
		else if (newc)
			smap[y][x] = true;
	}
};
