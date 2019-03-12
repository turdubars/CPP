#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include "BSTreeInt.h"

using namespace std;

TEST_CASE("constructors", "[ctors]")
{
    BSTreeInt s;

    REQUIRE(s.size() == 0);
}

TEST_CASE("insert", "[insert]")
{
    BSTreeInt s;

    REQUIRE(s.insert(50));
    REQUIRE(s.size() == 1);
    REQUIRE(s.path == "");


    REQUIRE(s.insert(27));
    REQUIRE(s.size() == 2);
    REQUIRE(s.path == "L");

    REQUIRE(s.insert(69));
    REQUIRE(s.size() == 3);
    REQUIRE(s.path == "R");

    REQUIRE(s.insert(13));
    REQUIRE(s.size() == 4);
    REQUIRE(s.path == "LL");

    REQUIRE(s.insert(35));
    REQUIRE(s.size() == 5);
    REQUIRE(s.path == "LR");

    REQUIRE(s.insert(63));
    REQUIRE(s.size() == 6);
    REQUIRE(s.path == "RL");

    REQUIRE(s.insert(70));
    REQUIRE(s.size() == 7);
    REQUIRE(s.path == "RR");

    REQUIRE_FALSE(s.insert(63));
    REQUIRE(s.size() == 7);
    REQUIRE(s.path == "RL");

}

TEST_CASE("find", "[find]")
{
    BSTreeInt s;

    s.insert(50);
    s.insert(27);
    s.insert(69);
    s.insert(13);
    s.insert(35);
    s.insert(63);
    s.insert(70);

    REQUIRE(s.find(50));
    REQUIRE(s.path == "");

    REQUIRE(s.find(27));
    REQUIRE(s.path == "L");

    REQUIRE(s.find(69));
    REQUIRE(s.path == "R");

    REQUIRE(s.find(13));
    REQUIRE(s.path == "LL");

    REQUIRE(s.find(35));
    REQUIRE(s.path == "LR");

    REQUIRE(s.find(63));
    REQUIRE(s.path == "RL");

    REQUIRE(s.find(70));
    REQUIRE(s.path == "RR");

    REQUIRE_FALSE(s.find(100));
    REQUIRE(s.path == "RRR");
}

TEST_CASE("erase", "[erase]")
{

    BSTreeInt s;

    SECTION("only node")
    {
        s.insert(50);

        REQUIRE(s.erase(50));
        REQUIRE(s.size() == 0);
        REQUIRE(s.path == "");
    }


    SECTION("leaves in big tree")
    {
        s.insert(50);
        s.insert(27);
        s.insert(69);
        s.insert(13);
        s.insert(35);
        s.insert(63);
        s.insert(70);

        REQUIRE(s.erase(13));
        REQUIRE(s.size() == 6);
        REQUIRE(s.path == "LL");
    }

    SECTION("node with left child")
    {
        s.insert(50);
        s.insert(25);
        s.insert(11);

        REQUIRE(s.erase(25));
        REQUIRE(s.size() == 2);
        REQUIRE(s.find(11));
        REQUIRE(s.path == "L");
    }

    SECTION("node with right child")
    {
        s.insert(50);
        s.insert(25);
        s.insert(30);

        REQUIRE(s.erase(25));
        REQUIRE(s.size() == 2);
        REQUIRE(s.find(30));
        REQUIRE(s.path == "L");
    }


     SECTION("leaves in big tree")
    {
        s.insert(50);
        s.insert(27);
        s.insert(69);
        s.insert(13);
        s.insert(35);
        s.insert(63);
        s.insert(70);

        REQUIRE(s.erase(13));
        REQUIRE(s.size() == 6);
        REQUIRE(s.path == "LL");
    }

     SECTION("erase nodes with two children")
    {
        s.insert(50);
        s.insert(27);
        s.insert(69);
        s.insert(13);
        s.insert(35);
        s.insert(63);
        s.insert(70);


        REQUIRE(s.erase(50));
        REQUIRE(s.size() == 6);
        REQUIRE(s.find(35));
        REQUIRE(s.path == "");

        REQUIRE(s.erase(35));
        REQUIRE(s.size() == 5);
        REQUIRE(s.find(27));
        REQUIRE(s.path == "");
    }
}
