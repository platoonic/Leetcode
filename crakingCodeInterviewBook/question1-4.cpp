/*
	
	Chapter 1 Question 4
	Palindrome Permutation

*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool palindromePermutation(string input){
	unordered_set<char> set;
	int uniqueCount   = 0;
	int repeatedCount = 0;
	for(int i = 0; i < input.length(); i++){
		if(input[i] != ' '){
			if(set.insert(tolower(input[i])).second){
				uniqueCount++;
			}else{
				set.erase(tolower(input[i]));
				repeatedCount++;
			}
		}
	}
	if(uniqueCount ==  repeatedCount || uniqueCount == repeatedCount + 1){
		return true;
	}

	return false;
}

int main(){
	if(palindromePermutation("carcar"))
		cout << "Valid";
	else
		cout << "Invalid";

	cout << "\n";
	return 0;
}