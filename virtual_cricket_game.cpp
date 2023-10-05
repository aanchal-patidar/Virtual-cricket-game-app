
#include "game.h"
using namespace std;

int main() {
	Game game;
		game.welcome();

		cout<< "\npress enter to the continue";
		getchar();

		game.showAllPlayers();

		cout<< "\npress enter to the continue";
		getchar();

		game.selectPlayers();
		game.showTeamPlayers();

		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\npress enter to toss";
		getchar();

		game.toss();

	    game.startFirstInnings();

        game.startSecondInnings();

        game.showMatchSummary();
		return 0;
	}


