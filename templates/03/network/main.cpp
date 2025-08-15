#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


vector<string> split(const string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    vector<string> result;
    string tmp = s;

    while(tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

// TODO: Implement command functions here

int main()
{
     set<string> valid_commands = {"S", "s", "P", "p", "C", "c",
                                             "D", "d", "Q", "q"};

    // TODO: Implement the datastructure here

    while(true)
    {
        string line;
        cout << "> ";
        getline(cin, line);
        vector<string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        string command = parts.at(0);

        if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id1 = parts.at(1);
            string id2 = parts.at(2);

            // TODO: Implement the command here!

        }
        // Other valid commands are not reasonable for an empty datastructure
	// TODO: complete the condition below
        else if(valid_commands.find(command) != valid_commands.end()
                /* and your datastructure is empty */)
        {
            continue;
        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            // TODO: Call the command function here!

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            // TODO: Call the command function here!

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            // TODO: Call the command function here!

        }
        else
        {
            cout << "Erroneous command!" << endl << HELP_TEXT;
        }
    }
}
