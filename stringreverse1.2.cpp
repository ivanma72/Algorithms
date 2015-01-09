#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str){

	if(str == nullptr){
		return;
	}

	int length = strlen(str);

	int left = 0;
	int right = length - 1;

	while(left < right){

		//swap
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;

		left++;
		right--;
	}
}

int main(){

	//char* test = "hello" <== NOTE: This is a string constant, which are placed into read-only
	//								 memory, so should never be modified.
	char test []= "qwertyuiop"; //allocates an array on the stack; can be modified freely

	reverse(test);

	cout << test << endl;

	return 0;
}