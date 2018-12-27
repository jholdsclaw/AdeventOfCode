#include "Day7.h" 

#include <iostream>
#include <string>

namespace Day7 {
	void run() {
		std::cout << "Day 7:\n" << std::endl;

		// Test Case 1
		std::string test1 = "abba[mnop]qrst";
		bool result1 = hasAbba(&test1);
		std::cout << "Test Case 1:\n" << test1 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result1 << " (" << ((result1 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 2
		std::string test2 = "abcd[bddb]xyyx";
		bool result2 = hasAbba(&test2);
		std::cout << "Test Case 1:\n" << test2 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result2 << " (" << ((result2 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 3
		std::string test3 = "aaaa[qwer]tyui";
		bool result3 = hasAbba(&test3);
		std::cout << "Test Case 1:\n" << test3 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result3 << " (" << ((result3 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 4
		std::string test4 = "ioxxoj[asdfgh]zxcvbn";
		bool result4 = hasAbba(&test4);
		std::cout << "Test Case 1:\n" << test4 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result4 << " (" << ((result4 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		//// Part 1 
		//std::ifstream part1("./Day6.txt");
		//std::array<charmap, 8> charmap1;
		//parseInput(part1, &charmap1);
		//std::cout << "Part 1 - result = ???" << std::endl;
		//std::cout << "Result: " << Part1::decode(&charmap1) << "\n" << std::endl;

		return;
	}

	bool hasAbba(const std::string *input) {

		return false;
	}
}