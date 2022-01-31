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
	Player* player;
	int field_size;
	int style;
public:
	Map();
	Map(Display*,int);
	~Map();

	enum DIRECTION
	{
		UP,DOWN,LEFT,RIGHT
	};

	void draw();
	void refresh_player();
	void make_move(DIRECTION);
	void load_map(string,Display*);
	bool win();

	void set_widht(int);
	void set_height(int);
	int get_height();
	int get_widht();



	Field* get_map_field(int, int);
};

