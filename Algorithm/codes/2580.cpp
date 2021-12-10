#include <iostream>
using namespace std;

int zeroCnt = 0;

int sudokuBoard[9][9] = { 0, };

void printAns() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << sudokuBoard[i][j] << " ";
		cout << endl;
	}
}

bool isCool(int row, int col) {
	int sectionRow = row / 3;
	int sectionCol = col / 3;

	for (int i = 0; i < 9; i++) {
		if (i != col && sudokuBoard[row][i] == sudokuBoard[row][col]) return false;
		if (i != row && sudokuBoard[i][col] == sudokuBoard[row][col]) return false;
	}

	for (int i = sectionRow * 3; i < sectionRow * 3 + 3; i++)
		for (int j = sectionCol * 3; j < sectionCol * 3 + 3; j++)
			if ((i != row && j != col) && sudokuBoard[i][j] == sudokuBoard[row][col]) return false;

	return true;
}

bool sudoku(int order) {
	if (order > zeroCnt) {
		printAns();
		return true;
	}

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (sudokuBoard[row][col] == 0) {
				for (int k = 1; k <= 9; k++) {
					sudokuBoard[row][col] = k;
					if (isCool(row, col))
						if (sudoku(order + 1))
							return true;
					sudokuBoard[row][col] = 0;
				}
				return false;
			}
		}
	}
}

int main() {
	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) zeroCnt++;
			sudokuBoard[i][j] = temp;
		}
	sudoku(1);
}
