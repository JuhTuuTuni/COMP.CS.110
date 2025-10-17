#include "visit.hh"

using namespace std;

Visit::Visit()
{
}

//constructor for the visit class
//parameters are a Date for the start of the visit and the number of the room
Visit::Visit(Date start, int room_num)
{
    room_num_ = room_num;
    start_ = start;
    current_ = true;
    end_ = Date();
}


//method to end a visit at a specified date
//parameter is the date of the end of the visit
void Visit::end_visit(Date end) {

    end_ = end;
    current_ = false;
}
