#pragma once
#include "PrimitiveRenderer.h"
class Field
{
public:
	enum Type
	{
		FLOOR,TARGET,WALL,CHEST,PLAYER,AIR
	};
	Field(Type,Type,int);
	~Field();
	void draw(int, int,int);

	enum Type get_up();
	enum Type get_floor();
	void set_floor(Type);
	void set_up(Type);
	void change_up();
	void change_floor();
	void change();

private:
	Type floor;
	Type up;
	int size;
};

