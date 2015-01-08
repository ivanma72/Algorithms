#include <iostream>
#include "heap_sort.h"

using namespace std;

void Heap::heap_sort(){

	//already sorted
	if(array.size() <= 1){
		return;
	}

	build_heap();

	//sort in place by swapping n...1 with top elt in heap and then calling heapify
	//on the 0th elt array
	for(int to_sort = array.size() - 1; to_sort > 0; --to_sort){
		int temp = array[0];
		array[0] = array[to_sort];
		array[to_sort] = temp;

		//to_sort decrements every iteration so as not to mess with
		//already sorted array
		heapify(0, to_sort);
	}
}

void Heap::heapify(uint i, uint size){
	uint max = i;
	uint left = (2 * i) + 1;
	uint right = (2 * i) + 2;

	if(left < size && array[left] > array[max]){
		max = left;
	}

	if(right < size && array[right] > array[max]){
		max = right;
	}

	if(max != i){
		int temp = array[i];
		array[i] = array[max];
		array[max] = temp;

		//we might have broken invariant in lower subtree
		//so call heapify() again
		heapify(max, size);
	}
}

void Heap::build_heap(){
	
	for(uint i = (array.size() - 1) / 2; i >= 0; --i){
		heapify(i, array.size());

		if(i == 0){
			break;
		}
	}
}