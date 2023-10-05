#include"team.h"
#include<cstdlib>
#include<ctime>
#include<limits>
#include<iostream>

class Game{
public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];

	bool isFirstInnings;
	Team teamA ,teamB;
	Team *battingTeam , *bowllingTeam;
	Player *batsman , *bowler;

	void welcome();
	void showAllPlayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayers(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScorecard();
    void startSecondInnings();
    void initializingPlayers();
    void playGameInnings();
    void bats();
    void showScoreCard();
    bool validatingInningsScore();
    void showMatchSummary();
};
