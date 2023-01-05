#include "headers/field.hpp"


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