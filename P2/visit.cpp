#include "visit.hh"
#include <vector>
#include <iostream>

using namespace std;


vector<Visit> current_visits;
vector<Visit> all_visits;


Visit::Visit(Date start, Date end = Date(), bool current = true, int room_num = 0, string name = "") {
    start_ = start;
    end_ = end;
    start_ = start;
    current_ = current;
    room_num_ = room_num;
    name_ = name;
}
//void print_current(const vector<Hotel::room_>& rooms) {

//}
