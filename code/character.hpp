#pragma once 
#include <iostream>
#include <string>

class Character{

public: 
    Character(std::string f, std::string n, std::string o) : first_name(f), last_name(n), origin(o), present(0){};
    Character(const Character & c): first_name(c.first_name), last_name(c.last_name), origin(c.origin), present(c.present){};
    std::string getName(){return first_name + ' '+ last_name;}
    std::string getOrigin(){return origin;}
    bool on_field(){return present;}

    void setPresence(){present=1;}
    void setOrigin(std::string nation){origin=nation;}

    //virtual void indicate_position() const = 0;
    //virtual void move() const = 0;

protected: 
    std::string first_name;
    std::string last_name;
    std::string origin; 
    bool present; //Presence sur le terrain
    size_t stats;
    
};
