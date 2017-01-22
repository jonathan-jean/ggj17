//
// Created by jean_j on 21.01.17.
//

#ifndef GGJ17_COLLIDEBOX_HH
#define GGJ17_COLLIDEBOX_HH


#include <SFML/System/Vector2.hpp>
#include "Pos.hh"

class CollideBox {
public:
	CollideBox(const sf::Vector2f &pos, int width, int height, double rotation);

	~CollideBox();

	const sf::Vector2f &getPos() const;

	void setPos(const sf::Vector2f &pos);

	int getWidth() const;

	void setWidth(int width);

	int getHeight() const;

	void setHeight(int height);

	double getRotation() const;

	void setRotation(double rotation);

private:
	sf::Vector2f    pos;
	int             width;
	int             height;
	double          rotation;
};


#endif //GGJ17_COLLIDEBOX_HH
