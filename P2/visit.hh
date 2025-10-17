/* Class Visit
 * ----------
 * COMP.CS.110 FALL 2025
 * ----------
 * Class for describing a guest's visit in hotel.
 *
 * Note: Students need to implement almost all of this class by themselves.
 * */
#ifndef VISIT_HH
#define VISIT_HH

#include "date.hh"

using namespace std;

class Visit
{
public:
    Visit();
    ~Visit();

    Visit(Date start, int room_num);

    //method for ending a visit at a specified date
    void end_visit(Date end);

    //getter method for the reservations starting date
    const Date& get_startdate() const {
        return start_;
    }

    //getter method for the reservations ending date
    const Date& get_enddate() const{
        return end_;
    }

    //getter method for if the reservation is active/ongoing
    bool get_current() const {
        return current_;
    }

    //getter method for the number of the room
    const int& get_roomnum() const{
        return room_num_;
    }


private:
    //starting date of the reservation
    Date start_;
    //ending date of the reservation
    Date end_;
    //boolean for if the reservation is active/ongoing
    //if true then reservation is active
    bool current_;
    //integer for the number of the room
    int room_num_;
};

#endif // VISIT_HH
