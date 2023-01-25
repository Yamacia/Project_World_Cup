#include "headers/team.hpp"

using namespace std;

Team::Team()
{

}

Team::Team(string  country, string  players){
    string retour = "";
    int i = 0;
    int cpt=0;
    while (players[i] != '\0')
    {
        if (players[i] != ',')
        {
            if (retour=="" && players[i]==' '){
                retour = retour;
            }
            else{
                retour = retour + players[i];
            }
        }
        
        if ( players[i] == ',' || players[i+1] == '\0'){
            
            if (retour!="")
            {
               
                Player current_player (retour, country);
                std::string fichier = "../data/" + country + "_team.txt";
                current_player.initInfo(fichier);
                cout << current_player << endl;
                roster.push_back(current_player);

                
            }
          
            retour="";
            
        }

        i++; 
    }
}

void Team::printTeam(){

    for(list<Player>::iterator it = roster.begin(); it != roster.end(); it++){
		cout << *it << endl;
	}

}

/* A revoir

void Team::init(){

    for (auto i: roster){
        if (i.has_ball()!=0){
            i.move();
            cout << i.getX() << endl;
            cout << i.getY() << endl;
        }
    }
    
}
*/

void Team::update(){
    
}

Player Team::who_ball()
{
    for (auto& player : roster)
    {
        if(player.has_ball())
        {
            std::cout << player.getName()  + " a la balle "<< std::endl;
            return player;
        }
    };
}

Player Team::operator()(std::string player)
{
    for(Player i : roster)
    {
        if(i.getName() == player)
            return i;
    };
}