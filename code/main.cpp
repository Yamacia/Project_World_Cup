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
    // p2.initStat("../data/France_team.txt");
    // p2.initStat2(p2,"../data/French_team.csv");
    std::cout << p2.getStat() << std::endl;

    sf::RenderWindow window(sf::VideoMode(LARGEUR_ECRAN,HAUTEUR_ECRAN), "Football");
    sf::Texture terrain;
    terrain.loadFromFile("../images/field.png");
    sf::Sprite s(terrain);
    window.setVerticalSyncEnabled(true);

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
        window.display();
    }

   return 0;
}