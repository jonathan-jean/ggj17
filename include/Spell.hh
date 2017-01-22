//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_SPELL_HH
#define GGJ17_SPELL_HH

class           Spell
{
  public:
	typedef enum    e_SpellType
	{
		PUSH,
		PULL
	}               SpellType;

  private:
	unsigned int    _power;
	const int       _cooldown;
	int             _currentCooldown;

  public:
	Spell();
	~Spell();

  public:
	unsigned int getPower() const;
	void setPower(unsigned int _power);
	const int &getCooldown() const;
	int getCurrentCooldown() const;
	void setCurrentCooldown(int _currentCooldown);

  public:
	void           cast(void);
};

#endif //GGJ17_SPELL_HH
