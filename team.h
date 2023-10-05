#include"player.h"
#include<vector>
class Team{

public:
	Team();
	std::string name;
	int totalRunsScored;
	int totalBallsBowled;
	int WicketsLost;
	std::vector<Player>players;


};
