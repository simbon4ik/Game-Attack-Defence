#include "simple_class.h"
#include "input.h"
#include <vector>
#include <algorithm>
/**
    This class is created for description character's in differents game
    Here is massiv of characteristic
*/

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::min;
using std::max;
using std::vector;
using std::begin;
using std::end;
void push_back(characteristic** ptr, characteristic item);


class table {
        friend std::ostream& operator << (std::ostream&, const table&);
        private:
        ///This is massiv of characteristic
        characteristic* characteristics;
        ///This is len of massiv
        int length;
        ///Comparator for sort characteristics
        static bool comparator(const characteristic& left, const characteristic& right);
        public:
        //Conctustors:
        /**
            Copy constructor, that creates new characteristics and transfers them from right class
            \param[in] right - class, from which characteristics are copied
        */
        table(const table& right);
        ///Moving constructor
        table(table&& move_right) noexcept;
        /**
            Constructor that creates class with characteristics
            \param[in] characteristics_input - characteristics for create
        */
        table(vector<string> characteristics_input);
        ///Constructor to create class with name and value
        table(const string& name, int value);

        ///Constructor without something. Array is nullptr, len is 0
        table();
        //Destructor
        ///Destructor
        ~table();
        //Getters
        ///This is getter for get characteristic from class using the name of this characteristic
        characteristic& get_characteristic(const string& name) const;
        
        //Checkers
        ///This is checker characteristic in the class using the name and difficult of characteristic
        bool check_characteristic(const string& name, int difficult) const;
        ///This is advantage checker characteristic in the class using the name and difficult of characteristic
        bool check_characteristic_advantage(const string& name, int difficult) const;
        ///This is disadvantage checker characteristic in the class using the name and difficult of characteristic
        bool check_characteristic_disadvantage(const string& name, int difficult) const;
        //Create new characteristic*/
        /**
            Func to create new characteristic in the class
            \param[in] name - name, that user inserts
            \param[in] value - value, that user inserts
        */
        void create_characteristic(string name, int value);
        //Sort characteristics and get_max_characteristic
        /**
            Func to sort characteristic, work with comparator
        */
        void sort_characteristic();
        characteristic& get_max_characteristic(const vector<string>& names);
        //Print_table
        void print();

        /**
            This func is created to push characteristic back to the array of characteristics
            \param[in] ptr - pointer to an array, where is needed to add characteristic
            \param[in] item - characteristic to push
        */
        void push_back(characteristic& item);
        //Operators overloading
        table& operator = (table &&move_right) noexcept;

        table& operator = (const table &right);
        table& operator += (characteristic& insert);
        characteristic operator [] (string name) const;
        characteristic& operator [] (string name);
        /**
            This operator can be used for choosing check type in the class
        */
        bool operator () (string name, int difficult, int number) const;
};

        
