using namespace env;

void drawAll (void) {
	for (int y = 0; y < sizeY; ++y)
		for (int x = 0; x < sizeX; ++x) {
			tempRect.setPosition(x * step, y * step);

			if (smap[y][x])
				tempRect.setFillColor(lightC);
			else
				tempRect.setFillColor(sf::Color(30, 30, 30));

			window.draw(tempRect);
		}

	tempRect.setPosition(charac.x * step, charac.y * step);
	tempRect.setFillColor(sf::Color::Cyan);
	window.draw(tempRect);
}

void rebind (void) {
	for (;;) {
		puts("↑ ⬈ → ⬊ ↓ ⬋ ← ⬉ - set values");
		for (int it = 0; it < 8; ++it)
			scanf("%d", &dpos[it]);
	}
}

void getChoise (std::vector<double> &temp) {
	for (int it = 0; it < 9; ++it) {
		temp[it] = temp[it * 3] + temp[it * 3 + 1] + temp[it * 3 + 2]; 
	}
   
	double buffer = 0;
	for (int it = 0; it < 8; ++it)
		if (temp[it] > buffer) buffer = temp[it];

	for (int it = 0; it < 8; ++it)
		temp[it] /= buffer;
}

int modY (int y) {
	if (y < 0) return y + sizeY;
	else if (y >= sizeY) return y - sizeY;
	return y;
}

int modX (int x) {
	if (x < 0) return x + sizeX;
	else if (x >= sizeX) return x - sizeX;
	return x; 
}

int corresp(int cy, int cx) {
	double angle;

	if (cx) {
		angle = double(cy) / double(cx);
		angle = atan(abs(angle)) * 180 / 3.14;
	} else angle = 90;

	if (cy >= 0) {
		if (cx >= 0) angle = 90 - angle;
		else angle += 270;
	} else {
		if (cx >= 0) angle += 90;
		else angle = 270 - angle;
	}

	return int(angle / 360 * 8) * 3 + 1;
}

void makeEpoch (FILE * dump) {
	lightning = 0.01;
	std::vector<double> saver(24, 0.01);  
	int ty, tx;

	for (int y = -zoom; y <= zoom; ++y)
		for (int x = -std::min(zoom - y, y + zoom); sqrt(pow(x, 2) + pow(y, 2)) <= zoom; ++x) {
			ty = modY(charac.y + y);
			tx = modX(charac.x + x);

			if (smap[ty][tx]) {
				int iter = corresp(-y, x);

				saver[iter] = 
					std::max(double(1) - sqrt(pow(ty - charac.y, 2) * pow(tx - charac.x, 2)) / zoom, saver[iter]);

				lightning = std::max(saver[iter], lightning);
			}
		}
	
	charac.soul.setIn(saver, 0, 0);
	charac.soul.setIn(saver, 3, 0);

	charac.soul.exec(true, (smap[charac.y][charac.x] ? 0.1 : lightning));
	saver = charac.soul.getOut();

	charac.soul.dropOut();
	charac.soul.dropPart(lightning);
	
	charac.soul.setIn(saver, 1, 0);
	
	getChoise(saver);

	if (saver[dpos[0]] == 1) --charac.y;
	else if (saver[dpos[1]] == 1) { --charac.y; ++charac.x; }
	else if (saver[dpos[2]] == 1) ++charac.x;
	else if (saver[dpos[3]] == 1) { ++charac.y; ++charac.x; }
	else if (saver[dpos[4]] == 1) ++charac.y;
	else if (saver[dpos[5]] == 1) { ++charac.y; --charac.x; }
	else if (saver[dpos[6]] == 1) --charac.x;
	else if (saver[dpos[7]] == 1) { --charac.y; --charac.x; }
	
	charac.y = modY(charac.y);
	charac.x = modX(charac.x);

	// data mining
	++variety;
	coun += lightning;

	if (variety == vartop) {
		fprintf(dump, "%lf\n", coun);
		variety = 0;
		coun = 0;
	}

	//reInitLight(charac.x, charac.y, false);
}
