#include "visit.hh"
#include <vector>
#include <iostream>

using namespace std;


vector<Visit> current_visits;
vector<Visit> all_visits;

Visit::Visit()
{
}

Visit::Visit(int room_num)
{
    room_num_ = room_num;
    start_ = Date();
    end_ = Date();
    current_ = true;
}

Visit::~Visit()
{
}

void Visit::end_visit() {
    cout << "test" << endl;
    end_.print();
    end_ = Date(8, 9, 2025);
    current_ = false;
    cout << "test" << endl;
}
