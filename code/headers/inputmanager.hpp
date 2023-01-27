#pragma once
#include "constants.hpp"

class InputManager
{
private:
	bool oldIsPressesMouse[sf::Mouse::Button::ButtonCount];
	bool oldIsPressesKeyboard[sf::Keyboard::Key::KeyCount];
	bool newIsPressesMouse[sf::Mouse::Button::ButtonCount];
	bool newIsPressesKeyboard[sf::Keyboard::Key::KeyCount];
	sf::Vector2f oldMousePosition;
    sf::Vector2f newMousePosition;
    sf::Vector2f mouseVelosity;

	

public:
	InputManager();
	static InputManager& Instance();

	bool GetKey(sf::Mouse::Button button);
	bool GetKey(sf::Keyboard::Key key);
	bool GetKeyDown(sf::Mouse::Button button);
	bool GetKeyDown(sf::Keyboard::Key key);

	sf::Vector2f MousePosition();
	sf::Vector2f MouseVelocity();

	void Start(sf::RenderWindow& window);

};
