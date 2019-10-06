/*
	
	Chapter 1 Question 2
	Check if one string is permutation of other one

*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void checkStringsPermutation(string input1, string input2){
	// Make sure 2 strings are the same length
	if(input1.length() != input2.length()){
		cout << "Not Permutation";
		return;
	}
	
	unordered_map<char, bool> map;
	
	for(int i = 0; i < input1.length(); i++){
		map[input1[i]] = true;
	}

	for(int i = 0; i < input2.length(); i++){
		if(map.find(input2[i]) == map.end()){
			cout << "Not Permutation";
			return;
		}
	}

	cout << "Permutation";
	return;
}

int main(){
	checkStringsPermutation(" zgb", " zbg");

	cout << "\n";
	return 0;
}