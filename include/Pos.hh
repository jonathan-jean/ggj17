//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_POS_HH
#define GGJ17_POS_HH

class           Pos
{
  public:
	int         x;
	int         y;

  public:
	Pos(const int x = 0, const int y = 0);
	Pos(Pos const &cpy);
	~Pos();
	Pos         &operator=(Pos const &pos);
};

#endif //GGJ17_POS_HH
