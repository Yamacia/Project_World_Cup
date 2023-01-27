#include "headers/character.hpp"
#include <string>
#include <iostream>

Character::Character(): name("Unknown"), origin("Unknown"), present(0), stat(0.0), _x(0), _y(0)
{}

Character::Character(std::string n, std::string o) : name(n), origin(o), present(0), _x(0), _y(0)
{}

Character::Character(const Character &c) : name(c.name), origin(c.origin), present(c.present), stat(c.stat), poste(c.poste), _x(c._x), _y(c._y)
{
    sprite = sf::CircleShape(6);  // Taille du sprite sur le jeu
    setSpritePosition();
    setSpriteColor();
}

std::string Character::toInfo() const{
    std::string retour="";

    retour = name + ", " + origin + ", " + poste;
    return retour;
}




/* Met à jour la position du joueur sur l'interface graphique */
void Character::setSpritePosition()
{
    sprite.setPosition(_x*LARGEUR_CASE, _y*HAUTEUR_CASE);
}

/* Colorie le sprite d'un joueur selon sa nationalité (sur l'interface graphique) */
void Character::setSpriteColor(){
    if(origin == "France")
    {
        sprite.setFillColor(sf::Color::Blue); 
        if (poste=="GO"){
            sprite.setFillColor(sf::Color::Magenta);
        }
        // std::cout << "Blue team !" << std::endl;
    }
    if(origin == "Portugal")
    {
        sprite.setFillColor(sf::Color::Green);
        if (poste=="GO"){
            sprite.setFillColor(sf::Color::Magenta);
        }
    }
}

/* Opérateur pour afficher toute sa description dans un cout*/
std::ostream & operator<<(std::ostream& os, const Character& e){
    os << e.toInfo();
    return os;
}