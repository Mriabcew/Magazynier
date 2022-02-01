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
	/**
	* Game
	* @param Display* 
	* @param bool dev
	* Constructor for Game
	*/
	Game(Display*,bool);
	
	/**
	* loop
	* game main loop
	*/
	void loop();
	/**
	* set_fps
	* @param int fps
	* seter for fps
	*/
	void set_fps(int);
};

