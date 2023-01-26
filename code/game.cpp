#include "headers/game.hpp"
#include "headers/inputmanager.hpp"

/* Unique instance de jeu */
GameInstance& GameInstance::Instance()
{
    static GameInstance gameManager;
    return gameManager;
}

/* Initialise la musique au lancer */
GameInstance::GameInstance()
{
    loadMusic();
    loadPlaylist();
    song = true;

    turn = 1;
    in_game = false;
    score_gauche = 0;
    score_droite = 0;
}

/* Destructeur de GameInstance */
GameInstance::~GameInstance()
{
}

/* Joue la musique sélectionnée*/
void GameInstance::loadMusic()
{
    /* Création musique principale */
    main_theme.openFromFile("../musique/world_cup.wav");
    current_song = 0;

    /* Musique en boucle */
    main_theme.setLoop(true);
    main_theme.setVolume(10);
    main_theme.play();    
}

/* Charge la playlist disponible */
void GameInstance::loadPlaylist()
{
    playlist.push_back("../musique/world_cup.wav"); // iShowSpeed - World Cup
    playlist.push_back("../musique/waving_flag.wav"); // K'NAAN - Waving Flag
    playlist.push_back("../musique/espana.wav"); // Amine - La Roja
}

/* Crée une petite boite de dialogue à la position désirée */
sf::Sprite GameInstance::createBox(size_t l_pos, size_t h_pos)
{
    sf::Texture *text_box = new sf::Texture;
    text_box->loadFromFile("../images/box_blank.png");
    sf::Sprite box(*text_box);
    box.setTextureRect(sf::IntRect(0, 0, LARGEUR_BOX, HAUTEUR_BOX));
    box.setPosition(l_pos,h_pos);
    return box;
}

/* Crée une grande boite de dialogue à la position désirée */
sf::Sprite GameInstance::createBigBox(size_t l_pos, size_t h_pos)
{
    sf::Texture *text_box = new sf::Texture;
    text_box->loadFromFile("../images/big_box_blank.png");
    sf::Sprite box(*text_box);
    box.setTextureRect(sf::IntRect(0, 0, LARGEUR_BIG, HAUTEUR_BIG));
    box.setPosition(l_pos,h_pos);
    return box;
}

/* Crée le texte à la position et taille désirées */
sf::Text GameInstance::createText(std::string string, size_t size, size_t l_pos, size_t h_pos)
{
    sf::Font *font = new sf::Font;
    font->loadFromFile("../font/arial.ttf");

    sf::Text text;
    text.setFont(*font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setString(string);
    text.setPosition(sf::Vector2f(l_pos,h_pos));

    return text;
}

/* Bouge le curseur de choix (Menu / Option) à la case désirée */
size_t GameInstance::cursorPosition(size_t x, size_t y, size_t selected)
{
    sf::Texture *arrow_cursor = new sf::Texture;
    arrow_cursor->loadFromFile("../images/Selection.png");
    menu_cursor.setTexture(*arrow_cursor);
    menu_cursor.setPosition(x,y);
    return selected;
}

/* Charge le menu */
void GameInstance::menuStart(sf::RenderWindow& window)
{
    loadBackgroundMenu();
    loadLogo();
    sf::Text text;

    text = createText("Jouer", 30, 330, 229);
    menu.push_back(text);

    text = createText("Options", 30, 320, 309);
    menu.push_back(text);

    text = createText("Quitter", 30, 320, 389);
    menu.push_back(text);

    menuLoop(window);

}

/* Charge l'image de fond du menu */
void GameInstance::loadBackgroundMenu()
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/menu.png");
    background.setTexture(*menu_screen);
}

/* Charge le logo du jeu */
void GameInstance::loadLogo()
{
    sf::Texture *menu_logo = new sf::Texture;
    menu_logo->loadFromFile("../images/logo.png");
    logo.setTexture(*menu_logo);
    logo.setTextureRect(sf::IntRect(0,0,202,190));
    logo.setPosition(275,10);
}

/* Crée une fenêtre interactive (Menu) */
void GameInstance::menuLoop(sf::RenderWindow& window)
{
    size_t selected = cursorPosition(188, 225, 0);
     
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || InputManager::Instance().GetKey(sf::Keyboard::Key::Escape))
            {
                window.close();
                std::cout << "Closing the game intentionally..." << std::endl;
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Up) && selected > 0)
                {
                    selected = cursorPosition(menu_cursor.getPosition().x, menu_cursor.getPosition().y - 80, --selected);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down) && selected < 2)
                {
                    selected = cursorPosition(menu_cursor.getPosition().x, menu_cursor.getPosition().y + 80, ++selected);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 0)
                {
                    in_game = true;
                    gameStart(window);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 1)
                {
                    optionStart(window);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 2)
                {
                    window.close();
                }
            }
            menuDraw(window);
        }
    }

}

/* Affiche l'interface graphique (Menu) */
void GameInstance::menuDraw(sf::RenderWindow& window)
{
    sf::Sprite play_box = createBox(255,225);
    sf::Sprite option_box = createBox(255,305);
    sf::Sprite exit_box = createBox(255,385);

    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(logo);
    window.draw(play_box);
    window.draw(option_box);
    window.draw(exit_box);
    window.draw(menu_cursor);
    for(auto &text : menu)
    {
        window.draw(text);
    }

    window.display();

}

/* Charge les options */
void GameInstance::optionStart(sf::RenderWindow& window)
{
    if(in_game)
        tour = createText("", 30, 190, 223);
    updateSong();
    optionLoop(window);
}

/* Crée une fenêtre interactive (Option) */
void GameInstance::optionLoop(sf::RenderWindow& window)
{
    size_t selected = cursorPosition(188, 225, 0);
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || InputManager::Instance().GetKey(sf::Keyboard::Key::Escape))
            {
                window.close();
                std::cout << "Closing the game intentionally..." << std::endl;
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Up) && selected > 0)
                {
                    selected = cursorPosition(menu_cursor.getPosition().x, menu_cursor.getPosition().y - 80, --selected);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down) && selected < 2)
                {
                    selected = cursorPosition(menu_cursor.getPosition().x, menu_cursor.getPosition().y + 80, ++selected);
                }
                if((InputManager::Instance().GetKey(sf::Keyboard::Key::Left) && selected == 0) || (InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && selected == 0))
                {
                    toggleSong();
                    updateSong();
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Left) && selected == 1)
                {
                    if(current_song == 0)
                        current_song = 2;
                    else
                        current_song--;
                    selectSong(current_song);
                    updateSong();
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && selected == 1)
                {
                    if(current_song == 2)
                        current_song = 0;
                    else
                        current_song++;
                    selectSong(current_song);
                    updateSong();
                }
                if((InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 2) || (InputManager::Instance().GetKey(sf::Keyboard::Key::P)))
                {
                    if(!in_game)
                        menuStart(window);
                    else
                        gameStart(window);
                }
            }
            optionDraw(window);
        }
    }
}

/* Affiche l'interface graphique (Option) */
void GameInstance::optionDraw(sf::RenderWindow& window)
{
    sf::Sprite toggle_box = createBox(255,225);
    sf::Sprite song_box = createBox(255, 305);
    sf::Sprite return_box = createBox(255,385);

    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(logo);
    window.draw(toggle_box);
    window.draw(song_box);
    window.draw(return_box);
    window.draw(toggle_song);
    window.draw(playing_song);
    window.draw(menu_cursor);
    window.draw(return_text);
    window.display();

}

/* Active ou désactive la musique */
void GameInstance::toggleSong()
{
    if(song)
    {
        main_theme.stop();
        song = false;
    }
    else
    {
        main_theme.play();
        song = true;
    }
}

/* Choisit une musique spécifique */
void GameInstance::selectSong(size_t number)
{
    std::string& new_song = playlist[number];
    song = true;
    main_theme.openFromFile(new_song);
    main_theme.play();
    main_theme.setLoop(true);
}

/* Met à jour les options de chanson */
void GameInstance::updateSong()
{
    if(song)
    {
        toggle_song = createText("Active", 30, 330, 229);
    }
    else
    {
        toggle_song = createText("Desactive", 30, 305, 229);
    }

    switch(current_song)
    {
        case 0:
            playing_song = createText("iShowSpeed - World Cup", 15, 290, 320);
            break;
        case 1:
            playing_song = createText("K'NAAN - Waving Flag", 15, 300, 320);
            break;
        case 2:
            playing_song = createText("Amine - La Roja", 15, 320, 320);
            break;
        default:
            break;
    }
}

/* Démarre le jeu */
void GameInstance::gameStart(sf::RenderWindow& window)
{
    loadTeam();
    loadBackground();
    loadScore();
    tour = createText("Tour " + std::to_string(turn), 30, 195, 223);

    game_cursor.setSize(sf::Vector2f(LARGEUR_CASE, HAUTEUR_CASE));
    game_cursor.setFillColor(sf::Color::Transparent);
    game_cursor.setOutlineColor(sf::Color::Red);
    game_cursor.setOutlineThickness(2);

    game_selector.setSize(sf::Vector2f(LARGEUR_BOX, HAUTEUR_BOX));
    game_selector.setFillColor(sf::Color::Transparent);
    game_selector.setOutlineColor(sf::Color::Red);
    game_selector.setOutlineThickness(2);

    gameLoop(window);
}

/* Charge les équipes sur l'interface graphique */
void GameInstance::loadTeam()
{

    team_gauche = Team("France", "Antoine Griezmann, Olivier Giroud");

    team_gauche("Antoine Griezmann")->set_ball(true); // marche pas LOL


}

/* Charge l'image de fond du jeu */
void GameInstance::loadBackground()
{
    sf::Texture *terrain = new sf::Texture;
    terrain->loadFromFile("../images/Field_no_grid.png");
    background.setTexture(*terrain);
}

/* Charge l'interface des scores */
void GameInstance::loadScore()
{
    sf::Texture *score = new sf::Texture;
    score->loadFromFile("../images/scoreboard.png");
    scoreboard.setTexture(*score);
    scoreboard.setTextureRect(sf::IntRect(0,0,230,86));
    scoreboard.setPosition(260,0);
}

/* Crée une fenêtre interactive (Jeu) */
void GameInstance::gameLoop(sf::RenderWindow& window)
{
    /* Carré de sélection de case */
    size_t cursor_x = 0;
    size_t cursor_y = 0;
    game_cursor.setPosition(cursor_x*LARGEUR_CASE + 29, cursor_y*HAUTEUR_CASE + 27);

    /* Rectangle de sélection d'action */
    size_t selector = 0;
    game_selector.setPosition(480, 246);

    toggle_boxes = true;
    whoHasBall();
    displayOptions();
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || InputManager::Instance().GetKey(sf::Keyboard::Key::Escape))
            {
                window.close();
                std::cout << "Closing the game intentionally..." << std::endl;
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Tab))
                {
                    toggle_boxes = !toggle_boxes;
                }
                /* Debuggage : pas dans le final */
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Space) && toggle_boxes)
                {
                    updateTurn();
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::P))
                {
                    optionStart(window);
                }
                /* Debuggage : pas dans le final */
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::R))
                {
                    score_gauche++;
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Up))
                {
                    if(toggle_boxes && selector > 0)
                    {
                        selector--;
                        game_selector.setPosition(game_selector.getPosition().x, game_selector.getPosition().y - 55);
                    }
                    if(!toggle_boxes && cursor_y > 0)
                    {
                        cursor_y--;
                        game_cursor.setPosition(cursor_x*LARGEUR_CASE + 29, cursor_y*HAUTEUR_CASE + 27);
                    }
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down))
                {
                    if(toggle_boxes && selector < 2)
                    {
                        selector++;
                        game_selector.setPosition(game_selector.getPosition().x, game_selector.getPosition().y + 55);
                    }
                    if(!toggle_boxes && cursor_y < HAUTEUR_TERRAIN)
                    {
                        cursor_y++;
                        game_cursor.setPosition(cursor_x*LARGEUR_CASE + 29, cursor_y*HAUTEUR_CASE + 27);
                    }   
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Left) && !toggle_boxes && cursor_x > 0)
                {
                    cursor_x--;
                    game_cursor.setPosition(cursor_x*LARGEUR_CASE + 29, cursor_y*HAUTEUR_CASE + 27);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && !toggle_boxes && cursor_x < LARGEUR_TERRAIN)
                {
                    cursor_x++;
                    game_cursor.setPosition(cursor_x*LARGEUR_CASE + 29, cursor_y*HAUTEUR_CASE + 27);
                }
            }
            
        }
        gameDraw(window);
    }
}

/* Affiche l'interface graphique (Jeu) */
void GameInstance::gameDraw(sf::RenderWindow& window)
{   
    window.clear(sf::Color::Black);
    window.draw(background);

    for(Player i : team_gauche.roster)
    {
        sf::CircleShape sprite = i.getSprite();
        window.draw(sprite);
    }

    if(!toggle_boxes)
    {
        window.draw(game_cursor);
    }

    /* Interface de dialogue (affichée ou non selon l'utilisateur) */
    if(toggle_boxes)
    {
        sf::Sprite large_box = createBigBox(35, 218);
        sf::Sprite option_1 = createBox(480, 246);
        sf::Sprite option_2 = createBox(480, 301);
        sf::Sprite option_3 = createBox(480, 356);
        sf::Sprite option_4 = createBox(480, 411);

        window.draw(large_box);  
        window.draw(option_1);
        window.draw(option_2);          
        window.draw(option_3);    
        window.draw(option_4);
        window.draw(text_1);
        window.draw(text_2);
        window.draw(text_3);
        window.draw(big_dialog_box);
        window.draw(tour);
        window.draw(tab);
        window.draw(scoreboard);
        window.draw(sc_gauche);
        window.draw(sc_droite);
        window.draw(game_selector);
        for(auto &text : actions_attaque)
        {
            window.draw(text);
        }
    }

    window.display();
}

/* Met à jour le tour actuel */
void GameInstance::updateTurn()
{
    turn++;
    tour = createText("Tour " + std::to_string(turn), 30, 195, 223);
    if(turn == 69)
        tour = createText("Tour " + std::to_string(turn) + " Nice.", 30, 157, 223);
    sc_gauche = createText(std::to_string(score_gauche), 30, 285, 5);
    sc_droite = createText(std::to_string(score_droite), 30, 445, 5);
}

void GameInstance::whoHasBall()
{
    std::cout << "methode WhoHasBall" << std::endl;
    for(Player i : team_gauche.roster)
    {
        std::string player_name = i.getName();
        std::cout << "le joueur est : " + player_name << std::endl;
        if(team_gauche(player_name)->has_ball())
            std::cout << player_name + " a la balle" << std::endl;
    };
}

void GameInstance::displayOptions()
{
    std::string temp = "_";
    text_1 = createText("Passer (" + temp + "%)", 20, 490, 256);
    text_2 = createText("Dribbler (" + temp + "%)", 20, 490, 311);
    text_3 = createText("Tirer (" + temp + "%)", 20, 490, 366);

}

// if(_x == 4 && _y == 7)
//     std::cout << "Theo Rouyer est beaucoup trop nul." << std::endl;
// if(_x == 4 && _y == 2)
//     std::cout << "Leonard Pannetier vient du Sud." << std::endl;
// if(_x == 12 && _y == 4)
//     std::cout << "Louis Leclercq est vraiment pas beau." << std::endl;

// game_cursor.setPosition(sf::Vector2f(_x*LARGEUR_CASE + 32, _y*HAUTEUR_CASE + 29));

