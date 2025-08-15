#include "library.hh"
#include <iostream>

using namespace std;

int main()
{
    // Create a library
    Library library;

    // Create three books and add them to the library
    Book book1({"Kivi", "Seitsemän veljestä"});
    Book book2({"Camus", "Sivullinen"});
    Book book3({"Irving", "Oman elämänsä sankari"});
    library.add_book(book1);
    library.add_book(book2);
    library.add_book(book3);

    // Reserve books
    library.reserve_book(book1);
    library.reserve_book(book2);
    library.reserve_book(book2);
    library.reserve_book(book3);
    library.reserve_book(book3);
    library.reserve_book(book3);

    cout << "Print reservations separately:" << endl;
    cout << library.reservations(book1) << endl;
    cout << library.reservations(book2) << endl;
    cout << library.reservations(book3) << endl << endl;

    cout << "Print all books and their reservations:" << endl;
    library.print_reservations();

    return 0;
}
