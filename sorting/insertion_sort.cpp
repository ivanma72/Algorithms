#include <iostream>
#include <string>

using namespace std;


void insertion_sort(int array[], int size){

	if(size <= 1){
		return;
	}

	//iterate through every index of array
	for(int i = 0; i < size - 1; ++i){
		
		//get next index
		int next = i + 1;
		int next_val = array[next];

		//use temp index for swapping, init to i
		int temp = i;
		//keep swapping until we found correct postion or hit beginning of array
		while(next > 0 && next_val < array[temp]){
			array[next] = array[temp];
			array[temp] = next_val;
			temp--;
			next--;
		}
	}
}


int main(){

	int array[5] = {4,3,2,1,0};

	insertion_sort(array, 5);

	for(int i = 0; i < 5; ++i){
		cout << array[i] << endl;
	}

	return 0;
}