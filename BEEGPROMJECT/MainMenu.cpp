#include "pch.h"
#include "MainMenu.hpp"
#include<iostream>

MainMenu::MainMenu() : 
	PLAY(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "PLAY"),
	CREDITS(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "CREDITS"),
	EXIT(AssetManager::access()->getFont("yooy"), sf::Vector2f(256.0f, 64.0f), "EXIT")
{
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
}

void MainMenu::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
	PLAY.EventHandler(event, window);
	CREDITS.EventHandler(event, window);
	EXIT.EventHandler(event, window);
}

void MainMenu::update(float delTime)
{

}

void MainMenu::draw(sf::RenderTarget& target)
{
	PLAY.render(target);
	CREDITS.render(target);
	EXIT.render(target);
}
