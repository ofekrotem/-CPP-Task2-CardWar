#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;



TEST_CASE("Test classic game flow") {
    Player p1("Itzik");
    Player p2("Moti");

    CHECK(p1.getName() == "Itzik");
    CHECK(p2.getName() == "Moti");

    CHECK_NOTHROW(p1.setName("Katzar"));
    CHECK(p1.getName() == "Katzar");

    CHECK_NOTHROW(p2.setName("Newton"));
    CHECK(p2.getName() == "Newton");

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    
    CHECK(game.getFirstPlayer().getName() == "Katzar");
    CHECK(game.getSecondPlayer().getName() == "Newton");

    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
}