#include "game.h"
using namespace std;

Game::Game( ) {
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10]="Ishant";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}
void Game::Welcome( ){

	        cout << "Hello Everyone!  \n\nWelcome to Virtual Cricket Game"<<endl;
	        cout <<"\nlet us go through the instructions"<<endl;
	        cout << "\nFirst about Teams:" << endl;
	        cout << "\nEach team consists of four players." << endl;
	        cout << "\nThere are two teams competing against each other." << endl;
	        cout << "\nNext about Innings:" << endl;
	        cout << "\nThere will be two innings to bat and two innings to bowl." << endl;
	        cout << "\nAn inning consists of 6 balls (overs)." << endl;
	        cout << "\nThen about Batting:" <<endl;
	        cout << "\nTwo players from the batting team will be at the crease (on the field) at any given time." << endl;
	        cout << "\nBatsmen try to score runs by hitting the ball and running between the wickets. They can also hit boundaries (4 runs) or sixes (6 runs) by hitting the ball beyond the field boundary." << endl;
	        cout << "\nIf a batsman is dismissed (e.g., bowled, caught, run out), they will be replaced by the next batsman in the batting order." << endl;
	        cout << "\nAbout Bowling:" << endl;
	        cout << "\nEach over consists of 6 balls, which will be bowled by a single bowler." << endl;
	        cout << "\nBowlers try to dismiss batsmen and restrict the number of runs scored by the batting team." << endl;
	        cout << "\nA different player from the bowling team can bowl each over." << endl;
}
void Game :: showAllPlayers(){
    cout << "List of Players:" << endl;
    for (int i = 0; i < 11; ++i) {
        cout << "[" << i << "] " << players[i] << endl;
    }
}
    int Game::takeIntegerInput() {

    	int n;

    	while (!(cin >> n)) {

    		cin.clear();
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		cout << "Invalid input! Please try again with valid input: ";
    	}
    	  return n;
}
    void Game::selectPlayers() {
        cout << "Select the players of your own wish" << endl;
        cout << "Create Team-A and Team-B" << endl;

        for (int i = 0; i < playersPerTeam; i++) {
            teamASelection:
            cout << endl << "Select player " << i + 1 << " of Team A - ";
            int playerIndexTeamA = takeIntegerInput();

            if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
                cout << "Invalid player number. Please select from the given players." << endl;
                goto teamASelection;
            } else {
                for (const Player &player : teamB.players) {
                    if (player.id == playerIndexTeamA) {
                        cout << "Player " << playerIndexTeamA << " is already added to Team B. Please select another player." << endl;
                        goto teamASelection;
                    }
                }

                Player teamAPlayer;
                teamAPlayer.id = playerIndexTeamA;
                teamAPlayer.name = players[playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);
            }

            teamBSelection:
            cout << endl << "Select player " << i + 1 << " of Team B - ";
            int playerIndexTeamB = takeIntegerInput();

            if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
                cout << "Invalid player number. Please select from the given players." << endl;
                goto teamBSelection;
            } else {
                for (const Player &player : teamA.players) {
                    if (player.id == playerIndexTeamB) {
                        cout << "Player " << playerIndexTeamB << " is already added to Team A. Please select another player." << endl;
                        goto teamBSelection;
                    }
                }

                Player teamBPlayer;
                teamBPlayer.id = playerIndexTeamB;
                teamBPlayer.name = players[playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
            }
        }
    }
    void Game::showTeamPlayers() {
        cout << "Team-A\t\t\t\t\tTeam-B" << endl;
        for (int i = 0; i < playersPerTeam; ++i) {
            cout << "[" << i +1<< "]" << "\t" << teamA.players[i].name << "\t\t\t\t[" << i+1<< "]" << "\t" << teamB.players[i].name << endl;
        }
    }
void Game::toss(){
	 cout << "Tossing the coin..." << endl;
	        srand(time(NULL));

	        int tossResult = rand() % 2;

	        cout << "Toss result: ";
	        switch (tossResult) {
	            case 0:
	                cout << endl<<"Team-A won the toss!" << endl;
	                tossChoice(teamA);
	                break;
	            case 1:
	                cout << endl<<"Team-B won the toss!" << endl;
	                tossChoice(teamB);
	                break;
	        }
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
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


	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
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

	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;
	   if (runsScored != 0) {
	    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
	    	showGameScorecard();
	    } else {
	    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

	    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
	    	bowler->wicketsTaken = bowler->wicketsTaken + 1;
	    	showGameScorecard();
	    	int nextPlayerIndex = battingTeam->wicketsLost;
	    	batsman = &battingTeam->players[nextPlayerIndex];

	    }
	}

	bool Game::validateInningsScore() {

		if (isFirstInnings) {

			if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
				cout<<endl;
				showGameScorecard();
				cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

				cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
						<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
						<< ")" << endl;

				cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
						<< " runs to win the match" << endl << endl;
				cout<<endl;
				return false;
			}

		} else {if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls || battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
		    cout << endl;
		    showGameScorecard();
		    cout << "\t\t ||| MATCH ENDS ||| " << endl << endl;

		    if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
		        cout << battingTeam->name << " wins the match by " << battingTeam->totalRunsScored - bowlingTeam->totalRunsScored << " runs" << endl;
		    } else {
		        cout << bowlingTeam->name << " wins the match by " << playersPerTeam - battingTeam->wicketsLost << " wickets" << endl;
		    }

		    cout << endl;
		    return false;
		}
    }
		return true;

	}
	void Game::showGameScorecard() {
		 cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
		         << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") ["
		         << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ")]\t"
		         << bowler->name << " " << bowler->ballsBowled << " - " << bowler->runsGiven
		         << " - " << bowler->wicketsTaken << endl;
	}

	void Game::startSecondInnings() {
	    cout << "\n\t\t ||| SECOND INNINGS STARTS ||| " << endl << endl;

	    isFirstInnings = false;


	    Team *temp = battingTeam;
	    battingTeam = bowlingTeam;
	    bowlingTeam = temp;

	    initializePlayers();
	    playInnings();
	    endGame();
	}

	void Game::displayMatchSummary() {
	    cout << "\n\t\t ||| MATCH SUMMARY ||| " << endl << endl;

	    if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
	        cout << battingTeam->name << " wins the match by " << battingTeam->totalRunsScored - bowlingTeam->totalRunsScored << " runs" << endl;
	    } else {
	        cout << bowlingTeam->name << " wins the match by " << playersPerTeam - battingTeam->wicketsLost << " wickets" << endl;
	    }

	    cout << endl;

	    cout << "Batting Team: " << battingTeam->name << " - " << battingTeam->totalRunsScored << " runs for " << battingTeam->wicketsLost << " wickets (" << bowlingTeam->totalBallsBowled << " balls)" << endl;
	    for (const Player& player : battingTeam->players) {
	        cout << player.name << ": " << player.runsScored << " runs (" << player.ballsPlayed << " balls)" << endl;
	    }

	    cout << "\nBowling Team: " << bowlingTeam->name << endl;
	    for (const Player& player : bowlingTeam->players) {
	        cout << player.name << ": " << player.ballsBowled << " balls, " << player.runsGiven << " runs, " << player.wicketsTaken << " wickets" << endl;
	    }
	}

	void Game::endGame() {
	    cout << "\n\t\t ||| MATCH ENDS ||| " << endl << endl;
	    displayMatchSummary();
	}
