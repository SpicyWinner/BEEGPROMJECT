#pragma once
#include<SFML/Graphics.hpp>


class AssetManager : public sf::NonCopyable
{
public:
	AssetManager();
	~AssetManager();

	static AssetManager* access();

	void loadTexture(std::string name, std::string filepath);

	sf::Texture& getTexture(std::string name);

private:
	std::map<std::string, sf::Texture> textures;
};

