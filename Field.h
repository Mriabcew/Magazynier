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
	* Field constructor
	*/
	Field(Type,Type,int,int = 40);

	/**
	* draw
	* @param int x
	* @param int y
	* @param int style
	* @param bool dev
	* @param int size
	* drawing field (textures or primitiv)
	*/
	void draw(int, int, int,bool, int);

	/**
	* get_up
	* getter for up
	* return enum Type of fild what is up
	*/
	enum Type get_up();
	/**
	* get_floor
	* getter for floor
	* return enum Type of fild what is floor
	*/
	enum Type get_floor();
	/**
	* set_floor
	* @param Type  
	* setter for floor
	*/
	void set_floor(Type);
	/**
	* set_floor
	* @param Type
	* setter for up
	*/
	void set_up(Type);
	/**
	* change_up
	* changing type of up in the filed
	*/
	void change_up();
	/**
	* change_floor
	* changing type of floor in the filed
	*/
	void change_floor();
	/**
	* change
	* changing floor and up after move 
	*/
	void change();
	/**
	* @param int style
	* refreshing bitmap after move
	*/
	void bitmap_refresh(int);

protected:
	Type floor;
	Type up;
	ALLEGRO_BITMAP* bitmap_up;
	ALLEGRO_BITMAP* bitmap_floor;
};

