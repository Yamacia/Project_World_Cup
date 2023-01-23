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
    sf::Music main_theme;
    sf::RectangleShape cursor;

    sf::Text menu[3];


public:
    GameInstance();
    ~GameInstance();

    static GameInstance& Instance();
    void loadMusic();


    void gameMenu(sf::RenderWindow& window);
    void loadMenu();
    void loadBackgroundMenu();
    void menuLoop(sf::RenderWindow& window);

    void gameStart(sf::RenderWindow& window);
    void loadTeam();
    void loadBackground();
    void gameLoop(sf::RenderWindow& window);

};