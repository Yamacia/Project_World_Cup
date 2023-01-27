// Let Catch provide main():
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../code/headers/constants.hpp"
#include "../code/headers/utility.hpp"
#include "../code/headers/character.hpp"
#include "../code/headers/player.hpp"
#include "../code/headers/field.hpp"
#include "../code/headers/goal.hpp"
//#include "../code/referee.hpp"
#include "../code/headers/team.hpp"

TEST_CASE("1: Player")
{
  Player player1("Kylian Mbappe", "France"); //Test du constructeur avec deux Parametres
  REQUIRE(player1.getName() == "Kylian Mbappe");
  REQUIRE(player1.on_field()==0);
  player1.setPresence();
  REQUIRE(player1.on_field()==1);

  //std::cout << player1;

  Player player2(player1); //Test du constructeur par copie
  CHECK(player2.getOrigin()==player1.getOrigin());
  REQUIRE(player2.on_field()==1);
  CHECK(player2.has_ball()==0);
  player2.set_ball(1);
  CHECK(player2.has_ball()==1);

  Player player3("Phil Foden", "England");
  Player player4=player3; //Test de la surcharge de l'operateur
  REQUIRE(player4.getName()==player3.getName());
}


TEST_CASE("2: Goal")
{
  Goal goal1("Rui Patricio", "Portugal"); //Test du constructeur avec deux parametres
  CHECK(goal1.getPoste()=="GO");

  Goal goal2;
  goal2=goal1; //Test de l'operateur =
  CHECK(goal2.getName()=="Rui Patricio");
  REQUIRE(goal2.getStat()==goal1.getStat());
  goal2.initGoalGauche(); //Test de l'initialisation des positions
  REQUIRE(goal2.getX()==1);
  REQUIRE(goal2.getY()==5);
}


TEST_CASE("3: Team")
{
  Team team_france("France", "Kylian Mbappe, Lucas Digne, Paul Pogba, Hugo Lloris");

  Player p1;
  for(const auto& iter : team_france.roster)
    {
      p1 = iter; //Test de l'opérateur =

      if (p1.getName()=="Kylian Mbappe"){
        REQUIRE(p1.getOrigin()=="France");
        REQUIRE(p1.getStat()==0.84);
      }

      if (p1.getName()=="Paul Pogba"){
        REQUIRE(p1.getOrigin()=="France");
        REQUIRE(p1.getStat()==0.90);
      }

      if (p1.getName()=="Hugo Lloris"){
        REQUIRE(p1.getPoste()=="GO"); //Test du getter de poste
        REQUIRE(p1.getStat()==0.56);
      }

    }
  
    
}
