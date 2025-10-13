//------------------------------------------------
//  COMP.CS.110 Programming 2: Techniques
//  Copyright Â© 2025
//------------------------------------------------

/*Hotel
 *
 * Description:
 * Program that simulates a hotel based on information taken from a file,
 * where each line is of the form x;y x being the room capacity and y the
 * number of such rooms.
 *
 * The hotel can intake guests, and the date can be set and advanced.
 * The program also allows for printing of different kinds of information.
 *
 * Program authors
 * Names: Juho Tuulos, Niklas Korpeinen
 * Student numbers: 151867558, 153845484
 * Username: nxjutu, crr566
 * Email: juho.tuulos@tuni.fi, niklas.korpeinen@tuni.fi
 */

#include "cli.hh"
#include "hotel.hh"
#include <string>
#include <memory>

using namespace std;

const string PROMPT = "Hotel> ";

int main()
{
    shared_ptr<Hotel> hotel = make_shared<Hotel>();
    if ( not hotel->init() )
    {
        return EXIT_FAILURE;
    }

    Cli cli(hotel, PROMPT);
    while ( cli.exec() );

    return EXIT_SUCCESS;
}
