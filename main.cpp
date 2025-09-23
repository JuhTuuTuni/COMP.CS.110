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
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

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
void print_authors(const map<string, map<string, vector<string>>>& auths) {
    // map is already in alphabetical order so no need to sort
    // first print out the author as the first elements of the map
    for(const auto& a_pair : auths) {
        cout << a_pair.first << endl;

        //for each author print out their books which are also in alphabetical order
        for (const auto& b_pair : a_pair.second) {
            cout << " * " << b_pair.first << endl;
        }

    }
}

// function that prints all books by a certain author
void print_books_by(const map<string, map<string, vector<string>>>& auths, string key) {

    //if author is unknown, print error message and exit function
    if (not auths.count(key)) {
        error_message("unknown author");
        return;
    }

    //print out all the books (which are already) in alphabetical order
    for (const auto& pair : auths.at(key)) {
        cout << pair.first << endl;
    }
}

// prints n of the most recently read books and all books planned to be read
void print_recent_books(map<string, map<string, vector<string>>> auths, int n) {
    cout << "Books read most recently:" << endl;

    //run a loop for n times, where each time we find the most recent book and then print it
    while (int i = 0 < n) {
        string most_recent = "9999-99-99";

        //Iterate through the map
        for(const auto& a_pair : auths) {

            //check all book dates and find the smallest
            for (const auto& b_pair : a_pair.second) {
                if ()

            }

        }

    }

}

void thickest(map<string, vector<vector<string>>> booksByAuthor) {
    int max_sivumaara;

    for(const auto& value_pair: booksByAuthor) {
        for(const auto& book : value_pair.second) {
            int sivumaara = std::stoi(book[1]);
            if(sivumaara > max_sivumaara) {
                max_sivumaara = sivumaara;
            }
        }
    }
    cout << "Thickest book(s) has " << max_sivumaara << " pages:";

    vector<pair<string, string>> thickestBooks;
    for(const auto&value_pair : booksByAuthor) {
        for(const auto& book : value_pair.second) {
            const string& author = value_pair.first;
            for(const auto& book : value_pair.second) {
                if(stoi(book[1]) == max_sivumaara) {
                    thickestBooks.push_back({author, book[0]});
                }
            }
        }


        sort(thickestBooks.begin(), thickestBooks.end(), [](const pair<string,string> &a, const pair<string,string> &b){
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        });

    } for(const auto &result : thickestBooks) {
        cout << result.first << " | " << result.second;
    }
}

// Tarkistaa, onko merkkijono numeerinen
bool isNumeric(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}


/****************************/
/* End of utility functions */
/****************************/

map<string, vector<vector<string>>> read_file_by_author(const string &filename) {
    ifstream MyFile(filename);
    if (!MyFile) {
        cout << "Error: the input file cannot be opened";
        EXIT_FAILURE;
    }

    map<string, vector<vector<string>>> tietue;
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

        }

        if (!isNumeric(pages)) {
            cout << "Error: amount of pages is not numeric";
            exit(EXIT_FAILURE);
        }
        tietue[author].push_back({title, pages, date});
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
