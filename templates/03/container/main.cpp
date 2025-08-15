#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Prints the elements in the parameter vector ints.
void print_integers(const vector< int >& ints)
{
    for(auto elem : ints) {
        cout << elem << " ";
    }
    cout << endl;
}

// Reads as many integers as the parameter count indicates
// and stores them into the parameter vector ints.
void read_integers(vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i) {
        cin >> new_integer;
        // TODO: Implement your solution here
    }
}

// TODO: Implement your solution here


int main()
{
    cout << "How many integers are there? ";
    int how_many = 0;
    cin >> how_many;

    if(how_many <= 0) {
        return EXIT_FAILURE;
    }

    cout << "Enter the integers: ";
    vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers)) {
        cout << "All the integers are the same" << endl;
    } else {
        cout << "All the integers are not the same" << endl;
    }

    if(is_ordered_non_strict_ascending(integers)) {
        cout << "The integers are in a non-strict ascending order" << endl;
    } else {
        cout << "The integers are not in a non-strict ascending order" << endl;
    }

    if(is_arithmetic_series(integers)) {
        cout << "The integers form an arithmetic series" << endl;
    } else {
        cout << "The integers do not form an arithmetic series" << endl;
    }

    if(is_geometric_series(integers)) {
        cout << "The integers form a geometric series" << endl;
    } else {
        cout << "The integers do not form a geometric series" << endl;
    }

    triple_integers(integers);
    cout << "Tripled values: ";
    print_integers(integers);

    return EXIT_SUCCESS;
}

