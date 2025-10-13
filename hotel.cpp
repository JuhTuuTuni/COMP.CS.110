#include "hotel.hh"
#include "utils.hh"
#include <iostream>
#include <fstream>
#include <set>

// Error and information outputs
const string FILE_NOT_FOUND = "Error: Input file not found."s;
const string WRONG_FORMAT = "Error: Wrong format in file."s;
const string NOT_NUMERIC = "Error: Wrong type of parameters."s;
const string ALREADY_EXISTS = "Error: Already exists: "s;
const string CANT_FIND = "Error: Can't find anything matching: "s;
const string GUEST_ENTERED = "A new guest has entered."s;
const string GUEST_LEFT = "Guest left hotel, visit closed."s;
const string FULL = "Error: Can't book, no such rooms available."s;

Hotel::Hotel()
{
    //cout << "Hotel constructor" << endl;
}

Hotel::~Hotel()
{
    //cout << "Hotel destructor" << endl;
}

bool Hotel::init()
{
    cout << "Input file: ";
    string file_name = "";
    getline(cin, file_name);
    ifstream file(file_name);
    if ( not file )
    {
        cout << FILE_NOT_FOUND << endl;
        return false;
    }

    string line = "";
    while ( getline(file, line) )
    {
        vector<string> parts = utils::split(line, ';');
        if ( parts.size() != 2 )
        {
            cout << WRONG_FORMAT << endl;
            return false;
        }
        if ( not ( utils::is_numeric(parts.at(0), false) and
                   utils::is_numeric(parts.at(1), false) ) )
        {
            cout << NOT_NUMERIC << endl;
            return false;
        }

        unsigned int amount = stoi(parts.at(1));
        for ( unsigned int i = 0; i < amount; ++i )
        {
            unsigned int size = stoi(parts.at(0));
            // TODO: Write code that creates rooms and adds them into a suitable data structure
        }
    }
    return true;
}

void Hotel::set_date(Params params)
{
    string day = params.at(0);
    string month = params.at(1);
    string year = params.at(2);
    if ( not utils::is_numeric(day, false) or
         not utils::is_numeric(month, false) or
         not utils::is_numeric(year, false) )
    {
        cout << NOT_NUMERIC << endl;
        return;
    }
    utils::today.set(stoi(day), stoi(month), stoi(year));
    cout << "Date has been set to ";
    utils::today.print();
    cout << endl;
}

void Hotel::advance_date(Params params)
{
    string amount = params.at(0);
    if ( not utils::is_numeric(amount, true) )
    {
        cout << NOT_NUMERIC << endl;
        return;
    }
    utils::today.advance(stoi(amount));
    cout << "New date is ";
    utils::today.print();
    cout << endl;
}

void Hotel::print_rooms(Params /*params*/)
{
}

void Hotel::book(Params params)
{
}

void Hotel::leave(Params params)
{
}

void Hotel::print_guest_info(Params params)
{
}

void Hotel::print_all_visits(Params /*params*/)
{
}

void Hotel::print_current_visits(Params /*params*/)
{
}

void Hotel::print_honor_guests(Params /*params*/)
{
}
