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

//function for printing the known authors and their bibliography in alphabetical order
void print_authors(const map<string, vector<string>>& auths) {
    // map is already in alphabetical order so no need to sort
    for(const auto& pair : auths) {
        cout << pair.first;

        //collect the book names into a temporary vector in alphabetical order
        vector<string> books = {};
        for () {
            books.push_back()
        }

    }
}


/****************************/
/* End of utility functions */
/****************************/

// Tarkistaa, onko merkkijono numeerinen
bool isNumeric(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}


map<string, vector<string>> read_file(const string &filename) {
    ifstream MyFile(filename);
    if (!MyFile) {
        cout << "Error: the input file cannot be opened";
        exit(EXIT_FAILURE);
    }

    map<string, vector<string>> tietue;
    tietue["author"] = {};
    tietue["title"]  = {};
    tietue["pages"]  = {};
    tietue["date"]   = {};
    string line;
    int lineNumber = 0;

    while (getline(MyFile, line)) {
        lineNumber++;

        int puolipisteet = 0;
        for(char c : line) {
            if(c == ';') {
                puolipisteet += 1;
            }
        }
        if(puolipisteet != 3) {
            cout <<  "Error: the input file has an erroneous line";
            EXIT_FAILURE;
        }

        size_t first  = line.find(';');
        size_t second = line.find(';', first + 1);
        size_t third  = line.find(';', second + 1);

        string author = line.substr(0, first);
        string title  = line.substr(first + 1, second - first - 1);
        string pages  = line.substr(second + 1, third - second - 1);
        string date   = line.substr(third + 1);

        if (author.empty() || title.empty() || pages.empty()) {
            cout << "Error: a line has an empty field";
            EXIT_FAILURE;
        }

        if (!isNumeric(pages)) {
            cout << "Error: amount of pages is not numeric";
            EXIT_FAILURE;
        }
        tietue["author"].push_back(author);
        tietue["title"].push_back(title);
        tietue["pages"].push_back(pages);
        tietue["date"].push_back(date);
    }

    return tietue;
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
