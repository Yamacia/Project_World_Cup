#include "game.hpp"

Game::Game(){}

Game::~Game(){}

Game& Game::instance()
{
    static Game gameManager;
    return gameManager;
}

void Game::gameLoop(sf::RenderWindow& window)
{
    while(window.isOpen())
    {
        gameUpdate(window);

        window.clear(sf::Color::Black);
        gameDraw(window);
        window.display();
    }
}

void Game::gameStart(sf::RenderWindow& window)
{

}

void Game::gameUpdate(sf::RenderWindow& window)
{

}

void Game::gameDraw(sf::RenderWindow& window)
{
    
}