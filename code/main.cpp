//#pragma once
#include "character.hpp"
#include "player.hpp"
#include "game.hpp"
#include "field.hpp"
#include "referee.hpp"


int main(){
    Player p1( "Kylian","Mbappe", "French");
    p1.initStat("../data/France_team.txt");
    std::cout << p1.getStat() << std::endl;
        

    Player p2("Adrien","Rabiot", "French");
    p2.initStat("../data/France_team.txt");
    // p2.initStat2(p2,"../data/French_team.csv");
    std::cout << p2.getStat() << std::endl;


    /* Création de la fenêtre */
    sf::RenderWindow window(sf::VideoMode(LARGEUR_ECRAN,HAUTEUR_ECRAN), "Football");
    sf::Texture terrain;
    terrain.loadFromFile("../images/Field_no_grid.png");
    sf::Sprite s(terrain);    

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

    Player french_player("Antoine", "Griezmann", "French");
    size_t position_x = 3;
    size_t position_y = 6;
    french_player.setPosition(position_x, position_y);
    // std::cout << "Position est (" << french_player.getX() << "," << french_player.getY() << ")" << std::endl;
    french_player.setSpritePosition();
    french_team.push_back(french_player);

    Player french_player_2("Olivier", "Giroud", "French");
    position_x = 4;
    position_y = 8;
    french_player_2.setPosition(position_x, position_y);
    french_player_2.setSpritePosition();
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
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                    window.close();
            
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Left && x > 0)
                    x--;
                if(event.key.code == sf::Keyboard::Right && x < LARGEUR_TERRAIN)
                    x++;
                if(event.key.code == sf::Keyboard::Up && y > 0)
                    y--;
                if(event.key.code == sf::Keyboard::Down && y < HAUTEUR_TERRAIN)
                    y++;
                if(event.key.code == sf::Keyboard::Enter)
                {
                    std::cout << "Case (" << x << "," << y << ")" << std::endl;
                    if(x == 4 && y == 7)
                        std::cout << "Theo Rouyer a choisi cette case." << std::endl;
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
            std::cout << player.getName() << " " << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
            window.draw(sprite);
        }

        /* */
        cursor.setPosition(sf::Vector2f(x*LARGEUR_CASE + 32, y*HAUTEUR_CASE + 29));
        window.draw(cursor);
        window.display();
    }

   return 0;
}