/*
	
	Chapter 1 Question 6
	String compression

*/

let string = "aabcccccaaa";

// O(n) solution where n => input.length
function compressString(input){
	let compressed = "";
	let count = 1;
	for(let i = 1; i < input.length; i++){
		if(input[i] == input[i-1]){
			count++;
		}else{
			compressed += input[i-1] + count;
			count = 1;
		}
	}
	// Add last pair
	compressed += input[input.length - 1] + count;
	// Check compressed string length
	return compressed.length > input.length ? input : compressed;
}

// Test
console.log(compressString(string));