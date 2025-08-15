#include <iostream>
#include <string>
#include <vector>

using namespace std;

// TODO: Implement split function here
// Do not change main function


int main()
{
    string line = "";
    cout << "Enter a string: ";
    getline(cin, line);
    cout << "Enter the separator character: ";
    char separator = getchar();

    vector< string > parts  = split(line, separator);
    cout << "Splitted string including empty parts: " << endl;
    for( auto part : parts ) {
        cout << part << endl;
    }

    vector< string > parts_no_empty  = split(line, separator, true);
    cout << "Splitted string ignoring empty parts: " << endl;
    for( auto part : parts_no_empty ) {
        cout << part << endl;
    }

    return EXIT_SUCCESS;
}
