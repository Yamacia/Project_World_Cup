#pragma once 
#include "character.hpp"
#include "constants.hpp"

class Player : public Character {

    public: 
        Player(std::string n, std::string o): Character(n, o){};
        Player(const Player & p): Character(p){};
        void initStat( std::string fichier);
        void initLeftPosition();
        std::string toInfo() const;
        void move(){_x++; _y++;}
        // void move();
        // bool has_ball() const;
        // void dribble() const;
        // void shoot() const;
        // void pass() const;
        // void stop() const;
        // void disturb() const;
        // void tackle() const;
    
    
};