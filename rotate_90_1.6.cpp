#include <iostream>

using namespace std;

template <size_t row, size_t col>
void rotate(int (&array)[row][col], int size){

	if(size < 2){
		return;
	}

	int end_idx = size / 2;

	for(int i = 0; i < end_idx; ++i){

		for(int j = i; j < size - 1 - i; ++j){
			
			int temp = array[i][j];

			//set quadrant 1 = quadrant 4
			array[i][j] = array[size - 1 - j][i];

			//set quadrant 4 = quadrant 3
			array[size - 1 - j][i] = array[size - 1 - i][size - 1 - j];

			//set quadrant 3 = quadrant 2
			array[size - 1 - i][size - 1 - j] = array[j][size - 1 - i];

			//set quadrant 2 to temp
			array[j][size - 1 - i] = temp;
		}
	}
}

template <size_t row, size_t col>
void printMatrix(int (&mat)[row][col], int size){
	
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){

	int array[4][4];
	int count = 0;
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			array[i][j] = count++;
		}
	}

	//Print the original matrix
	printMatrix(array, 4);

	//Rotate 90 degrees
	rotate(array, 4);
	
	//Print rotated matrix
	cout << "#######################" << endl;
	printMatrix(array, 4);

	return 0;
}