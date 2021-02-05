#include "pch.h"
#include "SplashScreen.hpp"
#include "eUtil.hpp"

SplashScreen::SplashScreen()
{
	boxSpeed = 100.0f;
}

SplashScreen::~SplashScreen()
{
	std::cout << "\n SplashScreen class is destroyed";
}

void SplashScreen::initialize()
{
	logo.setTexture(AssetManager::access()->getTexture("logo"));
	util::eUtil::centerOrigin(logo);
	logo.setPosition(960.0f, 540.0f);

	boxA.setSize(sf::Vector2f(400.0f, 300.0f));
	util::eUtil::centerOrigin(boxA);
	boxA.setFillColor(sf::Color::Black);
	boxA.setPosition(860.0f, 440.0f);

	boxB.setSize(sf::Vector2f(400.0f, 300.0f));
	util::eUtil::centerOrigin(boxB);
	boxB.setFillColor(sf::Color::Black);
	boxB.setPosition(1160.0f, 440.0f);

	boxC.setSize(sf::Vector2f(400.0f, 300.0f));
	util::eUtil::centerOrigin(boxC);
	boxC.setFillColor(sf::Color::Black);
	boxC.setPosition(860.0f, 640.0f);

	boxD.setSize(sf::Vector2f(400.0f, 300.0f));
	util::eUtil::centerOrigin(boxD);
	boxD.setFillColor(sf::Color::Black);
	boxD.setPosition(1160.0f, 640.0f);

	delayClock.restart().asSeconds();
}

void SplashScreen::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{

}

void SplashScreen::update(float delTime)
{
	if (delayClock.getElapsedTime().asSeconds() >= 0.5f)
	{
		boxA.move(0.0f, -boxSpeed * delTime);
		boxB.move(boxSpeed * delTime, 0.0f);
		boxC.move(-boxSpeed * delTime, 0.0f);
		boxD.move(0.0f, boxSpeed * delTime);
	}
	if (delayClock.getElapsedTime().asSeconds() >= 7.0f) StateMachine::access()->changeState(new MainMenu());
}

void SplashScreen::draw(sf::RenderTarget& renderer)
{
	renderer.setView(renderer.getDefaultView());
	renderer.draw(logo);
	renderer.draw(boxA);
	renderer.draw(boxB);
	renderer.draw(boxC);
	renderer.draw(boxD);

}
