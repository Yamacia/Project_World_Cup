#include "headers/player.hpp"
#include "headers/utility.hpp"
#include<vector>
using namespace std;



Player::Player(std::string n, std::string o): Character(n, o)
{
    string fichier = "../data/" + origin + "_team.txt";
    this->stat = initStat(fichier,n);
    this->poste= initPoste(fichier,n);
    this->ball=false;
    if(origin == "France")
        initLeftPosition();
    else
        initRightPosition();

}

/* Fonction qui initialise les statistiques des joueurs à partir d'un fichier txt 

void Player::initStat(string fichier){

    ifstream file(fichier, ios::in);  // on ouvre le fichier en lecture
    

        if(file)  // si l'ouverture a réussi
        {   
            bool found=false;
            string mot;
            vector<string> retour;

            while (file.peek()!=EOF){
                file >> mot;
                //cout << mot << endl;
                retour.push_back(mot);
            }
            if(!found){
                for (size_t i = 0; i < retour.size(); i+=4)
                {
                    //cout << retour[i] << " + " << retour[i+1] << endl;
                    if (retour[i]+' '+retour[i+1] == this->name)
                    {
                        //cout << retour[i]  << ' ' << retour[i+1] << endl;
                        this->setStat(stod(retour[i+2]));
                        found = true;
                    }
                }
            }
            file.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}

*/
/* Fonction qui initialise les postes des joueurs à partir d'un fichier txt 

void Player::initPoste(string fichier){
        ifstream file(fichier, ios::in);  // on ouvre le fichier en lecture
    

        if(file)  // si l'ouverture a réussi
        {   
            bool found=false;
            string ligne;
            string mot;
            vector<string> retour;

            while (file.peek()!=EOF){
                file >> mot;
                //cout << mot << endl;
                retour.push_back(mot);
            }
            if(!found){
                for (size_t i = 0; i < retour.size(); i+=4)
                {
                    //cout << retour[i] << " + " << retour[i+1] << endl;
                    if (retour[i]+' '+retour[i+1] == this->name)
                    {
                        cout << retour[i]  << ' ' << retour[i+1] << endl;
                        this->setPoste(retour[i+3]);
                        found = true;
                    }
                }
            }
            file.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}
*/

/* Fonction qui initialise les infos des joueurs à partir d'un fichier txt 
*/
bool Player::initInfo(string fichier){
        ifstream file(fichier, ios::in);  // on ouvre le fichier en lecture
        bool found=false;
        //bool trouve=false;
        if(file)  // si l'ouverture a réussi
        {   
            
            string ligne;
            string mot;
            vector<string> retour;

            while (file.peek()!=EOF){
                file >> mot;
                //cout << mot << endl;
                retour.push_back(mot);
            }
            if(!found){
                for (size_t i = 0; i < retour.size(); i+=4)
                {
                    //cout << retour[i] << " + " << retour[i+1] << endl;
                    if (retour[i]+' '+retour[i+1] == this->name)
                    {
                        //cout << retour[i]  << ' ' << retour[i+1] << endl;
                        this->setStat(stod(retour[i+2]));
                        this->setPoste(retour[i+3]);
                        found = true;
                    }
                }
            }

            file.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;

    
 return found;
}

/* Fonction qui initialise la position des joueurs en fonction de leur postes sur la partie gauche du terrain 
*/
void Player::initLeftPosition()
{
    if (poste== "DG")
    {
        _x=1;
        _y=1;
        cout << _x << ' ' << _y << endl;
    }
    
    if (poste =="DC")
    {
        _x=1;
        _y=4;
        cout << _x << ' ' << _y<<endl;
    }

    if (poste== "DD")
    {
        _x=1;
        _y=8;
        cout << _x << ' ' << _y <<endl;
    }

    if (poste== "MG")
    {
    
        _x=3;
        _y=1;
        cout << _x << ' ' << _y << endl;
    }

    if (poste=="MC")
    {
        _x=3;
        _y=4;
        cout << _x << ' ' << _y << endl;
    }

    if (poste== "MD"){
        _x=3;
        _y=7;
        cout << _x << ' ' << _y << endl;
    }
    if (poste== "AG"){
        _x=5;
        _y=1;
        cout << _x << ' ' << _y << endl;   
    }

    if (poste=="AC"){
        _x=6;
        _y=4;
        cout << _x << ' ' << _y << endl;
    }

    if (poste=="AD"){
        _x=5;
        _y=7;
        cout << _x << ' ' << _y << endl;
    }

    if(poste=="BU"){
        _x=7;
        _y=5;
        cout << _x << ' ' << _y << endl;
    }
}

/* Fonction qui initialise la position des joueurs en fonction de leur postes sur la partie droite du terrain 
*/
void Player::initRightPosition()
{
    if (poste== "DG")
    {
        _x=14;
        _y=1;
        cout << _x << ' ' << _y << endl;
    }
    
    if (poste =="DC")
    {
        _x=14;
        _y=4;
        cout << _x << ' ' << _y<<endl;
    }

    if (poste== "DD")
    {
        _x=14;
        _y=8;
        cout << _x << ' ' << _y <<endl;
    }

    if (poste== "MG")
    {
    
        _x=12;
        _y=1;
        cout << _x << ' ' << _y << endl;
    }

    if (poste=="MC")
    {
        _x=12;
        _y=4;
        cout << _x << ' ' << _y << endl;
    }

    if (poste== "MD"){
        _x=12;
        _y=7;
        cout << _x << ' ' << _y << endl;
    }
    if (poste== "AG"){
        _x=10;
        _y=1;
        cout << _x << ' ' << _y << endl;   
    }

    if (poste=="AC"){
        _x=9;
        _y=4;
        cout << _x << ' ' << _y << endl;
    }

    if (poste=="AD"){
        _x=10;
        _y=7;
        cout << _x << ' ' << _y << endl;
    }

    if(poste=="BU"){
        _x=8;
        _y=5;
        cout << _x << ' ' << _y << endl;
    }
}

std::string Player::toInfo() const{
        std::string retour="";
        retour = name + ", " + origin + ", " + poste + ", " + to_string(stat);
        return retour;
}

Player& Player::operator=(const Player &p){
    name=p.name;
    origin=p.origin;
    present=p.present;
    stat=p.stat;
    role=p.role;
    poste=p.poste;
    _x=p._x;
    _y=p._y;
    sprite=p.sprite;
    ball=p.ball;
    return *this;
}

void Player::setSpriteball()
{
    if(has_ball())
    {
        sprite.setOutlineColor(sf::Color::Red);
        sprite.setOutlineThickness(2);
    }
    else
    {
        sprite.setOutlineColor(sf::Color::Transparent);
        sprite.setOutlineThickness(0);
    }
}


void Player::move(){

    size_t random_x = rand()%2;
    size_t random_y = rand()%2;
    if(random_x == 1 && _x < LARGEUR_TERRAIN + 1)
    {
        setPosition(_x + 1, _y);
    }
    else if(random_x == 0 && _x > 1)
    {
        setPosition(_x - 1, _y);
    }
    if(random_y == 1 && _y < HAUTEUR_TERRAIN + 1)
    {
        setPosition(_x, _y + 1);
    }
    else if(random_y == 0 && _y > 1)
    {
        setPosition(_x, _y - 1);
    }

}



size_t Player::dribble_proba(size_t Nbadversaire) const
{
    if(Nbadversaire <= 0)
    {
        return 100;
    }
    else
    {
        return (size_t)((50*stat) / Nbadversaire);
    }

}

bool Player::dribble_right(size_t proba)
{
    size_t roll_dice = rand()%100;
    if(roll_dice < proba)
    {
        setPosition(_x + 1, _y);
        return true;
    }
    return false;
}

bool Player::dribble_left(size_t proba)
{
    size_t roll_dice = rand()%100;
    if(roll_dice < proba)
    {
        setPosition(_x - 1, _y);
        return true;
    }
    return false;
}


size_t Player::shoot_proba_right() const
{
    return (size_t)((100*stat) / ((abs((int)(CAGE_DROITE_X - _x)) + abs((int)(CAGE_DROITE_Y - _y))) + 1));
}

size_t Player::shoot_proba_left() const
{
    return (size_t)((100*stat) / ((abs((int)(CAGE_GAUCHE_X - _x)) + abs((int)(CAGE_GAUCHE_Y - _y))) + 1));
}

bool Player::shoot(size_t proba)
{
    size_t roll_dice = rand()%100;
    if(roll_dice < proba)
    {
        return true;
    }
    return false;
}

size_t Player::pass_proba(Player p) const
{
    // std::cout << "x1 = " << this->_x << " et x2 = " << p._x << std::endl;
    // std::cout << "y1 = " << this->_y << " et y2 = " << p._y << std::endl;
    // std::cout << "x^2 = " << pow(std::max(this->_x,p._x) - std::min(this->_x,p._x),2) << " et y^2 = " << pow(std::max(this->_y,p._y) - std::min(this->_y,p._y),2) << std::endl;

    return (size_t)(100 - pow(std::max(this->_x,p._x) - std::min(this->_x,p._x),2) - pow(std::max(this->_y,p._y) - std::min(this->_y,p._y),2));
}

bool Player::pass(size_t proba)
{
    size_t roll_dice = rand()%100;
    if(roll_dice < proba)
    {

        return true;
    }
    return false;
}

/*
void Player::disturb() const{

}

void Player::tackle() const{
    
}
*/