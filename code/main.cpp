#include "character.hpp"
#include "player.hpp"


int main(){
    Player p1( "Kylian","Mbappe", "French");
    p1.initStat("../data/France_team.txt");
    std::cout << p1.getStat() << std::endl;
/*
    Player p2("Adrien","Rabiot", "French");
    p2.initStat2(p2,"../data/French_team.csv");
    std::cout << p2.getStat() << std::endl;
  */
   return 0;
}