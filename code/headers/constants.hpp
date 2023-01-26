#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

/* Taille d'une petite boite de dialogue */
const size_t LARGEUR_BOX = 230;
const size_t HAUTEUR_BOX = 48;

/* Taille d'une grande boite de dialogue */
const size_t LARGEUR_BIG = 420; // Blaze it
const size_t HAUTEUR_BIG = 245;