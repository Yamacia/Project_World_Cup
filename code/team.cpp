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

Player* Team::operator()(std::string player)
{
    std::cout << "Looking for : " + player << std::endl;
    Player* p= new Player;
    bool found=false;
    list<Player>::iterator i = roster.begin();
    /*for(Player i : roster)*/
    while(i != roster.end() && found == false )
    {
        std::cout << "Current is : " + i->getName() << std::endl;
        if(i->getName() == player && found==false){
            std::cout << *i << std::endl;
            //static Player p(i);
            p=&(*i);
            //std::cout << "Operateur a retourne : " + p->getName() << std::endl;
            //return &p;
            found =true;
        }
            i++;
    };
    //static Player p("",""); // pas trouvé
    return p;
    delete [] p;
}

/*
Player* Team::operator()(std::string player)
{
    std::cout << "Looking for : " + player << std::endl;
    
    for(Player i : roster)
    {
        std::cout << "Current is : " + i.getName() << std::endl;
        if(i.getName() == player){
            std::cout << i << std::endl;
            static Player p(i);
            //p=i;
            std::cout << "Operateur a retourne : " + p.getName() << std::endl;
            return &p;
            //found =true;
        }
            
    };
    static Player p("",""); // pas trouvé
    return &p;
}*/
