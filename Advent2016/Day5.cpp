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
		std::string result1 = md5(Test1);
		std::cout << "Test Case 1 md5(" << Test1 << ") - result = b781cbb29054db12f88f08c6e161c199" << std::endl;
		std::cout << "Result: " << result1 << " (" << ((result1 == "b781cbb29054db12f88f08c6e161c199") ? "Pass" : "Fail") << ")\n" << std::endl;
		assert(result1 == "b781cbb29054db12f88f08c6e161c199");

		// Part 1 
		std::string Part1 = "reyedfim";
		std::string result = getPassword(Part1);
		std::cout << "Part 1 - result = ???" << std::endl;
		std::cout << "Result: " << result << "\n" << std::endl;

	}

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