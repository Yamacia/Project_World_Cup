#include "headers/team.hpp"

using namespace std;

Team::Team()
{}

/*Constructeur à partir du pays d'origine et de la liste des joueurs souhaitée*/
Team::Team(string  country, string  players){
    string retour = "";
    int i = 0;
    bool found=false;
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
                std::string fichier = "../data/" + country + "_team.txt"; //Charge le fichier correspondant
                
                found = current_player.initInfo(fichier);
                
                if (found == false) //Si c'est un goal
                {
                    Goal current_goal(retour, country);
                    std::string fichier_goal = "../data/" + country + "_goal.txt";
                    current_goal.initInfo(fichier_goal);
                    //cout << current_goal << endl;
                    roster.push_back(current_goal);
                }
                else //Si c'est un joueur autre que goal
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

/*Destructeur*/
Team::~Team(){
    roster.clear();
}

/*Affiche l'équipe*/
void Team::printTeam(){

    for(list<Player>::iterator it = roster.begin(); it != roster.end(); it++){
		cout << *it << endl;
	}

}


/* Met à jour la position de tous les joueurs de l'équipe */
void Team::updatePosition()
{
    list<Player>::iterator i = roster.begin();
    srand(time(NULL));
    while(i != roster.end())
    {
        if(i->has_ball() == false)
        {
            if (i->getPoste()=="GO"){
                i->setPosition(i->getX(), i->getY() );

            }
            else{
            i->move();
            }
        }
        i++;
    };
}

/* Donne la balle à un joueur aléatoire de l'équipe */
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

/* Retourne un joueur potentiel à qui faire la passe */
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
    }
    return p;
    delete [] p;

}

/* Opérateur pour retrouver un joueur dans l'équipe à partir de son nom */
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
