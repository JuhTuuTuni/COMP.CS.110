#ifndef LIBRARY_HH
#define LIBRARY_HH

#include <string>
#include <vector>
#include <memory>

using namespace std;

// Book has no actual methods (just equivalence comparison), so no class
// is needed, but struct is enough
struct Book
{
    string author;
    string title;
    bool operator==(const Book& rhs)
    {
        return author == rhs.author and title == rhs.title;
    }
};

class Library
{
public:
    // Constructor
    Library();

    // Destructor
    ~Library();

    // Add the given book in library
    void add_book(const Book& book);
    void add_book(const string& author, const string& title);

    // Reserve the given book
    // Return true, if and only if the book can be found from the library
    bool reserve_book(const Book& book);

    // Return the number of reservations of the given book
    unsigned int reservations(const Book& book) const;

    // Print reservations of all books in the library
    void print_reservations() const;

private:
    // Material of the library
    // (Here we could have a vector of Book objects instead of shared pointers,
    // but it would make other code less straightforward.)
    vector<shared_ptr<Book>> books_;

    // Reserved books in the library
    vector<shared_ptr<Book>> reservations_;
};

#endif // LIBRARY_HH
