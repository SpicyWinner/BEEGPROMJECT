#pragma once
#include"State.hpp"
#include"StateMachine.hpp"
#include"MainMenu.hpp"

class SplashScreen : public State
{
public:
	SplashScreen();
	~SplashScreen();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& renderer) override;

private:
	sf::Sprite logo;
	sf::RectangleShape boxA, boxB, boxC, boxD;
	
	float boxSpeed;

	sf::Clock delayClock;
};

