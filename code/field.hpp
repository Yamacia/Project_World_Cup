#pragma once 
#include "constants.hpp"

class Field{
    public: 
    /* Constructeurs et Destructeurs */
    Field(size_t w, size_t h);
    Field (const Field & f);

    /* Getters*/
    size_t getWidth()  const {return width;}
    size_t getHeight() const {return height;}

    char operator()(size_t i, size_t j) const {return field[i][j];}

    private: 

    char **field;
    size_t width;
    size_t height;
    
};