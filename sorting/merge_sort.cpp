#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//O(n) runtime
void merge(int array[], int left, int right){

	int midpoint = (left + right) / 2;

	int sorted_size = right - left + 1;
	int merged[sorted_size];


	//Will iterate 'merged_size' times
	for(int i = left, j = midpoint + 1, k = 0; k < sorted_size; ++k){

		//if end of one array is hit, automatically go to 
		//next element in other array
		if(j > right){
			merged[k] = array[i++];
			continue;
		}

		if(i > midpoint){
			merged[k] = array[j++];
			continue;
		}

		if(array[i] <= array[j]){
			merged[k] = array[i++];
		} else if(array[j] < array[i]){
			merged[k] = array[j++];
		}
	}

	//copy values from merged to original array
	for(int i = left, j = 0; i <= right; ++i, ++j){
		array[i] = merged[j];
	}
}

void merge_sort(int array[], int left, int right){

	//base case: merge done if only 1 element
	if(right == left){
		return;
	}

	int midpoint = (left + right) / 2;

	merge_sort(array, left, midpoint);
	merge_sort(array, midpoint + 1, right);

	merge(array, left, right);
}

int main(){

	int array[6] = {5,3,5,2,1,0};

	merge_sort(array, 0, 5);

	for(int i : array){
		cout << i << endl;
	}

	return 0;
}