#pragma once

class Player
{
private:
	int x;
	int y;
public:
	/**
	* get_x
	* getter for x in player class
	* return x
	*/
	int get_x();
	/**
	* get_y
	* getter for y in player class
	* return y
	*/
	int get_y();
	/**
	* set_x
	* @param int x
	* setter for x in player class
	*/
	void set_x(int);
	/**
	* set_y
	* @param int y
	* setter for y in player class
	*/
	void set_y(int);
	/**
	* Player constructor
	* @param int x 
	* @param int y
	* player starts in (x,y) block
	*/
	Player(int, int);
	/**
	* Player deconstructor
	* delete player object
	*/
	~Player();
};

