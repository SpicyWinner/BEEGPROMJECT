#pragma once
#include<SFML/Graphics.hpp>
#include"State.hpp"
#include"StateMachine.hpp"
#include"AssetManager.hpp"
#include"elib/Button.hpp"
#include"elib/Animator.hpp"

class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu();

	void initialize() override;
	void eventHandler(sf::Event& event, const sf::RenderWindow& window) override;
	void update(float delTime) override;
	void draw(sf::RenderTarget& target) override;

private:
	gui::Button PLAY, CREDITS, EXIT;

	sf::Sprite logo;

	util::Animator animator;

	int currentState;
};

