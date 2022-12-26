#pragma once
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
    terrain.loadFromFile("../images/field.png");
    sf::Sprite s(terrain);    

    /* Cercle blanc qui représente le coin haut-gauche du terrain */
    sf::CircleShape origine(12);

    while(window.isOpen())
    {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed)
                    window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(s);


        /* Fixer sa position au coin haut-gauche */
        origine.setPosition(sf::Vector2f(32, 29));
        origine.setOrigin(sf::Vector2f(origine.getRadius(),origine.getRadius())); // Fixer son origine en son centre

        window.draw(origine);
        window.display();
    }

   return 0;
}