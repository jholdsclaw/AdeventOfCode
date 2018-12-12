#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include "Day2.h"

namespace Day2 {
	void run() {
		std::cout << "Day 1:\n" << std::endl;

		std::string result;

		// Test Case 1 - result should be 1985
		Keypad keypad1;
		const std::string input1 = "ULL\nRRDDD\nLURDL\nUUUUD";
		result = parseInput(input1, &keypad1);
		std::cout << "Test 1: (ULL\\nRRDDD\\nLURDL\\nUUUUD) = Code: " << result << std::endl;
		assert(result == "1985");

		return;
	}

	std::string parseInput(std::string const &input, Keypad *kpd) {
		// string to store our result code
		std::string code;

		// create a string stream to parse through our input
		std::stringstream ss(input);

		while (ss.good()) {
			// per spec, each line is one key press command queue
			std::string line;

			// get first line
			std::getline(ss, line);
			code += ('0' + kpd->processInput(line)); // quick hack to convert single digit to char
		}

		return code;
	}

	Keypad::Keypad() noexcept {
		buildKeypad();

		// Per spec, always start at number 5
		currentKeypadNumber = &keys[1][1];
	}

	// Initialize the keypad numbers, starting top left moving left-to-right, top-to-bottom
	void Keypad::buildKeypad() {
		unsigned short int key = 1;

		// Loop through and setup our relative positions, capped at the bounds of the keypad per the spec
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				keys[i][j].up = &keys[std::max(0, i - 1)][j];
				keys[i][j].down = &keys[std::min(2, i + 1)][j];
				keys[i][j].left = &keys[i][std::max(0, j - 1)];
				keys[i][j].right = &keys[i][std::min(2, j + 1)];
				keys[i][j].key = key++;
			}
		}
	}

	int Keypad::processInput(std::string const &input) {
		// create a string stream to parse through our input
		std::stringstream ss(input);
		char c;

		while (ss >> c) {
			switch (c) {
			case 'U':
			case 'u':
				currentKeypadNumber = currentKeypadNumber->up;
				break;
			case 'D':
			case 'd':
				currentKeypadNumber = currentKeypadNumber->down;
				break;
			case 'L':
			case 'l':
				currentKeypadNumber = currentKeypadNumber->left;
				break;
			case 'R':
			case 'r':
				currentKeypadNumber = currentKeypadNumber->right;
				break;
			default:
				throw std::runtime_error("Bad input string");
				break;
			}
		}

		return currentKeypadNumber->key;
	}
}
