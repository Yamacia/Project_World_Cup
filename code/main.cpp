#include "headers/character.hpp"
#include "headers/player.hpp"
#include "headers/game.hpp"
#include "headers/field.hpp"
#include "headers/referee.hpp"
#include "headers/team.hpp"
#include "headers/inputmanager.hpp"

int main(){

    /*  Création de la fenêtre */
    sf::RenderWindow window(sf::VideoMode(LARGEUR_ECRAN,HAUTEUR_ECRAN), "Football");
    sf::Texture terrain;
    terrain.loadFromFile("../images/Field_no_grid.png");
    sf::Sprite s(terrain);

    /* Création musique principale */
    sf::Music main_theme;
    main_theme.openFromFile("../musique/world_cup.wav");

    /* Musique en boucle */
    main_theme.setLoop(true);
    main_theme.play();    

    /* Lancement engine pour inputs */
    InputManager::Instance().Start(window);

    /* Test Joueurs */
    std::vector<sf::CircleShape> portuguese_team;

    sf::CircleShape portuguese_player(6);
    portuguese_player.setFillColor(sf::Color::Green);
    portuguese_player.setPosition(sf::Vector2f(200,200));
    portuguese_team.push_back(portuguese_player);

    sf::CircleShape portuguese_player2(6);
    portuguese_player2.setFillColor(sf::Color::Green);
    portuguese_player2.setPosition(sf::Vector2f(400,400));
    portuguese_team.push_back(portuguese_player2);
    
    /* Test Afficher Equipe de joueurs */
    std::vector<Player> french_team;

    Player french_player("Antoine Griezmann", "France");
    french_team.push_back(french_player);

    Player french_player_2("Olivier Giroud", "France");
    french_team.push_back(french_player_2);
    

    /* Carré de sélection de case */
    sf::RectangleShape cursor(sf::Vector2f(LARGEUR_CASE, HAUTEUR_CASE));
    cursor.setFillColor(sf::Color::Transparent);
    cursor.setOutlineColor(sf::Color::Red);
    cursor.setOutlineThickness(2);
    size_t x = 0;
    size_t y = 0;

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
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Left) && x > 0)
                    x--;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Right) && x < LARGEUR_TERRAIN)
                    x++;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Up) && y > 0)
                    y--;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Down) && y < HAUTEUR_TERRAIN)
                    y++;
                if(InputManager::Instance().GetKey(sf::Keyboard::Key::Enter))
                {
                    std::cout << "Case (" << x << "," << y << ")" << std::endl;
                    if(x == 4 && y == 7)
                        std::cout << "Theo Rouyer a choisi cette case." << std::endl;
                    if(x == 4 && y == 2)
                        std::cout << "Leonard Pannetier a choisi cette case." << std::endl;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(s);

        for(auto sprite : portuguese_team)
        {
            window.draw(sprite);
        }
        
        for(auto player : french_team)
        {
            sf::CircleShape sprite = player.getSprite();
            window.draw(sprite);
        }
        
        
        cursor.setPosition(sf::Vector2f(x*LARGEUR_CASE + 32, y*HAUTEUR_CASE + 29));
        window.draw(cursor);        
        window.display();
    }
   return 0;
}