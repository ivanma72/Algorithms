#include <iostream>
#include "heap_sort.h"

using namespace std;

int main(){

	Heap h;

	h.array = {1,2,3,4,5,6,4,2,1,4,6,7,9};

	h.heap_sort();


	for(int i : h.array){
		cout << i << endl;
	}

	return 0;
}