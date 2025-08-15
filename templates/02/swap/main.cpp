#include <cstdlib>
#include <iostream>

using namespace std;

// Write your swap function here.



#ifndef UNIT_TESTING
int main()
{
    cout << "Enter an integer: ";
    int i = 0;
    cin >> i;

    cout << "Enter another integer: ";
    int j = 0;
    cin >> j;

    swap(i, j);
    cout << "The integers are " << i << " and " << j << endl;

    return EXIT_SUCCESS;
}
#endif
