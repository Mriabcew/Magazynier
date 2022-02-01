#pragma once
#include <iostream>
#include "Map.h"
using namespace std;
class Game
{
private:
	Display* display;
	int fps;
	bool dev;
public:
	Game(Display*,bool);
	~Game();

	void loop();
	void set_fps(int);
};

