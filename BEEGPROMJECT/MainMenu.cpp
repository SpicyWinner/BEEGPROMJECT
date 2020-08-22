#include "pch.h"
#include "MainMenu.hpp"
#include<iostream>

MainMenu::MainMenu() : 
	PLAY(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "PLAY"),
	CREDITS(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "CREDITS"),
	EXIT(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "EXIT")
{
	currentAnimationState = 0;
	animGroup = 0;
	drawLight = true;
	aClock.restart().asSeconds();
	delayTimer.restart().asSeconds();
}

MainMenu::~MainMenu()
{
}

void MainMenu::initialize()
{
	PLAY.setPosition(sf::Vector2f(960.0f, 540.0f));
	CREDITS.setPosition(sf::Vector2f(960.0f, 640.0f));
	EXIT.setPosition(sf::Vector2f(960.0f, 740.0f));

	PLAY.setFunction([]() { std::cout << "PLAY!" << std::endl; });
	CREDITS.setFunction([]() { std::cout << "CREDITS!" << std::endl; });
	EXIT.setFunction([]() { exit(0); });

	logo.setTexture(AssetManager::access()->getTexture("goat"));
	util::eUtil::centerOrigin(logo);
	logo.setPosition(960.0f, 200.0f);

	ligt.setTexture(AssetManager::access()->getTexture("lightning"));
	ligt.setTextureRect(sf::IntRect(0, 0, 400, 400));
	ligt.setOrigin(200.0f, 200.0f);
	ligt.setPosition(200.0f, 200.0f);

	Test.setBuffer(AssetManager::access()->getSFX("skajfhekjf"));
}

void MainMenu::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	PLAY.EventHandler(event, window);
	CREDITS.EventHandler(event, window);
	EXIT.EventHandler(event, window);

	if (CREDITS.isClicked(window)) changeStateToCreds();
}

void MainMenu::update(float delTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) currentAnimationState = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) currentAnimationState = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) currentAnimationState = 2;
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Test.play();

	if (delayTimer.getElapsedTime().asSeconds() > 1.0f)
	{
		drawLight = true;
		delayTimer.restart().asSeconds();
	}
	
	lAnima(0.02f);

	//std::cout << "dL : " << drawLight << std::endl;
	

}

void MainMenu::draw(sf::RenderTarget& target)
{
	PLAY.render(target);
	CREDITS.render(target);
	EXIT.render(target);
	target.draw(logo);
	target.draw(ligt);
}

void MainMenu::lAnima(float switchTime)
{
	sf::IntRect rectTemp = ligt.getTextureRect();
	rectTemp.top = animGroup * 400;

	if (rectTemp.left < 3600 && drawLight)
	{
		if (aClock.getElapsedTime().asSeconds() > switchTime)
		{
			rectTemp.left += 400;
			ligt.setTextureRect(rectTemp);
			aClock.restart().asSeconds();
		}
	}
	else
	{
		animGroup = std::rand() % 5;
		std::cout << animGroup << std::endl;
		drawLight = false; 
		int x = std::rand() % 1520 + 200;
		int y = std::rand() % 140 + 200;
		ligt.setPosition(x, y);
		ligt.setTextureRect(sf::IntRect(0, 0, 400, 400));
	}
}

void MainMenu::changeStateToCreds()
{
	StateMachine::access()->changeState(new CreditsScreen());
}
