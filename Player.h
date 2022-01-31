#pragma once
class Player
{
private:
	int x;
	int y;
public:
	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);
	Player(int, int);
	~Player();
};

