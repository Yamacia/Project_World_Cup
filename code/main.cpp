#include "headers/character.hpp"
#include "headers/player.hpp"
#include "headers/game.hpp"
#include "headers/field.hpp"
#include "headers/referee.hpp"
#include "headers/team.hpp"
#include "headers/inputmanager.hpp"

int main(){

    /*  Création de la fenêtre */
    GameInstance& GameManager = GameInstance::Instance();
    sf::RenderWindow window(sf::VideoMode(LARGEUR_ECRAN,HAUTEUR_ECRAN), "Football");

    /* Lancement engine pour inputs */
    InputManager::Instance().Start(window);

    /* Menu screen */
    GameManager.gameMenu(window);
    GameManager.menuLoop(window);

    return 0;
}