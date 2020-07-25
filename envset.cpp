namespace env {
    // structures ----------------
    struct unit {
        int x, y, state;
        kernel::model soul;
    };

	// engine data ----------------
	const int sizeX = 30, 
		sizeY = 30,
		step = 20,
		zoom = 10;

    // network template presets ---
    const auto lays = {
        $(24, {1}),
        $(24, {2}),
        $(50, {3}), // hidden layers
        $(24, {4}),
        $(50, {5}), // hidden layers
        $(24, {}),
    };

    const double defav = 0.1,
                 reser = 3,
				 neumax = 1,
				 impulse = 100;
    const std::string name = "unit";

    // environment meta data ------ 
    unsigned int epoch = 0;

    unsigned int variety = 0,
				 vartop = 100;
	double coun = 0;
  
	unit charac;
	double lightning;
	bool smap[sizeY][sizeX];
	int dpos[8] = {0, 1, 2, 3, 4, 5, 6, 7};

	void init (void) {
		charac.soul = kernel::model(lays, defav, reser, neumax, impulse, name);
	}

	void reInitLight (int x, int y, bool newc) {
		if (newc)
			{ x /= step; y /= step; }
		
		if (smap[y][x])
			smap[y][x] = false;
		else if (newc)
			smap[y][x] = true;
	}
};