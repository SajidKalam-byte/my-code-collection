/*HOW TO PLAY
 ->EACH GRID STARTS WITH A NUMBER
 FROM 1-9.
 ->INSERT THE NUMBER ACCODING TO THE GRID REGARDING
 YOUR PLAYER TAG
 *AFTER A SUCCESSFUL WIN IT RECORDS SCORE
 TO A .TXT FILE */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <limits>
using namespace std;
void check();
void player1();
void player2();
void show();
void score();
char t[3][3];
int win = 0, moves = 0;
char point;
void reset() {
	win=0;
	moves=0;
}
void start() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t[i][j] = ' ';
		}
	}
	while (win == 0 && moves < 9) {
		show();
		if (moves % 2 == 0) {
			player1();
		} else {
			player2();
		}
	}
	if (win == 0) {
		cout << "\n Game Draw \n";
	}
}

void score(char points) {

	cout<<endl<<endl<<"_~_~_~_Updating score_~_~_~_"<<endl<<endl;
	ofstream obj("score.txt",ios::app);
	obj<<points;
	obj.close();

	fstream file("score.txt");
	if(!file.is_open()) {
		cerr<<"*****Error showing scores*****"<<endl;
	}
	char c;
	int p1=0,p2=0;
	while(file.get(c)) {
		if(c=='1')
			p1++;
		if(c=='0')
			p2++;
	}
	cout<<">>>>>>Player 1 score=  "<<p1<<endl;
	cout<<">>>>>>Player 2 score=  "<<p2<<endl;
	file.close();
}

void player1() {
	int pos;
	while(true) {

		cout << "\n\n";
		cout << "Player 1 'O' \n";
		cout << "Enter the position \n";
		if(cin >> pos) {

			if (pos >= 1 && pos <= 9) {
				int row = (pos - 1) / 3;
				int col = (pos - 1) % 3;
				if (t[row][col] == ' ') {
					t[row][col] = 'O';
					moves++;

				} else {
					cout << "\n Position already filled, try again. \n";
					player1();
					moves--;
				}
			} else {
				cout << "\n Wrong input \n";
				player1();
				moves--;
			}
			show();
			check();
			break;
		} else
			cout << pos << " is not a digit between 1 and 9."<<endl;
		cin.clear(); // Clear the fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
	}
}

void player2() {
	int pos;
	while(true) {

		cout << "\n\n";
		cout << "Player 2 'X' \n";
		cout << "Enter the position \n";
		if(cin >> pos) {
			if (pos >= 1 && pos <= 9) {
				int row = (pos - 1) / 3;
				int col = (pos - 1) % 3;
				if (t[row][col] == ' ') {
					t[row][col] = 'X';
					moves++;
				} else {
					cout << "\n Position already filled, try again. \n";
					player2();
					moves--;
				}
			} else {
				cout << "\n Wrong input \n";
				player2();
				moves--;
			}
			show();
			check();
			break;
		} else {
			cout << pos << " is not a digit between 1 and 9."<<endl;
			cin.clear(); // Clear the fail state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
		}
	}
}


void show() {
	system("cls"); // Clear the console screen
	cout << "\n\nTic Tac Toe\n";
	cout << "Version 3.0 \n";
	cout << "Player 1 (O) - Player 2 (X)\n\n";
	cout << "     |     |     \n";
	cout << "  " << t[0][0] << "  |  " << t[0][1] << "  | " << t[0][2] << " \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << t[1][0] << "  |  " << t[1][1] << "  | " << t[1][2] << " \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << t[2][0] << "  |  " << t[2][1] << "  | " << t[2][2] << " \n";
	cout << "     |     |     \n";
}
void check() {

// Check rows for a win
	int aa=0;
	for (int i = 0; i < 3; i++) {
		if (t[i][0] == t[i][1] && t[i][1] == t[i][2] && t[i][0] != ' ') {
			if (t[i][0] == 'O') {
				cout << "\n Player 1 wins! \n";
				point='1';
				score(point);
			} else {
				cout << "\n Player 2 wins! \n";
				point='0';
				score(point);
			}
			win = 1;
		}
	}
// Check columns for a win
	for (int j = 0; j < 3; j++) {
		if (t[0][j] == t[1][j] && t[1][j] == t[2][j] && t[0][j] != ' ') {
			if (t[0][j] == 'O') {
				cout << "\n Player 1 wins! \n";
				point='1';
				score(point);
			} else {
				cout << "\n Player 2 wins! \n";
				point='0';
				score(point);
			}
			win = 1;
		}
	}
// Check diagonals for a win
	if ((t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[0][0] != ' ') ||
	        (t[0][2] == t[1][1] && t[1][1] == t[2][0] && t[0][2] != ' ')) {
		if (t[1][1] == 'O') {
			cout << "\n Player 1 wins! \n";
			point='1';
			score(point);
		} else {
			cout << "\n Player 2 wins! \n";
			point='0';
			score(point);
		}
		win = 1;
	}
}
int main() {
	cout << "\n\nTic Tac Toe\n";
	cout << "Version 3.0 \n";
	do {
		bool game_over=false;
		char c;
		cout<<endl<<endl<<"Press any key to continue . . . "<<endl;
		cout<<"To EXIT press spacebar "<<endl;
		c=getch();
		if(c==' ')
			break;
		reset();
		start();
	} while(true);
	return 0;
}