#pragma once 
#include <iostream>
#include <string>
#include <list>
#include "player.hpp"
#include "goal.hpp"

class Team{
    public:
    Team(); 
    Team(std::string country, std::string players);
    void printTeam(); //Probleme..
    

    void init(); // A revoir
    void update();
    std::string who_ball();
    Player operator()(std::string player);

    std::list<Player> roster; 

    private:

};

