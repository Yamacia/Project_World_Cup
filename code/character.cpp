#include "headers/character.hpp"
#include <string>
#include <iostream>

Character::Character(): name("Unknown"), origin("Unknown"), present(0), stat(0.0), _x(0), _y(0)
{}

Character::Character(std::string n, std::string o) : name(n), origin(o), present(0), _x(0), _y(0)
{}

Character::Character(const Character &c) : name(c.name), origin(c.origin), present(c.present), stat(c.stat), poste(c.poste), _x(c._x), _y(c._y)
{
    sprite = sf::CircleShape(6); 
    setSpriteColor(); 
    setSpritePosition();
}

std::string Character::toInfo() const{
    std::string retour="";

    retour = name + ", " + origin + ", " + poste;
    return retour;
}

void Character::move() const
{
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