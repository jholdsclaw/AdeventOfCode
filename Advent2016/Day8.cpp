#include "Day8.h" 

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath> // for atoi

namespace Day8 {
	void run() {
		std::cout << "Day 8:\n" << std::endl;

		bool testscreen[3][7] = { {0,0,0,0,0,0,0}, { 0,0,0,0,0,0,0}, { 0,0,0,0,0,0,0} };
		std::cout << "Starting grid: \n" << printScreen(testscreen) << std::endl;

		// Test Case 1
		std::string test1 = "rect 3x2";
		std::cout << "Test Case 1: " << test1 << std::endl;
		readInstruction(&test1, testscreen);
		std::cout << "Result:\n" << printScreen(testscreen) << std::endl;

		// Test Case 2
		std::string test2 = "rotate column x=1 by 1";
		std::cout << "Test Case 2: " << test2 << std::endl;
		readInstruction(&test2, testscreen);
		std::cout << "Result:\n" << printScreen(testscreen) << std::endl;

		// Test Case 3
		std::string test3 = "rotate row y=0 by 4";
		std::cout << "Test Case 3: " << test3 << std::endl;
		readInstruction(&test3, testscreen);
		std::cout << "Result:\n" << printScreen(testscreen) << std::endl;

		// Test Case 4
		std::string test4 = "rotate column x=1 by 1";
		std::cout << "Test Case 4: " << test4 << std::endl;
		readInstruction(&test4, testscreen);
		std::cout << "Result:\n" << printScreen(testscreen) << std::endl;

		// Test Case 5
		std::cout << "Test Case 5: number of lit pixels should eq 6" << std::endl;
		std::cout << "Result:\n" << numPixelsLit(testscreen) << "\n" << std::endl;

		// Part 1 
		std::ifstream part1("./Day8.txt");
		bool screen1[6][50] = { 0 };
		parseInput(part1, screen1);
		std::cout << "Part 1 - Number of lit pixels - result = ???" << std::endl;
		std::cout << "Result: " << numPixelsLit(screen1) << "\n" << std::endl;
		std::cout << printScreen(screen1);
		return;
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void readInstruction(std::string const *input, bool(&screen)[SIZE_Y][SIZE_X]) {
		Operations instruction = OperationMap.at(input->substr(0, input->find(" ")));
		std::string params = input->substr(input->find(" ") + 1);

		switch (instruction) {
		case Operations::RECT:
			drawRect(&params, screen);
			break;
		case Operations::ROTATE:
			rotate(&params, screen);
			break;
		default:
			std::cerr << "Error: unknown instruction!" << std::endl;
		}
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void parseInput(std::ifstream &input, bool(&screen)[SIZE_Y][SIZE_X]) {
		std::string line;

		while (input.good()) {
			std::getline(input, line);
			readInstruction(&line, screen);
		} 
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void drawRect(std::string const *params, bool(&screen)[SIZE_Y][SIZE_X]) {
		// Grab our rect's width and height
		int width = atoi(params->substr(0, params->find("x")).c_str());
		int height = atoi(params->substr(params->find("x") + 1).c_str());;

		// Make sure we're not out of bounds of thre screen
		if (width > SIZE_X || height > SIZE_Y) {
			std::cerr << "Error: rect(" << width << "," << height << ") is larger than screen(" << SIZE_X << "," << SIZE_Y << ")!" << std::endl;
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
	void rotate(std::string const *params, bool(&screen)[SIZE_Y][SIZE_X]) {
		char axis;
		int index, offset;

		// Find out of we're rotating on the X or Y (can ignore column/row since x=/y= is also a unique identifier)
		if (params->find("x=") != std::string::npos) {
			axis = 'x';
		}
		else if (params->find("y=") != std::string::npos) {
			axis = 'y';
		}
		else {
			std::cerr << "Error: bad input for rotate command (" << params << ")" << std::endl;
		}

		// Now grab the index and the offset
		int index_pos = params->find("=") + 1;
		int offset_pos = params->find("by ") + 3;
		index = atoi(params->substr(index_pos, params->find("by") - index_pos).c_str());
		offset = atoi(params->substr(offset_pos).c_str());

		switch (axis) {
		case 'x':
			shiftX(index, offset, screen);
			break;
		case 'y':
			shiftY(index, offset, screen);
			break;
		default:
			std::cout << "Error: something went wrong..." << std::endl;
			break;
		}
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void shiftX(int index, int offset, bool(&screen)[SIZE_Y][SIZE_X]) {
		// Temp array to build our new col
		bool col[SIZE_Y] = { false };

		// First populate our temp col array
		for (int i = 0; i < SIZE_Y; i++)
			col[(i + offset) % SIZE_Y] = screen[i][index];

		// And now apply it back to the original screen buffer
		for (int i = 0; i < SIZE_Y; i++)
			screen[i][index] = col[i];
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	void shiftY(int index, int offset, bool(&screen)[SIZE_Y][SIZE_X]) {
		// Temp array to build our new col
		bool col[SIZE_X] = { false };

		// First populate our temp col array
		for (int i = 0; i < SIZE_X; i++)
			col[(i + offset) % SIZE_X] = screen[index][i];

		// And now apply it back to the original screen buffer
		for (int i = 0; i < SIZE_X; i++)
			screen[index][i] = col[i];
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	std::string printScreen(const bool(&input)[SIZE_Y][SIZE_X]) {
		std::stringstream buf;

		for (int y = 0; y < SIZE_Y; y++) {
			for (int x = 0; x < SIZE_X; x++) {
				buf << ((input[y][x]) ? '*' : '.') << ' ';
			}
			buf << std::endl;
		}
		return buf.str();
	}

	template<std::size_t SIZE_Y, std::size_t SIZE_X>
	int numPixelsLit(const bool(&input)[SIZE_Y][SIZE_X]) {
		int count = 0;

		for (int y = 0; y < SIZE_Y; y++) {
			for (int x = 0; x < SIZE_X; x++) {
				if (input[y][x])
					count++;
			}
		}
		return count;
	}
}