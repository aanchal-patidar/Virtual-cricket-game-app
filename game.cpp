#include"game.h"
using namespace std;

Game :: Game(){
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Rahul";
	players[1] = "Virat";
	players[2] = "Sachin";
	players[3] = "Kohli";
	players[4] = "Yuvraj";
	players[5] = "Shery";
	players[6] = "Prakhar";
	players[7] = "Ashutosh";
	players[8] = "Aniket";
	players[9] = "Rupesh";
	players[10] = "Aanchal";


	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}

void Game::welcome(){
cout<<"*******************************************************************************************"<<endl << endl<<endl;
cout<< "|---------------------------------------------------------------------------------------|"<<endl;
cout<< "| ====================================CRIC-IN===========================================|"<<endl;
cout<< "|                                                                                       |"<<endl;
cout<< "|*************************Welcome to the Virtual Cricket game***************************|"<<endl;
cout<< "|---------------------------------------------------------------------------------------|"<<endl << endl;

cout<< "____________________________________________________________________________________________"<<endl;
cout<< "|                                                                                           |"<<endl;
cout<< "|===================================Instruction for Game====================================|"<<endl;
cout<< "|___________________________________________________________________________________________"<<endl << endl;
cout<< "       || 1.  hitting the ball and running the wickets and making it to the other			"<<endl;
cout<< "              end before the filders can hit the wickets with the ball 			        	"<<endl;
cout<< "       || 2.  hitting the ball to the boundary along the ground is the four runs    		"<<endl;
cout<< "       || 3.  hitting the ball over the boundary on the full equal six runs 	        	"<<endl;
cout<< "                                                                                            "<<endl;
cout<< "=====================================END INSTRUCTIONS======================================"<<endl << endl<<endl;
cout<<"*********************************************************************************************"<<endl;
}

void Game::showAllPlayers(){
	cout << endl;
	cout <<"------------------------------------------------------------------------"<<endl;
	cout <<"========================= PULL OF PLAYERS =============================="<<endl;
	cout <<"------------------------------------------------------------------------"<<endl;
	cout << endl;

	for(int i=0; i<totalPlayers; i++){
		cout<<"\t\t["<< i << "]" << players[i]<< endl;
	}

}
int Game::takeIntegerInput(){
	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input please try again.";
	}
	return n;
}

bool Game::validateSelectedPlayers(int index){
	int n;
	vector<Player>players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i<n ; i++){
		if(players[i].id == index){
			return false;

		}
	}
	players = teamB.players;
		n = players.size();
		for (int i = 0; i<n ; i++){
			if(players[i].id == index){
				return false;

			}
		}
	return true;
}
void Game::selectPlayers(){
	cout << endl;
	cout <<"-----------------------------------------------------------------------"<<endl;
	cout <<"=================create team-A and team-B=============================="<<endl;
	cout <<"-----------------------------------------------------------------------"<<endl;
	cout << endl;


	for (int i = 0 ; i<playersPerTeam ; i++){
		//add player to team A
		teamASelected:

		cout << endl << "select player " << i + 1 << " of team A - ";
		int	playerIndexTeamA = takeIntegerInput();

		if(playerIndexTeamA < 0 || playerIndexTeamA > 10){
			cout << endl << "please select from the given players" << endl;
			goto teamASelected;

		}else if(!validateSelectedPlayers(playerIndexTeamA)){
			cout << endl << " Player has been already selected . please select other player" << endl;
			goto teamASelected;

		}else{
			Player teamAPlayer;
					teamAPlayer.id = playerIndexTeamA;
					teamAPlayer.name = players[playerIndexTeamA];
					teamA.players.push_back(teamAPlayer);


		}


		//add player to the team B
		teamBSelected:

		cout << endl << "select player " << i+1 << " of team B - ";
		int	playerIndexTeamB = takeIntegerInput();

		if(playerIndexTeamB < 0 || playerIndexTeamB > 10){
					cout << endl << "please select from the given players" << endl;
					goto teamBSelected;

				}else if(!validateSelectedPlayers(playerIndexTeamB)){
					cout << endl << " Player has been already selected . please select other player" << endl;
					goto teamBSelected;

				}else{
					Player teamBPlayer;
							teamBPlayer.id = playerIndexTeamB;
							teamBPlayer.name = players[playerIndexTeamB];
							teamB.players.push_back(teamBPlayer);
				}


	}
}

void Game::showTeamPlayers(){
	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout << endl << endl;
	cout << "----------------------\t\t------------------------" << endl;
	cout << "|=====Team-A==========\t\t======Team-B============|" << endl;
	cout << "----------------------\t\t------------------------" << endl;

	for(int i = 0 ; i < playersPerTeam ; i++){
		cout << "|\t" << "[" << i << "]" << teamAPlayers[i].name <<"\t|" <<"\t"
		"|\t" << "[" << i << "]" << teamBPlayers[i].name << "\t|" << "\t" << endl;


	}

	cout << "-----------------------\t\t------------------------ " << endl;
}
void Game::toss(){
	cout << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "====================Let's toss===============================" << endl;
	cout << "------------------------------------------------------------" << endl;

	cout << "Tossing the coin....." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2 ;
	switch (randomValue){

	case 0:
	cout << "Team-A won the toss" << endl;
	tossChoice(teamA);
	break;

	case 1:
	cout << " Team-B won the toss" << endl;
	tossChoice(teamB);
	break;

	}
}

void Game::tossChoice(Team tossWinnerTeam){

	cout << "Enter 1 to bat or 2 to bowl first." << endl
			<<"1. bat "<<endl
			<<"2. bowl"<<endl;

			int tossInput = takeIntegerInput();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');

			switch (tossInput){

			case 1:
			cout << endl << tossWinnerTeam.name << "won the toss and choose the bat first" << endl;

			if(tossWinnerTeam.name.compare("Team-A") == 0){
				battingTeam = &teamA;
				bowllingTeam = &teamB;

			} else {
				battingTeam = &teamB;
				bowllingTeam = &teamA;

			}
			break;

			case 2:
				cout << endl << tossWinnerTeam.name << "won the toss and choose the bat first" << endl;

				if(tossWinnerTeam.name.compare("Team-A") == 0){
					bowllingTeam = &teamA;
					battingTeam = &teamB;

				}else {
					bowllingTeam = &teamB;
					battingTeam = &teamA;

				}
				break;

			default:
				cout << endl << "invalid input . please try again." << endl << endl;

				tossChoice(tossWinnerTeam);
				break;
			}
}
void Game::startFirstInnings() {

	cout << "\t\t ||| FIRST INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {

	// Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowllingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowllingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		getchar();
		cout << "Bowling..." << endl;

		bat();

	    if (!validateInningsScore()) {
	    	break;
	    }
	}
}

void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowllingTeam->totalBallsBowled = bowllingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else { 	// else runScored = 0 and the batsman is �OUT�
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->WicketsLost = battingTeam->WicketsLost + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;

    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->WicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }
}

bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->WicketsLost == playersPerTeam || bowllingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->WicketsLost << " (" << bowllingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowllingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings
    if (battingTeam->totalRunsScored > bowllingTeam->totalRunsScored) { //Case1: If batting team score > bowling team score
            cout << battingTeam->name << " WON THE MATCH" << endl << endl;
    return false;
    //Case2: Batting team is all OUT OR Bowling team is done bowling
    } else if (battingTeam->WicketsLost == playersPerTeam || bowllingTeam->totalBallsBowled == maxBalls) {
    if (battingTeam->totalRunsScored < bowllingTeam->totalRunsScored) {
    cout << bowllingTeam->name << " WON THE MATCH" << endl << endl;
    } else {
        cout << "MATCH DRAW" << endl << endl;
    }
    return false;
    }
    }

return true;


    }




void Game::showGameScorecard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->WicketsLost << " (" << bowllingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}


void Game::startSecondInnings(){
    cout << "\t\t ||| SECOND INNINGS STARTS |||" << endl << endl;
    isFirstInnings = false;
    Team tempTeam = *battingTeam;
    *battingTeam = *bowllingTeam;
    *bowllingTeam = tempTeam;
    initializePlayers();
    playInnings();
}
void Game::initializingPlayers(){

    batsman = &battingTeam->players[0];
    bowler = &bowllingTeam->players[0];

    cout << battingTeam->name << "-" << batsman->name << "is batting" << endl;
    cout << bowllingTeam->name << "-" << bowler->name << "is bowlling" << endl << endl;

}
void Game::playGameInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		getchar();
		cout << "Bowling..." << endl;

		bats();

	    if (!validatingInningsScore()) {
	    	break;
	    }
	}
}

void Game::bats() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowllingTeam->totalBallsBowled = bowllingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showScoreCard();
    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->WicketsLost = battingTeam->WicketsLost + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;

    	showScoreCard();

    	int nextPlayerIndex = battingTeam->WicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }
}


bool Game::validatingInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->WicketsLost == playersPerTeam || bowllingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->WicketsLost << " (" << bowllingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowllingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings
            if(battingTeam->totalRunsScored > bowllingTeam->totalRunsScored){
                cout << battingTeam->name << "WON THE MATCH" << endl << endl;
                return false;
            }
            else if (battingTeam->WicketsLost == playersPerTeam || bowllingTeam-> totalBallsBowled == maxBalls)
             if (battingTeam->totalRunsScored < bowllingTeam->totalRunsScored) {

            	cout << bowllingTeam->name << " WON THE MATCH" << endl << endl;
            }
            else {

            	cout << "MATCH DRAW" << endl << endl;
            }
            return false;
        }
            return true;
    }


void Game::showScoreCard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->WicketsLost << " (" << bowllingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}

void Game::showMatchSummary(){

        cout << "********************************************************************" << endl;

        cout << "\t\t\t ||| MATCH END |||" << endl << endl;

        cout << "********************************************************************" << endl;

        cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->WicketsLost << "(" << bowllingTeam->totalBallsBowled << ")" << endl;


        cout <<"======================================================================" << endl;

        cout << "                          | PLAYER \t BATTING \t BOWLLING |"                                        <<endl;

    for(int j= 0 ; j < playersPerTeam ; j++){
        Player player = battingTeam->players[j];
        cout << "---------------------------------------------------------------------- " << endl;

        cout <<  "\t\t\t" << "[" << j << "]" << player.name << " \t" ;

        cout << player.runsScored << "(" << player.ballsPlayed << ")\t\t";
        cout << player.ballsBowled << "-" << player.runsGiven << "-";
        cout << player.wicketsTaken << "\t |" << endl;
    }
        cout <<" ======================================================================" << endl << endl;


        cout << bowllingTeam->name << " " << bowllingTeam->totalRunsScored << "-" << bowllingTeam->WicketsLost << "(" << battingTeam->totalBallsBowled << ")" << endl;

        cout <<"======================================================================" << endl;

        cout << "                          | PLAYER \t BATTING \t BOWLLING |"                                        <<endl;

    for(int i= 0 ; i < playersPerTeam ; i++){
        Player player = bowllingTeam->players[i];
        cout << "---------------------------------------------------------------------- " << endl;
        cout <<  "\t\t\t" << "[" << i << "]" << player.name << " \t" ;
        cout << player.runsScored << "(" << player.ballsPlayed << ")\t\t";
        cout << player.ballsBowled << "-" << player.runsGiven << "-";
        cout << player.wicketsTaken << "\t |" << endl;
    }
        cout <<" ======================================================================" << endl;

}


