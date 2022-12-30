#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>

/* Postes des joueurs
Légende :
AG / AC / AD = Attaquant Gauche / Centre / Droite
MOG / MOC / MOD = Milieu Offensif Gauche / Centre / Droite
MG / MC / MD = Milieu Gauche / Centre / Droite
DG / DC / DD = Défense Gauche / Centre / Droite
G = Gardien
*/
enum Poste{AG, AC, AD, MOG, MOC, MOD, MG, MC, MD, DG, DC, DD, G};

/* Taille du terrain (basée sur l'image) */
const size_t LARGEUR_TERRAIN = 13;
const size_t HAUTEUR_TERRAIN = 8;
const size_t LARGEUR_CASE = 49;
const size_t HAUTEUR_CASE = 47;
const size_t CENTRE_CASE = 24;

/* Taille de l'écran (basée sur l'image) */
const size_t LARGEUR_ECRAN = 744;
const size_t HAUTEUR_ECRAN = 476;