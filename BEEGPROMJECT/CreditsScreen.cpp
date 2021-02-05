#include "pch.h"
#include "CreditsScreen.hpp"
#include<iostream>
#include"MainMenu.hpp"

CreditsScreen::CreditsScreen()
{
}

CreditsScreen::~CreditsScreen()
{
	std::cout << "\nCreditsScreen class is destroyed";
}

void CreditsScreen::initialize()
{
    banner.setTexture(AssetManager::access()->getTexture("spsc_banner"));

    creds.setTexture(AssetManager::access()->getTexture("spsc_creds"));
    util::eUtil::centerOrigin(creds);
    creds.setPosition(960,2080);
}

void CreditsScreen::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
}

void CreditsScreen::update(float delTime)
{
    creds.move(0, -50.0f * delTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || 
        creds.getPosition().y + creds.getGlobalBounds().height/2.0f < 0.0f) 
            StateMachine::access()->changeState(new MainMenu());

}

void CreditsScreen::draw(sf::RenderTarget& target)
{
    target.setView(target.getDefaultView());
    target.draw(creds);
    target.draw(banner);
}
