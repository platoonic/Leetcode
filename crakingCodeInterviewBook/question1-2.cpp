/*
	
	Chapter 1 Question 2
	Check if one string is permutation of other one

*/

#include <iostream>
#include <unordered_map>

using namespace std;

bool checkStringsPermutation(string input1, string input2){
	// If strings are different in length then they're not perm. of each other
	if(input1.length() != input2.length()){
		return false;
	}
	
	unordered_map<char, bool> map;
	
	for(int i = 0; i < input1.length(); i++){
		map[input1[i]] = true;
	}

	for(int i = 0; i < input2.length(); i++){
		if(map.find(input2[i]) == map.end()){
			return false;
		}
	}

	return true;
}

int main(){
	if(checkStringsPermutation("zsz", "zzs"))
		cout << "Permutation";
	else
		cout << "Not Permutation";

	cout << "\n";
	return 0;
}