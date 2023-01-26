#include "headers/team.hpp"

using namespace std;

Team::Team()
{

}

Team::Team(string  country, string  players){
    string retour = "";
    int i = 0;
    bool found=false;
    // int cpt=0;
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
                
                found=current_player.initInfo(fichier);
                //cout << "Found :" << found << std::endl;
                if (found ==false)
                {
                    Goal current_goal(retour,country);
                    std::string fichier_goal= "../data/" + country + "_goal.txt";
                    current_goal.initInfo(fichier_goal);
                    cout << current_goal << endl;
                    roster.push_back(current_goal);
                }
                else
                {
                    cout << current_player << endl;
                    roster.push_back(current_player);
                }

                
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

void Team::updatePosition()
{
    list<Player>::iterator i = roster.begin();
    srand(time(NULL));
    while(i != roster.end())
    {
        if(i->has_ball() == false)
        {
            size_t random_x = rand()%2;
            size_t random_y = rand()%2;
            if(random_x == 1 && i->getX() < LARGEUR_TERRAIN + 1)
            {
                i->setPosition(i->getX() + 1, i->getY());
            }
            else if(random_x == 0 && i->getX() > 1)
            {
                i->setPosition(i->getX() - 1, i->getY());
            }
            if(random_y == 1 && i->getY() < HAUTEUR_TERRAIN + 1)
            {
                i->setPosition(i->getX(), i->getY() + 1);
            }
            else if(random_y == 0 && i->getY() > 1)
            {
                i->setPosition(i->getX(), i->getY() - 1);
            }
        }
        i++;
    };
}

Player* Team::operator()(std::string player)
{
    Player* p= new Player;
    bool found=false;
    list<Player>::iterator i = roster.begin();
    while(i != roster.end() && found == false )
    {
        if(i->getName() == player && found==false){
            p=&(*i);
            found =true;
        }
            i++;
    };
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
