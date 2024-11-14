#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>
#include "../src/class.h"

using std::cout;

TEST_CASE("Testing classes") {
    SECTION("Test class characteristic") {
        characteristic attack("ATAKA",15);
        attack.set_name("attack");
        attack.set_value(12);
        REQUIRE(attack.get_name() == "attack");
        REQUIRE(attack.get_value() == 12);
        characteristic undefined;
        REQUIRE(undefined.get_value() == 10);
        characteristic defence("defence");
        defence.set_value(20);
        REQUIRE(defence.check(1000) == false);
        REQUIRE(defence.check_disadvantage(1000) == false);
        attack.set_value(1);
        REQUIRE(attack.check_advantage(1) == true);
        REQUIRE( (attack != defence) == true);
        REQUIRE( (attack != attack) == false);
        REQUIRE( (attack += 5).get_value() == 6);
    }
    SECTION("Test class table") {
        table character_1("attack",15);
        REQUIRE_THROWS(character_1.get_characteristic("defence"));
        REQUIRE(character_1.get_characteristic("attack").get_value() == 15);
        REQUIRE(character_1.check_characteristic("attack",1) == true);
        REQUIRE(character_1.check_characteristic_advantage("attack",1000) == false);
        REQUIRE(character_1.check_characteristic_disadvantage("attack",1) == true);
        REQUIRE_THROWS(character_1.check_characteristic("defence",1));
        REQUIRE_THROWS(character_1.check_characteristic_advantage("defence",1));
        REQUIRE_THROWS(character_1.check_characteristic_disadvantage("defence",1));
        table character_2;
        characteristic defence("defence", 2);
        character_2 += defence;   
        REQUIRE(character_2.get_characteristic("defence").get_value() == 2);
        vector<string> characteristics_test = {"defence", "attack", "luckiness", "something", "some", "very_bad", "very_good", "best_of_the_best", "worse", "doggy", "doggy_2"};
        table character_3(characteristics_test);
        REQUIRE(character_3.get_characteristic("doggy_2").get_value() == 10); 
    }
}
