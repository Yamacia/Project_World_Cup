#include "headers/character.hpp"
#include "headers/player.hpp"
#include "headers/game.hpp"
#include "headers/field.hpp"
#include "headers/team.hpp"
#include "headers/goal.hpp"
#include "headers/inputmanager.hpp"

int main(){

    /*  Création de la fenêtre */
    GameInstance& GameManager = GameInstance::Instance();
    sf::RenderWindow window(sf::VideoMode(LARGEUR_ECRAN,HAUTEUR_ECRAN), "Football");

    /* Lancement engine pour inputs*/ 
    InputManager::Instance().Start(window);

    /* Menu screen */ 
    GameManager.menuStart(window);

/*
    Goal g1("Nick Pope", "England");
    std::cout << g1 << std::endl;

    Goal g2(g1);

    //std::cout << g2 <<std::endl;
    g2.initGoalDroit();

    Team t("France", "Kylian Mbappe, Lucas Digne, Paul Pogba, Hugo Lloris");
*/   
    
    return 0;
}