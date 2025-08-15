#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    minstd_rand generator;

    cout << "Enter some text. Quit by entering the word \"END\"." << endl;
    string word;

    while (cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        // TODO: implement your solution here
	
        cout << word << endl;
    }

    return EXIT_SUCCESS;
}
