#include "pch.h"
#include "MainApplication.hpp"
#include "StateMachine.hpp"
#include "SplashScreen.hpp"

MainApplication::MainApplication(sf::VideoMode Vmode, std::string name)
{
	this->Vmode = Vmode;
	window.create(this->Vmode, name, sf::Style::Fullscreen);
	window.setFramerateLimit(200);
	delTime = 0;

	AssetManager::access()->loadGlobalAssets();

	StateMachine::access()->changeState(new SplashScreen());
}

MainApplication::~MainApplication()
{
}

void MainApplication::run()
{
	while (window.isOpen())
	{
		delTime = mainClock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			StateMachine::access()->getActiveState()->eventHandler(event, window);
		}

		StateMachine::access()->getActiveState()->update(delTime);

		window.clear();
		StateMachine::access()->getActiveState()->draw(window);
		window.display();
	}
}