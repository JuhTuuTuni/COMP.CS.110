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
#include "hotel.hh"
#include <vector>

using namespace std;

class Visit
{
public:
    // TODO: Add parameters for the constructor if needed
    Visit();
    ~Visit();

    void print_all(const vector<Hotel::Room>& rooms);

    void print_current(const vector<Hotel::Room>& rooms);

    // TODO: More public methods

private:
    Date start_;
    Date end_;

    struct person {
        string name;
    };

    struct room_;

    vector<room_> rooms;

    // TODO: More attributes and private methods
};

#endif // VISIT_HH
