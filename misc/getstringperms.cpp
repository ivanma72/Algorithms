#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getPerms(vector <string> & perms, string input){

	if(input.size() <= 1){
		perms.push_back(input);
		return;
	}

	//break down string into (0 to n - 1) and (n - 1 to n)
	string first_letters = input.substr(0, input.size() - 1);
	string last_letter = input.substr(input.size() - 1, string::npos);

	//recursive step --> do until we get to base case (first_letters.size() == 1)
	if(first_letters.length() != 1){
		getPerms(perms, first_letters);
	}

	//push back first letter
	if(perms.empty()){
		perms.push_back(first_letters);
	}

	//for every letter in perms, add last_letter to every position
	vector <string> new_perms;
	for(string s : perms){
		for(uint i = 0; i <= s.size(); ++i){
			string new_s = s;
			new_perms.push_back(new_s.insert(i, last_letter));
		}
	}

	//new_perms becomes perms
	perms = new_perms;
}


int main(){

	string test = "abc";
	vector <string> perms;

	getPerms(perms, test);

	for(string s : perms){
		cout << s << endl;
	}

	return 0;
}