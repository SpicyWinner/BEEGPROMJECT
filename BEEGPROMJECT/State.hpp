#pragma once
#include<SFML/Graphics.hpp>

class State
{
public:
	virtual void initialize() = 0;
	virtual void eventHandler(sf::Event& event, const sf::RenderWindow& window) = 0;
	virtual void update(float delTime) = 0;
	virtual void draw(sf::RenderTarget& target) = 0;
};
