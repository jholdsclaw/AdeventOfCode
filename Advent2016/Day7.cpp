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

		//// Part 1 
		//std::ifstream part1("./Day6.txt");
		//std::array<charmap, 8> charmap1;
		//parseInput(part1, &charmap1);
		//std::cout << "Part 1 - result = ???" << std::endl;
		//std::cout << "Result: " << Part1::decode(&charmap1) << "\n" << std::endl;

		return;
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
				sequence.str(std::string());
				hypernet = true;
				break;
			case ']':
				hypernet = false;
				// If the hypernet sequence is an ABBA, we know the sequence isn't valid
				if (isAbba(sequence.str()))
					return false;

				// end of hypernet, go ahead and clear sequence
				sequence.str(std::string());
				break;
			default:
				sequence << c;
				break;
			}

			if (sequence.str().size() >= 4 && !hypernet) {
				result = (result || isAbba(sequence.str().substr(sequence.str().size() - 4, 4)));
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