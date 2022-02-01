#pragma once
#include <allegro5/allegro_image.h>
#include "PrimitiveRenderer.h"

class Field
{
public:
	enum Type
	{
		FLOOR,TARGET,WALL,CHEST,PLAYER,AIR
	};
	/**
	* Field
	* @param enum Type floor
	* @param enum Type up
	* @param int style
	* @param int size
	*/
	Field(Type,Type,int,int = 40);
	void draw(int, int, int,bool, int);

	enum Type get_up();
	enum Type get_floor();
	void set_floor(Type);
	void set_up(Type);
	void change_up();
	void change_floor();
	void change();
	void bitmap_refresh(int);

protected:
	Type floor;
	Type up;
	ALLEGRO_BITMAP* bitmap_up;
	ALLEGRO_BITMAP* bitmap_floor;
};

