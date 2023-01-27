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
    /* Variables pour la musique */
    loadMusic();
    loadPlaylist();
    song = true;

    /* Variables pour le jeu */
    terrain = Field(LARGEUR_TERRAIN, HAUTEUR_TERRAIN);
    succesful_action = false;
    turn = 0;
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
    playlist.push_back("../musique/nfl_theme.wav"); // NFL Theme Song
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

            if(event.type == sf::Event::KeyPressed) // Sélection de paramètres
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

            if(event.type == sf::Event::KeyPressed) // Sélection de paramètres
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
                    if(current_song == 0) // Aller au dernier si on est au premier
                        current_song = 3;
                    else
                        current_song--;
                    selectSong(current_song);
                    updateSong();
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && selected == 1)
                {
                    if(current_song == 3) // Aller au premier si on est au dernier
                        current_song = 0;
                    else
                        current_song++;
                    selectSong(current_song);
                    updateSong();
                }
                if((InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 2) || (InputManager::Instance().GetKey(sf::Keyboard::Key::P)))
                {
                    if(!in_game) // Retourner dans le jeu directement si on a commencé une partie
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
        case 3:
            playing_song = createText("NFL Theme Song", 15, 320, 320);
        default:
            break;
    }
}

/* Démarre le jeu */
void GameInstance::gameStart(sf::RenderWindow& window)
{
    loadTeam();
    team_gauche.randomPlayerBall();

    loadBackground();
    loadScore();
    tour = createText("Tour " + std::to_string(turn), 30, 195, 223);

    game_selector.setSize(sf::Vector2f(LARGEUR_BOX, HAUTEUR_BOX));
    game_selector.setFillColor(sf::Color::Transparent);
    game_selector.setOutlineColor(sf::Color::Red);
    game_selector.setOutlineThickness(2);

    goal_confirmed = false;
    gamePlay(window);
}

/* Charge les équipes sur l'interface graphique */
void GameInstance::loadTeam()
{
    team_gauche = Team("France", "Antoine Griezmann, Olivier Giroud, Karim Benzema, Kylian Mbappe, Hugo Lloris, Paul Pogba, Adrien Rabiot, Nabil Fekir, Kingsley Coman, Theo Hernandez, Lucas Digne");

    team_droite = Team("Portugal", "Christiano Ronaldo, Bruno Fernandes, Goncalo Guedes, Diogo Jota, Ruben Neves, Andre Silva, Joao Cancelo, Rafael Leao, Nuno Mendes, Raphael Guerreiro, Rui Patricio");
}

/* Donne la balle à l'équipe correspondante */
void GameInstance::giveBall()
{
    loadTeam();
    if(player_with_ball.getOrigin() == "France")
    {
        team_droite.randomPlayerBall();
    }
    else
    {
        team_gauche.randomPlayerBall();
    }
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
void GameInstance::gamePlay(sf::RenderWindow& window)
{
    toggle_boxes = true;
    updateTurn(window);
    gameLoop(window);
    
    gameEnd(window);

    window.close();
}

/* Boucle de jeu */
void GameInstance::gameLoop(sf::RenderWindow& window)
{
    /* Rectangle de sélection d'action */
    size_t selector = 0;
    game_selector.setPosition(480, 246);
    while(window.isOpen() && turn < MAX_TOURS) // Dépasse pas le max de tours imposé
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
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Tab)) // Cacher l'interface
                {
                    toggle_boxes = !toggle_boxes;
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::P)) // Options
                {
                    optionStart(window);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Up)) // Selectionner une case
                {
                    if(toggle_boxes && selector > 0)
                    {
                        selector--;
                        game_selector.setPosition(game_selector.getPosition().x, game_selector.getPosition().y - 55);
                    }
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down)) // Selectionner une case
                {
                    if(toggle_boxes && selector < 2)
                    {
                        selector++;
                        game_selector.setPosition(game_selector.getPosition().x, game_selector.getPosition().y + 55);
                    }
                }
            }
            if(player_with_ball.getOrigin() == "France") // Actions quand on a la balle
            {
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && toggle_boxes && pass_action) // Action de passe
                {
                    if(selector == 0) // Joueur 1
                    {
                        succesful_action = player_with_ball.pass(player_with_ball.pass_proba(*player_option_1));
                        team_gauche(player_with_ball.getName())->set_ball(false);
                        player_option_1->set_ball(true);
                        confirmTurn(window);
                        updateTurn(window);
                    }
                    if(selector == 1) // Joueur 2
                    {
                        succesful_action = player_with_ball.pass(player_with_ball.pass_proba(*player_option_2));
                        team_gauche(player_with_ball.getName())->set_ball(false);
                        player_option_2->set_ball(true);
                        confirmTurn(window);
                        updateTurn(window);
                    }
                    if(selector == 2) // Joueur 3
                    {
                        succesful_action = player_with_ball.pass(player_with_ball.pass_proba(*player_option_3));
                        team_gauche(player_with_ball.getName())->set_ball(false);
                        player_option_3->set_ball(true);
                        confirmTurn(window);
                        updateTurn(window);
                    }
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && toggle_boxes && !pass_action) // Actions de base
                {
                    if(selector == 1) // Dribbler
                    {
                        if(player_with_ball.getX() <= LARGEUR_TERRAIN)
                        {
                            succesful_action = player_with_ball.dribble_right(player_with_ball.dribble_proba(terrain.howManyOpponent(player_with_ball.getX(), player_with_ball.getY(), team_droite)));
                            confirmTurn(window);
                            updateTurn(window);
                        }
                        else
                        {
                            dribbleErrorMessage(window);
                        }

                    }
                    if(selector == 2) // Tirer
                    {
                        succesful_action = player_with_ball.shoot(player_with_ball.shoot_proba_right());
                        if(succesful_action)
                        {
                            confirmGoal();
                        }
                        confirmTurn(window);
                        updateTurn(window);
                    }
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::LControl) && toggle_boxes)
                {
                    if(selector == 0 && !pass_action) // Faire la passe
                    {
                        passOptions(window);
                        pass_action = true;
                    }
                    
                }
            }
            else // Actions lorsqu'on n'a pas la balle
            {
                pass_action = false;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && toggle_boxes && !pass_action && selector == 2) // Confirmer le tour
                {
                    if(player_with_ball.getX() > 1) // Avance si possible
                    {
                        succesful_action = player_with_ball.dribble_left(player_with_ball.dribble_proba(terrain.howManyOpponent(player_with_ball.getX(), player_with_ball.getY(), team_gauche)));
                    }
                    else // Tire sinon
                    {
                        succesful_action = player_with_ball.shoot(player_with_ball.shoot_proba_left());
                        if(succesful_action)
                        {
                            confirmGoal();
                        }
                    }
                    confirmTurn(window);
                    updateTurn(window);
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

    for(Player i : team_gauche.getTeam()) // Afficher équipe de gauche
    {
        i.setSpriteball();
        sf::CircleShape sprite = i.getSprite();
        window.draw(sprite);
    }

    for(Player i : team_droite.getTeam()) // Afficher équipe de droite
    {
        i.setSpriteball();
        sf::CircleShape sprite = i.getSprite();
        window.draw(sprite);
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
        window.draw(info_dialog);
    }

    window.display();
}

/* Met à jour le tour actuel */
void GameInstance::updateTurn(sf::RenderWindow& window)
{
    turn++;
    tour = createText("Tour " + std::to_string(turn), 30, 195, 223);
    if(turn == 42)
        tour = createText("Tour " + std::to_string(turn) + " Nice.", 30, 157, 223);
    sc_gauche = createText(std::to_string(score_gauche), 30, 285, 5);
    sc_droite = createText(std::to_string(score_droite), 30, 445, 5);

    updateTeamPositions();
    whoHasBall();
    displayOptions();
    gameDraw(window);
}

/* Permet de mettre le jeu en pause en attendant la confirmation de l'utilisateur */
void GameInstance::confirmTurn(sf::RenderWindow& window)
{
    if(!goal_confirmed) // Afficher si rien de spécial
    {
        if(player_with_ball.getOrigin() == "France")
        {
            if(succesful_action)
            {
                big_dialog_box = createText("L'action a reussi", 20, 50, 268);
            }
            else
            {
                big_dialog_box = createText("L'action a echoue.", 20, 50, 268);
                giveBall();
            }
        }
        else
        {
            if(succesful_action)
            {
                big_dialog_box = createText(player_with_ball.getName() + " a reussi a avancer", 20, 50, 268);
            }
            else
            {
                big_dialog_box = createText("Vous avez recupere la balle !", 20, 50, 268);
                giveBall();
            }
        }
    }
    
    info_dialog = createText("Appuyez sur Espace pour continuer.", 20, 50, 420);

    gameDraw(window);
    sf::Event event;
    while(window.pollEvent(event)) // Boucle qui permet de fixer le tour actuel
    {
        while(true)
        {
            if (event.type == sf::Event::Closed || InputManager::Instance().GetKey(sf::Keyboard::Key::Escape))
            {
                window.close();
                std::cout << "Closing the game intentionally..." << std::endl;
            }
            if(InputManager::Instance().GetKey(sf::Keyboard::Key::Space) && toggle_boxes)
            {   
                pass_action = false;
                goal_confirmed = false;            
                return;
            }
        }
    }
}

/* Permet de savoir quel joueur a la balle parmi tous */
void GameInstance::whoHasBall()
{
    if(!goal_confirmed)
    {
        for(Player i : team_gauche.getTeam())
        {
            std::string player_name = i.getName();
            if(team_gauche(player_name)->has_ball())
            {
                big_dialog_box = createText(player_name + " a la balle. \nQue voulez-vous faire ?", 20, 50, 268);
                player_with_ball = i;
            }
        };
        for(Player i : team_droite.getTeam())
        {
            std::string player_name = i.getName();
            if(team_droite(player_name)->has_ball())
            {
                big_dialog_box = createText(player_name + " a la balle. \nIl va essayer d'avancer. \nVotre equipe va essayer de le bloquer.", 20, 50, 268);
                player_with_ball = i;
            }
        };
    }
    
}

/* Affiche les différentes possibilités d'action */
void GameInstance::displayOptions()
{
    if(player_with_ball.getOrigin() == "France") // L'utilisateur possède la balle
    {
        size_t NbAdversaire = terrain.howManyOpponent(player_with_ball.getX(), player_with_ball.getY(), team_droite);
        info_dialog = createText(std::to_string(NbAdversaire) + " adversaires sur cette case.", 20, 50, 420);
        text_1 = createText("Passer (Control)", 20, 490, 256);
        text_2 = createText("Dribbler (" + std::to_string(player_with_ball.dribble_proba(NbAdversaire)) + "%)", 20, 490, 311);
        text_3 = createText("Tirer (" + std::to_string(player_with_ball.shoot_proba_right()) + "%)", 20, 490, 366);
    }
    else // L'utilisateur doit défendre
    {
        size_t NbAdversaire = terrain.howManyOpponent(player_with_ball.getX(), player_with_ball.getY(), team_gauche);
        info_dialog = createText(std::to_string(NbAdversaire) + " adversaires sur cette case.", 20, 50, 420);
        text_1 = createText("Chances de reussite :", 20, 500, 256);
        text_2 = createText(std::to_string(player_with_ball.dribble_proba(NbAdversaire)), 20, 580, 311);
        text_3 = createText("Confirmer.", 20, 545, 366);
    }


}

/* Met la jour la position de tous les joueurs au tour suivant */
void GameInstance::updateTeamPositions()
{
    team_gauche.updatePosition();
    team_droite.updatePosition();
    updateBallPosition();
}

/* Met à jour quel joueur possède la tour au tour suivant */
void GameInstance::updateBallPosition()
{
    if(player_with_ball.getOrigin() == "France")
    {
        team_gauche(player_with_ball.getName())->setPosition(player_with_ball.getX(), player_with_ball.getY());
    }
    else
    {
        team_droite(player_with_ball.getName())->setPosition(player_with_ball.getX(), player_with_ball.getY());
    }
}

/* Message d'erreur lorsque le joueur ne peut plus avancer */
void GameInstance::dribbleErrorMessage(sf::RenderWindow& window)
{
    big_dialog_box = createText("Erreur : Vous ne pouvez plus avancer.", 20, 50, 268);
    gameDraw(window);
}

/* Donne les différents joueurs à qui on peut faire la passe */
void GameInstance::passOptions(sf::RenderWindow& window)
{
    player_option_1 = team_gauche.randomPlayerPass();
    player_option_2 = team_gauche.randomPlayerPass();
    player_option_3 = team_gauche.randomPlayerPass();

    text_1 = createText(player_option_1->getName() + " (" + std::to_string(player_with_ball.pass_proba(*player_option_1)) + "%)", 20, 490, 256);
    text_2 = createText(player_option_2->getName() + " (" + std::to_string(player_with_ball.pass_proba(*player_option_2)) + "%)", 20, 490, 311);
    text_3 = createText(player_option_3->getName() + " (" + std::to_string(player_with_ball.pass_proba(*player_option_3)) + "%)", 20, 490, 366);

    gameDraw(window);

}

/* Met à jour le score, la disposition des équipes et l'équipe qui a la balle */
void GameInstance::confirmGoal()
{
    big_dialog_box = createText("But de " + player_with_ball.getName() + " !", 20, 50, 268);
    goal_confirmed = true;
    loadTeam();
    if(player_with_ball.getOrigin() == "France")
    {
        score_gauche++;
        team_droite.randomPlayerBall();
    }
    else
    {
        score_droite++;
        team_gauche.randomPlayerBall();
    }
    whoHasBall();
}

/* Affiche l'écran de fin correspondant */
void GameInstance::gameEnd(sf::RenderWindow& window)
{
    main_theme.stop();
    if(score_gauche > score_droite) // Victoire
    {
        EndScreen::Instance().loadBackgroundEndVictory(window);
    }
    if(score_gauche < score_droite) // Défaite
    {
        EndScreen::Instance().loadBackgroundEndDefeat(window);
    }
    else // Match Nul
    {
        EndScreen::Instance().loadBackgroundEndDraw(window);
    }
}
