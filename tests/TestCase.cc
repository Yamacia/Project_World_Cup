// Let Catch provide main():
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../code/character.hpp"
#include "../code/player.hpp"
//#include "../code/field.hpp"
//#include "../code/goal.hpp"
//#include "../code/referee.hpp"
//#include "../code/team.hpp"

TEST_CASE("1: Player")
{
  Player player1("Kylian","Mbappe", "French");
  REQUIRE(player1.getName() == "Kylian Mbappe");
  REQUIRE(player1.on_field()==0);
  player1.setPresence();
  REQUIRE(player1.on_field()==1);
  Player player2(player1);
  CHECK(player2.getOrigin()==player1.getOrigin());
  REQUIRE(player2.on_field()==1);
}

