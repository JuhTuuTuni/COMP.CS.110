#include <iostream>
#include <vector>

#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

using namespace std;

// Returns the index of the smallest character in the given string s.
// The parameter current_ind holds the current index of the string,
// and result_ind holds the index of the smallest characters so far
// (until the current_ind).
unsigned int index_of_smallest(const string& s, unsigned int current_ind = 0,
                               unsigned int result_ind = 0)
{
 
}

// Sorts the given string s based on the ASCII codes of the characters.
// The parameter current_ind holds the end index of the sorted substring so far.
void sort(string& s, unsigned int current_ind = 0)
{
    // -------------------------------------------------------------------------
    // This macro definition is needed for the unit testing of your solution, so 
    // don't touch it!
       RECURSIVE_FUNC
    // Write your solution below, please.
    // -------------------------------------------------------------------------

}

#ifndef UNIT_TESTS
// Main function asks input, calls other functions, and prints results.
int main()
{
    cout << "Enter a string: ";
    string input_str = "";
    cin >> input_str;
    cout << "Index of smallest character: " << index_of_smallest(input_str)
         << endl;
    sort(input_str);
    cout << "Sorted string: " << input_str << endl;
    return EXIT_SUCCESS;
}
#endif

