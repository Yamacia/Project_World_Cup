#pragma once 
#include "constants.hpp"
#include "field.hpp"

class Game
{

public:
    Game();
    ~Game();

    Game& instance();
    void gameLoop(sf::RenderWindow& window);
    void gameStart(sf::RenderWindow& window);
    void gameUpdate(sf::RenderWindow& window);
    void gameDraw(sf::RenderWindow& window);
};