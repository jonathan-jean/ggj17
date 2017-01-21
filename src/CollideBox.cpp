//
// Created by jean_j on 21.01.17.
//

#include "CollideBox.hh"

CollideBox::CollideBox(const sf::Vector2f &pos, int width, int height, double rotation) : pos(pos), width(width), height(height),
                                                                                 rotation(rotation) {}

CollideBox::~CollideBox() {

}

const sf::Vector2f &CollideBox::getPos() const {
	return pos;
}

void CollideBox::setPos(const sf::Vector2f &pos) {
	CollideBox::pos = pos;
}

int CollideBox::getWidth() const {
	return width;
}

void CollideBox::setWidth(int width) {
	CollideBox::width = width;
}

int CollideBox::getHeight() const {
	return height;
}

void CollideBox::setHeight(int height) {
	CollideBox::height = height;
}

double CollideBox::getRotation() const {
	return rotation;
}

void CollideBox::setRotation(double rotation) {
	CollideBox::rotation = rotation;
}
