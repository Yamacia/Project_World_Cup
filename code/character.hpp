#pragma once 
#include <iostream>
#include <string>
#include <fstream>

/* Postes des joueurs
Légende :
AG / AC / AD = Attaquant Gauche / Centre / Droite
MOG / MOC / MOD = Milieu Offensif Gauche / Centre / Droite
MG / MC / MD = Milieu Gauche / Centre / Droite
DG / DC / DD = Défense Gauche / Centre / Droite
G = Gardien
*/
typedef enum Poste{AG, AC, AD, MOG, MOC, MOD, MG, MC, MD, DG, DC, DD, G} Poste;


class Character{

public:
    /* Constructeurs et Destructeurs */
    Character(std::string f, std::string n, std::string o) : first_name(f), last_name(n), origin(o), present(0), stat(0), _x(0), _y(0){};
    Character(const Character & c): first_name(c.first_name), last_name(c.last_name), origin(c.origin), present(c.present), _x(0), _y(0){};

    /* Getters */
    std::string getName(){return first_name + ' '+ last_name;}
    std::string getOrigin(){return origin;}
    double getStat(){return stat;}
    size_t getX(){return _x;}
    size_t getY(){return _y;}
    bool on_field(){return present;}

    /* Setters */
    void setPresence(){present=1;}
    void setOrigin(std::string nation){origin=nation;}
    void setStat(double s){stat=s;}
    void setPosition(size_t x, size_t y){_x = x; _y = y;}

    /* Autres méthodes*/
    //virtual void initStat(const Character & c, std::stringstream fichier)=0;
    //virtual void indicate_position() const = 0;
    //virtual void move() const = 0;

protected: 
    std::string first_name;
    std::string last_name;
    std::string origin; 
    bool present; //Presence sur le terrain
    double stat;
    Poste *role;

    //Character's position on the field
    size_t _x;
    size_t _y;
};
