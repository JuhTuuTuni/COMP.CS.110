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

    Visit(Date start, Date end, bool current_, int room_num, string name);

    void print_all(const vector<Visit> visits);

    void end_visit(Date date);

    //void print_current(const vector<Hotel::room_>& rooms);

    // TODO: More public methods

    Date get_startdate() {
        return start_;
    }

    Date get_enddate() {
        return end_;
    }

    bool get_current() {
        return current_;
    }


private:
    Date start_;
    Date end_;
    bool current_;
    int room_num_;
    string name_;

    struct person {
        string name;
    };

    // TODO: More attributes and private methods
};

#endif // VISIT_HH
