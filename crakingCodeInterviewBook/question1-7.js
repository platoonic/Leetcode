/*
	
	Chapter 1 Question 7
	Rotate Matrix

*/

let input = [
	[3, 4, 5],
	[8, 6, 9],
	[7, 1, 2]
];

// O(n^2) using extra array
function rotateMatrix(input){
	let output = [[], [], []];
	let x = 0;
	let y = 0;
	for(let j = 0; j < input.length; j++){
		for(let i = input.length - 1; i >= 0; i--){
			output[x][y] = input[i][j];
			y++;
		}
		y = 0;
		x++;
	}
	return output;
}

console.log(rotateMatrix(input));