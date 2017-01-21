//
// Created by tonell_m on 21/01/17.
//

#include "../include/Pos.hh"

Pos::Pos(const int x, const int y) : x(x), y(y)
{

}

Pos::Pos(Pos const &cpy) : x(cpy.x), y(cpy.y)
{

}

Pos::~Pos()
{

}

Pos&            Pos::operator=(Pos const &pos)
{
	if (this != &pos)
	{
		this->x = pos.x;
		this->y = pos.y;
	}
	return *this;
}