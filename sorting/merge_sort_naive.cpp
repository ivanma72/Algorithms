#include <iostream>
#include <vector>

using namespace std;

//O(n) runtime
vector<int> merge(vector <int> & a, vector <int> & b){

	vector <int> merged(a.size() + b.size());

	//Will iterate 'merged_size' times
	for(uint i = 0, j = 0, k = 0; k < (a.size() + b.size()); ++k){

		//if end of one array is hit, automatically go to 
		//next element in other array
		if(j == b.size()){
			merged[k] = a[i++];
			continue;
		}

		if(i == a.size()){
			merged[k] = b[j++];
			continue;
		}

		if(a[i] <= b[j]){
			merged[k] = a[i++];
		} else if(b[j] < a[i]){
			merged[k] = b[j++];
		}
	}

	return merged;
}

vector <int> merge_sort(vector <int> & array, int left, int right){

	if(right == left){
		vector <int> elt = {array[left]};
		return elt;
	}

	int midpoint = (left + right) / 2;

	vector <int> left_array = merge_sort(array, left, midpoint);
	vector <int> right_array = merge_sort(array, midpoint + 1, right);

	return merge(left_array, right_array);
}

int main(){

	vector <int> array = {5,3,1,5,1,7,44,123,0,0,0,0,1,1,1,2,4,6};

	vector <int> sorted = merge_sort(array, 0, array.size() - 1);

	for(int i : sorted){
		cout << i << endl;
	}

	return 0;
}