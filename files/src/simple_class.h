#include "input.h"
#include <iostream>
/**
        This class is designed to describe characteristic in difficult class
        Here you can set name of characteristic and value of characteristic
*/

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::min;
using std::max;
using std::begin;
using std::end;


class characteristic {
        private:
        ///name of characteristic
        string name;
        ///value of characteristic
        int value;
        /**
                This metod is necessary for to do checking
        */
        bool result(const int& value_rand, int difficult);
        public:
        //Constructors
        /**
                This is constructor with name and value
                \param input_name - name, that set the user
                \param input_value - value, that set the user
        */
        characteristic(const string& input_name, int input_value);
        ///Conctrustor with only name, default value is 10
        characteristic(const string& input_name);
        ///Constructor without something, default name is "Undefined", value is 10
        characteristic();
        
        //Getters

        ///This getter for get name from the class
        string get_name() const;
        ///This getter for get value from the class
        int get_value() const;

        //Setters

        ///This setter for set name from the class
        void set_name(const string& new_name);
        ///This setter for set value from the class
        void set_value(int new_value);
        

        //Checkers

        /**
                This func checks the characteristic
                \param[in] diffucult - parameter, which is checked
                \param[out] result - bool type, true or false
        */
        bool check(int difficult);
        ///Check characteristic with advantage(max of two)
        bool check_advantage(int difficult);
        ///Check characteristic with disadvantage(min of two)
        bool check_disadvantage(int difficult);
        
        //Change fields
        /**
            This func changes name and value in characteristic
            User inserts new name and new value
        */
        void change_fields();
        //Operator overloading
        bool operator != (const characteristic& right);
        characteristic& operator += (int a);
};


