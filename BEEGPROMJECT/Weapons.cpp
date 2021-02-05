#include "pch.h"
#include "Weapons.hpp"

Weapon::Weapon(std::string ID, sf::Texture& txr, float damage ):
	 damage(damage), ID(ID)
{
	ammo = 0;
	body.setTexture(&txr);
}

Weapon::~Weapon()
{

}

void Weapon::addAmmo(unsigned int increment)
{
	ammo += increment;
}
