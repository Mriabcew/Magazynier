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
	/**
	* Menu
	* Menu basic constructor
	*/
	Menu();
	/**
	* Menu
	* @param Display* - this display
	* Menu constructor 
	*/
	Menu(Display*);
	/**
	* get_opt
	* getter for opt
	*/
	int get_opt();
	/**
	* print
	* @param enum Meni
	* Showing menu 
	*/
	void print(Meni);
};