#include"pch.h"
#include<SFML/Graphics.hpp>
#include"SFMLOrthogonalLayer.hpp"
#include"MainApplication.hpp"

int main()
{
	MainApplication app(sf::VideoMode(1920, 1080), "Unchipped");
	app.run();
	return 0;
}