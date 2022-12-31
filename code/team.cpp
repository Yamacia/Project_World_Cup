#include "team.hpp"

using namespace std;

Team::Team(string  country, string  players){
    string retour = "";
    int i = 0;
    int cpt=0;
    while (players[i] != '\0')
    {
        if (players[i] != ',')
        {
            retour = retour + players[i];
        }
        
        if ( players[i] == ',' || players[i+1] == '\0'){
            
            if (retour!="")
            {
               
                Player current_player (retour, country);
                cout << "Le nom est : " << current_player.getName() << endl;
                roster.push_back(current_player);
                
            }
          
            retour="";
            
        }

        i++; 
    }
}

void Team::printTeam(){

for (auto const &i: roster) {
    cout << i << endl;
    }

}

void Team::init(){

}

void Team::update(){
    
}