#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
using namespace std;

class Display
{
private:
	ALLEGRO_DISPLAY* display;
public:
	Display(int=800, int=800);
	~Display();

	void change_size(int,int);
	ALLEGRO_DISPLAY* get_display();
	void refresh();
	int get_height();
	int get_width();

};

