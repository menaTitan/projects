/*
Name:Mena Sergeyous
Date:11/3/2015
*/


#include<iostream>
using namespace std;
int const rows = 10;// global variable
int const  columns = 3;// global variable

// print Preorder
void Preoder(int a[][columns], int root) {
	//checks if the root if not negtive one and print the root
	if (root != -1) {
		cout << root << " ";
	}
	// goes through the columns 
	for (int i = 0; i < columns; i++) {
		
		if (root != -1) {
			// recrsive call that  returns root
			Preoder(a, a[root - 1][i]);
		}
	}
}

// print postorder
void postorder(int a[][columns], int root) {
	// goes through the columns in the array 
	for (int i = 0; i < columns; i++) {
		 //checks item inside the array
		if (a[root - 1][i] != -1) {
			// recrive call that return item inside the array has root
			postorder(a, a[root - 1][i]);
		}
	}
	if (root != -1) {
	// print the root
		cout << root << " ";
	}

}

// print  inorder
void  inorder(int a[][3], int root) {
	// checks the item inside the array if not equal to negtive one 
	if (a[root-1][0] != -1) {
		// recrsive call that return the left child
		inorder(a, a[root-1][0]);
	}
	// checks if the root is not negtive one 
	if (root != -1) {
		// print out the root
		cout << root << " ";

	}
	//goes  through the array columns 
	for (int i = 1; i < columns; i++) {
		if (a[root - 1][i] != -1) {

			inorder(a, a[root-1][i]);
		}
	}



}

// Print array Representation
void arrayRepresentation(int a[][columns], int node) {

	cout << "The left child, middle child, right child array representation is" << endl;
	// print out the array Representation by double loop one for row and one for columns
	for (int r = 0; r < node; r++) {
		for (int c = 0; c < columns; c++) {
			cout << a[r][c];
			cout << " ";
		}

		cout << endl;
	}


}

void printAdjacencyMatrix(int a[][columns], int node) {


	// print Adjency matrix
	int temp1;
	int temp2;
	int temp3;
	cout << "The adjacency matrix is: " << endl;
	for (int r = 0; r < node; r++) {
		for (int c = 0; c < node; c++) {
			temp1 = a[r][0] - 1;
			temp2 = a[r][1] - 1;
			temp3 = a[r][2] - 1;
			//checks if the index equal the item in the array
			if (temp1 == c || temp2 == c || temp3 == c) {

				cout << 1 <<" ";
			}
			else {
				cout << 0 <<" ";
			}
		}

		cout << endl;
	}
}

int main() {
	// declaring variable
	int Darray[rows][columns] = { { 0 } };
	cout << "Plase enter the array" << endl;
	int row;
	cin >> row;
	// put value into the array
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < columns; c++)
			cin >> Darray[r][c];
	}


	cout << endl;
	// call print AdjecncyMatrix 
	printAdjacencyMatrix(Darray, row);
	cout << endl;
	// call arrayRepresentation
	arrayRepresentation(Darray, row);
	cout << endl;
	cout << "The preorder traversal is: " << endl;
	// call preoder
	Preoder(Darray, 1);
	cout << "\n" << endl;
	cout << "The Inorder traversal is:" << endl;
	// call inorder
	inorder(Darray, 1);
	cout << "\n"<<endl;
	cout << "The postorder traversal is: " << endl;
	// call postorder
	postorder(Darray, 1);
	cout <<"\n" <<endl;
	return 0;

}