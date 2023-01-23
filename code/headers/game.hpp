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
    std::vector<std::string> playlist;
    size_t current_song;
    bool song;


public:
    GameInstance();
    ~GameInstance();

    /* Méthodes générales */
    static GameInstance& Instance();
    void loadMusic();
    void loadPlaylist();

    /* Méthodes menu */
    void gameMenu(sf::RenderWindow& window);
    void loadMenu();
    void loadBackgroundMenu();
    void menuLoop(sf::RenderWindow& window);
    void menuDraw(sf::RenderWindow& window);

    /* Méthodes options */
    void loadOption(sf::RenderWindow& window);
    void drawOption(sf::RenderWindow& window);
    void toggleSong();
    void selectSong(size_t number);

    /* Méthodes jeu */
    void gameStart(sf::RenderWindow& window);
    void loadTeam();
    void loadBackground();
    void gameLoop(sf::RenderWindow& window);
    void gameDraw(sf::RenderWindow& window);

};