//------------------------------------------------
//  COMP.CS.110 Programming 2: Techniques
//  Copyright © 2025
//------------------------------------------------

/*Book Diary
 *
 * Description:
 * Program that reads data about books from a file where the lines are of the form:
 * author;title;number_of_pages;date
 * Program checks if each line is of correct form.
 *
 *
 * Program authors
 * Names: Juho Tuulos, Niklas Korpeinen
 * Student numbers: 151867558, 153845484
 * Username: nxjutu, crr566
 * Email: juho.tuulos@tuni.fi, niklas.korpeinen@tuni.fi
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*********************/
/* Utility functions */
/*********************/

// Split the given string based on the given delimiter.
// Consider text enclosed with quatation marks as a single word.
vector<string> split(const string& str, char delim) {
    vector<string> result = {""};
    bool inside_quotation = false;
    for ( char current_char : str ) {
        if ( current_char == '"' ) {
            inside_quotation = not inside_quotation;
        } else if ( current_char == delim and not inside_quotation ) {
            result.push_back("");
        } else {
            result.back().push_back(current_char);
        }
    }
    return result;
}

// Return true, if and only if the given string consists only of digits.
bool is_numeric(const string& str) {
    for( unsigned int i = 0; i < str.size(); ++i ) {
        if ( not isdigit(str.at(i)) ) {
            return false;
        }
    }
    return true;
}

// Return true, if and only if the given string consists only of empty spaces.
bool is_space(const string& str) {
    for ( char ch : str ) {
        if ( ch != ' ' ) {
            return false;
        }
    }
    return true;
}

// Print the given error message.
void error_message(const string& text) {
    cout << "Error: " << text << endl;
}

/****************************/
/* End of utility functions */
/****************************/

//tiedoston lukeminen

void read_file() {
    cout << "Input file: ";
    string filename;
    cin >> filename;
    string text;
    int puolipisteet = 0;

    ifstream MyFile(filename);
    if(not MyFile) {
        cout << "Error! The input file cannot be opened.";
        return EXIT_FAILURE;
    }

    while(getline(MyFile, text)) {
        for(char c : text) {
            if(c == ';') {
                puolipisteet += 1;
            }
        }
        if(puolipisteet != 3) {
            cout << "Error : the input file has an erroneous line";
            return EXIT_FAILURE;
        }
    }

    size_t first = text.find(";");
    size_t second = text.find(";", first + 1);
    size_t third = text.find(";", second + 1);
    size_t fourth = text.find(";", third + 1);

std:string pages;
    if(third  == std::string::npos) {
        pages = text.substr(second + 1);
    } else {
        pages = text.substr(second + 1, third - second - 1);
    }



}

int main() {

    // creating a map containing all the allowed commands and their proper lengths
    string Q = "quit";
    string A = "authors";
    string BB = "books_by";
    string AO = "authors_of";
    string T = "thickest";
    string RB = "recent_books";

    map<string, size_t> allowed_commands = {{Q, 1}, {A, 1}, {BB, 2}, {AO, 2}, {T, 1}, {RB, 2}};

    while(1) {
        string cmd_long = "";
        cout << "> ";
        getline(cin, cmd_long);

        // split the given command string into parts
        vector<string> cmd_split = split(cmd_long, ' ');

        string cmd = cmd_split[0];

        // check that command is known, and that it is of the right length
        if(allowed_commands.count(cmd)) {
            if (sizeof(cmd_split) != allowed_commands[cmd]){
                cout << "Error: error in command: " << cmd;
                continue;
            }
        }

        else {
            cout << "Error: unknown command: " << cmd;
            continue;
        }

        //Run through the commands
        if (cmd_split[0] == Q) {
            return EXIT_SUCCESS;
        }

        else if (cmd == A) {

        }

        else if (cmd == BB) {

        }

        else if (cmd == AO) {

        }

        else if (cmd == T) {

        }

        else if (cmd == RB) {

        }
    }


    return EXIT_SUCCESS;
}
