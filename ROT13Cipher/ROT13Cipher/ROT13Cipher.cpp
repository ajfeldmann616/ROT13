// ROT13Cipher.cpp : Defines the entry point for the console application.
// Name: Allen Feldmann
// Date: 9/4/2017
// Class: CS-230
// Professor: Daniel Packer
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// encrypt is the method that takes a character read from a file and encrypts it using the ROT13 cipher
// parameter char c is the character that is being read from the input file
char encrypt(char c)
{
	// evaluates the ASCII decimal value of the character and runs the body if the character is a-m or A-M 
	if ((65 <= int(c) && int(c) <= 77) || (97 <= int(c) && int(c) <= 109)) {
		// increases the ASCII decimal value by 13, turning A to N and so on
		c = int(c) + 13;
	}
	// evaluates the ASCII decimal value of the character and runs the body if the character is n-z or N-Z
	else if ((78 <= int(c) && int(c) <= 90) || (110 <= int(c) && int(c) <= 122)) {
		// decreases the ASCII decimal value by 13, turning N to A and so on
		c = int(c) - 13;
	}
	return c;
}

int main()
{
	ifstream input;
	ofstream output;
	char c;
	string original;
	string encrypted;

	// opening the input and output files for reading and writing
	input.open("C:\\Users\\armag\\datastructures\\input.txt");
	output.open("C:\\Users\\armag\\datastructures\\output.txt");

	// error handling statements
	if (!output) {
		cout << "Problem opening output file" << endl;
		return 1;
	}
	else if (!input) {
		cout << "Problem opening input file" << endl;
		return 1;
	}

	// this loop runs as long as there are still characters in the input file left unparsed
	while (input.get(c)) {
		// reads a character from the input file, runs the encrypt method on it, and writes it to the output file.
		// also writes all of the characters from the input to the string original and the characters from the output
		// stream to the string encrypted for easy viewing of output.
		original += c;
		c = encrypt(c);
		encrypted += c;
		output.put(c);
	}
	cout << original << endl;
	cout << encrypted << endl;
    return 0;
}

