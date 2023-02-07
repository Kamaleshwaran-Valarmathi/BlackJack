#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	srand(time(NULL));

	vector<string> v = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "K", "Q", "A"};
	string prediction;
	int n = 0;
	cout << left << setw(5) << "No." << setw(10) << "Player" << setw(10) << "Dealer" << setw(14) << "Prediction" << endl;
	cout << "--------------------------------------" << endl;
	bool flag = true;
	while (true) {
		cout << setw(5) << ++n;
		if (flag) {
			cout << setw(10) << v[(rand() % 12)] + " " + v[(rand() % 12)];	// Hard
		} else {
			cout << setw(10) << ("A " + v[(rand() % 8)]);	// Soft
		}
		// cout << setw(10) << v[(rand() % 13)] + " " + v[(rand() % 13)];	// Both
		cout << setw(10) << v[(rand() % 13)];
		cin >> prediction;
		flag ^= true;
	}
}
