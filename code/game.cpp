#include "headers/game.hpp"
#include "headers/inputmanager.hpp"

GameInstance::GameInstance()
{
    loadMusic();
    loadMenu();
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
    sf::Font font;
    font.loadFromFile("../font/arial.ttf");
    std::cout << "Succesfully loaded font : Arial" << std::endl;

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Jouer");
    menu[0].setCharacterSize(12);
    menu[0].setPosition(sf::Vector2f(320,72));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Option");
    menu[1].setCharacterSize(12);
    menu[1].setPosition(sf::Vector2f(320,152));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Quitter");
    menu[2].setCharacterSize(12);
    menu[2].setPosition(sf::Vector2f(320,232));

}

void GameInstance::gameLoop(sf::RenderWindow& window)
{
    /* Carré de sélection de case */
    sf::RectangleShape cursor(sf::Vector2f(LARGEUR_CASE, HAUTEUR_CASE));
    cursor.setFillColor(sf::Color::Transparent);
    cursor.setOutlineColor(sf::Color::Red);
    cursor.setOutlineThickness(2);
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
                        std::cout << "Theo Rouyer a choisi cette case." << std::endl;
                    if(_x == 4 && _y == 2)
                        std::cout << "Leonard Pannetier a choisi cette case." << std::endl;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(background);

        for(auto player : team_1)
        {
            sf::CircleShape sprite = player.getSprite();
            window.draw(sprite);
        }     
        
        cursor.setPosition(sf::Vector2f(_x*LARGEUR_CASE + 32, _y*HAUTEUR_CASE + 29));
        window.draw(cursor);        
        window.display();
    }
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
    sf::Text text;
    sf::Font font;
    font.loadFromFile("../font/arial.ttf");
    std::cout << "Succesfully loaded font : Arial" << std::endl;

    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString("Jouer");
    text.setCharacterSize(12);
    text.setPosition(320,249);

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
        }

        window.clear(sf::Color::Black);
        window.draw(background);
        window.draw(play_box);
        window.draw(option_box);
        window.draw(exit_box);

        window.draw(text);

        window.display();
    }

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

    /* Musique en boucle */
    main_theme.setLoop(true);
    main_theme.play();    
}