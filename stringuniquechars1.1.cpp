#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

//using data structures
//NOTE: if map[key] returns an uninitialized value, it will init using type's default constructor
bool has_unique_chars_d(string input){
	unordered_map <char, int> word_map;


	if(input.size() <= 1){
		return true;
	}

	for(char c : input){
		word_map[c] += 1;
	}

	for(auto it = word_map.begin(); it != word_map.end(); ++it){
		
		if(it->second > 1){
			return false;
		}
	}

	return true;
}


//not using data structures
bool has_unique_chars(string input){
	
	if(input.size() <= 1){
		return true;
	}

	sort(input.begin(), input.end());

	for(uint i = 1; i < input.size(); ++i){
		if(input[i] == input[i - 1]){
			return false;
		}
	}

	return true;
}


//using a bit vector (uses 8x less space)
bool has_unique_chars_bv(string input){
	int bitvector = 0; //assume lowercase a-z

	for(char c : input){
		int idx = c - 'a'; //get index of word (0-25)

		//if bit vector already contains a 1 at idx
		if((bitvector & (1 << idx)) > 0){
			return false;
		}

		//set the bit at index idx to 1
		bitvector = bitvector | (1 << idx);
	}

	return true;
}


int main(){

	string test = "qwerty";

	bool result = has_unique_chars_bv(test);
	cout << result << endl;

	return 0;
}