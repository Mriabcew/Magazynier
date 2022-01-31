#include "Field.h"

Field::Field(Type floor, Type up,int size)
{
	this->floor = floor;
	this->up = up;
	this->size = size;

}

void Field::draw(int x, int y,int size) 
{
		switch (floor)
		{
		case FLOOR:
			PrimitiveRenderer::draw_rectangle(x, y, size, PrimitiveRenderer::SZARY_JASNY, size / 10, PrimitiveRenderer::CZARNY);
			break;
		case TARGET:
			PrimitiveRenderer::draw_rectangle(x, y, size, PrimitiveRenderer::FIOLETOWY, size / 10, PrimitiveRenderer::CZARNY);
			break;
		}
		switch (up)
		{
		case WALL:
			PrimitiveRenderer::draw_rectangle(x, y, size, PrimitiveRenderer::SZARY_CIEMNY, size / 10, PrimitiveRenderer::CZARNY);
			break;
		case PLAYER:
			PrimitiveRenderer::narysuj_kolo(x + size / 2, y + size / 2, size / 2 - size / 10, PrimitiveRenderer::CZERWONY);
			break;
		case CHEST:
			PrimitiveRenderer::draw_rectangle(x + size / 5, y + size / 5, size - 2 * (size / 5), PrimitiveRenderer::ZOLTY, size / 10, PrimitiveRenderer::CZARNY);
			break;
		}
	
	
}

void Field::set_floor(Type floor)
{
	this->floor = floor;
}

void Field::set_up(Type up)
{
	this->up = up;
}

void Field::change_up()
{
	switch (up)
	{
	case WALL:
		up = CHEST;
		break;
	case CHEST:
		up = PLAYER;
		break;
	case PLAYER:
		up = AIR;
		break;
	case AIR:
		up = WALL;
		break;
	}
}

void Field::change_floor()
{
	switch (floor)
	{
	case FLOOR:
		floor = TARGET;
		break;
	case AIR:
		floor = FLOOR;
		break;
	case TARGET:
		floor = AIR;
	}
}

void Field::change()
{
	int tmp=10;

	if (up == AIR && floor == AIR)
		tmp = 1;
	else if (up == AIR && floor == FLOOR)
		tmp = 2;
	else if (up == WALL && floor == FLOOR)
		tmp = 3;
	else if (up == CHEST && floor == FLOOR)
		tmp = 4;
	else if (up == CHEST && floor == TARGET)
		tmp = 5;
	else if (up == PLAYER && floor == FLOOR)
		tmp = 6;
	else if (up == PLAYER && floor == TARGET)
		tmp = 7;
	else if (up == AIR && floor == TARGET)
		tmp = 0;
	switch (tmp)
	{
	case 0:
		up = AIR;
		floor = AIR;
		break;
	case 1:
		up = AIR;
		floor = FLOOR;
		break;
	case 2:
		up = WALL;
		floor = FLOOR;
		break;
	case 3:
		up = CHEST;
		floor = FLOOR;
		break;
	case 4:
		up = CHEST;
		floor = TARGET;
		break;
	case 5:
		up = PLAYER;
		floor = FLOOR;
		break;
	case 6:
		up = PLAYER;
		floor = TARGET;
		break;
	case 7:
		up = AIR;
		floor = TARGET;
		break;
	}
}

Field::Type Field::get_floor()
{
	return floor;
}

Field::Type Field::get_up()
{
	return up;
}