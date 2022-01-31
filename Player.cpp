#include "Player.h"
Player::Player(int x,int y):x(x),y(y)
{}

Player::~Player() {}

int Player::get_x()
{
    return x;
}

int Player::get_y()
{
    return y;
}

void Player::set_x(int x)
{
    this->x = x;
}
void Player::set_y(int y)
{
    this->y = y;
}