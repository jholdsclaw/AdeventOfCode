#include "Day7.h" 

#include <ios>
#include <iostream>
#include <string>
#include <sstream>

namespace Day7 {
	void run() {
		std::cout << "Day 7:\n" << std::endl;

		// Test Case 1
		std::string test1 = "abba[mnop]qrst";
		bool result1 = supportTLS(&test1);
		std::cout << "Test Case 1:\n" << test1 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result1 << " (" << ((result1 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 2
		std::string test2 = "abcd[bddb]xyyx";
		bool result2 = supportTLS(&test2);
		std::cout << "Test Case 2:\n" << test2 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result2 << " (" << ((result2 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 3
		std::string test3 = "aaaa[qwer]tyui";
		bool result3 = supportTLS(&test3);
		std::cout << "Test Case 3:\n" << test3 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result3 << " (" << ((result3 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 4
		std::string test4 = "ioxxoj[asdfgh]zxcvbn";
		bool result4 = supportTLS(&test4);
		std::cout << "Test Case 4:\n" << test4 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result4 << " (" << ((result4 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 5
		std::string test5 = "abba";
		bool result5 = isAbba(test5);
		std::cout << "Test Case 5:\n" << test5 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result5 << " (" << ((result5 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 6
		std::string test6 = "aabb";
		bool result6 = isAbba(test6);
		std::cout << "Test Case 5:\n" << test6 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result6 << " (" << ((result6 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Part 1 
		std::ifstream part1("./Day7.txt");
		unsigned int count = parseInput(part1);
		std::cout << "Part 1 - result = ???" << std::endl;
		std::cout << "Result: " << count << "\n" << std::endl;

		return;
	}

	int parseInput(std::ifstream &input) {
		std::string line;
		unsigned int count = 0;

		while (input.good()) {
			std::getline(input, line);

			if (supportTLS(&line))
				count++;
		}

		return count;
	}
	
	bool supportTLS(const std::string *input) {
		bool result = false;
		
		std::string line = *input;
		std::stringstream sequence;

		bool hypernet = false;

		for (char &c : line) {
			switch (c) {
			case '[':
				// Beginning of a hypernet, reset our sequence
				hypernet = true;
				sequence.str(std::string());
				break;
			case ']':
				hypernet = false;
				sequence.str(std::string());
				break;
			default:
				sequence << c;
				break;
			}

			if (sequence.str().size() >= 4) {
				if (isAbba(sequence.str().substr(sequence.str().size() - 4, 4))) {
					if (hypernet)
						return false;
					result = true;
				}
			}
		}
		return result;
	}

	bool isAbba(const std::string input) {
		// Last two must be reverse of first two, but all cannot be the same
		bool result = (input[0] == input[3] && input[1] == input[2] && input[0] != input[1]);
		return result;
	}
}