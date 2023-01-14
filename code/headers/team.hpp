#pragma once 
#include <iostream>
#include <string>
#include <list>
#include "player.hpp"
#include "goal.hpp"

class Team{
    public: 
    Team(std::string country, std::string players);
    void printTeam(); //Probleme..
    

    void init(); // A revoir
    void update();
    
    private:
        std::list<Player> roster; 
};