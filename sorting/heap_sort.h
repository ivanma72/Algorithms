#include <iostream>
#include <vector>

class Heap{

public:

	std::vector <int> array;

	//sort the heap O(nlog(n))
	void heap_sort();

private:

	//helper function to make fix heap invariant for subtree starting
	//at 'index'
	//O(log(n))
	void heapify(uint i, uint size);


	//create a heap from vector of ints
	//O(n)
	void build_heap();
};