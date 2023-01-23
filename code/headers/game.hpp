#pragma once 
#include "constants.hpp"
#include "field.hpp"
#include "team.hpp"

class GameInstance
{
protected:
    std::vector<Player> team_1;
    std::vector<Player> team_2;
    sf::Sprite background;
    sf::Sprite menu_cursor;
    sf::RectangleShape game_cursor;
    sf::Music main_theme;
    std::vector<sf::Text> menu;


public:
    GameInstance();
    ~GameInstance();

    /* Méthodes générales */
    static GameInstance& Instance();
    void loadMusic();

    /* Méthodes menu */
    void gameMenu(sf::RenderWindow& window);
    void loadMenu();
    void loadBackgroundMenu();
    void menuLoop(sf::RenderWindow& window);
    void menuDraw(sf::RenderWindow& window);

    /* Méthodes jeu */
    void gameStart(sf::RenderWindow& window);
    void loadTeam();
    void loadBackground();
    void gameLoop(sf::RenderWindow& window);
    void gameDraw(sf::RenderWindow& window);

};