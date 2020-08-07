#include "pch.h"
#include "MainMenu.hpp"
#include<iostream>

MainMenu::MainMenu() : 
	PLAY(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "PLAY"),
	CREDITS(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "CREDITS"),
	EXIT(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "EXIT"),
	animator(AssetManager::access()->getTexture("testSprite"), sf::Vector2f(100.0f,100.0f), 0.25f)
{
	currentState = 0;
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

	logo.setTexture(AssetManager::access()->getTexture("testSprite"));
	logo.setPosition(960.0f, 200.0f);
}

void MainMenu::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	PLAY.EventHandler(event, window);
	CREDITS.EventHandler(event, window);
	EXIT.EventHandler(event, window);
}

void MainMenu::update(float delTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) currentState = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) currentState = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) currentState = 2;
	
	animator.update(logo, currentState);
}

void MainMenu::draw(sf::RenderTarget& target)
{
	PLAY.render(target);
	CREDITS.render(target);
	EXIT.render(target);
	target.draw(logo);
}
