#include <iostream>

using namespace std;

// function to draw the tic tac toe board
void drawBoard(char board[9]) {
	printf("\033c");
	for ( int i = 0 ; i < 9 ; i++ ) {
		if (i % 3 == 0) {
			cout << "\t\t\t\t";
		}
		cout << board[i];
		if (i % 3 != 2) {
			cout << " | ";
		} else if (i < 8) {
			cout << "\n\t\t\t\t---------\n";
		} else {
			cout << endl;
		}
	}
	cout << endl;
}

// function to check if the game has been won
bool checkWin(char board[9], char player) {
	for ( int i = 0 ; i < 3 ; i++ ) {
		if (board[i] == player && board[i+3] == player && board[i+6] == player) {
			return true;
		} 
		if (board[3*i] == player && board[3*i+1] == player && board[3*i+2] == player) {
			return true;
		}
	}

	if (board[0] == player && board[4] == player && board[8] == player) {
		return true;
	}
	if (board[2] == player && board[4] == player && board[6] == player) {
		return true;
	}
	return false;
}

// main function 
int main() {
	char board[9] = { 
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9'
	};
	char currentPlayer = 'X';
	int choice;

	cout << "Welcome to 2-Player Tic Tac Toe!" << endl;

	while (true) {
		drawBoard(board);

		// get the players move
		cout << "Player " << currentPlayer << ", enter the number of block you want to place your character in: ";
		cin >> choice;

		if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
			cout << "Invalid move, Try again." << endl;
			continue;
		}

		// update the board with the player's move
		board[choice - 1] = currentPlayer;

		// check if the currrent player has won
		if (checkWin(board, currentPlayer)) {
			drawBoard(board);
			cout << "Player " << currentPlayer << " wins!! Congratulations!" << endl;
			break;
		}

		// check for draw 
		bool boardFull = true;
		for ( int i = 0 ; i < 9 ; i++  ) {
			if (board[i] != 'X' && board[i] != 'O') {
				boardFull = false;
				break;
			}
		}

		if (boardFull) {
			drawBoard(board);
			cout << "It's a draw! the game is over." << endl;
			break;
		}

		// Switch to the other player
		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}

	return 0;
}
