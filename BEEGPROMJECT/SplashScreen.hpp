#pragma once
#include"State.hpp"

class SplashScreen : public State
{
public:
	SplashScreen();
	~SplashScreen();

	void initialize() override;
	void eventHandler(sf::Event& event) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& renderer) override;

private:
	sf::RectangleShape logo;
};

