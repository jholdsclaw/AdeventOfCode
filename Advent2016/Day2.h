#ifndef ADVENT2016_DAY2_H
#define ADVENT2016_DAY2_H

#pragma once

#include <iostream>
#include <map> 

namespace Day2
{
	struct KeypadNumber {
		KeypadNumber *up;
		KeypadNumber *down;
		KeypadNumber *left;
		KeypadNumber *right;

		int key;
	};

	class Keypad {
	public:
		int processInput(std::string const &input);

		Keypad() noexcept;

	private:
		KeypadNumber keys[3][3];
		KeypadNumber *currentKeypadNumber;

		void buildKeypad();
	};

	std::string parseInput(std::string const &input, Keypad *kpd);

	void run();
}

#endif //ADVENT2016_DAY2_H
