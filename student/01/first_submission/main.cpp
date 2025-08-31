#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "";
    cout << "Enter your name: ";
    getline(cin, name);

    int age = 0;
    cout << "Enter your age: ";
    cin >> age;

    cout << "Pleased to meet you, " << name << "!" << endl;

    return EXIT_SUCCESS;
}
