#include "player.hh"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Player player1 = Player("Matti");
    Player player2 = Player("Teppo");
    Player* in_turn = 0;

    int turn = 1;
    while (true)
    {
        if (turn % 2 != 0)
        {
            in_turn = &player1;
        }
        else
        {
            in_turn = &player2;
        }

        cout << "Enter the score of player " << in_turn->get_name()
                  << " of turn " << turn << ": ";
        int pts = 0;
        cin >> pts;

        in_turn->add_points(pts);
        if (in_turn->has_won())
        {
            cout << "Game over! The winner is " << in_turn->get_name() << "!" << endl;
            return EXIT_SUCCESS;
        }

        cout << endl;
        cout << "Scoreboard after turn " << turn << ":" << endl;
        cout << player1.get_name() << ": " << player1.get_points() << "p" << endl;
        cout << player2.get_name() << ": " << player2.get_points() << "p" << endl;
        cout << endl;

        turn += 1;
    }

    return EXIT_SUCCESS;
}
