#include "headers/inputmanager.hpp"

InputManager::InputManager()
{

}

InputManager& InputManager::Instance()
{
	static InputManager instance;
	return instance;
}

bool InputManager::GetKey(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

bool InputManager::GetKey(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool InputManager::GetKeyDown(sf::Mouse::Button button)
{
	return !oldIsPressesMouse[(int)button] && newIsPressesMouse[(int)button];
}

bool InputManager::GetKeyDown(sf::Keyboard::Key key)
{
	return !oldIsPressesKeyboard[(int)key] && newIsPressesKeyboard[(int)key];
}

sf::Vector2f InputManager::MousePosition()
{
	return newMousePosition;
}

sf::Vector2f InputManager::MouseVelocity()
{
	return mouseVelosity;
}

void InputManager::Start(sf::RenderWindow& window)
{
	for (int i = 0; i < (int)sf::Mouse::Button::ButtonCount; i++)
	{
		this->oldIsPressesMouse[i] = false;
		this->newIsPressesMouse[i] = false;
	}

	for (int i = 0; i < (int)sf::Keyboard::Key::KeyCount; i++)
	{
		this->newIsPressesKeyboard[i] = false;
	}

	sf::Vector2u tmp = window.getSize();
	sf::Mouse::setPosition(sf::Vector2i(tmp.x * 0.5, tmp.y * 0.5), window);
	oldMousePosition = sf::Vector2f(0, 0);
	newMousePosition = sf::Vector2f(0, 0);
	mouseVelosity = sf::Vector2f(0, 0);
}