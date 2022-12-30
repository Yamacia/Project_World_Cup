#include "team.hpp"

using namespace std;

Team::Team(string  country, string  players){
    string retour = "";
    int i = 0;
    int cpt=0;
    while (players[i] != '\0')
    {
        if (players[i] != ',' && players[i] != ' ')
        {
            //cout << retour << endl;
            retour = retour + players[i];

        }
        
        if ( players[i] == ',' && players[i+1]==' ' || players[i+1] == '\0'){
            
            if (retour!="")
            {
                cout << retour << endl;
               // cout << "ici a :" << cpt << endl;
                Player current_player (retour, country);
                //cout << "Le nom est : " << current_player.getName() << endl;
                //cpt=0;
                
            }
            //cout << retour << endl;
            retour="";
            /*
            if (cpt==0 && retour !="" && players[i]==' '){
            //cout << "cpt : "<< cpt << endl;
            
            cpt++;
            cout << cpt << endl;
            }
            if (retour !=" " && cpt==1 || retour !=""){
                cout << retour << endl;
                retour= retour + ' ';
            }
            */
            
        }

        i++; 
    }
}

void Team::init(){

}

void Team::update(){
    
}