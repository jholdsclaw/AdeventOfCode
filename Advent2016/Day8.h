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
		RECT, 
		ROTATE
	};

	const std::map<std::string, Operations> OperationMap = { {"rect", Operations::RECT}, {"rotate", Operations::ROTATE} };
	
	// Helper function to draw a rect on screen of variable size
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void drawRect(std::string const *params, bool (&screen)[SIZE_Y][SIZE_X]);

	// Helper function to rotate
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void rotate(std::string const *params, bool(&screen)[SIZE_Y][SIZE_X]);

	// Helper function to shift X axis
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void shiftX(int index, int offset, bool(&screen)[SIZE_Y][SIZE_X]);

	// Helper function to shift Y axes
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void shiftY(int index, int offset, bool(&screen)[SIZE_Y][SIZE_X]);

	// Allow our parser to accept screens of variable size via templating
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void parseInput(std::string const *input, bool (&screen)[SIZE_Y][SIZE_X]);

	// And use templates so we can also print variable sized screens
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	std::string printScreen(bool const (&input)[SIZE_Y][SIZE_X]);

	// Get number of pixels that are lit (true)
	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	int numPixelsLit(bool const (&input)[SIZE_Y][SIZE_X]);

	void run();
}
#endif //ADVENT2016_DAY8_H
