// Header file: time.hh
#ifndef TIME_HH
#define TIME_HH

#include <string>

class Time {
public:
    Time(const std::string& time = "00.00");

    bool set_value(int hour, int minute);
    bool set_value(const std::string& hhmm);
    bool read_from_keyboard(const std::string& prompt);
    bool less_or_equal(const Time& time2) const;
    void print() const;

private:
    int hour_;
    int minute_;
};

#endif
