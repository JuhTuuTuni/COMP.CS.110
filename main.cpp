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
//returns a vector that contains strings
vector<string> split(const string& str, char delim) {
    //vector to store the result
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
//takes a parameter of a string that you want to check
//returns a boolean value of whether the given string is numeric
bool is_numeric(const string& str) {
    for( unsigned int i = 0; i < str.size(); ++i ) {
        if ( not isdigit(str.at(i)) ) {
            return false;
        }
    }
    return true;
}

// Return true, if and only if the given string consists only of empty spaces.
//takes a parameter of a string that you want to check
//returns a boolean value of whether the given string is numeric
bool is_space(const string& str) {
    for ( char ch : str ) {
        if ( ch != ' ' ) {
            return false;
        }
    }
    return true;
}

// Print the given error message.
//takes a parameter of a string
//returns an error message as a string
void error_message(const string& text) {
    cout << "Error: " << text << endl;
}

//function for printing the known authors and their bibliography in alphabetical order
//outer map key: string (authors name), outer map value: map of books for the specified author
//inner map key: string (book title), inner map value: vector of the books details
//function has a return value of void so it does not return anything
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
//outer map key: string (authors name), outer map value: map of books from the author
//inner map key : string (book title), inner map value : vector of the books details
//key is the author whos books we want to print
//function has a return value of void so it doesnt return anything
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

//function prints all the authors of a given book (string bookname)
// outer map key : string(authors name), outer map value : a map of the books by that author
// inner map key : string(title of book), outer map value : vector of details of the book
//function has a return value of void so it doesnt return anything
void authors_of(const map<string, map<string, vector<string>>>& booksByAuthor,
                const string &bookname){

    // Vector to store all authors who wrote this book
    vector<string> authors;

    // Go through all authors
    for(const auto& pair : booksByAuthor) {
        const string &author = pair.first;
        const map<string, vector<string>> &authorBooks = pair.second;

        // Go through all books of this author
        for(const auto &bookPair : authorBooks) {
            const string &title = bookPair.first;
            if(title == bookname) {
                authors.push_back(author);
                break;
            }
        }
    }

    // Sort authors alphabetically
    sort(authors.begin(), authors.end());

    // if no authors is empty, no book was found
    if (authors.size() == 0) {
        error_message("unknown title");
    }

    // Print the authors
    for(const string &a : authors) {
        cout << a << endl;
    }
}


// prints n of the most recently read books and all books planned to be read
//outer map key : (string) authors name, outer map value : (map<string, vector<string>>) books from that author
//inner map key : (string) name of book, inner map value: vector<string> which contains the details of the book
//function has a return value of void so it doesnt return anything
void print_recent_books(map<string, map<string, vector<string>>> auths, int n) {

    //map (because its in alphabetical order) that contains all the books yet to be read
    map<string, vector<string>> to_read;

    //string for checking the most recent book
    string most_recent = "0000-00-00";
    //map (because its in alphabetical order) that contains all the books to be printed
    string book = "";
    string author = "";
    string date = "";
    //id = author + book, for alphabetical sorting
    string id = "";
    map<string, vector<string>> to_print;

    //Iterate through the map and erase the books yet to be read
    for(const auto& a_pair : auths) {

        //check all book dates
        for (const auto& b_pair : a_pair.second) {

            book = b_pair.first;
            author = a_pair.first;

            //if the book has yet to be read, the second value is empty
            if (b_pair.second[1].empty()) {
                //add the book to the map of to_read and restart loop
                to_read[author + book] = {author, book};
                continue;
            }
        }
    }

    //erase the unread books from auth
    for (const auto& p : to_read) {
        auths[p.second.at(0)].erase(p.second.at(1));
    }

    //checking if there are any books left
    int books_left = 0;
    for (const auto& a_pair : auths) {
        if (not a_pair.second.empty()) {
            books_left = 1;
            break;
        }
    }

    // if there are still books left, we know some of them will be printed
    if (books_left) {
        cout << "Books read most recently:" << endl;
    }

    else {
        cout << "No books read yet" << endl;
    }

    //run a loop for n times, where each time we find the most recent book(s) and then print
    int i = 0;
    while (i < n) {
        most_recent = "0000-00-00";
        to_print.clear();

        //Iterate through the map
        for(const auto& a_pair : auths) {

            //check all book dates and find the biggest
            for (const auto& b_pair : a_pair.second) {
                book = b_pair.first;
                author = a_pair.first;
                date = b_pair.second.at(1);

                //if new most_recent is found, clear the to_print map
                if (date > most_recent) {
                    to_print.clear();

                    //add the new values of the most recent book
                    most_recent = date;
                    to_print[author + book] = {author, book, date};
                }

                // if there already exists a book with the same date, append it
                else if (date == most_recent) {
                    to_print[{author + book}] = {author, book, date};
                }
            }
        }

        //if new biggest was not found,
        //that means that all read books have been printed
        if (most_recent == "0000-00-00") {
            i = n;
        }

        //otherwise print all the books in to_print,
        //format is: {id, {author, book, date}}
        else {
            for (const auto& book : to_print) {
                cout << " * " << book.second.at(2) << " : " <<
                    book.second.at(0) << " : " << book.second[1] << endl;

                auths[book.second.at(0)].erase(book.second.at(1));
                i++;
            }
        }
    }

    //check if there are any unread books:
    if (to_read.size() == 0) {
        cout << "No books planned to be read" << endl;
    }

    //once the read books have been printed, print the books to be read
    //format is {id, {author, book}}
    else {
        cout << "Books planned to be read:" << endl;

        for (const auto& book : to_read) {
            cout << " * " << book.second.at(0) << " : " <<
                book.second.at(1) << endl;
        }
    }
}

//checks for the biggest books
//outer map key (string) name of author, outer map value : vector of books from that author
//each book is a vector of strings that has a title, number of pages date
//the method has a return value of void so it doesnt return anything
void print_thickest_books(const map<string, map<string, vector<string>>> &booksByAuthor) {
    int max_no_of_pages = 0;

    //goes through every book and finds the highest value for pagenumber
    for(const auto& value_pair: booksByAuthor) {
        for(const auto& book : value_pair.second) {
            int number_of_pages = std::stoi(book.second.at(0));
            //checks for if the current book is longer than the previous high
            if(number_of_pages > max_no_of_pages) {
                max_no_of_pages = number_of_pages;
            }
        }
    }
    cout << "Thickest book(s) has " << max_no_of_pages << " pages:" << endl;

    //vector for the result of the function
    vector<pair<string, string>> thickestBooks;

    //checks which books in particular have the length of maximum length
    for(const auto&value_pair : booksByAuthor) {
            const string& author = value_pair.first;
            for(const auto& book : value_pair.second) {
                //if book has the specified number of pages it gets added into the vector
                if(stoi(book.second.at(0)) == max_no_of_pages) {
                    thickestBooks.push_back({author, book.first});
                }
            }

        //using the sort algorithm to sort the books in an alphabetical order
        sort(thickestBooks.begin(), thickestBooks.end(),
             [](const pair<string,string> &a, const pair<string,string> &b){
                 if (a.first != b.first) {
                     return a.first < b.first;
                 } else {
                     return a.second < b.second;
                 }
             });

        //printing the result
    } for(const auto &result : thickestBooks) {
        cout << " * " << result.first << " : " << result.second << endl;
    }
}

/****************************/
/* End of utility functions */
/****************************/

//function that reads a file and  organizes the books by author
//filename is the name of the file that you want to read
//outer map key : (string) authors name, outer map value: vector of books from the author
//each book is a vector of strings that contains :  title of book, number of pages and date of publication
map<string, map<string, vector<string>>> read_file_by_author(const string &filename) {
    //opening the file
    ifstream MyFile(filename);
    if (!MyFile) {
        error_message("the input file cannot be opened");
        exit(EXIT_FAILURE);
    }

    map<string, map<string, vector<string>>> structure;
    string line;

    while (getline(MyFile, line)) {

        int puolipisteet = 0;
        for(char c : line) {
            if(c == ';') {
                puolipisteet += 1;
            }
        }
        if(puolipisteet != 3) {
            error_message("the input file has an erroneous line");
            exit(EXIT_FAILURE);
        }

        //split the line into author, title, number of pages and date
        size_t first  = line.find(';');
        size_t second = line.find(';', first + 1);
        size_t third  = line.find(';', second + 1);

        string author = line.substr(0, first);
        string title  = line.substr(first + 1, second - first - 1);
        string pages  = line.substr(second + 1, third - second - 1);
        string date   = line.substr(third + 1);

        //checks if one of the three key informations is empty
        if (author.empty() || title.empty() || pages.empty()) {
            error_message("a line has an empty field");
            exit(EXIT_FAILURE);

        }

        //checks if amount of pages isnt numeric
        if (!is_numeric(pages)) {
            error_message("amount of pages is not numeric");
            exit(EXIT_FAILURE);
        }
        //pushing the values into their specified place
        structure[author][title] = { pages, date};
    }
    return structure;
}


int main() {

    // creating a map containing all the allowed commands and their proper lengths
    string Q = "quit";
    string A = "authors";
    string BB = "books_by";
    string AO = "authors_of";
    string T = "thickest";
    string RB = "recent_books";

    map<string, size_t> allowed_commands =
        {{Q, 1}, {A, 1}, {BB, 2}, {AO, 2}, {T, 1}, {RB, 2}};

    string file_name;
    cout << "Input file: ";
    getline(cin, file_name);

    //reading file into struct
    auto auths = read_file_by_author(file_name);

    while(1) {
        string cmd_long = "";
        cout << "> ";
        getline(cin, cmd_long);

        // split the given command string into parts
        vector<string> cmd_split = split(cmd_long, ' ');

        string cmd = cmd_split[0];

        // check that command is known, and that it is of the right length
        if(allowed_commands.count(cmd)) {
            if (cmd_split.size() != allowed_commands[cmd]){
                error_message("error in command " + cmd );
                continue;
            }
        }

        else {
            error_message("unknown command: " + cmd);
            continue;
        }

        //Run through the commands
        if (cmd_split[0] == Q) {
            return EXIT_SUCCESS;
        }

        else if (cmd == A) {
            print_authors(auths);
        }

        else if (cmd == BB) {
            print_books_by(auths, cmd_split[1]);
        }

        else if (cmd == AO) {
            authors_of(auths, cmd_split[1]);
        }

        else if (cmd == T) {
            print_thickest_books(auths);
        }

        else if (cmd == RB) {
            if (not is_numeric(cmd_split[1])) {
                error_message("parameter not numeric");
                continue;
            }
            print_recent_books(auths, std::stoi(cmd_split[1]));
        }
    }
    return EXIT_SUCCESS;
}
