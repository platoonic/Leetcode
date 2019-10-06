/*
	
	Chapter 1 Question 3
	URLify

*/

#include <iostream>

using namespace std;

void URLify(string input, int length){
	int appendIndex = input.length() - 1;
	for(int i = length - 1; i >= 0; i--){
		if(input[i] != ' '){
			input[appendIndex] = input[i];
			appendIndex--;
		}else{
			input[appendIndex] = '0';
			input[appendIndex-1] = '2';
			input[appendIndex-2] = '%';
			appendIndex -= 3;
		}
	}
	cout << input;
}

int main(){
	URLify("Mr John Smith    ", 13); // Mr%20John%20Smith
	cout << "\n";
	return 0;
}