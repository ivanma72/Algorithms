#include <iostream>

using namespace std;

void quick_sort(int array[], int left, int right){

	int size = right - left + 1;

	if(size <= 1){
		return;
	}

	//make a guess for the pivot value
	//in this case, pivot = midpoint
	int pivot = (left + right) / 2;

	//use l and r as temp variables for left and right
	//left and right need to be preserved to use later when
	//calling quicksort recursively
	int l = left, r = right;

	//keep scanning until l and r meet
	while(l <= r){

		//keep scanning lhs until you find a value larger
		//than pivot or hit the pivot element
		while(l < pivot && array[l] <= array[pivot]){
			l++;
		}

		//keep scanning rhs until you find a value smaller
		//than pivot or hit the pivot element
		while(r > pivot && array[r] >= array[pivot]){
			r--;
		}

		//we want l and r to cross eventually so that we know
		//where we can safely partition and call quick_sort() again
		if(l <= r){

			//swap right and left only if they are different
			if(l != r){
				int temp = array[r];
				array[r] = array[l];
				array[l] = temp;		
			}
			l++;
			r--;
		}
	}

	//make sure we still have elements to sort
	if(r > left){
		quick_sort(array, left, r);
	}

	if(l < right){
		quick_sort(array, l, right);	
	}

}


int main(){

	int array[5] = {10,3,5,2,90};

	quick_sort(array, 0, 4);

	for(uint i = 0; i < 5; ++i){
		cout << array[i] << endl;
	}

	return 0;
}