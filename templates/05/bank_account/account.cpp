#include "account.hh"
#include <iostream>

using namespace std;

Account::Account(const string& owner, bool has_credit):
{
    generate_iban();
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        cout << "Too many accounts" << endl;
    }
    suffix.append(to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
