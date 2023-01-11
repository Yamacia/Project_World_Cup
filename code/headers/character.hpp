#pragma once 
#include "constants.hpp"

class Character{

public:
    /* Constructeurs et Destructeurs */
    Character():name("Unknown"), origin("Unknown"), stat(0.0), present(0), _x(0), _y(0){}; // Constructeur par défaut
    Character(std::string n, std::string o) : name(n), origin(o), present(0), _x(0), _y(0){};
    Character(const Character & c): name(c.name), origin(c.origin), present(c.present), _x(c._x), _y(c._y){sprite = sf::CircleShape(6); setSpriteColor(); setSpritePosition();};

    /* Getters */
    std::string getName()const{return name;}
    std::string getOrigin()const{return origin;}
    std::string getPoste()const{return poste;}
    double getStat()const{return stat;}
    size_t getX()const{return _x;}
    size_t getY()const{return _y;}
    bool on_field()const{return present;}
    sf::CircleShape getSprite(){return sprite;}

    /* Setters */
    void setPresence(){present=1;}
    void setOrigin(std::string nation){origin=nation;}
    void setStat(double s){stat=s;}
    void setPosition(size_t x, size_t y){_x = x; _y = y;}
    void setSpritePosition();
    void setSpriteColor();
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