#include "class.h"

//Operators overloadins
std::ostream& operator << (std::ostream& c, const table &temp);

std::ostream& operator << (std::ostream& c, const characteristic &temp);

std::istream& operator >> (std::istream& s, table &temp);

std::istream& operator >> (std::istream& s, characteristic &temp);
        

//Print_characteristic
void print_characteristic(const characteristic& charac);
