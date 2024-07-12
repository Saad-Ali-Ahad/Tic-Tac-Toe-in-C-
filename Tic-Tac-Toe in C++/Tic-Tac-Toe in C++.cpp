#include <iostream>
using namespace std;
int a = 3;
const int ROWS = 3, COLS = 3;
char board[ROWS][COLS] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };
void printBoard() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << board[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------";
		cout << endl;
	}
}
bool checkwinner(char player) {
	// check rows
	for (int i = 0; i < ROWS; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
			return true;
		}
	}
	// check columns
	for (int i = 0; i < COLS; i++) {
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
			return true;
		}
	}
	// check diagonals
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}
	return false;
}
bool checkDraw() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (board[i][j] == '_') {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int row, col;
	char player = 'X';
	cout << "^^^^^^^^TIC TAC TOE GAME^^^^^^^\n";
	cout << "This game is based on 2d array manipulation.\nIf you want to play this game then first you need to \nenter the value of 'ROW' then enter the value of 'COLUMNS'	\n";
	cout << " 00|01|02\n";
	cout << " -- -- --\n";
	cout << " 10|11|12\n";
	cout << " -- -- --\n";
	cout << " 20|21|22\n";
	cout << "\n\t" << endl;
	printBoard();
	while (true) {
		cout << "Player " << player << ", enter row and column (0-2) for your move: \n";
		cin >> row >> col;
		if (row < 0 || row > 2 || col < 0 || col > 2) {
			cout << "Invalid move, try again." << endl;
			continue;
		}
		else if (board[row][col] != '_') {
			cout << "Cell already occupied, try again." << endl;
			continue;
		}
		board[row][col] = player;
		printBoard();
		if (checkwinner(player)) {
			cout << "Player " << player << " wins!" << endl;
			break;
		}
		else if (checkDraw()) {
			cout << "Its a draw!" << endl;
			break;
		}
		if (player == 'X') {
			player = 'O';
		}
		else {
			player = 'X';
		}
	}
