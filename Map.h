#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "Display.h"
#include "Field.h"
#include "Player.h"

using namespace std;

class Map
{
private:
	Display* display;
	vector <Field*> map;
	int height;
	int widht;
	int field_size;
	Player* player;
	int style;
	bool dev;
public:
	Map(Display*,int,bool);

	enum DIRECTION
	{
		UP,DOWN,LEFT,RIGHT
	};
	/**
	* draw
	* drawing map using fields
	*/
	void draw();
	/**
	* refresh_player
	* refreshing player position on map by setting new x and y
	*/
	void refresh_player();
	/**
	* make_move
	* @param enum DIRECTION dir
	* for move player and change position of player and chests
	*/
	void make_move(DIRECTION);
	/**
	* load_map
	* @param string name - name of level
	* @param Display* display
	* loading map from file in game dir
	*/
	void load_map(string,Display*);
	/**
	* win
	* checking is player won
	* return true if game is over
	* return false if game is not over
	*/
	bool win();
	/**
	* set_widht
	* @param int widht 
	* setter for widht
	*/
	void set_widht(int);
	/**
	* set_height
	* @param int height
	* setter for height
	*/
	void set_height(int);
	/**
	* get_height
	* getter for height
	* return map height
	*/
	int get_height();
	/**
	* get_height
	* getter for widht
	* return map widht
	*/
	int get_widht();

	/**
	* get_map_field
	* @param int x
	* @param int y
	* return type of field in field (x,y)
	*/
	Field* get_map_field(int, int);
};

