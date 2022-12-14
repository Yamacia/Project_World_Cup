#pragma once 
#include "character.hpp"


class Referee: public Character{
    public:
        Referee(std::string f, std::string n, std::string o): Character(f,n, o){};
        void whistle(); //siffler
        void card(); //carton
        void offside(); //hors-jeu
};