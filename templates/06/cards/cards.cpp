#include <iostream>
#include "cards.hh"

using namespace std;

Cards::Cards(): top_(nullptr)
{
    cout << "constructor" << endl;
}

Cards::~Cards()
{
    cout << "destructor" << endl;
}
