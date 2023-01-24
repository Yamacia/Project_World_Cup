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
    static GameInstance& Instance();
    GameInstance();
    ~GameInstance();

    /* Playlist */
    void loadMusic();
    void loadPlaylist();

    /* Création graphique */
    sf::Sprite createBox(size_t l_pos, size_t h_pos);
    sf::Text createText(std::string string, size_t size, size_t l_pos, size_t h_pos);
    size_t cursorPosition(size_t x, size_t y, size_t selected);

    /* Méthodes menu */
    void menuStart(sf::RenderWindow& window);
    void loadBackgroundMenu();
    void menuLoop(sf::RenderWindow& window);
    void menuDraw(sf::RenderWindow& window);

    /* Méthodes options */
    void optionStart(sf::RenderWindow& window);
    void optionLoop(sf::RenderWindow& window);
    void optionDraw(sf::RenderWindow& window);
    void toggleSong();
    void selectSong(size_t number);

    /* Méthodes jeu */
    void gameStart(sf::RenderWindow& window);
    void loadTeam();
    void loadBackground();
    void gameLoop(sf::RenderWindow& window);
    void gameDraw(sf::RenderWindow& window);

};