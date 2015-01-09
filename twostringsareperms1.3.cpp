#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

bool is_permutation(char* string_a, char* string_b){

	int size_a = strlen(string_a), size_b = strlen(string_b);

	if(size_a != size_b){
		return false;
	}

	unordered_map <char, int> char_map;

	//keep track of how many characters string_a uses
	for(int i = 0; i < size_a; ++i){
		char_map[*(string_a + i)] += 1;
	}

	//iterate through string_b, if character count in map
	//for any character is 0, return false (is not permutation)
	//return true if for loop finishes
	for(int i = 0; i < size_b; ++i){
		
		if(char_map[*(string_b + i)] == 0){
			return false;
		}

		char_map[*(string_b + i)] -= 1;
	}

	return true;
}


int main(){

	char* string_a = (char*)"hello";

	char* string_b = (char*)"hellb";

	cout << is_permutation(string_a, string_b) << endl;

	return 0;
}