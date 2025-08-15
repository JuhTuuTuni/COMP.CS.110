#include "queue.hh"
#include <iostream>

using namespace std;

bool is_positive_number(const string& num_str)
{
    // An empty string or a string starting with zero are not considered as
    // positive numbers
    if(num_str.size() == 0 or num_str.at(0) == '0')
    {
        return false;
    }

    // Going through the string and checking each character
    for(char ch : num_str)
    {
        if(not isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const unsigned int VEHICLES_PER_GREEN_PERIOD = 3;
    Queue q(VEHICLES_PER_GREEN_PERIOD);
    cout << "Current cycle is " << VEHICLES_PER_GREEN_PERIOD
         << ", i.e. at most " << VEHICLES_PER_GREEN_PERIOD
         << " vehicles can pass during the same green period" << endl;

    while(true) {
        cout << "(a)dd, (p)rint, (s)witch light, (r)eset cycle, (q)uit: ";
        string choice = "";
        getline(cin, choice);
        if ( choice == "a" ) {
            cout << "  Input a register number: ";
            string reg = "";
            getline(cin, reg);
            q.enqueue(reg);
        } else if ( choice == "p" ) {
            q.print();
        } else if ( choice == "s" ) {
            q.switch_light();
        } else if ( choice == "r" ) {
            cout << "  Input a new amount for cycle: ";
            getline(cin, choice); // reusing an existing variable
            unsigned int cycle = 0;
            // Ensuring that choice (cycle) is a positive number
            if(not is_positive_number(choice))
            {
                cout << "Not a positive number, using 1 instead" << endl;
                cycle = 1;
            }
            else
            {
                cycle = stoi(choice);
            }
            q.reset_cycle(cycle);
        } else if ( choice == "q" ) {
            break;
        } else {
            cout << "An unknown command" << endl;
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}
