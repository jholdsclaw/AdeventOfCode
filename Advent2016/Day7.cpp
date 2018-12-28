#include "Day7.h" 

#include <ios>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
		std::cout << "Test Case 6:\n" << test6 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result6 << " (" << ((result6 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Part 1 
		std::ifstream part1("./Day7.txt");
		unsigned int count = Part1::parseInput(part1);
		std::cout << "Part 1 - result = ???" << std::endl;
		std::cout << "Result: " << count << "\n" << std::endl;

		// Test Case 7
		std::string test7 = "aba";
		bool result7 = isAba(test7);
		std::cout << "Test Case 7:\n" << test7 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result7 << " (" << ((result7 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 8
		std::string test8 = "aaa";
		bool result8 = isAba(test8);
		std::cout << "Test Case 8:\n" << test8 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result8 << " (" << ((result8 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 9
		std::string test9 = "bab";
		bool result9 = isBab(test9, test7);
		std::cout << "Test Case 9:\n" << test7 << " & " << test9 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result9 << " (" << ((result9 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 10
		std::string test10 = "aba[bab]xyz";
		bool result10 = supportSSL(&test10);
		std::cout << "Test Case 10:\n" << test10 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result10 << " (" << ((result10 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 11
		std::string test11 = "xyx[xyx]xyx";
		bool result11 = supportSSL(&test11);
		std::cout << "Test Case 11:\n" << test11 << " - result = FALSE" << std::endl;
		std::cout << "Result: " << result11 << " (" << ((result11 == false) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 12
		std::string test12 = "aaa[kek]eke";
		bool result12 = supportSSL(&test12);
		std::cout << "Test Case 12:\n" << test12 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result12 << " (" << ((result12 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 13
		std::string test13 = "zazbz[bzb]cdb";
		bool result13 = supportSSL(&test13);
		std::cout << "Test Case 13:\n" << test13 << " - result = TRUE" << std::endl;
		std::cout << "Result: " << result13 << " (" << ((result13 == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Part 2 
		std::ifstream part2("./Day7.txt");
		unsigned int count2 = Part2::parseInput(part2);
		std::cout << "Part 2 - result = ???" << std::endl;
		std::cout << "Result: " << count2 << "\n" << std::endl;

		return;
	}

	namespace Part1 {
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
	}

	namespace Part2 {
		int parseInput(std::ifstream &input) {
			std::string line;
			unsigned int count = 0;

			while (input.good()) {
				std::getline(input, line);

				if (supportSSL(&line))
					count++;
			}

			return count;
		}
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
				// End of a hypernet, reset our sequence
				hypernet = false;
				sequence.str(std::string());
				break;
			default:
				sequence << c;
				break;
			}

			if (sequence.str().size() >= 4) {
				if (isAbba(sequence.str().substr(sequence.str().size() - 4, 4))) {
					// If we find an ABBA in a hypernet, the line is not TLS, so return immediately
					if (hypernet)
						return false;

					// Otherwise, set that we found an ABBA, but keep going in case we later find an ABBA in hypernet
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

	bool supportSSL(const std::string *input) {
		bool result = false;

		// List of abas and abas and babs found
		std::vector<std::string> abas, babs;
		
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
				// End of a hypernet, reset our sequence
				hypernet = false;
				sequence.str(std::string());
				break;
			default:
				sequence << c;
				break;
			}

			if (sequence.str().size() >= 3) {
				std::string s = sequence.str().substr(sequence.str().size() - 3, 3);
				if (isAba(s)) {
					// ABA's inside hypernets are potential BAB's
					if (hypernet) {
						babs.push_back(s);
					}
					// Otherwise, it's just a plain ol' ABA
					else {
						abas.push_back(s);
					}
				}
			}
		}

		// Now cross-check our ABA's and BAB's to see if we have any valid matches
		for (auto aba : abas) {
			for (auto bab : babs) {
				result = result || isBab(bab, aba);
			}
		}
		return result;
	}

	bool isAba(const std::string input) {
		bool result = (input[0] == input[2] && input[0] != input[1]);
		return result;
	}

	bool isBab(const std::string input, const std::string aba) {
		// First we check if this is even a valid BAB
		bool result = (input[0] == input[2] && input[0] != input[1]);

		// And then make sure it's the inverse of the ABA we're checking against
		result = result && (input[0] == aba[1] && input[1] == aba[0]);

		return result;
	}
}