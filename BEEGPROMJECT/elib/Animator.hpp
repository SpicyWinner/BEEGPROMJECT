#pragma once
#include<SFML/Graphics.hpp>

namespace util
{
	class Animator
	{
	public:
		Animator(sf::Sprite& spr, sf::Vector2u gridSize, float switchTime);

		void updateAnimation(float deltaTime, int currentState);

	private:
		sf::IntRect imageRect;
		sf::Sprite spr;

		float referenceTime, switchTime;

		int states, framesPerState;
	};
}