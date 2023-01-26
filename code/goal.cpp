#include "headers/goal.hpp"

using namespace std;

Goal::Goal(string n, string o){
    string fichier = "../data/" + o + "_goal.txt";
    this->stat = initStat(fichier,n);
    this->name=n;
    this->origin=o;
    this->poste="GO";
    this->_gball=false;
}


/*Redifinition de la fonction virtuelle */
std::string Goal::toInfo() const{
        std::string retour="";
        retour = name + ", " + origin + ", " + poste + ", " + to_string(stat);
        return retour;
}

/* Fonction qui initialise la position du goal en fonction sur la partie gauche du terrain */
void Goal::initGoalGauche(){
    if (poste=="GO"){
        _x=1;
        _y=5;
        cout << _x << ' ' << _y << endl;
    }
}

/* Fonction qui initialise la position du goal en fonction sur la partie droite du terrain */
void Goal::initGoalDroit(){
    if (poste=="GO"){
        _x=14;
        _y=5;
        cout << _x << ' ' << _y << endl;
    }
}

void Goal::catch_ball(){

}

void Goal::stop(){

}