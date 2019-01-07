#ifndef ADVENT2016_DAY8_H
#define ADVENT2016_DAY8_H

#pragma once

#include <iostream>
#include <string>
#include <map>

namespace Day8
{
	// Enum and conversion map for each switch on operations
	enum Operations {
		rect, 
		rotate
	};
	const std::map<std::string, Operations> OperationMap = { {"rect", Operations::rect}, {"rotate", Operations::rotate} };
	

	// Helper function to draw a rect on screen of variable size
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void DrawRect(std::string const *params, bool (&screen)[SIZE_Y][SIZE_X]);

	// Helper function to rotate
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void Rotate(std::string const *params, bool(&screen)[SIZE_Y][SIZE_X]);

	// Allow our parser to accept screens of variable size via templating
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void parseInput(std::string const *input, bool (&screen)[SIZE_Y][SIZE_X]);

	// And use templates so we can also print variable sized screens
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	std::string printScreen(bool const (&input)[SIZE_Y][SIZE_X]);

	void run();
}
#endif //ADVENT2016_DAY8_H
