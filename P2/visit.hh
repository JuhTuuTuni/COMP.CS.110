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
#include <iostream>
#include <vector>

using namespace std;

class Visit
{
public:
    // TODO: Add parameters for the constructor if needed
    Visit();
    ~Visit();

    Visit(Date start, int room_num);

    void end_visit(Date end);

    //void print_current(const vector<Hotel::room_>& rooms);

    // TODO: More public methods

    const Date& get_startdate() const {
        return start_;
    }

    const Date& get_enddate() const{
        return end_;
    }

    bool get_current() const {
        return current_;
    }

    const int& get_roomnum() const{
        return room_num_;
    }


private:
    Date start_;
    Date end_;
    bool current_;
    int room_num_;

    // TODO: More attributes and private methods
};

#endif // VISIT_HH
