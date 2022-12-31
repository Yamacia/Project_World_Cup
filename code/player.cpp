#include "player.hpp"
#include<vector>
using namespace std;


/* Fonction qui initialise les statistiques des jouerus à parti d'un fichier txt 
*/
void Player::initStat( string fichier){

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

/* Fonction qui initialise la position des joueurs en fonction de leur postes sur la partie gauche du terrain 
*/
void Player::initLeftPosition()
{
    if (poste== "DG")
    {
            _x=1;
            _y=0;
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
}
std::string Player::toInfo() const{
        std::string retour="";
        retour = name + " , " + origin + " , " + poste+" , " + to_string(stat);
        return retour;
}
/*
void Player::move(){

}

bool Player::has_ball() const {

}

void Player::dribble() const{

}

void Player::shoot() const{

}

void Player::pass() const{

}

void Player::stop() const{

}
void Player::disturb() const{

}

void Player::tackle() const{
    
}
*/