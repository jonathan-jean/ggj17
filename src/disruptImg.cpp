#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include "World.hh"

void SineWave(sf::Vector2f &p, int time, int middle)
{
  if (p.x < middle - 50 || p.x > middle + 50)
    {
      if (p.x < middle)
        p.y += sin((p.x / 8) + time) * 20;
      else
        p.y += sin((p.x / 8) - time) * 20;
    }
}

void    disruptImg(sf::Image &initial, sf::Image &rendered, int time)
{
  sf::Vector2f posBefore;
  sf::Vector2f posAfter;
  sf::Color color;

  int Height = initial.getSize().y;
  int Width = initial.getSize().x;

  for (int y = 0; y < Height; y++)
    {
      for (int x = 0; x < Width; x++)
        {
          posAfter.x = x;
          posAfter.y = y;
          SineWave(posAfter, time, SCREEN_WIDTH / 2);

          if (posAfter.x < 0 || posAfter.x > Width || posAfter.y < 0 || posAfter.y > Height)
            color = sf::Color::White;
          else
            color = initial.getPixel(posAfter.x, posAfter.y);

          rendered.setPixel(x, y, color);
        }
    }
}
