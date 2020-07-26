#include "pch.h"
#include "Animator.hpp"

util::Animator::Animator(sf::Sprite& spr, sf::Vector2u gridSize, float switchTime)
{
	this->spr = spr;
	imageRect.top = imageRect.left = 0;
	imageRect.height = spr.getTexture()->getSize().y / gridSize.y;
	imageRect.width = spr.getTexture()->getSize().x / gridSize.x;
	states = gridSize.y;
	framesPerState = gridSize.x;
	this->switchTime = switchTime;
}

void util::Animator::updateAnimation(float deltaTime, int currentState)
{
	imageRect.top = currentState;
	referenceTime += deltaTime;
	
	if (referenceTime >= switchTime)
	{
		referenceTime = 0;
		if (imageRect.left + imageRect.width >= spr.getTexture()->getSize().x)
			imageRect.left = 0;
		else imageRect.left += imageRect.width;
	}

	spr.setTextureRect(imageRect);

}
