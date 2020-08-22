#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


class AssetManager : public sf::NonCopyable
{
public:
	AssetManager();
	~AssetManager();

	static AssetManager* access();

	void loadGlobalAssets();

	void loadTexture(std::string name, std::string filepath);
	void loadFont(std::string name, std::string filepath);
	void loadsfx(std::string name, std::string filepath);
	

	sf::Texture& getTexture(std::string name);
	sf::Font& getFont(std::string name);
	sf::SoundBuffer& getSFX(std::string name);

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::SoundBuffer> sfx;
	
};

