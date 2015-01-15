#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//Takes in a string and len of that string and modifies 'str'
//to contain the same string with spaces replaced by "%20"
//NOTE: assumes that we are given string of enough length
//to incorporate all "%20"s
void add_amp_twenty(char* str, int len);

//Shift part of the string str designated by space_idx and end_idx "shift_num"
//positions to the right
void shift_str(char* str, int space_idx, int end_idx, int shift_num);


int main(){

	char test [100] = "    ";

	add_amp_twenty(test, strlen(test));
	cout << test << endl;

	return 0;
}


void add_amp_twenty(char* str, int len){
	
	//find every space in string and add to vector
	vector <int> spaces;
	for(int i = 0; i < len; ++i){
		
		if(str[i] == ' '){
			spaces.push_back(i);
		}
	}

	//corner case: last character is space
	if(spaces.back() == (len - 1)){
		str[len - 1] = '%';
		str[len] = '2';
		str[len + 1] = '0';
		str[len + 2] = '\0'; //don't forget null character

		spaces.pop_back();
		len += 2;
	}

	//last word will shift by (2 * size of spaces vector)
	int shift_num = 2 * spaces.size();
	int prev_space = len;

	//shift every word after given space to new location
	for(int i = spaces.size() - 1; i >= 0; --i){
		shift_str(str, spaces[i], prev_space - 1, shift_num);
		prev_space = spaces[i];
		spaces[i] = spaces[i] + shift_num - 2; //don't forget to move the space (word also shifted)
		shift_num -= 2;
	}
	

	//iterate through new spaces string, fill in "holes" with "%20"
	for(int i : spaces){
		str[i] = '%';
		str[i + 1] = '2';
		str[i + 2] = '0';
	}
}

void shift_str(char* str, int space_idx, int end_idx, int shift_num){

	for(int i = end_idx; i >= (space_idx + 1); --i){
		str[i + shift_num] = str[i];
	}
}