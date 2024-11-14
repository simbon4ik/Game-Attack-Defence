#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits>
#include "input.h"
#include "class.h"


int create_pers(table& character){
        int attack, defence, luckiness;
        cout << "Insert the attack for character (1-20)" << endl;
        attack = getint(1,20);
        character.create_characteristic("attack", attack);
        cout << "Insert the defence for character (1-20)" << endl;
        defence = getint(1,20);
        character.create_characteristic("defence", defence);
        cout << "Insert the luckiness for character (1-20)" << endl;
        luckiness = getint(1,20);
        character.create_characteristic("luckiness", luckiness);
        return 0;
}

int fight(table& character_1, table& character_2){    
        cout << "\tRules is:\n\t\t The first thing to do is to throw a coin, if the number 1 falls out, then the first player attacks first, otherwise the second.\n\t\t Each player has 20 hp by default. The entered protection value is added to the hp.\n\t\t The task of each player is to remove hp to the opposite player. \n\t\t With each hit, the luck of the attacker is subtracted from the luck of the defender.\n\t\t If it turns out to be zero, then the chance of getting a double-force strike is average.\n\t\t If the number is negative (the attacker is luckier than the defender), then the chance is higher than average, otherwise less than average." << endl;
        int luck(0), power(0), hp(0);
        int coin = rand() % 2 + 1;
        cout << "coin = " << coin << endl;
        character_2.get_characteristic("hp").set_value(20+character_2.get_characteristic("defence").get_value());
        character_1.get_characteristic("hp").set_value(20+character_1.get_characteristic("defence").get_value());
        while ( (character_1.get_characteristic("hp").get_value() > 1) && (character_2.get_characteristic("hp").get_value() > 1) ){
                cout << "\nInsert 1 for continue" << endl;
                getint(1,1);
                hp = character_1.get_characteristic("hp").get_value();
                luck = character_2.get_characteristic("hp").get_value();
                cout << "\t\t\t( •_•)⠀⠀⠀⠀(•_• )\n\t\t\t( ง )ง ⠀⠀ ୧( ୧ )\n\t\t\t/︶\\   ⠀⠀⠀⠀ /︶\\ \n\t\tFirst player hp:" <<  hp << "     Second player hp:" << luck << endl;
                switch(coin){
                        case 1:
                                hp = character_2.get_characteristic("hp").get_value();
                                luck = character_1.get_characteristic("luckiness").get_value() - character_2.get_characteristic("luckiness").get_value();
                                cout << "Difference between luckiness attacker and luckiness defender is: " << luck << endl;
                                if (luck > 0){
                                        power = character_1.get_characteristic("attack").get_value()*(1 + character_1.get_characteristic("attack").check_advantage(30));
                                }
                                else if (luck == 0){
                                        power = character_1.get_characteristic("attack").get_value()*(1 + character_1.get_characteristic("attack").check(30));
                                }
                                else{
                                        power = character_1.get_characteristic("attack").get_value()*(1 + character_1.get_characteristic("attack").check_disadvantage(30));
                                }      
                                cout << "Power first player is: " << power << endl;
                                if ((hp - power) <= 1){
                                        character_2.get_characteristic("hp").set_value(1);
                                        cout << "First player win!" << endl;
                                }
                                else{
                                        character_2.get_characteristic("hp").set_value(hp-power);
                                        cout << "Current hp second player is: " << character_2.get_characteristic("hp").get_value();
                                }
                                break;

                        case 2:
                                hp = character_1.get_characteristic("hp").get_value();
                                luck = character_2.get_characteristic("luckiness").get_value() - character_1.get_characteristic("luckiness").get_value();
                                cout << "Difference between luckiness attacker and luckiness defender is: " << luck << endl;
                                if (luck > 0){
                                        power = character_2.get_characteristic("attack").get_value()*(1 + character_2.get_characteristic("attack").check_advantage(30));
                                }
                                else if (luck == 0){
                                        power = character_2.get_characteristic("attack").get_value()*(1 + character_2.get_characteristic("attack").check(30));
                                }
                                else{
                                        power = character_2.get_characteristic("attack").get_value()*(1 + character_2.get_characteristic("attack").check_disadvantage(30));
                                }      

                                cout << "Power second player is: " << power << endl;
                                if ((hp - power) <= 1){
                                        character_1.get_characteristic("hp").set_value(1);
                                        cout << "Second player win!" << endl;
                                }
                                else{
                                        character_1.get_characteristic("hp").set_value(hp-power);
                                        cout << "Current hp first player is: " << character_1.get_characteristic("hp").get_value();
                                }
                                break;
                }
        coin = coin % 2 + 1;
        }
        
        return 0;
}






int main(){
        srand(time(0));
        table character_1("hp",20); table character_2("hp",20);
        try{
                int number(0), status(1);
                do{
                        std::cout << "1. Set the first character\n2. Set the second character\n3. Play attack-defence" << std::endl;
                        number = getint(1,3);
                        switch(number)
                        {
                        case 1:
                                status = create_pers(character_1);
                                break;
                        case 2:
                                status = create_pers(character_2);
                                break;
                        case 3:
                                status = fight(character_1, character_2);
                                break;
                        }
                }while (status == 0);
        }
        catch(const std::runtime_error& e){
                std::cerr << e.what() << endl;
        }
        catch(const std::exception& e){
                std::cerr  << e.what() << endl;
        }
        return 0;
}

