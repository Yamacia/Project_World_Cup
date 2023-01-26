#pragma once 
#include "constants.hpp"
#include "team.hpp"

class Field{
    public: 
    /* Constructeurs et Destructeurs */
    Field();
    Field(size_t w, size_t h);
    Field (const Field & f);

    /* Getters*/
    size_t getWidth()  const {return width;}
    size_t getHeight() const {return height;}

    size_t howManyOpponent(size_t x, size_t y, Team opponent_team);

    char operator()(size_t i, size_t j) const {return field[i][j];}

    private: 

    char **field;
    size_t width;
    size_t height;
    
};