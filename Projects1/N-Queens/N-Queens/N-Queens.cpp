#include<iostream>
using namespace std;
int const size=4;

void PrintBoard(int board[][size], int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(board[i][j]==1){
			   cout<< "Q"<<"\t";
			}
			else{
			     cout<<"_"<< "\t";
			}
		}
		cout<<endl;
	}
}
bool toPlaceOrNotToPlace(int board[][size], int row, int col) {
		int i, j;
		for (i = 0; i < col; i++) {
			if (board[row][i] == 1)
				return false;
		}
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 1)
				return false;
		}
		for (i = row, j = col; j >= 0 && i < size; i++, j--) {
			if (board[i][j] == 1)
				return false;
		}
		return true;
	}
bool theBoardSolver(int board[][size], int col) {
		if (col >= size)
			return true;
		for (int i = 0; i < size; i++) {
			if (toPlaceOrNotToPlace(board, i, col)) {
				board[i][col] = 1;
				if (theBoardSolver(board, col + 1))
					return true;
				// Backtracking is hella important in this one.
				board[i][col] = 0;
			}
		}
		return false;
	}

int main(){
	/*scan = new Scanner(System.in);
		System.out.println("State the value of N in this program!");
		N = scan.nextInt();
		int[][] board = new int[N][N];
		if (!theBoardSolver(board, 0)) {
			System.out.println("Solution not found.");
		}
		printBoard(board);*/
	int board[size][size]={{0}};

	if (!theBoardSolver(board, 0)) {
			cout<<"No solution possible for N queens!"<<endl;
		}
	else{
		PrintBoard(board, size);
	}

return 0;
}