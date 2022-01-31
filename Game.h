#pragma once
#include <iostream>
#include "Map.h"
using namespace std;
class Game
{
private:
	Display* display;
	int fps;
public:
	Game(Display*);
	~Game();

	void loop();
	void set_fps(int);
};

