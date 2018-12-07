#include <iostream>
#include <sstream>
#include <algorithm>

#include "Day2.h"

namespace Day2 {
	void run() {
		// Test Case 1 - result should be 1985
		Keypad keypad1;
		const std::string input1 = "ULL\nRRDDD\nLURDL\nUUUUD";
		parseInput(input1, &keypad1);

		return;
	}

	void parseInput(std::string const &input, Keypad *kpd) {
		// create a string stream to parse through our input
		std::stringstream ss(input);

		while (ss.good()) {
			// per spec, each line is one key press command queue
			std::string line;

			// get first line
			std::getline(ss, line);
			kpd->processInput(line);
		}

	}

	Keypad::Keypad() noexcept {
		buildKeypad();
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

	void Keypad::processInput(std::string const &input) {
		std::cout << input << std::endl;
	}
}
