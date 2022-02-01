#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Display.h"
#include "Game.h"
#include "Menu.h"

using namespace std;

class Engine
{
private:
	Display *e;
	bool dev;
public:
	/**
	* Engine
	* @param bool dev
	* if you are developer you can run this game in special dev mode
	*/
	Engine(bool);
	
	/**
	* allegro_start
	* allegro initialization
	*/

	void allegro_start();
};

