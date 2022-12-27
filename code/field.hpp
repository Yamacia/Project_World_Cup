#pragma once 
#include <iostream>
#include <string>

/* Postes des joueurs
Légende :
AG / AC / AD = Attaquant Gauche / Centre / Droite
MOG / MOC / MOD = Milieu Offensif Gauche / Centre / Droite
MG / MC / MD = Milieu Gauche / Centre / Droite
DG / DC / DD = Défense Gauche / Centre / Droite
G = Gardien
*/
typedef enum Poste{AG, AC, AD, MOG, MOC, MOD, MG, MC, MD, DG, DC, DD, G} Poste;

/* Taille du terrain (basé sur l'image) */
const size_t LARGEUR_TERRAIN = 14;
const size_t HAUTEUR_TERRAIN = 9;
const size_t TAILLE_CASE = 50;
const size_t CENTRE_CASE = 24;


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