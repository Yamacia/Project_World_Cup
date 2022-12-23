#include "player.hpp"
#include<vector>
using namespace std;

void Player::initStat( Player & e, string fichier){

    ifstream file(fichier, ios::in);  // on ouvre le fichier en lecture
    bool found=false;

        if(file)  // si l'ouverture a réussi
        {       
            string ligne;
            string mot2;
            string mot3;
            vector<string> retour;
            while (file.peek()!=EOF){
                file >> mot2;
                //cout << mot2 << endl;
                retour.push_back(mot2);
                
            }
            if(!found){
                for (size_t i=0; i< retour.size(); i++ ){
                    if (retour[i]==e.first_name && retour[i+1]==e.last_name){
                        cout << retour[i]  << ' ' << retour[i+1] << endl;
                        e.setStat(stod(retour[i+2]));
                        found =true;
                    }
                }
            }
            file.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}


void Player::initStat2( Player & e, string fichier){

    ifstream file(fichier, ios::in);  // on ouvre le fichier en lecture
    bool found=false;

        if(file)  // si l'ouverture a réussi
        {       
            string ligne;
            
            vector<string> retour;
            while (getline(file,ligne, ';')){
                //stringstream str(ligne);
                //cout << ligne << endl;
                retour.push_back(ligne);
            }
            //if(!found){
                for (size_t i = 0; i < retour.size(); i++){
                    //cout << "ici" << endl;
                    //cout << retour[i] << endl;
                    //cout << "=============" << endl;
                    //cout << e.first_name << ' ' << e.last_name << endl;
                    cout << retour[i]  << ' ' << retour[i+1] << endl;
                    if (retour[i] == e.first_name && retour[i+1] == e.last_name){
                        
                        e.setStat(stod(retour[i+2]));
                        found=true;
                    }
                }
            //}
            
            file.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
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