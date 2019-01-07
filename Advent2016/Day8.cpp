#include "Day8.h" 

#include <iostream>
#include <sstream>
#include <string>
#include <cmath> // for atoi

namespace Day8 {
	void run() {
		std::cout << "Day 8:\n" << std::endl;

		// Test Case 1
		bool testscreen[3][7] = { {0,0,0,0,0,0,0}, { 0,0,0,0,0,0,0}, { 0,0,0,0,0,0,0} };
		std::cout << "Starting grid: \n" << printScreen(testscreen) << std::endl;

		std::string test1 = "rect 3x2";
		std::cout << "Test Case 1: " << test1 << std::endl;
		parseInput(&test1, testscreen);
		std::cout << "Result:\n" << printScreen(testscreen) << std::endl;

		return;
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void parseInput(std::string const *input, bool(&screen)[SIZE_Y][SIZE_X]) {
		Operations instruction = OperationMap.at(input->substr(0, input->find(" ")));
		std::string params = input->substr(input->find(" ") + 1);

		switch (instruction) {
		case rect:
			DrawRect(&params, screen);
			break;
		default:
			std::cout << "unknown instruction" << std::endl;
		}
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void DrawRect(std::string const *params, bool(&screen)[SIZE_Y][SIZE_X]) {
		// Grab our rect's width and height
		int width = atoi(params->substr(0, params->find("x")).c_str());
		int height = atoi(params->substr(params->find("x") + 1).c_str());;

		// Make sure we're not out of bounds of thre screen
		if (width > SIZE_X || height > SIZE_Y) {
			std::cerr << "Error: rect(" << width << "," << height << ") is larger than screen(" << SIZE_X << "," << SIZE_Y << ")!";
			return;
		}

		// Draw our map on the screen buffer
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				screen[y][x] = true;
			}
		}
	}


	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	std::string printScreen(const bool(&input)[SIZE_Y][SIZE_X]) {
		std::stringstream buf;

		for (int y = 0; y < SIZE_Y; y++) {
			for (int x = 0; x < SIZE_X; x++) {
				buf << input[y][x] << ' ';
			}
			buf << std::endl;
		}
		return buf.str();
	}
}