#include "headers/character.hpp"
#include <string>
#include <iostream>

std::string Character::toInfo() const{
    std::string retour="";

    retour = name + ", " + origin + ", " + poste;
    return retour;
}


void Character::setSpritePosition()
{
    sprite.setPosition(_x*LARGEUR_CASE, _y*HAUTEUR_CASE);
}

void Character::setSpriteColor(){
    if(origin == "France")
    {
        sprite.setFillColor(sf::Color::Blue); 
        // std::cout << "Blue team !" << std::endl;
    }
    if(origin == "Portugal")
    {
        sprite.setFillColor(sf::Color::Green);
    }
}


std::ostream & operator<<(std::ostream& os, const Character& e){
    os << e.toInfo();
    return os;
}