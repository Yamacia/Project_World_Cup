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


    const std::list<Player>& getTeam(){return roster;}
    void printTeam(); 
    

    void updatePosition();
    void randomPlayerBall();
    Player* randomPlayerPass();
    Player* operator()(std::string player);

     

    private:
    std::list<Player> roster;
};

