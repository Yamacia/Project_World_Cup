#include "headers/field.hpp"

Field::Field()
{}

Field::Field(size_t w, size_t h)
{   
    width=w;
    height=h;

    field= new char*[width];
    for (long unsigned int i=0; i < width; i++)
    {
        *(field+i) = new char[height];
    }

    for (long unsigned int k=0 ; k < width; k++)
    {
        for (long unsigned int j=0; j < height; j++)
        {
            field[k][j] = '*'; //A modifier 
        }
    }
}


Field::Field (const Field & f)
{
    width  = f.getWidth();
    height = f.getHeight();
    field  = new char*[width];

    for ( long unsigned int i=0; i < width; i++)
    {
        field[i] = new char[height];
    }

    for (long unsigned int i=0; i < width; i++)
    {
        for (long unsigned int j=0; j < height; j++)
        {
            field[i][j] = f(i,j);
        }
    }

}

/* Permet de savoir combien d'adversaires sont présent sur une case précise */
size_t Field::howManyOpponent(size_t x, size_t y, Team opponent_team)
{
    size_t compteur = 0;
    for(Player i : opponent_team.roster)
    {
        if(i.getX() == x && i.getY() == y)
        {
            compteur++;
        }
    };
    return compteur;
}