#pragma once 
#include "constants.hpp"

class Character{

public:
    /* Constructeurs et Destructeurs */
    Character( std::string n, std::string o) : name(n), origin(o), present(0), _x(0), _y(0){};//{sprite = sf::CircleShape(6); setSpriteColor(); std::cout << "Appel Constructeur vide" << std::endl;};
    Character(const Character & c): name(c.name), origin(c.origin), present(c.present), _x(c._x), _y(c._y){};//{sprite = sf::CircleShape(6); setSpriteColor(); std::cout << "Appel Constructeur" << std::endl;};
    Character(std::string n, std::string o, std::string p, double s): name(n), origin(o), poste(p), stat(s){};
    /* Getters */
    std::string getName()const{return name;}
    std::string getOrigin(){return origin;}
    double getStat(){return stat;}
    size_t getX(){return _x;}
    size_t getY(){return _y;}
    bool on_field(){return present;}
    sf::CircleShape getSprite(){return sprite;}

    /* Setters */
    void setPresence(){present=1;}
    void setOrigin(std::string nation){origin=nation;}
    void setStat(double s){stat=s;}
    void setPosition(size_t x, size_t y){_x = x; _y = y;}
    void setSpritePosition(){std::cout << "x = " << _x * LARGEUR_CASE << std::endl; std::cout << "y = " << _y*LARGEUR_CASE << std::endl; sprite.setPosition(_x*LARGEUR_CASE, _y*HAUTEUR_CASE);}
    void setSpriteColor(){if(origin == "French"){sprite.setFillColor(sf::Color::Blue); std::cout << "Blue team !" << std::endl;}; if(origin == "Portugese"){sprite.setFillColor(sf::Color::Green);};}
    void setPoste(std::string p){poste=p;}
    virtual std::string toInfo() const;
    /* Autres méthodes*/
    //virtual void initStat(const Character & c, std::stringstream fichier)=0;
    //virtual void indicate_position() const = 0;
    //virtual void move() const = 0;

protected: 
    std::string name;
    std::string origin; 
    bool present; //Presence sur le terrain
    double stat;
    Poste role;
    std::string poste;

    //Character's position on the field
    size_t _x;
    size_t _y;

    // Character's sprite
    sf::CircleShape sprite;
};

std::ostream & operator<<(std::ostream& os, const Character& e);