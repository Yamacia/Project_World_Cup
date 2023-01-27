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
            i->move();
        }
        i++;
    };
}

void Team::randomPlayerBall()
{
    int random_player = rand()%roster.size();

    int int_i = 0;
    list<Player>::iterator i = roster.begin();
    bool found = false;

    while(i != roster.end() && !found)
    {
        if(int_i == random_player){
            i->set_ball(true);
            found =true;
        }
        int_i++;
        i++;
    };

}

Player* Team::randomPlayerPass()
{
    Player* p = new Player;
    int random_player = rand()%roster.size();

    int int_i = 0;
    list<Player>::iterator i = roster.begin();
    bool found = false;

    while(i != roster.end() && !found)
    {
        if(int_i == random_player){
            p=&(*i);
            found =true;
        }
        int_i++;
        i++;
    };
    return p;
    delete [] p;

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
