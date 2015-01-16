#include <iostream>
#include <string>

using namespace std;

string str_compression(string str);

void build_str(string str, string & new_str);


int main(){

	string s = "aaaaaaaabcdef";

	cout << str_compression(s) << endl;

	return 0;
}


string str_compression(string str){

	if(str.length() <= 2){
		return str;
	}

	char prev = str[0];
	uint unique_count = 1;

	//find # of unique chars in str
	for(uint i = 1; i < str.length(); ++i){
		if(str[i] != prev){
			unique_count++;
			prev = str[i];
		}
	}

	//if compressed str length is >= str.length(), just return str
	if((unique_count * 2) >= str.length()){
		return str;
	}

	//build new string
	string new_str;

	build_str(str, new_str);


	return new_str;
}

void build_str(string str, string & new_str){
	
	uint curr = 0, next = 1, rep = 1;

	while(next < str.length()){

		if(str[curr] == str[next]){
			rep++;
		} else{
			new_str += (str[curr] + to_string(rep));
			rep = 1;
		}

		//advance both pointers after each iteration
		curr++;
		next++;
	}

	//take care of last character
	new_str += (str[curr] + to_string(rep));
}