#pragma once 
#include "character.hpp"


class Referee: public Character{
    public:
        Referee(std::string f, std::string n): Character(f,n){};
        void whistle(); //siffler
        void card(); //carton
        void offside(); //hors-jeu
};