/*
	
	Chapter 1 Question 1
	Check if string has all unique characters

*/

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(){

	string input = "abcdefghjk";

	// Using Sets
	unordered_set<int> set;

	for(int i = 0; i < input.length(); i++){
		set.insert(input[i]);
	}

	if(set.size() == input.length())
		cout << "All Unique" << "\n";
	else
		cout << "Not Unique" << "\n";


	// Without using any data structure
	bool unique = true;
	
	// Sort string
	sort(input.begin(), input.end());

	// Iterate and search for neighbour duplicates
	for(int i = 1; i < input.length(); i++){
		if(input[i] == input[i-1]){
			unique = false;
			cout << "Not Unique";
			break;
		}
	}

	if(unique)
		cout << "All Unique";

	cout << "\n";
	return 0;
}






