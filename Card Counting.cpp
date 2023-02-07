#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

// Insurance (% Player Advantage):
// +0.12 -> For Single Deck Game
// +0.035 -> For 4 Deck Game

// Index 0 -> 10s, 1 -> A, 2 to 9 -> 2 to 9
vector<int> HiOpt1 = {-1, 0, 0, 1, 1, 1, 1, 0, 0, 0};
vector<int> HiOpt2 = {-2, 0, 1, 1, 2, 2, 1, 1, 0, 0};

char c, yOrn;
float noOfDeck, BSE, tableMin, bankroll, curWin;
float runningCount, remCardsInShoe, aceCount;
float combRunningCount, trueCount, playerAdvantage;
bool flag = true;

void setColor(int colorID) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void print() {
	cout << "\n\nHow much do you win? ";
	cin >> curWin;
	bankroll += curWin;
	system("clear");
	cout << std::left << setw(15) << "Running_Count" << setw(15) << "True_Count" << "Player_Advantage" << endl;
	cout << "----------------------------------------------" << endl;
	cout << fixed << setprecision(2) << std::left << setw(15) << combRunningCount << setw(15) << trueCount << playerAdvantage << endl << endl;

	setColor(10);
	cout << "BET: " << (tableMin + ((playerAdvantage > 0) ? round(playerAdvantage * ((bankroll - tableMin) / 100)) : 0)) << endl;
	if ((noOfDeck == 1 && trueCount >= 2) || (noOfDeck > 1 && trueCount >= 3))
		cout << "Take Insurance" << endl;
	setColor(7);
	flag = true;
}

int main(void) {
	cout << "Enter the no. of Decks: ";
	cin >> noOfDeck;
	cout << "Enter the Basic Strategy Expectation (BSE): ";
	cin >> BSE;
	cout << "Enter the Table Minimum (Bet): ";
	cin >> tableMin;
	cout << "Enter Your Bankroll: ";
	cin >> bankroll;
	runningCount = 0, remCardsInShoe = 52 * noOfDeck, aceCount = 4 * noOfDeck;

	while (true) {
		if (kbhit()) {
			c = getch();

			// To do the calculations and tells the final results
			if (c == 13) {	// ASCII: enter -> 13
				combRunningCount = runningCount + (aceCount - ceil(remCardsInShoe / 13));
				trueCount = combRunningCount / (remCardsInShoe / 52);
				playerAdvantage = BSE + 0.515 * trueCount;
				print();
				continue;
			}

			// To reset the values
			if (c == 'r') {
				cout << "\nDo you want to reset (y/n): ";
				cin >> yOrn;
				if (yOrn == 'y') {
					runningCount = 0, remCardsInShoe = 52 * noOfDeck, aceCount = 4 * noOfDeck;
					system("clear");
					cout << "Reset Successful" << endl << endl;
				}
				continue;
			}

			// For HiOpt1 and HiOpt2 (use numpad)
			if (c >= '0' && c <= '9') {
				(c == '1') ? --aceCount : (runningCount += HiOpt2[c - '0']);
				--remCardsInShoe;
				if (c == '1')	cout << "A ";
				else if (c == '0')	cout << "10 ";
				else	cout << c << " ";
			}
		}
		if (flag) {
			cout << "\nEnter the Current Hand's Cards: ";
			flag = false;
		}
	}
}
