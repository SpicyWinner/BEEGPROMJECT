#include "pch.h"
#include "AssetManager.hpp"
#include<iostream>

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

AssetManager* AssetManager::access()
{
	static AssetManager assMan;
	return &assMan;
}

void AssetManager::loadGlobalAssets()
{
	//fonts
	loadFont("default_font", "data/fonts/consola.ttf");

	//textures
	loadTexture("texture_not_found", "data/images/NAtex.png");
	loadTexture("logo", "data/images/goat.png");
	loadTexture("Title", "data/images/Title.png");
	loadTexture("testSprite", "data/images/testSprite.png");
	loadTexture("creds", "data/images/creds.png");
	loadTexture("lightning", "data/images/lightning.png");
	loadTexture("mm_bg", "data/images/mainmenubg.png");
	loadTexture("mm_h1", "data/images/h1.png");

	//sfx
	loadsfx("sfx_not_found", "data/audio/sfx/NAsfx.wav");
}

void AssetManager::loadTexture(std::string name, std::string filepath)
{
	sf::Texture temp;
	if (!temp.loadFromFile(filepath)) std::cout << name + " failed to load" << std::endl;
	else textures.insert(std::make_pair(name, temp));
}

void AssetManager::loadFont(std::string name, std::string filepath)
{
	sf::Font temp;
	if (!temp.loadFromFile(filepath)) std::cout << name + " failed to load" << std::endl;
	else fonts.insert(std::make_pair(name, temp));
}

void AssetManager::loadsfx(std::string name, std::string filepath)
{
	sf::SoundBuffer temp;
	if (!temp.loadFromFile(filepath)) std::cout << name + " failed to load" << std::endl;
	else sfx.insert(std::make_pair(name, temp));
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	if (textures.count(name)) return textures.at(name);
	else return textures.at("texture_not_found");
}

sf::Font& AssetManager::getFont(std::string name)
{
	if (fonts.count(name)) return fonts.at(name);
	else return fonts.at("default_font");
}

sf::SoundBuffer& AssetManager::getSFX(std::string name)
{
	if (sfx.count(name)) return sfx.at(name);
	else return sfx.at("sfx_not_found");
}
