#include "pch.h"
#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialize()
{
	logo.setSize({ 100.0f,100.0f });
	logo.setOrigin(50.0f, 50.0f);
	logo.setPosition(500.0f, 500.0f);
}

void SplashScreen::eventHandler(sf::Event& event)
{
}

void SplashScreen::update(float delTime)
{
	logo.rotate(10 * delTime);
}

void SplashScreen::draw(sf::RenderTarget& renderer)
{
	renderer.draw(logo);
}
