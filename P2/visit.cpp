#include "visit.hh"
#include "hotel.hh"
#include <vector>
#include <iostream>

using namespace std;


vector<Visit> current_visits;
vector<Visit> all_visits;

//void print_all(const vector<Hotel::room_>& rooms) {
//}

void print_all(const vector<Visit> visits) {
    for(Visit visit : visits) {
        visit.get_startdate().print();

    }
}

//void print_current(const vector<Hotel::room_>& rooms) {

//}
