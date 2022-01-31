#include "Display.h"

Display::Display(int width, int height)
{
	display = al_create_display(width, height);
	if(!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "ALLEGRO DISPLAY ERROR", NULL,NULL);
		cout << "ALLEGRO DISPLAY ERROR" << endl;
		return;
	}
}

Display::~Display()
{
	al_destroy_display(display);
}

void Display::change_size(int width, int height)
{
	al_resize_display(display, width, height);
	refresh();
}

void Display::refresh()
{
	al_flip_display();
}

ALLEGRO_DISPLAY* Display::get_display()
{
	return display;
}

int Display::get_width()
{
	return al_get_display_width(display);
}

int Display::get_height()
{
	return al_get_display_height(display);
}