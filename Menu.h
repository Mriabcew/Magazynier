#pragma once
#include <iostream>
#include "Display.h"

using namespace std;

class Menu
{
private:
	enum Meni {
		MENU, SETTINGS
	};
	int opt;
public:
	Menu();
	Menu(Display*);
	~Menu();
	int get_opt();
	void print(Meni);
};