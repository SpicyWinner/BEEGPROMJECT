#pragma once
#include<SFML/Graphics.hpp>

class Weapon
{
public:
	Weapon(std::string ID, sf::Texture& txr, float damage);
	~Weapon();

	void update(float delTime);

	void render(sf::RenderTarget& target);

	void addAmmo(unsigned int increment);

private:
	sf::RectangleShape body;

	
	
	unsigned int ammo;
	float damage;
	std::string ID;
};

