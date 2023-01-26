#include "headers/character.hpp"
#include "headers/player.hpp"
#include "headers/game.hpp"
#include "headers/field.hpp"
#include "headers/referee.hpp"
#include "headers/team.hpp"

int main(){
    //Player p1("Karim Benzema", "France");
    //Player p2=p1;
    //std::cout << p2 << std::endl;
    //std::cout << p1.getStat() << std::endl;
    //std::cout << p1.getPoste() << std::endl;
    /*p1.initStat("../data/France_team.txt");
    //std::cout << p1.getStat() << std::endl;
    p1.initLeftPosition();    
    std::cout << "La position du joueur est : (" <<p1.getX() << ',' << p1.getY() <<')' << std::endl;

    Player p2("Lucas Digne", "French");
    //p2.initStat("../data/France_team.txt");
    //p2.initPoste("../data/France_team.txt");
    p2.initInfo("../data/France_team.txt");
    std::cout << p2 << std::endl;*/

    // p2.initStat2(p2,"../data/French_team.csv");
    //std::cout << p2.getStat() << std::endl;
    //std::stringstream ss;
    //ss << p2;
    Team t("France", "Kylian Mbappe, Lucas Digne, Paul Pogba");
    //Player p= t("Kylian Mbappe");
    //p.set_ball(false);
    //std::cout << p.has_ball() << std::endl;
    //std::cout << t("Kylian Mbappe")/*->set_ball(true);*/ << std::endl;
    t("Kylian Mbappe")->set_ball(true);
    t("Kylian Mbappe")->has_ball();
    //t.init();
    //t.printTeam();
   return 0;
}