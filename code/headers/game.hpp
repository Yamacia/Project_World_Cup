#pragma once 
#include "constants.hpp"
#include "field.hpp"
#include "team.hpp"
#include "endscreen.hpp"
#include "utility.hpp"

class GameInstance : public EndScreen
{
protected:
    /* Les deux équipes qui jouent */
    Team team_gauche;
    Team team_droite;
    size_t score_gauche;
    size_t score_droite;

    /* Attributs généraux (background, musique)*/
    sf::Sprite background;
    sf::Sprite logo;
    sf::Music main_theme;
    std::vector<std::string> playlist;

    /* Attributs Menu */
    sf::Sprite menu_cursor;
    std::vector<sf::Text> menu;

    /* Attributs Options*/
    sf::Text toggle_song;
    sf::Text playing_song; // chanson en cours
    size_t current_song; // ID de la chanson en cours
    bool song; // savoir si la chanson est active ou non

    /* Attributs Jeu */
    Field terrain;
    sf::Sprite scoreboard;
    bool in_game; // savoir si on a lancé une partie ou non
    size_t turn; // Tour actuel
    sf::RectangleShape game_selector; 
    Player player_with_ball;

    /* Booléen du jeu */
    bool succesful_action; // si l'action est réussie
    bool pass_action; // si on veut faire une passe
    bool goal_confirmed; // si on a marqué
    bool toggle_boxes; // si on veut afficher les boites de texte


public:
    static GameInstance& Instance();
    GameInstance();
    ~GameInstance();

    /* Playlist */
    void loadMusic();
    void loadPlaylist();

    /* Création graphique */
    size_t cursorPosition(size_t x, size_t y, size_t selected);

    /* Méthodes menu */
    void menuStart(sf::RenderWindow& window);
    void loadBackgroundMenu();
    void loadLogo();
    void menuLoop(sf::RenderWindow& window);
    void menuDraw(sf::RenderWindow& window);

    /* Méthodes options */
    void optionStart(sf::RenderWindow& window);
    void optionLoop(sf::RenderWindow& window);
    void optionDraw(sf::RenderWindow& window);
    void toggleSong();
    void selectSong(size_t number);
    void updateSong();

    /* Méthodes jeu */
    void gameStart(sf::RenderWindow& window);
    void loadTeam();
    void giveBall();
    void loadBackground();
    void loadScore();
    void gamePlay(sf::RenderWindow& window);
    void gameLoop(sf::RenderWindow& window);
    void gameDraw(sf::RenderWindow& window);
    void updateTurn(sf::RenderWindow& window);
    void confirmTurn(sf::RenderWindow& window);
    void whoHasBall();
    void displayOptions();
    void updateTeamPositions();
    void updateBallPosition();
    void passOptions(sf::RenderWindow& window);
    void confirmGoal();
    void gameEnd(sf::RenderWindow& window);

    /* Message d'erreur */
    void dribbleErrorMessage(sf::RenderWindow& window);

    /* Constantes */
    sf::Text return_text = createText("Retour", 30, 325, 389);
    sf::Text tab = createText("Appuyez sur Tab pour cacher le menu", 12, 492, 425);
    sf::Text tour = createText("Tour " + std::to_string(turn), 30, 195, 223);
    sf::Text sc_gauche = createText(std::to_string(score_gauche), 30, 285, 5);
    sf::Text sc_droite = createText(std::to_string(score_droite), 30, 445, 5);
    sf::Text big_dialog_box = createText("", 20, 50, 268);
    sf::Text text_1 = createText("", 20, 490, 256);
    sf::Text text_2 = createText("", 20, 490, 311);
    sf::Text text_3 = createText("", 20, 490, 366);
    sf::Text info_dialog = createText("", 20, 50, 420);

    /* Joueurs à qui faire la passe */
    Player* player_option_1;
    Player* player_option_2;
    Player* player_option_3;
};