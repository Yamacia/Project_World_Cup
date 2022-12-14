#pragma once 
#include "character.hpp"

class Player : public Character {

    public: 
        Player(std::string f, std::string n): Character(f,n){};
        bool on_field(){return present;}
        void move();
        bool has_ball() const;
        void dribble() const;
        void shoot() const;
        void pass() const;
        void stop() const;
        void disturb() const;
        void tackle() const;

    
};