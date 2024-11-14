#define start_size 10 
#include "class.h"
#include <algorithm>

using std::for_each;
using std::find_if;

bool table::comparator(const characteristic& left, const characteristic& right){
        return left.get_name() < right.get_name();
}
       
table::table(const table& right){
        length = right.length;
        characteristics = new characteristic[length];
        for_each(&(right.characteristics[0]), &(right.characteristics[length]), [this](characteristic& temp){create_characteristic(temp.get_name(), temp.get_value()); } );
}

table::table(table&& move_right) noexcept : characteristics(move_right.characteristics){move_right.characteristics = nullptr;}

table::table(vector<string> characteristics_input){
        length = 0;
        characteristics = new characteristic[start_size];
        int size = characteristics_input.size();
        for_each(&(characteristics_input[0]), &(characteristics_input[size]), [this](string& temp){ create_characteristic(temp, 10);});
}

table::table(const string& name, int value){
        length = 0;
        characteristics = new characteristic[start_size];
        create_characteristic(name, value);
}

table::table(){characteristics = nullptr; length = 0;}
table::~table() {
        if (characteristics){
                delete[] characteristics;
        }
}
characteristic& table::get_characteristic(const string& name) const{
        auto result = find_if(&(characteristics[0]),&(characteristics[length]), [name](characteristic& temp){
                if (temp.get_name() == name) return true;
                return false;
        });
        if (result == &(characteristics[length]) ) throw "No exist characteristic with this name";
        return *result;
}
        
bool table::check_characteristic(const string& name, int difficult) const{
        return get_characteristic(name).check(difficult);
}
bool table::check_characteristic_advantage(const string& name, int difficult) const{
        return get_characteristic(name).check_advantage(difficult);
}

bool table::check_characteristic_disadvantage(const string& name, int difficult) const{
        return get_characteristic(name).check_disadvantage(difficult);
}
void table::create_characteristic(string name, int value){
        characteristic temp;
        temp.set_name(name);
        temp.set_value(value);
        push_back(temp);
}

void table::sort_characteristic(){ std::sort(&characteristics[0], &characteristics[length], comparator); }

characteristic& table::get_max_characteristic(const vector<string>& names){
        int max_value = 0;
        for (string item : names){
                max_value = max(max_value, get_characteristic(item).get_value());
        }
        auto result = find_if(&(characteristics[0]), &(characteristics[length]),[max_value](characteristic& temp){
                if (temp.get_value() == max_value) return true;
                return false;
        });
        if (result == &(characteristics[length]) ) throw "No exist characteristic with this name";
        return *result;     
}

void table::print(){
        for_each( &(characteristics[0]), &(characteristics[length]), [](characteristic& temp){ cout << "Name of characteristic is " << temp.get_name() << ", value of characteristic is " << temp.get_value() << endl;});
}

void table::push_back(characteristic& item){
        if (length == 0){
                 characteristics = new characteristic[start_size];
        }
        else if (length % start_size == 0){
                 characteristic* temp = new characteristic[length];
                std::copy(& ((characteristics)[0]), & ((characteristics)[length-1]), &(temp[0]));
                delete [] (characteristics);
                characteristics = new characteristic[length+start_size];
                std::copy(&(temp[0]), &(temp[length-1]),& ((characteristics)[0]) );
                delete [] temp;
        }
        (characteristics)[length] = item;
        length += 1;
}

table& table::operator = (table &&move_right) noexcept{
        delete [] characteristics;
        characteristics = move_right.characteristics;
        move_right.characteristics = nullptr;
        return *this;
}

table& table::operator = (const table &right){
        if (this != &right){
                delete [] characteristics;
                characteristics = new characteristic[start_size];
                int size = right.length;
                for (int i = 0; i < size; i++){
                        create_characteristic(right.characteristics[i].get_name(), right.characteristics[i].get_value());
                }
        }
        return *this;
}
table& table::operator += (characteristic& insert){ 
        push_back(insert);
        return *this;
}
        
characteristic table::operator [] (string name) const{
        auto result = find_if(&(characteristics[0]),&(characteristics[length]), [name](characteristic temp){
                if (temp.get_name() == name) return true;
                return false;
        });
        if (result == &(characteristics[length]) ) throw "No exist characteristic with this name";
        return *result;
}

characteristic& table::operator [] (string name){
        return get_characteristic(name);
}
bool table::operator () (string name, int difficult, int number) const{
        if (number == 1) return check_characteristic(name, difficult);
        if (number == 2) return check_characteristic_advantage(name, difficult);
        if (number == 3) return check_characteristic_disadvantage(name, difficult);
        return 0;
}

        
