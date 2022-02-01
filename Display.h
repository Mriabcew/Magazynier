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
	/**
	* @param int 
	* @param int
	* Constructor for display 
	*/
	Display(int=800, int=800);
	/**
	* Destructor for display
	*/
	~Display();

	/**
	* change_size
	* @param int 
	* @param int
	* Chenging size of the window
	*/
	void change_size(int,int);
	/**
	* get_display
	* return display pointer to this display
	*/
	ALLEGRO_DISPLAY* get_display();
	/**
	* refresh
	* this function is refreshing display
	*/
	void refresh();
	/*
	* get_height
	* getter for height
	*/
	int get_height();
	/*
	* get_width
	* width for height
	*/
	int get_width();

};

