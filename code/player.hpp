#pragma once 
#include "character.hpp"
#include <fstream>
#include <sstream>
#include <string>

class Player : public Character {

    public: 
        Player(std::string f, std::string n, std::string o): Character(f,n, o){};
        Player(const Player & p): Character(p){};
        void initStat( std::string fichier);
        void initStat2( Player & e, std::string fichier);

        // void move();
        // bool has_ball() const;
        // void dribble() const;
        // void shoot() const;
        // void pass() const;
        // void stop() const;
        // void disturb() const;
        // void tackle() const;
    
    
};