#pragma once 
#include "constants.hpp"

class Character{

public:
    /* Constructeurs et Destructeurs */
    Character(); // Constructeur par défaut
    Character(std::string n, std::string o);
    Character(const Character & c);

    /* Getters */
    std::string getName()const{return name;}
    std::string getOrigin()const{return origin;}
    std::string getPoste()const{return poste;}
    double getStat()const{return stat;}
    size_t getX()const{return _x;}
    size_t getY()const{return _y;}
    sf::CircleShape getSprite(){return sprite;}

    /* Setters */
    void setOrigin(std::string nation){origin=nation;}
    void setStat(double s){stat=s;}
    void setPosition(size_t x, size_t y){_x = x; _y = y;}
    void setSpritePosition();
    void setSpriteColor();
    void setPoste(std::string p){poste=p;}
    virtual std::string toInfo() const;
   

protected: 

    /* Character's informations */
    std::string name;
    std::string origin; 
    double stat;
    Poste role;
    std::string poste;

    /* Character's position on the field */
    size_t _x;
    size_t _y;

    /* Character's sprite */
    sf::CircleShape sprite;
};

/* Operator to print the Character's informations */
std::ostream & operator<<(std::ostream& os, const Character& e);