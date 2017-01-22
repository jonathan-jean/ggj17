//
// Created by tonell_m on 21/01/17.
//

#include "Constants.hh"
#include "Spell.hh"

Spell::Spell() : _power(SPELL_DEFAULT_POWER), _cooldown(SPELL_COOLDOWN), _currentCooldown(0) {}

unsigned int Spell::getPower() const
{
	return _power;
}

void Spell::setPower(unsigned int _power)
{
	Spell::_power = _power;
}

const int Spell::getCooldown() const
{
	return _cooldown;
}

int Spell::getCurrentCooldown() const
{
	return _currentCooldown;
}

void Spell::setCurrentCooldown(int _currentCooldown)
{
	Spell::_currentCooldown = _currentCooldown;
}

