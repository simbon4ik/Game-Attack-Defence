#include "operators.h"
#include <limits>
#include <climits>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::min;
using std::max;
using std::vector;
using std::begin;
using std::end;

//Operators overloadins
std::ostream& operator << (std::ostream& c, const table &temp){
        int size = temp.length;
        for (int i = 0; i < size; i++){
                c << "Characteristic name is " << temp.characteristics[i].get_name() << ". Value is " << temp.characteristics[i].get_value() << endl;
        }
        return c;
}

std::ostream& operator << (std::ostream& c, const characteristic &temp){
        c << "Characteristic name is " << temp.get_name() << ". Value is " << temp.get_value() << endl;
        return c;
}

std::istream& operator >> (std::istream& s, table &temp){
        cout << "Insert how much characteristics you wanna set" << endl;
        int cnt = getint(1, INT_MAX);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (int i = 0; i < cnt; i ++){
                string name;
                cout << "Insert the name of characteristic:" << endl;
                getline(s, name);
                cout << "Insert the value of characteristic" << endl;
                int value = getint(1,20);
                temp.create_characteristic(name, value);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return s;
}

std::istream& operator >> (std::istream& s, characteristic &temp){
        string name;
        cout << "Insert the name of characteristic:" << endl;
        getline(s, name);
        cout << "Insert the value of characteristic" << endl;
        int value = getint(1,20);
        temp.set_value(value);
        temp.set_name(name);
        return s;
}
        

//Print_characteristic
void print_characteristic(const characteristic& charac){
        cout << "Name is " << charac.get_name() << ", value is " << charac.get_value() << endl;
}
