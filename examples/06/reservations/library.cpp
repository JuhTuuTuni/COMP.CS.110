#include "library.hh"
#include <iostream>

Library::Library()
{
}

Library::~Library()
{
}

void Library::add_book(const Book &book)
{
    shared_ptr<Book> new_book = make_shared<Book>(book);
    books_.push_back(new_book);

    // The above two code lines could be replaced with the following one:
    // books_.push_back(make_shared<Book>(book));
}

void Library::add_book(const string &author, const string &title)
{
    Book book({author, title});
    add_book(book);
}

bool Library::reserve_book(const Book &book)
{
    for ( const shared_ptr<Book>& current_book : books_ )
    {
        if ( *current_book == book )
        {
            shared_ptr<Book> new_reservation = current_book;

            // new_reservation is a local variable, so to keep use count
            // increased, i.e. to keep a shared pointer pointing to an object,
            // the pointer must be stored more globally, e.g. to a container
            reservations_.push_back(new_reservation);

            return true;
        }
    }
    return false;
}

unsigned int Library::reservations(const Book &book) const
{
    for ( const shared_ptr<Book>& current_book : books_ )
    {
        if ( *current_book == book )
        {
            return current_book.use_count() - 1; // Count only additional
                                                 // pointers
        }
    }
    return 0;
}

void Library::print_reservations() const
{
    // Print books
    for ( const shared_ptr<Book>& book : books_ )
    {
        cout << book.use_count() - 1 << " "; // Count only additional pointers
    }
    cout << endl;

    // Print reservations
    for ( const shared_ptr<Book>& reservation : reservations_ )
    {
        cout << reservation.use_count() - 1 << " "; // Count only additional
                                                    // pointers
    }
    cout << endl;
}
