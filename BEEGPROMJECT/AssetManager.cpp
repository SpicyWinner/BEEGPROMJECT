#include "pch.h"
#include "AssetManager.hpp"

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

void AssetManager::loadTexture(std::string name, std::string filepath)
{
	sf::Texture temp;
	temp.loadFromFile(filepath);
	textures.insert(std::make_pair(name, temp));
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	return textures.at(name);
}
