#include "simple_class.h"

bool characteristic::result(const int& value_rand, int difficult){            
                if (value_rand == 1) return false;
                if (value_rand == 20) return true;
                return ( (value_rand + value) >= difficult ?  true :  false);
        }
//Constructors
characteristic::characteristic(const string& input_name, int input_value){
                name = input_name;
                value = input_value;
        }
characteristic::characteristic(const string& input_name): characteristic(input_name, 10){}
characteristic::characteristic(): characteristic("Undefined"){}
        
//Getters
string characteristic::get_name() const { return name; }
int characteristic::get_value() const { return value; }

//Setters
void characteristic::set_name(const string& new_name){ name = new_name;}
void characteristic::set_value(int new_value){ value = new_value;}

//Checks
bool characteristic::check(int difficult){
        return result(rand() % 20 + 1, difficult);
}
bool characteristic::check_advantage(int difficult){
        return result(max(rand() % 20 + 1, rand() % 20 + 1), difficult);
}
bool characteristic::check_disadvantage(int difficult){
        return result(min(rand() % 20 + 1, rand() % 20 + 1), difficult);
}

//Change_field     
void characteristic::change_fields(){
        int new_value;
        string new_name;
        cout << "Insert new value "<< endl;
        cin >> new_value;
        cout << "Insert new name " << endl;
        getline(cin, new_name);
        name = new_name;
        value = new_value;
}

//Overloading operators
bool characteristic::operator != (const characteristic& right){
        if ( (name == right.get_name()) && (value == right.get_value()) ) return 0;
        return 1;
}
characteristic& characteristic::operator += (int a){ 
        if (value + a > 20){value = 20;}
        else{
                value += a;
        }
        return *this;
}
