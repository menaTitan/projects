#include<iostream>
#define N 4
using namespace std;

/* print the chess_board after placing 'N' queens
'1' denotes the positions where queens are placed
*/
void printPlacement(int chess_board[N][N]) {
	int i, j;
	cout << "\nPlacement of N queens :-\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << chess_board[i][j] << " ";
		}
		cout << endl;
	}
}

/* ckeck if a queen can be placed on the chess_board at a specific cell
(r_idx,c_idx) so that it cannot be attacked by any of the other queens.
We only need to check whether queens placed in columns [0...c_idx-1] can
attack this cell or not.
*/
bool isCellSafe(int chess_board[N][N], int r_idx, int c_idx) {
	int i, j;

	for (i = 0; i < c_idx; i++) {
		// any queen placed cells (r_idx,0) to (r_idx..c_idx-1)
		// can attack this cell i.e. we are checking for queens
		// placed in the left of this cell
		if (chess_board[r_idx][i] == 1) {
			return false;
		}
	}

	i = r_idx; j = c_idx;
	while (i >= 0 && j >= 0) {
		// we are checking if any queen is placed in the
		// upper left diagonal
		if (chess_board[i][j] == 1) {
			return false;
		}
		i--; j--;
	}

	i = r_idx; j = c_idx;
	while (i < N && j >= 0) {
		// we are checking if any queen is placed in the
		// lower left diagonal
		if (chess_board[i][j] == 1) {
			return false;
		}
		i++; j--;
	}

	// queen can be placed in this cell (r_idx,c_idx)
	return true;
}

/* recursive function to solve the N Queens problem
Start placing the queens in each column starting from left
For each recursive call, find the row in which a queen can be
placed for a particular column
*/
bool placeNQueens(int chess_board[N][N], int c_idx) {
	if (c_idx >= N) {
		// all N queens are successfully placed on the chess board
		return true;
	}

	int i;
	// look for a feasible cell i.e find a row where a queen
	// can be placed for the current column
	// iterate over each row   
	for (i = 0; i < N; i++) {
		if (isCellSafe(chess_board, i, c_idx)) {
			// cell (i,c_idx) is safe, so place a queen here
			chess_board[i][c_idx] = 1;

			// recursively place other queens in each successive column
			if (placeNQueens(chess_board, c_idx + 1) == true)
				return true;

			// we cannot place the queen in this cell
			// backtrack and try for other possiblities
			chess_board[i][c_idx] = 0;
		}
	}

	// Solution to N queens problem doesn't exist 
	return false;
}


// main
int main() {
	int chess_board[N][N] = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } };
	bool n_queens_sol = placeNQueens(chess_board, 0);
	if (n_queens_sol == false) {
		cout << "\n N queens placement not possible";
	}
	else {
		cout << "\n N queens can be placed on NxN chessboard";
		printPlacement(chess_board);
	}
	cout << endl;
	return 0;
}