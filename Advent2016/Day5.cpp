#include "Day5.h"
#include "lib/md5.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

namespace Day5 {
	void run() {
		std::cout << "Day 5:\n" << std::endl;

		// Test Case 1
		std::string Test1 = "grape";
		std::string result = md5(Test1);
		std::cout << "Test Case 1 md5(" << Test1 << ") - result = b781cbb29054db12f88f08c6e161c199" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == "b781cbb29054db12f88f08c6e161c199") ? "Pass" : "Fail") << ")\n" << std::endl;
		assert(result == "b781cbb29054db12f88f08c6e161c199");

		//// Part 1 
		//std::string Part1 = "reyedfim";
		//std::string result1 = Part1::getPassword(Part1);
		//std::cout << "Part 1 - result = ???" << std::endl;
		//std::cout << "Result: " << result1 << "\n" << std::endl;

		// Part 2 
		std::string Part2 = "reyedfim";
		std::string result2 = Part2::getPassword(Part2);
		std::cout << "Part 2 - result = ???" << std::endl;
		std::cout << "Result: " << result2 << "\n" << std::endl;

	}
	namespace Part1 {
		std::string getPassword(const std::string input) {
			std::stringstream password;

			// Variable for tracking current digit of password
			unsigned int password_pos = 0;

			// Varible to track incrementing index for generating hash
			unsigned long hash_index = 0;

			do {
				// Calculate the md5 hash
				std::string hash_result = md5(input + std::to_string(hash_index));

				// Check if the first 5 digits are all 0's
				if (hash_result.substr(0, 5) == "00000") {
					password << hash_result[5];

					std::cout << "Password digit found at hash_index " << hash_index << std::endl;
					std::cout << "Current password: " << password.str() << std::endl;

					password_pos++;
				}

				hash_index++;

			} while (password_pos < 8);

			return password.str();
		}
	}

	namespace Part2 {
		std::string getPassword(const std::string input) {
			// We'll use a regular string for this one since we are going to place at explicit locations
			// Filling it with underscore characters as markers for whether or not that position has been set
			std::string password = "________";

			// Variable for tracking current digit of password
			unsigned int password_pos = 0;

			// Varible to track incrementing index for generating hash
			unsigned long hash_index = 0;

			do {
				// Calculate the md5 hash
				std::string hash_result = md5(input + std::to_string(hash_index));

				// Check if the first 5 digits are all 0's
				if (hash_result.substr(0, 5) == "00000") {
					// Make sure the 6th digit is a valid password position
					if ('0' <= hash_result[5] && hash_result[5] <= '7') {
						// Quick abuse of C'a implicit conversion between char and int to convert to numeric 0
						password_pos = (int)hash_result[5] - '0';

						// If this position hasn't been set yet, go ahead and set it
						if (password[password_pos] == '_') password[password_pos] = hash_result[6];

						std::cout << "Password digit found at hash_index " << hash_index << std::endl;
						std::cout << "Current password: " << password << std::endl;
					}
				}

				hash_index++;
				// Continue looping until all positions have been set
			} while (std::count(password.begin(), password.end(), '_') > 0);

			return password;
		}
	}
}