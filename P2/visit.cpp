#include "visit.hh"
#include <vector>
#include <iostream>

using namespace std;

Visit::Visit()
{
}

Visit::Visit(Date start, int room_num)
{
    room_num_ = room_num;
    start_ = start;
    current_ = true;
    end_ = Date();
}

Visit::~Visit()
{
}

void Visit::end_visit(Date end) {

    end_ = end;
    current_ = false;
}
