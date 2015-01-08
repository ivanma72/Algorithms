#include <iostream>
#include <string>

using namespace std;

void selection_sort(int array[], uint size){

	if(size <= 1){
		return;
	}

	//iterate through every elt in array
	for(uint i = 0; i < size; ++i){

		//set temp min to starting index
		uint min = i;

		//find true min
		for(uint j = i + 1; j < size; ++j){
			if(array[j] < array[min]){
				min = j;
			}
		}

		//if min is still i, don't bother swapping
		if(min == i){
			continue;
		}

		uint min_val = array[min];
		array[min] = array[i];
		array[i] = min_val;
	}

}


int main(){

	int array[5] = {4,3,2,1,0};

	selection_sort(array, 5);

	for(int i = 0; i < 5; ++i){
		cout << array[i] << endl;
	}

	return 0;
}