#include "Map.h"

Map::Map(Display* d,int style)
{
    display = d;
    this->style = style;
	player = new Player(7, 4);
   

    load_map("poziom1",d);
}

Field* Map::get_map_field(int x, int y)
{
	return map[y * widht + x];
}

void Map::draw()
{
	for (int i = 0; i < map.size() / widht; i++)
		for (int j = 0; j < map.size() / height; j++)
			map[i * widht + j]->draw(j * field_size, i * field_size,field_size);
}

void Map::refresh_player()
{
    for (int i = 0; i < map.size() / widht; i++)
        for (int j = 0; j < map.size() / height; j++)
            if (map[i * widht + j]->get_up() == Field::PLAYER)
            {
                player->set_x(j);
                player->set_y(i);
            }
}

void Map::make_move(DIRECTION dir)
{
    refresh_player();
    switch (dir)
    {
    case UP:
        if (map[(player->get_y() - 1) * widht + player->get_x()]->get_up() == Field::AIR)
        {
            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y() - 1) * widht + player->get_x()]->set_up(Field::PLAYER);
        }
        else if (map[(player->get_y() - 1) * widht + player->get_x()]->get_up() == Field::CHEST && map[(player->get_y() - 2) * widht + player->get_x()]->get_up() == Field::AIR)
        {

            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y() - 1) * widht + player->get_x()]->set_up(Field::PLAYER);
            map[(player->get_y() - 2) * widht + player->get_x()]->set_up(Field::CHEST);
        }
        break;
    case DOWN:
        if (map[(player->get_y() + 1) * widht + player->get_x()]->get_up() == Field::AIR)
        {
            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y() + 1) * widht + player->get_x()]->set_up(Field::PLAYER);
        }
        else if (map[(player->get_y() + 1) * widht + player->get_x()]->get_up() == Field::CHEST && map[(player->get_y() + 2) * widht + player->get_x()]->get_up() == Field::AIR)
        {

            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y() + 1) * widht + player->get_x()]->set_up(Field::PLAYER);
            map[(player->get_y() + 2) * widht + player->get_x()]->set_up(Field::CHEST);
        }
        break;
    case LEFT:
        if (map[(player->get_y()) * widht + player->get_x() - 1]->get_up() == Field::AIR)
        {
            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y()) * widht + player->get_x() - 1]->set_up(Field::PLAYER);
        }
        else if (map[(player->get_y()) * widht + player->get_x() - 1]->get_up() == Field::CHEST && map[(player->get_y()) * widht + player->get_x() - 2]->get_up() == Field::AIR)
        {
            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y()) * widht + player->get_x() - 1]->set_up(Field::PLAYER);
            map[(player->get_y()) * widht + player->get_x() - 2]->set_up(Field::CHEST);
        }
        break;
    case RIGHT:
        if (map[(player->get_y()) * widht + player->get_x() + 1]->get_up() == Field::AIR)
        {
            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y()) * widht + player->get_x() + 1]->set_up(Field::PLAYER);
        }
        else if (map[(player->get_y()) * widht + player->get_x() + 1]->get_up() == Field::CHEST && map[(player->get_y()) * widht + player->get_x() + 2]->get_up() == Field::AIR)
        {
            map[(player->get_y()) * widht + player->get_x()]->set_up(Field::AIR);
            map[(player->get_y()) * widht + player->get_x() + 1]->set_up(Field::PLAYER);
            map[(player->get_y()) * widht + player->get_x() + 2]->set_up(Field::CHEST);
        }
        break;
    }
}

void Map::load_map(string name,Display* d)
{
    fstream file;
    string n = "mapy/";
    n+= name + ".txt";
    file.open(n, ios::in);
    string height, widht;
    if (!file.good())
    {
        cout << "Map file error" << endl;
        return;
    }
    getline(file, widht);
    getline(file, height);
    this->height = stoi(height);
    this->widht = stoi(widht);
    map.clear();
    char tmp;
    field_size = min(d->get_width() / this->widht, d->get_height() / this->height);
    while (!file.eof())
    {
        file >> tmp;
        if (tmp == '0')
            map.push_back(new Field(Field::FLOOR, Field::AIR, field_size));
        else if (tmp == '1')
            map.push_back(new Field(Field::FLOOR, Field::WALL, field_size));
        else if (tmp == '2')
            map.push_back(new Field(Field::FLOOR, Field::PLAYER, field_size));
        else if (tmp == '3')
            map.push_back(new Field(Field::FLOOR, Field::CHEST, field_size));
        else if (tmp == '4')
            map.push_back(new Field(Field::TARGET, Field::AIR, field_size));
        else if (tmp == '5')
            map.push_back(new Field(Field::TARGET, Field::CHEST, field_size));
        else if (tmp == '6')
            map.push_back(new Field(Field::TARGET, Field::PLAYER, field_size));
        else if (tmp == '7')
            map.push_back(new Field(Field::AIR, Field::AIR, field_size));
    }

file.close();
}

bool Map::win()
{
    for (int i = 0; i < map.size(); i++)
        if (map[i]->get_floor() == Field::FLOOR && map[i]->get_up() == Field::CHEST)
            return false;
    return true;
}

void Map::set_widht(int widht)
{
    this->widht = widht;
}

void Map::set_height(int height)
{
    this->height = height;
}

int Map::get_height()
{
    return height;
}

int Map::get_widht()
{
    return widht;
}


