#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include "Day3.h"

namespace Day3 {
	// Global variable to store count (creating a whole class seems overkill)
	int numPossibleTriangles = 0;

	void run() {
		std::cout << "Day 3:\n" << std::endl;

		// Test Case 1 - bad triangle
		std::vector<int> Test1 = { 5, 10, 25 };
		bool result = validTriangle(Test1);
		std::cout << "Test Case 1 - (5, 10, 25) - result = false" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == false) ? "Pass" : "Fail") << ")\n" << std::endl;
		assert(result == false);

		// Test Case 2 - good triangle
		std::vector<int> Test2 = { 4, 5, 6 };
		result = validTriangle(Test2);
		std::cout << "Test Case 2 - (4, 5, 6) - result = true" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == true) ? "Pass" : "Fail") << ")\n" << std::endl;
		assert(result == true);

		// Part 1 - results unknown
		std::ifstream input("./Day3.txt");
		parseInput(input);
		std::cout << "Part 1: " << std::endl;
		std::cout << "Result: " << numPossibleTriangles;

	}

	void parseInput(std::ifstream &input) {
		std::stringstream ss;
		std::string line;

		std::vector<int> triangle = { 0,0,0 };

		while (std::getline(input, line)) {
			ss.str(line);

			for (int i = 0; i < 3; i++)
			{
				ss >> triangle[i];
			}

			if (validTriangle(triangle)) numPossibleTriangles++;
			ss.clear();
		}
	}

	bool validTriangle(std::vector<int> triangle) {
		std::vector<int> sortedTriangle = triangle;

		// Sort the triangle lengths so we only have to check if the first two lengths are greater than the last
		std::sort(sortedTriangle.begin(), sortedTriangle.end());

		return ((sortedTriangle[0] + sortedTriangle[1]) > sortedTriangle[2]);
	}

}