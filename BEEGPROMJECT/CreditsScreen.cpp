#include "pch.h"
#include "CreditsScreen.hpp"
#include<iostream>
#include"MainMenu.hpp"

CreditsScreen::CreditsScreen()
{
}

CreditsScreen::~CreditsScreen()
{
}

void CreditsScreen::initialize()
{
   

	logo.setTexture(AssetManager::access()->getTexture("logo"));
    logo.setScale(0.7f, 0.7f);
    util::eUtil::centerOrigin(logo);
    logo.setPosition(600, 100);

    //name
    NAME.setFont(AssetManager::access()->getFont("ekjadfbe"));
    NAME.setCharacterSize(50);
    NAME.setString("RADIOACTIVE GOAT STUDIDOS");
    NAME.setOrigin(0, NAME.getGlobalBounds().height / 2.0f);
    NAME.setPosition(logo.getPosition().x + logo.getGlobalBounds().width/2.0f, 100);

    creds.setTexture(AssetManager::access()->getTexture("creds"));
    util::eUtil::centerOrigin(creds);
    creds.setPosition(960,2080);
}

void CreditsScreen::eventHandler(sf::Event& event, const sf::RenderWindow& window)
{
}

void CreditsScreen::update(float delTime)
{
    creds.move(0, -50.0f * delTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || creds.getPosition().y + creds.getGlobalBounds().height/2.0f < 0.0f) StateMachine::access()->changeState(new MainMenu());

}

void CreditsScreen::draw(sf::RenderTarget& target)
{
    target.draw(creds);
    target.draw(logo);
    target.draw(NAME);
    
}
