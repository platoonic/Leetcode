/*
	
	Chapter 1 Question 5
	One Array
	(NOT FINISHED)

*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool checkforSingleEdit(string input1, string input2) {
	int edits = 0;
	int lengthDifference = input1.length() - input2.length();
	lengthDifference = abs(lengthDifference);
	if(lengthDifference > 1){
		return false;
	}
	for(int i = 0; i < input1.length(); i++){
		if(input1[i] != input2[i]){
			edits++;
		}
	}

	if(edits <= 1){
		cout << edits << "\n";
		return true;
	}

	return false;
}

int main(){
	if(checkforSingleEdit("pale", ""))
		cout << "True";
	else
		cout << "False";

	cout << "\n";
	return 0;
}