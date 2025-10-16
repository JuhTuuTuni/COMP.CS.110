#include "hotel.hh"
#include "utils.hh"
#include <iostream>
#include <fstream>
#include <set>
#include <memory>

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

    //pointer used in the loop for assigning next to the previous pointer
    shared_ptr<room_> previous;

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

            //creating a new pointer
            shared_ptr<room_> new_room = make_shared<room_>();
            new_room->capacity = size;
            new_room->available = true;

            // if first_ is yet to be set point it to new_room and restart loop
            if (first_ == nullptr) {
                first_ = new_room;
                previous = new_room;
                continue;
            }

            //setting the pointer of the previous room to point to the new room
            previous->next = new_room;
            previous = new_room;

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
    //counter, so that room numbers can be printed out
    int counter = 1;
    shared_ptr<room_>room = first_;

    // when room is nullptr the ned of the loop has been reached
    while (room != nullptr) {
        cout << "Room " << counter << " : " <<
        "for " << room->capacity <<  " person(s)" << " : ";
        if (room->available) {
            cout << "available for " << room->capacity << " person(s)" << endl;
        }

        else {
            cout << "full" << endl;
        }
        room = room->next;
        counter++;
    }
}

void Hotel::book(Params params)
{

    // if the last parameter is not numeric, return
    string last_param = params.at(1);
    if (not utils::is_numeric(last_param, false)) {
        cout << NOT_NUMERIC << endl;
        return;
    }

    string name = params.at(0);

    //if guest is already present, print error and return
    if (guests[name].visiting) {
        cout << ALREADY_EXISTS << name << endl;
        return;
    }

    unsigned int req_size = stoi(params.at(1));

    shared_ptr<room_> room = first_;

    //counter used to write room numbers into visit
    int counter = 1;

    //iterating through rooms to find suitable room and set as booked if found
    while (room != nullptr) {
        if (room->capacity == req_size and room->available) {

            //room has been found, so it's availability is set to false
            room->available = false;

            //creating a new guest struct
            guest_ new_guest = {{}, true};
            //creating a new Visit entity and adding it to the guest struct
            Visit new_visit = Visit(counter);
            new_guest.visits.push_back(new_visit);
            //adding the new guest_ to the map of guests
            guests.insert({name, new_guest});

            cout << "GUEST_ENTERED" << endl;
            return;
        }
        room = room->next;
        counter++;
    }

    //if no suitable rooms were found print error and return
    cout << FULL << endl;
}

void Hotel::leave(Params params)
{
    string name = params.at(0);

    // iterating through guests to find the leaving
    for(auto& pair: guests) {
        if (pair.first == name) {

            cout << GUEST_LEFT << endl;
            pair.second.visits.back().end_visit();

            cout << "test" << endl;

            //getting the room number
            int room_number = pair.second.visits.back().get_roomnum();

            shared_ptr<room_> room = first_;
            //go to the room which is currently not available
            for (int i = 1; i < room_number; i++) {
                room = room->next;
            }
            //setting room as available again
            room->available = true;
            return;
        }
    }

    //if the leaving was not found print error and return
    cout << CANT_FIND << name << endl;
}

void Hotel::print_guest_info(Params params)
{
    if(params.size() < 1) {
        //if no parameters found
        return;
    }
    string guest_id = params.at(0);

    auto it = guests.find(guest_id);

    //if guest id was not found in guests
    if(it == guests.end()) {
        cout << "Cant find anything matching: " << guest_id << endl;
        return;
    }

    const guest_& guest_data = it->second;

    //loop through all of the guests visits on the map
    for(const Visit& visit : guest_data.visits) {
        cout << "* Visit ";
        visit.get_startdate().print();
        cout << " - ";
        //if visits ending date isnt the default it gets printed
        if(!visit.get_enddate().is_default()) {
            visit.get_enddate().print();
            cout << endl;
        }
    }

}

void Hotel::print_all_visits(Params /*params*/)
{
    //if nobody has visited, print error and return
    if (guests.size() == 0) {
        cout << "None" << endl;
        return;
    }

    //loop through all the pairs in guests
    for(const auto& pair: guests) {
        const string name = pair.first;

        //create a vector that will be passed to print_guest_info
        vector<string> single_param = {name};

        print_guest_info(single_param);

    }
}

void Hotel::print_current_visits(Params /*params*/)
{
    //set bool flag in case there are no current visits
    bool no_visitors = true;

    //loop through the pairs in guests
    for(const auto& pair : guests) {
        const string name = pair.first;
        const guest_ guest_data = pair.second;

        //check if visit is still ongoing, print it if it is
        if(guest_data.visiting) {
            const Visit& current = guest_data.visits.back();

            cout << name << " is boarded in room ";
            cout << current.get_roomnum();

            //if visitor was found, change flag
            no_visitors = false;
        }

    }
    if (no_visitors) {
        cout << "None" << endl;
    }
}


void Hotel::print_honor_guests(Params /*params*/)
{
    size_t most_visits = 0;
    //loop through guests to find the guest with longest visits vector
    for(const auto& pair : guests) {
        if (pair.second.visits.size() > most_visits) {
            most_visits = pair.second.visits.size();
        }
    }
    //if most_visits is still 0, then guests is empty, error and return
    if (most_visits == 0) {
        cout << "None" << endl;
        return;
    }

    //finding all the guests with most_visits visits and printing their info
    for(const auto& pair : guests) {
        if (pair.second.visits.size() == most_visits) {

            const string name = pair.first;
            vector<string> single_param = {name};

            print_guest_info(single_param);
        }
    }
}
