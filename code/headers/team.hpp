#pragma once 
#include <iostream>
#include <string>
#include <list>
#include "player.hpp"
#include "goal.hpp"

class Team{
    public:
    /* Constructeurs*/
    Team(); 
    Team(std::string country, std::string players);

    /*Setter*/
    const std::list<Player>& getTeam(){return roster;}

    /*Méthode d'affichage*/
    void printTeam();

    /*Méthodes d'actions*/ 
    void updatePosition();
    void randomPlayerBall();
    Player* randomPlayerPass();

    /*Surcharge opérateur */
    Player* operator()(std::string player);

    private:
    std::list<Player> roster; //Equipe
};

