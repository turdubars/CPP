#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include "ListInt.h"

TEST_CASE("Constructors with no parameters", "[ctors]")
{
    ListInt lst;
    
    REQUIRE(lst.size() == 0);
    REQUIRE(lst.toStr() == "{}");
}

TEST_CASE("pushBack(int x)", "[pushBack]")
{
    ListInt lst;
    
    SECTION("Case 1")
    {
        lst.pushBack(1);
        REQUIRE(lst.size() == 1);
        REQUIRE(lst.toStr() == "{1}");
    }
    
    SECTION("Case 1")
    {
        lst.pushBack(1);
        lst.pushBack(2);
        lst.pushBack(3);
        lst.pushBack(4);
        lst.pushBack(5);
        
        REQUIRE(lst.size() == 5);
        REQUIRE(lst.toStr() == "{1, 2, 3, 4, 5}");
    }
}

TEST_CASE("Iterators", "iters")
{
    ListInt lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);

    SECTION("Case 1")
    {
        ListInt::Iter it = lst.begin();
        REQUIRE(*it == 1);
        
        ++it;
        REQUIRE(*it == 2);
        
        ++it;
        REQUIRE(*it == 3);
    }
    
    SECTION("Case 2")
    {
        ListInt::Iter it = lst.end();
        --it;
        REQUIRE(*it == 3);
        
        --it;
        REQUIRE(*it == 2);
        
        --it;
        REQUIRE(*it == 1);
        
        REQUIRE(it == lst.begin());
    }
}