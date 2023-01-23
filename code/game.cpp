#include "headers/game.hpp"
#include "headers/inputmanager.hpp"

GameInstance::GameInstance()
{
    loadMusic();
    loadPlaylist();
    loadMenu();
    song = true;
}

GameInstance::~GameInstance()
{
}

GameInstance& GameInstance::Instance()
{
    static GameInstance gameManager;
    return gameManager;
}

void GameInstance::loadMenu()
{
    sf::Font *font = new sf::Font;
    font->loadFromFile("../font/arial.ttf");
    std::cout << "Succesfully loaded font : Arial" << std::endl;
    sf::Text text;
    text.setFont(*font);

    text.setFillColor(sf::Color::White);
    text.setString("Jouer");
    text.setCharacterSize(30);
    text.setPosition(sf::Vector2f(330,229));
    menu.push_back(text);

    text.setFillColor(sf::Color::White);
    text.setString("Option");
    text.setCharacterSize(30);
    text.setPosition(sf::Vector2f(320,309));
    menu.push_back(text);

    text.setFillColor(sf::Color::White);
    text.setString("Quitter");
    text.setCharacterSize(30);
    text.setPosition(sf::Vector2f(320,389));    
    menu.push_back(text);

}

void GameInstance::gameLoop(sf::RenderWindow& window)
{
    /* Carré de sélection de case */
    game_cursor.setSize(sf::Vector2f(LARGEUR_CASE, HAUTEUR_CASE));
    game_cursor.setFillColor(sf::Color::Transparent);
    game_cursor.setOutlineColor(sf::Color::Red);
    game_cursor.setOutlineThickness(2);
    size_t _x = 0;
    size_t _y = 0;

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
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Left) && _x > 0)
                    _x--;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && _x < LARGEUR_TERRAIN)
                    _x++;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Up) && _y > 0)
                    _y--;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down) && _y < HAUTEUR_TERRAIN)
                    _y++;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter))
                {
                    std::cout << "Case (" << _x << "," << _y << ")" << std::endl;
                    if(_x == 4 && _y == 7)
                        std::cout << "Theo Rouyer est beaucoup trop nul." << std::endl;
                    if(_x == 4 && _y == 2)
                        std::cout << "Leonard Pannetier vient du Sud." << std::endl;
                    if(_x == 12 && _y == 4)
                        std::cout << "Louis Leclercq est vraiment pas beau." << std::endl;
                }
            }
        }
        game_cursor.setPosition(sf::Vector2f(_x*LARGEUR_CASE + 32, _y*HAUTEUR_CASE + 29));
        gameDraw(window);
    }
}

void GameInstance::gameDraw(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    window.draw(background);

    for(auto player : team_1)
    {
        sf::CircleShape sprite = player.getSprite();
        window.draw(sprite);
    }     
    window.draw(game_cursor);        
    window.display();
}


void GameInstance::gameMenu(sf::RenderWindow& window)
{
    loadBackgroundMenu();
}

void GameInstance::loadBackgroundMenu()
{
    sf::Texture *menu_screen = new sf::Texture;
    menu_screen->loadFromFile("../images/menu.png");
    background.setTexture(*menu_screen);
    std::cout << "Fixed Background image with : Menu" << std::endl;
}

void GameInstance::menuLoop(sf::RenderWindow& window)
{
    sf::Texture *arrow_cursor = new sf::Texture;
    arrow_cursor->loadFromFile("../images/Selection.png");
    menu_cursor.setTexture(*arrow_cursor);
    size_t pixel_x = 188;
    size_t pixel_y = 225;
    menu_cursor.setPosition(pixel_x,pixel_y);
    size_t selected = 0;
     
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
                    selected--;
                    pixel_y -= 80;
                    menu_cursor.setPosition(pixel_x,pixel_y);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down) && selected < 2)
                {
                    selected++;
                    pixel_y += 80;
                    menu_cursor.setPosition(pixel_x,pixel_y);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 0)
                {
                    gameStart(window);
                    gameLoop(window);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 1)
                {
                    loadOption(window);
                    drawOption(window);
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

void GameInstance::menuDraw(sf::RenderWindow& window)
{
    sf::Texture *text_box = new sf::Texture;
    text_box->loadFromFile("../images/box_blank.png");
    sf::Sprite play_box(*text_box);
    play_box.setTextureRect(sf::IntRect(0, 0, 230, 48));
    play_box.setPosition(255,225);

    sf::Sprite option_box(*text_box);
    option_box.setTextureRect(sf::IntRect(0, 0, 230, 48));
    option_box.setPosition(255,305);

    sf::Sprite exit_box(*text_box);
    exit_box.setTextureRect(sf::IntRect(0, 0, 230, 48));
    exit_box.setPosition(255,385);

    window.clear(sf::Color::Black);
    window.draw(background);
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

void GameInstance::gameStart(sf::RenderWindow& window)
{
    loadTeam();
    loadBackground();
}

void GameInstance::loadTeam()
{
    /* Test Afficher Equipe de joueurs */

    Player french_player("Antoine Griezmann", "France");
    team_1.push_back(french_player);

    Player french_player_2("Olivier Giroud", "France");
    team_1.push_back(french_player_2);

}

void GameInstance::loadBackground()
{
    sf::Texture *terrain = new sf::Texture;
    terrain->loadFromFile("../images/Field_no_grid.png");
    background.setTexture(*terrain);
    std::cout << "Fixed Background image with : Game" << std::endl;
}

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

void GameInstance::loadOption(sf::RenderWindow& window)
{
    sf::Texture *arrow_cursor = new sf::Texture;
    arrow_cursor->loadFromFile("../images/Selection.png");
    menu_cursor.setTexture(*arrow_cursor);
    size_t pixel_x = 188;
    size_t pixel_y = 225;
    menu_cursor.setPosition(pixel_x,pixel_y);
    size_t selected = 0;

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
                    selected--;
                    pixel_y -= 80;
                    menu_cursor.setPosition(pixel_x,pixel_y);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down) && selected < 2)
                {
                    selected++;
                    pixel_y += 80;
                    menu_cursor.setPosition(pixel_x,pixel_y);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 0)
                {
                    toggleSong();
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Left) && selected == 1)
                {
                    if(current_song == 0)
                        current_song = 2;
                    else
                        current_song--;
                    selectSong(current_song);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && selected == 1)
                {
                    if(current_song == 2)
                        current_song = 0;
                    else
                        current_song++;
                    selectSong(current_song);
                }
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter) && selected == 2)
                {
                    gameMenu(window);
                    menuLoop(window);
                }
            }
            drawOption(window);
        }
    }
}

void GameInstance::selectSong(size_t number)
{
    std::string& new_song = playlist[number];
    song = true;
    main_theme.openFromFile(new_song);
    main_theme.play();
    main_theme.setLoop(true);
}

void GameInstance::loadPlaylist()
{
    playlist.push_back("../musique/world_cup.wav");
    playlist.push_back("../musique/waving_flag.wav");
    playlist.push_back("../musique/espana.wav");    
}

void GameInstance::drawOption(sf::RenderWindow& window)
{
    sf::Texture *text_box = new sf::Texture;
    text_box->loadFromFile("../images/box_blank.png");

    sf::Sprite toggle_box(*text_box);
    toggle_box.setTextureRect(sf::IntRect(0, 0, 230, 48));
    toggle_box.setPosition(255,225);

    sf::Sprite song_box(*text_box);
    song_box.setTextureRect(sf::IntRect(0, 0, 230, 48));
    song_box.setPosition(255,305);

    sf::Sprite return_box(*text_box);
    return_box.setTextureRect(sf::IntRect(0, 0, 230, 48));
    return_box.setPosition(255,385);

    sf::Font *font = new sf::Font;
    font->loadFromFile("../font/arial.ttf");

    sf::Text toggle;
    toggle.setFont(*font);
    toggle.setCharacterSize(30);
    toggle.setFillColor(sf::Color::White);
    if(song)
    {
        toggle.setString("Active");
        toggle.setPosition(sf::Vector2f(330,229));
    }
    else
    {
        toggle.setString("Desactive");
        toggle.setPosition(sf::Vector2f(305,229));
    }

    sf::Text playing_song;
    playing_song.setCharacterSize(15);
    playing_song.setFont(*font);
    playing_song.setFillColor(sf::Color::White);
    switch(current_song)
    {
        case 0:
            playing_song.setString("iShowSpeed - World Cup");
            playing_song.setPosition(sf::Vector2f(290,320));
            break;
        case 1:
            playing_song.setString("K'NAAN - Waving Flag");
            playing_song.setPosition(sf::Vector2f(300,320));

            break;
        case 2:
            playing_song.setString("Amine - La Roja");
            playing_song.setPosition(sf::Vector2f(320,320));
            break;
        default:
            break;
    }

    sf::Text return_text;
    return_text.setCharacterSize(30);
    return_text.setString("Retour");
    return_text.setFont(*font);
    return_text.setFillColor(sf::Color::White);
    return_text.setPosition(sf::Vector2f(325,389));

    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(toggle_box);
    window.draw(song_box);
    window.draw(return_box);
    window.draw(toggle);
    window.draw(playing_song);
    window.draw(menu_cursor);
    window.draw(return_text);
    window.display();
}