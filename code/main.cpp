#include "character.hpp"
#include "player.hpp"


int main(){
    Player p1( "Kylian","Mbappe", "French");
    p1.initStat(p1,"../data/France_team.txt");
    std::cout << p1.getStat() << std::endl;
    return 0;
}