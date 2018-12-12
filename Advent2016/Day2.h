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

		char key;
	};

	class Keypad {
	public:
		char processInput(std::string const &input);

	protected:
		KeypadNumber *keys;
		KeypadNumber *currentKeypadNumber;

	};

	class Keypad1 : public Keypad {
	private:
		void buildKeypad();
	
	public:
		Keypad1() noexcept;
		~Keypad1() noexcept;

	};

	class Keypad2 : public Keypad {
	private:
		void buildKeypad();

	public:
		Keypad2() noexcept;
		~Keypad2() noexcept;

	};

	std::string parseInput(std::string const &input, Keypad *kpd);

	void run();
}

#endif //ADVENT2016_DAY2_H
