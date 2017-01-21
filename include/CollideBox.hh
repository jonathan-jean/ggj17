//
// Created by jean_j on 21.01.17.
//

#ifndef GGJ17_COLLIDEBOX_HH
#define GGJ17_COLLIDEBOX_HH


#include "Pos.hh"

class CollideBox {
public:
	CollideBox(const Pos &pos, int width, int height, double rotation);

	~CollideBox();

	const Pos &getPos() const;

	void setPos(const Pos &pos);

	int getWidth() const;

	void setWidth(int width);

	int getHeight() const;

	void setHeight(int height);

	double getRotation() const;

	void setRotation(double rotation);

private:
	Pos         pos;
	int         width;
	int         height;
	double      rotation;
};


#endif //GGJ17_COLLIDEBOX_HH
