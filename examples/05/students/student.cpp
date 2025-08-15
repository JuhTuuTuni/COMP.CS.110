#include "student.hh"
#include <iostream>

using namespace std;

Student::Student(string const& name, const Date& birth_day):
    name_(name), collected_credits_(0), birth_day_(birth_day)
{
}

Student::~Student()
{
}

void Student::start_studies(const Date &today)
{
    studies_started_ = today;
}

void Student::complete_course(unsigned int credits)
{
    collected_credits_ += credits;
}

bool Student::older_than(const Student &other_stud) const
{
    return birth_day_ < other_stud.birth_day_;
}

bool Student::studied_longer_than(const Student &other_stud) const
{
    return studies_started_ < other_stud.studies_started_;
}

void Student::print() const
{
    cout << "* Name: " << name_ << endl;
    cout << "* Birth day: ";
    birth_day_.print();
    cout << "* Credits: " << collected_credits_ << endl;
    cout << "* Studies started: ";
    studies_started_.print();
    cout << endl;
}
