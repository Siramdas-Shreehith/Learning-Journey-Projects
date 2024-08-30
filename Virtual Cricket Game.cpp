//============================================================================
// File Name           : Virtual.cpp.
// Author  Name    :  Siramdas Shreehith.
// Description         : Virtual Cricket Game.
//============================================================================

#include "game.h"
using namespace std;

int main() {
    Game game;
    game.Welcome();
	cout << "\nPress Enter to continue";
	cin.get();
    game.showAllPlayers();
	cout << "\nPress Enter to continue";
	cin.get();
    game.selectPlayers();
    cout << "\nTeam Players:" << endl;
    game.showTeamPlayers();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\nPress Enter to Toss The Coin";
    cin.get();
    cout << "\nToss:" << endl;
    game.toss();
    game.startFirstInnings();
    game.startSecondInnings();
    return 0;
}
